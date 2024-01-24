// See LICENSE for license details.
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef BAREMETAL
#include <sys/mman.h>
#endif
//#include "include/gemmini_testutils.h"
#include "include/dma.h"

#define CHECK_RESULT 0 // 1

#ifndef BAREMETAL

#define MAT_DIM_I 128
#define MAT_DIM_J 512

#else
#define MAT_DIM_I 32
#define MAT_DIM_J 48
#endif

#define MAT_DIM_I2 56
#define MAT_DIM_J2 64

#define PageSize 4096

#define NUM_TILE 8

#define DIRECT_DRAM 1
#define DIRECT_DRAM2 0

void full_printMatrix(elem_t m[MAT_DIM_I][MAT_DIM_J]) {
  for (size_t i = 0; i < MAT_DIM_I; ++i) {
    for (size_t j = 0; j < MAT_DIM_J; ++j)
      printf("%d ", m[i][j]);
    printf("\n");
  }
}

bool vec_is_equal(elem_t * a, elem_t * b, int len) {
    for (int i = 0; i < len; i++)
        if (a[i] != b[i])
            printf("a: %d, b: %d, index: %d\n", a[i], b[i], i);
            //return false;
    return true;
}

int main() {
#ifndef BAREMETAL
    if (mlockall(MCL_CURRENT | MCL_FUTURE) != 0) {
      perror("mlockall failed");
      exit(1);
    }
#endif

    int channel = 0;
    int channel2 = 1;
    printf("DMA channel: %d\n", channel);
    printf("I: %d, J: %d\n", MAT_DIM_I, MAT_DIM_J);

    dma_flush(0);

    static elem_t A[MAT_DIM_I][MAT_DIM_J] byte_align(DMA_MAX_BYTES) = {0};
    static elem_t B[MAT_DIM_I][MAT_DIM_J] byte_align(DMA_MAX_BYTES) = {0};

    static elem_t A2[MAT_DIM_I2][MAT_DIM_J2] byte_align(DMA_MAX_BYTES) = {0};
    static elem_t B2[MAT_DIM_I2][MAT_DIM_J2] byte_align(DMA_MAX_BYTES) = {0};

    uint64_t A_copy_addr = (BASE_ADDR & ~(PageSize-1));
    uint64_t A_copy_addr2 = ((BASE_ADDR + PageSize) & ~(PageSize-1));
    printf("A copy addr: 0x%08lx\n", A_copy_addr);
    printf("A source addr: 0x%08lx\n", A);
    printf("A2 copy addr: 0x%08lx\n", A_copy_addr2);
    printf("A2 source addr: 0x%08lx\n", A2);

    printf("Init A and B\n");
    for (size_t i = 0; i < MAT_DIM_I; ++i) {
      for (size_t j = 0; j < MAT_DIM_J; ++j) {
        A[i][j] = (rand() % 64) - 32;
        //B[i][j] = (rand() % 8) - 4;
        //gold[i][j] = A[i][j]+B[i][j];
      }
    }
    for (size_t i = 0; i < MAT_DIM_I2; ++i) {
      for (size_t j = 0; j < MAT_DIM_J2; ++j) {
        A2[i][j] = (rand() % 8) - 4;
        //gold[i][j] = A[i][j]+B[i][j];
      }
    }
    printf("configuring DMA\n");
    dma_source_config(channel, DIRECT_DRAM, (elem_t*) A, MAT_DIM_J);
    dma_source_config(channel2, DIRECT_DRAM2, (elem_t*) A2, MAT_DIM_J2);
    dma_dest_config(channel, A_copy_addr, MAT_DIM_J);
    dma_dest_config(channel2, A_copy_addr2, MAT_DIM_J2);

    printf("perform memcpy\n");
    bool granted = false;
    int index = 0;
    int curr_tile = NUM_TILE;
    int tile_row = MAT_DIM_I / NUM_TILE;
    int tile_col = MAT_DIM_J;//MAT_DIM_J / NUM_TILE;
    for(int i = 0; i < NUM_TILE; i++){
      dma_memcpy_tile(channel, granted, i * tile_row * tile_col * sizeof(elem_t), i * tile_row * tile_col * sizeof(elem_t), i, MAT_DIM_I, (MAT_DIM_J) * sizeof(elem_t));
      if(!granted) {
        curr_tile = i;
        break;
      }
    }
    for(int i = curr_tile; i < NUM_TILE; i++){
      granted = false;
      while(!granted) dma_memcpy_tile(channel, granted, i * tile_row * tile_col * sizeof(elem_t), i * tile_row * tile_col * sizeof(elem_t), i, MAT_DIM_I, (MAT_DIM_J) * sizeof(elem_t));
    }
    
    //printf("granted %d, stopped tile: %d\n", granted, curr_tile);
    
    tile_row = MAT_DIM_I / NUM_TILE;
    tile_col = MAT_DIM_J / NUM_TILE;
    for(int i = 0; i < NUM_TILE; i++){
      dma_memcpy_tile(channel2, granted, i * tile_row * tile_col * sizeof(elem_t), i * tile_row * tile_col * sizeof(elem_t), i, MAT_DIM_I2, (MAT_DIM_J2) * sizeof(elem_t));
      if(!granted) {
        curr_tile = i;
        int state = 0;
        dma_probe_state(state, channel);
        printf("channel 1 done: %d\n", state);
        break;
      }
    }
    for(int i = curr_tile; i < NUM_TILE; i++){
      granted = false;
      while(!granted) dma_memcpy_tile(channel2, granted, i * tile_row * tile_col * sizeof(elem_t), i * tile_row * tile_col * sizeof(elem_t), i, MAT_DIM_I2, (MAT_DIM_J2) * sizeof(elem_t));
    }
    
    //tiled_resadd_auto(MAT_DIM_I, MAT_DIM_J, 1, 1, 1, (elem_t*) A_copy_addr, (elem_t*) B, (elem_t*) C, false, WS);
    printf("granted %d, stopped tile: %d \n", granted, curr_tile);
    vec_is_equal(&A[0][0], (elem_t*) A_copy_addr, sizeof(A)/sizeof(elem_t));
    printf("channel 2\n");
    vec_is_equal(&A2[0][0], (elem_t*) A_copy_addr2, sizeof(A2)/sizeof(elem_t));
    //vec_is_equal(&gold[0][0], &C[0][0], sizeof(gold)/sizeof(elem_t));

    exit(0);
}

