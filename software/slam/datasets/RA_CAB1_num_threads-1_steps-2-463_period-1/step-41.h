#pragma once

const bool step41_is_reconstruct = true;

const int step41_num_threads = 1;

const uint64_t step41_scaled_relin_cost = 0;

const bool step41_run_model = false;

const int step41_factor111_height = 13;
const int step41_factor111_width = 6;
int step41_factor111_ridx[] = {24, 25, 26, 27, 28, 29, 36, 37, 38, 39, 40, 41, 42, };
float step41_factor111_data[78] = {0};

const int step41_factor111_num_blks = 2;
int step41_factor111_A_blk_start[] = {0, 6, };
int step41_factor111_B_blk_start[] = {24, 36, };
int step41_factor111_blk_width[] = {6, 6, };

const int step41_factor112_height = 13;
const int step41_factor112_width = 6;
int step41_factor112_ridx[] = {24, 25, 26, 27, 28, 29, 48, 49, 50, 51, 52, 53, 54, };
float step41_factor112_data[78] = {0};

const int step41_factor112_num_blks = 2;
int step41_factor112_A_blk_start[] = {0, 6, };
int step41_factor112_B_blk_start[] = {24, 48, };
int step41_factor112_blk_width[] = {6, 6, };

const int step41_factor113_height = 7;
const int step41_factor113_width = 6;
int step41_factor113_ridx[] = {6, 7, 8, 9, 10, 11, 24, };
float step41_factor113_data[42] = {0};

const int step41_factor113_num_blks = 1;
int step41_factor113_A_blk_start[] = {0, };
int step41_factor113_B_blk_start[] = {6, };
int step41_factor113_blk_width[] = {6, };

const int step41_factor114_height = 13;
const int step41_factor114_width = 6;
int step41_factor114_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 24, };
float step41_factor114_data[78] = {0};

const int step41_factor114_num_blks = 1;
int step41_factor114_A_blk_start[] = {0, };
int step41_factor114_B_blk_start[] = {0, };
int step41_factor114_blk_width[] = {12, };

const int step41_factor115_height = 7;
const int step41_factor115_width = 6;
int step41_factor115_ridx[] = {12, 13, 14, 15, 16, 17, 24, };
float step41_factor115_data[42] = {0};

const int step41_factor115_num_blks = 1;
int step41_factor115_A_blk_start[] = {0, };
int step41_factor115_B_blk_start[] = {12, };
int step41_factor115_blk_width[] = {6, };

const int step41_factor116_height = 13;
const int step41_factor116_width = 6;
int step41_factor116_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 24, };
float step41_factor116_data[78] = {0};

const int step41_factor116_num_blks = 1;
int step41_factor116_A_blk_start[] = {0, };
int step41_factor116_B_blk_start[] = {6, };
int step41_factor116_blk_width[] = {12, };

const int step41_factor117_height = 7;
const int step41_factor117_width = 6;
int step41_factor117_ridx[] = {18, 19, 20, 21, 22, 23, 24, };
float step41_factor117_data[42] = {0};

const int step41_factor117_num_blks = 1;
int step41_factor117_A_blk_start[] = {0, };
int step41_factor117_B_blk_start[] = {18, };
int step41_factor117_blk_width[] = {6, };

const int step41_factor118_height = 13;
const int step41_factor118_width = 6;
int step41_factor118_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, };
float step41_factor118_data[78] = {0};

const int step41_factor118_num_blks = 1;
int step41_factor118_A_blk_start[] = {0, };
int step41_factor118_B_blk_start[] = {12, };
int step41_factor118_blk_width[] = {12, };

const int step41_factor119_height = 13;
const int step41_factor119_width = 6;
int step41_factor119_ridx[] = {0, 1, 2, 3, 4, 5, 18, 19, 20, 21, 22, 23, 24, };
float step41_factor119_data[78] = {0};

const int step41_factor119_num_blks = 2;
int step41_factor119_A_blk_start[] = {0, 6, };
int step41_factor119_B_blk_start[] = {0, 18, };
int step41_factor119_blk_width[] = {6, 6, };

const int step41_factor120_height = 13;
const int step41_factor120_width = 6;
int step41_factor120_ridx[] = {6, 7, 8, 9, 10, 11, 18, 19, 20, 21, 22, 23, 24, };
float step41_factor120_data[78] = {0};

const int step41_factor120_num_blks = 2;
int step41_factor120_A_blk_start[] = {0, 6, };
int step41_factor120_B_blk_start[] = {6, 18, };
int step41_factor120_blk_width[] = {6, 6, };

const int step41_factor110_height = 7;
const int step41_factor110_width = 6;
int step41_factor110_ridx[] = {0, 1, 2, 3, 4, 5, 24, };
float step41_factor110_data[42] = {0};

const int step41_factor110_num_blks = 1;
int step41_factor110_A_blk_start[] = {0, };
int step41_factor110_B_blk_start[] = {0, };
int step41_factor110_blk_width[] = {6, };

const int step41_node4_num_factors = 1;
const int step41_node4_relin_cost = 0;
const int step41_node4_sym_cost = 20000;
const bool step41_node4_marked = false;
const bool step41_node4_fixed = true;
int step41_node4_factor_height[] = {step41_factor112_height, };
int step41_node4_factor_width[] = {step41_factor112_width, };
int* step41_node4_factor_ridx[] = {step41_factor112_ridx, };
float* step41_node4_factor_data[] = {step41_factor112_data, };
int step41_node4_factor_num_blks[] = {step41_factor112_num_blks, };
int* step41_node4_factor_A_blk_start[] = {step41_factor112_A_blk_start, };
int* step41_node4_factor_B_blk_start[] = {step41_factor112_B_blk_start, };
int* step41_node4_factor_blk_width[] = {step41_factor112_blk_width, };
const int step41_node4_parent = 6;
const int step41_node4_height = 55;
const int step41_node4_width = 30;
float step41_node4_data[1650] = {0};
const int step41_node4_num_blks = 2;
int step41_node4_A_blk_start[] = {0, 12, };
int step41_node4_B_blk_start[] = {12, 30, };
int step41_node4_blk_width[] = {12, 12, };


const int step41_node6_num_factors = 1;
const int step41_node6_relin_cost = 0;
const int step41_node6_sym_cost = 20000;
const bool step41_node6_marked = false;
const bool step41_node6_fixed = true;
int step41_node6_factor_height[] = {step41_factor111_height, };
int step41_node6_factor_width[] = {step41_factor111_width, };
int* step41_node6_factor_ridx[] = {step41_factor111_ridx, };
float* step41_node6_factor_data[] = {step41_factor111_data, };
int step41_node6_factor_num_blks[] = {step41_factor111_num_blks, };
int* step41_node6_factor_A_blk_start[] = {step41_factor111_A_blk_start, };
int* step41_node6_factor_B_blk_start[] = {step41_factor111_B_blk_start, };
int* step41_node6_factor_blk_width[] = {step41_factor111_blk_width, };
const int step41_node6_parent = 7;
const int step41_node6_height = 43;
const int step41_node6_width = 30;
float step41_node6_data[1290] = {0};
const int step41_node6_num_blks = 2;
int step41_node6_A_blk_start[] = {0, 6, };
int step41_node6_B_blk_start[] = {18, 42, };
int step41_node6_blk_width[] = {6, 6, };


const int step41_node7_num_factors = 0;
const int step41_node7_relin_cost = 0;
const int step41_node7_sym_cost = 28000;
const bool step41_node7_marked = false;
const bool step41_node7_fixed = true;
int step41_node7_factor_height[] = {};
int step41_node7_factor_width[] = {};
int* step41_node7_factor_ridx[] = {};
float* step41_node7_factor_data[] = {};
int step41_node7_factor_num_blks[] = {};
int* step41_node7_factor_A_blk_start[] = {};
int* step41_node7_factor_B_blk_start[] = {};
int* step41_node7_factor_blk_width[] = {};
const int step41_node7_parent = 8;
const int step41_node7_height = 49;
const int step41_node7_width = 42;
float step41_node7_data[2058] = {0};
const int step41_node7_num_blks = 1;
int step41_node7_A_blk_start[] = {0, };
int step41_node7_B_blk_start[] = {0, };
int step41_node7_blk_width[] = {6, };


const int step41_node8_num_factors = 9;
const int step41_node8_relin_cost = 0;
const int step41_node8_sym_cost = 16000;
const bool step41_node8_marked = true;
const bool step41_node8_fixed = false;
int step41_node8_factor_height[] = {step41_factor110_height, step41_factor113_height, step41_factor114_height, step41_factor115_height, step41_factor116_height, step41_factor117_height, step41_factor118_height, step41_factor119_height, step41_factor120_height, };
int step41_node8_factor_width[] = {step41_factor110_width, step41_factor113_width, step41_factor114_width, step41_factor115_width, step41_factor116_width, step41_factor117_width, step41_factor118_width, step41_factor119_width, step41_factor120_width, };
int* step41_node8_factor_ridx[] = {step41_factor110_ridx, step41_factor113_ridx, step41_factor114_ridx, step41_factor115_ridx, step41_factor116_ridx, step41_factor117_ridx, step41_factor118_ridx, step41_factor119_ridx, step41_factor120_ridx, };
float* step41_node8_factor_data[] = {step41_factor110_data, step41_factor113_data, step41_factor114_data, step41_factor115_data, step41_factor116_data, step41_factor117_data, step41_factor118_data, step41_factor119_data, step41_factor120_data, };
int step41_node8_factor_num_blks[] = {step41_factor110_num_blks, step41_factor113_num_blks, step41_factor114_num_blks, step41_factor115_num_blks, step41_factor116_num_blks, step41_factor117_num_blks, step41_factor118_num_blks, step41_factor119_num_blks, step41_factor120_num_blks, };
int* step41_node8_factor_A_blk_start[] = {step41_factor110_A_blk_start, step41_factor113_A_blk_start, step41_factor114_A_blk_start, step41_factor115_A_blk_start, step41_factor116_A_blk_start, step41_factor117_A_blk_start, step41_factor118_A_blk_start, step41_factor119_A_blk_start, step41_factor120_A_blk_start, };
int* step41_node8_factor_B_blk_start[] = {step41_factor110_B_blk_start, step41_factor113_B_blk_start, step41_factor114_B_blk_start, step41_factor115_B_blk_start, step41_factor116_B_blk_start, step41_factor117_B_blk_start, step41_factor118_B_blk_start, step41_factor119_B_blk_start, step41_factor120_B_blk_start, };
int* step41_node8_factor_blk_width[] = {step41_factor110_blk_width, step41_factor113_blk_width, step41_factor114_blk_width, step41_factor115_blk_width, step41_factor116_blk_width, step41_factor117_blk_width, step41_factor118_blk_width, step41_factor119_blk_width, step41_factor120_blk_width, };
const int step41_node8_parent = 9;
const int step41_node8_height = 25;
const int step41_node8_width = 24;
float step41_node8_data[600] = {0};
const int step41_node8_num_blks = 0;
int step41_node8_A_blk_start[] = {};
int step41_node8_B_blk_start[] = {};
int step41_node8_blk_width[] = {};


const int step41_node9_num_factors = 0;
const int step41_node9_relin_cost = 0;
const int step41_node9_sym_cost = 4000;
const bool step41_node9_marked = true;
const bool step41_node9_fixed = false;
int step41_node9_factor_height[] = {};
int step41_node9_factor_width[] = {};
int* step41_node9_factor_ridx[] = {};
float* step41_node9_factor_data[] = {};
int step41_node9_factor_num_blks[] = {};
int* step41_node9_factor_A_blk_start[] = {};
int* step41_node9_factor_B_blk_start[] = {};
int* step41_node9_factor_blk_width[] = {};
const int step41_node9_parent = -1;
const int step41_node9_height = 1;
const int step41_node9_width = 1;
float step41_node9_data[1] = {0};
const int step41_node9_num_blks = 0;
int step41_node9_A_blk_start[] = {};
int step41_node9_B_blk_start[] = {};
int step41_node9_blk_width[] = {};


int step41_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 252, };
int step41_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 252, };
int step41_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 126, 127, 128, 129, 130, 131, 252, };
int step41_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 252, };
int step41_node4_ridx[] = {
102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 204, 205, 206, 207, 208, 209, 228, 229, 230, 231, 232, 233, 252, };
int step41_node5_ridx[] = {
132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 252, };
int step41_node6_ridx[] = {
156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 204, 205, 206, 207, 208, 209, 228, 229, 230, 231, 232, 233, 252, };
int step41_node7_ridx[] = {
186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 252, };
int step41_node8_ridx[] = {
228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, };
int step41_node9_ridx[] = {
252, };
const int step41_nnodes = 10;
bool step41_node_marked[] = {false, false, false, false, step41_node4_marked, false, step41_node6_marked, step41_node7_marked, step41_node8_marked, step41_node9_marked, };
bool step41_node_fixed[] = {false, false, false, false, step41_node4_fixed, false, step41_node6_fixed, step41_node7_fixed, step41_node8_fixed, step41_node9_fixed, };
int step41_node_num_factors[] = {0, 0, 0, 0, step41_node4_num_factors, 0, step41_node6_num_factors, step41_node7_num_factors, step41_node8_num_factors, step41_node9_num_factors, };
int step41_node_relin_cost[] = {0, 0, 0, 0, step41_node4_relin_cost, 0, step41_node6_relin_cost, step41_node7_relin_cost, step41_node8_relin_cost, step41_node9_relin_cost, };
int step41_node_sym_cost[] = {0, 0, 0, 0, step41_node4_sym_cost, 0, step41_node6_sym_cost, step41_node7_sym_cost, step41_node8_sym_cost, step41_node9_sym_cost, };
int* step41_node_factor_height[] = {0, 0, 0, 0, step41_node4_factor_height, 0, step41_node6_factor_height, step41_node7_factor_height, step41_node8_factor_height, step41_node9_factor_height, };
int* step41_node_factor_width[] = {0, 0, 0, 0, step41_node4_factor_width, 0, step41_node6_factor_width, step41_node7_factor_width, step41_node8_factor_width, step41_node9_factor_width, };
int** step41_node_factor_ridx[] = {0, 0, 0, 0, step41_node4_factor_ridx, 0, step41_node6_factor_ridx, step41_node7_factor_ridx, step41_node8_factor_ridx, step41_node9_factor_ridx, };
float** step41_node_factor_data[] = {0, 0, 0, 0, step41_node4_factor_data, 0, step41_node6_factor_data, step41_node7_factor_data, step41_node8_factor_data, step41_node9_factor_data, };
int* step41_node_factor_num_blks[] = {0, 0, 0, 0, step41_node4_factor_num_blks, 0, step41_node6_factor_num_blks, step41_node7_factor_num_blks, step41_node8_factor_num_blks, step41_node9_factor_num_blks, };
int** step41_node_factor_A_blk_start[] = {0, 0, 0, 0, step41_node4_factor_A_blk_start, 0, step41_node6_factor_A_blk_start, step41_node7_factor_A_blk_start, step41_node8_factor_A_blk_start, step41_node9_factor_A_blk_start, };
int** step41_node_factor_B_blk_start[] = {0, 0, 0, 0, step41_node4_factor_B_blk_start, 0, step41_node6_factor_B_blk_start, step41_node7_factor_B_blk_start, step41_node8_factor_B_blk_start, step41_node9_factor_B_blk_start, };
int** step41_node_factor_blk_width[] = {0, 0, 0, 0, step41_node4_factor_blk_width, 0, step41_node6_factor_blk_width, step41_node7_factor_blk_width, step41_node8_factor_blk_width, step41_node9_factor_blk_width, };
int step41_node_parent[] = {0, 0, 0, 0, step41_node4_parent, 0, step41_node6_parent, step41_node7_parent, step41_node8_parent, step41_node9_parent, };
int step41_node_height[] = {0, 0, 0, 0, step41_node4_height, 0, step41_node6_height, step41_node7_height, step41_node8_height, step41_node9_height, };
int step41_node_width[] = {0, 0, 0, 0, step41_node4_width, 0, step41_node6_width, step41_node7_width, step41_node8_width, step41_node9_width, };
float* step41_node_data[] = {0, 0, 0, 0, step41_node4_data, 0, step41_node6_data, step41_node7_data, step41_node8_data, step41_node9_data, };
int step41_node_num_blks[] = {0, 0, 0, 0, step41_node4_num_blks, 0, step41_node6_num_blks, step41_node7_num_blks, step41_node8_num_blks, step41_node9_num_blks, };
int* step41_node_A_blk_start[] = {0, 0, 0, 0, step41_node4_A_blk_start, 0, step41_node6_A_blk_start, step41_node7_A_blk_start, step41_node8_A_blk_start, step41_node9_A_blk_start, };
int* step41_node_B_blk_start[] = {0, 0, 0, 0, step41_node4_B_blk_start, 0, step41_node6_B_blk_start, step41_node7_B_blk_start, step41_node8_B_blk_start, step41_node9_B_blk_start, };
int* step41_node_blk_width[] = {0, 0, 0, 0, step41_node4_blk_width, 0, step41_node6_blk_width, step41_node7_blk_width, step41_node8_blk_width, step41_node9_blk_width, };
int* step41_node_ridx[] = {step41_node0_ridx, step41_node1_ridx, step41_node2_ridx, step41_node3_ridx, step41_node4_ridx, step41_node5_ridx, step41_node6_ridx, step41_node7_ridx, step41_node8_ridx, step41_node9_ridx, };


float step41_x_data[253] = {};
const int step41_workspace_needed = 32104;

