#pragma once

const bool step17_is_reconstruct = true;

const int step17_num_threads = 1;

const uint64_t step17_scaled_relin_cost = 0;

const bool step17_run_model = false;

const int step17_factor45_height = 7;
const int step17_factor45_width = 6;
int step17_factor45_ridx[] = {0, 1, 2, 3, 4, 5, 30, };
float step17_factor45_data[42] = {0};

const int step17_factor45_num_blks = 1;
int step17_factor45_A_blk_start[] = {0, };
int step17_factor45_B_blk_start[] = {0, };
int step17_factor45_blk_width[] = {6, };

const int step17_factor46_height = 13;
const int step17_factor46_width = 6;
int step17_factor46_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step17_factor46_data[78] = {0};

const int step17_factor46_num_blks = 1;
int step17_factor46_A_blk_start[] = {0, };
int step17_factor46_B_blk_start[] = {18, };
int step17_factor46_blk_width[] = {12, };

const int step17_factor47_height = 7;
const int step17_factor47_width = 6;
int step17_factor47_ridx[] = {6, 7, 8, 9, 10, 11, 30, };
float step17_factor47_data[42] = {0};

const int step17_factor47_num_blks = 1;
int step17_factor47_A_blk_start[] = {0, };
int step17_factor47_B_blk_start[] = {6, };
int step17_factor47_blk_width[] = {6, };

const int step17_factor48_height = 13;
const int step17_factor48_width = 6;
int step17_factor48_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 30, };
float step17_factor48_data[78] = {0};

const int step17_factor48_num_blks = 1;
int step17_factor48_A_blk_start[] = {0, };
int step17_factor48_B_blk_start[] = {0, };
int step17_factor48_blk_width[] = {12, };

const int step17_factor49_height = 7;
const int step17_factor49_width = 6;
int step17_factor49_ridx[] = {12, 13, 14, 15, 16, 17, 30, };
float step17_factor49_data[42] = {0};

const int step17_factor49_num_blks = 1;
int step17_factor49_A_blk_start[] = {0, };
int step17_factor49_B_blk_start[] = {12, };
int step17_factor49_blk_width[] = {6, };

const int step17_factor50_height = 13;
const int step17_factor50_width = 6;
int step17_factor50_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 30, };
float step17_factor50_data[78] = {0};

const int step17_factor50_num_blks = 1;
int step17_factor50_A_blk_start[] = {0, };
int step17_factor50_B_blk_start[] = {6, };
int step17_factor50_blk_width[] = {12, };

const int step17_factor51_height = 7;
const int step17_factor51_width = 6;
int step17_factor51_ridx[] = {18, 19, 20, 21, 22, 23, 30, };
float step17_factor51_data[42] = {0};

const int step17_factor51_num_blks = 1;
int step17_factor51_A_blk_start[] = {0, };
int step17_factor51_B_blk_start[] = {18, };
int step17_factor51_blk_width[] = {6, };

const int step17_factor52_height = 13;
const int step17_factor52_width = 6;
int step17_factor52_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 30, };
float step17_factor52_data[78] = {0};

const int step17_factor52_num_blks = 1;
int step17_factor52_A_blk_start[] = {0, };
int step17_factor52_B_blk_start[] = {12, };
int step17_factor52_blk_width[] = {12, };

const int step17_factor53_height = 7;
const int step17_factor53_width = 6;
int step17_factor53_ridx[] = {24, 25, 26, 27, 28, 29, 30, };
float step17_factor53_data[42] = {0};

const int step17_factor53_num_blks = 1;
int step17_factor53_A_blk_start[] = {0, };
int step17_factor53_B_blk_start[] = {24, };
int step17_factor53_blk_width[] = {6, };

const int step17_factor54_height = 13;
const int step17_factor54_width = 6;
int step17_factor54_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step17_factor54_data[78] = {0};

const int step17_factor54_num_blks = 1;
int step17_factor54_A_blk_start[] = {0, };
int step17_factor54_B_blk_start[] = {18, };
int step17_factor54_blk_width[] = {12, };

const int step17_node2_num_factors = 1;
const int step17_node2_relin_cost = 0;
const int step17_node2_sym_cost = 16000;
const bool step17_node2_marked = false;
const bool step17_node2_fixed = true;
int step17_node2_factor_height[] = {step17_factor46_height, };
int step17_node2_factor_width[] = {step17_factor46_width, };
int* step17_node2_factor_ridx[] = {step17_factor46_ridx, };
float* step17_node2_factor_data[] = {step17_factor46_data, };
int step17_node2_factor_num_blks[] = {step17_factor46_num_blks, };
int* step17_node2_factor_A_blk_start[] = {step17_factor46_A_blk_start, };
int* step17_node2_factor_B_blk_start[] = {step17_factor46_B_blk_start, };
int* step17_node2_factor_blk_width[] = {step17_factor46_blk_width, };
const int step17_node2_parent = 3;
const int step17_node2_height = 31;
const int step17_node2_width = 24;
float step17_node2_data[744] = {0};
const int step17_node2_num_blks = 1;
int step17_node2_A_blk_start[] = {0, };
int step17_node2_B_blk_start[] = {0, };
int step17_node2_blk_width[] = {6, };


const int step17_node3_num_factors = 9;
const int step17_node3_relin_cost = 0;
const int step17_node3_sym_cost = 20000;
const bool step17_node3_marked = true;
const bool step17_node3_fixed = false;
int step17_node3_factor_height[] = {step17_factor45_height, step17_factor47_height, step17_factor48_height, step17_factor49_height, step17_factor50_height, step17_factor51_height, step17_factor52_height, step17_factor53_height, step17_factor54_height, };
int step17_node3_factor_width[] = {step17_factor45_width, step17_factor47_width, step17_factor48_width, step17_factor49_width, step17_factor50_width, step17_factor51_width, step17_factor52_width, step17_factor53_width, step17_factor54_width, };
int* step17_node3_factor_ridx[] = {step17_factor45_ridx, step17_factor47_ridx, step17_factor48_ridx, step17_factor49_ridx, step17_factor50_ridx, step17_factor51_ridx, step17_factor52_ridx, step17_factor53_ridx, step17_factor54_ridx, };
float* step17_node3_factor_data[] = {step17_factor45_data, step17_factor47_data, step17_factor48_data, step17_factor49_data, step17_factor50_data, step17_factor51_data, step17_factor52_data, step17_factor53_data, step17_factor54_data, };
int step17_node3_factor_num_blks[] = {step17_factor45_num_blks, step17_factor47_num_blks, step17_factor48_num_blks, step17_factor49_num_blks, step17_factor50_num_blks, step17_factor51_num_blks, step17_factor52_num_blks, step17_factor53_num_blks, step17_factor54_num_blks, };
int* step17_node3_factor_A_blk_start[] = {step17_factor45_A_blk_start, step17_factor47_A_blk_start, step17_factor48_A_blk_start, step17_factor49_A_blk_start, step17_factor50_A_blk_start, step17_factor51_A_blk_start, step17_factor52_A_blk_start, step17_factor53_A_blk_start, step17_factor54_A_blk_start, };
int* step17_node3_factor_B_blk_start[] = {step17_factor45_B_blk_start, step17_factor47_B_blk_start, step17_factor48_B_blk_start, step17_factor49_B_blk_start, step17_factor50_B_blk_start, step17_factor51_B_blk_start, step17_factor52_B_blk_start, step17_factor53_B_blk_start, step17_factor54_B_blk_start, };
int* step17_node3_factor_blk_width[] = {step17_factor45_blk_width, step17_factor47_blk_width, step17_factor48_blk_width, step17_factor49_blk_width, step17_factor50_blk_width, step17_factor51_blk_width, step17_factor52_blk_width, step17_factor53_blk_width, step17_factor54_blk_width, };
const int step17_node3_parent = 4;
const int step17_node3_height = 31;
const int step17_node3_width = 30;
float step17_node3_data[930] = {0};
const int step17_node3_num_blks = 0;
int step17_node3_A_blk_start[] = {};
int step17_node3_B_blk_start[] = {};
int step17_node3_blk_width[] = {};


const int step17_node4_num_factors = 0;
const int step17_node4_relin_cost = 0;
const int step17_node4_sym_cost = 4000;
const bool step17_node4_marked = true;
const bool step17_node4_fixed = false;
int step17_node4_factor_height[] = {};
int step17_node4_factor_width[] = {};
int* step17_node4_factor_ridx[] = {};
float* step17_node4_factor_data[] = {};
int step17_node4_factor_num_blks[] = {};
int* step17_node4_factor_A_blk_start[] = {};
int* step17_node4_factor_B_blk_start[] = {};
int* step17_node4_factor_blk_width[] = {};
const int step17_node4_parent = -1;
const int step17_node4_height = 1;
const int step17_node4_width = 1;
float step17_node4_data[1] = {0};
const int step17_node4_num_blks = 0;
int step17_node4_A_blk_start[] = {};
int step17_node4_B_blk_start[] = {};
int step17_node4_blk_width[] = {};


int step17_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 108, };
int step17_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 108, };
int step17_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 108, };
int step17_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, };
int step17_node4_ridx[] = {
108, };
const int step17_nnodes = 5;
bool step17_node_marked[] = {false, false, step17_node2_marked, step17_node3_marked, step17_node4_marked, };
bool step17_node_fixed[] = {false, false, step17_node2_fixed, step17_node3_fixed, step17_node4_fixed, };
int step17_node_num_factors[] = {0, 0, step17_node2_num_factors, step17_node3_num_factors, step17_node4_num_factors, };
int step17_node_relin_cost[] = {0, 0, step17_node2_relin_cost, step17_node3_relin_cost, step17_node4_relin_cost, };
int step17_node_sym_cost[] = {0, 0, step17_node2_sym_cost, step17_node3_sym_cost, step17_node4_sym_cost, };
int* step17_node_factor_height[] = {0, 0, step17_node2_factor_height, step17_node3_factor_height, step17_node4_factor_height, };
int* step17_node_factor_width[] = {0, 0, step17_node2_factor_width, step17_node3_factor_width, step17_node4_factor_width, };
int** step17_node_factor_ridx[] = {0, 0, step17_node2_factor_ridx, step17_node3_factor_ridx, step17_node4_factor_ridx, };
float** step17_node_factor_data[] = {0, 0, step17_node2_factor_data, step17_node3_factor_data, step17_node4_factor_data, };
int* step17_node_factor_num_blks[] = {0, 0, step17_node2_factor_num_blks, step17_node3_factor_num_blks, step17_node4_factor_num_blks, };
int** step17_node_factor_A_blk_start[] = {0, 0, step17_node2_factor_A_blk_start, step17_node3_factor_A_blk_start, step17_node4_factor_A_blk_start, };
int** step17_node_factor_B_blk_start[] = {0, 0, step17_node2_factor_B_blk_start, step17_node3_factor_B_blk_start, step17_node4_factor_B_blk_start, };
int** step17_node_factor_blk_width[] = {0, 0, step17_node2_factor_blk_width, step17_node3_factor_blk_width, step17_node4_factor_blk_width, };
int step17_node_parent[] = {0, 0, step17_node2_parent, step17_node3_parent, step17_node4_parent, };
int step17_node_height[] = {0, 0, step17_node2_height, step17_node3_height, step17_node4_height, };
int step17_node_width[] = {0, 0, step17_node2_width, step17_node3_width, step17_node4_width, };
float* step17_node_data[] = {0, 0, step17_node2_data, step17_node3_data, step17_node4_data, };
int step17_node_num_blks[] = {0, 0, step17_node2_num_blks, step17_node3_num_blks, step17_node4_num_blks, };
int* step17_node_A_blk_start[] = {0, 0, step17_node2_A_blk_start, step17_node3_A_blk_start, step17_node4_A_blk_start, };
int* step17_node_B_blk_start[] = {0, 0, step17_node2_B_blk_start, step17_node3_B_blk_start, step17_node4_B_blk_start, };
int* step17_node_blk_width[] = {0, 0, step17_node2_blk_width, step17_node3_blk_width, step17_node4_blk_width, };
int* step17_node_ridx[] = {step17_node0_ridx, step17_node1_ridx, step17_node2_ridx, step17_node3_ridx, step17_node4_ridx, };


float step17_x_data[109] = {};
const int step17_workspace_needed = 7992;

