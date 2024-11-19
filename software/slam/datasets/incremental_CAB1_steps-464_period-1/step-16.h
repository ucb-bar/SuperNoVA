#pragma once

const bool step16_is_reconstruct = true;

const int step16_num_threads = 1;

const uint64_t step16_scaled_relin_cost = 0;

const bool step16_run_model = false;

const int step16_factor49_height = 7;
const int step16_factor49_width = 6;
int step16_factor49_ridx[] = {12, 13, 14, 15, 16, 17, 24, };
float step16_factor49_data[42] = {0};

const int step16_factor49_num_blks = 1;
int step16_factor49_A_blk_start[] = {0, };
int step16_factor49_B_blk_start[] = {12, };
int step16_factor49_blk_width[] = {6, };

const int step16_factor50_height = 13;
const int step16_factor50_width = 6;
int step16_factor50_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 24, };
float step16_factor50_data[78] = {0};

const int step16_factor50_num_blks = 1;
int step16_factor50_A_blk_start[] = {0, };
int step16_factor50_B_blk_start[] = {6, };
int step16_factor50_blk_width[] = {12, };

const int step16_factor51_height = 7;
const int step16_factor51_width = 6;
int step16_factor51_ridx[] = {18, 19, 20, 21, 22, 23, 24, };
float step16_factor51_data[42] = {0};

const int step16_factor51_num_blks = 1;
int step16_factor51_A_blk_start[] = {0, };
int step16_factor51_B_blk_start[] = {18, };
int step16_factor51_blk_width[] = {6, };

const int step16_factor52_height = 13;
const int step16_factor52_width = 6;
int step16_factor52_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, };
float step16_factor52_data[78] = {0};

const int step16_factor52_num_blks = 1;
int step16_factor52_A_blk_start[] = {0, };
int step16_factor52_B_blk_start[] = {12, };
int step16_factor52_blk_width[] = {12, };

const int step16_factor45_height = 7;
const int step16_factor45_width = 6;
int step16_factor45_ridx[] = {0, 1, 2, 3, 4, 5, 24, };
float step16_factor45_data[42] = {0};

const int step16_factor45_num_blks = 1;
int step16_factor45_A_blk_start[] = {0, };
int step16_factor45_B_blk_start[] = {0, };
int step16_factor45_blk_width[] = {6, };

const int step16_factor46_height = 13;
const int step16_factor46_width = 6;
int step16_factor46_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step16_factor46_data[78] = {0};

const int step16_factor46_num_blks = 1;
int step16_factor46_A_blk_start[] = {0, };
int step16_factor46_B_blk_start[] = {18, };
int step16_factor46_blk_width[] = {12, };

const int step16_factor47_height = 7;
const int step16_factor47_width = 6;
int step16_factor47_ridx[] = {6, 7, 8, 9, 10, 11, 24, };
float step16_factor47_data[42] = {0};

const int step16_factor47_num_blks = 1;
int step16_factor47_A_blk_start[] = {0, };
int step16_factor47_B_blk_start[] = {6, };
int step16_factor47_blk_width[] = {6, };

const int step16_factor48_height = 13;
const int step16_factor48_width = 6;
int step16_factor48_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 24, };
float step16_factor48_data[78] = {0};

const int step16_factor48_num_blks = 1;
int step16_factor48_A_blk_start[] = {0, };
int step16_factor48_B_blk_start[] = {0, };
int step16_factor48_blk_width[] = {12, };

const int step16_node2_num_factors = 1;
const int step16_node2_relin_cost = 30000;
const bool step16_node2_marked = false;
const bool step16_node2_fixed = true;
int step16_node2_factor_height[] = {step16_factor46_height, };
int step16_node2_factor_width[] = {step16_factor46_width, };
int* step16_node2_factor_ridx[] = {step16_factor46_ridx, };
float* step16_node2_factor_data[] = {step16_factor46_data, };
int step16_node2_factor_num_blks[] = {step16_factor46_num_blks, };
int* step16_node2_factor_A_blk_start[] = {step16_factor46_A_blk_start, };
int* step16_node2_factor_B_blk_start[] = {step16_factor46_B_blk_start, };
int* step16_node2_factor_blk_width[] = {step16_factor46_blk_width, };
const int step16_node2_parent = 3;
const int step16_node2_height = 31;
const int step16_node2_width = 24;
float step16_node2_data[744] = {0};
const int step16_node2_num_blks = 1;
int step16_node2_A_blk_start[] = {0, };
int step16_node2_B_blk_start[] = {0, };
int step16_node2_blk_width[] = {6, };


const int step16_node3_num_factors = 7;
const int step16_node3_relin_cost = 210000;
const bool step16_node3_marked = true;
const bool step16_node3_fixed = false;
int step16_node3_factor_height[] = {step16_factor45_height, step16_factor47_height, step16_factor48_height, step16_factor49_height, step16_factor50_height, step16_factor51_height, step16_factor52_height, };
int step16_node3_factor_width[] = {step16_factor45_width, step16_factor47_width, step16_factor48_width, step16_factor49_width, step16_factor50_width, step16_factor51_width, step16_factor52_width, };
int* step16_node3_factor_ridx[] = {step16_factor45_ridx, step16_factor47_ridx, step16_factor48_ridx, step16_factor49_ridx, step16_factor50_ridx, step16_factor51_ridx, step16_factor52_ridx, };
float* step16_node3_factor_data[] = {step16_factor45_data, step16_factor47_data, step16_factor48_data, step16_factor49_data, step16_factor50_data, step16_factor51_data, step16_factor52_data, };
int step16_node3_factor_num_blks[] = {step16_factor45_num_blks, step16_factor47_num_blks, step16_factor48_num_blks, step16_factor49_num_blks, step16_factor50_num_blks, step16_factor51_num_blks, step16_factor52_num_blks, };
int* step16_node3_factor_A_blk_start[] = {step16_factor45_A_blk_start, step16_factor47_A_blk_start, step16_factor48_A_blk_start, step16_factor49_A_blk_start, step16_factor50_A_blk_start, step16_factor51_A_blk_start, step16_factor52_A_blk_start, };
int* step16_node3_factor_B_blk_start[] = {step16_factor45_B_blk_start, step16_factor47_B_blk_start, step16_factor48_B_blk_start, step16_factor49_B_blk_start, step16_factor50_B_blk_start, step16_factor51_B_blk_start, step16_factor52_B_blk_start, };
int* step16_node3_factor_blk_width[] = {step16_factor45_blk_width, step16_factor47_blk_width, step16_factor48_blk_width, step16_factor49_blk_width, step16_factor50_blk_width, step16_factor51_blk_width, step16_factor52_blk_width, };
const int step16_node3_parent = 4;
const int step16_node3_height = 25;
const int step16_node3_width = 24;
float step16_node3_data[600] = {0};
const int step16_node3_num_blks = 0;
int step16_node3_A_blk_start[] = {};
int step16_node3_B_blk_start[] = {};
int step16_node3_blk_width[] = {};


const int step16_node4_num_factors = 0;
const int step16_node4_relin_cost = 0;
const bool step16_node4_marked = true;
const bool step16_node4_fixed = false;
int step16_node4_factor_height[] = {};
int step16_node4_factor_width[] = {};
int* step16_node4_factor_ridx[] = {};
float* step16_node4_factor_data[] = {};
int step16_node4_factor_num_blks[] = {};
int* step16_node4_factor_A_blk_start[] = {};
int* step16_node4_factor_B_blk_start[] = {};
int* step16_node4_factor_blk_width[] = {};
const int step16_node4_parent = -1;
const int step16_node4_height = 1;
const int step16_node4_width = 1;
float step16_node4_data[1] = {0};
const int step16_node4_num_blks = 0;
int step16_node4_A_blk_start[] = {};
int step16_node4_B_blk_start[] = {};
int step16_node4_blk_width[] = {};


int step16_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 102, };
int step16_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 102, };
int step16_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 102, };
int step16_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, };
int step16_node4_ridx[] = {
102, };
const int step16_nnodes = 5;
bool step16_node_marked[] = {false, false, step16_node2_marked, step16_node3_marked, step16_node4_marked, };
bool step16_node_fixed[] = {false, false, step16_node2_fixed, step16_node3_fixed, step16_node4_fixed, };
int step16_node_num_factors[] = {0, 0, step16_node2_num_factors, step16_node3_num_factors, step16_node4_num_factors, };
int step16_node_relin_cost[] = {0, 0, step16_node2_relin_cost, step16_node3_relin_cost, step16_node4_relin_cost, };
int* step16_node_factor_height[] = {0, 0, step16_node2_factor_height, step16_node3_factor_height, step16_node4_factor_height, };
int* step16_node_factor_width[] = {0, 0, step16_node2_factor_width, step16_node3_factor_width, step16_node4_factor_width, };
int** step16_node_factor_ridx[] = {0, 0, step16_node2_factor_ridx, step16_node3_factor_ridx, step16_node4_factor_ridx, };
float** step16_node_factor_data[] = {0, 0, step16_node2_factor_data, step16_node3_factor_data, step16_node4_factor_data, };
int* step16_node_factor_num_blks[] = {0, 0, step16_node2_factor_num_blks, step16_node3_factor_num_blks, step16_node4_factor_num_blks, };
int** step16_node_factor_A_blk_start[] = {0, 0, step16_node2_factor_A_blk_start, step16_node3_factor_A_blk_start, step16_node4_factor_A_blk_start, };
int** step16_node_factor_B_blk_start[] = {0, 0, step16_node2_factor_B_blk_start, step16_node3_factor_B_blk_start, step16_node4_factor_B_blk_start, };
int** step16_node_factor_blk_width[] = {0, 0, step16_node2_factor_blk_width, step16_node3_factor_blk_width, step16_node4_factor_blk_width, };
int step16_node_parent[] = {0, 0, step16_node2_parent, step16_node3_parent, step16_node4_parent, };
int step16_node_height[] = {0, 0, step16_node2_height, step16_node3_height, step16_node4_height, };
int step16_node_width[] = {0, 0, step16_node2_width, step16_node3_width, step16_node4_width, };
float* step16_node_data[] = {0, 0, step16_node2_data, step16_node3_data, step16_node4_data, };
int step16_node_num_blks[] = {0, 0, step16_node2_num_blks, step16_node3_num_blks, step16_node4_num_blks, };
int* step16_node_A_blk_start[] = {0, 0, step16_node2_A_blk_start, step16_node3_A_blk_start, step16_node4_A_blk_start, };
int* step16_node_B_blk_start[] = {0, 0, step16_node2_B_blk_start, step16_node3_B_blk_start, step16_node4_B_blk_start, };
int* step16_node_blk_width[] = {0, 0, step16_node2_blk_width, step16_node3_blk_width, step16_node4_blk_width, };
int* step16_node_ridx[] = {step16_node0_ridx, step16_node1_ridx, step16_node2_ridx, step16_node3_ridx, step16_node4_ridx, };


float step16_x_data[103] = {};
const int step16_workspace_needed = 6648;

