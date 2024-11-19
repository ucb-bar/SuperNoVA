#pragma once

const bool step20_is_reconstruct = true;

const int step20_num_threads = 1;

const uint64_t step20_scaled_relin_cost = 0;

const bool step20_run_model = false;

const int step20_factor59_height = 7;
const int step20_factor59_width = 6;
int step20_factor59_ridx[] = {18, 19, 20, 21, 22, 23, 24, };
float step20_factor59_data[42] = {0};

const int step20_factor59_num_blks = 1;
int step20_factor59_A_blk_start[] = {0, };
int step20_factor59_B_blk_start[] = {18, };
int step20_factor59_blk_width[] = {6, };

const int step20_factor60_height = 13;
const int step20_factor60_width = 6;
int step20_factor60_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, };
float step20_factor60_data[78] = {0};

const int step20_factor60_num_blks = 1;
int step20_factor60_A_blk_start[] = {0, };
int step20_factor60_B_blk_start[] = {12, };
int step20_factor60_blk_width[] = {12, };

const int step20_factor53_height = 7;
const int step20_factor53_width = 6;
int step20_factor53_ridx[] = {0, 1, 2, 3, 4, 5, 24, };
float step20_factor53_data[42] = {0};

const int step20_factor53_num_blks = 1;
int step20_factor53_A_blk_start[] = {0, };
int step20_factor53_B_blk_start[] = {0, };
int step20_factor53_blk_width[] = {6, };

const int step20_factor54_height = 13;
const int step20_factor54_width = 6;
int step20_factor54_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step20_factor54_data[78] = {0};

const int step20_factor54_num_blks = 1;
int step20_factor54_A_blk_start[] = {0, };
int step20_factor54_B_blk_start[] = {18, };
int step20_factor54_blk_width[] = {12, };

const int step20_factor55_height = 7;
const int step20_factor55_width = 6;
int step20_factor55_ridx[] = {6, 7, 8, 9, 10, 11, 24, };
float step20_factor55_data[42] = {0};

const int step20_factor55_num_blks = 1;
int step20_factor55_A_blk_start[] = {0, };
int step20_factor55_B_blk_start[] = {6, };
int step20_factor55_blk_width[] = {6, };

const int step20_factor56_height = 13;
const int step20_factor56_width = 6;
int step20_factor56_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 24, };
float step20_factor56_data[78] = {0};

const int step20_factor56_num_blks = 1;
int step20_factor56_A_blk_start[] = {0, };
int step20_factor56_B_blk_start[] = {0, };
int step20_factor56_blk_width[] = {12, };

const int step20_factor57_height = 7;
const int step20_factor57_width = 6;
int step20_factor57_ridx[] = {12, 13, 14, 15, 16, 17, 24, };
float step20_factor57_data[42] = {0};

const int step20_factor57_num_blks = 1;
int step20_factor57_A_blk_start[] = {0, };
int step20_factor57_B_blk_start[] = {12, };
int step20_factor57_blk_width[] = {6, };

const int step20_factor58_height = 13;
const int step20_factor58_width = 6;
int step20_factor58_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 24, };
float step20_factor58_data[78] = {0};

const int step20_factor58_num_blks = 1;
int step20_factor58_A_blk_start[] = {0, };
int step20_factor58_B_blk_start[] = {6, };
int step20_factor58_blk_width[] = {12, };

const int step20_node3_num_factors = 1;
const int step20_node3_relin_cost = 0;
const int step20_node3_sym_cost = 16000;
const bool step20_node3_marked = false;
const bool step20_node3_fixed = true;
int step20_node3_factor_height[] = {step20_factor54_height, };
int step20_node3_factor_width[] = {step20_factor54_width, };
int* step20_node3_factor_ridx[] = {step20_factor54_ridx, };
float* step20_node3_factor_data[] = {step20_factor54_data, };
int step20_node3_factor_num_blks[] = {step20_factor54_num_blks, };
int* step20_node3_factor_A_blk_start[] = {step20_factor54_A_blk_start, };
int* step20_node3_factor_B_blk_start[] = {step20_factor54_B_blk_start, };
int* step20_node3_factor_blk_width[] = {step20_factor54_blk_width, };
const int step20_node3_parent = 4;
const int step20_node3_height = 31;
const int step20_node3_width = 24;
float step20_node3_data[744] = {0};
const int step20_node3_num_blks = 1;
int step20_node3_A_blk_start[] = {0, };
int step20_node3_B_blk_start[] = {0, };
int step20_node3_blk_width[] = {6, };


const int step20_node4_num_factors = 7;
const int step20_node4_relin_cost = 0;
const int step20_node4_sym_cost = 16000;
const bool step20_node4_marked = true;
const bool step20_node4_fixed = false;
int step20_node4_factor_height[] = {step20_factor53_height, step20_factor55_height, step20_factor56_height, step20_factor57_height, step20_factor58_height, step20_factor59_height, step20_factor60_height, };
int step20_node4_factor_width[] = {step20_factor53_width, step20_factor55_width, step20_factor56_width, step20_factor57_width, step20_factor58_width, step20_factor59_width, step20_factor60_width, };
int* step20_node4_factor_ridx[] = {step20_factor53_ridx, step20_factor55_ridx, step20_factor56_ridx, step20_factor57_ridx, step20_factor58_ridx, step20_factor59_ridx, step20_factor60_ridx, };
float* step20_node4_factor_data[] = {step20_factor53_data, step20_factor55_data, step20_factor56_data, step20_factor57_data, step20_factor58_data, step20_factor59_data, step20_factor60_data, };
int step20_node4_factor_num_blks[] = {step20_factor53_num_blks, step20_factor55_num_blks, step20_factor56_num_blks, step20_factor57_num_blks, step20_factor58_num_blks, step20_factor59_num_blks, step20_factor60_num_blks, };
int* step20_node4_factor_A_blk_start[] = {step20_factor53_A_blk_start, step20_factor55_A_blk_start, step20_factor56_A_blk_start, step20_factor57_A_blk_start, step20_factor58_A_blk_start, step20_factor59_A_blk_start, step20_factor60_A_blk_start, };
int* step20_node4_factor_B_blk_start[] = {step20_factor53_B_blk_start, step20_factor55_B_blk_start, step20_factor56_B_blk_start, step20_factor57_B_blk_start, step20_factor58_B_blk_start, step20_factor59_B_blk_start, step20_factor60_B_blk_start, };
int* step20_node4_factor_blk_width[] = {step20_factor53_blk_width, step20_factor55_blk_width, step20_factor56_blk_width, step20_factor57_blk_width, step20_factor58_blk_width, step20_factor59_blk_width, step20_factor60_blk_width, };
const int step20_node4_parent = 5;
const int step20_node4_height = 25;
const int step20_node4_width = 24;
float step20_node4_data[600] = {0};
const int step20_node4_num_blks = 0;
int step20_node4_A_blk_start[] = {};
int step20_node4_B_blk_start[] = {};
int step20_node4_blk_width[] = {};


const int step20_node5_num_factors = 0;
const int step20_node5_relin_cost = 0;
const int step20_node5_sym_cost = 4000;
const bool step20_node5_marked = true;
const bool step20_node5_fixed = false;
int step20_node5_factor_height[] = {};
int step20_node5_factor_width[] = {};
int* step20_node5_factor_ridx[] = {};
float* step20_node5_factor_data[] = {};
int step20_node5_factor_num_blks[] = {};
int* step20_node5_factor_A_blk_start[] = {};
int* step20_node5_factor_B_blk_start[] = {};
int* step20_node5_factor_blk_width[] = {};
const int step20_node5_parent = -1;
const int step20_node5_height = 1;
const int step20_node5_width = 1;
float step20_node5_data[1] = {0};
const int step20_node5_num_blks = 0;
int step20_node5_A_blk_start[] = {};
int step20_node5_B_blk_start[] = {};
int step20_node5_blk_width[] = {};


int step20_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 126, };
int step20_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 126, };
int step20_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 126, };
int step20_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 126, };
int step20_node4_ridx[] = {
102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, };
int step20_node5_ridx[] = {
126, };
const int step20_nnodes = 6;
bool step20_node_marked[] = {false, false, false, step20_node3_marked, step20_node4_marked, step20_node5_marked, };
bool step20_node_fixed[] = {false, false, false, step20_node3_fixed, step20_node4_fixed, step20_node5_fixed, };
int step20_node_num_factors[] = {0, 0, 0, step20_node3_num_factors, step20_node4_num_factors, step20_node5_num_factors, };
int step20_node_relin_cost[] = {0, 0, 0, step20_node3_relin_cost, step20_node4_relin_cost, step20_node5_relin_cost, };
int step20_node_sym_cost[] = {0, 0, 0, step20_node3_sym_cost, step20_node4_sym_cost, step20_node5_sym_cost, };
int* step20_node_factor_height[] = {0, 0, 0, step20_node3_factor_height, step20_node4_factor_height, step20_node5_factor_height, };
int* step20_node_factor_width[] = {0, 0, 0, step20_node3_factor_width, step20_node4_factor_width, step20_node5_factor_width, };
int** step20_node_factor_ridx[] = {0, 0, 0, step20_node3_factor_ridx, step20_node4_factor_ridx, step20_node5_factor_ridx, };
float** step20_node_factor_data[] = {0, 0, 0, step20_node3_factor_data, step20_node4_factor_data, step20_node5_factor_data, };
int* step20_node_factor_num_blks[] = {0, 0, 0, step20_node3_factor_num_blks, step20_node4_factor_num_blks, step20_node5_factor_num_blks, };
int** step20_node_factor_A_blk_start[] = {0, 0, 0, step20_node3_factor_A_blk_start, step20_node4_factor_A_blk_start, step20_node5_factor_A_blk_start, };
int** step20_node_factor_B_blk_start[] = {0, 0, 0, step20_node3_factor_B_blk_start, step20_node4_factor_B_blk_start, step20_node5_factor_B_blk_start, };
int** step20_node_factor_blk_width[] = {0, 0, 0, step20_node3_factor_blk_width, step20_node4_factor_blk_width, step20_node5_factor_blk_width, };
int step20_node_parent[] = {0, 0, 0, step20_node3_parent, step20_node4_parent, step20_node5_parent, };
int step20_node_height[] = {0, 0, 0, step20_node3_height, step20_node4_height, step20_node5_height, };
int step20_node_width[] = {0, 0, 0, step20_node3_width, step20_node4_width, step20_node5_width, };
float* step20_node_data[] = {0, 0, 0, step20_node3_data, step20_node4_data, step20_node5_data, };
int step20_node_num_blks[] = {0, 0, 0, step20_node3_num_blks, step20_node4_num_blks, step20_node5_num_blks, };
int* step20_node_A_blk_start[] = {0, 0, 0, step20_node3_A_blk_start, step20_node4_A_blk_start, step20_node5_A_blk_start, };
int* step20_node_B_blk_start[] = {0, 0, 0, step20_node3_B_blk_start, step20_node4_B_blk_start, step20_node5_B_blk_start, };
int* step20_node_blk_width[] = {0, 0, 0, step20_node3_blk_width, step20_node4_blk_width, step20_node5_blk_width, };
int* step20_node_ridx[] = {step20_node0_ridx, step20_node1_ridx, step20_node2_ridx, step20_node3_ridx, step20_node4_ridx, step20_node5_ridx, };


float step20_x_data[127] = {};
const int step20_workspace_needed = 6648;

