
#ifndef CHOL_BLOCK_SIZE
#define CHOL_BLOCK_SIZE 8
#endif
#ifndef TRSM_BLOCK_SIZE
#define TRSM_BLOCK_SIZE 256
#endif
#ifndef GEMM_BLOCK_SIZE
#define GEMM_BLOCK_SIZE 32
#endif
#ifndef GEMM_BLOCKED
#define GEMM_BLOCKED 1
#endif
#ifndef MAX_DENSE_BLK_SIZE
#define MAX_DENSE_BLK_SIZE 48 //36//32
#endif

#ifndef PRINT_CYCLES
#define PRINT_CYCLES 0
#endif
#ifndef SPICA
#define SPICA 1
#endif
#ifndef MATADD
#define MATADD 0
#endif

#ifndef PERF 
#define PERF 0
#endif
#include "include/memory.h"

// cycles to profile
uint64_t group_block_cycles = 0;
uint64_t matrix_add_cycles = 0;

static inline int min(int A, int B) { return A > B? B : A; }
static inline int max(int A, int B) { return A < B? B : A; }


//int* A_blk_start_orig = A_blk_start;
int A_blk_start[200] = {0}; // ToDo
int B_blk_start[200] = {0}; // ToDo
int blk_width[200] = {0};

void print_col_major(float* M, int w, int h, int stride) {
  float* M_i0 = M;
  for(int i = 0; i < h; i++) {
    float* M_ij = M_i0;
    for(int j = 0; j < w; j++) {
      printf("%f, ", *M_ij);
      M_ij += stride;
    }
    printf("\n");
    M_i0++;
  }
  printf("\n");
}
int tiling_AtA_nfactor(int nfactors, int max_height, int max_width, int avail_AtA_mem){
   int A_bytes = nfactors * max_height * max_width * sizeof(elem_t);
   int AtA_bytes = nfactors * max_height * max_height * sizeof(elem_t);
   int AtA_total_bytes = A_bytes + AtA_bytes;
   //printf("total AtA bytes: %d (A: %d, AtA: %d)\n", AtA_total_bytes, A_bytes, AtA_bytes);
   //int tile_nfactor = nfactors;
   int tile_nfactor = nfactors;
   int num_tile = 1; 
   while(AtA_total_bytes > avail_AtA_mem || tile_nfactor >= 256){
       num_tile ++;
       tile_nfactor = ceil_divide_int(nfactors, num_tile);
       A_bytes = tile_nfactor * max_height * max_width * sizeof(elem_t);
       AtA_bytes = tile_nfactor * max_height * max_height * sizeof(elem_t);
       AtA_total_bytes = A_bytes + AtA_bytes;
   }
   //printf("num nfactor tile: %d, nfactor tile: %d, AtA total bytes: %d\n", num_tile, tile_nfactor, AtA_total_bytes);
   return tile_nfactor;
 }


int tiling_cholesky(int supernode_width, int H_height, int chol_tile_len, int avail_chol_mem){
  int gemm_tile_len = H_height - chol_tile_len;
  uint64_t chol_tile_size = H_height * chol_tile_len * sizeof(elem_t);
  uint64_t syrk_tile_size = gemm_tile_len * (H_height-chol_tile_len) * sizeof(elem_t);
  uint64_t total_tile_size = chol_tile_size + syrk_tile_size;
  int gemm_tile_num = 1;
  while(avail_chol_mem < total_tile_size){
    gemm_tile_num ++;
    gemm_tile_len = ceil_divide_int(ceil_divide_int(H_height - chol_tile_len, gemm_tile_num), DIM) * DIM;
    syrk_tile_size = gemm_tile_len * (H_height - chol_tile_len) * sizeof(elem_t);
    total_tile_size = syrk_tile_size + chol_tile_size;
  }
  //printf("available memory size: %d\n", avail_chol_mem);
  printf("number of syrk tile: %d, tile len: (chol %d, syrk %d), size of tile: (chold %d, syrk %d)\n", gemm_tile_num, chol_tile_len, gemm_tile_len, chol_tile_size, syrk_tile_size); 
  return gemm_tile_len;
}

void ax(float a, float* x, int h) {
  for(int i = 0; i < h; i++) {
    x[i] *= a;
  }
}

void div_ax(float a, float* x, int h) {
  float reciprocal = 1/a;
  //for(int i = 0; i < h; i++) { 
  //  x[i] = x[i] * reciprocal;
  //}
  tiled_resadd_stride_auto(1, h, 
          reciprocal, 1, 1, h, h, h,
          x, NULL, x,
          false, WS);
}

void div_ax_unrolled(float a, float* x, int h){
  float reciprocal = 1/a;
  int tile_J = (h%DIM == 0) ? (int)(h/DIM) : (int)(h/DIM) + 1;
  int pad_J = ((h%DIM) == 0) ? 0 : DIM - (h % DIM);
  gemmini_extended4_config_ld(h * sizeof(elem_t), reciprocal, true, DIM, 0);
  gemmini_loop_ws(1, tile_J, 0, DIM - 1, pad_J, 0, x, NULL, NULL, x,
          h, h, 0, h, false, false, false, false, false, 0, 0, 0, true, false);
}

void div_ax_cpu(float a, float* x, int h) {
  float reciprocal = 1/a;
  for(int i = 0; i < h; i++) { 
    x[i] = x[i] * reciprocal;
  }
}

void saxpy(float a, float* x, float* y, int h) {
  for(int i = 0; i < h; i++) {
    y[i] += a * x[i];
  }
}

void saxpy_unrolled(float a, float* x, float* y, int h) {
  int tile_J = (h%DIM == 0) ? (int)(h/DIM) : (int)(h/DIM) + 1;
  int pad_J = ((h%DIM) == 0) ? 0 : DIM - (h % DIM);
  gemmini_extended4_config_ld(h * sizeof(elem_t), a, true, DIM, 0);
  gemmini_loop_ws(1, tile_J, 0, DIM - 1, pad_J, 0, x, y, NULL, y,
          h, h, 0, h, false, false, false, false, false, 0, 0, 0, true, false);
}
// Do C += scale_factor_B * BB^T
// B is dim_I x dim_K, C is dim_I x dim_I
// Equivalent to the following call
// matmul(dim_I, dim_I, dim_K,
//      B, B, C, 
//      stride_B, stride_B, stride_C,
//      scale_factor_B, 1,
//      true, false);
void tiled_blocked_syrk(int dim_I, int dim_K, int gemm_tile_len,
                  float* B, float* C_spad, float* C_in,
                  int stride_B, int stride_C,
                  float scale_factor_B, int channel, int acc_cfgid, int dma_cfgid) {
  // dim_I: h-w, dim_K: w
  // stride_B: h, stride_C: h
  
  float* B_JK = B;
  float* C_0J = C_in;
  int channel1 = channel + 1; // TODO: guarantee safe
  int iter = 0;
  int index = 0;
  int comp_index = 0;
  int gemm_block_len = min(dim_I, gemm_tile_len);
  bool granted = false; // ToDo
  uint64_t memcpy_start = 0, memcpy_end = 0, memcpy_total = 0;
  //printf("gemm block len: %d, GEMM BLOCK SIZE: %d\n", gemm_block_len, GEMM_BLOCK_SIZE);
  for(int JJ = 0; JJ < dim_I; JJ += gemm_block_len){
      int tile_J = min(dim_I - JJ, gemm_block_len);
      B_JK = B + JJ;
      C_0J = C_in + JJ * stride_C;
      granted = false;

      while(!granted)
        dma_source_config(channel, granted, false, (elem_t*) C_0J, stride_C * sizeof(elem_t));
      dma_nord_dest_config(channel, false, (elem_t*) C_spad, dim_I * sizeof(elem_t));
      granted = false;
      while(!granted)
        dma_source_config(channel1, granted, false, (elem_t*) C_spad, dim_I * sizeof(elem_t));
      dma_nord_dest_config(channel1, false, (elem_t*) C_0J, stride_C * sizeof(elem_t));
      dma_set_state(granted, 0, channel);
      dma_set_state(granted, 0, channel1);

      index = 0;
      int index_break = -1;
      comp_index = 0;
      int mvout_index = 0;
      int mvout_I_break = JJ;
      int mvout_J_break = 0;

      bool mvin_done = false;
        int I_break = -1;
        int J_break = -1;
#if SPICA == 1
        granted = false;
        // TODO: pull this out one level above
        //index = 0;
      for(int J = 0; J < tile_J; J += GEMM_BLOCK_SIZE){
        J_break = J;
        int I = JJ + J;
        int hhJ = min(tile_J - J, GEMM_BLOCK_SIZE);
        for(; I < dim_I; I += GEMM_BLOCK_SIZE){
          int hhI = min(dim_I - I, GEMM_BLOCK_SIZE);
          //printf("memcpy in index: %d\n", index + 1);
          //printf("JJ: %d, tile_J: %d, I: %d\n", JJ, tile_J, I);
          dma_memcpy_tile(channel, granted, (J * stride_C + I) * sizeof(elem_t), (J * dim_I + I - (JJ + J)) * sizeof(elem_t), index + 1, hhJ, hhI * sizeof(elem_t));
          index_break = index;
          // need to redo from here
          if(!granted){
              //printf("not granted I: %d, index: %d\n", I, index+1);
              I_break = I;
              break;
          }
          I_break = I + GEMM_BLOCK_SIZE;
          index ++; // encode from 1
        }
        if (I < dim_I)
            break;
        else if (J + GEMM_BLOCK_SIZE > tile_J){
            //J_break = dim_J;
            mvin_done = true;
        }
      }
#endif
      for(int J = 0; J < tile_J; J += GEMM_BLOCK_SIZE) {
        //float* B_JK = B;
        int hhJ = min(tile_J - J, GEMM_BLOCK_SIZE);
        //int hhJ = min(dim_I - J, gemm_block_len);
        float* B_IK = B_JK;
        //float* C_IJ = C_0J + J + JJ;
        //index = 0;
        for(int I = JJ+J; I < dim_I; I += GEMM_BLOCK_SIZE){
            //printf("JJ: %d, J: %d, dim_I: %d, I_break: %d, index: %d\n", JJ, J, dim_I, I_break, index_break + 1);
            float* C = (float*) C_spad + J * dim_I + I - (JJ + J);//GEMM_BLOCK_SIZE * index;
            int hhI = min(dim_I - I, GEMM_BLOCK_SIZE);
            // in case not all mvin is fetched
            if(!mvin_done){
              granted = false;
              //printf("need to do more, I_break: %d, J_break: %d, index_break: %d\n", I_break, J_break, index_break);
              for(int J_b = J_break; J_b < tile_J; J_b += GEMM_BLOCK_SIZE){
                int I_start = J_b == J_break ? I_break : JJ + J_b;
                int I_b = I_start;
                //J_break = J_b;
                int hhmJ = min(tile_J - J_b, GEMM_BLOCK_SIZE);

                for(; I_b < dim_I;){
                  int hhmI = min(dim_I - I_b, GEMM_BLOCK_SIZE);
                  dma_memcpy_tile(channel, granted, (J_b * stride_C + I_b) * sizeof(elem_t), (J_b * dim_I + I_b - (JJ + J_b)) * sizeof(elem_t), index_break + 1, hhmJ, hhmI * sizeof(elem_t));
                  // need to redo from here
                  if(!granted){
                      I_break = I_b;
                      if(index_break > index) {
                          //printf("I %d, JJ: %d, J: %d, I_b %d, J_b %d index %d is behind, index break: %d\n", I, JJ, J, I_b, J_b, index, index_break);
                          J_break = J_b;
                          break;
                      }
                      else {
                          //printf("I %d, JJ: %d, J: %d, I_b: %d, J_b: %d, index %d try once more, index_break: %d\n", I, JJ, J, I_b, J_b, index, index_break);
                          continue;
                      }
                  }
                  I_b += GEMM_BLOCK_SIZE;
                  I_break = I_b;
                  index_break ++; // encode from 1
                }
                if (I_b < dim_I) 
                  break;
                else if(J_b + GEMM_BLOCK_SIZE > tile_J){
                  //J_break = dim_J; 
                  mvin_done = true;
                }
              }
            }
           /* 
            //memcpy_start = read_cycles();
#if SPICA == 1
            // TODO: pull out
            dma_nord_source_config(channel, false, (elem_t*) C_IJ, stride_C * sizeof(elem_t));
            dma_nord_dest_config(channel, false, (elem_t*) C, dim_I * sizeof(elem_t));
            dma_memcpy_tile(channel, granted, 0, 0, index, hhJ, hhI * sizeof(elem_t));
#if ReRoCC == 1
            rr_fence(dma_cfgid); // replace with index check
#endif
#else
            for(int row = 0; row < hhJ; row++){
                memcpy((float*) C + row * gemm_block_len, (float*) C_IJ + row * stride_C, hhI * sizeof(elem_t));
            }
#endif
            memcpy_end = read_cycles();
            memcpy_total += memcpy_end - memcpy_start;
            */
            //printf("I: %d, J: %d, K: %d\n", I, J, K);
            //printf("C_in: 0x%08lx, C: 0x%08lx, dim_I: %d, dim_J: %d, dim_K: %d\n", C_IJ, C, hhJ, hhI, ww);
            int probe = 0;
            //printf("index: %d, comp index: %d\n", index, comp_index);
            while(probe <= comp_index + 1){
              dma_probe_state(probe, channel);
              //printf("hhJ: %d, hhI: %d, dim_K: %d\n", hhJ, hhI, dim_K);
              if(probe > comp_index + 1){
                 //printf("J: %d, JJ: %d, I: %d, B_JK: 0x%08lx, B_IK: 0x%08lx, C: 0x%08lx\n", J, JJ, I, B_JK, B_IK, C);
                 tiled_matmul_small(hhJ, hhI, dim_K,
                       (elem_t*) B_JK, (elem_t*) B_IK, (elem_t*) C, (elem_t*) C,
                       stride_B, stride_B, dim_I, dim_I,
                       scale_factor_B, 1,
                       true, false,
                       0, JJ == 0 && J == 0 && I == 0);
      //if(dim_I - JJ <= GEMM_BLOCK_SIZE * 2 && tile_J <= GEMM_BLOCK_SIZE) rr_fence(acc_cfgid);
              }
              /*
                 tiled_matmul_auto(hhJ, hhI, dim_K,
                       (elem_t*) B_JK, (elem_t*) B_IK, (elem_t*) C, (elem_t*) C,
                       stride_B, stride_B, dim_I, dim_I,
                       scale_factor_B, 1, MVIN_SCALE_IDENTITY,
                       NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
                       true, false,
                       false, false,
                       0, WS);
                       */
              //else
                  //printf("probe: %d, index: %d\n", probe, index+1);
              //rr_fence(acc_cfgid);
            }
              
#if ReRoCC == 1
            //rr_fence(acc_cfgid); // replace with index check
#endif
            //printf("memcpy out start\n");
            // ToDo: hide this latency
            //memcpy_start = read_cycles();
            /*
#if SPICA == 1
              // ToDo: hide this latency
            dma_nord_source_config(channel, false, (elem_t*) C, dim_I * sizeof(elem_t));
            dma_nord_dest_config(channel, false, (elem_t*) C_IJ, stride_C * sizeof(elem_t));
            dma_memcpy_tile(channel, granted, 0, 0, index, hhJ, hhI * sizeof(elem_t));
#if ReRoCC == 1
            rr_fence(dma_cfgid); // replace with index check
#endif
#else
            for(int row = 0; row < hhJ; row ++){
                memcpy((float*) C_IJ + row * stride_C, (float*) C + row * gemm_block_len, hhI * sizeof(elem_t));
            }
#endif
            */
            //memcpy_end = read_cycles();
            //memcpy_total += memcpy_end - memcpy_start;

            B_IK += GEMM_BLOCK_SIZE;
            //C_IJ += GEMM_BLOCK_SIZE;
            comp_index ++;
          
        }
        
#if ReRoCC == 1
        //if(dim_I - (JJ + J) <= GEMM_BLOCK_SIZE * 2) rr_fence(acc_cfgid);
#endif  

//#if PERT == 1
#define MVOUT_GAP PERF ? 2 : 4
        if(mvin_done && mvout_index + MVOUT_GAP <= comp_index){
          //printf("overlap mvout I break: %d, J break: %d\n", mvout_I_break, mvout_J_break);
          for(int J_b = mvout_J_break; J_b < tile_J; J_b += GEMM_BLOCK_SIZE){
            int I_start = J_b == mvout_J_break ? mvout_I_break : JJ + J_b;
            int I_b = I_start;
            int hhmJ = min(tile_J - J_b, GEMM_BLOCK_SIZE);
            if(mvout_index + MVOUT_GAP > comp_index){
                mvout_J_break = J_b;
                mvout_I_break = I_b;
                //printf("mvout break I: %d, J: %d\n", I_b, J_b);
                break;
            }
            //printf("I_start: %d, J_b: %d\n", I_start, J_b);
            for(; I_b < dim_I;){
              if(mvout_index + MVOUT_GAP > comp_index){
                  mvout_I_break = I_b;
                  mvout_J_break = J_b;
                  //printf("mvout break I: %d, J: %d\n", I_b, J_b);
                  break;
              }
              //printf("mvout mvout index: %d, comp index: %d, J_b: %d, I_b: %d\n", mvout_index, comp_index, J_b, I_b);
              granted = false;
              int hhmI = min(dim_I - I_b, GEMM_BLOCK_SIZE);
              // index does not matter
              dma_memcpy_tile(channel1, granted, (dim_I * J_b + I_b - (JJ + J_b)) * sizeof(elem_t), (J_b * stride_C + I_b) * sizeof(elem_t), mvout_index, hhmJ, hhmI * sizeof(elem_t));
              if(!granted){
                  mvout_I_break = I_b;
                  mvout_J_break = J_b;
                  break;
              }
              I_b += GEMM_BLOCK_SIZE;
              mvout_I_break = I_b;
              mvout_index ++;
            }
            if(I_b < dim_I)
                break;
          }
        }
//#endif

        B_JK += GEMM_BLOCK_SIZE;
        //C_0J += GEMM_BLOCK_SIZE * stride_C;
#if ReRoCC == 1
        //rr_fence(dma_cfgid);
#endif
      }
      
#if ReRoCC == 1
      //if(dim_I - JJ <= GEMM_BLOCK_SIZE * 2 && tile_J <= GEMM_BLOCK_SIZE) 
//#if PERF == 1
      if(mvout_index + MVOUT_GAP > comp_index) rr_fence(acc_cfgid);
//#else
//      rr_fence(acc_cfgid);
//#endif
#endif
      //int mvout_index = 0;
      //printf("spearate overlap mvout I break: %d, J break: %d\n", mvout_I_break, mvout_J_break);
      for(int J = mvout_J_break; J < tile_J; J += GEMM_BLOCK_SIZE){
        int hhJ = min(tile_J - J, GEMM_BLOCK_SIZE);
        int I = J == mvout_J_break ? mvout_I_break : J + JJ;
        for(; I < dim_I; I += GEMM_BLOCK_SIZE){
          granted = false;
          int hhI = min(dim_I - I, GEMM_BLOCK_SIZE);
          // index does not matter
          while(!granted)
            dma_memcpy_tile(channel1, granted, (dim_I * J + I - (JJ + J)) * sizeof(elem_t), (J * stride_C + I) * sizeof(elem_t), mvout_index, hhJ, hhI * sizeof(elem_t));
          mvout_index ++;
        }
      }
#if ReRoCC == 1
      rr_fence(dma_cfgid);
#endif

  }
#if PRINT_CYCLE == 1
  printf("total memcpy cycles: %llu\n", memcpy_total);
#endif
}

void workspace_blocked_syrk(int dim_I, int dim_K,
                  float* B, float* C,
                  int stride_B, int stride_C,
                  float scale_factor_B) {
  // dim_I: h-w, dim_K: w
  // stride_B: h, stride_C: h


  //float* B_0K = B;
  //for(int K = 0; K < dim_K; K += GEMM_BLOCK_SIZE) {
    //int ww = min(dim_K - K, GEMM_BLOCK_SIZE); // ww is the actual panel width
  float* B_JK = B;
  float* C_0J = C;
  for(int J = 0; J < dim_I; J += GEMM_BLOCK_SIZE) {
    int hhJ = min(dim_I - J, GEMM_BLOCK_SIZE);
    float* B_IK = B_JK;
    float* C_IJ = C_0J + J;
    for(int I = J; I < dim_I; I += GEMM_BLOCK_SIZE) {
      int hhI = min(dim_I - I, GEMM_BLOCK_SIZE); 
      /*
      matmul(hhJ, hhI, ww,
             B_JK, B_IK, C_IJ,
             stride_B, stride_B, stride_C,
             scale_factor_B, 1,
             true, false);
      */
      //printf("%d, %d, %d\n", hhJ, hhI, ww);

      tiled_matmul_small(hhJ, hhI, dim_K,
            (elem_t*) B_JK, (elem_t*) B_IK, (elem_t*) C_IJ, (elem_t*) C_IJ,
            stride_B, stride_B, stride_C, stride_C,
            scale_factor_B, 1,
            true, false,
            0, J == 0 && I == 0);
      B_IK += GEMM_BLOCK_SIZE;
      C_IJ += GEMM_BLOCK_SIZE;
    }
    B_JK += GEMM_BLOCK_SIZE;
    C_0J += GEMM_BLOCK_SIZE * stride_C;
  }
  //B_0K += GEMM_BLOCK_SIZE * stride_B;
  //}
}


void multi_workspace_blocked_syrk(int dim_I, int dim_K,
                  float* B, float* C,
                  int stride_B, int stride_C,
                  float scale_factor_B,
                  int acc_cfgid, int num_accel) {
  // dim_I: h-w, dim_K: w
  // stride_B: h, stride_C: h


  //float* B_0K = B;
  //for(int K = 0; K < dim_K; K += GEMM_BLOCK_SIZE) {
    //int ww = min(dim_K - K, GEMM_BLOCK_SIZE); // ww is the actual panel width
  float* B_JK = B;
  float* C_0J = C;
  bool configured= false;
  int turn = 0;
  for(int J = 0; J < dim_I; J += GEMM_BLOCK_SIZE) {
    int hhJ = min(dim_I - J, GEMM_BLOCK_SIZE);
    float* B_IK = B_JK;
    float* C_IJ = C_0J + J;
    for(int I = J; I < dim_I; I += GEMM_BLOCK_SIZE) {
      int hhI = min(dim_I - I, GEMM_BLOCK_SIZE); 
      /*
      matmul(hhJ, hhI, ww,
             B_JK, B_IK, C_IJ,
             stride_B, stride_B, stride_C,
             scale_factor_B, 1,
             true, false);
      */
      //printf("%d, %d, %d\n", hhJ, hhI, ww);
#if ReRoCC == 1
      if(num_accel > 1)
         rr_set_opc(XCUSTOM_ACC, acc_cfgid + (turn%num_accel));
#endif

      tiled_matmul_small(hhJ, hhI, dim_K,
            (elem_t*) B_JK, (elem_t*) B_IK, (elem_t*) C_IJ, (elem_t*) C_IJ,
            stride_B, stride_B, stride_C, stride_C,
            scale_factor_B, 1,
            true, false,
            0, !configured);// (J == 0 && I == 0);
      B_IK += GEMM_BLOCK_SIZE;
      C_IJ += GEMM_BLOCK_SIZE;
      if(turn%num_accel == num_accel-1) configured = true;
      turn ++;
    }
    B_JK += GEMM_BLOCK_SIZE;
    C_0J += GEMM_BLOCK_SIZE * stride_C;
  }
  //B_0K += GEMM_BLOCK_SIZE * stride_B;
  //}
}
void dual_workspace_blocked_syrk(int dim_I, int dim_K,
                  float* B, float* C,
                  int stride_B, int stride_C,
                  float scale_factor_B,
                  int acc_cfgid1, int acc_cfgid2) {
  // dim_I: h-w, dim_K: w
  // stride_B: h, stride_C: h


  //float* B_0K = B;
  //for(int K = 0; K < dim_K; K += GEMM_BLOCK_SIZE) {
    //int ww = min(dim_K - K, GEMM_BLOCK_SIZE); // ww is the actual panel width
  float* B_JK = B;
  float* C_0J = C;
  bool configured2= false;
  int turn = 0;
  for(int J = 0; J < dim_I; J += GEMM_BLOCK_SIZE) {
    int hhJ = min(dim_I - J, GEMM_BLOCK_SIZE);
    float* B_IK = B_JK;
    float* C_IJ = C_0J + J;
    for(int I = J; I < dim_I; I += GEMM_BLOCK_SIZE) {
      int hhI = min(dim_I - I, GEMM_BLOCK_SIZE); 
      /*
      matmul(hhJ, hhI, ww,
             B_JK, B_IK, C_IJ,
             stride_B, stride_B, stride_C,
             scale_factor_B, 1,
             true, false);
      */
      //printf("%d, %d, %d\n", hhJ, hhI, ww);
#if ReRoCC == 1
      rr_set_opc(XCUSTOM_ACC, turn % 2 == 0 ? acc_cfgid1 : acc_cfgid2);
#endif

      tiled_matmul_small(hhJ, hhI, dim_K,
            (elem_t*) B_JK, (elem_t*) B_IK, (elem_t*) C_IJ, (elem_t*) C_IJ,
            stride_B, stride_B, stride_C, stride_C,
            scale_factor_B, 1,
            true, false,
            0, !configured2);// (J == 0 && I == 0);
      B_IK += GEMM_BLOCK_SIZE;
      C_IJ += GEMM_BLOCK_SIZE;
      if(turn%2 == 1) configured2 = true;
      turn ++;
    }
    B_JK += GEMM_BLOCK_SIZE;
    C_0J += GEMM_BLOCK_SIZE * stride_C;
  }
  //B_0K += GEMM_BLOCK_SIZE * stride_B;
  //}
}

void blocked_syrk(int dim_I, int dim_K,
                  float* B, float* C,
                  int stride_B, int stride_C,
                  float scale_factor_B) {

  float* B_0K = B;
  for(int K = 0; K < dim_K; K += GEMM_BLOCK_SIZE) {
    int ww = min(dim_K - K, GEMM_BLOCK_SIZE); // ww is the actual panel width
    float* B_JK = B_0K;
    float* C_0J = C;
    for(int J = 0; J < dim_I; J += GEMM_BLOCK_SIZE) {
      int hhJ = min(dim_I - J, GEMM_BLOCK_SIZE);
      float* B_IK = B_JK;
      float* C_IJ = C_0J + J;
      for(int I = J; I < dim_I; I += GEMM_BLOCK_SIZE) {
        int hhI = min(dim_I - I, GEMM_BLOCK_SIZE); 
        /*
        matmul(hhJ, hhI, ww,
               B_JK, B_IK, C_IJ,
               stride_B, stride_B, stride_C,
               scale_factor_B, 1,
               true, false);
        */
        //printf("%d, %d, %d\n", hhJ, hhI, ww);
        tiled_matmul_auto(hhJ, hhI, ww,
               (elem_t*) B_JK, (elem_t*) B_IK, (elem_t*) C_IJ, (elem_t*) C_IJ,
               stride_B, stride_B, stride_C, stride_C,
               scale_factor_B, 1, MVIN_SCALE_IDENTITY,
               NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
               true, false,
               false, false,
               0, WS);

        B_IK += GEMM_BLOCK_SIZE;
        C_IJ += GEMM_BLOCK_SIZE;
      }
      B_JK += GEMM_BLOCK_SIZE;
      C_0J += GEMM_BLOCK_SIZE * stride_C;
    }
    B_0K += GEMM_BLOCK_SIZE * stride_B;
  }
}



// Do C[:, max_J] += (scale_factor_B * BB^T)[:, max_J]
// B is dim_I x dim_K, C is dim_I x dim_I
// Equivalent to the following call
// matmul(dim_I, dim_I, dim_K,
//      B, B, C, 
//      stride_B, stride_B, stride_C,
//      scale_factor_B, 1,
//      true, false);
// C_spad size: 2 GEMM_BLOCK_SIZE^2
// need to copy out to C each tile
void truncated_blocked_syrk(int dim_I, int dim_K, int max_J,
                  float* B, float* C,
                  int stride_B, int stride_C,
                  float scale_factor_B) {
  float* B_0K = B;
  for(int K = 0; K < dim_K; K += GEMM_BLOCK_SIZE) {
    int ww = min(dim_K - K, GEMM_BLOCK_SIZE); // ww is the actual panel width
    float* B_JK = B_0K;
    float* C_0J = C;
    for(int J = 0; J < max_J; J += GEMM_BLOCK_SIZE) {
      int hhJ = min(max_J - J, GEMM_BLOCK_SIZE);
      float* B_IK = B_JK;
      float* C_IJ = C_0J + J;
      for(int I = J; I < dim_I; I += GEMM_BLOCK_SIZE) {
        int hhI = min(dim_I - I, GEMM_BLOCK_SIZE); 
        /*
        matmul(hhJ, hhI, ww,
               B_JK, B_IK, C_IJ,
               stride_B, stride_B, stride_C,
               scale_factor_B, 1,
               true, false);
        */
        tiled_matmul_auto(hhJ, hhI, ww,
              (elem_t*)B_JK, (elem_t*)B_IK, (elem_t*)C_IJ, (elem_t*)C_IJ,
              stride_B, stride_B, stride_C, stride_C,
              scale_factor_B, 1, MVIN_SCALE_IDENTITY,
              NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
              true, false,
              false, false,
              0,
              WS);

        B_IK += GEMM_BLOCK_SIZE;
        C_IJ += GEMM_BLOCK_SIZE;
      }
      B_JK += GEMM_BLOCK_SIZE;
      C_0J += GEMM_BLOCK_SIZE * stride_C;
    }
    B_0K += GEMM_BLOCK_SIZE * stride_B;
  }
}

// Takes a dense square matrix A with size dim x dim, 
// modify it to be chol(A). 
// A is column major
void dense_block_cholesky(float* A, int dim, int stride, int acc_cfgid) {
  int hh = dim;                       // subdiagonal height of current column
  
    gemmini_extended_config_st(stride * sizeof(elem_t), NO_ACTIVATION, 1);
    gemmini_config_ex(WS, 0, 0);
    //gemmini_extended4_config_ld(0, 0, true, DIM, 1);
    gemmini_extended3_config_ld(0, 1, false, 2);
    gemmini_extended4_config_ld(0, 1, true, DIM, 1);
    
  for(int j = 0; j < dim; j++) {
    hh--;
    if(A[0] <= 0) A[0] = 1;
    float sqrtdiag = sqrt(A[0]);
    //printf("A[0]: %d, sqrtdiag: %d\n", (int)(A[0]*1000), (int)(sqrtdiag*1000));
    A[0] = sqrtdiag;
    div_ax_cpu(sqrtdiag, A + 1, hh);
    //if(hh > 0) div_ax_unrolled(sqrtdiag, A+1, hh);
    float* A_k = A;
    int hhh = hh;                     // subdiagonal height for columns left of current column
#if ReRoCC == 1
    rr_fence(acc_cfgid);
#endif
    for(int k = 1; k < dim - j; k++) {
      A_k += stride + 1;
      saxpy(-A[k], A+k, A_k, hhh);
      //if(hhh > 0) saxpy_unrolled(-A[k], A + k, A_k, hhh);
      hhh--;
    }
    A += stride + 1;
#if ReRoCC == 1
    rr_fence(acc_cfgid);
#endif
  }
}

void cpu_dense_block_cholesky(float* A, int dim, int stride) {
  int hh = dim;                       // subdiagonal height of current column
  
  for(int j = 0; j < dim; j++) {
    hh--;
    float sqrtdiag = sqrt(A[0]);
    //if(j== 0) printf("A[0]: %d, sqrtdiag: %d\n", (int)(A[0]*1000), (int)(sqrtdiag*1000));
    A[0] = sqrtdiag;
    //div_ax_cpu(sqrtdiag, A + 1, hh);
    div_ax(sqrtdiag, A+1, hh);
    float* A_k = A;
    int hhh = hh;                     // subdiagonal height for columns left of current column
    for(int k = 1; k < dim - j; k++) {
      A_k += stride + 1;
      saxpy(-A[k], A + k, A_k, hhh);
      hhh--;
    }
    A += stride + 1;
  }
}
// Solve Lx = B.T in place, overwriting B with the answer
// L is size w x w column major, B is size h x w column major
// B will be transposed implicitly
void cpu_dense_block_triangle_solve(float* L, float* B, 
                                int w, int h,
                                int strideL, int strideB) {
  int hh = w;                         // subdiagonal height of current column of L
  for(int j = 0; j < w; j++) {
    hh--;
    div_ax_cpu(L[0], B, h);
    float* B_k = B;
    for(int k = 1; k < w - j; k++) {
      B_k += strideB;
      saxpy(-L[k], B, B_k, h);
    }
    L += strideL + 1;
    B += strideB;
  }
}

// Solve Lx = B.T in place, overwriting B with the answer
// L is size w x w column major, B is size h x w column major
// B will be transposed implicitly
void dense_block_triangle_solve(float* L, float* B, 
                                 int w, int h,
                                 int strideL, int strideB, int acc_cfgid) {
  float* L_orig = L;
  float* B_orig = B;
  for(int j = 0; j < w; j++) {
    //printf("%d\n", (int)(L[0] * 1000));
    //div_start = read_cycles();
    //div_ax(L[0], B, h);
    //div_end = read_cycles();
    //div_total += div_end - div_start;

    int dim_I = h, dim_J = w - 1 - j, dim_K = 1;
    //printf("dim_I: %d, dim_J: %d, dim_K: %d\n", h, w-1-j, 1);
    float* gemmA = B;
    float* gemmB = L + 1;
    //B += strideB;
    float* gemmC = B + strideB;
    int stride_A = strideB, stride_B = strideL, stride_C = strideB;
    float scale_factor_A = -1, scale_factor_B = (float)(1/L[0]);
    bool transpose_A = true, transpose_B = false;
#if ReRoCC == 1
    //rr_fence(acc_cfgid); // replace with index check
#endif
    //printf("dim_I: %d, dim_J: %d, dim_K: %d\n", dim_I, dim_J, dim_K);
    if(dim_J > 0 && dim_I > 0) { // TODO: check big dim_I tiling 
      gemmini_extended3_config_ld(stride_A * sizeof(elem_t), scale_factor_B, false, 1);
#if PERF == 1
      int tile_I = dim_I > (ACC_ROWS/(2*8))*4 ? (ACC_ROWS/(2*8))*4 : ceil_divide_int(ceil_divide_int(dim_I,2),DIM)*DIM;
#else
      int tile_I = dim_I > (ACC_ROWS/(2*8))*4 ? (ACC_ROWS/(2*8))*4 : dim_I;
#endif
      //int iter = 0;
      //if(dim_J == 1 || dim_I <= 8) tile_I = dim_I;
      for(int i = 0; i < dim_I; i+=tile_I){
        //int dim_II = i == 0 ? half_dim_I : dim_I / 2;
        int dim_II = i + tile_I > dim_I ? dim_I - i : tile_I;
        //iter ++;
        //printf("j: %d, dim I : %d, dim J: %d (%d), dim K: %d\n", j, dim_J, dim_II, dim_I, dim_K);
        elem_t* B = (elem_t*) gemmA + i;// * stride_A;
        elem_t* C = (elem_t*) gemmC + i;
        //printf("A: 0x%08lx, B: 0x%08lx, C: 0x%08lx\n", gemmB, B, C);
        tiled_matmul_small(dim_J, dim_II, dim_K,
            (elem_t*)gemmB, (elem_t*)B, (elem_t*)C, (elem_t*)C,
            stride_B, stride_A, stride_C, stride_C,
            scale_factor_A, scale_factor_B, //MVIN_SCALE_IDENTITY,
            //NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
            transpose_A, transpose_B,
            //false, false,
            0,
            j==0 && i == 0); 
      }
#if PERF == 0
#if ReRoCC == 1
      rr_fence(acc_cfgid);
#endif
#endif
/*
      tiled_matmul_small(dim_J, dim_I, dim_K,
          (elem_t*)gemmB, (elem_t*)gemmA, (elem_t*)gemmC, (elem_t*)gemmC,
          stride_B, stride_A, stride_C, stride_C,
          scale_factor_A, scale_factor_B, //MVIN_SCALE_IDENTITY,
          //NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
          transpose_A, transpose_B,
          //false, false,
          0,
          j==0);
#if ReRoCC == 1      
       rr_fence(acc_cfgid);
#endif
*/
    }

    B += strideB;
    L += strideL + 1;
  }
#if ReRoCC == 1
  rr_fence(acc_cfgid); 
#endif
  L = L_orig;
  B = B_orig;
  for(int j = 0; j < w; j++) {
    div_ax(L[0], B, h);
    B += strideB;
    L += strideL + 1;
  }
#if ReRoCC == 1
  rr_fence(acc_cfgid); 
#endif
}

void dense_workspace_triangle_solve(float* L, float* AB_out, 
                                 int w, int h,
                                 int strideL, int strideB, int acc_cfgid) {
  float* L_orig = L;
  float* B_in = L + w;
  float* B_out = AB_out;

  for(int j = 0; j < w; j++) {
    //printf("%d\n", (int)(L[0] * 1000));
    //div_start = read_cycles();
    //div_ax(L[0], B, h);
    //div_end = read_cycles();
    //div_total += div_end - div_start;

    int dim_I = h, dim_J = w - 1 - j, dim_K = 1;
    //printf("dim_I: %d, dim_J: %d, dim_K: %d\n", h, w-1-j, 1);
    float* gemmA = B_in;
    float* gemmB = L + 1;
    //B += strideB;
    float* gemmC = B_out + strideB;
    int stride_A = strideL, stride_B = strideL, stride_C = strideB;
    float scale_factor_A = -1, scale_factor_B = (float)(1/L[0]);
    //printf("j: %d, L0: %d, scale: %d\n", j, (int)(1000*L[0]), (int)(1000*scale_factor_B));
    bool transpose_A = true, transpose_B = false;
#if ReRoCC == 1
    //rr_fence(acc_cfgid); // replace with index check
#endif
    //printf("dim_I: %d, dim_J: %d, dim_K: %d\n", dim_I, dim_J, dim_K);
    if(dim_J > 0 && dim_I > 0) { // TODO: check big dim_I tiling 
      gemmini_extended3_config_ld(stride_A * sizeof(elem_t), scale_factor_B, false, 1);
#if PERF == 1
      int tile_I = dim_I > (ACC_ROWS/(2*8))*4 ? (ACC_ROWS/(2*8))*4 : ceil_divide_int(ceil_divide_int(dim_I,2),DIM)*DIM;
#else
      int tile_I = dim_I > (ACC_ROWS/(2*8))*4 ? (ACC_ROWS/(2*8))*4 : dim_I;
#endif
      //int iter = 0;
      //if(dim_J == 1 || dim_I <= 8) tile_I = dim_I;
      for(int i = 0; i < dim_I; i+=tile_I){
        //int dim_II = i == 0 ? half_dim_I : dim_I / 2;
        int dim_II = i + tile_I > dim_I ? dim_I - i : tile_I;
        //iter ++;
        //printf("j: %d, dim I : %d, dim J: %d (%d), dim K: %d\n", j, dim_J, dim_II, dim_I, dim_K);
        elem_t* B = (elem_t*) gemmA + i;// * stride_A;
        elem_t* C = (elem_t*) gemmC + i;
        //printf("A: 0x%08lx, B: 0x%08lx, C: 0x%08lx\n", gemmB, B, C);
        tiled_matmul_small(dim_J, dim_II, dim_K,
            (elem_t*)gemmB, (elem_t*)B, (elem_t*)C, (elem_t*)C,
            stride_B, stride_A, stride_C, stride_C,
            scale_factor_A, scale_factor_B, //MVIN_SCALE_IDENTITY,
            //NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
            transpose_A, transpose_B,
            //false, false,
            0,
            j==0 && i == 0); 
      }
#if PERF == 0
#if ReRoCC == 1
      rr_fence(acc_cfgid);
#endif
#endif
/*
      tiled_matmul_small(dim_J, dim_I, dim_K,
          (elem_t*)gemmB, (elem_t*)gemmA, (elem_t*)gemmC, (elem_t*)gemmC,
          stride_B, stride_A, stride_C, stride_C,
          scale_factor_A, scale_factor_B, //MVIN_SCALE_IDENTITY,
          //NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
          transpose_A, transpose_B,
          //false, false,
          0,
          j==0);
#if ReRoCC == 1      
       rr_fence(acc_cfgid);
#endif
*/
    }

    B_in += strideL;
    L += strideL + 1;
    B_out += strideB;
  }
#if ReRoCC == 1
  rr_fence(acc_cfgid); 
#endif
  L = L_orig;
  B_out = AB_out;
  for(int j = 0; j < w; j++) {
    div_ax(L[0], B_out, h);
    B_out += strideB;
    L += strideL + 1;
  }
#if ReRoCC == 1
  rr_fence(acc_cfgid); 
#endif
}
/*
// Splitting out LC = C - LB LB^T computation for profiling
// Tile C, not A and B
//void C_tiled_partial_factorization(float* AB, float* C_spad, float* C_in, int w, int h) {
void C_tiled_partial_factorization(float* AB, float* m, int w, int h, int channel, int acc_cfgid, int dma_cfgid) {
  int hh = h;   // hh is the height of the current block column

  float* AB_JJ = AB;
  float* ABm_start = AB;
  float* C_spad = (float*) AB + h * w; // height * diag_width

  float* C_in = (float*) m + w*(h+1);//diag_width*(height+1); // starting of C
  uint64_t memcpy_start = 0, memcpy_end = 0, memcpy_total = 0;
  
  bool granted = false;
  memcpy_start = read_cycles();
#if SPICA == 1
  dma_nord_source_config(channel, false, (elem_t*) m, h*sizeof(float));
  dma_nord_dest_config(channel, false, (elem_t*) ABm_start, h*sizeof(float));
  dma_memcpy_tile(channel, granted, 0, 0, 0, w, h*sizeof(float));
#if ReRoCC == 1
  rr_fence(dma_cfgid); // replace with index check
#endif
#else
  //memcpy(ABm_start, m, height * diag_width * sizeof(float));  
  memcpy(ABm_start, m, h * w * sizeof(float));   
#endif
  memcpy_end = read_cycles();
  memcpy_total += (memcpy_end - memcpy_start);
  
  // J is the row/col index of the diagonal block
  // I is the row index of the subdiagonal block
  int J;
  int I;

  uint64_t A_B_start = 0, A_B_end = 0, A_B_mid = 0;
  uint64_t total_panel_chol = 0, total_triangular = 0;
  uint64_t truncated_start = 0, truncated_total = 0;

  // This is interleaved [LA; LB] computation
  for(J = 0; J < w; J += CHOL_BLOCK_SIZE) {
    // TODO: Make ww fixed and use cleanup iterations
    int ww = min(w - J, CHOL_BLOCK_SIZE); // ww is the panel width.

    A_B_start = read_cycles();
    dense_block_cholesky(AB_JJ, ww, h, acc_cfgid);
    float* AB_IJ = AB_JJ + ww;
    A_B_mid = read_cycles();
    for(I = J + ww; I < h; I += TRSM_BLOCK_SIZE) {
      // TODO: Make hh fixed and use cleanup iterations
      int hh = min(h - I, TRSM_BLOCK_SIZE); // hh is the block height
      dense_block_triangle_solve(AB_JJ, AB_IJ, 
                                  ww, 
                                  hh, 
                                  h, h, acc_cfgid);
      AB_IJ += TRSM_BLOCK_SIZE;
    }
    int dim_I = h - J - ww, dim_J = dim_I, dim_K = ww, max_J = w - J - ww;
    float* B = AB_JJ + ww;
    float* C = AB_JJ + ww * (h + 1);
    int stride_B = h, stride_C = h;
    float scale_factor_A = -1, scale_factor_B = 1;
    bool transpose_A = true, transpose_B = false;
    //printf("truncated block syrk dim_I: %d, dim_J: %d, dim_K: %d\n", dim_I, max_J, dim_K);
    truncated_start = read_cycles();
#if GEMM_BLOCKED == 1
    truncated_blocked_syrk(dim_I, dim_K, max_J,
                 B, C,
                 stride_B, stride_C,
                 scale_factor_A);
#else
    if(max_J > 0){
       tiled_matmul_auto(max_J, dim_I, dim_K,
              (elem_t*)B, (elem_t*)B, (elem_t*)C, (elem_t*)C,
              stride_B, stride_B, stride_C, stride_C,
              scale_factor_A, scale_factor_B, MVIN_SCALE_IDENTITY,
              NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
              transpose_A, transpose_B,
              false, false,
              0,
              WS);
    }
#endif
#if ReRoCC == 1
    rr_fence(acc_cfgid); // replace with index check
#endif
    A_B_end = read_cycles();
    truncated_total += (A_B_end - truncated_start);
    total_panel_chol += (A_B_mid - A_B_start);
    total_triangular += (A_B_end - A_B_mid);
    AB_JJ += CHOL_BLOCK_SIZE * (h + 1);
    hh -= CHOL_BLOCK_SIZE;
  }

  // This is LC = C - LB LB^T computation
  int dim_I = h - w, dim_J = dim_I, dim_K = w;
  float* B = AB + w;
  //float* C = AB + w * (h + 1);
  int stride_B = h, stride_C = h;
  float scale_factor_A = -1, scale_factor_B = 1;
  bool transpose_A = true, transpose_B = false;

  uint64_t C_start = 0, C_end = 0;
  C_start = read_cycles();
  tiled_blocked_syrk(dim_I, dim_K,
               B, C_spad, C_in,
               stride_B, stride_C,
               scale_factor_A,
               channel, acc_cfgid, dma_cfgid);

  C_end = read_cycles();

  // ToDo: hide this latency (copying out A, B)
  memcpy_start = read_cycles();
#if SPICA == 1
  dma_nord_source_config(channel, false, (elem_t*) AB, h*sizeof(float));
  dma_nord_dest_config(channel, false, (elem_t*) m, h*sizeof(float));
  dma_memcpy_tile(channel, granted, 0, 0, 0, w, h*sizeof(float));
#if ReRoCC == 1
  rr_fence(dma_cfgid); // replace with index check
#endif
#else
  memcpy(m, ABm_start, h * w * sizeof(float));  
#endif
  memcpy_end = read_cycles();
  memcpy_total += (memcpy_end - memcpy_start);
#if PRINT_CYCLES == 1
  printf("A_B cholesky cycles: %llu\n", total_panel_chol);
  printf("A_B triangle solve cycles: %llu\n", total_triangular);
  //printf("A_B division overhead cycles: %llu\n", div_total);
  printf("A_B truncated cycles: %llu\n", truncated_total);
  printf("C cycles: %llu\n", C_end - C_start);
  printf("memcpy cycles: %llu\n", memcpy_total);
#endif
}
*/
// Do partial cholesky factorization by first doing as dense cholesky on the diagonal block
// Then doing triangle solve
void full_tiled_partial_factorization(float* AB_spad, float* AB_in, int supernode_w, int h, int chol_tile_len, int gemm_tile_len, int channel, int acc_cfgid, int dma_cfgid) {

  //int hh = h;   // hh is the height of the current block column

  float* ABm_start = AB_spad;
  float* m = AB_in;
  float* C_spad = (float*) ABm_start + chol_tile_len * h; 
 
  //float* AB_JJ = AB_in;
  float* C_0 = AB_in;

  uint64_t A_B_start = 0, A_B_mid = 0, A_B_end = 0, C_start = 0, C_end = 0;
  uint64_t cholesky_total = 0, triangle_total = 0, C_total = 0;

  //int iter = 0;

  int index = 0;
  bool granted = false; // ToDo
  uint64_t memcpy_start = 0, memcpy_end = 0, memcpy_total = 0;

  for(int JJ = 0; JJ < supernode_w; JJ += chol_tile_len){
    int w = min(supernode_w - JJ, chol_tile_len);
    //index = 0;
    float* AB_JJ = (float*) AB_in + JJ * (h + 1);
    // J is the row/col index of the diagonal block
    // I is the row index of the subdiagonal block
    //for(int J = 0; J < w; J += CHOL_BLOCK_SIZE) {
      // TODO: Make ww fixed and use cleanup iterations
      //int ww = min(w - J, CHOL_BLOCK_SIZE); // ww is the panel width.
   
      //printf("JJ: %d, w: %d, col: %d\n", JJ, w, h-JJ-w);
      memcpy_start = read_cycles();
      //float* AB = (float*) AB_spad + J * h;
      //float* AB = iter == 0 ? AB_spad : (float*) AB_spad + CHOL_BLOCK_SIZE * h;
#if SPICA == 1
      // TODO: pull out (to be configured once)
      float* source_addr = (float*) AB_JJ + w;
      dma_nord_source_config(channel, false, source_addr, h* sizeof(float));
      dma_nord_dest_config(channel, false, (float*) AB_spad, h* sizeof(float));
      dma_memcpy_tile(channel, granted, 0, 0, index, w, (h- JJ - w) * sizeof(float));
#else
      float* source_addr = (float*) AB_JJ + w;
      for(int row = 0; row < w; row ++){
	  float* source_addr = (float*) AB_JJ + w + row * h;
	  float* dest_addr = (float*) AB_spad + row * h;
	  memcpy(dest_addr, source_addr, (h-JJ-w)*sizeof(float));
      }
      //memcpy((float*) AB_spad + row * h, (float*) AB_JJ + ww + row * h, (h - J - ww) * sizeof(float));
#endif    

      A_B_start = read_cycles();
      dense_block_cholesky(AB_JJ, w, h, acc_cfgid);
      float* AB_IJ = AB_spad;// + w;
#if ReRoCC == 1
      rr_fence(dma_cfgid); // TODO: replace with index check
#endif
      memcpy_end = read_cycles();
      memcpy_total += memcpy_end - memcpy_start;
      /*
      if(JJ == 0) 
          for(int i = 0; i < chol_tile_len; i++)
              printf("%d\n", (int)(AB_JJ[i+i*h]*1000));
      */
      A_B_mid = read_cycles();
      //for(int I = JJ + w; I < h; I += TRSM_BLOCK_SIZE) {
        //int hh = min(h - I, TRSM_BLOCK_SIZE); // hh is the block height
        int hh = h - (JJ + w);
        //printf("tri solve JJ: %d, w: %d, hh: %d\n", JJ, w, hh);
        dense_block_triangle_solve(AB_JJ, AB_IJ, 
                                   w, 
                                   hh, 
                                   h, h, acc_cfgid);
        //AB_IJ += TRSM_BLOCK_SIZE;
      //}
      A_B_end = read_cycles();
      cholesky_total += (A_B_mid - A_B_start);
      triangle_total += (A_B_end - A_B_mid);
     /* 
      if(JJ == 0) 
          for(int i = 0; i < chol_tile_len; i++)
              printf("%d\n", (int)(AB_JJ[i+i*h]*1000));
       */       
      memcpy_start = read_cycles();
      // copy it out
      // ToDo: hide this latency
#if SPICA == 1
      // TODO: pull it out of the loop
      float* dest_addr = (float*) AB_JJ + w;
      //printf("JJ: %d, w: %d, col: %d\n", JJ, w, h-JJ-w);
      dma_nord_source_config(channel, false, (elem_t*) AB_spad, h * sizeof(elem_t));
      dma_nord_dest_config(channel, false, dest_addr, h * sizeof(elem_t));
      //memcpy_start = read_cycles();
      dma_memcpy_tile(channel, granted, 0, 0, index, w, (h - JJ - w) * sizeof(elem_t));
#if ReRoCC == 1
      rr_fence(dma_cfgid); // ToDo: replace with index check
#endif
#else
      for(int row = 0; row < w; row ++){
	  float* source_addr = (float*) AB_spad + row * h;
	  float* dest_addr = (float*) AB_JJ + w + row * h;
          memcpy(dest_addr, source_addr, (h - JJ - w) * sizeof(float));
      }
      memcpy_end = read_cycles();
      memcpy_total += memcpy_end - memcpy_start;
#endif
    // TODO: Make this symmetric and blocked
    //int dim_I = h - J - ww, dim_J = dim_I, dim_K = ww;
    int dim_I = h - JJ - w, dim_J = dim_I, dim_K = w;
    float* B = AB_spad; //AB_JJ + ww;
    float* C = C_0 + w * (h + 1); // copy to C_spad
    int stride_B = h, stride_C = h;
    float scale_factor_A = -1, scale_factor_B = 1;
    bool transpose_A = true, transpose_B = false;

    //printf("block syrk dim_I: %d, dim_K: %d\n", dim_I, dim_K);
    C_start = read_cycles();
    tiled_blocked_syrk(dim_I, dim_K, gemm_tile_len,
                 B, C_spad, C,
                 stride_B, stride_C,
                 scale_factor_A, channel, acc_cfgid, dma_cfgid);
    C_end = read_cycles();
    C_total += C_end - C_start;

    C_0 += chol_tile_len * (h+1);
    //AB_JJ += chol_tile_len * (h + 1);
      //index ++;
    //hh -= CHOL_BLOCK_SIZE;
  }
#if PRINT_CYCLES == 1
  printf("A_B cholesky cycles: %llu\n", cholesky_total);
  printf("A_B triangle solve cycles: %llu\n", triangle_total);
  //printf("A_B division overhead cycles: %llu\n", div_total);
  //printf("A_B truncated cycles: %llu\n", truncated_total);
  printf("C cycles: %llu\n", C_total);
  printf("memcpy cycles (includes cholesky): %llu\n", memcpy_total);
#endif
}

void multi_workspace_partial_factorization(float* workspace, float* AB_out, int supernode_w, int h, int chol_tile_len, int channel, int acc_cfgid, int dma_cfgid, int num_accel) {

  float* AB_in = workspace;
 
  float* C_0 = workspace;
  int mvout_JJ = 0;

  uint64_t A_B_start = 0, A_B_mid = 0, A_B_end = 0, C_start = 0, C_end = 0;
  uint64_t cholesky_total = 0, triangle_total = 0, C_total = 0;

  int index = 0;
  bool granted = false; // ToDo
  uint64_t memcpy_start = 0, memcpy_end = 0, memcpy_total = 0;

  for(int JJ = 0; JJ < supernode_w; JJ += chol_tile_len){
    int w = min(supernode_w - JJ, chol_tile_len);
    //index = 0;
    float* workspace_JJ = (float*) AB_in + JJ * (h + 1);
    float* AB_out_JJ = (float*) AB_out + JJ * (h + 1);
    // J is the row/col index of the diagonal block
    // I is the row index of the subdiagonal block

      A_B_start = read_cycles();
      dense_block_cholesky(workspace_JJ, w, h, acc_cfgid);
      //float* AB_IJ = AB_spad;// + w;

      //printf("JJ: %d, w: %d, col: %d\n", JJ, w, h-JJ-w);
      // copy out block LA
      A_B_mid = read_cycles();
      int hh = h - (JJ + w);
      // workspace_JJ: A, B input
      // B_out: B output
      //printf("tri solve JJ: %d, w: %d, hh: %d\n", JJ, w, hh);
      float* B_JJ = workspace_JJ + w;
      dense_workspace_triangle_solve(workspace_JJ, B_JJ, 
                                 w, 
                                 hh, 
                                 h, h, acc_cfgid);
      //AB_IJ += TRSM_BLOCK_SIZE;
      //}
      A_B_end = read_cycles();
      cholesky_total += (A_B_mid - A_B_start);
      triangle_total += (A_B_end - A_B_mid);
      //printf("block chol: %d\n", A_B_mid - A_B_start);
      //printf("triangle: %d\n", A_B_end - A_B_mid);
      //float* B_out = AB_out_JJ + w;
#if SPICA == 1
      // TODO: pull out (to be configured once)
      if(JJ == 0){
        granted = false;
        while(!granted)
          dma_source_config(channel+1, granted, false, AB_in, h* sizeof(float));
        dma_nord_dest_config(channel+1, false, AB_out, h* sizeof(float));
        if(num_accel > 1){
          rr_set_opc(XCUSTOM_DMA, dma_cfgid+1);
          granted = false;
          while(!granted)
            dma_source_config(channel+1, granted, false, AB_in, h* sizeof(float));
          dma_nord_dest_config(channel+1, false, AB_out, h* sizeof(float));
        }
      }
      granted = false;
      int mvout_width = w + (JJ - mvout_JJ);
      dma_memcpy_tile(channel+1, granted, mvout_JJ * (h+1) * sizeof(float), mvout_JJ * (h+1) * sizeof(float), index, mvout_width, (h-mvout_JJ) * sizeof(float));
      if(JJ + chol_tile_len >= supernode_w){
        if(num_accel > 1)
          rr_set_opc(XCUSTOM_DMA, dma_cfgid);
        while(!granted)
          dma_memcpy_tile(channel+1, granted, mvout_JJ * (h+1) * sizeof(float), mvout_JJ * (h+1) * sizeof(float), index, mvout_width, (h-mvout_JJ) * sizeof(float));
      }
      else if(granted)
        mvout_JJ += chol_tile_len;
#else
      int mvout_rows = w + (JJ - mvout_JJ);
      for(int row = 0; row < mvout_rows; row ++)
        memcpy((float*) AB_in + row * h, (float*) AB_out + row * h, (h-mvout_JJ) * sizeof(float));
#endif  
    
    // TODO: Make this symmetric and blocked
    //int dim_I = h - J - ww, dim_J = dim_I, dim_K = ww;
    int dim_I = h - JJ - w, dim_J = dim_I, dim_K = w;
    float* B = B_JJ; //workspace_JJ + ww;
    float* C = C_0 + w * (h + 1); // copy to C_spad
    int stride_B = h, stride_C = h;
    float scale_factor_A = -1, scale_factor_B = 1;
    bool transpose_A = true, transpose_B = false;

    //printf("block syrk dim_I: %d, dim_K: %d\n", dim_I, dim_K);
    C_start = read_cycles();
    multi_workspace_blocked_syrk(dim_I, dim_K,
                 B, C,
                 stride_B, stride_C,
                 scale_factor_A, acc_cfgid, num_accel);
#if ReRoCC == 1
    rr_fence(acc_cfgid);
    //rr_fence(acc_cfgid1);
    //rr_fence(dma_cfgid);
    if (num_accel > 1)
      rr_set_opc(XCUSTOM_ACC, acc_cfgid);
#endif
    C_end = read_cycles();
    C_total += C_end - C_start;
    //printf("syrk: %llu\n", C_end - C_start);

    C_0 += chol_tile_len * (h+1);
    //workspace_JJ += chol_tile_len * (h + 1);
      //index ++;
    //hh -= CHOL_BLOCK_SIZE;
  }
#if ReRoCC == 1 
#if SPICA == 1
  rr_fence(dma_cfgid);
#endif
#endif
#if PRINT_CYCLES == 1
  printf("A_B cholesky cycles: %llu\n", cholesky_total);
  printf("A_B triangle solve cycles: %llu\n", triangle_total);
  //printf("A_B division overhead cycles: %llu\n", div_total);
  //printf("A_B truncated cycles: %llu\n", truncated_total);
  printf("C cycles: %llu\n", C_total);
  printf("memcpy cycles (includes cholesky): %llu\n", memcpy_total);
#endif
}
void dual_workspace_partial_factorization(float* workspace, float* AB_out, int supernode_w, int h, int chol_tile_len, int channel, int acc_cfgid1, int acc_cfgid2, int dma_cfgid) {

  float* AB_in = workspace;
 
  float* C_0 = workspace;
  int mvout_JJ = 0;

  uint64_t A_B_start = 0, A_B_mid = 0, A_B_end = 0, C_start = 0, C_end = 0;
  uint64_t cholesky_total = 0, triangle_total = 0, C_total = 0;

  int index = 0;
  bool granted = false; // ToDo
  uint64_t memcpy_start = 0, memcpy_end = 0, memcpy_total = 0;

  for(int JJ = 0; JJ < supernode_w; JJ += chol_tile_len){
    int w = min(supernode_w - JJ, chol_tile_len);
    //index = 0;
    float* workspace_JJ = (float*) AB_in + JJ * (h + 1);
    float* AB_out_JJ = (float*) AB_out + JJ * (h + 1);
    // J is the row/col index of the diagonal block
    // I is the row index of the subdiagonal block

      A_B_start = read_cycles();
      dense_block_cholesky(workspace_JJ, w, h, acc_cfgid1);
      //float* AB_IJ = AB_spad;// + w;

      //printf("JJ: %d, w: %d, col: %d\n", JJ, w, h-JJ-w);
      // copy out block LA
      A_B_mid = read_cycles();
      int hh = h - (JJ + w);
      // workspace_JJ: A, B input
      // B_out: B output
      //printf("tri solve JJ: %d, w: %d, hh: %d\n", JJ, w, hh);
      float* B_JJ = workspace_JJ + w;
      dense_workspace_triangle_solve(workspace_JJ, B_JJ, 
                                 w, 
                                 hh, 
                                 h, h, acc_cfgid1);
      //AB_IJ += TRSM_BLOCK_SIZE;
      //}
      A_B_end = read_cycles();
      cholesky_total += (A_B_mid - A_B_start);
      triangle_total += (A_B_end - A_B_mid);
      //printf("block chol: %d\n", A_B_mid - A_B_start);
      //printf("triangle: %d\n", A_B_end - A_B_mid);
      //float* B_out = AB_out_JJ + w;
#if SPICA == 1
      // TODO: pull out (to be configured once)
      if(JJ == 0){
        granted = false;
        while(!granted)
          dma_source_config(channel+1, granted, false, AB_in, h* sizeof(float));
        dma_nord_dest_config(channel+1, false, AB_out, h* sizeof(float));
      }
      granted = false;
      int mvout_width = w + (JJ - mvout_JJ);
      dma_memcpy_tile(channel+1, granted, mvout_JJ * (h+1) * sizeof(float), mvout_JJ * (h+1) * sizeof(float), index, mvout_width, (h-mvout_JJ) * sizeof(float));
      if(JJ + chol_tile_len >= supernode_w){
        while(!granted)
          dma_memcpy_tile(channel+1, granted, mvout_JJ * (h+1) * sizeof(float), mvout_JJ * (h+1) * sizeof(float), index, mvout_width, (h-mvout_JJ) * sizeof(float));
      }
      else if(granted)
        mvout_JJ += chol_tile_len;
#else
      int mvout_rows = w + (JJ - mvout_JJ);
      for(int row = 0; row < mvout_rows; row ++)
        memcpy((float*) AB_in + row * h, (float*) AB_out + row * h, (h-mvout_JJ) * sizeof(float));
#endif  
    
    // TODO: Make this symmetric and blocked
    //int dim_I = h - J - ww, dim_J = dim_I, dim_K = ww;
    int dim_I = h - JJ - w, dim_J = dim_I, dim_K = w;
    float* B = B_JJ; //workspace_JJ + ww;
    float* C = C_0 + w * (h + 1); // copy to C_spad
    int stride_B = h, stride_C = h;
    float scale_factor_A = -1, scale_factor_B = 1;
    bool transpose_A = true, transpose_B = false;

    //printf("block syrk dim_I: %d, dim_K: %d\n", dim_I, dim_K);
    C_start = read_cycles();
    dual_workspace_blocked_syrk(dim_I, dim_K,
                 B, C,
                 stride_B, stride_C,
                 scale_factor_A, acc_cfgid1, acc_cfgid2);
#if ReRoCC == 1
    rr_fence(acc_cfgid2);
    rr_fence(acc_cfgid1);
    //rr_fence(dma_cfgid);
    rr_set_opc(XCUSTOM_ACC, acc_cfgid1);
#endif
    C_end = read_cycles();
    C_total += C_end - C_start;
    //printf("syrk: %llu\n", C_end - C_start);

    C_0 += chol_tile_len * (h+1);
    //workspace_JJ += chol_tile_len * (h + 1);
      //index ++;
    //hh -= CHOL_BLOCK_SIZE;
  }
#if ReRoCC == 1
  rr_fence(dma_cfgid);
#endif
#if PRINT_CYCLES == 1
  printf("A_B cholesky cycles: %llu\n", cholesky_total);
  printf("A_B triangle solve cycles: %llu\n", triangle_total);
  //printf("A_B division overhead cycles: %llu\n", div_total);
  //printf("A_B truncated cycles: %llu\n", truncated_total);
  printf("C cycles: %llu\n", C_total);
  printf("memcpy cycles (includes cholesky): %llu\n", memcpy_total);
#endif
}

void full_workspace_partial_factorization(float* workspace, float* AB_out, int supernode_w, int h, int chol_tile_len, int channel, int acc_cfgid, int dma_cfgid) {

  //int hh = h;   // hh is the height of the current block column

  float* AB_in = workspace;
  //float* ABm_start = AB_spad;
  //float* m = AB_in;
  //float* C_spad = (float*) ABm_start + chol_tile_len * h; 
 
  float* C_0 = workspace;
  int mvout_JJ = 0;

  uint64_t A_B_start = 0, A_B_mid = 0, A_B_end = 0, C_start = 0, C_end = 0;
  uint64_t cholesky_total = 0, triangle_total = 0, C_total = 0;

  //int iter = 0;

  int index = 0;
  bool granted = false; // ToDo
  uint64_t memcpy_start = 0, memcpy_end = 0, memcpy_total = 0;

  for(int JJ = 0; JJ < supernode_w; JJ += chol_tile_len){
    int w = min(supernode_w - JJ, chol_tile_len);
    //index = 0;
    float* workspace_JJ = (float*) AB_in + JJ * (h + 1);
    float* AB_out_JJ = (float*) AB_out + JJ * (h + 1);
    // J is the row/col index of the diagonal block
    // I is the row index of the subdiagonal block
    //for(int J = 0; J < w; J += CHOL_BLOCK_SIZE) {
      // TODO: Make ww fixed and use cleanup iterations
      //int ww = min(w - J, CHOL_BLOCK_SIZE); // ww is the panel width.
  /* 
      if(JJ == 0) 
          for(int i = 0; i < chol_tile_len; i++)
              printf("%d\n", (int)(workspace_JJ[i+i*h]));
*/
      A_B_start = read_cycles();
      dense_block_cholesky(workspace_JJ, w, h, acc_cfgid);
      //float* AB_IJ = AB_spad;// + w;

      //printf("JJ: %d, w: %d, col: %d\n", JJ, w, h-JJ-w);
      // copy out block LA
      A_B_mid = read_cycles();
      //float* AB = (float*) AB_spad + J * h;
      //float* AB = iter == 0 ? AB_spad : (float*) AB_spad + CHOL_BLOCK_SIZE * h;
  /*    
      if(JJ == 0) 
          for(int i = 0; i < chol_tile_len; i++)
              printf("%d\n", (int)(workspace_JJ[i+i*h]));
    */  
      /*
#if SPICA == 1
      // TODO: pull out (to be configured once)
      dma_nord_source_config(channel, false, workspace_JJ, h* sizeof(float));
      dma_nord_dest_config(channel, false, AB_out_JJ, h* sizeof(float));
      dma_memcpy_tile(channel, granted, 0, 0, index, w, w * sizeof(float));
#else
      for(int row = 0; row < w; row ++)
        memcpy((float*) AB_out_JJ + row * h, (float*) workspace_JJ + row * h, w * sizeof(float));
#endif 
      */
      /*
#if ReRoCC == 1
      rr_fence(dma_cfgid); // TODO: replace with index check
#endif
      memcpy_end = read_cycles();
      memcpy_total += memcpy_end - memcpy_start;
      */
      //for(int I = JJ + w; I < h; I += TRSM_BLOCK_SIZE) {
      //int hh = min(h - I, TRSM_BLOCK_SIZE); // hh is the block height
      int hh = h - (JJ + w);
      // workspace_JJ: A, B input
      // B_out: B output
      //printf("tri solve JJ: %d, w: %d, hh: %d\n", JJ, w, hh);
      float* B_JJ = workspace_JJ + w;
      dense_workspace_triangle_solve(workspace_JJ, B_JJ, 
                                 w, 
                                 hh, 
                                 h, h, acc_cfgid);
      //AB_IJ += TRSM_BLOCK_SIZE;
      //}
      A_B_end = read_cycles();
      cholesky_total += (A_B_mid - A_B_start);
      triangle_total += (A_B_end - A_B_mid);
      //printf("block chol: %d\n", A_B_mid - A_B_start);
      //printf("triangle: %d\n", A_B_end - A_B_mid);
      //float* B_out = AB_out_JJ + w;
#if SPICA == 1
      // TODO: pull out (to be configured once)
      if(JJ == 0){
        granted = false;
        while(!granted)
          dma_source_config(channel+1, granted, false, AB_in, h* sizeof(float));
        dma_nord_dest_config(channel+1, false, AB_out, h* sizeof(float));
      }
      granted = false;
      int mvout_width = w + (JJ - mvout_JJ);
      dma_memcpy_tile(channel+1, granted, mvout_JJ * (h+1) * sizeof(float), mvout_JJ * (h+1) * sizeof(float), index, mvout_width, (h-mvout_JJ) * sizeof(float));
      if(JJ + chol_tile_len >= supernode_w){
        while(!granted)
          dma_memcpy_tile(channel+1, granted, mvout_JJ * (h+1) * sizeof(float), mvout_JJ * (h+1) * sizeof(float), index, mvout_width, (h-mvout_JJ) * sizeof(float));
      }
      else if(granted)
        mvout_JJ += chol_tile_len;
#else
      int mvout_rows = w + (JJ - mvout_JJ);
      for(int row = 0; row < mvout_rows; row ++)
        memcpy((float*) AB_in + row * h, (float*) AB_out + row * h, (h-mvout_JJ) * sizeof(float));
#endif  
    
    // TODO: Make this symmetric and blocked
    //int dim_I = h - J - ww, dim_J = dim_I, dim_K = ww;
    int dim_I = h - JJ - w, dim_J = dim_I, dim_K = w;
    float* B = B_JJ; //workspace_JJ + ww;
    float* C = C_0 + w * (h + 1); // copy to C_spad
    int stride_B = h, stride_C = h;
    float scale_factor_A = -1, scale_factor_B = 1;
    bool transpose_A = true, transpose_B = false;

    //printf("block syrk dim_I: %d, dim_K: %d\n", dim_I, dim_K);
    C_start = read_cycles();
    workspace_blocked_syrk(dim_I, dim_K,
                 B, C,
                 stride_B, stride_C,
                 scale_factor_A);
#if ReRoCC == 1
    rr_fence(acc_cfgid);
    //rr_fence(dma_cfgid);
#endif
    C_end = read_cycles();
    C_total += C_end - C_start;
    //printf("syrk: %llu\n", C_end - C_start);

    C_0 += chol_tile_len * (h+1);
    //workspace_JJ += chol_tile_len * (h + 1);
      //index ++;
    //hh -= CHOL_BLOCK_SIZE;
  }
#if ReRoCC == 1
#if SPICA == 1
  rr_fence(dma_cfgid);
#endif
#endif
#if PRINT_CYCLES == 1
  printf("A_B cholesky cycles: %llu\n", cholesky_total);
  printf("A_B triangle solve cycles: %llu\n", triangle_total);
  //printf("A_B division overhead cycles: %llu\n", div_total);
  //printf("A_B truncated cycles: %llu\n", truncated_total);
  printf("C cycles: %llu\n", C_total);
  printf("memcpy cycles (includes cholesky): %llu\n", memcpy_total);
#endif
}
// Splitting out LC = C - LB LB^T computation for profiling
void split_partial_factorization(float* AB, int w, int h, int acc_cfgid) {

  int hh = h;   // hh is the height of the current block column

  float* AB_JJ = AB;
  // J is the row/col index of the diagonal block
  // I is the row index of the subdiagonal block
  int J;
  int I;

  uint64_t A_B_start = 0, A_B_end = 0, A_B_mid = 0;
  uint64_t total_panel_chol = 0, total_triangular = 0;
  uint64_t truncated_start = 0, truncated_total = 0;

  // This is interleaved [LA; LB] computation
  for(J = 0; J < w; J += CHOL_BLOCK_SIZE) {
    // TODO: Make ww fixed and use cleanup iterations
    int ww = min(w - J, CHOL_BLOCK_SIZE); // ww is the panel width.

    A_B_start = read_cycles();
    dense_block_cholesky(AB_JJ, ww, h, acc_cfgid);
    float* AB_IJ = AB_JJ + ww;
    A_B_mid = read_cycles();
    for(I = J + ww; I < h; I += TRSM_BLOCK_SIZE) {
      // TODO: Make hh fixed and use cleanup iterations
      int hh = min(h - I, TRSM_BLOCK_SIZE); // hh is the block height
      dense_block_triangle_solve(AB_JJ, AB_IJ, 
                                  ww, 
                                  hh, 
                                  h, h, acc_cfgid);
      AB_IJ += TRSM_BLOCK_SIZE;
    }
    int dim_I = h - J - ww, dim_J = dim_I, dim_K = ww, max_J = w - J - ww;
    float* B = AB_JJ + ww;
    float* C = AB_JJ + ww * (h + 1);
    int stride_B = h, stride_C = h;
    float scale_factor_A = -1, scale_factor_B = 1;
    bool transpose_A = true, transpose_B = false; 
#if ReRoCC == 1
    rr_fence(acc_cfgid);
#endif
    //printf("truncated block syrk dim_I: %d, dim_J: %d, dim_K: %d\n", dim_I, max_J, dim_K);
    truncated_start = read_cycles();
#if GEMM_BLOCKED == 1
    truncated_blocked_syrk(dim_I, dim_K, max_J,
                 B, C,
                 stride_B, stride_C,
                 scale_factor_A);
#else
    if(max_J > 0){
       tiled_matmul_auto(max_J, dim_I, dim_K,
              (elem_t*)B, (elem_t*)B, (elem_t*)C, (elem_t*)C,
              stride_B, stride_B, stride_C, stride_C,
              scale_factor_A, scale_factor_B, MVIN_SCALE_IDENTITY,
              NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
              transpose_A, transpose_B,
              false, false,
              0,
              WS);
    }
#endif
#if ReRoCC == 1
    rr_fence(acc_cfgid);
#endif
    A_B_end = read_cycles();
    truncated_total += (A_B_end - truncated_start);
    total_panel_chol += (A_B_mid - A_B_start);
    total_triangular += (A_B_end - A_B_mid);
    AB_JJ += CHOL_BLOCK_SIZE * (h + 1);
    hh -= CHOL_BLOCK_SIZE;
  }
  // This is LC = C - LB LB^T computation
  int dim_I = h - w, dim_J = dim_I, dim_K = w;
  float* B = AB + w;
  float* C = AB + w * (h + 1);
  int stride_B = h, stride_C = h;
  float scale_factor_A = -1, scale_factor_B = 1;
  bool transpose_A = true, transpose_B = false;

  uint64_t C_start = 0, C_end = 0;
  C_start = read_cycles();
#if GEMM_BLOCKED == 1
  blocked_syrk(dim_I, dim_K,
               B, C,
               stride_B, stride_C,
               scale_factor_A);
#else
  tiled_matmul_auto(dim_I, dim_J, dim_K,
          (elem_t*)B, (elem_t*)B, (elem_t*)C, (elem_t*)C,
          stride_B, stride_B, stride_C, stride_C,
          scale_factor_B, scale_factor_A, MVIN_SCALE_IDENTITY,
          NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
          transpose_A, transpose_B,
          false, false,
          0,
          WS);
#endif
#if ReRoCC == 1
  rr_fence(acc_cfgid);
#endif
  C_end = read_cycles();

#if PRINT_CYCLES == 1
  printf("A_B cholesky cycles: %llu\n", total_panel_chol);
  printf("A_B triangle solve cycles: %llu\n", total_triangular);
  //printf("A_B division overhead cycles: %llu\n", div_total);
  printf("A_B truncated cycles: %llu\n", truncated_total);
  printf("C cycles: %llu\n", C_end - C_start);
#endif
}

// Do partial cholesky factorization by first doing as dense cholesky on the diagonal block
// Then doing triangle solve
void mix_partial_factorization(float* AB, int w, int h, int acc_cfgid) {

  int hh = h;   // hh is the height of the current block column

  float* AB_JJ = AB;
  // J is the row/col index of the diagonal block
  // I is the row index of the subdiagonal block
  int J;
  int I;

  uint64_t A_B_start = 0, A_B_mid = 0, A_B_end = 0, C_start = 0, C_end = 0;
  uint64_t cholesky_total = 0, triangle_total = 0, C_total = 0;
  for(J = 0; J < w; J += CHOL_BLOCK_SIZE) {
    // TODO: Make ww fixed and use cleanup iterations
    int ww = min(w - J, CHOL_BLOCK_SIZE); // ww is the panel width.
    A_B_start = read_cycles();
    dense_block_cholesky(AB_JJ, ww, h, acc_cfgid);
    A_B_mid = read_cycles();
    float* AB_IJ = AB_JJ + ww;
    for(I = J + ww; I < h; I += TRSM_BLOCK_SIZE) {
      // TODO: Make hh fixed and use cleanup iterations
      int hh = min(h - I, TRSM_BLOCK_SIZE); // hh is the block height
      dense_block_triangle_solve(AB_JJ, AB_IJ, 
                                 ww, 
                                 hh, 
                                 h, h, acc_cfgid);
      AB_IJ += TRSM_BLOCK_SIZE;
    }
    A_B_end = read_cycles();
    cholesky_total += (A_B_mid - A_B_start);
    triangle_total += (A_B_end - A_B_mid);

    // TODO: Make this symmetric and blocked
    int dim_I = h - J - ww, dim_J = dim_I, dim_K = ww;
    float* B = AB_JJ + ww;
    float* C = AB_JJ + ww * (h + 1);
    int stride_B = h, stride_C = h;
    float scale_factor_A = -1, scale_factor_B = 1;
    bool transpose_A = true, transpose_B = false;

    C_start = read_cycles();
    blocked_syrk(dim_I, dim_K,
                 B, C,
                 stride_B, stride_C,
                 scale_factor_A);
#if ReRoCC == 1
    rr_fence(acc_cfgid);
#endif
    C_end = read_cycles();
    C_total += C_end - C_start;

    // matmul(dim_I, dim_J, dim_K,
    //      B, B, C, 
    //      stride_B, stride_B, stride_C,
    //      scale_factor_A, scale_factor_B,
    //      transpose_A, transpose_B);

    AB_JJ += CHOL_BLOCK_SIZE * (h + 1);
    hh -= CHOL_BLOCK_SIZE;
  }
#if PRINT_CYCLES == 1
  printf("A_B cholesky cycles: %llu\n", cholesky_total);
  printf("A_B triangle solve cycles: %llu\n", triangle_total);
  //printf("A_B truncated cycles: %llu\n", truncated_total);
  printf("C cycles: %llu\n", C_total);
#endif
}

void set_strictly_upper_trianguler(float a, float* x, int w, int h, int stride) {
  for(int j = 0; j < w; j++) {
    for(int i = 0; i < j && i < h; i++) {
      x[i] = a;
    }
    x += stride;
  }
}

// Check the lower triangular part of M equals M_correct
// Returns 0 if the matrices are the same
// Returns nonzero if there is a mismatched entry
int check_tril_result(float* m, float* m_correct,
                      int w, int h, int stride,
                      double tol) {
  for(int j = 0; j < w; j++) {
    for(int i = j; i < h; i++) {
      double abs_err = fabs(m_correct[j * stride + i] - m[j * stride + i]);
      double abs_A = fabs(m_correct[j * stride + i]);
      double rel_err = abs_A != 0? abs_err / abs_A :
                       abs_err == 0? 0 : INFINITY;

      // printf("%.10e, ", rel_err);

      if(rel_err > tol) {
        printf("Relative error at (%d, %d) exceeded threshold: %.8e\n", i, j, rel_err);
        printf("Correct: %d, Value: %d\n", (int)(m_correct[j * stride + i]*1000), (int)(m[j * stride + i]*1000));
        break;
        //return 1;
      }
    }
    // printf("\n");
  }
  return 0;
}

// Do B += Ascale * A. Both A and B are square and col major. 
// A is Adim x Adim. B is Bdim x Bdim. Bdim >= Adim
// Bidx must be a superset of Aidx and in the same order
void cpu_sparse_matrix_add(float* A, int Adim, int Astride, int* Aidx,
                       float* B, int Bdim, int Bstride, int* Bidx,
                       float Ascale) {
  int Aj = 0;
  float* A_0j = A;
  float* B_0j = B;
  for(int Bj = 0; Bj < Bdim; Bj++, B_0j += Bstride) {
    float* B_ij = B_0j;
    if(Aidx[Aj] == Bidx[Bj]) {
      int Ai = 0;
      float* A_ij = A_0j;
      for(int Bi = 0; Bi < Bdim; Bi++, B_ij++) {
        if(Aidx[Ai] == Bidx[Bi]) {
          *B_ij += Ascale * (*A_ij);
          Ai++;
          A_ij++;
        }
      }
      Aj++;
      A_0j += Astride;
    }
  }
}

// Add two dense blocks together
// Bblk = scaleA * Ablk + scaleB * Bblk
void dense_block_add(float* Ablk, float* Bblk, 
                     int height, int width,
                     int Astride, int Bstride,
                     float Ascale, float Bscale) {

  //printf("width: %d, height: %d A stride: %d, B stride: %d, A: 0x%08lx, B: 0x%08lx\n", width, height, Astride, Bstride, Ablk, Bblk);  
  /*
  if(height < 2 && width < DIM){
  float* Ablk_0j = Ablk;                             
  float* Bblk_0j = Bblk;
  for(int j = 0; j < width; j++) {
    float* Ablk_ij = Ablk_0j;
    float* Bblk_ij = Bblk_0j;
    for(int i = 0; i < height; i++) {
      *Bblk_ij = Ascale * *Ablk_ij + Bscale * *Bblk_ij;
      Ablk_ij++;
      Bblk_ij++;
    }
    Ablk_0j += Astride;
    Bblk_0j += Bstride;
  }
  }
  else
  */
#if MATADD == 1
  tiled_matadd_stride_auto(width, height, Ascale, Bscale, 1,
          Astride, Bstride, Bstride, Ablk, Bblk, Bblk,
          false, WS);
#else
  tiled_resadd_stride_auto(width, height, Ascale, Bscale, 1,
          Astride, Bstride, Bstride, Ablk, Bblk, Bblk,
          false, WS);
#endif
}
// Add two dense blocks together
// Bblk = scaleA * Ablk + scaleB * Bblk
void packed_dense_block_add(float* A_blk_start, float* B_blk_start, 
                     int h, int H_height, int* width_blk,
                     int Astride, int Bstride,
                     int* A_blk, int* B_blk, int num_blk, bool config) {
/*
   tiled_packed_matadd(Jwidth, &width_blk[i][J], h, H_height, H_height,
          //Jwidth, width_blk[i][I],
          1, 1, 1,
          A_blk_start, B_blk_start, B_blk_start,
          &A_blk[i][J], &B_blk[i][J], num_blk[i] - J, false, J == 0);
*/
/*
   for(int J = 0; J < num_blk - 1; J++)
       A_blk_start += *(width_blk + J) * h;

   for(int J = num_blk-1; J >= 0; J--){
       float* B_col = (float*) B_blk_start + *(B_blk + J) * H_height;
       float* A = (float*) A_blk_start + *(A_blk + J);
       float* B = (float*) B_col + *(B_blk + J);
       tiled_packed_matadd(*(width_blk+J), (width_blk+J), h, H_height, H_height,
               1, 1, 1,
               A, B, B,
               (int*) (A_blk + J), (int*) (B_blk + J), 
               num_blk - J, false, J == num_blk - 1);
       if(J != 0) A_blk_start -= *(width_blk + J - 1) * h;
   }
   */
    
   for(int J = 0; J < num_blk; J++){
       //printf("J: %d, num_blk: %d, A: %d, B: %d\n", J, num_blk, *(A_blk+J), *(B_blk+J));
       float* B_col = (float*) B_blk_start + *(B_blk + J) * Bstride;//H_height;
       float* A = (float*) A_blk_start + *(A_blk + J);
       float* B = (float*) B_col + *(B_blk + J);
       tiled_packed_matadd(*(width_blk+J), (width_blk+J), 
               //h, H_height, H_height,
               Astride, Bstride, Bstride,
               1, 1, 1,
               A, B, B,
               (int*) (A_blk + J), (int*) (B_blk + J), 
               num_blk - J, false, J == 0 && config);
       A_blk_start += *(width_blk + J) * Astride;//h;
   }
}


void interleave_block_sparse_matrix_add(float* A, int Adim, int Astride, int* Aidx,
                        float* B, int Bdim, int Bstride, int* Bidx,
                        float Ascale, int acc_cfgid) {

  bool in_blk = false;
  int* Aidx_orig = Aidx;
  int* Bidx_orig = Bidx;
  int num_blks = 0;
  int idx = 0;
  uint64_t start = 0, end = 0;

  float* A_col = A; float* B_col = B;
  for(int Bi = 0; Bi < Bdim; Bi++, Bidx++) {
    if(*Aidx == *Bidx) {
      if(!in_blk) {
        in_blk = true;
        A_blk_start[idx] = Aidx - Aidx_orig;
        B_blk_start[idx] = Bidx - Bidx_orig;
        blk_width[idx] = 1;
        if(Bi == Bdim - 1) {
          num_blks ++;
          in_blk = false;
  //start = read_cycles();
          for(int J = 0; J < num_blks; J++){
              float* A_blk = A_col + A_blk_start[idx];
              float* B_blk = B_col + B_blk_start[idx] + B_blk_start[J] * Bstride;
              printf("case 3 I: %d, J: %d, row: %d, col: %d\n", idx, J, blk_width[idx], blk_width[J]);
              dense_block_add(A_blk, B_blk, blk_width[idx], blk_width[J], Astride, Bstride, 1, 1);
              A_col += blk_width[J] * Astride;
          }
  //rr_fence(acc_cfgid);
  //end = read_cycles();
  //matrix_add_cycles += end - start;
          A_col = A;
          //idx ++;
        }
        else
          num_blks++;
      }
      else {
        blk_width[idx] ++;
        // Start new block if block size too large
        if(blk_width[idx] >= MAX_DENSE_BLK_SIZE || Bi == Bdim - 1) {
          in_blk = false;
  //start = read_cycles();
          for(int J = 0; J < num_blks; J++){
              float* A_blk = A_col + A_blk_start[idx];
              float* B_blk = B_col + B_blk_start[idx] + B_blk_start[J] * Bstride;
              printf("case 2 I: %d, J: %d, row: %d, col: %d\n", idx, J, blk_width[idx], blk_width[J]);
              dense_block_add(A_blk, B_blk, blk_width[idx], blk_width[J], Astride, Bstride, 1, 1);
              A_col += blk_width[J] * Astride;
          }
  //rr_fence(acc_cfgid);
  //end = read_cycles();
  //matrix_add_cycles += end - start;
          A_col = A;
          idx ++;
        }
      }
      Aidx++;
    }
    else {
      if(in_blk) {
        in_blk = false;
  //start = read_cycles();
        for(int J = 0; J < num_blks; J++){
            float* A_blk = A_col + A_blk_start[idx];
            float* B_blk = B_col + B_blk_start[idx] + B_blk_start[J] * Bstride;
            printf("case 1 I: %d, J: %d, row: %d, col: %d\n", idx, J, blk_width[idx], blk_width[J]);
            dense_block_add(A_blk, B_blk, blk_width[idx], blk_width[J], Astride, Bstride, 1, 1);
            A_col += blk_width[J] * Astride;
        }
  //rr_fence(acc_cfgid);
  //end = read_cycles();
  //matrix_add_cycles += end - start;
        A_col = A;
        idx ++;
      }
    }
  }
  //printf("number of blocks: %d\n",  num_blks);
#if ReRoCC == 1
  rr_fence(acc_cfgid);
#endif
}

/*
// Group indices in A that are consecutive in B into blocks
// A_blk_start, B_blk_start, blk_width should already be allocated
// and should be at least Alen long
void group_block_indices(int* Aidx, int Alen,
                         int* Bidx, int Blen,
                         int* A_blk_start, int* B_blk_start, 
                         int* blk_width, int* num_blks) {

  int* A_blk_start_orig = A_blk_start;
  bool in_blk = false;
  int* Aidx_orig = Aidx;
  int* Bidx_orig = Bidx;
  *num_blks = 0;
  for(int Bi = 0; Bi < Blen; Bi++, Bidx++) {
    if(*Aidx == *Bidx) {
      if(!in_blk) {
        in_blk = true;
        *A_blk_start = Aidx - Aidx_orig;
        *B_blk_start = Bidx - Bidx_orig;
        *blk_width = 1;
        (*num_blks)++;
      }
      else {
        (*blk_width)++;
        // Start new block if block size too large
        if(*blk_width >= MAX_DENSE_BLK_SIZE) {
          in_blk = false;
          A_blk_start++;
          B_blk_start++;
          blk_width++;
        }
      }
      Aidx++;
    }
    else {
      if(in_blk) {
        in_blk = false;
        A_blk_start++;
        B_blk_start++;
        blk_width++;
      }
    }
  }
}
// Do B += A. Both A and B are square and col major. 
// A is Adim x Adim. B is Bdim x Bdim. Bdim >= Adim
// Bidx must be a superset of Aidx and in the same order
void block_sparse_matrix_add(float* A, int Adim, int Astride, int* Aidx,
                        float* B, int Bdim, int Bstride, int* Bidx,
                        float Ascale, int acc_cfgid) {

  int* A_blk_start = (int*) my_malloc(Adim * sizeof(int));
  int* B_blk_start = (int*) my_malloc(Adim * sizeof(int));
  int* blk_width = (int*) my_malloc(Adim * sizeof(int));
  int num_blks;
  uint64_t start = 0, end = 0;
  start = read_cycles();
  group_block_indices(Aidx, Adim, Bidx, Bdim, A_blk_start, B_blk_start, blk_width, &num_blks);
  end = read_cycles();
  group_block_cycles += end - start;

  float* A_col = A;
  //printf("number of blocks: %d\n",  num_blks);
  start = read_cycles();
  for(int J = 0; J < num_blks; J++) {
    float* B_col = B + B_blk_start[J] * Bstride;
    for(int I = J; I < num_blks; I++) {
      float* A_blk = A_col + A_blk_start[I];
      float* B_blk = B_col + B_blk_start[I];
      //printf("I: %d, J: %d, row: %d, col: %d\n", I, J, blk_width[I], blk_width[J]);
      dense_block_add(A_blk, B_blk, blk_width[I], blk_width[J], Astride, Bstride, 1, 1);
    }
    A_col += blk_width[J] * Astride;
  }
#if ReRoCC == 1
  rr_fence(acc_cfgid);
#endif
  end = read_cycles();
  matrix_add_cycles += end - start;
}
*/
// From a list of values, build a reverse
// lookup table from values to index
// indices must be already allocated to the maximum entry in values
void build_reverse_lookup(int* values, 
                          int len,
                          int* indices) {
  for(int i = 0; i < len; i++) {
    indices[values[i]] = i;
  }
}

// Group indices in A that are consecutive in B into blocks
// A_blk_start, B_blk_start, blk_width should already be allocated
// and should be at least Alen long
// B_lookup should be a reverse lookup from entry in Aidx to index in Bidx
void group_block_indices(int* Aidx, int Alen,
                          int* A_blk_start, int* B_blk_start, 
                          int* blk_width, int* num_blks,
                          int* B_lookup) {

  // Prepare for initial ++ operation
  A_blk_start--;
  B_blk_start--;
  blk_width--;

  int last_matched_idx = INT_MAX;
  *num_blks = 0;
  for(int i = 0; i < Alen; i++) {
    int Aval = Aidx[i];
    int Bidx = B_lookup[Aval];
    //if(Bidx != last_matched_idx + 1) {
    if(Bidx != last_matched_idx + 1 || *blk_width >= MAX_DENSE_BLK_SIZE) {
      *(++A_blk_start) = i;
      *(++B_blk_start) = Bidx;
      *(++blk_width) = 1;
      (*num_blks)++;
    }
    else {
      (*blk_width)++;
    }
    last_matched_idx = Bidx;
  } 
}

// Do B += A. Both A and B are square and col major. 
// A is Adim x Adim. B is Bdim x Bdim. Bdim >= Adim
// Bidx must be a superset of Aidx and in the same order
void block_sparse_matrix_add(float* A, int Adim, int Astride, int* Aidx,
                        float* B, int Bdim, int Bstride, int* Bidx,
                        float Ascale, 
                        int* B_lookup, int acc_cfgid) {
  int* A_blk_start = (int*) my_malloc(Adim * sizeof(int));
  int* B_blk_start = (int*) my_malloc(Adim * sizeof(int));
  int* blk_width = (int*) my_malloc(Adim * sizeof(int));
  int num_blks;
  uint64_t start = 0, end = 0;
  start = read_cycles();
  group_block_indices(Aidx, Adim, A_blk_start, B_blk_start, blk_width, &num_blks, B_lookup);
  end = read_cycles();
  group_block_cycles += end - start;

  float* A_col = A;
  //printf("number of blocks: %d\n",  num_blks);
  start = read_cycles();
  for(int J = 0; J < num_blks; J++) {
    float* B_col = B + B_blk_start[J] * Bstride;
    for(int I = J; I < num_blks; I++) {
      float* A_blk = A_col + A_blk_start[I];
      float* B_blk = B_col + B_blk_start[I];
      //printf("B: 0x%08lx, B_blk: 0x%08lx, B_col: 0x%08lx, offset: %d\n", B, B_blk, B_col, B_blk_start[I]);
      //printf("I: %d, J: %d, row: %d, col: %d\n", I, J, blk_width[I], blk_width[J]);
      dense_block_add(A_blk, B_blk, blk_width[I], blk_width[J], Astride, Bstride, 1, 1);
    }
    A_col += blk_width[J] * Astride;
  }
  if(acc_cfgid != -1){
#if ReRoCC == 1
    rr_fence(acc_cfgid);
#endif
    end = read_cycles();
    matrix_add_cycles += end - start;
  }
}
// Do B += A. Extend the case of sparse_block_add3 to nonsquare case
// A is Ah x Aw. Ah >= Aw. B is larger than A
// Bidx must be a superset of Aidx and in the same order
void opt_block_sparse_matrix_add(float* A, int Ah, int Aw, int Astride, int* Aidx,
                        float* B, int Bh, int Bw, int Bstride, int* Bidx,
                        float Ascale, 
                        int* B_lookup, int acc_cfgid) {
  int* A_blk_start = (int*) my_malloc(Ah * sizeof(int));
  int* B_blk_start = (int*) my_malloc(Ah * sizeof(int));
  int* blk_widths = (int*) my_malloc(Ah * sizeof(int));
  int num_blks;

  uint64_t start = 0, end = 0;
  start = read_cycles();
  group_block_indices(Aidx, Ah, A_blk_start, B_blk_start, blk_widths, &num_blks, B_lookup);
  end = read_cycles();
  group_block_cycles += end - start;

  start = read_cycles();
  for(int J = 0; A_blk_start[J] < Aw; J++) {
    int blk_start = A_blk_start[J];
    int blk_width = blk_widths[J];
    int Jwidth = blk_start + blk_width < Aw? blk_width : Aw - blk_start;
    float* A_col = A + blk_start * Astride;
    float* B_col = B + B_blk_start[J] * Bstride;

    for(int I = J; I < num_blks; I++) {
      float* A_blk = A_col + A_blk_start[I];
      float* B_blk = B_col + B_blk_start[I];
      dense_block_add(A_blk, B_blk, blk_widths[I], Jwidth, Astride, Bstride, 1, 1);
    }
  }
  if(acc_cfgid != -1){
#if ReRoCC == 1
    rr_fence(acc_cfgid);
#endif
    end = read_cycles();
    matrix_add_cycles += end - start;
  }
}

void tile_AtA_supernode_pointer(int f, int this_nfactors, //int M, int N,
        int max_factor_height, const int* this_factor_heights, const int* this_factor_widths, float** this_factor_data,
        int H_h, int H_w, int* H_ridx, float* H_data,
        float* workspace, float* data_start,
        int** A_this_blk, int** B_this_blk, int** width_this_blk, int* num_this_blk,
        int dma_i, int num_channel, int acc_cfgid, int dma_cfgid, int add_cfgid){

  bool granted = false;
  int channel = 0;

  uint64_t start = 0, end = 0, mid1 = 0, mid2 = 0;
  uint64_t AtA_cycles = 0;
  uint64_t memcpy_cycles = 0, cholesky_cycles = 0, matadd_cycles = 0; 
  uint64_t expected_cycles = 0;
  start = read_cycles();
  for(int i = 0; i < num_channel; i++){
    granted = false;
    while(!granted)
      dma_set_state(granted, 0, i);
    dma_nord_dest_config(i, false, (elem_t*) data_start, max_factor_height * sizeof(elem_t));
  }
  float* data_sp = (float*) (data_start);
  int acc_i = 0;
  float* base_addr = workspace;
  uint64_t data_offset = 0;//base_addr + SPAD_TOTAL_BYTES/2;  
  while(dma_i < this_nfactors){ 
      granted = false;
      channel = dma_i % num_channel;
      int real_dma_i = dma_i + f;
      int h = this_factor_heights[real_dma_i];
      int w = this_factor_widths[real_dma_i];
      //int* ridx = factor_ridx[real_dma_i];
      float* data = this_factor_data[real_dma_i];
      //memcpy((elem_t*) data_offset, data, h * w * sizeof(float));
      dma_source_config(channel, granted, false, data, h * sizeof(elem_t));
      if(granted){
        dma_nord_memcpy_tile(channel, 0, data_offset, dma_i, w, h * sizeof(elem_t));
        //printf("dma_i: %d, channel: %d\n", dma_i, channel);
        dma_i ++;
        data_offset += max_factor_height * w * sizeof(elem_t);
      }
      
      int probe = 0;
      while(acc_i < this_nfactors){
        channel = acc_i % num_channel;
        dma_probe_state(probe, channel);
        if(probe > acc_i){
          h = this_factor_heights[f+acc_i];
          w = this_factor_widths[f+acc_i];
          //printf("probe: %d, acc_i: %d, dma_i: %d\n ", probe, acc_i, dma_i);
          tiled_matmul_small(h, h, w,
               (elem_t*) data_sp, (elem_t*) data_sp, NULL, (elem_t*) workspace,
               max_factor_height, max_factor_height, max_factor_height, max_factor_height,
               //1, 1, 1,
               //ceil_divide_int(h, DIM), ceil_divide_int(h, DIM), ceil_divide_int(w, DIM),
               //0, 1,
               1, 1,
               true, false, //false, false,
               0, acc_i == 0);

          workspace += max_factor_height * h;
          data_sp += max_factor_height * w;
           
          acc_i++;
        }
        else
            break;
      }

  }
//rr_fence(dma_cfgid);
  for(int i = acc_i; i < this_nfactors; ) {
      channel = i % num_channel;
      int probe = 0;
      dma_probe_state(probe, channel);
      if(probe <= acc_i) continue;
      int h = this_factor_heights[f+i];
      int w = this_factor_widths[f+i];

      tiled_matmul_small(h, h, w,
            (elem_t*) data_sp, (elem_t*) data_sp, NULL, (elem_t*) workspace,
            max_factor_height, max_factor_height, max_factor_height, max_factor_height,
            1, 1,
            true, false, 
            0, i == 0);
  
      workspace += max_factor_height * h;
      data_sp += max_factor_height * w;
      i++;
  }

  workspace = (float*) base_addr;
#if ReRoCC == 1
  rr_fence(acc_cfgid);
  rr_fence(dma_cfgid);
#endif
  mid1 = read_cycles();

  //expected_cycles = 0;
  for(int i = f; i < f+this_nfactors; i++){
      //sparse_matrix_add3_2(workspace, h, h, ridx,
      //                     H_data, H_h, H_h, H_ridx,
      //                     1, H_lookup);
      float* A_col = workspace;
      int h = this_factor_heights[i];
      //printf("h: %d, A: 0x%08lx, B: 0x%08lx\n", h, A_this_blk[i], B_this_blk[i]);
      packed_dense_block_add(workspace, H_data,
              h, H_h, width_this_blk[i],
              max_factor_height, H_h,
              A_this_blk[i], B_this_blk[i],
              num_this_blk[i], i == f);
      /*
      for(int J = 0; J < num_this_blk[i]; J++){
          float* B_col = H_data + B_this_blk[i][J] * H_h;
          for(int I = J; I < num_this_blk[i]; I++){
              //printf("factor: %d, I: %d, J: %d, row: %d, col: %d\n", i, I, J, width_this_blk[i][I], width_this_blk[i][J]);
              //expected_cycles += width_this_blk[i][I] * ceil_divide_int(width_this_blk[i][J], DIM) * 4;
              float* A = A_col + A_this_blk[i][I];
              float* B = B_col + B_this_blk[i][I];
              dense_block_add(A, B, width_this_blk[i][I], width_this_blk[i][J], h, H_h, 1, 1);
          }
          A_col += width_this_blk[i][J] * h;
      }
      */
#if ReRoCC == 1
#if MATADD == 0
      // configure accel again
      //rr_fence(acc_cfgid);
#endif
#endif
      workspace += max_factor_height * h;
  }
#if ReRoCC == 1
#if MATADD == 1
  rr_fence(add_cfgid);
#else
  rr_fence(acc_cfgid);
#endif
#endif
  mid2 = read_cycles();
  //printf("need AtA merge\n");
  //fflush(stdout);

  workspace = (float*) base_addr;
  int H_square = (H_h - 1) * H_h;
  for(int i = f; i < f+this_nfactors; i++){
      int num_block = num_this_blk[i];
      int h = this_factor_heights[i];
      float* A_col = workspace + h - 1;
      float* B_col = H_data + H_h - 1;
      for(int J = 0; J < num_block; J++){
          float* B = B_col + B_this_blk[i][J] * H_h;
          
          tiled_unpacked_matadd(width_this_blk[i][J], 1, max_factor_height, H_h, H_h, 
                 1, 1, 1,
                 A_col, B, B,
                 false, J == 0 && i == f);
          
          //dense_block_add(A_col, B, 1, width_this_blk[i][J],
          //        h, H_h, 1, 1);
          A_col += max_factor_height * width_this_blk[i][J];
#if ReRoCC == 1
#if MATADD == 0
          // configure accel again
          //rr_fence(acc_cfgid);
#endif
#endif
      }
      float* B = B_col + H_square; //(H_h - 1) * H_h;
      *B = *B + *A_col;
      workspace += max_factor_height * h;
  }
#if ReRoCC == 1
#if MATADD == 1
  rr_fence(add_cfgid);
#else
  rr_fence(acc_cfgid);
#endif
#endif

  end = read_cycles();
  AtA_cycles = end - start;
  //printf("expected block add cycle: %llu\n", expected_cycles);
#if PRINT_CYCLES == 1
  printf("AtA cycles: %llu (prefetch+matmul: %llu, matadd: %llu, last row: %llu) \n", AtA_cycles, mid1 - start, mid2 - mid1, end -  mid2);
#endif
  //printf("grouping: %llu, block add: %llu\n", mid2 - mid1, end - mid2);

}
void tile_AtA_supernode_pointer_nodma(int f, int this_nfactors, //int M, int N,
        int max_factor_height, const int* this_factor_heights, const int* this_factor_widths, float** this_factor_data,
        int H_h, int H_w, int* H_ridx, float* H_data,
        float* workspace, float* data_start,
        int** A_this_blk, int** B_this_blk, int** width_this_blk, int* num_this_blk,
        int dma_i, int acc_cfgid, int add_cfgid){

  bool granted = false;
  int channel = 0;

  uint64_t start = 0, end = 0, mid1 = 0, mid2 = 0;
  uint64_t AtA_cycles = 0;
  uint64_t memcpy_cycles = 0, cholesky_cycles = 0, matadd_cycles = 0; 
  uint64_t expected_cycles = 0;
  start = read_cycles();
  float* base_addr = workspace;

//rr_fence(dma_cfgid);
  for(int i = 0; i < this_nfactors; i++) {
      int h = this_factor_heights[f+i];
      int w = this_factor_widths[f+i];
      float* data = this_factor_data[i];

      tiled_matmul_small(h, h, w,
            (elem_t*) data, (elem_t*) data, NULL, (elem_t*) workspace,
            h, h, max_factor_height, max_factor_height,
            1, 1,
            true, false, 
            0, true);
#if ReRoCC == 1
      // configure accel again
      rr_fence(acc_cfgid);
#endif
  
      workspace += max_factor_height * h;
  }
  workspace = (float*) base_addr;
#if ReRoCC == 1
  rr_fence(acc_cfgid);
  //rr_fence(dma_cfgid);
#endif
  mid1 = read_cycles();

  //expected_cycles = 0;
  for(int i = f; i < f+this_nfactors; i++){
      //sparse_matrix_add3_2(workspace, h, h, ridx,
      //                     H_data, H_h, H_h, H_ridx,
      //                     1, H_lookup);
      float* A_col = workspace;
      int h = this_factor_heights[i];
      //printf("h: %d, A: 0x%08lx, B: 0x%08lx\n", h, A_this_blk[i], B_this_blk[i]);
      packed_dense_block_add(workspace, H_data,
              h, H_h, width_this_blk[i],
              max_factor_height, H_h,
              A_this_blk[i], B_this_blk[i],
              num_this_blk[i], i == f);
      
#if ReRoCC == 1
#if MATADD == 0
      // configure accel again
      //rr_fence(acc_cfgid);
#endif
#endif
      workspace += max_factor_height * h;
  }
#if ReRoCC == 1
#if MATADD == 1
  rr_fence(add_cfgid);
#else
  rr_fence(acc_cfgid);
#endif
#endif
  mid2 = read_cycles();

  workspace = (float*) base_addr;
  int H_square = (H_h - 1) * H_h;
  for(int i = f; i < f+this_nfactors; i++){
      int num_block = num_this_blk[i];
      int h = this_factor_heights[i];
      float* A_col = workspace + h - 1;
      float* B_col = H_data + H_h - 1;
      for(int J = 0; J < num_block; J++){
          float* B = B_col + B_this_blk[i][J] * H_h;
          
          tiled_unpacked_matadd(width_this_blk[i][J], 1, max_factor_height, H_h, H_h, 
                 1, 1, 1,
                 A_col, B, B,
                 false, J == 0 && i == f);
          
          //dense_block_add(A_col, B, 1, width_this_blk[i][J],
          //        h, H_h, 1, 1);
          A_col += max_factor_height * width_this_blk[i][J];
#if ReRoCC == 1
#if MATADD == 0
	  // configure accel again
	  //rr_fence(acc_cfgid);
#endif
#endif
      }
      float* B = B_col + H_square; //(H_h - 1) * H_h;
      *B = *B + *A_col;
      workspace += max_factor_height * h;
  }
#if ReRoCC == 1
#if MATADD == 1
  rr_fence(add_cfgid);
#else
  rr_fence(acc_cfgid);
#endif
#endif

  end = read_cycles();
  AtA_cycles = end - start;
  //printf("expected block add cycle: %llu\n", expected_cycles);
#if PRINT_CYCLES == 1
  printf("AtA cycles: %llu (prefetch+matmul: %llu, matadd: %llu, last row: %llu) \n", AtA_cycles, mid1 - start, mid2 - mid1, end -  mid2);
#endif
  //printf("grouping: %llu, block add: %llu\n", mid2 - mid1, end - mid2);

}

void dual_tile_AtA_supernode_pointer(int f, int this_nfactors, //int M, int N,
        int max_factor_height, const int* this_factor_heights, const int* this_factor_widths, float** this_factor_data,
        int H_h, int H_w, int* H_ridx, float* H_data,
        float* workspace, float* data_start,
        int** A_this_blk, int** B_this_blk, int** width_this_blk, int* num_this_blk,
        int dma_i, int num_channel, int acc_cfgid1, int acc_cfgid2, int dma_cfgid, int add_cfgid){

  bool granted = false;
  int channel = 0;

  uint64_t start = 0, end = 0, mid1 = 0, mid2 = 0;
  uint64_t AtA_cycles = 0;
  uint64_t memcpy_cycles = 0, cholesky_cycles = 0, matadd_cycles = 0; 
  uint64_t expected_cycles = 0;
  start = read_cycles();
  for(int i = 0; i < num_channel; i++){
    granted = false;
    while(!granted)
      dma_set_state(granted, 0, i);
    dma_nord_dest_config(i, false, (elem_t*) data_start, max_factor_height * sizeof(elem_t));
  }
  float* data_sp = (float*) (data_start);
  int acc_i = 0;
  float* base_addr = workspace;
  uint64_t data_offset = 0;//base_addr + SPAD_TOTAL_BYTES/2;  
  while(dma_i < this_nfactors){ 
      granted = false;
      channel = dma_i % num_channel;
      int real_dma_i = dma_i + f;
      int h = this_factor_heights[real_dma_i];
      int w = this_factor_widths[real_dma_i];
      //int* ridx = factor_ridx[real_dma_i];
      float* data = this_factor_data[real_dma_i];
      //memcpy((elem_t*) data_offset, data, h * w * sizeof(float));
      dma_source_config(channel, granted, false, data, h * sizeof(elem_t));
      if(granted){
        dma_nord_memcpy_tile(channel, 0, data_offset, dma_i, w, h * sizeof(elem_t));
        //printf("dma_i: %d, channel: %d\n", dma_i, channel);
        dma_i ++;
        data_offset += max_factor_height * w * sizeof(elem_t);
      }
      
      int probe = 0;
      while(acc_i < this_nfactors){
        channel = acc_i % num_channel;
        dma_probe_state(probe, channel);
        if(probe > acc_i){
          h = this_factor_heights[f+acc_i];
          w = this_factor_widths[f+acc_i];
          //printf("probe: %d, acc_i: %d, dma_i: %d\n ", probe, acc_i, dma_i);
          tiled_matmul_small(h, h, w,
               (elem_t*) data_sp, (elem_t*) data_sp, NULL, (elem_t*) workspace,
               max_factor_height, max_factor_height, max_factor_height, max_factor_height,
               //1, 1, 1,
               //ceil_divide_int(h, DIM), ceil_divide_int(h, DIM), ceil_divide_int(w, DIM),
               //0, 1,
               1, 1,
               true, false, //false, false,
               0, acc_i == 0);

          workspace += max_factor_height * h;
          data_sp += max_factor_height * w;
           
          acc_i++;
        }
        else
            break;
      }

  }
  bool configured2 = false;
//rr_fence(dma_cfgid);
  for(int i = acc_i; i < this_nfactors; ) {
      channel = i % num_channel;
      int probe = 0;
      dma_probe_state(probe, channel);
      if(probe <= acc_i) continue;
      int h = this_factor_heights[f+i];
      int w = this_factor_widths[f+i];
#if ReRoCC == 1
      rr_set_opc(XCUSTOM_ACC, i % 2 == 0 ? acc_cfgid1 : acc_cfgid2);
#endif
      tiled_matmul_small(h, h, w,
            (elem_t*) data_sp, (elem_t*) data_sp, NULL, (elem_t*) workspace,
            max_factor_height, max_factor_height, max_factor_height, max_factor_height,
            1, 1,
            true, false, 
            0, i == 0 || !configured2);

      if(i % 2 == 1) configured2 = true;

      workspace += max_factor_height * h;
      data_sp += max_factor_height * w;
      i++;
  }

  workspace = (float*) base_addr;
#if ReRoCC == 1
  rr_fence(acc_cfgid1);
  rr_fence(acc_cfgid2);
  rr_fence(dma_cfgid);
  rr_set_opc(XCUSTOM_ACC, acc_cfgid1);
#endif
  rr_set_opc(XCUSTOM_ACC, add_cfgid);
  mid1 = read_cycles();

  //expected_cycles = 0;
  for(int i = f; i < f+this_nfactors; i++){
      //sparse_matrix_add3_2(workspace, h, h, ridx,
      //                     H_data, H_h, H_h, H_ridx,
      //                     1, H_lookup);
      float* A_col = workspace;
      int h = this_factor_heights[i];
      //printf("h: %d, A: 0x%08lx, B: 0x%08lx\n", h, A_this_blk[i], B_this_blk[i]);
      packed_dense_block_add(workspace, H_data,
              h, H_h, width_this_blk[i],
              max_factor_height, H_h,
              A_this_blk[i], B_this_blk[i],
              num_this_blk[i], i == f);
      /*
      for(int J = 0; J < num_this_blk[i]; J++){
          float* B_col = H_data + B_this_blk[i][J] * H_h;
          for(int I = J; I < num_this_blk[i]; I++){
              //printf("factor: %d, I: %d, J: %d, row: %d, col: %d\n", i, I, J, width_this_blk[i][I], width_this_blk[i][J]);
              //expected_cycles += width_this_blk[i][I] * ceil_divide_int(width_this_blk[i][J], DIM) * 4;
              float* A = A_col + A_this_blk[i][I];
              float* B = B_col + B_this_blk[i][I];
              dense_block_add(A, B, width_this_blk[i][I], width_this_blk[i][J], h, H_h, 1, 1);
          }
          A_col += width_this_blk[i][J] * h;
      }
      */
      workspace += max_factor_height * h;
  }
#if ReRoCC == 1
#if MATADD == 1
  rr_fence(add_cfgid);
#else
  rr_fence(acc_cfgid1);
#endif
#endif
  mid2 = read_cycles();

  workspace = (float*) base_addr;
  int H_square = (H_h - 1) * H_h;
  for(int i = f; i < f+this_nfactors; i++){
      int num_block = num_this_blk[i];
      int h = this_factor_heights[i];
      float* A_col = workspace + h - 1;
      float* B_col = H_data + H_h - 1;
      for(int J = 0; J < num_block; J++){
          float* B = B_col + B_this_blk[i][J] * H_h;
          
          tiled_unpacked_matadd(width_this_blk[i][J], 1, max_factor_height, H_h, H_h, 
                 1, 1, 1,
                 A_col, B, B,
                 false, J == 0 && i == f);
          
          //dense_block_add(A_col, B, 1, width_this_blk[i][J],
          //        h, H_h, 1, 1);
          A_col += max_factor_height * width_this_blk[i][J];
      }
      float* B = B_col + H_square; //(H_h - 1) * H_h;
      *B = *B + *A_col;
      workspace += max_factor_height * h;
  }
#if ReRoCC == 1
#if MATADD == 1
  rr_fence(add_cfgid);
#else
  rr_fence(acc_cfgid1);
#endif
#endif

  end = read_cycles();
  AtA_cycles = end - start;
  //printf("expected block add cycle: %llu\n", expected_cycles);
#if PRINT_CYCLES == 1
  printf("AtA cycles: %llu (prefetch+matmul: %llu, matadd: %llu, last row: %llu) \n", AtA_cycles, mid1 - start, mid2 - mid1, end -  mid2);
#endif
  //printf("grouping: %llu, block add: %llu\n", mid2 - mid1, end - mid2);

}

void tile_AtA_supernode(int f, int this_nfactors, int M, int N,
        int max_factor_height, const int* this_factor_heights, const int* this_factor_widths, float** this_factor_data,
        int H_h, int H_w, int* H_ridx, float* H_data,
        float* workspace, float* data_start,
        int A_this_blk[N][M], int B_this_blk[N][M], int width_this_blk[N][M], int* num_this_blk,
        int dma_i, int num_channel, int acc_cfgid, int dma_cfgid, int add_cfgid){

  bool granted = false;
  int channel = 0;

  uint64_t start = 0, end = 0, mid1 = 0, mid2 = 0;
  uint64_t AtA_cycles = 0;
  uint64_t memcpy_cycles = 0, cholesky_cycles = 0, matadd_cycles = 0; 
  uint64_t expected_cycles = 0;
  start = read_cycles();
  for(int i = 0; i < num_channel; i++){
    granted = false;
    while(!granted)
      dma_set_state(granted, 0, i);
    dma_nord_dest_config(i, false, (elem_t*) data_start, max_factor_height * sizeof(elem_t));
  }
  float* data_sp = (float*) (data_start);
  int acc_i = 0;
  float* base_addr = workspace;
  uint64_t data_offset = 0;//base_addr + SPAD_TOTAL_BYTES/2;  
  while(dma_i < this_nfactors){ 
      granted = false;
      channel = dma_i % num_channel;
      int real_dma_i = dma_i + f;
      int h = this_factor_heights[real_dma_i];
      int w = this_factor_widths[real_dma_i];
      //int* ridx = factor_ridx[real_dma_i];
      float* data = this_factor_data[real_dma_i];
      //memcpy((elem_t*) data_offset, data, h * w * sizeof(float));
      dma_source_config(channel, granted, false, data, h * sizeof(elem_t));
      if(granted){
        dma_nord_memcpy_tile(channel, 0, data_offset, dma_i, w, h * sizeof(elem_t));
        //printf("dma_i: %d, channel: %d\n", dma_i, channel);
        dma_i ++;
        data_offset += max_factor_height * w * sizeof(elem_t);
      }
      
      int probe = 0;
      while(acc_i < this_nfactors){
        channel = acc_i % num_channel;
        dma_probe_state(probe, channel);
        if(probe > acc_i){
          h = this_factor_heights[f+acc_i];
          w = this_factor_widths[f+acc_i];
          //printf("probe: %d, acc_i: %d, dma_i: %d\n ", probe, acc_i, dma_i);
          tiled_matmul_small(h, h, w,
               (elem_t*) data_sp, (elem_t*) data_sp, NULL, (elem_t*) workspace,
               max_factor_height, max_factor_height, max_factor_height, max_factor_height,
               //1, 1, 1,
               //ceil_divide_int(h, DIM), ceil_divide_int(h, DIM), ceil_divide_int(w, DIM),
               //0, 1,
               1, 1,
               true, false, //false, false,
               0, acc_i == 0);

          workspace += max_factor_height * h;
          data_sp += max_factor_height * w;
           
          acc_i++;
        }
        else
            break;
      }

  }
//rr_fence(dma_cfgid);
  for(int i = acc_i; i < this_nfactors; ) {
      channel = i % num_channel;
      int probe = 0;
      dma_probe_state(probe, channel);
      if(probe <= acc_i) continue;
      int h = this_factor_heights[f+i];
      int w = this_factor_widths[f+i];

      tiled_matmul_small(h, h, w,
            (elem_t*) data_sp, (elem_t*) data_sp, NULL, (elem_t*) workspace,
            max_factor_height, max_factor_height, max_factor_height, max_factor_height,
            1, 1,
            true, false, 
            0, i == 0);
  
      workspace += max_factor_height * h;
      data_sp += max_factor_height * w;
      i++;
  }

  workspace = (float*) base_addr;
#if ReRoCC == 1
  rr_fence(acc_cfgid);
  rr_fence(dma_cfgid);
#endif
  mid1 = read_cycles();

  //expected_cycles = 0;
  for(int i = f; i < f+this_nfactors; i++){
      //sparse_matrix_add3_2(workspace, h, h, ridx,
      //                     H_data, H_h, H_h, H_ridx,
      //                     1, H_lookup);
      float* A_col = workspace;
      int h = this_factor_heights[i];
      //printf("h: %d, A: 0x%08lx, B: 0x%08lx\n", h, A_this_blk[i], B_this_blk[i]);
      packed_dense_block_add(workspace, H_data,
              h, H_h, width_this_blk[i],
              max_factor_height, H_h,
              A_this_blk[i], B_this_blk[i],
              num_this_blk[i], i == f);
      /*
      for(int J = 0; J < num_this_blk[i]; J++){
          float* B_col = H_data + B_this_blk[i][J] * H_h;
          for(int I = J; I < num_this_blk[i]; I++){
              //printf("factor: %d, I: %d, J: %d, row: %d, col: %d\n", i, I, J, width_this_blk[i][I], width_this_blk[i][J]);
              //expected_cycles += width_this_blk[i][I] * ceil_divide_int(width_this_blk[i][J], DIM) * 4;
              float* A = A_col + A_this_blk[i][I];
              float* B = B_col + B_this_blk[i][I];
              dense_block_add(A, B, width_this_blk[i][I], width_this_blk[i][J], h, H_h, 1, 1);
          }
          A_col += width_this_blk[i][J] * h;
      }
      */
      workspace += max_factor_height * h;
  }
#if ReRoCC == 1
#if MATADD == 1
  rr_fence(add_cfgid);
#else
  rr_fence(acc_cfgid);
#endif
#endif
  mid2 = read_cycles();

  workspace = (float*) base_addr;
  int H_square = (H_h - 1) * H_h;
  for(int i = f; i < f+this_nfactors; i++){
      int num_block = num_this_blk[i];
      int h = this_factor_heights[i];
      float* A_col = workspace + h - 1;
      float* B_col = H_data + H_h - 1;
      for(int J = 0; J < num_block; J++){
          float* B = B_col + B_this_blk[i][J] * H_h;
          
          tiled_unpacked_matadd(width_this_blk[i][J], 1, max_factor_height, H_h, H_h, 
                 1, 1, 1,
                 A_col, B, B,
                 false, J == 0 && i == f);
          
          //dense_block_add(A_col, B, 1, width_this_blk[i][J],
          //        h, H_h, 1, 1);
          A_col += max_factor_height * width_this_blk[i][J];
      }
      float* B = B_col + H_square; //(H_h - 1) * H_h;
      *B = *B + *A_col;
      workspace += max_factor_height * h;
  }
#if ReRoCC == 1
#if MATADD == 1
  rr_fence(add_cfgid);
#else
  rr_fence(acc_cfgid);
#endif
#endif

  end = read_cycles();
  AtA_cycles = end - start;
  //printf("expected block add cycle: %llu\n", expected_cycles);
#if PRINT_CYCLES == 1
  printf("AtA cycles: %llu (prefetch+matmul: %llu, matadd: %llu, last row: %llu) \n", AtA_cycles, mid1 - start, mid2 - mid1, end -  mid2);
#endif
  //printf("grouping: %llu, block add: %llu\n", mid2 - mid1, end - mid2);

}

void AtA_update(int M, int N, int M_h, int M_w, int max_nfactor_per_node, int factor_max_height, int factor_max_width, float* M_data, float* M_workspace_data, float* AtA_prefetch_workspace, float* AtA_workspace,  int* cur_node_factor_height, int* cur_node_factor_width, int** cur_node_factor_ridx, float** cur_node_factor_data, float** cur_node_new_factor_data, int cur_node_num_update_factors, int A_blk[M][N], int B_blk[M][N], int width_blk[M][N], int* num_blk, int num_channel, int acc_cfgid, int add_cfgid, int dma_cfgid){
      // Restore C = LC + LBLB^T
      // Restore [A; B] = [LA; LB] * LA^T
      int supernode_size = M_h * M_w;
      int M_subdiag_h = M_h - M_w;
      float* LA_data = M_data;
      float* LB_data = M_data + M_w;
      float* A_data = M_workspace_data;
      float* C_data = M_workspace_data + supernode_size + M_w;

      bool granted = false;

      uint64_t start = read_cycles();
      for(int i = 0; i < num_channel; i++){
          granted = false;
          while (!granted)
              dma_set_state(granted, 0, i);
          dma_nord_dest_config(i, false, AtA_prefetch_workspace, factor_max_height * sizeof(float));
      }
      int data_offset = 0;
      for(int i = 0; i < cur_node_num_update_factors; i++){
          granted = false;
          float* data = cur_node_factor_data[i];
          int h = cur_node_factor_height[i];
          int w = cur_node_factor_width[i];
          int channel = i % num_channel;
          while(!granted)
            dma_source_config(channel, granted, false, data, h * sizeof(float));
          dma_nord_memcpy_tile(channel, 0, data_offset, i, w, h * sizeof(float));
          data_offset += factor_max_height * w * sizeof(float);
      }

      if(M_subdiag_h > 0) {
          // Restore C as LC + LB LB^T
          /*
          matmul2(M_subdiag_h, M_subdiag_h, M_w, 
                  LB_data, LB_data, C_data, C_data,
                  1, 1, 1, 
                  true, false);
                  */
          
          tiled_matmul_auto(M_subdiag_h, M_subdiag_h, M_w, 
                  LB_data, LB_data, C_data, C_data,
                  M_h, M_h, M_h, M_h,
                  1, 1, 1,
                  0, 1, 0, false,
                  true, false,
                  false, false,
                  0, WS);
                  
      }

      float* new_AtA_prefetch_workspace = (float*) AtA_prefetch_workspace + max_nfactor_per_node * factor_max_height * factor_max_width;
      for(int i = 0; i < num_channel; i++){
          granted = false;
          while (!granted)
              //dma_set_state(granted, 0, i);
            dma_dest_config(i, granted, false, new_AtA_prefetch_workspace, factor_max_height * sizeof(float));
      }
      data_offset = 0;
      for(int i = 0; i < cur_node_num_update_factors; i++){
          granted = false;
          int h = cur_node_factor_height[i];
          int w = cur_node_factor_width[i];
          float* new_data = cur_node_new_factor_data[i];
          int channel = i % num_channel;
          granted = false;
          while(!granted)
            dma_source_config(channel, granted, false, new_data, h * sizeof(float));
          dma_nord_memcpy_tile(channel, 0, data_offset, i, w, h * sizeof(float));
          data_offset += factor_max_height * w * sizeof(float);
      }


      // Restore [A; B] as [LA; LB] * LA^T
      /*
      matmul2(M_w, M_h, M_w,
              LA_data, LA_data, A_data, A_data,
              M_h, M_h, M_h, M_h,
              1, 1, 1,
              true, false);
              */
      // TODO: skip configuring config
      tiled_matmul_auto(M_w, M_h, M_w, 
              LA_data, LA_data, A_data, A_data,
              M_h, M_h, M_h, M_h,
              1, 1, 1,
              0, 1, 0, false,
              true, false,
              false, false,
              0, WS);
#if ReRoCC == 1
      rr_fence(dma_cfgid);
      rr_fence(acc_cfgid);
#endif
      //printf("start prefetching\n") 

      uint64_t mid1 = read_cycles();
      //printf("start AtA uipdate\n");
      float* data_sp = AtA_prefetch_workspace;
      float* AtA_temp = AtA_workspace;
      for(int i = 0; i < cur_node_num_update_factors; i++) {
        int h = cur_node_factor_height[i];
        int w = cur_node_factor_width[i];
        //int* ridx = cur_node_factor_ridx[i];
        float* data = cur_node_factor_data[i];
        //float* new_data = cur_node_new_factor_data[i];
        // TODO: define workspace once above

        //my_memset(workspace, 0, h * h * sizeof(float));

        // TODO: separate these two matmul
        // avoid reconfiguring config
        tiled_matmul_small(h, h, w, 
               //data, data,
               data_sp, data_sp, 
               NULL, AtA_temp,
               //h, h, h, h,
               factor_max_height, factor_max_height, factor_max_height, factor_max_height,
               -1, 1, //0,
               //0, 1, 0, false,
               true, false,
               //false, false, 
               0, i == 0);
        data_sp += factor_max_height * w;
        AtA_temp += factor_max_height * h;
      }
      AtA_temp = AtA_workspace;
#if ReRoCC == 1
      rr_fence(acc_cfgid);
#endif
      
      data_sp = new_AtA_prefetch_workspace;//(float*) AtA_prefetch_workspace + MAX_NFACTOR_PER_NODE * factor_max_height * factor_max_width;
      for(int i = 0; i < cur_node_num_update_factors; i++) {
        int h = cur_node_factor_height[i];
        int w = cur_node_factor_width[i];
        int* ridx = cur_node_factor_ridx[i];
        //float* data = cur_node_factor_data[i];
        float* new_data = cur_node_new_factor_data[i];
        // TODO: only reconfigure 1, separate out
        tiled_matmul_small(h, h, w, 
               data_sp, data_sp,
               //new_data, new_data,
               AtA_temp, AtA_temp,
               //h, h, h, h,
               factor_max_height, factor_max_height, factor_max_height, factor_max_height,
               1, 1, //1,
               //0, 1, 0, false,
               true, false,
               //false, false, 
               0, i == 0);

        // TODO: redo
        /*
        cpu_sparse_matrix_add3_2(AtA_temp, h, factor_max_height, ridx,
                             M_workspace_data, M_h, factor_max_height, M_ridx,
                             1, M_lookup);
       */
        /*
        cpu_sparse_matrix_add3_2(AtA_temp, h, h, ridx,
                             M_workspace_data, M_h, M_h, M_ridx,
                             1, M_lookup);
        */
        // TODO: pull out
        data_sp += factor_max_height * w;
        AtA_temp += factor_max_height * h;
      }
#if ReRoCC == 1
      rr_fence(acc_cfgid);
#endif
     
      AtA_temp = AtA_workspace;
      uint64_t mid2 = read_cycles();

      for(int i = 0; i < cur_node_num_update_factors; i++){
          //sparse_matrix_add3_2(workspace, h, h, ridx,
          //                     H_data, H_h, H_h, H_ridx,
          //                     1, H_lookup);
         // float* A_col = workspace;
          int h = cur_node_factor_height[i];
          //printf("h: %d, A: 0x%08lx, B: 0x%08lx\n", h, A_blk[i], B_blk[i]);
          packed_dense_block_add(AtA_temp, M_workspace_data,
                  h, M_h, width_blk[i],
                  factor_max_height, M_h,
                  A_blk[i], B_blk[i],
                  num_blk[i], i == 0);
          AtA_temp += factor_max_height * h;
      }
      
#if ReRoCC == 1
      rr_fence(add_cfgid);
#endif
      uint64_t end = read_cycles();
#if PRINT_CYCLES == 1
  printf("prefetch+recon: %llu, matmul: %llu, matadd: %llu \n", mid1 - start, mid2 - mid1, end -  mid2);
#endif
 
}

// Solve L.T x = B in place, overwriting B with the answer
// L is size w x w column major, B is size w x h column major
// h is typically 1 in our use case
void cpu_dense_block_triangle_solve_transpose_vector(float* L, float* B, 
                                                int w, /*int h = 1,*/
                                                int strideL/*, int strideB*/) {
    L = L + (w - 1) * (strideL + 1);
    for(int j = w - 1; j >= 0; j--) {
	if(L[0] <= 0) L[0] = 1;
        B[j] = B[j] / L[0];

        float* Li = L - strideL;
        for(int i = j - 1; i >= 0; i--) {
            B[i] -= *Li * B[j];
            Li -= strideL;
        }

        L -= (strideL + 1);
    }
}
void dense_block_triangle_solve_transpose_vector(float* L, float* B, 
                                                int w, /*int h = 1,*/
                                                int strideL/*, int strideB*/, int acc_cfgid) {
    int block_size = 4;
    float* Lb = L + (w-1)*(strideL+1);
    for(int jj = w - 1; jj >= 0; jj-=block_size){
        int ww = jj < block_size ? jj+1 : block_size;
        int rows = jj - ww + 1;
        for(int j = 0; j < ww; j ++){
            int row = jj - j;
	    if(Lb[0] <= 0) Lb[0] = 1;
            B[row] = B[row] / Lb[0];
            //printf("jj: %d, j:%d, jj-j: %d\n", jj, j, row);

            float* Li = Lb - strideL;
            for(int i = row - 1; i >= rows; i--) {
                //printf("i: %d\n", i);
                B[i] -= *Li * B[row];
                Li -= strideL;
            }
            Lb -= (strideL + 1);
        }
        float* L2 = L + rows;
        float* B2 = B + rows;
        //printf("mult: %d\n", jj-ww+1);
        // TODO: x^TL
        if (rows >= 1)
           tiled_matmul_small(1, rows, ww,//rows, 1, ww,
                B2, L2, B, B,
                1, strideL, 1, 1,
                -1, 1,
                false, true, 
                0, jj == w - 1);
#if ReRoCC == 1
        rr_fence(acc_cfgid);
#endif
    }


}
// L is a factorized supernode of height x width
// x is a dense vector
// Compute the part of x corresponding to the columns of the supernode
void partial_backsolve(float* L, int w, int h, int stride, int* ridx,
                       float* x, int channel, int dma_cfgid, int acc_cfgid) {
    int subdiag_h = h - w - 1;  // Don't count last row
    bool granted = false;
    // Copy last row to x
    float* L_last_row = L + h - 1;
    float* x1 = x + ridx[0];
    uint64_t start = read_cycles();
#if SPICA == 1
    while(!granted)
      dma_source_config(channel, granted, false, (float*) L_last_row, stride * sizeof(float));
    dma_nord_dest_config(channel, false, (float*) x1, sizeof(float));
    dma_memcpy_tile(channel, granted, 0, 0, 0, w, sizeof(float));
#else
    for(int i = 0; i < w; i++) {
        x1[i] = *L_last_row;
        L_last_row += stride;
    }
#endif
    if(subdiag_h > 0) {

        // Gather relevant x
        float* x2 = (float*) my_malloc(subdiag_h * sizeof(float));

        for(int i = 0; i < subdiag_h; i++) {
            x2[i] = x[ridx[i + w]];
        }

        float* L2 = L + w;

        // Compute y1 -= L2.T x2
        /*
        gemv2(w, subdiag_h,
              L2, x2,
              x1, x1,
              stride,
              -1, 1, 1,
              false, false);
  */      
        tiled_matmul_auto(1, w, subdiag_h, 
                 x2, L2, x1, x1,
                 1, stride, 1, 1,
                 -1, 1, 1,
                 0, 1, 0, false,
                 false, false,
                 false, true,
                 0, WS); 
/*
        tiled_matmul_small(1, w, subdiag_h,//w, 1, subdiag_h, 
                x2, L2, x1, x1,
                1, stride, 1, 1,
                -1, 1,
                //0, 1, 0, false,
                //false, false,
                false, true,
                0, true);
*/
        my_free_after(x2);
    }
#if ReRoCC == 1
    rr_fence(acc_cfgid);
#if SPICA == 1
    rr_fence(dma_cfgid);
#endif
#endif
    uint64_t mid = read_cycles();
    // Solve L1^T x1 = y1 in place
    dense_block_triangle_solve_transpose_vector(L, x1, w, stride, acc_cfgid);
    uint64_t end = read_cycles();

#if PRINT_CYCLES == 1
    printf("last row move + gemv: %llu, transpose triangle solve: %llu\n", mid - start, end - mid);
#endif
}


// CPU code
void cpu_blocked_syrk(int dim_I, int dim_K,
                  float* B, float* C,
                  int stride_B, int stride_C,
                  float scale_factor_B) {

  float* B_0K = B;
  for(int K = 0; K < dim_K; K += GEMM_BLOCK_SIZE) {
    int ww = min(dim_K - K, GEMM_BLOCK_SIZE); // ww is the actual panel width
    float* B_JK = B_0K;
    float* C_0J = C;
    for(int J = 0; J < dim_I; J += GEMM_BLOCK_SIZE) {
      int hhJ = min(dim_I - J, GEMM_BLOCK_SIZE);
      float* B_IK = B_JK;
      float* C_IJ = C_0J + J;
      for(int I = J; I < dim_I; I += GEMM_BLOCK_SIZE) {
        int hhI = min(dim_I - I, GEMM_BLOCK_SIZE); 
/*
        matmul(hhJ, hhI, ww,
               B_JK, B_IK, C_IJ,
               stride_B, stride_B, stride_C,
               scale_factor_B, 1,
               true, false);
*/
        tiled_matmul_auto(hhJ, hhI, ww,
               (elem_t*) B_JK, (elem_t*) B_IK, (elem_t*) C_IJ, (elem_t*) C_IJ,
               stride_B, stride_B, stride_C, stride_C,
               scale_factor_B, 1, MVIN_SCALE_IDENTITY,
               NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
               true, false,
               false, false,
               0, CPU);

        B_IK += GEMM_BLOCK_SIZE;
        C_IJ += GEMM_BLOCK_SIZE;
      }
      B_JK += GEMM_BLOCK_SIZE;
      C_0J += GEMM_BLOCK_SIZE * stride_C;
    }
    B_0K += GEMM_BLOCK_SIZE * stride_B;
  }
}
// Do partial cholesky factorization by first doing as dense cholesky on the diagonal block
// Then doing triangle solve
void cpu_partial_factorization(float* AB, int w, int h) {

  int hh = h;   // hh is the height of the current block column

  float* AB_JJ = AB;
  // J is the row/col index of the diagonal block
  // I is the row index of the subdiagonal block
  int J;
  int I;
  for(J = 0; J < w; J += CHOL_BLOCK_SIZE) {
    // TODO: Make ww fixed and use cleanup iterations
    int ww = min(w - J, CHOL_BLOCK_SIZE); // ww is the panel width.
    cpu_dense_block_cholesky(AB_JJ, ww, h); // CPU implementation
    float* AB_IJ = AB_JJ + ww;
    for(I = J + ww; I < h; I += TRSM_BLOCK_SIZE) {
      // TODO: Make hh fixed and use cleanup iterations
      int hh = min(h - I, TRSM_BLOCK_SIZE); // hh is the block height
      cpu_dense_block_triangle_solve(AB_JJ, AB_IJ, 
                                 ww, 
                                 hh, 
                                 h, h);
      AB_IJ += TRSM_BLOCK_SIZE;
    }

    int dim_I = h - J - ww, dim_J = dim_I, dim_K = ww;
    float* B = AB_JJ + ww;
    float* C = AB_JJ + ww * (h + 1);
    int stride_B = h, stride_C = h;
    float scale_factor_A = -1, scale_factor_B = 1;
    bool transpose_A = true, transpose_B = false;

    cpu_blocked_syrk(dim_I, dim_K,
                 B, C,
                 stride_B, stride_C,
                 scale_factor_A);

    // matmul(dim_I, dim_J, dim_K,
    //      B, B, C, 
    //      stride_B, stride_B, stride_C,
    //      scale_factor_A, scale_factor_B,
    //      transpose_A, transpose_B);

    AB_JJ += CHOL_BLOCK_SIZE * (h + 1);
    hh -= CHOL_BLOCK_SIZE;
  }
}
void cpu_dense_block_add(float* Ablk, float* Bblk, 
                     int height, int width,
                     int Astride, int Bstride,
                     float Ascale, float Bscale) {

  //printf("width: %d, height: %d A stride: %d, B stride: %d, A: 0x%08lx, B: 0x%08lx\n", width, height, Astride, Bstride, Ablk, Bblk);  
  
  float* Ablk_0j = Ablk;                             
  float* Bblk_0j = Bblk;
  for(int j = 0; j < width; j++) {
    float* Ablk_ij = Ablk_0j;
    float* Bblk_ij = Bblk_0j;
    for(int i = 0; i < height; i++) {
      *Bblk_ij = Ascale * *Ablk_ij + Bscale * *Bblk_ij;
      Ablk_ij++;
      Bblk_ij++;
    }
    Ablk_0j += Astride;
    Bblk_0j += Bstride;
  }
 }
void cpu_sparse_matrix_add3_2(float* A, int Adim, int Astride, int* Aidx,
                          float* B, int Bdim, int Bstride, int* Bidx,
                          float Ascale, 
                          int* B_lookup) {
  int* A_blk_start = (int*) my_malloc(Adim * sizeof(int));
  int* B_blk_start = (int*) my_malloc(Adim * sizeof(int));
  int* blk_width = (int*) my_malloc(Adim * sizeof(int));
  int num_blks;

  group_block_indices(Aidx, Adim - 1, A_blk_start, B_blk_start, blk_width, &num_blks, B_lookup);
  
  for(int J = 0; J < num_blks; J++) {
    float* A_col = A + A_blk_start[J] * Astride;
    float* B_col = B + B_blk_start[J] * Bstride;
    for(int I = J; I < num_blks; I++) {
      float* A_blk = A_col + A_blk_start[I];
      float* B_blk = B_col + B_blk_start[I];
      cpu_dense_block_add(A_blk, B_blk, blk_width[I], blk_width[J], Astride, Bstride, 1, 1);
    }
  }

  // Manually add last row
  A_blk_start[num_blks] = Adim - 1;
  B_blk_start[num_blks] = Bdim - 1;
  blk_width[num_blks] = 1;
  num_blks++;

  float* A_col = A + Adim - 1;
  for(int J = 0; J < num_blks; J++) {
    float* B_col = B + B_blk_start[J] * Bstride + Bdim - 1;
    for(int j = 0; j < blk_width[J]; j++) {
      *B_col += *A_col;
      A_col += Astride;
      B_col += Bstride;
    }
  }

}

