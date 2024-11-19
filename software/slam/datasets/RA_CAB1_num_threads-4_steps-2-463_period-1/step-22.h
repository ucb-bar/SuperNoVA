#pragma once

const bool step22_is_reconstruct = true;

const int step22_num_threads = 1;

const uint64_t step22_scaled_relin_cost = 0;

const bool step22_run_model = false;

const int step22_factor63_height = 7;
const int step22_factor63_width = 6;
int step22_factor63_ridx[] = {6, 7, 8, 9, 10, 11, 12, };
float step22_factor63_data[42] = {0};

const int step22_factor63_num_blks = 1;
int step22_factor63_A_blk_start[] = {0, };
int step22_factor63_B_blk_start[] = {6, };
int step22_factor63_blk_width[] = {6, };

const int step22_factor61_height = 7;
const int step22_factor61_width = 6;
int step22_factor61_ridx[] = {0, 1, 2, 3, 4, 5, 12, };
float step22_factor61_data[42] = {0};

const int step22_factor61_num_blks = 1;
int step22_factor61_A_blk_start[] = {0, };
int step22_factor61_B_blk_start[] = {0, };
int step22_factor61_blk_width[] = {6, };

const int step22_factor64_height = 13;
const int step22_factor64_width = 6;
int step22_factor64_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, };
float step22_factor64_data[78] = {0};

const int step22_factor64_num_blks = 1;
int step22_factor64_A_blk_start[] = {0, };
int step22_factor64_B_blk_start[] = {0, };
int step22_factor64_blk_width[] = {12, };

const int step22_factor62_height = 13;
const int step22_factor62_width = 6;
int step22_factor62_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step22_factor62_data[78] = {0};

const int step22_factor62_num_blks = 1;
int step22_factor62_A_blk_start[] = {0, };
int step22_factor62_B_blk_start[] = {18, };
int step22_factor62_blk_width[] = {12, };

const int step22_node4_num_factors = 1;
const int step22_node4_relin_cost = 0;
const int step22_node4_sym_cost = 16000;
const bool step22_node4_marked = false;
const bool step22_node4_fixed = true;
int step22_node4_factor_height[] = {step22_factor62_height, };
int step22_node4_factor_width[] = {step22_factor62_width, };
int* step22_node4_factor_ridx[] = {step22_factor62_ridx, };
float* step22_node4_factor_data[] = {step22_factor62_data, };
int step22_node4_factor_num_blks[] = {step22_factor62_num_blks, };
int* step22_node4_factor_A_blk_start[] = {step22_factor62_A_blk_start, };
int* step22_node4_factor_B_blk_start[] = {step22_factor62_B_blk_start, };
int* step22_node4_factor_blk_width[] = {step22_factor62_blk_width, };
const int step22_node4_parent = 5;
const int step22_node4_height = 31;
const int step22_node4_width = 24;
float step22_node4_data[744] = {0};
const int step22_node4_num_blks = 1;
int step22_node4_A_blk_start[] = {0, };
int step22_node4_B_blk_start[] = {0, };
int step22_node4_blk_width[] = {6, };


const int step22_node5_num_factors = 3;
const int step22_node5_relin_cost = 0;
const int step22_node5_sym_cost = 8000;
const bool step22_node5_marked = true;
const bool step22_node5_fixed = false;
int step22_node5_factor_height[] = {step22_factor61_height, step22_factor63_height, step22_factor64_height, };
int step22_node5_factor_width[] = {step22_factor61_width, step22_factor63_width, step22_factor64_width, };
int* step22_node5_factor_ridx[] = {step22_factor61_ridx, step22_factor63_ridx, step22_factor64_ridx, };
float* step22_node5_factor_data[] = {step22_factor61_data, step22_factor63_data, step22_factor64_data, };
int step22_node5_factor_num_blks[] = {step22_factor61_num_blks, step22_factor63_num_blks, step22_factor64_num_blks, };
int* step22_node5_factor_A_blk_start[] = {step22_factor61_A_blk_start, step22_factor63_A_blk_start, step22_factor64_A_blk_start, };
int* step22_node5_factor_B_blk_start[] = {step22_factor61_B_blk_start, step22_factor63_B_blk_start, step22_factor64_B_blk_start, };
int* step22_node5_factor_blk_width[] = {step22_factor61_blk_width, step22_factor63_blk_width, step22_factor64_blk_width, };
const int step22_node5_parent = 6;
const int step22_node5_height = 13;
const int step22_node5_width = 12;
float step22_node5_data[156] = {0};
const int step22_node5_num_blks = 0;
int step22_node5_A_blk_start[] = {};
int step22_node5_B_blk_start[] = {};
int step22_node5_blk_width[] = {};


const int step22_node6_num_factors = 0;
const int step22_node6_relin_cost = 0;
const int step22_node6_sym_cost = 4000;
const bool step22_node6_marked = true;
const bool step22_node6_fixed = false;
int step22_node6_factor_height[] = {};
int step22_node6_factor_width[] = {};
int* step22_node6_factor_ridx[] = {};
float* step22_node6_factor_data[] = {};
int step22_node6_factor_num_blks[] = {};
int* step22_node6_factor_A_blk_start[] = {};
int* step22_node6_factor_B_blk_start[] = {};
int* step22_node6_factor_blk_width[] = {};
const int step22_node6_parent = -1;
const int step22_node6_height = 1;
const int step22_node6_width = 1;
float step22_node6_data[1] = {0};
const int step22_node6_num_blks = 0;
int step22_node6_A_blk_start[] = {};
int step22_node6_B_blk_start[] = {};
int step22_node6_blk_width[] = {};


int step22_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 138, };
int step22_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 138, };
int step22_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 138, };
int step22_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 138, };
int step22_node4_ridx[] = {
102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 138, };
int step22_node5_ridx[] = {
126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, };
int step22_node6_ridx[] = {
138, };
const int step22_nnodes = 7;
bool step22_node_marked[] = {false, false, false, false, step22_node4_marked, step22_node5_marked, step22_node6_marked, };
bool step22_node_fixed[] = {false, false, false, false, step22_node4_fixed, step22_node5_fixed, step22_node6_fixed, };
int step22_node_num_factors[] = {0, 0, 0, 0, step22_node4_num_factors, step22_node5_num_factors, step22_node6_num_factors, };
int step22_node_relin_cost[] = {0, 0, 0, 0, step22_node4_relin_cost, step22_node5_relin_cost, step22_node6_relin_cost, };
int step22_node_sym_cost[] = {0, 0, 0, 0, step22_node4_sym_cost, step22_node5_sym_cost, step22_node6_sym_cost, };
int* step22_node_factor_height[] = {0, 0, 0, 0, step22_node4_factor_height, step22_node5_factor_height, step22_node6_factor_height, };
int* step22_node_factor_width[] = {0, 0, 0, 0, step22_node4_factor_width, step22_node5_factor_width, step22_node6_factor_width, };
int** step22_node_factor_ridx[] = {0, 0, 0, 0, step22_node4_factor_ridx, step22_node5_factor_ridx, step22_node6_factor_ridx, };
float** step22_node_factor_data[] = {0, 0, 0, 0, step22_node4_factor_data, step22_node5_factor_data, step22_node6_factor_data, };
int* step22_node_factor_num_blks[] = {0, 0, 0, 0, step22_node4_factor_num_blks, step22_node5_factor_num_blks, step22_node6_factor_num_blks, };
int** step22_node_factor_A_blk_start[] = {0, 0, 0, 0, step22_node4_factor_A_blk_start, step22_node5_factor_A_blk_start, step22_node6_factor_A_blk_start, };
int** step22_node_factor_B_blk_start[] = {0, 0, 0, 0, step22_node4_factor_B_blk_start, step22_node5_factor_B_blk_start, step22_node6_factor_B_blk_start, };
int** step22_node_factor_blk_width[] = {0, 0, 0, 0, step22_node4_factor_blk_width, step22_node5_factor_blk_width, step22_node6_factor_blk_width, };
int step22_node_parent[] = {0, 0, 0, 0, step22_node4_parent, step22_node5_parent, step22_node6_parent, };
int step22_node_height[] = {0, 0, 0, 0, step22_node4_height, step22_node5_height, step22_node6_height, };
int step22_node_width[] = {0, 0, 0, 0, step22_node4_width, step22_node5_width, step22_node6_width, };
float* step22_node_data[] = {0, 0, 0, 0, step22_node4_data, step22_node5_data, step22_node6_data, };
int step22_node_num_blks[] = {0, 0, 0, 0, step22_node4_num_blks, step22_node5_num_blks, step22_node6_num_blks, };
int* step22_node_A_blk_start[] = {0, 0, 0, 0, step22_node4_A_blk_start, step22_node5_A_blk_start, step22_node6_A_blk_start, };
int* step22_node_B_blk_start[] = {0, 0, 0, 0, step22_node4_B_blk_start, step22_node5_B_blk_start, step22_node6_B_blk_start, };
int* step22_node_blk_width[] = {0, 0, 0, 0, step22_node4_blk_width, step22_node5_blk_width, step22_node6_blk_width, };
int* step22_node_ridx[] = {step22_node0_ridx, step22_node1_ridx, step22_node2_ridx, step22_node3_ridx, step22_node4_ridx, step22_node5_ridx, step22_node6_ridx, };


float step22_x_data[139] = {};
const int step22_workspace_needed = 4824;

