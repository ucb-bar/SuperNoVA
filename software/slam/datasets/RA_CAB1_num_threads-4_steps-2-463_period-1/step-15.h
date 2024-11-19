#pragma once

const bool step15_is_reconstruct = true;

const int step15_num_threads = 1;

const uint64_t step15_scaled_relin_cost = 0;

const bool step15_run_model = false;

const int step15_factor46_height = 13;
const int step15_factor46_width = 6;
int step15_factor46_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step15_factor46_data[78] = {0};

const int step15_factor46_num_blks = 1;
int step15_factor46_A_blk_start[] = {0, };
int step15_factor46_B_blk_start[] = {18, };
int step15_factor46_blk_width[] = {12, };

const int step15_factor47_height = 7;
const int step15_factor47_width = 6;
int step15_factor47_ridx[] = {6, 7, 8, 9, 10, 11, 18, };
float step15_factor47_data[42] = {0};

const int step15_factor47_num_blks = 1;
int step15_factor47_A_blk_start[] = {0, };
int step15_factor47_B_blk_start[] = {6, };
int step15_factor47_blk_width[] = {6, };

const int step15_factor48_height = 13;
const int step15_factor48_width = 6;
int step15_factor48_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 18, };
float step15_factor48_data[78] = {0};

const int step15_factor48_num_blks = 1;
int step15_factor48_A_blk_start[] = {0, };
int step15_factor48_B_blk_start[] = {0, };
int step15_factor48_blk_width[] = {12, };

const int step15_factor49_height = 7;
const int step15_factor49_width = 6;
int step15_factor49_ridx[] = {12, 13, 14, 15, 16, 17, 18, };
float step15_factor49_data[42] = {0};

const int step15_factor49_num_blks = 1;
int step15_factor49_A_blk_start[] = {0, };
int step15_factor49_B_blk_start[] = {12, };
int step15_factor49_blk_width[] = {6, };

const int step15_factor50_height = 13;
const int step15_factor50_width = 6;
int step15_factor50_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, };
float step15_factor50_data[78] = {0};

const int step15_factor50_num_blks = 1;
int step15_factor50_A_blk_start[] = {0, };
int step15_factor50_B_blk_start[] = {6, };
int step15_factor50_blk_width[] = {12, };

const int step15_factor45_height = 7;
const int step15_factor45_width = 6;
int step15_factor45_ridx[] = {0, 1, 2, 3, 4, 5, 18, };
float step15_factor45_data[42] = {0};

const int step15_factor45_num_blks = 1;
int step15_factor45_A_blk_start[] = {0, };
int step15_factor45_B_blk_start[] = {0, };
int step15_factor45_blk_width[] = {6, };

const int step15_node2_num_factors = 1;
const int step15_node2_relin_cost = 0;
const int step15_node2_sym_cost = 16000;
const bool step15_node2_marked = false;
const bool step15_node2_fixed = true;
int step15_node2_factor_height[] = {step15_factor46_height, };
int step15_node2_factor_width[] = {step15_factor46_width, };
int* step15_node2_factor_ridx[] = {step15_factor46_ridx, };
float* step15_node2_factor_data[] = {step15_factor46_data, };
int step15_node2_factor_num_blks[] = {step15_factor46_num_blks, };
int* step15_node2_factor_A_blk_start[] = {step15_factor46_A_blk_start, };
int* step15_node2_factor_B_blk_start[] = {step15_factor46_B_blk_start, };
int* step15_node2_factor_blk_width[] = {step15_factor46_blk_width, };
const int step15_node2_parent = 3;
const int step15_node2_height = 31;
const int step15_node2_width = 24;
float step15_node2_data[744] = {0};
const int step15_node2_num_blks = 1;
int step15_node2_A_blk_start[] = {0, };
int step15_node2_B_blk_start[] = {0, };
int step15_node2_blk_width[] = {6, };


const int step15_node3_num_factors = 5;
const int step15_node3_relin_cost = 0;
const int step15_node3_sym_cost = 12000;
const bool step15_node3_marked = true;
const bool step15_node3_fixed = false;
int step15_node3_factor_height[] = {step15_factor45_height, step15_factor47_height, step15_factor48_height, step15_factor49_height, step15_factor50_height, };
int step15_node3_factor_width[] = {step15_factor45_width, step15_factor47_width, step15_factor48_width, step15_factor49_width, step15_factor50_width, };
int* step15_node3_factor_ridx[] = {step15_factor45_ridx, step15_factor47_ridx, step15_factor48_ridx, step15_factor49_ridx, step15_factor50_ridx, };
float* step15_node3_factor_data[] = {step15_factor45_data, step15_factor47_data, step15_factor48_data, step15_factor49_data, step15_factor50_data, };
int step15_node3_factor_num_blks[] = {step15_factor45_num_blks, step15_factor47_num_blks, step15_factor48_num_blks, step15_factor49_num_blks, step15_factor50_num_blks, };
int* step15_node3_factor_A_blk_start[] = {step15_factor45_A_blk_start, step15_factor47_A_blk_start, step15_factor48_A_blk_start, step15_factor49_A_blk_start, step15_factor50_A_blk_start, };
int* step15_node3_factor_B_blk_start[] = {step15_factor45_B_blk_start, step15_factor47_B_blk_start, step15_factor48_B_blk_start, step15_factor49_B_blk_start, step15_factor50_B_blk_start, };
int* step15_node3_factor_blk_width[] = {step15_factor45_blk_width, step15_factor47_blk_width, step15_factor48_blk_width, step15_factor49_blk_width, step15_factor50_blk_width, };
const int step15_node3_parent = 4;
const int step15_node3_height = 19;
const int step15_node3_width = 18;
float step15_node3_data[342] = {0};
const int step15_node3_num_blks = 0;
int step15_node3_A_blk_start[] = {};
int step15_node3_B_blk_start[] = {};
int step15_node3_blk_width[] = {};


const int step15_node4_num_factors = 0;
const int step15_node4_relin_cost = 0;
const int step15_node4_sym_cost = 4000;
const bool step15_node4_marked = true;
const bool step15_node4_fixed = false;
int step15_node4_factor_height[] = {};
int step15_node4_factor_width[] = {};
int* step15_node4_factor_ridx[] = {};
float* step15_node4_factor_data[] = {};
int step15_node4_factor_num_blks[] = {};
int* step15_node4_factor_A_blk_start[] = {};
int* step15_node4_factor_B_blk_start[] = {};
int* step15_node4_factor_blk_width[] = {};
const int step15_node4_parent = -1;
const int step15_node4_height = 1;
const int step15_node4_width = 1;
float step15_node4_data[1] = {0};
const int step15_node4_num_blks = 0;
int step15_node4_A_blk_start[] = {};
int step15_node4_B_blk_start[] = {};
int step15_node4_blk_width[] = {};


int step15_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 96, };
int step15_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 96, };
int step15_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 96, };
int step15_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, };
int step15_node4_ridx[] = {
96, };
const int step15_nnodes = 5;
bool step15_node_marked[] = {false, false, step15_node2_marked, step15_node3_marked, step15_node4_marked, };
bool step15_node_fixed[] = {false, false, step15_node2_fixed, step15_node3_fixed, step15_node4_fixed, };
int step15_node_num_factors[] = {0, 0, step15_node2_num_factors, step15_node3_num_factors, step15_node4_num_factors, };
int step15_node_relin_cost[] = {0, 0, step15_node2_relin_cost, step15_node3_relin_cost, step15_node4_relin_cost, };
int step15_node_sym_cost[] = {0, 0, step15_node2_sym_cost, step15_node3_sym_cost, step15_node4_sym_cost, };
int* step15_node_factor_height[] = {0, 0, step15_node2_factor_height, step15_node3_factor_height, step15_node4_factor_height, };
int* step15_node_factor_width[] = {0, 0, step15_node2_factor_width, step15_node3_factor_width, step15_node4_factor_width, };
int** step15_node_factor_ridx[] = {0, 0, step15_node2_factor_ridx, step15_node3_factor_ridx, step15_node4_factor_ridx, };
float** step15_node_factor_data[] = {0, 0, step15_node2_factor_data, step15_node3_factor_data, step15_node4_factor_data, };
int* step15_node_factor_num_blks[] = {0, 0, step15_node2_factor_num_blks, step15_node3_factor_num_blks, step15_node4_factor_num_blks, };
int** step15_node_factor_A_blk_start[] = {0, 0, step15_node2_factor_A_blk_start, step15_node3_factor_A_blk_start, step15_node4_factor_A_blk_start, };
int** step15_node_factor_B_blk_start[] = {0, 0, step15_node2_factor_B_blk_start, step15_node3_factor_B_blk_start, step15_node4_factor_B_blk_start, };
int** step15_node_factor_blk_width[] = {0, 0, step15_node2_factor_blk_width, step15_node3_factor_blk_width, step15_node4_factor_blk_width, };
int step15_node_parent[] = {0, 0, step15_node2_parent, step15_node3_parent, step15_node4_parent, };
int step15_node_height[] = {0, 0, step15_node2_height, step15_node3_height, step15_node4_height, };
int step15_node_width[] = {0, 0, step15_node2_width, step15_node3_width, step15_node4_width, };
float* step15_node_data[] = {0, 0, step15_node2_data, step15_node3_data, step15_node4_data, };
int step15_node_num_blks[] = {0, 0, step15_node2_num_blks, step15_node3_num_blks, step15_node4_num_blks, };
int* step15_node_A_blk_start[] = {0, 0, step15_node2_A_blk_start, step15_node3_A_blk_start, step15_node4_A_blk_start, };
int* step15_node_B_blk_start[] = {0, 0, step15_node2_B_blk_start, step15_node3_B_blk_start, step15_node4_B_blk_start, };
int* step15_node_blk_width[] = {0, 0, step15_node2_blk_width, step15_node3_blk_width, step15_node4_blk_width, };
int* step15_node_ridx[] = {step15_node0_ridx, step15_node1_ridx, step15_node2_ridx, step15_node3_ridx, step15_node4_ridx, };


float step15_x_data[97] = {};
const int step15_workspace_needed = 5592;

