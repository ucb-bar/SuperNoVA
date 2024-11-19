
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
#define MAX_DENSE_BLK_SIZE 48//36//32
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


//const int CHOL_BLOCK_SIZE = 4;
//const int TRSM_BLOCK_SIZE = 4;
//const int GEMM_BLOCK_SIZE = 4;
//const int MAX_DENSE_BLK_SIZE = 8;

static inline int min(int A, int B) { return A > B? B : A; }

// Perform C += A_scale_factor * A^(transpose_A * T) * B_scale_factor * B^(transpose_B * T)
// Assume A, B, C are stored in row-major order
void cpu_matmul(
  size_t dim_I, size_t dim_J, size_t dim_K, 
  const elem_t* A, const elem_t* B, elem_t* C,
  size_t stride_A, size_t stride_B, size_t stride_C,
  scale_t A_scale_factor, scale_t B_scale_factor,
  bool transpose_A, bool transpose_B) {

  tiled_matmul_auto(dim_I, dim_J, dim_K,
                    A, B, C, C,
                    stride_A, stride_B, stride_C, stride_C,
                    A_scale_factor, B_scale_factor, 1,
                    0, 1, 0,
                    false,
                    transpose_A, transpose_B,
                    false, false,
                    0,
                    CPU);

}

// Perform y = A_scale_factor A * x_scale_factor x + z_scale_factor z
// A is of dim_I x dim_K
// x is a vector of dim_K x 1, y, z are vectors of dim_I x 1
void gemv2(
  size_t dim_I, size_t dim_K,
  const elem_t* A, const elem_t* x, 
  const elem_t* z, elem_t* y,
  size_t stride_A,
  scale_t A_scale_factor, scale_t x_scale_factor, scale_t z_scale_factor,
  bool transpose_A, bool transpose_x) {

  tiled_matmul_auto(dim_I, 1, dim_K,
                    A, x, z, y,
                    stride_A, 1, 1, 1,
                    A_scale_factor, x_scale_factor, z_scale_factor,
                    0, 1, 0,
                    false,
                    transpose_A, transpose_x,
                    false, false,
                    0,
                    CPU);
}

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

void ax(float a, float* x, int h) {
  for(int i = 0; i < h; i++) {
    x[i] *= a;
  }
}

void div_ax(float a, float* x, int h) {
  for(int i = 0; i < h; i++) {
    if(a == 0) a = 1;
    x[i] /= a;
  }
}

void saxpy(float a, float* x, float* y, int h) {
  for(int i = 0; i < h; i++) {
    y[i] += a * x[i];
  }
}

// Do C += scale_factor_B * BB^T
// B is dim_I x dim_K, C is dim_I x dim_I
// Equivalent to the following call
// matmul(dim_I, dim_I, dim_K,
//      B, B, C, 
//      stride_B, stride_B, stride_C,
//      scale_factor_B, 1,
//      true, false);
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

        cpu_matmul(hhJ, hhI, ww,
               B_JK, B_IK, C_IJ,
               stride_B, stride_B, stride_C,
               scale_factor_B, 1,
               true, false);

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

        cpu_matmul(hhJ, hhI, ww,
               B_JK, B_IK, C_IJ,
               stride_B, stride_B, stride_C,
               scale_factor_B, 1,
               true, false);

        B_IK += GEMM_BLOCK_SIZE;
        C_IJ += GEMM_BLOCK_SIZE;
      }
      B_JK += GEMM_BLOCK_SIZE;
      C_0J += GEMM_BLOCK_SIZE * stride_C;
    }
    B_0K += GEMM_BLOCK_SIZE * stride_B;
  }
}

// Do partial cholesky factorization with more vector type operations
// AB is column major
void partial_factorization1(float* AB, int w, int h) {
  float* AB_orig = AB;

  int hh = h;
  for(int j = 0; j < w; j++) {
    hh--;
    if(AB[0] <= 0) AB[0] = 1;
    //if(AB[0] <= 0) {
    //    printf("Not positive definite!\n");
    //    exit(1);
    //}
    float sqrtdiag = sqrt(AB[0]);
    AB[0] = sqrtdiag;
    float scale = 1 / sqrtdiag;
    div_ax(sqrtdiag, AB + 1, hh);
    // ax(scale, AB + 1, hh);
    float* AB_k = AB;
    int hhh = hh;
    for(int k = 1; k < w - j; k++) {
      AB_k += h + 1;
      saxpy(-AB[k], AB + k, AB_k, hhh);
      hhh--;
    }
    AB += h + 1;
  }

  // Do C - BBT
  // We want to get C^T = B^T^T B^T, we have column major B, which is row major B^T
  int dim_I = h - w, dim_J = dim_I, dim_K = w;
  float* B = AB_orig + w;
  float* C = AB_orig + w * (h + 1);
  int stride_B = h, stride_C = h;
  float scale_factor_A = -1, scale_factor_B = 1;
  bool transpose_A = true, transpose_B = false;

  cpu_matmul(dim_I, dim_J, dim_K,
       B, B, C, 
       stride_B, stride_B, stride_C,
       scale_factor_A, scale_factor_B,
       transpose_A, transpose_B);

}

// Takes a dense square matrix A with size dim x dim, 
// modify it to be chol(A). 
// A is column major
void dense_block_cholesky(float* A, int dim, int stride) {
  int hh = dim;                       // subdiagonal height of current column
  for(int j = 0; j < dim; j++) {
    hh--;
    if(A[0] <= 0) A[0] = 1;
    //    printf("Non positive definite!\n");
    //    exit(1);
    //}
    float sqrtdiag = sqrt(A[0]);
    A[0] = sqrtdiag;
    div_ax(sqrtdiag, A + 1, hh);
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
void dense_block_triangle_solve(float* L, float* B, 
                                int w, int h,
                                int strideL, int strideB) {
  int hh = w;                         // subdiagonal height of current column of L
  for(int j = 0; j < w; j++) {
    hh--;
    div_ax(L[0], B, h);
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
void dense_block_triangle_solve2(float* L, float* B, 
                                 int w, int h,
                                 int strideL, int strideB) {
  for(int j = 0; j < w; j++) {
    div_ax(L[0], B, h);
    float* B_k = B;

    int dim_I = h, dim_J = w - 1 - j, dim_K = 1;
    float* gemmA = B;
    float* gemmB = L + 1;
    B += strideB;
    float* gemmC = B;
    int stride_A = strideB, stride_B = strideL, stride_C = strideB;
    float scale_factor_A = -1, scale_factor_B = 1;
    bool transpose_A = true, transpose_B = false;

    if(dim_J > 0) {
      cpu_matmul(dim_J, dim_I, dim_K,
          gemmB, gemmA, gemmC,
          stride_B, stride_A, stride_C,
          scale_factor_A, scale_factor_B,
          transpose_A, transpose_B);
    }

    // matmul(dim_I, dim_J, dim_K,
    //      B, B, C, 
    //      stride_B, stride_B, stride_C,
    //      scale_factor_A, scale_factor_B,
    //      transpose_A, transpose_B);

    // for(int k = 1; k < w - j; k++) {
    //   B_k += strideB;
    //   saxpy(-L[k], B, B_k, h);
    // }

    L += strideL + 1;
  }
}

// Solve L.T x = B in place, overwriting B with the answer
// L is size w x w column major, B is size w x h column major
// h is typically 1 in our use case
void dense_block_triangle_solve_tranpose_vector(float* L, float* B, 
                                                int w, /*int h = 1,*/
                                                int strideL/*, int strideB*/) {
    L = L + (w - 1) * (strideL + 1);
    for(int j = w - 1; j >= 0; j--) {
	if(L[0] == 0) L[0] = 1;
        B[j] = B[j] / L[0];

        float* Li = L - strideL;
        for(int i = j - 1; i >= 0; i--) {
            B[i] -= *Li * B[j];
            Li -= strideL;
        }

        L -= (strideL + 1);
    }
}

// Do partial cholesky factorization by first doing as dense cholesky on the diagonal block
// Then doing triangle solve
void partial_factorization2(float* AB, int w, int h) {

  int hh = h;   // hh is the height of the current block column

  float* AB_JJ = AB;
  // J is the row/col index of the diagonal block
  // I is the row index of the subdiagonal block
  int J;
  int I;
  for(J = 0; J < w; J += CHOL_BLOCK_SIZE) {
    // TODO: Make ww fixed and use cleanup iterations
    int ww = min(w - J, CHOL_BLOCK_SIZE); // ww is the panel width.
    dense_block_cholesky(AB_JJ, ww, h);
    float* AB_IJ = AB_JJ + ww;
    for(I = J + ww; I < h; I += TRSM_BLOCK_SIZE) {
      // TODO: Make hh fixed and use cleanup iterations
      int hh = min(h - I, TRSM_BLOCK_SIZE); // hh is the block height
      dense_block_triangle_solve(AB_JJ, AB_IJ, 
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

    blocked_syrk(dim_I, dim_K,
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

// Splitting out LC = C - LB LB^T computation for profiling
void partial_factorization3(float* AB, int w, int h) {

  int hh = h;   // hh is the height of the current block column

  float* AB_JJ = AB;
  // J is the row/col index of the diagonal block
  // I is the row index of the subdiagonal block
  int J;
  int I;

  // This is interleaved [LA; LB] computation
  for(J = 0; J < w; J += CHOL_BLOCK_SIZE) {
    // TODO: Make ww fixed and use cleanup iterations
    int ww = min(w - J, CHOL_BLOCK_SIZE); // ww is the panel width.
    dense_block_cholesky(AB_JJ, ww, h);
    float* AB_IJ = AB_JJ + ww;

    for(I = J + ww; I < h; I += TRSM_BLOCK_SIZE) {
      // TODO: Make hh fixed and use cleanup iterations
      int hh = min(h - I, TRSM_BLOCK_SIZE); // hh is the block height
      dense_block_triangle_solve(AB_JJ, AB_IJ, 
                                 ww, 
                                 hh, 
                                 h, h);
      AB_IJ += TRSM_BLOCK_SIZE;
    }

    int dim_I = h - J - ww, dim_J = dim_I, dim_K = ww, max_J = w - J - ww;
    float* B = AB_JJ + ww;
    float* C = AB_JJ + ww * (h + 1);
    int stride_B = h, stride_C = h;
    float scale_factor_A = -1, scale_factor_B = 1;
    bool transpose_A = true, transpose_B = false;

    truncated_blocked_syrk(dim_I, dim_K, max_J,
                 B, C,
                 stride_B, stride_C,
                 scale_factor_A);

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

  blocked_syrk(dim_I, dim_K,
               B, C,
               stride_B, stride_C,
               scale_factor_A);
}

// Splitting out LC = C - LB LB^T computation for profiling
void partial_factorization4(float* AB, int w, int h, int node) {

  int hh = h;   // hh is the height of the current block column

  float* AB_JJ = AB;
  // J is the row/col index of the diagonal block
  // I is the row index of the subdiagonal block
  int J;
  int I;

  uint64_t start = 0, end = 0;

  // This is interleaved [LA; LB] computation
  for(J = 0; J < w; J += CHOL_BLOCK_SIZE) {
    // TODO: Make ww fixed and use cleanup iterations
    int ww = min(w - J, CHOL_BLOCK_SIZE); // ww is the panel width.
    start = read_cycles();
    dense_block_cholesky(AB_JJ, ww, h);
    end = read_cycles();
    dense_block_chol_time[node] += end - start;
    float* AB_IJ = AB_JJ + ww;

    start = read_cycles();
    for(I = J + ww; I < h; I += TRSM_BLOCK_SIZE) {
      // TODO: Make hh fixed and use cleanup iterations
      int hh = min(h - I, TRSM_BLOCK_SIZE); // hh is the block height
      dense_block_triangle_solve2(AB_JJ, AB_IJ, 
                                  ww, 
                                  hh, 
                                  h, h);
      AB_IJ += TRSM_BLOCK_SIZE;
    }
    end = read_cycles();
    triangular_time[node] += end - start;

    int dim_I = h - J - ww, dim_J = dim_I, dim_K = ww, max_J = w - J - ww;
    float* B = AB_JJ + ww;
    float* C = AB_JJ + ww * (h + 1);
    int stride_B = h, stride_C = h;
    float scale_factor_A = -1, scale_factor_B = 1;
    bool transpose_A = true, transpose_B = false;

    start = read_cycles();
    truncated_blocked_syrk(dim_I, dim_K, max_J,
                 B, C,
                 stride_B, stride_C,
                 scale_factor_A);

    end = read_cycles();
    syrk_time[node] += end - start;

    AB_JJ += CHOL_BLOCK_SIZE * (h + 1);
    hh -= CHOL_BLOCK_SIZE;
  }

  if(h - w > 0) {
      // This is LC = C - LB LB^T computation
      int dim_I = h - w, dim_J = dim_I, dim_K = w;
      float* B = AB + w;
      float* C = AB + w * (h + 1);
      int stride_B = h, stride_C = h;
      float scale_factor_A = -1, scale_factor_B = 1;
      bool transpose_A = true, transpose_B = false;

      start = read_cycles();
      blocked_syrk(dim_I, dim_K,
                   B, C,
                   stride_B, stride_C,
                   scale_factor_A);
      end = read_cycles();
      syrk_time[node] += end - start;
  }
}

// Seah's impl of partial_factorization4
void partial_factorization5(float* AB, int w, int h) {

  int hh = h;   // hh is the height of the current block column

  float* AB_JJ = AB;
  // J is the row/col index of the diagonal block
  // I is the row index of the subdiagonal block
  int J;
  int I;

  uint64_t A_B_start = 0, A_B_end = 0, A_B_mid = 0;
  uint64_t total_panel_chol = 0, total_triangular = 0;

  // This is interleaved [LA; LB] computation
  for(J = 0; J < w; J += CHOL_BLOCK_SIZE) {
    // TODO: Make ww fixed and use cleanup iterations
    int ww = min(w - J, CHOL_BLOCK_SIZE); // ww is the panel width.

    dense_block_cholesky(AB_JJ, ww, h);
    float* AB_IJ = AB_JJ + ww;
    for(I = J + ww; I < h; I += TRSM_BLOCK_SIZE) {
      // TODO: Make hh fixed and use cleanup iterations
      int hh = min(h - I, TRSM_BLOCK_SIZE); // hh is the block height
      dense_block_triangle_solve2(AB_JJ, AB_IJ, 
                                  ww, 
                                  hh, 
                                  h, h);
      AB_IJ += TRSM_BLOCK_SIZE;
    }
    int dim_I = h - J - ww, dim_J = dim_I, dim_K = ww, max_J = w - J - ww;
    float* B = AB_JJ + ww;
    float* C = AB_JJ + ww * (h + 1);
    int stride_B = h, stride_C = h;
    float scale_factor_A = -1, scale_factor_B = 1;
    bool transpose_A = true, transpose_B = false;

    truncated_blocked_syrk(dim_I, dim_K, max_J,
                 B, C,
                 stride_B, stride_C,
                 scale_factor_A);

    total_panel_chol += (A_B_mid - A_B_start);
    total_triangular += (A_B_end - A_B_mid);
    AB_JJ += CHOL_BLOCK_SIZE * (h + 1);
    hh -= CHOL_BLOCK_SIZE;
  }
  printf("A_B cholesky cycles: %llu\n", total_panel_chol);
  printf("A_B triangle solve cycles: %llu\n", total_triangular);

  // This is LC = C - LB LB^T computation
  int dim_I = h - w, dim_J = dim_I, dim_K = w;
  float* B = AB + w;
  float* C = AB + w * (h + 1);
  int stride_B = h, stride_C = h;
  float scale_factor_A = -1, scale_factor_B = 1;
  bool transpose_A = true, transpose_B = false;

  uint64_t C_start = 0, C_end = 0;
#if GEMM_BLOCKED == true
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
          CPU);
#endif
  printf("C cycles: %llu\n", C_end - C_start);
}

// Partial factorization but don't do LC = C - LB LB^T
void partial_factorization6(float* AB, int w, int h) {

  int hh = h;   // hh is the height of the current block column

  float* AB_JJ = AB;
  // J is the row/col index of the diagonal block
  // I is the row index of the subdiagonal block
  int J;
  int I;

  // This is interleaved [LA; LB] computation
  for(J = 0; J < w; J += CHOL_BLOCK_SIZE) {
    // TODO: Make ww fixed and use cleanup iterations
    int ww = min(w - J, CHOL_BLOCK_SIZE); // ww is the panel width.
    dense_block_cholesky(AB_JJ, ww, h);
    float* AB_IJ = AB_JJ + ww;

    for(I = J + ww; I < h; I += TRSM_BLOCK_SIZE) {
      // TODO: Make hh fixed and use cleanup iterations
      int hh = min(h - I, TRSM_BLOCK_SIZE); // hh is the block height
      dense_block_triangle_solve2(AB_JJ, AB_IJ, 
                                  ww, 
                                  hh, 
                                  h, h);
      AB_IJ += TRSM_BLOCK_SIZE;
    }

    int dim_I = h - J - ww, dim_J = dim_I, dim_K = ww, max_J = w - J - ww;
    float* B = AB_JJ + ww;
    float* C = AB_JJ + ww * (h + 1);
    int stride_B = h, stride_C = h;
    float scale_factor_A = -1, scale_factor_B = 1;
    bool transpose_A = true, transpose_B = false;

    truncated_blocked_syrk(dim_I, dim_K, max_J,
                 B, C,
                 stride_B, stride_C,
                 scale_factor_A);

    AB_JJ += CHOL_BLOCK_SIZE * (h + 1);
    hh -= CHOL_BLOCK_SIZE;
  }
}

// L is a factorized supernode of height x width
// x is a dense vector
// Compute the part of x corresponding to the columns of the supernode
void partial_backsolve(float* L, int w, int h, int stride, int* ridx,
                       float* x) {
    int subdiag_h = h - w - 1;  // Don't count last row

    // Copy last row to x
    float* L_last_row = L + h - 1;
    float* x1 = x + ridx[0];
    for(int i = 0; i < w; i++) {
        x1[i] = *L_last_row;
        L_last_row += stride;
    }

    // printf("x1 = \n");
    // print_col_major(x1, w, 1, 1);

    if(subdiag_h > 0) {

        // Gather relevant x
        float* x2 = (float*) my_malloc(subdiag_h * sizeof(float));

        for(int i = 0; i < subdiag_h; i++) {
            x2[i] = x[ridx[i + w]];
        }

        // print_col_major(x2, subdiag_h, 1, 1);

        float* L2 = L + w;

        // print_col_major(L2, w, subdiag_h, h);

        // Compute y1 -= L2.T x2
        gemv2(w, subdiag_h,
              L2, x2,
              x1, x1,
              stride,
              -1, 1, 1,
              false, false);

        my_free_after(x2);
    }

    // Solve L1^T x1 = y1 in place
    dense_block_triangle_solve_tranpose_vector(L, x1, w, stride);

}

void set_strictly_upper_trianguler(float a, float* x, int w, int h, int stride) {
  for(int j = 0; j < w; j++) {
    for(int i = 0; i < j && i < h; i++) {
      x[i] = a;
    }
    x += stride;
  }
}

// Do B += Ascale * A. Both A and B are square and col major. 
// A is Adim x Adim. B is Bdim x Bdim. Bdim >= Adim
// Bidx must be a superset of Aidx and in the same order
void sparse_matrix_add(float* A, int Adim, int Astride, int* Aidx,
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

// Add two dense blocks together
// Bblk = scaleA * Ablk + scaleB * Bblk
void dense_block_add(float* Ablk, float* Bblk, 
                     int height, int width,
                     int Astride, int Bstride,
                     float Ascale, float Bscale) {
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

// Do B += A. Both A and B are square and col major. 
// A is Adim x Adim. B is Bdim x Bdim. Bdim >= Adim
// Bidx must be a superset of Aidx and in the same order
void sparse_matrix_add2(float* A, int Adim, int Astride, int* Aidx,
                        float* B, int Bdim, int Bstride, int* Bidx,
                        float Ascale) {
  int* A_blk_start = (int*) my_malloc(Adim * sizeof(int));
  int* B_blk_start = (int*) my_malloc(Adim * sizeof(int));
  int* blk_width = (int*) my_malloc(Adim * sizeof(int));
  int num_blks;

  group_block_indices(Aidx, Adim, Bidx, Bdim, A_blk_start, B_blk_start, blk_width, &num_blks);

  float* A_col = A;
  for(int J = 0; J < num_blks; J++) {
    float* B_col = B + B_blk_start[J] * Bstride;
    for(int I = J; I < num_blks; I++) {
      float* A_blk = A_col + A_blk_start[I];
      float* B_blk = B_col + B_blk_start[I];
      dense_block_add(A_blk, B_blk, blk_width[I], blk_width[J], Astride, Bstride, 1, 1);
    }
    A_col += blk_width[J] * Astride;
  }
}

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
void group_block_indices2(int* Aidx, int Alen,
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
void sparse_matrix_add3(float* A, int Adim, int Astride, int* Aidx,
                        float* B, int Bdim, int Bstride, int* Bidx,
                        float Ascale, 
                        int* B_lookup) {
  int* A_blk_start = (int*) my_malloc(Adim * sizeof(int));
  int* B_blk_start = (int*) my_malloc(Adim * sizeof(int));
  int* blk_width = (int*) my_malloc(Adim * sizeof(int));
  int num_blks;

  group_block_indices2(Aidx, Adim, A_blk_start, B_blk_start, blk_width, &num_blks, B_lookup);

  float* A_col = A;
  for(int J = 0; J < num_blks; J++) {
    float* B_col = B + B_blk_start[J] * Bstride;
    for(int I = J; I < num_blks; I++) {
      float* A_blk = A_col + A_blk_start[I];
      float* B_blk = B_col + B_blk_start[I];
      dense_block_add(A_blk, B_blk, blk_width[I], blk_width[J], Astride, Bstride, 1, 1);
    }
    A_col += blk_width[J] * Astride;
  }
}

// Do B += A. Both A and B are square and col major. 
// A is Adim x Adim. B is Bdim x Bdim. Bdim >= Adim
// Bidx must be a superset of Aidx and in the same order
// Always do last column separately
void sparse_matrix_add3_2(float* A, int Adim, int Astride, int* Aidx,
                          float* B, int Bdim, int Bstride, int* Bidx,
                          float Ascale, 
                          int* B_lookup) {
  int* A_blk_start = (int*) my_malloc(Adim * sizeof(int));
  int* B_blk_start = (int*) my_malloc(Adim * sizeof(int));
  int* blk_width = (int*) my_malloc(Adim * sizeof(int));
  int num_blks;

  group_block_indices2(Aidx, Adim - 1, A_blk_start, B_blk_start, blk_width, &num_blks, B_lookup);
  
  for(int J = 0; J < num_blks; J++) {
    float* A_col = A + A_blk_start[J] * Astride;
    float* B_col = B + B_blk_start[J] * Bstride;
    for(int I = J; I < num_blks; I++) {
      float* A_blk = A_col + A_blk_start[I];
      float* B_blk = B_col + B_blk_start[I];
      dense_block_add(A_blk, B_blk, blk_width[I], blk_width[J], Astride, Bstride, 1, 1);
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

// Do B += A. Both A and B are square and col major. 
// A is Adim x Adim. B is Bdim x Bdim. Bdim >= Adim
// group_block_indices is preprocessed
// Always do last column separately
void sparse_matrix_add3_3(float* A, int Adim, int Astride,
                          float* B, int Bdim, int Bstride,
                          float Ascale, 
                          int num_blks, int* A_blk_start, int* B_blk_start, int* blk_width) {
  
  for(int J = 0; J < num_blks; J++) {
    float* A_col = A + A_blk_start[J] * Astride;
    float* B_col = B + B_blk_start[J] * Bstride;
    for(int I = J; I < num_blks; I++) {
      float* A_blk = A_col + A_blk_start[I];
      float* B_blk = B_col + B_blk_start[I];
      dense_block_add(A_blk, B_blk, blk_width[I], blk_width[J], Astride, Bstride, 1, 1);
    }
  }
  
  // Manually add last row

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

// Do B += A. Extend the case of sparse_block_add3 to nonsquare case
// A is Ah x Aw. Ah >= Aw. B is larger than A
// Bidx must be a superset of Aidx and in the same order
void sparse_matrix_add4(float* A, int Ah, int Aw, int Astride, int* Aidx,
                        float* B, int Bh, int Bw, int Bstride, int* Bidx,
                        float Ascale, 
                        int* B_lookup) {
  int* A_blk_start = (int*) my_malloc(Ah * sizeof(int));
  int* B_blk_start = (int*) my_malloc(Ah * sizeof(int));
  int* blk_widths = (int*) my_malloc(Ah * sizeof(int));
  int num_blks;

  group_block_indices2(Aidx, Ah, A_blk_start, B_blk_start, blk_widths, &num_blks, B_lookup);

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
}

// Do B += A. Extend the case of sparse_block_add3 to nonsquare case
// A is Ah x Aw. Ah >= Aw. B is larger than A
// Bidx must be a superset of Aidx and in the same order
// Always separate out the last row
void sparse_matrix_add4_2(float* A, int Ah, int Aw, int Astride, int* Aidx,
                        float* B, int Bh, int Bw, int Bstride, int* Bidx,
                        float Ascale, 
                        int* B_lookup) {
  int* A_blk_start = (int*) my_malloc(Ah * sizeof(int));
  int* B_blk_start = (int*) my_malloc(Ah * sizeof(int));
  int* blk_widths = (int*) my_malloc(Ah * sizeof(int));
  int num_blks;

  group_block_indices2(Aidx, Ah - 1, A_blk_start, B_blk_start, blk_widths, &num_blks, B_lookup);

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
  
  // Manually add last row
  A_blk_start[num_blks] = Ah - 1;
  B_blk_start[num_blks] = Bh - 1;
  blk_widths[num_blks] = 1;
  num_blks++;

  float* A_col = A + Ah - 1;
  for(int J = 0; J < num_blks; J++) {
    float* B_col = B + B_blk_start[J] * Bstride + Bh - 1;
    for(int j = 0; j < blk_widths[J]; j++) {
      *B_col += *A_col;
      A_col += Astride;
      B_col += Bstride;
    }
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
                       abs_err < FLT_EPSILON? 0 : INFINITY;

      // printf("%.10e, ", rel_err);
      // Disable check if absolute error small enough
      if(abs_err > tol) {
          if(rel_err > tol) {
            printf("Relative error at (%d, %d) exceeded threshold: %.8e. ERR_THRESH: %.8e\n", i, j, rel_err, tol);
            printf("Value: %f, Correct: %f\n", m[j * stride + i], m_correct[j * stride + i]);
            return 1;
          }
      }

    }
    // printf("\n");
  }
  return 0;
}
