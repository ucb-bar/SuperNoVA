#ifndef AURORA_GEMMINI_H
#define AURORA_GEMMINI_H

#ifndef DNN_PROFILE
#define DNN_PROFILE 0
#endif

#if DNN_PROFILE == 1
int layer_pointer = 0;
int mt_layer_pointer[2] = {0};
int layer_cycles[4][130] = {0};
uint64_t mt_layer_cycles[2][2][130] = {0};
#endif

#define BANK_LEN (DIM*MAX_BLOCK_LEN)
#ifndef PRINT_TILE
#define PRINT_TILE 0
#endif
size_t* tiling_factor_matmul_calculate_auto(size_t dim_I_in, size_t dim_J_in, size_t dim_K_in,
  size_t orow_divide, size_t och_divide, size_t num_array, size_t cid, size_t args[]){

  bool fc_layer = (dim_I_in <= DIM) || (dim_J_in <= DIM);

  bool row_divisible = (orow_divide > 1) && dim_I_in >= num_array*DIM;
  size_t orow_offset_floor = 0;
  size_t dim_I = dim_I_in;
  size_t dim_J = dim_J_in;
  size_t dim_K = dim_K_in;
  if(row_divisible){
    dim_I = dim_I_in / orow_divide;
  }
  else
    dim_J = dim_J_in / och_divide;

 
#define partition_rows (BANK_NUM * BANK_ROWS / 2)
#define mats_in_partition (partition_rows / DIM)
#define mats_in_acc (ACC_ROWS / DIM)
#define max_tile_i_j ((size_t)sqrt(mats_in_acc))
#define max_tile_k (mats_in_partition / max_tile_i_j)

    // "db_" means "double-buffered"
#define db_partition_rows ((BANK_NUM * BANK_ROWS / 2) / 2)
#define db_mats_in_partition (db_partition_rows / DIM)
#define db_mats_in_acc ((ACC_ROWS / 2) / DIM)
#define db_max_tile_i_j ((size_t)sqrt(db_mats_in_acc))
#define db_max_tile_k (db_mats_in_partition / db_max_tile_i_j)

  const size_t dim_I_padded = (dim_I / DIM + (dim_I % DIM != 0)) * DIM;
  const size_t dim_J_padded = (dim_J / DIM + (dim_J % DIM != 0)) * DIM;
  const size_t dim_K_padded = (dim_K / DIM + (dim_K % DIM != 0)) * DIM;

  const bool double_buffered = true;//tiled_matmul_type == WS;
  const size_t max_spad_rows = double_buffered ? BANK_NUM * BANK_ROWS / 2 :
      BANK_NUM * BANK_ROWS;
  const size_t max_acc_rows = double_buffered ? ACC_ROWS / 2 : ACC_ROWS;

  size_t tile_I, tile_J, tile_K;

  if (double_buffered) {
    tile_I = dim_I_padded/DIM < db_max_tile_i_j ? dim_I_padded/DIM : db_max_tile_i_j;
    tile_J = dim_J_padded/DIM < db_max_tile_i_j ? dim_J_padded/DIM : db_max_tile_i_j;
    tile_K = dim_K_padded/DIM < db_max_tile_k ? dim_K_padded/DIM : db_max_tile_k;
  } else {
    tile_I = dim_I_padded/DIM < max_tile_i_j ? dim_I_padded/DIM : max_tile_i_j;
    tile_J = dim_J_padded/DIM < max_tile_i_j ? dim_J_padded/DIM : max_tile_i_j;
    tile_K = dim_K_padded/DIM < max_tile_k ? dim_K_padded/DIM : max_tile_k;
  }

  const size_t dim_I_in_padded = (dim_I_in / DIM + (dim_I_in % DIM != 0)) * DIM;
  const size_t dim_J_in_padded = (dim_J_in / DIM + (dim_J_in % DIM != 0)) * DIM;
  const size_t dim_K_in_padded = (dim_K_in / DIM + (dim_K_in % DIM != 0)) * DIM;

  
  // Fill scratchpad as much as possible
  while (true) {
    bool increased = false;

    if (tiled_matmul_total_spad_rows(tile_I, tile_J+1, tile_K) <= max_spad_rows &&
        tiled_matmul_total_acc_rows(tile_I, tile_J+1) <= max_acc_rows &&
        (tile_J+1) * DIM <= dim_J_padded) {
      tile_J++;
      increased = true;
    }

    if (tiled_matmul_total_spad_rows(tile_I+1, tile_J, tile_K) <= max_spad_rows &&
        tiled_matmul_total_acc_rows(tile_I+1, tile_J) <= max_acc_rows &&
        (tile_I+1) * DIM <= dim_I_padded) {
      tile_I++;
      increased = true;
    }

    if (tiled_matmul_total_spad_rows(tile_I, tile_J, tile_K+1) <= max_spad_rows &&
        (tile_K+1) * DIM <= dim_K_padded) {
      tile_K++;
      increased = true;
    }
  
    if (!increased)
      break;
  }
  args[0] = tile_I; args[1] = tile_J; args[2] = tile_K;
  args[3] = dim_I; args[4] = dim_J; args[5] = dim_K;
  const int spad_rows = tiled_matmul_total_spad_rows(tile_I, tile_J, tile_K);
  const int acc_rows = tiled_matmul_total_acc_rows(tile_I, tile_J);
  const int spad_util = (spad_rows * 100) / max_spad_rows;
  const int acc_util = (acc_rows * 100) / max_acc_rows;
#if PRINT_TILE == 1
  printf("tile_I: %d\n", tile_I);
  printf("tile_J: %d\n", tile_J);
  printf("tile_K: %d\n", tile_K);
#endif
  return args;
}


int* tiled_resadd_bubble_calculate(
    int out_args[], // window, bubble, ideal cycles, tiling factors
    size_t I, size_t J,
    size_t num_array, size_t cid){//, bool A_cached, 
    //int real_cycle, float alpha){

  int orow_divide = num_array;
  //bool row_divisible = orow_divide > 1 && (I % orow_divide == 0);
  //I = (row_divisible) ? I / orow_divide : I;
  //size_t och_divide = (row_divisible) ? 1 : orow_divide; // if row is divisible, no need to divide channel
  I = ceil_divide_int(I, orow_divide);
  //if (!row_divisible) orow_divide = 1;

  size_t tile_I = I;
  //J = J / och_divide;
  size_t tile_J = J;

  if(J < MAX_BLOCK_LEN * DIM){
    tile_J = J;
  }
  else{
    tile_J = MAX_BLOCK_LEN * DIM;
  }

	 
	size_t total_acc_rows = (tile_I / DIM + (tile_I % DIM != 0))*DIM * (tile_J / DIM + (tile_J % DIM != 0));

  // TODO this is a very inefficient way of doing this...
  while (total_acc_rows > ACC_ROWS/2) {
       if (tile_I >= tile_J)
           tile_I--;
       else
           tile_J -= DIM;

    total_acc_rows = (tile_I / DIM + (tile_I % DIM != 0))*DIM * (tile_J / DIM + (tile_J % DIM != 0));
  }
  
  out_args[0] = tile_I;
  out_args[1] = tile_J;

#if PRINT_TILE == 1
  printf("tile_I: %d, tile_J: %d\n", tile_I, tile_J);
#endif
  return out_args;
}

int* tiling_factor_calculate(int args[], int stride, int pool_size, int pool_stride, int kernel_dilation, int padding){
  int batch_size = args[0];
  int pool_out_row = args[1];
  int pool_out_dim = args[2];
  int out_channels = args[3];
  int kernel_dim = args[4];
  int in_channels = args[6];
  const int max_args[] = {batch_size, pool_out_row, pool_out_dim, out_channels, kernel_dim, kernel_dim, in_channels};
/*
    printf("batches = %d\n", args[0]);
    printf("orows   = %d\n", args[1]);
    printf("ocols   = %d\n", args[2]);
    printf("ochs    = %d\n", args[3]);
    printf("krows   = %d\n", args[4]);
    printf("kcols   = %d\n", args[5]);
    printf("kchs    = %d\n\n", args[6]);
*/
  const int orows_idx = 1;
  const int ocols_idx = 2;
  const int out_channels_idx = 3;
  const int in_channels_idx = 6;
 
  const int input_dilation = 1;
  const bool downsample = false;
  // We divide by 2 for the sake of double-buffering
  const int max_spad_rows = (BANK_NUM*BANK_ROWS / 2);
  const int max_acc_rows = (ACC_ROWS / 2);
  int spad_rows = tiled_conv_total_spad_rows(false,
    stride, input_dilation, kernel_dilation, downsample, false, false, args[0], args[1], args[2], args[3], args[4], args[5], args[6], pool_size, pool_stride);
  int acc_rows = tiled_conv_total_spad_rows(true,
    stride, input_dilation, kernel_dilation, downsample, false, false, args[0], args[1], args[2], args[3], args[4], args[5], args[6], pool_size, pool_stride);

  while (spad_rows > max_spad_rows || acc_rows > max_acc_rows) {
    int max_val = -1;
    int max_idx = -1;

    for (size_t j = 0; j < 7; j++) {
      // We avoid reducing ocols when possible to keep the spatial array fully utilized
      size_t i = 0;
      if(j == 0) i = 0;
      else if (j == 4) i = orows_idx;
      else if(j == 1) i = ocols_idx;
      else if (j == 5) i = 4;
      else if(j == 6) i = 5;
      else if(j == 2) i = out_channels_idx;
      else if(j == 3) i = in_channels_idx;

      if(i == 0 && args[0] > 1){ // batch first
        max_val = args[0];
        max_idx = 0;
        break;
      } else if(((pool_stride > 1 && args[in_channels_idx] >= DIM) || args[in_channels_idx] == MAX_BLOCK_LEN * DIM) && args[out_channels_idx] <= MAX_BLOCK_LEN * DIM){
        if(i == orows_idx && args[orows_idx] > 1 && (args[ocols_idx] <= DIM || (args[in_channels_idx] <= DIM * MAX_BLOCK_LEN && args[out_channels_idx] == MAX_BLOCK_LEN*DIM))){// && (args[orows_idx] >= args[ocols_idx] || args[ocols_idx] <= DIM)){ //decrease orows as much as possible 
          max_val = args[orows_idx];
          max_idx = orows_idx;
          break;
        }else if(i == ocols_idx && (args[i]) > DIM){
          max_val = args[ocols_idx];
          max_idx = ocols_idx;
          break;
        }else if((i==4 || i == 5) && args[i] > 1){
          max_val = args[i];
          max_idx = i;
          break;
        }else if(args[i] > DIM && pool_stride > 1 && (i == in_channels_idx || i == out_channels_idx)){
          max_val = args[i];
          max_idx = i;
        }
      }else if (!(i == ocols_idx && args[i] <= DIM && args[orows_idx] > 1) && args[i] > max_val) { // and then move on to channels
        if(!((i==out_channels_idx || i==in_channels_idx) && args[i] <= DIM)){
            max_val = args[i];
            max_idx = i;
        }
      }
    }
    if (max_idx == out_channels_idx || max_idx == in_channels_idx) {
      if(max_val > MAX_BLOCK_LEN * DIM || pool_stride > 1){
         // For input and output channels, there's no point in subtracting by just one
        if (args[max_idx] > MAX_BLOCK_LEN*DIM && args[max_idx] % (MAX_BLOCK_LEN * DIM) != 0) {
          args[max_idx] = (args[max_idx] / (MAX_BLOCK_LEN * DIM)) * (MAX_BLOCK_LEN * DIM);
        } else {
          if(args[max_idx] % (2*DIM) == 0) args[max_idx] = args[max_idx] / 2;
          else args[max_idx] = ((args[max_idx]-1) / DIM) * DIM;
        }
        args[max_idx] = args[max_idx] == 0 ? 1 : args[max_idx];
      }
      else if (args[4] > 1 || args[5] > 1){
        if(args[4] > 1) args[4] = 1;//args[4]--;
        else if(args[5] > 1) args[5]--;
      }
      else if(args[in_channels_idx] < DIM){//for first layer
        args[max_idx] = args[max_idx] / 2;
      }
      else if (args[orows_idx] > (DIM/4)){
        args[orows_idx] = args[orows_idx] / 2;
      }
      else if(args[ocols_idx] > DIM){
        args[ocols_idx] = DIM;
      }
    } else {
      if(max_idx == ocols_idx){
        if(args[max_idx] % DIM != 0) args[max_idx] = (args[max_idx]/DIM)*DIM;
        else args[max_idx] -= (DIM/pool_stride);
      }else{
        if(max_idx == 4 || max_idx == 5) args[max_idx] = 1;
        else args[max_idx]--;
      }
    }
    
    if(in_channels == 3 && padding == 0 && kernel_dim == 3){
      int prop = ceil_divide_int(out_channels, args[3]);
      args[3] = out_channels;
      args[2] = args[2] / prop;
    }
    //printf("max_val: %d, max_idx: %d \n", max_val, max_idx);

    spad_rows = tiled_conv_total_spad_rows(false,
      stride, input_dilation, kernel_dilation, false, false, false, args[0], args[1], args[2], args[3], args[4], args[5], args[6], pool_size, pool_stride);
    acc_rows = tiled_conv_total_spad_rows(true,
      stride, input_dilation, kernel_dilation, false, false, false,  args[0], args[1], args[2], args[3], args[4], args[5], args[6], pool_size, pool_stride);
  }

/*
    printf("batches = %d\n", args[0]);
    printf("orows   = %d\n", args[1]);
    printf("ocols   = %d\n", args[2]);
    printf("ochs    = %d\n", args[3]);
    printf("krows   = %d\n", args[4]);
    printf("kcols   = %d\n", args[5]);
    printf("kchs    = %d\n\n", args[6]);
*/

  // Check if we can increase ocols
  bool not_increased = false;

  // Check if there are any parameters that we can currently still increase
  bool nothing_increased = false;
  bool kdim_increase = true;
  while (!nothing_increased) {
    nothing_increased = true;
    //kdim_increase = true;

    for (size_t j = 0; j < 7; j++) {
       //size_t i =j;//  down_sample ? j : 6-j;
      size_t i = j;
      if(j == 0) i = 5;//in_channels_idx;
      else if (j == 1) i = in_channels_idx;
      else if(j == 2) i = 4;//in_channels_idx;
      else if (j == 3) i = out_channels_idx;
      else if(j == 4) i = ocols_idx;
      else if(j == 5) i = orows_idx;
      else if(j == 6) i = 0; 
      int args_candidate[] = {args[0], args[1], args[2], args[3], args[4], args[5], args[6]};
      if(i == out_channels_idx || i == in_channels_idx) args_candidate[i] *= 2;//+= MAX_BLOCK_LEN * DIM;//!down_sample ? MAX_BLOCK_LEN * DIM : DIM;
      else if(i == ocols_idx && (args[i] % DIM == 0)) args_candidate[i] += DIM;
      else args_candidate[i]+= kdim_increase && (i == 4 || i == 5) ? 2 : 1;
      if (args_candidate[i] > max_args[i])
        continue;

      spad_rows = tiled_conv_total_spad_rows(false,
         stride, input_dilation, kernel_dilation, false, false, false,  args_candidate[0], args_candidate[1], args_candidate[2], args_candidate[3], args_candidate[4], args_candidate[5], args_candidate[6], pool_size, pool_stride);
      acc_rows = tiled_conv_total_spad_rows(true,
         stride, input_dilation, kernel_dilation, false, false, false,  args_candidate[0], args_candidate[1], args_candidate[2], args_candidate[3], args_candidate[4], args_candidate[5], args_candidate[6], pool_size, pool_stride);

      if (spad_rows <= max_spad_rows && acc_rows <= max_acc_rows) {
        args[i] = args_candidate[i];
        nothing_increased = false;
        kdim_increase = false;
      }
    }
  }

#if PRINT_TILE == 1
    printf("batches = %d\n", args[0]);
    printf("orows   = %d\n", args[1]);
    printf("ocols   = %d\n", args[2]);
    printf("ochs    = %d\n", args[3]);
    printf("krows   = %d\n", args[4]);
    printf("kcols   = %d\n", args[5]);
    printf("kchs    = %d\n\n", args[6]);
#endif

  return args;
  
}


static void tiled_opcode_conv(
        int batch_size, int in_dim, int in_channels,
        int out_channels, int out_dim,
        int stride, int input_dilation, int kernel_dilation, int padding, int kernel_dim,
        int in_stride, int weight_stride, int out_stride,
        bool wrot180, bool trans_output_1203, bool trans_input_3120,
        bool trans_weight_1203, bool trans_weight_0132,

        int batches,
        int porows, int pocols, int pochs,
        int krows, int kcols, int kchs,

        elem_t * input,
        elem_t * weights,
        acc_t * bias,
        elem_t * output,

        int act, acc_scale_t scale, 
        int pool_size, int pool_stride, int pool_padding, bool pool_ceil_dim,

        enum tiled_matmul_type_t tiled_conv_type,
        bool div_orow, bool div_och,
        int num_array) {//, int cid, 
        //int num_tile, int total_mem) {

#ifdef GEMMINI_ASSERTIONS
  if (trans_weight_1203 && trans_weight_0132) {
    printf("Only one weight transformation can be applied at a time\n");
    exit(1);
  }
#endif
  // TODO move everything below this into a tiled_conv_outer function to match the tiled_matmul function

    bool no_bias = false;
    if (bias == NULL) {
        bias = (acc_t*)1;
        no_bias = true;
    }

    bool no_pool = pool_stride == 0;
    if (no_pool) {
        pool_size = 1;
        pool_stride = 1;
        pool_padding = 0;
    }

    const bool downsample = false;//stride == 2 && kernel_dim == 1 && in_dim % 2 == 0
      //&& padding == 0 && no_pool && input_dilation == 1 && !trans_input_3120;

    const int input_dilated = input_dilation == 2;

#ifdef GEMMINI_ASSERTIONS
    {
        // const int orows = porows * pool_stride + pool_size - 1;
        // const int ocols = pocols * pool_stride + pool_size - 1;

        // Check that data will fit in scratchpad
        const int spad_rows = tiled_conv_total_spad_rows(false,
            stride, input_dilation, kernel_dilation, downsample, trans_weight_0132, trans_input_3120,
            batches, porows, pocols, pochs, krows, kcols, kchs, pool_size, pool_stride);
        const int acc_rows = tiled_conv_total_spad_rows(true,
            stride, input_dilation, kernel_dilation, downsample, trans_weight_0132, trans_input_3120,
            batches, porows, pocols, pochs, krows, kcols, kchs, pool_size, pool_stride);

        if (spad_rows > BANK_NUM * BANK_ROWS / 2) {
            printf("not enough scratchpad space to store inputs and weights, %d\n", spad_rows);
            exit(1);
        }
        if (acc_rows > ACC_ROWS / 2) {
            printf("not enough accumulator space to store outputs\n");
            exit(1);
        }
        if (kernel_dim <= padding) {
            printf("kernel_dim must be larger than padding\n");
            exit(1);
        }
        if (input_dilation > 2) {
            printf("input_dilation > 2 is only supported on CPU\n");
            exit(1);
        }
        if (input_dilation > 1 && stride > 1) {
            printf("input input_dilation is only supported when stride == 1\n");
            exit(1);
        }
        if (trans_output_1203 && !no_pool) {
            printf("Output can only be transposed when pooling is disabled\n");
            exit(1);
        }
        if (trans_input_3120 && trans_weight_0132) {
            printf("Cannot transpose innermost dimensions of both inputs and weights on WS.\n");
            exit(1);
        }
    }
#endif

    const size_t st_dram_stride = trans_output_1203 ?
        batch_size * out_channels * sizeof(elem_t) :
        out_stride * sizeof(elem_t);

    for(int i = 0; i < num_array; i++){
#if ReRoCC == 1
      rr_set_opc(XCUSTOM_ACC, i);
#endif
      gemmini_extended_config_st(st_dram_stride, act, scale);
      gemmini_extended3_config_ex(WEIGHT_STATIONARY, 0, 0, 0, input_dilation, stride >> downsample, trans_input_3120, trans_weight_0132, false);
    }
    const int pool_out_dim = (out_dim + 2*pool_padding - pool_size) / pool_stride + 1;
    const int dilated_in_dim = in_dim + (input_dilation-1)*(in_dim-1);

//    printf("batches: %d, porows: %d, pocols: %d, pochs: %d, krows: %d, kcols: %d, kchs: %d\n", batches, porows, pocols, pochs, krows, kcols, kchs);
    
    int orow_divide = div_orow ? num_array : 1;
    int pool_out_row = (pool_out_dim % orow_divide == 0) ? pool_out_dim / orow_divide : ((int)(pool_out_dim/orow_divide)) + 1;
    
    while(kchs < DIM && pocols >= (int)(pool_out_dim / 4) && porows < (int)(pool_out_row)){
       pocols = pocols / 2;
       porows = porows * 2;
    }
    
    int porows_outer = div_orow ? num_array * porows : porows;
    int pochs_outer = div_och ? num_array * pochs : pochs;
    //printf("div orow: %d, div och: %d, porows_outer: %d, pochs_outer: %d\n",div_orow, div_och, porows_outer, pochs_outer);
/*
    if(mode == 6){
       if(div_och || num_array == 1)
	   weight_direct_dram = true;
    }
    */
    size_t a_spad_id = 0;
    size_t b_spad_id = 0;

    bool a_reuse = false;
    bool b_reuse = false;
    size_t num_kch = ceil_divide_int(in_channels, kchs);
    size_t num_poch = ceil_divide_int(out_channels, pochs_outer);
    size_t num_b = ceil_divide_int(batch_size, batches);
    size_t num_porow = ceil_divide_int(pool_out_dim, porows_outer);
    size_t num_pocol = ceil_divide_int(pool_out_dim, pocols);
    size_t num_krow = ceil_divide_int(kernel_dim, krows);
    size_t num_kcol = ceil_divide_int(kernel_dim, kcols);


//    printf("num_kch: %d, num_poch: %d, num_b: %d, num_porow: %d, num_pocol: %d, num_krow: %d, num_kcol: %d\n", num_kch, num_poch, num_b, num_porow, num_pocol, num_krow, num_kcol);

    if(num_kch * num_poch * num_krow * num_kcol <= 2) 
      b_reuse = true;
    if(num_kch * num_krow * num_kcol * num_b * num_porow * num_pocol <= 2)
      a_reuse = true;


    for (int poch = 0; poch < out_channels; poch += pochs_outer) {     
      int pochs_outer_loop = (out_channels - poch >= pochs_outer) ? pochs_outer : out_channels - poch;
      for (int b = 0; b < batch_size; b += batches) {
        for (int porow = 0; porow < pool_out_dim; porow += porows_outer) {
          int porows_outer_loop = (pool_out_dim - porow >= porows_outer) ? porows_outer : pool_out_dim - porow;
          for (int pocol = 0; pocol < pool_out_dim; pocol += pocols) {
            const int ocol = pocol * pool_stride - pool_padding;
            for (int krow = 0; krow < kernel_dim; krow += krows) {
              for (int kcol = 0; kcol < kernel_dim; kcol += kcols) {
                const int ocol_floored = ocol < 0 ? 0 : ocol;
                const int icol = ocol_floored * stride + kcol*kernel_dilation - padding;
                for (int kch = 0; kch < in_channels; kch += kchs) {
                  if(a_reuse)
                    a_spad_id = (kch + krow + kcol + b + porow + pocol) == 0 ? 1 : 2;
                  if(b_reuse)
                    b_spad_id = (kch + poch + krow + kcol) == 0 ? 1 : 2;
                  const int batches_ = batch_size - b > batches ? batches : batch_size - b;
                  const int pocols_ = pool_out_dim - pocol > pocols ? pocols : pool_out_dim - pocol;
                  const int krows_ = kernel_dim - krow > krows ? krows : kernel_dim - krow;
                  const int kcols_ = kernel_dim - kcol > kcols ? kcols : kernel_dim - kcol;
                  const int kchs_ = in_channels - kch > kchs ? kchs : in_channels - kch;
                  const int ocols_ = pocols_ * pool_stride + pool_size - 1;
                  const int plpad = ocol < 0 ? -ocol : 0;
                  const int prpad = ocol + ocols_ > out_dim ? ocol + ocols_ - out_dim : 0;

                  const int dilated_krows_ = krows_ + (kernel_dilation - 1)*(krows_ - 1);
                  const int dilated_kcols_ = kcols_ + (kernel_dilation - 1)*(kcols_ - 1);

                  const int icols_ = (ocols_ - plpad - prpad) * stride + dilated_kcols_ - 1;
                  int lpad = icol < 0 ? -icol : 0;
                  int rpad = icol + icols_ > dilated_in_dim ? icol + icols_ - dilated_in_dim : 0;

                  int krow_ = krow;
                  int kcol_ = kcol;
                  if (wrot180) {
                    krow_ = kernel_dim - krow - krows_;
                    kcol_ = kernel_dim - kcol - kcols_;
                  }

                  elem_t * weights_slice = weights + (krow_*kernel_dim*in_channels + kcol_*in_channels + kch) * weight_stride + poch;
                  if (trans_weight_1203) {
                    weights_slice = weights + (kch*kernel_dim*kernel_dim + krow_*kernel_dim+kcol_) * out_channels + poch;
                  } else if (trans_weight_0132) {
                    weights_slice = weights + (krow_*kernel_dim*out_channels + kcol_*out_channels + poch) * in_channels + kch;
                  }

                  if(b_reuse && (pocol + porow + b > 0)) weights_slice = NULL;
                  for(int porow_inner = 0; porow_inner < porows_outer_loop; porow_inner += porows){
                    const int orow = (porow + porow_inner) * pool_stride - pool_padding;
                    const int orow_floored = orow < 0 ? 0 : orow;
                    const int irow = orow_floored * stride + krow*kernel_dilation - padding;
                    elem_t * out = output + (b*pool_out_dim*pool_out_dim + (porow+porow_inner)*pool_out_dim + pocol) * out_stride + poch;
                    if (trans_output_1203) {
                      out = output + ((porow+porow_inner)*pool_out_dim*batch_size + pocol*batch_size + b) * out_channels + poch;
                    }
                    if (krow + krows < kernel_dim ||
                        kcol + kcols < kernel_dim ||
                        kch + kchs < in_channels) {
                      out = NULL;
                    }

                    const int porows_ = pool_out_dim - (porow + porow_inner) > porows ? porows : pool_out_dim - (porow + porow_inner);
                    const int orows_ = porows_ * pool_stride + pool_size - 1;

                    const int pupad = orow < 0 ? -orow : 0;
                    const int pdpad = orow + orows_ > out_dim ? orow + orows_ - out_dim : 0;
                    const int irows_ = (orows_ - pupad - pdpad) * stride + dilated_krows_ - 1;

                    int upad = irow < 0 ? -irow : 0;
                    int dpad = irow + irows_ > dilated_in_dim ? irow + irows_ - dilated_in_dim : 0;

                    if (input_dilated) {
                      lpad += lpad == 0 && icol % 2 != 0;
                      rpad += rpad == 0 && (icol + icols_) % 2 != 1;
                      upad += upad == 0 && irow % 2 != 0;
                      dpad += dpad == 0 && (irow + irows_) % 2 != 1;
                    }
                    elem_t * in = input + (b*in_dim*in_dim + ((irow+upad)>>input_dilated)*in_dim + ((icol+lpad)>>input_dilated)) * in_stride + kch;
                    if (trans_input_3120) {
                      in = input + (kch*in_dim*in_dim + ((irow+upad)>>input_dilated)*in_dim + ((icol+lpad)>>input_dilated)) * batch_size + b;
                    }
                    if(a_reuse && (poch > 0)) in = NULL;

                    int cfgid = 0;
                    for(int poch_inner  = 0; poch_inner < pochs_outer_loop; poch_inner += pochs){
                      const int pochs_ = out_channels - (poch + poch_inner) > pochs ? pochs : out_channels - (poch + poch_inner);
                      acc_t * bias_ = bias + poch + poch_inner;
                      if (krow > 0 ||
                              kcol > 0 ||
                              kch > 0) {
                          bias_ = NULL;
                      }
#if ReRoCC == 1
                      rr_set_opc(XCUSTOM_ACC, cfgid);
                      cfgid ++;
#endif
                      weights_slice = weights_slice != NULL ? weights_slice + poch_inner : weights_slice;
                      out = out != NULL ? out + poch_inner : out;
                      //size_t tracker = (int)(porow_inner/porows) + (int)(poch_inner/pochs);                  
    //printf("tracker: %d, porow: %d, porow_inner: %d, poch: %d, poch_inner: %d, porows_: %d, orows_: %d, irows_: %d, pochs_: %d\n", tracker, porow, porow_inner, poch, poch_inner, porows_, orows_, irows_, pochs_);
/*
                      sp_tiled_conv(
                          batch_size, in_dim, in_dim, in_channels,
                          out_channels, out_dim, out_dim, pool_out_dim, pool_out_dim,

                          stride, padding, kernel_dim, kernel_dilation,

                          in_stride, weight_stride, out_stride,

                          pool_size, pool_stride, pool_padding,

                          batches_,
                          porows_, pocols_, pochs_,
                          krows_, kcols_, kchs_,

                          lpad, rpad, upad, dpad,
                          plpad, prpad, pupad, pdpad,

                          in,
                          weights_slice,
                          out,
                          bias_,

                          act, scale,

                          wrot180, trans_output_1203, trans_input_3120,
                          trans_weight_1203, trans_weight_0132,

                          no_bias, no_pool, downsample, input_dilated,
                          false, a_spad_id, b_spad_id);
  */                   
                      const int orows = porows_ * pool_stride + pool_size - 1 - pupad - pdpad;
                      const int ocols = pocols_ * pool_stride + pool_size - 1 - plpad - prpad; 
                      int max_pixels_per_row = 1; // first layer optimization
                      gemmini_loop_conv_ws(batch_size, in_dim, in_dim, in_channels, out_channels, out_dim, out_dim, pool_out_dim, pool_out_dim, stride, padding, kernel_dim, kernel_dilation, pool_size, pool_stride, pool_padding, batches_, porows_, pocols_, pochs_, krows_, kcols_, kchs_, lpad, rpad, upad, dpad, plpad, prpad, pupad, pdpad, orows, ocols, weights_slice, out, bias_, in, no_bias, no_pool, downsample, wrot180, input_dilated, act, trans_output_1203, trans_weight_1203, trans_weight_0132, trans_input_3120, max_pixels_per_row, in_stride, weight_stride, out_stride, false, a_spad_id, b_spad_id);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
#if ReRoCC == 1
  for (int i = 0; i < num_array; i++){
    //printf("fencing\n");
    rr_fence(i); 
  }
#endif
}

static void tiled_opcode_conv_auto(
        int batch_size, int in_dim, int in_channels,
        int out_channels, int out_dim,
        int stride, int input_dilation, int kernel_dilation, int padding, int kernel_dim,

        int in_stride, int weight_stride, int out_stride,

        bool wrot180, bool trans_output_1203, bool trans_input_3120,
        bool trans_weight_1203, bool trans_weight_0132,

        elem_t * input,
        elem_t * weights,
        acc_t * bias,
        elem_t * output,

        int act, acc_scale_t scale, //, size_t relu6_shift,
        int pool_size, int pool_stride, int pool_padding, bool pool_ceil_dim,
        int num_array){ //int cid, 

        //float alpha, int real_cycle) {

    const bool no_pool = pool_stride == 0;
    if (no_pool) {
        pool_size = 1;
        pool_stride = 1;
        pool_padding = 0;
    }

    const int pool_out_dim = (out_dim + 2*pool_padding - pool_size) / pool_stride + 1;

    bool div_orow = false;
    bool div_och = false;
    int orow_divide = 1;
    int och_divide = 1;
    int out_channels_save = out_channels;
    int pool_out_row = pool_out_dim;
    //if(out_channels >= num_array * DIM * 2){
    if(out_channels >= num_array * DIM * MAX_BLOCK_LEN || !no_pool){
      out_channels = ceil_divide_int(out_channels, num_array);
      div_och = true;
      och_divide = num_array;
      if(out_channels % DIM != 0){
        out_channels = ceil_divide_int(out_channels, DIM) * DIM;
      }
    }
    else if(out_channels >= num_array * DIM && in_dim < num_array * ((DIM*3)/4)){
      out_channels = ceil_divide_int(out_channels, num_array);
      div_och = true;
      och_divide = num_array;
      if(out_channels % DIM != 0){
        out_channels = ceil_divide_int(out_channels, DIM) * DIM;
      }
    }
    else{
      div_orow = true;
      orow_divide = num_array;
      pool_out_row = ceil_divide_int(pool_out_row, num_array);
      
    }

   //// printf("div_orow: %d, div_och: %d, orow_divide: %d, och_divide: %d\n", div_orow, div_och, orow_divide, och_divide);

    int args[7] = {batch_size, pool_out_row, pool_out_dim, out_channels, kernel_dim, kernel_dim, in_channels};
    //int args[11] = {batch_size, in_dim, in_channels, out_channels, out_dim, kernel_dim, pool_out_dim, pool_out_row, 0, real_cycle, alpha_scale};
 
    int* tile_args = tiling_factor_calculate(args, stride,  pool_size, pool_stride, kernel_dilation, padding); 
    int batches = tile_args[0];
    int porows = tile_args[1];
    int pocols = tile_args[2];
    int pochs = tile_args[3];
    int krows = tile_args[4];
    int kcols = tile_args[5];
    int kchs = tile_args[6];

    //int num_tile = tile_args[7];
    //int total_mem = tile_args[8];
    //int prediction = tile_args[9];
    //alpha = tile_args[10];

/* 
    printf("batches = %d\n", batches);
    printf("orows   = %d\n", porows);
    printf("ocols   = %d\n", pocols);
    printf("ochs    = %d\n", pochs);
    printf("krows   = %d\n", krows);
    printf("kcols   = %d\n", kcols);
    printf("kchs    = %d\n\n", kchs);
*/
/*  
    printf("total spad_rows reserved: %d\n", spad_rows);
    printf("total acc_rows reserved: %d\n\n", acc_rows);

    printf("scratchpad row utilization: %d%%\n", (spad_rows*100) / max_spad_rows);
    printf("accumulator row utilization: %d%%\n\n", (acc_rows*100) / max_acc_rows);

    printf("inner matmul size: i=%d, j=%d, k=%d\n\n", ocols, ochs, kchs);
  */  

    tiled_opcode_conv(
        batch_size, in_dim, in_channels,
        out_channels_save, out_dim,
        stride, input_dilation, kernel_dilation, padding, kernel_dim,

        in_stride, weight_stride, out_stride,

        wrot180, trans_output_1203, trans_input_3120,
        trans_weight_1203, trans_weight_0132,

        batches,
        porows, pocols, pochs,
        krows, kcols, kchs,

        input,
        weights,
        bias,
        output,

        act, scale, //relu6_shift,
        pool_size, no_pool ? 0 : pool_stride, pool_padding, pool_ceil_dim,

        WS,
        div_orow, div_och,
        num_array);//, cid,
        //num_tile, total_mem);
}

static void tiled_opcode_conv_default(
        int batch_size, int in_dim, int in_channels,
        int out_channels, int out_dim,
        int stride, int kernel_dilation, int padding, int kernel_dim,
        int out_stride,
        //bool wrot180, bool trans_output_1203, bool trans_input_3120,
        //bool trans_weight_1203, bool trans_weight_0132,

        elem_t * input,
        elem_t * weights,
        acc_t * bias,
        elem_t * output,

        int act, acc_scale_t scale,// size_t relu6_shift,
        int pool_size, int pool_stride, int pool_padding, bool pool_ceil_dim,
        int num_array, int cid) {
    uint64_t start = read_cycles();
    int in_stride = (in_channels % (2*BANK_LEN) == 0) ? in_channels + BANK_LEN : in_channels;
    int weight_stride = (out_channels % (2*BANK_LEN) == 0) ? out_channels + BANK_LEN : out_channels;
    //printf("num array: %d\n", num_array);
    //pthread_mutex_lock(&print_cid);
    //if(num_array > 1) printf("conv cid: %d\n", cid);
    //fflush(stdout);
    //pthread_mutex_unlock(&print_cid);

    //if(in_channels == 3) in_stride = BANK_LEN;

    //printf("conv, num_array: %d, cid: %d, batch: %d, in dim: %d, in channel: %d, out channel: %d, out_dim: %d, kernel dim: %d, padding :%d, in_stride: %d, out_stride: %d, weight_stride: %d\n", num_array, cid, batch_size, in_dim, in_channels, out_channels, out_dim, kernel_dim, padding, in_stride, out_stride, weight_stride);


  tiled_opcode_conv_auto(
      batch_size, in_dim, in_channels,
      out_channels, out_dim,
      stride, 1, kernel_dilation, padding, kernel_dim,
      in_stride, weight_stride, out_stride,
      false, false, false,
      false, false,
      
      input, weights, bias, output,

      act, scale, //relu6_shift,
      pool_size, pool_stride, pool_padding, pool_ceil_dim,
      
      num_array);//, cid,
      //alpha, real_cycle);
#if DNN_PROFILE == 1
  uint64_t end = read_cycles();
  if(cid == 0){
    layer_cycles[num_array - 1][layer_pointer] = end - start;
    layer_pointer ++;
  }
  if(cid < 2){
    mt_layer_cycles[cid][num_array-1][mt_layer_pointer[cid]] = end - start;
    mt_layer_pointer[cid] ++;
  }
#endif
}

// for special case (lask K iterating factor)
static void sp_tiled_opcode_matmul_ws(elem_t * A, elem_t * B,
        void * D, void * C,
        //const size_t sub_num_I, const size_t sub_num_J, const size_t sub_num_K,
        scale_t A_scale_factor, scale_t B_scale_factor, scale_acc_t D_scale_factor,
        size_t I, size_t J, size_t K, size_t pad_I, size_t pad_J, size_t pad_K,
        size_t A_row_stride, size_t B_row_stride, size_t D_row_stride, size_t C_row_stride,
        bool a_transpose, bool b_transpose,
        bool full_C, bool low_D,
        bool no_bias, bool repeating_bias,
        size_t act,
        bool div_I, bool div_J,
        size_t num_array,
        size_t a_spad_id, size_t b_spad_id) {

  // Combined loop
    // for now, assume 1 opcode
    bool ex_acc = !no_bias || D==NULL;
    int T = div_I ? I : J;
    int T0 = 0;//ceil_divide_int(T, num_array); //div_I ? ceil_divide_int(I, num_array) : ceil_divide_int(J, num_array);
    int pad_T = 0;
    D_row_stride = repeating_bias ? 0 : D_row_stride;

    int num_array_store = num_array;
    for(int i = 0; i < num_array_store; i++){
      T0 = ceil_divide_int(T, num_array);
      bool last = i == num_array - 1;
      if (last)
        pad_T = div_I ? pad_I : pad_J;
//#if rerocc_debug == 1
      //printf("divide I: %d, divide J: %d, tracker: %d, T: %d, T0: %d, pad_T: %d, A: %llu, B: %llu, C: %llu, D: %llu, repeating bias: %d\n", div_I, div_J, i, T, T0, pad_T, A, B, C, D, repeating_bias);
//#endif
#if ReRoCC == 1
      rr_set_opc(XCUSTOM_ACC, i);
#endif
      //rerocc_assign(OP3, i);

      gemmini_loop_ws(div_I ? T0 : I, div_J ? T0 : J, K, div_I ? pad_T : pad_I, div_J ? pad_T : pad_J, pad_K, A, B, no_bias ? NULL : D, C,
        A_row_stride, B_row_stride, D_row_stride, C_row_stride,
        a_transpose, b_transpose,
        full_C, low_D, ex_acc,
        act, a_spad_id, b_spad_id, false, false);
      
      if(div_I && !last){
        if (A!=NULL) A = (a_transpose) ? A + T0 * DIM : A + A_row_stride * T0 * DIM;
        if (C!=NULL) C = C+C_row_stride*T0*DIM*sizeof(elem_t);
        if (D!=NULL && !no_bias){
          if(low_D) D = (int8_t*)D + (D_row_stride*T0*DIM)*sizeof(elem_t);
          else  D = &(((acc_t*)D)[D_row_stride*T0*DIM]); //D = (acc_t*)(D+D_row_stride*T0*DIM);
        }
      }
      if(div_J && !last){
        // both div_I, div_J -> diagonal (transposed)
        if (B!=NULL) B = (b_transpose) ? B + B_row_stride * T0 * DIM : B + T0 * DIM;
        if (C!=NULL) C = C+T0*DIM*sizeof(elem_t);
        if (D!=NULL && !no_bias){
          if(low_D) D = (int8_t*)D + (T0*DIM)*sizeof(elem_t);
          else D = &(((acc_t*)D)[T0*DIM]); //D = (acc_t*)(D+T0*DIM); 
        }
      }
      T -= T0;
      num_array --;
    }
}

// dim_I, dim_J are already fully dividied into subarray size
static void tiled_opcode_matmul_outer(size_t dim_I_original, size_t dim_J_original, size_t dim_K_original,
        size_t dim_I, size_t dim_J, size_t dim_K,
        //const size_t sub_num_I, const size_t sub_num_J, const size_t sub_num_K,
        elem_t* A, elem_t* B,
        void * D, void * C,
        size_t stride_A, size_t stride_B, size_t stride_D, size_t stride_C,
        scale_t A_scale_factor, scale_t B_scale_factor, scale_acc_t D_scale_factor,
        size_t tile_I, size_t tile_J, size_t tile_K,
        int act, acc_scale_t scale, bool repeating_bias,
        bool a_transpose, bool b_transpose,
        bool full_C, bool low_D,
        int dataflow,  
        int num_array, int cid){ 
        //int num_tile, int total_mem) {
  
    //pthread_mutex_lock(&print_cid);
    //if(num_array > 1) printf("matmul cid: %d\n", cid);
    //fflush(stdout);
    //pthread_mutex_unlock(&print_cid);
  // based on original dimension
  const size_t dim_I_padded = (dim_I_original / DIM + (dim_I_original % DIM != 0)) * DIM;
  const size_t dim_J_padded = (dim_J_original / DIM + (dim_J_original % DIM != 0)) * DIM;
  const size_t dim_K_padded = (dim_K_original / DIM + (dim_K_original % DIM != 0)) * DIM;

  bool div_J = (dim_J_original != dim_J);
  bool div_I = !div_J;

  // need to iterate outer tile granularity
  size_t outer_tile_I = div_I ? tile_I * num_array : tile_I;
  size_t outer_tile_J = div_J ? tile_J * num_array : tile_J;

  // to increase loop iter factor by +1
  const size_t I0 = dim_I_padded / (outer_tile_I*DIM) + (dim_I_padded % (outer_tile_I*DIM) != 0);
  const size_t J0 = dim_J_padded / (outer_tile_J*DIM) + (dim_J_padded % (outer_tile_J*DIM) != 0);
  const size_t K0 = dim_K_padded / (tile_K*DIM) + (dim_K_padded % (tile_K*DIM) != 0);

  // These lines here are supposed to help us deal with when the dimensions of
  // the systolic array aren't divisible by the tiling factors
  const size_t last_I = dim_I_padded % (outer_tile_I*DIM) == 0 ? outer_tile_I : (dim_I_padded/DIM) % outer_tile_I;
  const size_t last_J = dim_J_padded % (outer_tile_J*DIM) == 0 ? outer_tile_J : (dim_J_padded/DIM) % outer_tile_J;
  const size_t last_K = dim_K_padded % (tile_K*DIM) == 0 ? tile_K : (dim_K_padded/DIM) % tile_K;

  // These lines are supposed to figure out how much padding the hardware is
  // supposed to add for the final tile
  const size_t padding_I = dim_I_padded - dim_I_original;
  const size_t padding_J = dim_J_padded - dim_J_original;
  const size_t padding_K = dim_K_padded - dim_K_original;

  const bool no_bias = D == NULL;

  if (no_bias) {
    D = (void*) 1; // Dummy address which isn't NULL
  }
/*
   if(mode == 6){
      if((div_J || num_array == 1) && (I0==1))
          B_direct_dram = true;
      else B_direct_dram = false;
   }
   */
  const size_t sizeof_D = low_D ? sizeof(elem_t) : sizeof(acc_t) ;
  const size_t sizeof_C = full_C ? sizeof(acc_t) : sizeof(elem_t);

  for(int i = 0; i < num_array; i++){
#if ReRoCC == 1
      rr_set_opc(XCUSTOM_ACC, i);
#endif
    //rerocc_assign(i);
    gemmini_extended_config_ex(dataflow, act, 0, 1, a_transpose, b_transpose);
    gemmini_extended_config_st(stride_C * sizeof_C, act, scale);
    gemmini_extended3_config_ld(stride_A * sizeof(elem_t), A_scale_factor, false, 0);
    gemmini_extended3_config_ld(stride_B * sizeof(elem_t), B_scale_factor, false, 1)
    gemmini_extended3_config_ld(repeating_bias ? 0 : (stride_D * sizeof_D), D_scale_factor, low_D, 2);
  }
  size_t a_spad_id = 0;
  size_t b_spad_id = 0;

  bool a_reuse = false;
  bool b_reuse = false;

  if(J0 * K0 <= 2) 
    b_reuse = true;
  if(I0 * K0 <= 2)
    a_reuse = true;


  int num_array_store = num_array;
  int no_tile = 0;
 
  for (size_t i0 = 0; i0 < I0; i0++)
    for (size_t j0 = 0; j0 < J0; j0++){ 
      for (size_t k0 = 0; k0 < K0; k0++) {
        no_tile ++;
        if(a_reuse)
          a_spad_id = ((i0+k0) == 0) ? 1 : 2;
        if(b_reuse)
          b_spad_id = ((j0+k0) == 0) ? 1 : 2;

        void * pre;
        if (k0 != 0) {
          pre = NULL;
        } else {
          size_t bias_row = repeating_bias ? 0 : i0*outer_tile_I*DIM;
          pre = &(((acc_t*)D)[bias_row * stride_D + j0 * outer_tile_J * DIM]);
          if(low_D) pre = (int8_t*)D + (bias_row * stride_D + j0 * outer_tile_J * DIM)*sizeof_D;
        }

        void * out = k0 == K0-1 ? (int8_t*)C + (i0*outer_tile_I*DIM*stride_C + j0*outer_tile_J*DIM)*sizeof_C : NULL;

        size_t I = i0 < I0-1 ? outer_tile_I : last_I;
        size_t J = j0 < J0-1 ? outer_tile_J : last_J;
        size_t K = k0 < K0-1 ? tile_K : last_K; // entire K

        // if last iteration, I/K is the sum of all subarrays
        const bool last = div_J ? j0 == J0-1 : i0 == I0-1;         
        num_array_store = num_array;
        if(last){
          if(div_J && last_J <= num_array){
            num_array_store = last_J;
          }
          else if(div_I && last_I <= num_array){
            num_array_store = last_I;
          }
        }
        const size_t pad_I = i0 == I0-1 ? padding_I : 0;
        const size_t pad_J = j0 == J0-1 ? padding_J : 0;
        const size_t pad_K = k0 == K0-1 ? padding_K : 0;

        elem_t * a = a_transpose ? (A + k0*tile_K*DIM*stride_A + i0*outer_tile_I*DIM)
          : (A + i0*outer_tile_I*DIM*stride_A + k0*tile_K*DIM);

        elem_t * b = b_transpose ? (B + j0*outer_tile_J*DIM*stride_B + k0*tile_K*DIM)
          : (B + k0*tile_K*DIM*stride_B + j0*outer_tile_J*DIM);

        if(a_reuse && j0 >= 1) a = NULL;
        if(b_reuse && i0 >= 1) b = NULL;
        sp_tiled_opcode_matmul_ws(a, b, pre, out,// NULL,
              A_scale_factor, B_scale_factor, D_scale_factor,
              //sub_num_I, sub_num_J, sub_num_K,
              I, J, K,
              pad_I, pad_J, pad_K,
              stride_A, stride_B, stride_D, stride_C,
              a_transpose, b_transpose,
              full_C, low_D,
              no_bias, repeating_bias,
              act,
              div_I, div_J,
              num_array_store,
              a_spad_id, b_spad_id); 
      }
    }
#if ReRoCC == 1
  for (int i = 0; i < num_array; i++){
   // rerocc_assign(OP3, i);
   // gemmini_fence();
    rr_fence(i);
  }
#endif
}

static void tiled_opcode_matmul_auto_multi(size_t dim_I, size_t dim_J, size_t dim_K,  
  elem_t* A, elem_t* B,
  void * D, elem_t* C, 
  //const size_t sub_num_I, const size_t sub_num_J, const size_t sub_num_K,
  size_t stride_A, size_t stride_B, size_t stride_D, size_t stride_C,
  scale_t A_scale_factor, scale_t B_scale_factor, scale_acc_t D_scale_factor,
  int act, acc_scale_t scale, acc_scale_t bert_scale, bool repeating_bias, 
  bool A_transpose, bool B_transpose,
  bool full_C, bool low_D,
  //size_t orow_divide, size_t batch_divide, size_t cid, size_t group_id,
  const size_t num_array, size_t cid)
  //float alpha, int real_cycle) 
// real_cycle: -1 -> don't do throttling
{

  size_t* args_out;
  size_t args[7];
  size_t dim_J_original = dim_J;
  size_t dim_K_original = dim_K;
  size_t dim_I_original = dim_I;
  int orow_divide = 1;
  int och_divide = 1;
  if(dim_J >= num_array * DIM * MAX_BLOCK_LEN){
    och_divide = num_array;
    dim_J = ceil_divide_int(dim_J, num_array);
    if(dim_J % DIM != 0){
      dim_J = ceil_divide_int(dim_J, DIM) * DIM;
    }
  }
  else{
    orow_divide = num_array;
    dim_I = ceil_divide_int(dim_I, num_array);
    //if(dim_I % DIM != 0){
    //  dim_I = ceil_divide_int(dim_I, DIM) * DIM;
    //}
  }

  // A_from_dram, write_to_dram: false for now
  args_out = tiling_factor_matmul_calculate_auto(dim_I_original, dim_J_original, dim_K_original, orow_divide, och_divide, num_array, cid, args);

  bool no_bias = (D == NULL);
  dim_I = args_out[3];
  dim_J = args_out[4];
  dim_K = args_out[5];
  size_t tile_I = args_out[0];
  size_t tile_J = args_out[1];
  size_t tile_K = args_out[2];


#if rerocc_debug == 1
  printf("dim_I: %d, dim_J: %d, dim_K: %d, tile_I: %d, tile_J: %d, tile_K: %d\n", dim_I, dim_J, dim_K, tile_I, tile_J, tile_K);
#endif

  tiled_opcode_matmul_outer(dim_I_original, dim_J_original, dim_K_original,
      dim_I, dim_J, dim_K,
      //sub_num_I, sub_num_J, sub_num_K,
      A, B, no_bias ? NULL : D, C, // for now, disable global workload division
      //A + A_orow_offset + A_batch_offset, B + out_offset, no_bias ? NULL : D + out_offset*sizeof(acc_t), C + C_orow_offset + out_offset + C_batch_offset,
      stride_A, stride_B, stride_C, stride_C,
      A_scale_factor, B_scale_factor, D_scale_factor,
      tile_I, tile_J, tile_K,
      act, scale, repeating_bias,
      A_transpose, B_transpose, false, low_D,
      (int) WS,
      num_array, cid);//    num_tile, total_mem);
}


static void tiled_opcode_matmul_nn_auto_multi(size_t dim_I, size_t dim_J, size_t dim_K,
  //const size_t sub_num_I, const size_t sub_num_J, const size_t sub_num_K,
  size_t stride_A, size_t stride_B, size_t stride_C,
  elem_t* A, elem_t* B,
  void * D, elem_t* C,
  bool A_transpose, bool B_transpose,
  int act, acc_scale_t scale, bool repeating_bias,
  enum tiled_matmul_type_t tiled_matmul_type,
  //size_t orow_divide, size_t batch_divide, size_t cid, size_t group_id,
  const size_t num_array, int cid)//, float alpha, int real_cycle)
// orow_divide -> total, num_array -> inner
// for now assume one workload (no cid, orow_divide)
{

  size_t* args_out;
  size_t args[6];
  size_t dim_J_original = dim_J;
  size_t dim_K_original = dim_K;
  size_t dim_I_original = dim_I;
  int orow_divide = 1;
  int och_divide = 1;
  if(dim_J >= num_array * DIM * MAX_BLOCK_LEN){
    dim_J = ceil_divide_int(dim_J, num_array);
    if(dim_J % DIM != 0){
      dim_J = ceil_divide_int(dim_J, DIM) * DIM;
    }
    och_divide = num_array;
  }
  else{
    dim_I = ceil_divide_int(dim_I, num_array);
    //if(dim_I % DIM != 0){
    //  dim_I = ceil_divide_int(dim_I, DIM) * DIM;
    //}
    orow_divide = num_array;
  }

  //int alpha = (0.5 * 100);
  //args[8] = real_cycle;
  //rgs[9] = alpha >= 0 ? (int)(alpha*100) : -1;
  // A_from_dram, write_to_dram: false for now
  args_out = tiling_factor_matmul_calculate_auto(dim_I_original, dim_J_original, dim_K_original, orow_divide, och_divide, num_array, cid, args);

  dim_I = args_out[3];
  dim_J = args_out[4];
  dim_K = args_out[5];
  size_t tile_I = args_out[0];
  size_t tile_J = args_out[1];
  size_t tile_K = args_out[2];
  //int num_tile = args_out[6];
  //int total_mem = args_out[7];
  //alpha = args_out[9];
  //int prediction = args_out[8];

  bool no_bias = (D == NULL);

#if rerocc_debug == 1
  printf("dim_I: %d, dim_J: %d, dim_K: %d, tile_I: %d, tile_J: %d, tile_K: %d\n", dim_I, dim_J, dim_K, tile_I, tile_J, tile_K);
#endif

  tiled_opcode_matmul_outer(dim_I_original, dim_J_original, dim_K_original,
      dim_I, dim_J, dim_K,
      //sub_num_I, sub_num_J, sub_num_K,
      A, B, no_bias ? NULL : D, C, // for now, disable global workload division
      //A + A_orow_offset + A_batch_offset, B + out_offset, no_bias ? NULL : D + out_offset*sizeof(acc_t), C + C_orow_offset + out_offset + C_batch_offset,
      stride_A, stride_B, stride_C, stride_C,
      MVIN_SCALE_IDENTITY, MVIN_SCALE_IDENTITY, MVIN_SCALE_IDENTITY,
      tile_I, tile_J, tile_K,
      act, scale, repeating_bias,
      A_transpose, B_transpose, false, false,
      (int)tiled_matmul_type,
      num_array, cid);
      //num_tile, total_mem);
}

static void tiled_opcode_matmul_nn_default(size_t dim_I, size_t dim_J, size_t dim_K,
  size_t stride_C,
  elem_t* A, elem_t* B,
  void * D, elem_t* C,
  int act, acc_scale_t scale, bool repeating_bias,
  enum tiled_matmul_type_t tiled_matmul_type,
  size_t num_array, int cid){
  //size_t orow_divide, size_t batch_divide, size_t cid, size_t group_id){
  uint64_t start = read_cycles();
  size_t stride_A = (dim_K % (2*BANK_LEN) == 0) ? dim_K + BANK_LEN : dim_K;
  size_t stride_B = (dim_J % (2*BANK_LEN) == 0) ? dim_J + BANK_LEN : dim_J;
/*
  int real_cycle = -1;
  float alpha = -1; // ToDo

#if SUB_MODEL_MODE == 1
  if (curr_block[cid] != -1){
    if((int)(layer_pointer[cid] / SUB_MODEL_SIZE) != curr_block[cid]){
#if PRINT == 1
	printf("cid %d current block %d current layer %d skipped\n", cid, curr_block[cid], layer_pointer[cid]);
#endif
	return;
    }
  }
#if PRINT == 1
  printf("cid %d current block %d current layer %d execute\n", cid, curr_block[cid], layer_pointer[cid]);
#endif
#endif
*/
  //printf("matmul A: 0x%08lx, B: 0x%08lx, C: 0x08lx\n", A, B, C);
  tiled_opcode_matmul_nn_auto_multi(
      dim_I, dim_J, dim_K,
      stride_A, stride_B, stride_C,
      A, B, D, C,
      false, false,
      act, scale, repeating_bias,
      WS, num_array, cid); //, alpha, real_cycle); // start tracker: 0
      //orow_divide, batch_divide, cid, group_id);
#if DNN_PROFILE == 1
  uint64_t end = read_cycles();
  if(cid == 0){
    layer_cycles[num_array - 1][layer_pointer] = end - start;
    layer_pointer ++;
  }
  if(cid < 2){
    mt_layer_cycles[cid][num_array-1][mt_layer_pointer[cid]] = end - start;
    mt_layer_pointer[cid] ++;
  }
#endif
}

static void sp_tiled_opcode_resadd(size_t I, size_t J,
        const scale_t A_scale,
        const scale_t B_scale,
        const elem_t * A, const elem_t * B, elem_t * C,
        size_t A_row_stride, size_t B_row_stride, size_t C_row_stride,
        bool relu, size_t num_array) {

    // Use the new mvin2 command to overlap mvin A, mvin B, and mvout C

    int acc_I[8] = {0};
    int I_arr[8] = {0};
    I_arr[0] = num_array != 1 ? ceil_divide_int(I, num_array * DIM) * DIM : I;
    acc_I[0] = 0;
    size_t rounded_up_J = (J / DIM + (J % DIM != 0)) * DIM;
    size_t pad_J = J % DIM == 0 ? 0 : DIM - (J % DIM);

    for(int i = 1; i < num_array; i++){
      I -= I_arr[i-1];
      acc_I[i] += acc_I[i-1] + I_arr[i-1];
      I_arr[i] = i != num_array - 1 ? ceil_divide_int(I, (num_array - i)*DIM) * DIM : I;
    }

     for(int i = 0; i < num_array; i++){ 
      if(I_arr[i] <= 0) break;
#if ReRoCC == 1
      rr_set_opc(XCUSTOM_ACC, i);
#endif
      //printf("accumulated I: %d, I length: %d\n", acc_I[i], I_arr[i]);
      int tile_I = (I_arr[i] % DIM) == 0 ? (int)(I_arr[i] / DIM) : (int)(I_arr[i]/DIM) + 1;
      int pad_I = (I_arr[i] % DIM) == 0 ? 0 : DIM - (I_arr[i] % DIM);
      gemmini_loop_ws(tile_I, rounded_up_J/DIM, 0, pad_I, pad_J, 0, A+A_row_stride*acc_I[i], B+B_row_stride*acc_I[i], NULL, C+C_row_stride*acc_I[i], A_row_stride, B_row_stride, 0, C_row_stride, false, false, false, false, false, relu, 0, 0, true, false);
    }
}

// Compute MVIN_SCALE(A, A_scale) + MVIN_SCALE(B, B_scale) = C
static void tiled_opcode_resadd(const size_t I, const size_t J, const size_t A_stride, const size_t B_stride, const size_t C_stride,
        const size_t tile_I, const size_t tile_J,
        const scale_t A_scale,
        const scale_t B_scale,
        const acc_scale_t C_scale,
        const elem_t * A,
        const elem_t * B,
        elem_t * C,
        bool relu,
        enum tiled_matmul_type_t matadd_type,
        int num_array, int cid){
        //int num_tile, int total_mem) {

    //pthread_mutex_lock(&print_cid);
    //if(num_array > 1) printf("resadd cid: %d\n", cid);
    //fflush(stdout);
    //pthread_mutex_unlock(&print_cid);
  size_t outer_tile_I = num_array * tile_I;
  //printf("tile_I: %d, tile_J: %d, num_array: %d, start_tracker: %d\n", tile_I, tile_J, num_array, start_tracker);
  for(int i = 0; i < num_array; i++){
#if ReRoCC == 1
      rr_set_opc(XCUSTOM_ACC, i);
#endif
    gemmini_extended_config_st(C_stride * sizeof(elem_t), relu ? RELU : NO_ACTIVATION, C_scale);
    gemmini_config_ex(WS, 0, 0);
    gemmini_extended4_config_ld(A_stride * sizeof(elem_t), A_scale, true, DIM, 0);
    gemmini_extended4_config_ld(B_stride * sizeof(elem_t), B_scale, true, DIM, 1);
    gemmini_extended3_config_ld(0, 1, false, 2);
  }
  int num_array_store = num_array;

  for (size_t j = 0; j < J; j += tile_J) {
    num_array_store = num_array;
    for (size_t i = 0; i < I; i += outer_tile_I) {
        //printf("i: %d, j: %d\n", i, j);
        const size_t I_tile = i + outer_tile_I <= I ? outer_tile_I : I - i;
        const size_t J_tile = j + tile_J <= J ? tile_J : J - j; // aggregated
        const bool last = i + outer_tile_I > I;         
        if(last){
          if(I_tile <= num_array*DIM){
            num_array_store = ceil_divide_int(I_tile, DIM);
          }
        }

        //printf("I: %d, J: %d\n", I_tile, J_tile);
        const elem_t * a = A + i * A_stride + j;
        const elem_t * b = B + i * B_stride + j;
        elem_t * c = C + i * C_stride + j;

        sp_tiled_opcode_resadd(I_tile, J_tile,
                A_scale, B_scale, a, b, c,
                A_stride, B_stride, C_stride,
                relu, num_array_store);
    }
  }
#if ReRoCC == 1
  for (int i = 0; i < num_array; i++){
    rr_fence(i);
  }
#endif
}



static void tiled_opcode_resadd_auto_multi(size_t I, size_t J,
    const scale_t A_scale,
    const scale_t B_scale,
    const acc_scale_t C_scale,
    const size_t A_stride,
    const size_t B_stride,
    const size_t C_stride,
    const elem_t * A,
    const elem_t * B,
    elem_t * C,
    bool relu,
    enum tiled_matmul_type_t matadd_type,
    size_t num_array, size_t cid){
//    float alpha, int real_cycle){
 // real_cycle = -1 -> no throttler
// real_cycle = 0 -> as predicted 
  //int args_in[] = {0, 0, 0, 0, 0, 0};
  int args_in[3] = {0};
  bool A_cached = false;
  int * args = tiled_resadd_bubble_calculate(args_in, I, J, num_array, cid);//, A_cached, real_cycle, alpha);

  //int num_tile = args[0];
  //int total_mem = args[1];
  //int prediction = args[2];
  int tile_I = args[0];
  int tile_J = args[1];

	//printf("ideal cycle: %d, target_cycle: %d, \n", ideal_cycles, target_cycles);
  //printf("priority: %d, window: %d, target_load: %d \n", priority, window, target_load);
 
     //printf("tile_I: %llu\n", tile_I);
     //printf("tile_J: %llu\n", tile_J);

  if (matadd_type == WS) {
    tiled_opcode_resadd(I, J, A_stride, B_stride, C_stride,
        tile_I, tile_J, 
        A_scale, B_scale, C_scale, A, B, C,
        relu, matadd_type, num_array, cid);
        //num_tile, total_mem);
  } 
  else {
    printf("Unsupported type\n");
    exit(1);
  }
}

static void tiled_opcode_resadd_default(size_t I, size_t J,
    const scale_t A_scale,
    const scale_t B_scale,
    const acc_scale_t C_scale,
    const elem_t * A,
    const elem_t * B,
    elem_t * C,
    bool relu,
    size_t num_array, int cid){
    //size_t orow_divide, size_t batch_divide, size_t cid, size_t group_id) {
 // printf("resadd A: 0x%08lx, B: 0x%08lx, C: 0x08lx\n", A, B, C);
  size_t J_stride = (J % (BANK_LEN*2) == 0) ? J + BANK_LEN : J;
  uint64_t start = read_cycles(); 

  /*
  uint64_t overhead_start = read_cycles_re();
    for(int i = 0; i < num_array; i++)
      while(!rerocc_acquire(i, 1<<(i))){} //i+start_tracker
  uint64_t overhead_end = read_cycles_re();

  overhead += (overhead_end - overhead_start);
  */
  tiled_opcode_resadd_auto_multi(I, J, A_scale, B_scale, C_scale,
      J_stride, J_stride, J_stride,
      A, B, C,
      relu, WS, 
      num_array, cid);//, alpha, real_cycle);
#if DNN_PROFILE == 1
  uint64_t end = read_cycles();
  if(cid == 0){
    layer_cycles[num_array - 1][layer_pointer] = end - start;
    layer_pointer ++;
  }
  if(cid < 2){
    mt_layer_cycles[cid][num_array-1][mt_layer_pointer[cid]] = end - start;
    mt_layer_pointer[cid] ++;
  }
#endif
}

#endif
