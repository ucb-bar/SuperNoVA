#pragma once

const bool step25_is_reconstruct = true;

const int step25_num_threads = 1;

const uint64_t step25_scaled_relin_cost = 0;

const bool step25_run_model = false;

const int step25_factor51_height = 13;
const int step25_factor51_width = 6;
int step25_factor51_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, };
float step25_factor51_data[78] = {0};

const int step25_factor51_num_blks = 1;
int step25_factor51_A_blk_start[] = {0, };
int step25_factor51_B_blk_start[] = {0, };
int step25_factor51_blk_width[] = {12, };

const int step25_factor50_height = 7;
const int step25_factor50_width = 6;
int step25_factor50_ridx[] = {6, 7, 8, 9, 10, 11, 12, };
float step25_factor50_data[42] = {0};

const int step25_factor50_num_blks = 1;
int step25_factor50_A_blk_start[] = {0, };
int step25_factor50_B_blk_start[] = {6, };
int step25_factor50_blk_width[] = {6, };

const int step25_factor49_height = 13;
const int step25_factor49_width = 6;
int step25_factor49_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step25_factor49_data[78] = {0};

const int step25_factor49_num_blks = 1;
int step25_factor49_A_blk_start[] = {0, };
int step25_factor49_B_blk_start[] = {18, };
int step25_factor49_blk_width[] = {12, };

const int step25_factor48_height = 7;
const int step25_factor48_width = 6;
int step25_factor48_ridx[] = {0, 1, 2, 3, 4, 5, 12, };
float step25_factor48_data[42] = {0};

const int step25_factor48_num_blks = 1;
int step25_factor48_A_blk_start[] = {0, };
int step25_factor48_B_blk_start[] = {0, };
int step25_factor48_blk_width[] = {6, };

const int step25_node5_num_factors = 1;
const int step25_node5_relin_cost = 0;
const int step25_node5_sym_cost = 8000;
const bool step25_node5_marked = false;
const bool step25_node5_fixed = true;
int step25_node5_factor_height[] = {step25_factor49_height, };
int step25_node5_factor_width[] = {step25_factor49_width, };
int* step25_node5_factor_ridx[] = {step25_factor49_ridx, };
float* step25_node5_factor_data[] = {step25_factor49_data, };
int step25_node5_factor_num_blks[] = {step25_factor49_num_blks, };
int* step25_node5_factor_A_blk_start[] = {step25_factor49_A_blk_start, };
int* step25_node5_factor_B_blk_start[] = {step25_factor49_B_blk_start, };
int* step25_node5_factor_blk_width[] = {step25_factor49_blk_width, };
const int step25_node5_parent = 6;
const int step25_node5_height = 31;
const int step25_node5_width = 24;
float step25_node5_data[744] = {0};
const int step25_node5_num_blks = 1;
int step25_node5_A_blk_start[] = {0, };
int step25_node5_B_blk_start[] = {0, };
int step25_node5_blk_width[] = {6, };


const int step25_node6_num_factors = 3;
const int step25_node6_relin_cost = 0;
const int step25_node6_sym_cost = 4000;
const bool step25_node6_marked = true;
const bool step25_node6_fixed = false;
int step25_node6_factor_height[] = {step25_factor48_height, step25_factor50_height, step25_factor51_height, };
int step25_node6_factor_width[] = {step25_factor48_width, step25_factor50_width, step25_factor51_width, };
int* step25_node6_factor_ridx[] = {step25_factor48_ridx, step25_factor50_ridx, step25_factor51_ridx, };
float* step25_node6_factor_data[] = {step25_factor48_data, step25_factor50_data, step25_factor51_data, };
int step25_node6_factor_num_blks[] = {step25_factor48_num_blks, step25_factor50_num_blks, step25_factor51_num_blks, };
int* step25_node6_factor_A_blk_start[] = {step25_factor48_A_blk_start, step25_factor50_A_blk_start, step25_factor51_A_blk_start, };
int* step25_node6_factor_B_blk_start[] = {step25_factor48_B_blk_start, step25_factor50_B_blk_start, step25_factor51_B_blk_start, };
int* step25_node6_factor_blk_width[] = {step25_factor48_blk_width, step25_factor50_blk_width, step25_factor51_blk_width, };
const int step25_node6_parent = 7;
const int step25_node6_height = 13;
const int step25_node6_width = 12;
float step25_node6_data[156] = {0};
const int step25_node6_num_blks = 0;
int step25_node6_A_blk_start[] = {};
int step25_node6_B_blk_start[] = {};
int step25_node6_blk_width[] = {};


const int step25_node7_num_factors = 0;
const int step25_node7_relin_cost = 0;
const int step25_node7_sym_cost = 2000;
const bool step25_node7_marked = true;
const bool step25_node7_fixed = false;
int step25_node7_factor_height[] = {};
int step25_node7_factor_width[] = {};
int* step25_node7_factor_ridx[] = {};
float* step25_node7_factor_data[] = {};
int step25_node7_factor_num_blks[] = {};
int* step25_node7_factor_A_blk_start[] = {};
int* step25_node7_factor_B_blk_start[] = {};
int* step25_node7_factor_blk_width[] = {};
const int step25_node7_parent = -1;
const int step25_node7_height = 1;
const int step25_node7_width = 1;
float step25_node7_data[1] = {0};
const int step25_node7_num_blks = 0;
int step25_node7_A_blk_start[] = {};
int step25_node7_B_blk_start[] = {};
int step25_node7_blk_width[] = {};


int step25_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 156, };
int step25_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 156, };
int step25_node2_ridx[] = {
48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 156, };
int step25_node3_ridx[] = {
72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 156, };
int step25_node4_ridx[] = {
96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 156, };
int step25_node5_ridx[] = {
120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 156, };
int step25_node6_ridx[] = {
144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, };
int step25_node7_ridx[] = {
156, };
const int step25_nnodes = 8;
bool step25_node_marked[] = {false, false, false, false, false, step25_node5_marked, step25_node6_marked, step25_node7_marked, };
bool step25_node_fixed[] = {false, false, false, false, false, step25_node5_fixed, step25_node6_fixed, step25_node7_fixed, };
int step25_node_num_factors[] = {0, 0, 0, 0, 0, step25_node5_num_factors, step25_node6_num_factors, step25_node7_num_factors, };
int step25_node_relin_cost[] = {0, 0, 0, 0, 0, step25_node5_relin_cost, step25_node6_relin_cost, step25_node7_relin_cost, };
int step25_node_sym_cost[] = {0, 0, 0, 0, 0, step25_node5_sym_cost, step25_node6_sym_cost, step25_node7_sym_cost, };
int* step25_node_factor_height[] = {0, 0, 0, 0, 0, step25_node5_factor_height, step25_node6_factor_height, step25_node7_factor_height, };
int* step25_node_factor_width[] = {0, 0, 0, 0, 0, step25_node5_factor_width, step25_node6_factor_width, step25_node7_factor_width, };
int** step25_node_factor_ridx[] = {0, 0, 0, 0, 0, step25_node5_factor_ridx, step25_node6_factor_ridx, step25_node7_factor_ridx, };
float** step25_node_factor_data[] = {0, 0, 0, 0, 0, step25_node5_factor_data, step25_node6_factor_data, step25_node7_factor_data, };
int* step25_node_factor_num_blks[] = {0, 0, 0, 0, 0, step25_node5_factor_num_blks, step25_node6_factor_num_blks, step25_node7_factor_num_blks, };
int** step25_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, step25_node5_factor_A_blk_start, step25_node6_factor_A_blk_start, step25_node7_factor_A_blk_start, };
int** step25_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, step25_node5_factor_B_blk_start, step25_node6_factor_B_blk_start, step25_node7_factor_B_blk_start, };
int** step25_node_factor_blk_width[] = {0, 0, 0, 0, 0, step25_node5_factor_blk_width, step25_node6_factor_blk_width, step25_node7_factor_blk_width, };
int step25_node_parent[] = {0, 0, 0, 0, 0, step25_node5_parent, step25_node6_parent, step25_node7_parent, };
int step25_node_height[] = {0, 0, 0, 0, 0, step25_node5_height, step25_node6_height, step25_node7_height, };
int step25_node_width[] = {0, 0, 0, 0, 0, step25_node5_width, step25_node6_width, step25_node7_width, };
float* step25_node_data[] = {0, 0, 0, 0, 0, step25_node5_data, step25_node6_data, step25_node7_data, };
int step25_node_num_blks[] = {0, 0, 0, 0, 0, step25_node5_num_blks, step25_node6_num_blks, step25_node7_num_blks, };
int* step25_node_A_blk_start[] = {0, 0, 0, 0, 0, step25_node5_A_blk_start, step25_node6_A_blk_start, step25_node7_A_blk_start, };
int* step25_node_B_blk_start[] = {0, 0, 0, 0, 0, step25_node5_B_blk_start, step25_node6_B_blk_start, step25_node7_B_blk_start, };
int* step25_node_blk_width[] = {0, 0, 0, 0, 0, step25_node5_blk_width, step25_node6_blk_width, step25_node7_blk_width, };
int* step25_node_ridx[] = {step25_node0_ridx, step25_node1_ridx, step25_node2_ridx, step25_node3_ridx, step25_node4_ridx, step25_node5_ridx, step25_node6_ridx, step25_node7_ridx, };


float step25_x_data[157] = {};
const int step25_workspace_needed = 4824;

