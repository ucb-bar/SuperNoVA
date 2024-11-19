#define XCUSTOM_MATADD 2
#define k_LOOP_PACK 13

#define matadd_extended2_config_st(stride, acc_act, acc_scale, pool_stride, pool_size, pool_out_dim, porows, pocols, orows, ocols, upad, lpad) \
  ROCC_INSTRUCTION_RS1_RS2(XCUSTOM_MATADD, ((uint64_t)(ocols) << 56) | ((uint64_t)(orows) << 48) | ((uint64_t)(pocols) << 40) | ((uint64_t)(porows) << 32) | ((uint64_t)(pool_out_dim) << 24) | ((uint64_t)(lpad) << 10) | ((uint64_t)(upad) << 8) | ((uint64_t)(pool_size) << 6) | ((uint64_t)(pool_stride) << 4) | ((uint64_t)(acc_act) << 2) | CONFIG_ST, ((uint64_t)acc_scale_t_to_acc_scale_t_bits((acc_scale_t)acc_scale) << 32) | ((uint32_t)stride), k_CONFIG)

#define matadd_extended_config_st(stride, acc_act, acc_scale) \
    matadd_extended2_config_st(stride, acc_act, acc_scale, 0, 0, 0, 0, 0, 0, 0, 0, 0)

#define matadd_extended5_config_ld(stride, scale, shrunk, block_mvin_stride, pixel_repeats, id) \
  ROCC_INSTRUCTION_RS1_RS2(XCUSTOM_MATADD, ((uint64_t)(scale_t_to_scale_t_bits(scale)) << 32) | ((uint64_t)(block_mvin_stride) << 16) | ((uint64_t)(pixel_repeats) << 8) | ((id) << 3) | ((shrunk) << 2) | CONFIG_LD, stride, k_CONFIG)

#define matadd_extended4_config_ld(stride, scale, shrunk, block_mvin_stride, id) \
  matadd_extended5_config_ld(stride, scale, shrunk, block_mvin_stride, 1, id) \

#define matadd_extended3_config_ld(stride, scale, shrunk, id) \
  matadd_extended4_config_ld(stride, scale, shrunk, DIM, id)


// weight-stationary matmul loop
#define matadd_loop_ws(I, J, pad_I, pad_J, A, B, C, A_stride, B_stride, C_stride, num_blk) \
  { \
    ROCC_INSTRUCTION_RS1_RS2(XCUSTOM_MATADD, ((uint64_t)(num_blk) << 32) | ((uint64_t)(pad_I) << 16) | (uint64_t)(pad_J), ((uint64_t)(I) << 16) | (uint64_t)(J), k_LOOP_WS_CONFIG_BOUNDS) \
    ROCC_INSTRUCTION_RS1_RS2(XCUSTOM_MATADD, A, B, k_LOOP_WS_CONFIG_ADDRS_AB) \
    ROCC_INSTRUCTION_RS1_RS2(XCUSTOM_MATADD, C_stride, C, k_LOOP_WS_CONFIG_ADDRS_DC) \
    ROCC_INSTRUCTION_RS1_RS2(XCUSTOM_MATADD, A_stride, B_stride, k_LOOP_WS_CONFIG_STRIDES_AB) \
  }


#define matadd_loop_packed(A0, A1, A2, A3, B0, B1, B2, B3, tile0, tile1, tile2, tile3, pad0, pad1, pad2, pad3) \
  { \
    ROCC_INSTRUCTION_RS1_RS2(XCUSTOM_MATADD, ((uint64_t)(pad3) << 60) | ((uint64_t)(pad2) << 56) | ((uint64_t)(pad1) << 52) | ((uint64_t) (pad0) << 48) | ((uint64_t) (B0) << 36) | ((uint64_t) (B1) << 24) | ((uint64_t) (B2) << 12) | ((uint64_t) (B3)), ((uint64_t)(tile3) << 59) | ((uint64_t)(tile2) << 54) | ((uint64_t)(tile1) << 49) | ((uint64_t) (tile0) << 44) | ((uint64_t) (A0) << 33) | ((uint64_t) (A1) << 22) | ((uint64_t) (A2) << 11) | ((uint64_t) (A3)), k_LOOP_PACK) \
  }
// flush
#define matadd_flush(skip) \
  ROCC_INSTRUCTION_RS1_RS2(XCUSTOM_MATADD, skip, 0, k_FLUSH)



static void sp_tiled_matadd(const size_t I, const size_t J,
        //const scale_t A_scale,
        //const scale_t B_scale,
        const elem_t * A, const elem_t * B, elem_t * C,
        size_t A_row_stride, size_t B_row_stride, size_t C_row_stride,
        bool relu) {

    int pad_I = ((I%DIM) == 0) ? 0 : DIM - (I % DIM);
    int pad_J = ((J%DIM) == 0) ? 0 : DIM - (J % DIM);
    int tile_I = (I%DIM == 0) ? (int)(I/DIM) : (int)(I/DIM) + 1;
    int tile_J = (J%DIM == 0) ? (int)(J/DIM) : (int)(J/DIM) + 1;
    //printf("pad I: %d, pad_J: %d, tile_I: %d, tile_J: %d\n", pad_I, pad_J, tile_I, tile_J);
    
    matadd_loop_ws(tile_I, tile_J, pad_I, pad_J, A, B, C, A_row_stride, B_row_stride, C_row_stride, 1);
    /*
    // Use the new mvin2 command to overlap mvin A, mvin B, and mvout C

    size_t blocks = (J/DIM + (J % DIM != 0));
    if (blocks > MAX_BLOCK_LEN) blocks = MAX_BLOCK_LEN;

    const uint32_t D_sp_addr_start = 1 << (ADDR_LEN-1);
    const uint32_t C_sp_addr_start = 3 << (ADDR_LEN-2);

    const size_t rounded_up_J = (J / DIM + (J % DIM != 0)) * DIM;

    // Mvin A
    // printf("Mving A\n");
    for (size_t i = 0; i < I; i += DIM) {
        for (size_t j = 0; j < J; j += blocks * DIM) {
            const size_t cols = j + blocks*DIM <= J ? blocks*DIM : J-j;
            const size_t rows = i + DIM <= I ? DIM : I-i;

            const elem_t * const A_dram_addr = A + i * A_row_stride + j;
            const uint32_t A_sp_addr = D_sp_addr_start + i * (rounded_up_J/DIM) + j;

            matadd_extended_mvin(A_dram_addr, A_sp_addr, cols, rows);
        }
    }

    // Mvin B
     printf("Mving B\n");
    for (size_t i = 0; i < I; i += DIM) {
        for (size_t j = 0; j < J; j += blocks * DIM) {
            const size_t cols = j + blocks*DIM <= J ? blocks*DIM : J-j;
            const size_t rows = i + DIM <= I ? DIM : I-i;

            const elem_t * const B_dram_addr = B + i * B_row_stride + j;
            const uint32_t B_sp_addr = C_sp_addr_start + i * (rounded_up_J/DIM) + j;
            matadd_extended_mvin2(B_dram_addr, B_sp_addr, cols, rows);
        }
    }

    // Mvout C from accumulator
    // printf("Mvout C from accumulator\n");
    for (size_t i = 0; i < I; i += DIM) {
        for (size_t j = 0; j < J; j += blocks * DIM) {
            const size_t cols = j + blocks*DIM <= J ? blocks*DIM : J-j;
            const size_t rows = i + DIM <= I ? DIM : I-i;

            elem_t * const C_dram_addr = C + i * C_row_stride + j;
            const uint32_t C_sp_addr = D_sp_addr_start + i * (rounded_up_J/DIM) + j;
            matadd_extended_mvout(C_dram_addr, C_sp_addr, cols, rows);
        }
    }
    */
}

static void tiled_unpacked_matadd(const size_t I, const size_t J,
        const size_t A_stride, const size_t B_stride, const size_t C_stride,
        //const size_t tile_I, const size_t tile_J,
        const scale_t A_scale,
        const scale_t B_scale,
        const acc_scale_t C_scale,
        elem_t * A,
        elem_t * B,
        elem_t * C,
        bool relu, bool config){
        //enum tiled_matmul_type_t matadd_type) {

    if(config){
      matadd_extended_config_st(C_stride * sizeof(elem_t), relu ? RELU : NO_ACTIVATION, C_scale);
      //matadd_config_ex(WS, 0, 0);

      matadd_extended4_config_ld(A_stride * sizeof(elem_t), A_scale, true, DIM, 0);
      matadd_extended4_config_ld(B_stride * sizeof(elem_t), B_scale, true, DIM, 1);
      matadd_extended3_config_ld(0, 1, false, 2);
    }
    int pad_I = ((I%DIM) == 0) ? 0 : DIM - (I % DIM);
    int tile_I = (I%DIM == 0) ? (int)(I/DIM) : (int)(I/DIM) + 1;

    int tile_J = (J%DIM == 0) ? (int)(J/DIM) : (int)(J/DIM) + 1;
    int pad_J = ((J%DIM) == 0) ? 0 : DIM - (J % DIM);
    
    matadd_loop_ws(tile_I, tile_J, pad_I, pad_J, A, B, C, A_stride, B_stride, C_stride, 1);
    
    //sp_tiled_matadd(tile_I, tile_J, //A_scale, B_scale,
    //      a, b, c,
    //      A_stride, B_stride, C_stride, relu);
#if ReRoCC == false
    gemmini_fence();
#endif
}

static void tiled_packed_matadd(const size_t I, int* J,
        const size_t A_stride, const size_t B_stride, const size_t C_stride,
        //const size_t tile_I, const size_t tile_J,
        const scale_t A_scale,
        const scale_t B_scale,
        const acc_scale_t C_scale,
        elem_t * A,
        elem_t * B,
        elem_t * C,
        int* A_blk, int* B_blk, //int* C_blk, // assume B = C
        int num_J, bool relu, bool config){
        //enum tiled_matmul_type_t matadd_type) {

    if(config){
      matadd_extended_config_st(C_stride * sizeof(elem_t), relu ? RELU : NO_ACTIVATION, C_scale);
      //matadd_config_ex(WS, 0, 0);

      matadd_extended4_config_ld(A_stride * sizeof(elem_t), A_scale, true, DIM, 0);
      matadd_extended4_config_ld(B_stride * sizeof(elem_t), B_scale, true, DIM, 1);
      matadd_extended3_config_ld(0, 1, false, 2);
    }
    int pad_I = ((I%DIM) == 0) ? 0 : DIM - (I % DIM);
    int tile_I = (I%DIM == 0) ? (int)(I/DIM) : (int)(I/DIM) + 1;

    if(num_J > 1){
      int tile_J[4] = {0};
      int pad_J[4] = {0};
      int A_offset[4] = {0};
      int B_offset[4] = {0};
      int A_blk_base = *A_blk;
      int B_blk_base = *B_blk;
      //int C_offset[4] = {0};
      for(int jj = 0; jj < num_J; jj+=4){
        int num_blk = jj+4 > num_J ? num_J - jj : 4;
        float* A_addr = (float*) A + *(A_blk) - A_blk_base;
        float* B_addr = (float*) B + *(B_blk) - B_blk_base;
        float* C_addr = (float*) C + *(B_blk) - B_blk_base;
        //printf("A: %llu, A_addr: %llu, offset: %llu\n", A, A_addr, *(A_blk+jj)-*A_blk);
        for(int j = 0; j < num_blk; j++){
          int dim_J = *(J+jj+j);
          tile_J[j] = (dim_J%DIM == 0) ? (int)(dim_J/DIM) : (int)(dim_J/DIM) + 1;
          pad_J[j] = ((dim_J%DIM) == 0) ? 0 : DIM - (dim_J % DIM);
          A_offset[j] = *(A_blk + j) - *A_blk;
          B_offset[j] = *(B_blk + j) - *B_blk;
          //C_offset[i] = *(C_blk + j) - *C_blk;
        }
      
        //printf("num_block: %d, dim_I: %d, tile_I: %d, pad_I: %d\n", num_blk, I, tile_I, pad_I);
        //printf("A_offset: %d, %d, %d, %d, B_offset: %d, %d, %d, %d\n", A_offset[0], A_offset[1], A_offset[2], A_offset[3], B_offset[0], B_offset[1], B_offset[2], B_offset[3]);
        //printf("tile_J: %d, %d, %d, %d, pad_J: %d, %d, %d, %d\n", tile_J[0], tile_J[1], tile_J[2], tile_J[3], pad_J[0], pad_J[1], pad_J[2], pad_J[3]);
        matadd_loop_packed(A_offset[0], A_offset[1], A_offset[2], A_offset[3], B_offset[0], B_offset[1], B_offset[2], B_offset[3], tile_J[0], tile_J[1], tile_J[2], tile_J[3], pad_J[0], pad_J[1], pad_J[2], pad_J[3]);
        matadd_loop_ws(tile_I, 0, pad_I, 0, A_addr, B_addr, C_addr, A_stride, B_stride, C_stride, num_blk);
        //for(int i = 0; i < num_J; i++)
        //   matadd_loop_ws(tile_I, tile_J[i], pad_I, pad_J[i], A+A_offset[i], B+B_offset[i], C+B_offset[i], A_stride, B_stride, C_stride, 1);
        A_blk += num_blk;
        B_blk += num_blk;
      }
    }
    else {
      int dim_J = *J;
      int tile_J = (dim_J%DIM == 0) ? (int)(dim_J/DIM) : (int)(dim_J/DIM) + 1;
      int pad_J = ((dim_J%DIM) == 0) ? 0 : DIM - (dim_J % DIM);
      
      matadd_loop_ws(tile_I, tile_J, pad_I, pad_J, A, B, C, A_stride, B_stride, C_stride, 1);
    
      //sp_tiled_matadd(tile_I, tile_J, //A_scale, B_scale,
      //      a, b, c,
      //      A_stride, B_stride, C_stride, relu);
    }
    /*
    for (size_t i = 0; i < I; i += tile_I) {
        for (size_t j = 0; j < J; j += tile_J) {
            const size_t I_tile = i + tile_I <= I ? tile_I : I - i;
            const size_t J_tile = j + tile_J <= J ? tile_J : J - j;

            const elem_t * a = A + i * A_stride + j;
            const elem_t * b = B != NULL ? B + i * B_stride + j : NULL;
            elem_t * c = C + i * C_stride + j;

            sp_tiled_matadd(I_tile, J_tile,
                    //A_scale, B_scale, 
                    a, b, c,
                    A_stride, B_stride, C_stride,
                    relu);
        }
    }
    */

#if ReRoCC == false
    gemmini_fence();
#endif
}
// Compute MVIN_SCALE(A, A_scale) + MVIN_SCALE(B, B_scale) = C
static void tiled_matadd(const size_t I, const size_t J,
        const size_t A_stride, const size_t B_stride, const size_t C_stride,
        const size_t tile_I, const size_t tile_J,
        const scale_t A_scale,
        const scale_t B_scale,
        const acc_scale_t C_scale,
        const elem_t * A,
        const elem_t * B,
        elem_t * C,
        bool relu,
        enum tiled_matmul_type_t matadd_type) {

    matadd_extended_config_st(C_stride * sizeof(elem_t), relu ? RELU : NO_ACTIVATION, C_scale);
    //matadd_config_ex(WS, 0, 0);

    matadd_extended4_config_ld(A_stride * sizeof(elem_t), A_scale, true, DIM, 0);
    matadd_extended4_config_ld(B_stride * sizeof(elem_t), B_scale, true, DIM, 1);
    matadd_extended3_config_ld(0, 1, false, 2);
    
    for (size_t i = 0; i < I; i += tile_I) {
        for (size_t j = 0; j < J; j += tile_J) {
            const size_t I_tile = i + tile_I <= I ? tile_I : I - i;
            const size_t J_tile = j + tile_J <= J ? tile_J : J - j;

            const elem_t * a = A + i * A_stride + j;
            const elem_t * b = B != NULL ? B + i * B_stride + j : NULL;
            elem_t * c = C + i * C_stride + j;

            sp_tiled_matadd(I_tile, J_tile,
                    //A_scale, B_scale, 
                    a, b, c,
                    A_stride, B_stride, C_stride,
                    relu);
        }
    }

#if ReRoCC == false
    gemmini_fence();
#endif
}

// Compute (A >> A_shift) + B = C
// specify stride
static void tiled_matadd_stride_auto(const size_t I, const size_t J,
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
        enum tiled_matmul_type_t matadd_type) {
/*
    if (matadd_type == CPU) {
        resadd_cpu(I, J, stride,
            A_scale, B_scale, C_scale, A, B, C,
            relu);
        return;
    }
*/
    size_t tile_I = I, tile_J = J;

    // size_t total_spad_rows = 2 * (tile_I / DIM + (tile_I % DIM != 0))*DIM * (tile_J / DIM + (tile_J % DIM != 0));
    size_t total_acc_rows = (tile_I / DIM + (tile_I % DIM != 0))*DIM * (tile_J / DIM + (tile_J % DIM != 0));

    // TODO this is a very inefficient way of doing this...
    while (total_acc_rows > ACC_ROWS / 2) {
        //if(tile_J > MAX_BLOCK_LEN * DIM)
        //    tile_J = MAX_BLOCK_LEN * DIM;
        //else 
        if (tile_I >= tile_J || tile_J <= DIM)
            tile_I /= 2;
        else
            tile_J -= DIM;

        total_acc_rows = (tile_I / DIM + (tile_I % DIM != 0))*DIM * (tile_J / DIM + (tile_J % DIM != 0));
    }

    //printf("tile_I: %llu\n", tile_I);
    //printf("tile_J: %llu\n", tile_J);

    if (matadd_type == WS) {
      tiled_matadd(I, J, A_stride, B_stride, C_stride, tile_I, tile_J,
            A_scale, B_scale, C_scale, A, B, C,
            relu, matadd_type);
    }
    else {
      printf("Unsupported type\n");
      exit(1);
    }
}

static void tiled_matadd_auto(const size_t I, const size_t J,
        const scale_t A_scale,
        const scale_t B_scale,
        const acc_scale_t C_scale,
        const elem_t * A,
        const elem_t * B,
        elem_t * C,
        bool relu,
        enum tiled_matmul_type_t matadd_type) {
    tiled_matadd_stride_auto(I, J, 
        A_scale, B_scale, C_scale,
        J, J, J,
        A, B, C,
        relu, matadd_type);
}

