#pragma once

const bool step40_is_reconstruct = true;

const int step40_num_threads = 1;

const uint64_t step40_scaled_relin_cost = 0;

const bool step40_run_model = false;

const int step40_factor115_height = 7;
const int step40_factor115_width = 6;
int step40_factor115_ridx[] = {12, 13, 14, 15, 16, 17, 18, };
float step40_factor115_data[42] = {0};

const int step40_factor115_num_blks = 1;
int step40_factor115_A_blk_start[] = {0, };
int step40_factor115_B_blk_start[] = {12, };
int step40_factor115_blk_width[] = {6, };

const int step40_factor116_height = 13;
const int step40_factor116_width = 6;
int step40_factor116_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, };
float step40_factor116_data[78] = {0};

const int step40_factor116_num_blks = 1;
int step40_factor116_A_blk_start[] = {0, };
int step40_factor116_B_blk_start[] = {6, };
int step40_factor116_blk_width[] = {12, };

const int step40_factor110_height = 7;
const int step40_factor110_width = 6;
int step40_factor110_ridx[] = {0, 1, 2, 3, 4, 5, 18, };
float step40_factor110_data[42] = {0};

const int step40_factor110_num_blks = 1;
int step40_factor110_A_blk_start[] = {0, };
int step40_factor110_B_blk_start[] = {0, };
int step40_factor110_blk_width[] = {6, };

const int step40_factor111_height = 13;
const int step40_factor111_width = 6;
int step40_factor111_ridx[] = {24, 25, 26, 27, 28, 29, 36, 37, 38, 39, 40, 41, 42, };
float step40_factor111_data[78] = {0};

const int step40_factor111_num_blks = 2;
int step40_factor111_A_blk_start[] = {0, 6, };
int step40_factor111_B_blk_start[] = {24, 36, };
int step40_factor111_blk_width[] = {6, 6, };

const int step40_factor112_height = 13;
const int step40_factor112_width = 6;
int step40_factor112_ridx[] = {24, 25, 26, 27, 28, 29, 48, 49, 50, 51, 52, 53, 54, };
float step40_factor112_data[78] = {0};

const int step40_factor112_num_blks = 2;
int step40_factor112_A_blk_start[] = {0, 6, };
int step40_factor112_B_blk_start[] = {24, 48, };
int step40_factor112_blk_width[] = {6, 6, };

const int step40_factor113_height = 7;
const int step40_factor113_width = 6;
int step40_factor113_ridx[] = {6, 7, 8, 9, 10, 11, 18, };
float step40_factor113_data[42] = {0};

const int step40_factor113_num_blks = 1;
int step40_factor113_A_blk_start[] = {0, };
int step40_factor113_B_blk_start[] = {6, };
int step40_factor113_blk_width[] = {6, };

const int step40_factor114_height = 13;
const int step40_factor114_width = 6;
int step40_factor114_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 18, };
float step40_factor114_data[78] = {0};

const int step40_factor114_num_blks = 1;
int step40_factor114_A_blk_start[] = {0, };
int step40_factor114_B_blk_start[] = {0, };
int step40_factor114_blk_width[] = {12, };

const int step40_node4_num_factors = 1;
const int step40_node4_relin_cost = 0;
const int step40_node4_sym_cost = 20000;
const bool step40_node4_marked = false;
const bool step40_node4_fixed = true;
int step40_node4_factor_height[] = {step40_factor112_height, };
int step40_node4_factor_width[] = {step40_factor112_width, };
int* step40_node4_factor_ridx[] = {step40_factor112_ridx, };
float* step40_node4_factor_data[] = {step40_factor112_data, };
int step40_node4_factor_num_blks[] = {step40_factor112_num_blks, };
int* step40_node4_factor_A_blk_start[] = {step40_factor112_A_blk_start, };
int* step40_node4_factor_B_blk_start[] = {step40_factor112_B_blk_start, };
int* step40_node4_factor_blk_width[] = {step40_factor112_blk_width, };
const int step40_node4_parent = 6;
const int step40_node4_height = 55;
const int step40_node4_width = 30;
float step40_node4_data[1650] = {0};
const int step40_node4_num_blks = 2;
int step40_node4_A_blk_start[] = {0, 12, };
int step40_node4_B_blk_start[] = {12, 30, };
int step40_node4_blk_width[] = {12, 12, };


const int step40_node6_num_factors = 1;
const int step40_node6_relin_cost = 0;
const int step40_node6_sym_cost = 20000;
const bool step40_node6_marked = false;
const bool step40_node6_fixed = true;
int step40_node6_factor_height[] = {step40_factor111_height, };
int step40_node6_factor_width[] = {step40_factor111_width, };
int* step40_node6_factor_ridx[] = {step40_factor111_ridx, };
float* step40_node6_factor_data[] = {step40_factor111_data, };
int step40_node6_factor_num_blks[] = {step40_factor111_num_blks, };
int* step40_node6_factor_A_blk_start[] = {step40_factor111_A_blk_start, };
int* step40_node6_factor_B_blk_start[] = {step40_factor111_B_blk_start, };
int* step40_node6_factor_blk_width[] = {step40_factor111_blk_width, };
const int step40_node6_parent = 7;
const int step40_node6_height = 43;
const int step40_node6_width = 30;
float step40_node6_data[1290] = {0};
const int step40_node6_num_blks = 2;
int step40_node6_A_blk_start[] = {0, 6, };
int step40_node6_B_blk_start[] = {18, 42, };
int step40_node6_blk_width[] = {6, 6, };


const int step40_node7_num_factors = 0;
const int step40_node7_relin_cost = 0;
const int step40_node7_sym_cost = 28000;
const bool step40_node7_marked = false;
const bool step40_node7_fixed = true;
int step40_node7_factor_height[] = {};
int step40_node7_factor_width[] = {};
int* step40_node7_factor_ridx[] = {};
float* step40_node7_factor_data[] = {};
int step40_node7_factor_num_blks[] = {};
int* step40_node7_factor_A_blk_start[] = {};
int* step40_node7_factor_B_blk_start[] = {};
int* step40_node7_factor_blk_width[] = {};
const int step40_node7_parent = 8;
const int step40_node7_height = 49;
const int step40_node7_width = 42;
float step40_node7_data[2058] = {0};
const int step40_node7_num_blks = 1;
int step40_node7_A_blk_start[] = {0, };
int step40_node7_B_blk_start[] = {0, };
int step40_node7_blk_width[] = {6, };


const int step40_node8_num_factors = 5;
const int step40_node8_relin_cost = 0;
const int step40_node8_sym_cost = 12000;
const bool step40_node8_marked = true;
const bool step40_node8_fixed = false;
int step40_node8_factor_height[] = {step40_factor110_height, step40_factor113_height, step40_factor114_height, step40_factor115_height, step40_factor116_height, };
int step40_node8_factor_width[] = {step40_factor110_width, step40_factor113_width, step40_factor114_width, step40_factor115_width, step40_factor116_width, };
int* step40_node8_factor_ridx[] = {step40_factor110_ridx, step40_factor113_ridx, step40_factor114_ridx, step40_factor115_ridx, step40_factor116_ridx, };
float* step40_node8_factor_data[] = {step40_factor110_data, step40_factor113_data, step40_factor114_data, step40_factor115_data, step40_factor116_data, };
int step40_node8_factor_num_blks[] = {step40_factor110_num_blks, step40_factor113_num_blks, step40_factor114_num_blks, step40_factor115_num_blks, step40_factor116_num_blks, };
int* step40_node8_factor_A_blk_start[] = {step40_factor110_A_blk_start, step40_factor113_A_blk_start, step40_factor114_A_blk_start, step40_factor115_A_blk_start, step40_factor116_A_blk_start, };
int* step40_node8_factor_B_blk_start[] = {step40_factor110_B_blk_start, step40_factor113_B_blk_start, step40_factor114_B_blk_start, step40_factor115_B_blk_start, step40_factor116_B_blk_start, };
int* step40_node8_factor_blk_width[] = {step40_factor110_blk_width, step40_factor113_blk_width, step40_factor114_blk_width, step40_factor115_blk_width, step40_factor116_blk_width, };
const int step40_node8_parent = 9;
const int step40_node8_height = 19;
const int step40_node8_width = 18;
float step40_node8_data[342] = {0};
const int step40_node8_num_blks = 0;
int step40_node8_A_blk_start[] = {};
int step40_node8_B_blk_start[] = {};
int step40_node8_blk_width[] = {};


const int step40_node9_num_factors = 0;
const int step40_node9_relin_cost = 0;
const int step40_node9_sym_cost = 4000;
const bool step40_node9_marked = true;
const bool step40_node9_fixed = false;
int step40_node9_factor_height[] = {};
int step40_node9_factor_width[] = {};
int* step40_node9_factor_ridx[] = {};
float* step40_node9_factor_data[] = {};
int step40_node9_factor_num_blks[] = {};
int* step40_node9_factor_A_blk_start[] = {};
int* step40_node9_factor_B_blk_start[] = {};
int* step40_node9_factor_blk_width[] = {};
const int step40_node9_parent = -1;
const int step40_node9_height = 1;
const int step40_node9_width = 1;
float step40_node9_data[1] = {0};
const int step40_node9_num_blks = 0;
int step40_node9_A_blk_start[] = {};
int step40_node9_B_blk_start[] = {};
int step40_node9_blk_width[] = {};


int step40_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 246, };
int step40_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 246, };
int step40_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 126, 127, 128, 129, 130, 131, 246, };
int step40_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 246, };
int step40_node4_ridx[] = {
102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 204, 205, 206, 207, 208, 209, 228, 229, 230, 231, 232, 233, 246, };
int step40_node5_ridx[] = {
132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 246, };
int step40_node6_ridx[] = {
156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 204, 205, 206, 207, 208, 209, 228, 229, 230, 231, 232, 233, 246, };
int step40_node7_ridx[] = {
186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 246, };
int step40_node8_ridx[] = {
228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, };
int step40_node9_ridx[] = {
246, };
const int step40_nnodes = 10;
bool step40_node_marked[] = {false, false, false, false, step40_node4_marked, false, step40_node6_marked, step40_node7_marked, step40_node8_marked, step40_node9_marked, };
bool step40_node_fixed[] = {false, false, false, false, step40_node4_fixed, false, step40_node6_fixed, step40_node7_fixed, step40_node8_fixed, step40_node9_fixed, };
int step40_node_num_factors[] = {0, 0, 0, 0, step40_node4_num_factors, 0, step40_node6_num_factors, step40_node7_num_factors, step40_node8_num_factors, step40_node9_num_factors, };
int step40_node_relin_cost[] = {0, 0, 0, 0, step40_node4_relin_cost, 0, step40_node6_relin_cost, step40_node7_relin_cost, step40_node8_relin_cost, step40_node9_relin_cost, };
int step40_node_sym_cost[] = {0, 0, 0, 0, step40_node4_sym_cost, 0, step40_node6_sym_cost, step40_node7_sym_cost, step40_node8_sym_cost, step40_node9_sym_cost, };
int* step40_node_factor_height[] = {0, 0, 0, 0, step40_node4_factor_height, 0, step40_node6_factor_height, step40_node7_factor_height, step40_node8_factor_height, step40_node9_factor_height, };
int* step40_node_factor_width[] = {0, 0, 0, 0, step40_node4_factor_width, 0, step40_node6_factor_width, step40_node7_factor_width, step40_node8_factor_width, step40_node9_factor_width, };
int** step40_node_factor_ridx[] = {0, 0, 0, 0, step40_node4_factor_ridx, 0, step40_node6_factor_ridx, step40_node7_factor_ridx, step40_node8_factor_ridx, step40_node9_factor_ridx, };
float** step40_node_factor_data[] = {0, 0, 0, 0, step40_node4_factor_data, 0, step40_node6_factor_data, step40_node7_factor_data, step40_node8_factor_data, step40_node9_factor_data, };
int* step40_node_factor_num_blks[] = {0, 0, 0, 0, step40_node4_factor_num_blks, 0, step40_node6_factor_num_blks, step40_node7_factor_num_blks, step40_node8_factor_num_blks, step40_node9_factor_num_blks, };
int** step40_node_factor_A_blk_start[] = {0, 0, 0, 0, step40_node4_factor_A_blk_start, 0, step40_node6_factor_A_blk_start, step40_node7_factor_A_blk_start, step40_node8_factor_A_blk_start, step40_node9_factor_A_blk_start, };
int** step40_node_factor_B_blk_start[] = {0, 0, 0, 0, step40_node4_factor_B_blk_start, 0, step40_node6_factor_B_blk_start, step40_node7_factor_B_blk_start, step40_node8_factor_B_blk_start, step40_node9_factor_B_blk_start, };
int** step40_node_factor_blk_width[] = {0, 0, 0, 0, step40_node4_factor_blk_width, 0, step40_node6_factor_blk_width, step40_node7_factor_blk_width, step40_node8_factor_blk_width, step40_node9_factor_blk_width, };
int step40_node_parent[] = {0, 0, 0, 0, step40_node4_parent, 0, step40_node6_parent, step40_node7_parent, step40_node8_parent, step40_node9_parent, };
int step40_node_height[] = {0, 0, 0, 0, step40_node4_height, 0, step40_node6_height, step40_node7_height, step40_node8_height, step40_node9_height, };
int step40_node_width[] = {0, 0, 0, 0, step40_node4_width, 0, step40_node6_width, step40_node7_width, step40_node8_width, step40_node9_width, };
float* step40_node_data[] = {0, 0, 0, 0, step40_node4_data, 0, step40_node6_data, step40_node7_data, step40_node8_data, step40_node9_data, };
int step40_node_num_blks[] = {0, 0, 0, 0, step40_node4_num_blks, 0, step40_node6_num_blks, step40_node7_num_blks, step40_node8_num_blks, step40_node9_num_blks, };
int* step40_node_A_blk_start[] = {0, 0, 0, 0, step40_node4_A_blk_start, 0, step40_node6_A_blk_start, step40_node7_A_blk_start, step40_node8_A_blk_start, step40_node9_A_blk_start, };
int* step40_node_B_blk_start[] = {0, 0, 0, 0, step40_node4_B_blk_start, 0, step40_node6_B_blk_start, step40_node7_B_blk_start, step40_node8_B_blk_start, step40_node9_B_blk_start, };
int* step40_node_blk_width[] = {0, 0, 0, 0, step40_node4_blk_width, 0, step40_node6_blk_width, step40_node7_blk_width, step40_node8_blk_width, step40_node9_blk_width, };
int* step40_node_ridx[] = {step40_node0_ridx, step40_node1_ridx, step40_node2_ridx, step40_node3_ridx, step40_node4_ridx, step40_node5_ridx, step40_node6_ridx, step40_node7_ridx, step40_node8_ridx, step40_node9_ridx, };


float step40_x_data[247] = {};
const int step40_workspace_needed = 31048;

