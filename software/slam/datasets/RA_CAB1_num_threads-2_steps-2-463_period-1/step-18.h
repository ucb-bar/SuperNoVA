#pragma once

const bool step18_is_reconstruct = true;

const int step18_num_threads = 1;

const uint64_t step18_scaled_relin_cost = 0;

const bool step18_run_model = false;

const int step18_factor54_height = 13;
const int step18_factor54_width = 6;
int step18_factor54_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step18_factor54_data[78] = {0};

const int step18_factor54_num_blks = 1;
int step18_factor54_A_blk_start[] = {0, };
int step18_factor54_B_blk_start[] = {18, };
int step18_factor54_blk_width[] = {12, };

const int step18_factor55_height = 7;
const int step18_factor55_width = 6;
int step18_factor55_ridx[] = {6, 7, 8, 9, 10, 11, 12, };
float step18_factor55_data[42] = {0};

const int step18_factor55_num_blks = 1;
int step18_factor55_A_blk_start[] = {0, };
int step18_factor55_B_blk_start[] = {6, };
int step18_factor55_blk_width[] = {6, };

const int step18_factor53_height = 7;
const int step18_factor53_width = 6;
int step18_factor53_ridx[] = {0, 1, 2, 3, 4, 5, 12, };
float step18_factor53_data[42] = {0};

const int step18_factor53_num_blks = 1;
int step18_factor53_A_blk_start[] = {0, };
int step18_factor53_B_blk_start[] = {0, };
int step18_factor53_blk_width[] = {6, };

const int step18_factor56_height = 13;
const int step18_factor56_width = 6;
int step18_factor56_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, };
float step18_factor56_data[78] = {0};

const int step18_factor56_num_blks = 1;
int step18_factor56_A_blk_start[] = {0, };
int step18_factor56_B_blk_start[] = {0, };
int step18_factor56_blk_width[] = {12, };

const int step18_node3_num_factors = 1;
const int step18_node3_relin_cost = 0;
const int step18_node3_sym_cost = 16000;
const bool step18_node3_marked = false;
const bool step18_node3_fixed = true;
int step18_node3_factor_height[] = {step18_factor54_height, };
int step18_node3_factor_width[] = {step18_factor54_width, };
int* step18_node3_factor_ridx[] = {step18_factor54_ridx, };
float* step18_node3_factor_data[] = {step18_factor54_data, };
int step18_node3_factor_num_blks[] = {step18_factor54_num_blks, };
int* step18_node3_factor_A_blk_start[] = {step18_factor54_A_blk_start, };
int* step18_node3_factor_B_blk_start[] = {step18_factor54_B_blk_start, };
int* step18_node3_factor_blk_width[] = {step18_factor54_blk_width, };
const int step18_node3_parent = 4;
const int step18_node3_height = 31;
const int step18_node3_width = 24;
float step18_node3_data[744] = {0};
const int step18_node3_num_blks = 1;
int step18_node3_A_blk_start[] = {0, };
int step18_node3_B_blk_start[] = {0, };
int step18_node3_blk_width[] = {6, };


const int step18_node4_num_factors = 3;
const int step18_node4_relin_cost = 0;
const int step18_node4_sym_cost = 8000;
const bool step18_node4_marked = true;
const bool step18_node4_fixed = false;
int step18_node4_factor_height[] = {step18_factor53_height, step18_factor55_height, step18_factor56_height, };
int step18_node4_factor_width[] = {step18_factor53_width, step18_factor55_width, step18_factor56_width, };
int* step18_node4_factor_ridx[] = {step18_factor53_ridx, step18_factor55_ridx, step18_factor56_ridx, };
float* step18_node4_factor_data[] = {step18_factor53_data, step18_factor55_data, step18_factor56_data, };
int step18_node4_factor_num_blks[] = {step18_factor53_num_blks, step18_factor55_num_blks, step18_factor56_num_blks, };
int* step18_node4_factor_A_blk_start[] = {step18_factor53_A_blk_start, step18_factor55_A_blk_start, step18_factor56_A_blk_start, };
int* step18_node4_factor_B_blk_start[] = {step18_factor53_B_blk_start, step18_factor55_B_blk_start, step18_factor56_B_blk_start, };
int* step18_node4_factor_blk_width[] = {step18_factor53_blk_width, step18_factor55_blk_width, step18_factor56_blk_width, };
const int step18_node4_parent = 5;
const int step18_node4_height = 13;
const int step18_node4_width = 12;
float step18_node4_data[156] = {0};
const int step18_node4_num_blks = 0;
int step18_node4_A_blk_start[] = {};
int step18_node4_B_blk_start[] = {};
int step18_node4_blk_width[] = {};


const int step18_node5_num_factors = 0;
const int step18_node5_relin_cost = 0;
const int step18_node5_sym_cost = 4000;
const bool step18_node5_marked = true;
const bool step18_node5_fixed = false;
int step18_node5_factor_height[] = {};
int step18_node5_factor_width[] = {};
int* step18_node5_factor_ridx[] = {};
float* step18_node5_factor_data[] = {};
int step18_node5_factor_num_blks[] = {};
int* step18_node5_factor_A_blk_start[] = {};
int* step18_node5_factor_B_blk_start[] = {};
int* step18_node5_factor_blk_width[] = {};
const int step18_node5_parent = -1;
const int step18_node5_height = 1;
const int step18_node5_width = 1;
float step18_node5_data[1] = {0};
const int step18_node5_num_blks = 0;
int step18_node5_A_blk_start[] = {};
int step18_node5_B_blk_start[] = {};
int step18_node5_blk_width[] = {};


int step18_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 114, };
int step18_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 114, };
int step18_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 114, };
int step18_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 114, };
int step18_node4_ridx[] = {
102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, };
int step18_node5_ridx[] = {
114, };
const int step18_nnodes = 6;
bool step18_node_marked[] = {false, false, false, step18_node3_marked, step18_node4_marked, step18_node5_marked, };
bool step18_node_fixed[] = {false, false, false, step18_node3_fixed, step18_node4_fixed, step18_node5_fixed, };
int step18_node_num_factors[] = {0, 0, 0, step18_node3_num_factors, step18_node4_num_factors, step18_node5_num_factors, };
int step18_node_relin_cost[] = {0, 0, 0, step18_node3_relin_cost, step18_node4_relin_cost, step18_node5_relin_cost, };
int step18_node_sym_cost[] = {0, 0, 0, step18_node3_sym_cost, step18_node4_sym_cost, step18_node5_sym_cost, };
int* step18_node_factor_height[] = {0, 0, 0, step18_node3_factor_height, step18_node4_factor_height, step18_node5_factor_height, };
int* step18_node_factor_width[] = {0, 0, 0, step18_node3_factor_width, step18_node4_factor_width, step18_node5_factor_width, };
int** step18_node_factor_ridx[] = {0, 0, 0, step18_node3_factor_ridx, step18_node4_factor_ridx, step18_node5_factor_ridx, };
float** step18_node_factor_data[] = {0, 0, 0, step18_node3_factor_data, step18_node4_factor_data, step18_node5_factor_data, };
int* step18_node_factor_num_blks[] = {0, 0, 0, step18_node3_factor_num_blks, step18_node4_factor_num_blks, step18_node5_factor_num_blks, };
int** step18_node_factor_A_blk_start[] = {0, 0, 0, step18_node3_factor_A_blk_start, step18_node4_factor_A_blk_start, step18_node5_factor_A_blk_start, };
int** step18_node_factor_B_blk_start[] = {0, 0, 0, step18_node3_factor_B_blk_start, step18_node4_factor_B_blk_start, step18_node5_factor_B_blk_start, };
int** step18_node_factor_blk_width[] = {0, 0, 0, step18_node3_factor_blk_width, step18_node4_factor_blk_width, step18_node5_factor_blk_width, };
int step18_node_parent[] = {0, 0, 0, step18_node3_parent, step18_node4_parent, step18_node5_parent, };
int step18_node_height[] = {0, 0, 0, step18_node3_height, step18_node4_height, step18_node5_height, };
int step18_node_width[] = {0, 0, 0, step18_node3_width, step18_node4_width, step18_node5_width, };
float* step18_node_data[] = {0, 0, 0, step18_node3_data, step18_node4_data, step18_node5_data, };
int step18_node_num_blks[] = {0, 0, 0, step18_node3_num_blks, step18_node4_num_blks, step18_node5_num_blks, };
int* step18_node_A_blk_start[] = {0, 0, 0, step18_node3_A_blk_start, step18_node4_A_blk_start, step18_node5_A_blk_start, };
int* step18_node_B_blk_start[] = {0, 0, 0, step18_node3_B_blk_start, step18_node4_B_blk_start, step18_node5_B_blk_start, };
int* step18_node_blk_width[] = {0, 0, 0, step18_node3_blk_width, step18_node4_blk_width, step18_node5_blk_width, };
int* step18_node_ridx[] = {step18_node0_ridx, step18_node1_ridx, step18_node2_ridx, step18_node3_ridx, step18_node4_ridx, step18_node5_ridx, };


float step18_x_data[115] = {};
const int step18_workspace_needed = 4824;

