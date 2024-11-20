#pragma once

const bool step50_is_reconstruct = true;

const int step50_num_threads = -1;

const uint64_t step50_scaled_relin_cost = -1;

const bool step50_run_model = false;

const int step50_factor104_height = 4;
const int step50_factor104_width = 3;
int step50_factor104_ridx[] = {3, 4, 5, 9, };
float step50_factor104_data[12] = {0};

const int step50_factor104_num_blks = 1;
int step50_factor104_A_blk_start[] = {0, };
int step50_factor104_B_blk_start[] = {3, };
int step50_factor104_blk_width[] = {3, };

const int step50_factor105_height = 7;
const int step50_factor105_width = 3;
int step50_factor105_ridx[] = {0, 1, 2, 3, 4, 5, 9, };
float step50_factor105_data[21] = {0};

const int step50_factor105_num_blks = 1;
int step50_factor105_A_blk_start[] = {0, };
int step50_factor105_B_blk_start[] = {0, };
int step50_factor105_blk_width[] = {6, };

const int step50_factor106_height = 4;
const int step50_factor106_width = 3;
int step50_factor106_ridx[] = {6, 7, 8, 9, };
float step50_factor106_data[12] = {0};

const int step50_factor106_num_blks = 1;
int step50_factor106_A_blk_start[] = {0, };
int step50_factor106_B_blk_start[] = {6, };
int step50_factor106_blk_width[] = {3, };

const int step50_factor107_height = 7;
const int step50_factor107_width = 3;
int step50_factor107_ridx[] = {3, 4, 5, 6, 7, 8, 9, };
float step50_factor107_data[21] = {0};

const int step50_factor107_num_blks = 1;
int step50_factor107_A_blk_start[] = {0, };
int step50_factor107_B_blk_start[] = {3, };
int step50_factor107_blk_width[] = {6, };

const int step50_factor102_height = 4;
const int step50_factor102_width = 3;
int step50_factor102_ridx[] = {0, 1, 2, 9, };
float step50_factor102_data[12] = {0};

const int step50_factor102_num_blks = 1;
int step50_factor102_A_blk_start[] = {0, };
int step50_factor102_B_blk_start[] = {0, };
int step50_factor102_blk_width[] = {3, };

const int step50_factor103_height = 7;
const int step50_factor103_width = 3;
int step50_factor103_ridx[] = {21, 22, 23, 24, 25, 26, 27, };
float step50_factor103_data[21] = {0};

const int step50_factor103_num_blks = 1;
int step50_factor103_A_blk_start[] = {0, };
int step50_factor103_B_blk_start[] = {21, };
int step50_factor103_blk_width[] = {6, };

const int step50_node4_num_factors = 1;
const int step50_node4_relin_cost = 0;
const int step50_node4_sym_cost = 16000;
const bool step50_node4_marked = false;
const bool step50_node4_fixed = true;
int step50_node4_factor_height[] = {step50_factor103_height, };
int step50_node4_factor_width[] = {step50_factor103_width, };
int* step50_node4_factor_ridx[] = {step50_factor103_ridx, };
float* step50_node4_factor_data[] = {step50_factor103_data, };
int step50_node4_factor_num_blks[] = {step50_factor103_num_blks, };
int* step50_node4_factor_A_blk_start[] = {step50_factor103_A_blk_start, };
int* step50_node4_factor_B_blk_start[] = {step50_factor103_B_blk_start, };
int* step50_node4_factor_blk_width[] = {step50_factor103_blk_width, };
const int step50_node4_parent = 5;
const int step50_node4_height = 28;
const int step50_node4_width = 24;
float step50_node4_data[672] = {0};
const int step50_node4_num_blks = 1;
int step50_node4_A_blk_start[] = {0, };
int step50_node4_B_blk_start[] = {0, };
int step50_node4_blk_width[] = {3, };


const int step50_node5_num_factors = 5;
const int step50_node5_relin_cost = 0;
const int step50_node5_sym_cost = 6000;
const bool step50_node5_marked = true;
const bool step50_node5_fixed = false;
int step50_node5_factor_height[] = {step50_factor102_height, step50_factor104_height, step50_factor105_height, step50_factor106_height, step50_factor107_height, };
int step50_node5_factor_width[] = {step50_factor102_width, step50_factor104_width, step50_factor105_width, step50_factor106_width, step50_factor107_width, };
int* step50_node5_factor_ridx[] = {step50_factor102_ridx, step50_factor104_ridx, step50_factor105_ridx, step50_factor106_ridx, step50_factor107_ridx, };
float* step50_node5_factor_data[] = {step50_factor102_data, step50_factor104_data, step50_factor105_data, step50_factor106_data, step50_factor107_data, };
int step50_node5_factor_num_blks[] = {step50_factor102_num_blks, step50_factor104_num_blks, step50_factor105_num_blks, step50_factor106_num_blks, step50_factor107_num_blks, };
int* step50_node5_factor_A_blk_start[] = {step50_factor102_A_blk_start, step50_factor104_A_blk_start, step50_factor105_A_blk_start, step50_factor106_A_blk_start, step50_factor107_A_blk_start, };
int* step50_node5_factor_B_blk_start[] = {step50_factor102_B_blk_start, step50_factor104_B_blk_start, step50_factor105_B_blk_start, step50_factor106_B_blk_start, step50_factor107_B_blk_start, };
int* step50_node5_factor_blk_width[] = {step50_factor102_blk_width, step50_factor104_blk_width, step50_factor105_blk_width, step50_factor106_blk_width, step50_factor107_blk_width, };
const int step50_node5_parent = 6;
const int step50_node5_height = 10;
const int step50_node5_width = 9;
float step50_node5_data[90] = {0};
const int step50_node5_num_blks = 0;
int step50_node5_A_blk_start[] = {};
int step50_node5_B_blk_start[] = {};
int step50_node5_blk_width[] = {};


const int step50_node6_num_factors = 0;
const int step50_node6_relin_cost = 0;
const int step50_node6_sym_cost = 2000;
const bool step50_node6_marked = true;
const bool step50_node6_fixed = false;
int step50_node6_factor_height[] = {};
int step50_node6_factor_width[] = {};
int* step50_node6_factor_ridx[] = {};
float* step50_node6_factor_data[] = {};
int step50_node6_factor_num_blks[] = {};
int* step50_node6_factor_A_blk_start[] = {};
int* step50_node6_factor_B_blk_start[] = {};
int* step50_node6_factor_blk_width[] = {};
const int step50_node6_parent = -1;
const int step50_node6_height = 1;
const int step50_node6_width = 1;
float step50_node6_data[1] = {0};
const int step50_node6_num_blks = 0;
int step50_node6_A_blk_start[] = {};
int step50_node6_B_blk_start[] = {};
int step50_node6_blk_width[] = {};


int step50_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 117, 118, 119, 153, };
int step50_node1_ridx[] = {
33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 84, 85, 86, 117, 118, 119, 153, };
int step50_node2_ridx[] = {
57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 105, 106, 107, 108, 109, 110, 114, 115, 116, 153, };
int step50_node3_ridx[] = {
84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 153, };
int step50_node4_ridx[] = {
120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 153, };
int step50_node5_ridx[] = {
144, 145, 146, 147, 148, 149, 150, 151, 152, 153, };
int step50_node6_ridx[] = {
153, };
const int step50_nnodes = 7;
bool step50_node_marked[] = {false, false, false, false, step50_node4_marked, step50_node5_marked, step50_node6_marked, };
bool step50_node_fixed[] = {false, false, false, false, step50_node4_fixed, step50_node5_fixed, step50_node6_fixed, };
int step50_node_num_factors[] = {0, 0, 0, 0, step50_node4_num_factors, step50_node5_num_factors, step50_node6_num_factors, };
int step50_node_relin_cost[] = {0, 0, 0, 0, step50_node4_relin_cost, step50_node5_relin_cost, step50_node6_relin_cost, };
int step50_node_sym_cost[] = {0, 0, 0, 0, step50_node4_sym_cost, step50_node5_sym_cost, step50_node6_sym_cost, };
int* step50_node_factor_height[] = {0, 0, 0, 0, step50_node4_factor_height, step50_node5_factor_height, step50_node6_factor_height, };
int* step50_node_factor_width[] = {0, 0, 0, 0, step50_node4_factor_width, step50_node5_factor_width, step50_node6_factor_width, };
int** step50_node_factor_ridx[] = {0, 0, 0, 0, step50_node4_factor_ridx, step50_node5_factor_ridx, step50_node6_factor_ridx, };
float** step50_node_factor_data[] = {0, 0, 0, 0, step50_node4_factor_data, step50_node5_factor_data, step50_node6_factor_data, };
int* step50_node_factor_num_blks[] = {0, 0, 0, 0, step50_node4_factor_num_blks, step50_node5_factor_num_blks, step50_node6_factor_num_blks, };
int** step50_node_factor_A_blk_start[] = {0, 0, 0, 0, step50_node4_factor_A_blk_start, step50_node5_factor_A_blk_start, step50_node6_factor_A_blk_start, };
int** step50_node_factor_B_blk_start[] = {0, 0, 0, 0, step50_node4_factor_B_blk_start, step50_node5_factor_B_blk_start, step50_node6_factor_B_blk_start, };
int** step50_node_factor_blk_width[] = {0, 0, 0, 0, step50_node4_factor_blk_width, step50_node5_factor_blk_width, step50_node6_factor_blk_width, };
int step50_node_parent[] = {0, 0, 0, 0, step50_node4_parent, step50_node5_parent, step50_node6_parent, };
int step50_node_height[] = {0, 0, 0, 0, step50_node4_height, step50_node5_height, step50_node6_height, };
int step50_node_width[] = {0, 0, 0, 0, step50_node4_width, step50_node5_width, step50_node6_width, };
float* step50_node_data[] = {0, 0, 0, 0, step50_node4_data, step50_node5_data, step50_node6_data, };
int step50_node_num_blks[] = {0, 0, 0, 0, step50_node4_num_blks, step50_node5_num_blks, step50_node6_num_blks, };
int* step50_node_A_blk_start[] = {0, 0, 0, 0, step50_node4_A_blk_start, step50_node5_A_blk_start, step50_node6_A_blk_start, };
int* step50_node_B_blk_start[] = {0, 0, 0, 0, step50_node4_B_blk_start, step50_node5_B_blk_start, step50_node6_B_blk_start, };
int* step50_node_blk_width[] = {0, 0, 0, 0, step50_node4_blk_width, step50_node5_blk_width, step50_node6_blk_width, };
int* step50_node_ridx[] = {step50_node0_ridx, step50_node1_ridx, step50_node2_ridx, step50_node3_ridx, step50_node4_ridx, step50_node5_ridx, step50_node6_ridx, };


float step50_x_data[154] = {};
const int step50_workspace_needed = 3840;

