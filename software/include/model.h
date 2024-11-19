// timing model
#define TL_BITS 128 
#define DRAM_CHANNEL 2
#define DRAM_BITS (64*DRAM_CHANNEL) 
#define CACHE_SIZE (2048*1024) // 2M Bytes
#define CACHE_BANKS 4

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

// predict AtA cycles for reconstruct (reorder)
uint64_t predict_AtA_reorder(int max_factor_height, int max_factor_width, int num_factor){
  int factor_width = ceil_divide_int(max_factor_width, DIM) * DIM;
  int factor_height = ceil_divide_int(max_factor_height, DIM) * DIM;
  int min_bw = MIN(DRAM_BITS, TL_BITS);
  uint64_t AtA_prefetch_time = ((factor_height * 32) / min_bw) * factor_width * num_factor * 2.5;
  uint64_t AtA_compute_mem_time = num_factor * ((factor_height * 32) / min_bw) * factor_height * 4; 
  uint64_t AtA_compute_comp_time = num_factor * ((factor_height * factor_width * factor_height) / (DIM * DIM));
  uint64_t AtA_compute_time = MAX(AtA_compute_mem_time, AtA_compute_comp_time) + MIN(AtA_compute_mem_time, AtA_compute_comp_time);
  // scatter add (load 2, store)
  uint64_t AtA_scatter_time = AtA_prefetch_time * 3 + ((factor_height * 32) / min_bw) * factor_width * num_factor * 4 + ((factor_width * 32) / min_bw) * num_factor * 4;
  AtA_scatter_time += num_factor * (factor_height / DIM) * factor_width + num_factor * factor_width / DIM;

  uint64_t total_expected = AtA_prefetch_time + AtA_compute_time + AtA_scatter_time;
  printf("AtA prefetch: %llu, compute: %llu, scatter: %llu, total: %llu\n", AtA_prefetch_time, AtA_compute_time, AtA_scatter_time, total_expected);
  return total_expected;
}

// predict AtA cycles for update
uint64_t predict_AtA_update(int max_factor_height, int max_factor_width, int num_factor, int supernode_width, int supernode_height){
  int factor_width = ceil_divide_int(max_factor_width, DIM) * DIM;
  int factor_height = ceil_divide_int(max_factor_height, DIM) * DIM;
  int min_bw = MIN(DRAM_BITS, TL_BITS);
  /*
  uint64_t AtA_prefetch_time = ((factor_height * 32) / min_bw) * factor_width * num_factor;
  uint64_t AtA_compute_mem_time = num_factor * ((factor_height * 32) / min_bw) * factor_width * 2; 
  uint64_t AtA_compute_comp_time = num_factor * ((factor_height * factor_width * factor_width) / (DIM * DIM));
  uint64_t AtA_compute_time = MAX(AtA_compute_mem_time, AtA_compute_comp_time);
  */
  uint64_t AtA_prefetch_time = ((factor_height * 32) / min_bw) * factor_width * num_factor * 3;
  uint64_t AtA_compute_mem_time = num_factor * ((factor_height * 32) / min_bw) * factor_height * 4; 
  uint64_t AtA_compute_comp_time = num_factor * ((factor_height * factor_width * factor_height) / (DIM * DIM));
  uint64_t AtA_compute_time = MAX(AtA_compute_mem_time, AtA_compute_comp_time) + MIN(AtA_compute_mem_time, AtA_compute_comp_time);
  AtA_compute_time *= 2; // old, new
  // scatter add (load 2, store)
  //uint64_t AtA_scatter_time = AtA_prefetch_time * 3 + ((factor_height * 32) / min_bw) * num_factor * 3;
  uint64_t AtA_scatter_time = AtA_prefetch_time * 2 + ((factor_height * 32) / min_bw) * factor_width * num_factor * 4 + ((factor_width * 32) / min_bw) * num_factor * 4;
  AtA_scatter_time += num_factor * (factor_height / DIM) * factor_width + num_factor * factor_width / DIM;
  AtA_prefetch_time *= 2;

  printf("supernode height: %d, width: %d\n", supernode_height, supernode_width);
  uint64_t eff_height = ceil_divide_int(supernode_height, DIM) * DIM; 
  uint64_t eff_width = ceil_divide_int(supernode_width, DIM) * DIM;
  uint64_t eff_subdiag = ceil_divide_int(supernode_height - supernode_width, DIM) * DIM;
  uint64_t AB_recover_mem_time = eff_width * ((eff_width * 32) / min_bw)  + eff_width * ((eff_height * 32) / min_bw) * 3;
  AB_recover_mem_time += eff_width * ((eff_width * 32) / DRAM_BITS)  + eff_width * ((eff_height * 32) / DRAM_BITS) * 2; // DRAM -> L2
  uint64_t AB_recover_comp_time = (eff_width * eff_width * eff_height) / (DIM * DIM); 
  uint64_t AB_recover_time = (AB_recover_mem_time + AB_recover_comp_time);
  uint64_t C_recover_mem_time = eff_width * ((eff_height * 32) / min_bw) * 2 + eff_subdiag* ((eff_subdiag * 32) / min_bw) * 2;
  C_recover_mem_time += eff_width * ((eff_height * 32) / DRAM_BITS) + eff_subdiag* ((eff_subdiag * 32) / DRAM_BITS); // DRAM -> L2
  uint64_t C_recover_comp_time = (eff_subdiag * eff_subdiag * eff_width) / (DIM * DIM); 
  uint64_t C_recover_time = (C_recover_mem_time + C_recover_comp_time);

  uint64_t total_expected = AtA_prefetch_time + AtA_compute_time + AtA_scatter_time + AB_recover_time + C_recover_time;
  printf("AB recover: %llu, C recover: %llu, AtA prefetch: %llu, compute: %llu, scatter: %llu, total: %llu\n", AB_recover_time, C_recover_time, AtA_prefetch_time, AtA_compute_time, AtA_scatter_time, total_expected);
  return total_expected;
}

uint64_t predict_cholesky(int supernode_width, int supernode_height, int chol_tile_len, int gemm_tile_len, bool next_memset, int next_node_height){
  int min_bw = MIN(DRAM_BITS, TL_BITS);
  int chol_block_len = ceil_divide_int(chol_tile_len, DIM) * DIM; 
  int gemm_block_len = ceil_divide_int(gemm_tile_len, DIM) * DIM; 
  int num_chol_tile = ceil_divide_int(supernode_width, chol_block_len);
  uint64_t saxpy_time = ((chol_block_len * 32) / min_bw) * 3 * chol_block_len * (chol_block_len * (chol_block_len + 1)) / 2;
  uint64_t div_ax_time = ((chol_block_len * 32) / min_bw) * 2 * chol_block_len + 32 * chol_block_len * 2;
  uint64_t block_chol_time = num_chol_tile * (div_ax_time + saxpy_time);
  uint64_t tri_scale_time = ((chol_block_len * 32) / min_bw) * 2 * chol_block_len+ 32 * chol_block_len * 2;
  int avg_supernode_height = (ceil_divide_int(supernode_height, DIM) * DIM + (ceil_divide_int(supernode_width, DIM) * DIM / 2));
  // average
  uint64_t tri_mult_mem_time = 2 * chol_tile_len * (((avg_supernode_height) * ((chol_block_len * 32) / min_bw)) + (chol_block_len * 32) / min_bw + (avg_supernode_height * 32) / min_bw);
  uint64_t tri_mult_comp_time = chol_tile_len * (chol_block_len * avg_supernode_height * DIM) / (DIM * DIM);
  uint64_t tri_mult_time = tri_mult_mem_time + tri_mult_comp_time;
  uint64_t triangle_time = num_chol_tile * (tri_scale_time + tri_mult_time);
 
  uint64_t C_time = 0;

  for(int i = 0; i < supernode_width; i += chol_tile_len){
    int num_c_row = ceil_divide_int((supernode_height - i), gemm_tile_len);
    int num_c_blk = (num_c_row * num_c_row) / 2 + num_c_row;
    uint64_t C_comp_time = num_c_blk * (gemm_block_len * gemm_block_len * chol_block_len) / (DIM  * DIM);
    uint64_t C_mem_time = num_c_blk * ((chol_block_len * 32) / min_bw * gemm_block_len * 2 + (gemm_block_len * 32) / min_bw * gemm_block_len * 2);
    C_mem_time += num_c_blk * (gemm_block_len * 32) / DRAM_BITS * gemm_block_len; // DRAM -> L2
    C_time += MAX(C_comp_time, C_mem_time) + MIN(C_comp_time, C_mem_time) * 0.2;
  }
 
  uint64_t AB_copy_time = ((supernode_height * 32) / min_bw) * supernode_width;
  uint64_t next_memset_time = 0;
  if(next_memset)
      next_memset_time = (ceil_divide_int(next_node_height, DIM) * DIM) / min_bw * next_node_height;
  uint64_t memcpy_time = AB_copy_time + next_memset_time;
  
  uint64_t total_expected = block_chol_time + triangle_time + MAX(C_time, memcpy_time);
  printf("block cholesky time: %llu, triangle solver time: %llu, syrk time: %llu, memcpy time: %llu, total: %llu\n", block_chol_time, triangle_time, C_time, memcpy_time, total_expected);

  return total_expected;
}

uint64_t predict_node_add(int supernode_height, int supernode_width){
  int min_bw = MIN(DRAM_BITS, TL_BITS);
  int C_dim = supernode_height - supernode_width;
  int num_block = C_dim / 6;
  uint64_t scatter_mem_time = num_block * num_block * ((2 * DIM * 32) / min_bw) * (2 * DIM) * 3;
  //scatter_mem_time *= 2;
  printf("node merge scatter add time: %llu\n", scatter_mem_time);
  return scatter_mem_time;
}

uint64_t predict_backsolve(int width, int height, int backsolve_block_len){
  int min_bw = MIN(DRAM_BITS, TL_BITS);
  int eff_width = ceil_divide_int(width, DIM) * DIM;
  int eff_diag = ceil_divide_int(height - width - 1, DIM) * DIM;
  uint64_t last_row_time = width * ceil_divide_int(32, min_bw) * DIM + 500; // config overhead time
  
  uint64_t gemv_memory_time = DIM * (eff_diag * 32) / min_bw + (eff_width * 32) / min_bw * eff_diag + 2 * (eff_width * 32) / min_bw * DIM;
  gemv_memory_time += (eff_diag * 32) / DRAM_BITS + (eff_width * 32) / DRAM_BITS * eff_diag + (eff_width * 32) / DRAM_BITS;
  uint64_t gemv_comp_time = (DIM * eff_width * eff_diag) / (DIM * DIM);
  uint64_t gemv_time = gemv_comp_time + gemv_memory_time;
  
  uint64_t num_blk = ceil_divide_int(width, backsolve_block_len);
  uint64_t avg_width = ceil_divide_int(width, 2 * DIM) * DIM;
  uint64_t backsolve_scale_time = num_blk * 2 * (backsolve_block_len * ceil_divide_int(32, min_bw)) + 2 * 32 * backsolve_block_len * num_blk;
  uint64_t backsolve_mem_time = num_blk * (DIM * (backsolve_block_len * 32) / min_bw + backsolve_block_len * (avg_width * 32) / min_bw + 2 * DIM * (avg_width * 32) / min_bw);
  uint64_t backsolve_comp_time = num_blk * ((DIM * backsolve_block_len * avg_width) / (DIM * DIM));
  uint64_t backsolve_time = backsolve_scale_time + backsolve_mem_time + backsolve_comp_time;
  backsolve_time *= 2; 
  uint64_t total_time = last_row_time + gemv_time + backsolve_time;
  printf("total backsolve time: %llu, last row: %llu, gemv: %llu, triangle solve: %llu\n", total_time, last_row_time, gemv_time, backsolve_time);
  return total_time;
}

