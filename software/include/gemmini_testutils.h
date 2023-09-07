// See LICENSE for license details.

#ifndef SRC_MAIN_C_GEMMINI_TESTUTILS_H
#define SRC_MAIN_C_GEMMINI_TESTUTILS_H

#undef abs

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>


#ifdef BAREMETAL
#undef assert
#define assert(expr) \
    if (!(expr)) { \
      printf("Failed assertion: " #expr "\n  " __FILE__ ":%u\n", __LINE__); \
      exit(1); \
    }
#endif

// #define GEMMINI_ASSERTIONS

int rand() {
  static uint32_t x = 777;
  x = x * 1664525 + 1013904223;
  return x >> 24;
}


#ifdef ELEM_T_IS_FLOAT
double rand_double() {
    double a = (double)(rand() % 128) / (double)(1 + (rand() % 64));
    double b = (double)(rand() % 128) / (double)(1 + (rand() % 64));
    return a - b;
}
#endif


// This is a GNU extension known as statment expressions
#define MAT_IS_EQUAL(dim_i, dim_j, x, y) \
    ({int result = 1; \
      for (size_t i = 0; i < dim_i; i++) \
        for (size_t j = 0; j < dim_j; ++j) { \
          if (x[i][j] != y[i][j]) { \
            result = 0; \
            break; \
          } \
        } \
      result;})

static uint64_t read_cycles() {
    uint64_t cycles;
    asm volatile ("rdcycle %0" : "=r" (cycles));
    return cycles;

    // const uint32_t * mtime = (uint32_t *)(33554432 + 0xbff8);
    // const uint32_t * mtime = (uint32_t *)(33554432 + 0xbffc);
    // return *mtime;
}

#undef abs

#endif  // SRC_MAIN_C_GEMMINI_TESTUTILS_H
