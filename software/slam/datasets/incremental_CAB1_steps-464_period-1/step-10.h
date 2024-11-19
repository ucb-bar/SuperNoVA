#pragma once

const bool step10_is_reconstruct = true;

const int step10_num_threads = 1;

const uint64_t step10_scaled_relin_cost = 0;

const bool step10_run_model = false;

const int step10_factor27_height = 13;
const int step10_factor27_width = 6;
int step10_factor27_ridx[] = {0, 1, 2, 3, 4, 5, 30, 31, 32, 33, 34, 35, 36, };
float step10_factor27_data[78] = {0};

const int step10_factor27_num_blks = 2;
int step10_factor27_A_blk_start[] = {0, 6, };
int step10_factor27_B_blk_start[] = {0, 30, };
int step10_factor27_blk_width[] = {6, 6, };

const int step10_factor28_height = 13;
const int step10_factor28_width = 6;
int step10_factor28_ridx[] = {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, };
float step10_factor28_data[78] = {0};

const int step10_factor28_num_blks = 1;
int step10_factor28_A_blk_start[] = {0, };
int step10_factor28_B_blk_start[] = {24, };
int step10_factor28_blk_width[] = {12, };

const int step10_factor29_height = 13;
const int step10_factor29_width = 6;
int step10_factor29_ridx[] = {18, 19, 20, 21, 22, 23, 30, 31, 32, 33, 34, 35, 36, };
float step10_factor29_data[78] = {0};

const int step10_factor29_num_blks = 2;
int step10_factor29_A_blk_start[] = {0, 6, };
int step10_factor29_B_blk_start[] = {18, 30, };
int step10_factor29_blk_width[] = {6, 6, };

const int step10_factor30_height = 13;
const int step10_factor30_width = 6;
int step10_factor30_ridx[] = {12, 13, 14, 15, 16, 17, 30, 31, 32, 33, 34, 35, 36, };
float step10_factor30_data[78] = {0};

const int step10_factor30_num_blks = 2;
int step10_factor30_A_blk_start[] = {0, 6, };
int step10_factor30_B_blk_start[] = {12, 30, };
int step10_factor30_blk_width[] = {6, 6, };

const int step10_factor31_height = 7;
const int step10_factor31_width = 6;
int step10_factor31_ridx[] = {6, 7, 8, 9, 10, 11, 12, };
float step10_factor31_data[42] = {0};

const int step10_factor31_num_blks = 1;
int step10_factor31_A_blk_start[] = {0, };
int step10_factor31_B_blk_start[] = {6, };
int step10_factor31_blk_width[] = {6, };

const int step10_factor32_height = 13;
const int step10_factor32_width = 6;
int step10_factor32_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, };
float step10_factor32_data[78] = {0};

const int step10_factor32_num_blks = 1;
int step10_factor32_A_blk_start[] = {0, };
int step10_factor32_B_blk_start[] = {0, };
int step10_factor32_blk_width[] = {12, };

const int step10_factor25_height = 7;
const int step10_factor25_width = 6;
int step10_factor25_ridx[] = {0, 1, 2, 3, 4, 5, 12, };
float step10_factor25_data[42] = {0};

const int step10_factor25_num_blks = 1;
int step10_factor25_A_blk_start[] = {0, };
int step10_factor25_B_blk_start[] = {0, };
int step10_factor25_blk_width[] = {6, };

const int step10_factor26_height = 13;
const int step10_factor26_width = 6;
int step10_factor26_ridx[] = {6, 7, 8, 9, 10, 11, 30, 31, 32, 33, 34, 35, 36, };
float step10_factor26_data[78] = {0};

const int step10_factor26_num_blks = 2;
int step10_factor26_A_blk_start[] = {0, 6, };
int step10_factor26_B_blk_start[] = {6, 30, };
int step10_factor26_blk_width[] = {6, 6, };

const int step10_node1_num_factors = 5;
const int step10_node1_relin_cost = 150000;
const bool step10_node1_marked = false;
const bool step10_node1_fixed = true;
int step10_node1_factor_height[] = {step10_factor26_height, step10_factor27_height, step10_factor28_height, step10_factor29_height, step10_factor30_height, };
int step10_node1_factor_width[] = {step10_factor26_width, step10_factor27_width, step10_factor28_width, step10_factor29_width, step10_factor30_width, };
int* step10_node1_factor_ridx[] = {step10_factor26_ridx, step10_factor27_ridx, step10_factor28_ridx, step10_factor29_ridx, step10_factor30_ridx, };
float* step10_node1_factor_data[] = {step10_factor26_data, step10_factor27_data, step10_factor28_data, step10_factor29_data, step10_factor30_data, };
int step10_node1_factor_num_blks[] = {step10_factor26_num_blks, step10_factor27_num_blks, step10_factor28_num_blks, step10_factor29_num_blks, step10_factor30_num_blks, };
int* step10_node1_factor_A_blk_start[] = {step10_factor26_A_blk_start, step10_factor27_A_blk_start, step10_factor28_A_blk_start, step10_factor29_A_blk_start, step10_factor30_A_blk_start, };
int* step10_node1_factor_B_blk_start[] = {step10_factor26_B_blk_start, step10_factor27_B_blk_start, step10_factor28_B_blk_start, step10_factor29_B_blk_start, step10_factor30_B_blk_start, };
int* step10_node1_factor_blk_width[] = {step10_factor26_blk_width, step10_factor27_blk_width, step10_factor28_blk_width, step10_factor29_blk_width, step10_factor30_blk_width, };
const int step10_node1_parent = 2;
const int step10_node1_height = 37;
const int step10_node1_width = 30;
float step10_node1_data[1110] = {0};
const int step10_node1_num_blks = 1;
int step10_node1_A_blk_start[] = {0, };
int step10_node1_B_blk_start[] = {0, };
int step10_node1_blk_width[] = {6, };


const int step10_node2_num_factors = 3;
const int step10_node2_relin_cost = 90000;
const bool step10_node2_marked = true;
const bool step10_node2_fixed = false;
int step10_node2_factor_height[] = {step10_factor25_height, step10_factor31_height, step10_factor32_height, };
int step10_node2_factor_width[] = {step10_factor25_width, step10_factor31_width, step10_factor32_width, };
int* step10_node2_factor_ridx[] = {step10_factor25_ridx, step10_factor31_ridx, step10_factor32_ridx, };
float* step10_node2_factor_data[] = {step10_factor25_data, step10_factor31_data, step10_factor32_data, };
int step10_node2_factor_num_blks[] = {step10_factor25_num_blks, step10_factor31_num_blks, step10_factor32_num_blks, };
int* step10_node2_factor_A_blk_start[] = {step10_factor25_A_blk_start, step10_factor31_A_blk_start, step10_factor32_A_blk_start, };
int* step10_node2_factor_B_blk_start[] = {step10_factor25_B_blk_start, step10_factor31_B_blk_start, step10_factor32_B_blk_start, };
int* step10_node2_factor_blk_width[] = {step10_factor25_blk_width, step10_factor31_blk_width, step10_factor32_blk_width, };
const int step10_node2_parent = 3;
const int step10_node2_height = 13;
const int step10_node2_width = 12;
float step10_node2_data[156] = {0};
const int step10_node2_num_blks = 0;
int step10_node2_A_blk_start[] = {};
int step10_node2_B_blk_start[] = {};
int step10_node2_blk_width[] = {};


const int step10_node3_num_factors = 0;
const int step10_node3_relin_cost = 0;
const bool step10_node3_marked = true;
const bool step10_node3_fixed = false;
int step10_node3_factor_height[] = {};
int step10_node3_factor_width[] = {};
int* step10_node3_factor_ridx[] = {};
float* step10_node3_factor_data[] = {};
int step10_node3_factor_num_blks[] = {};
int* step10_node3_factor_A_blk_start[] = {};
int* step10_node3_factor_B_blk_start[] = {};
int* step10_node3_factor_blk_width[] = {};
const int step10_node3_parent = -1;
const int step10_node3_height = 1;
const int step10_node3_width = 1;
float step10_node3_data[1] = {0};
const int step10_node3_num_blks = 0;
int step10_node3_A_blk_start[] = {};
int step10_node3_B_blk_start[] = {};
int step10_node3_blk_width[] = {};


int step10_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 66, };
int step10_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 66, };
int step10_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, };
int step10_node3_ridx[] = {
66, };
const int step10_nnodes = 4;
bool step10_node_marked[] = {false, step10_node1_marked, step10_node2_marked, step10_node3_marked, };
bool step10_node_fixed[] = {false, step10_node1_fixed, step10_node2_fixed, step10_node3_fixed, };
int step10_node_num_factors[] = {0, step10_node1_num_factors, step10_node2_num_factors, step10_node3_num_factors, };
int step10_node_relin_cost[] = {0, step10_node1_relin_cost, step10_node2_relin_cost, step10_node3_relin_cost, };
int* step10_node_factor_height[] = {0, step10_node1_factor_height, step10_node2_factor_height, step10_node3_factor_height, };
int* step10_node_factor_width[] = {0, step10_node1_factor_width, step10_node2_factor_width, step10_node3_factor_width, };
int** step10_node_factor_ridx[] = {0, step10_node1_factor_ridx, step10_node2_factor_ridx, step10_node3_factor_ridx, };
float** step10_node_factor_data[] = {0, step10_node1_factor_data, step10_node2_factor_data, step10_node3_factor_data, };
int* step10_node_factor_num_blks[] = {0, step10_node1_factor_num_blks, step10_node2_factor_num_blks, step10_node3_factor_num_blks, };
int** step10_node_factor_A_blk_start[] = {0, step10_node1_factor_A_blk_start, step10_node2_factor_A_blk_start, step10_node3_factor_A_blk_start, };
int** step10_node_factor_B_blk_start[] = {0, step10_node1_factor_B_blk_start, step10_node2_factor_B_blk_start, step10_node3_factor_B_blk_start, };
int** step10_node_factor_blk_width[] = {0, step10_node1_factor_blk_width, step10_node2_factor_blk_width, step10_node3_factor_blk_width, };
int step10_node_parent[] = {0, step10_node1_parent, step10_node2_parent, step10_node3_parent, };
int step10_node_height[] = {0, step10_node1_height, step10_node2_height, step10_node3_height, };
int step10_node_width[] = {0, step10_node1_width, step10_node2_width, step10_node3_width, };
float* step10_node_data[] = {0, step10_node1_data, step10_node2_data, step10_node3_data, };
int step10_node_num_blks[] = {0, step10_node1_num_blks, step10_node2_num_blks, step10_node3_num_blks, };
int* step10_node_A_blk_start[] = {0, step10_node1_A_blk_start, step10_node2_A_blk_start, step10_node3_A_blk_start, };
int* step10_node_B_blk_start[] = {0, step10_node1_B_blk_start, step10_node2_B_blk_start, step10_node3_B_blk_start, };
int* step10_node_blk_width[] = {0, step10_node1_blk_width, step10_node2_blk_width, step10_node3_blk_width, };
int* step10_node_ridx[] = {step10_node0_ridx, step10_node1_ridx, step10_node2_ridx, step10_node3_ridx, };


float step10_x_data[67] = {};
const int step10_workspace_needed = 6456;

