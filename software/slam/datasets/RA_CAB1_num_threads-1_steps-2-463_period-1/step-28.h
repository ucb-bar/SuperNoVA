#pragma once

const bool step28_is_reconstruct = true;

const int step28_num_threads = 1;

const uint64_t step28_scaled_relin_cost = 0;

const bool step28_run_model = false;

const int step28_factor74_height = 13;
const int step28_factor74_width = 6;
int step28_factor74_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 24, };
float step28_factor74_data[78] = {0};

const int step28_factor74_num_blks = 1;
int step28_factor74_A_blk_start[] = {0, };
int step28_factor74_B_blk_start[] = {6, };
int step28_factor74_blk_width[] = {12, };

const int step28_factor75_height = 7;
const int step28_factor75_width = 6;
int step28_factor75_ridx[] = {18, 19, 20, 21, 22, 23, 24, };
float step28_factor75_data[42] = {0};

const int step28_factor75_num_blks = 1;
int step28_factor75_A_blk_start[] = {0, };
int step28_factor75_B_blk_start[] = {18, };
int step28_factor75_blk_width[] = {6, };

const int step28_factor76_height = 13;
const int step28_factor76_width = 6;
int step28_factor76_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, };
float step28_factor76_data[78] = {0};

const int step28_factor76_num_blks = 1;
int step28_factor76_A_blk_start[] = {0, };
int step28_factor76_B_blk_start[] = {12, };
int step28_factor76_blk_width[] = {12, };

const int step28_factor69_height = 7;
const int step28_factor69_width = 6;
int step28_factor69_ridx[] = {0, 1, 2, 3, 4, 5, 24, };
float step28_factor69_data[42] = {0};

const int step28_factor69_num_blks = 1;
int step28_factor69_A_blk_start[] = {0, };
int step28_factor69_B_blk_start[] = {0, };
int step28_factor69_blk_width[] = {6, };

const int step28_factor70_height = 13;
const int step28_factor70_width = 6;
int step28_factor70_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step28_factor70_data[78] = {0};

const int step28_factor70_num_blks = 1;
int step28_factor70_A_blk_start[] = {0, };
int step28_factor70_B_blk_start[] = {18, };
int step28_factor70_blk_width[] = {12, };

const int step28_factor71_height = 7;
const int step28_factor71_width = 6;
int step28_factor71_ridx[] = {6, 7, 8, 9, 10, 11, 24, };
float step28_factor71_data[42] = {0};

const int step28_factor71_num_blks = 1;
int step28_factor71_A_blk_start[] = {0, };
int step28_factor71_B_blk_start[] = {6, };
int step28_factor71_blk_width[] = {6, };

const int step28_factor72_height = 13;
const int step28_factor72_width = 6;
int step28_factor72_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 24, };
float step28_factor72_data[78] = {0};

const int step28_factor72_num_blks = 1;
int step28_factor72_A_blk_start[] = {0, };
int step28_factor72_B_blk_start[] = {0, };
int step28_factor72_blk_width[] = {12, };

const int step28_factor73_height = 7;
const int step28_factor73_width = 6;
int step28_factor73_ridx[] = {12, 13, 14, 15, 16, 17, 24, };
float step28_factor73_data[42] = {0};

const int step28_factor73_num_blks = 1;
int step28_factor73_A_blk_start[] = {0, };
int step28_factor73_B_blk_start[] = {12, };
int step28_factor73_blk_width[] = {6, };

const int step28_node5_num_factors = 1;
const int step28_node5_relin_cost = 0;
const int step28_node5_sym_cost = 16000;
const bool step28_node5_marked = false;
const bool step28_node5_fixed = true;
int step28_node5_factor_height[] = {step28_factor70_height, };
int step28_node5_factor_width[] = {step28_factor70_width, };
int* step28_node5_factor_ridx[] = {step28_factor70_ridx, };
float* step28_node5_factor_data[] = {step28_factor70_data, };
int step28_node5_factor_num_blks[] = {step28_factor70_num_blks, };
int* step28_node5_factor_A_blk_start[] = {step28_factor70_A_blk_start, };
int* step28_node5_factor_B_blk_start[] = {step28_factor70_B_blk_start, };
int* step28_node5_factor_blk_width[] = {step28_factor70_blk_width, };
const int step28_node5_parent = 6;
const int step28_node5_height = 31;
const int step28_node5_width = 24;
float step28_node5_data[744] = {0};
const int step28_node5_num_blks = 1;
int step28_node5_A_blk_start[] = {0, };
int step28_node5_B_blk_start[] = {0, };
int step28_node5_blk_width[] = {6, };


const int step28_node6_num_factors = 7;
const int step28_node6_relin_cost = 0;
const int step28_node6_sym_cost = 16000;
const bool step28_node6_marked = true;
const bool step28_node6_fixed = false;
int step28_node6_factor_height[] = {step28_factor69_height, step28_factor71_height, step28_factor72_height, step28_factor73_height, step28_factor74_height, step28_factor75_height, step28_factor76_height, };
int step28_node6_factor_width[] = {step28_factor69_width, step28_factor71_width, step28_factor72_width, step28_factor73_width, step28_factor74_width, step28_factor75_width, step28_factor76_width, };
int* step28_node6_factor_ridx[] = {step28_factor69_ridx, step28_factor71_ridx, step28_factor72_ridx, step28_factor73_ridx, step28_factor74_ridx, step28_factor75_ridx, step28_factor76_ridx, };
float* step28_node6_factor_data[] = {step28_factor69_data, step28_factor71_data, step28_factor72_data, step28_factor73_data, step28_factor74_data, step28_factor75_data, step28_factor76_data, };
int step28_node6_factor_num_blks[] = {step28_factor69_num_blks, step28_factor71_num_blks, step28_factor72_num_blks, step28_factor73_num_blks, step28_factor74_num_blks, step28_factor75_num_blks, step28_factor76_num_blks, };
int* step28_node6_factor_A_blk_start[] = {step28_factor69_A_blk_start, step28_factor71_A_blk_start, step28_factor72_A_blk_start, step28_factor73_A_blk_start, step28_factor74_A_blk_start, step28_factor75_A_blk_start, step28_factor76_A_blk_start, };
int* step28_node6_factor_B_blk_start[] = {step28_factor69_B_blk_start, step28_factor71_B_blk_start, step28_factor72_B_blk_start, step28_factor73_B_blk_start, step28_factor74_B_blk_start, step28_factor75_B_blk_start, step28_factor76_B_blk_start, };
int* step28_node6_factor_blk_width[] = {step28_factor69_blk_width, step28_factor71_blk_width, step28_factor72_blk_width, step28_factor73_blk_width, step28_factor74_blk_width, step28_factor75_blk_width, step28_factor76_blk_width, };
const int step28_node6_parent = 7;
const int step28_node6_height = 25;
const int step28_node6_width = 24;
float step28_node6_data[600] = {0};
const int step28_node6_num_blks = 0;
int step28_node6_A_blk_start[] = {};
int step28_node6_B_blk_start[] = {};
int step28_node6_blk_width[] = {};


const int step28_node7_num_factors = 0;
const int step28_node7_relin_cost = 0;
const int step28_node7_sym_cost = 4000;
const bool step28_node7_marked = true;
const bool step28_node7_fixed = false;
int step28_node7_factor_height[] = {};
int step28_node7_factor_width[] = {};
int* step28_node7_factor_ridx[] = {};
float* step28_node7_factor_data[] = {};
int step28_node7_factor_num_blks[] = {};
int* step28_node7_factor_A_blk_start[] = {};
int* step28_node7_factor_B_blk_start[] = {};
int* step28_node7_factor_blk_width[] = {};
const int step28_node7_parent = -1;
const int step28_node7_height = 1;
const int step28_node7_width = 1;
float step28_node7_data[1] = {0};
const int step28_node7_num_blks = 0;
int step28_node7_A_blk_start[] = {};
int step28_node7_B_blk_start[] = {};
int step28_node7_blk_width[] = {};


int step28_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 174, };
int step28_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 174, };
int step28_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 174, };
int step28_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 174, };
int step28_node4_ridx[] = {
102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 174, };
int step28_node5_ridx[] = {
126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 174, };
int step28_node6_ridx[] = {
150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, };
int step28_node7_ridx[] = {
174, };
const int step28_nnodes = 8;
bool step28_node_marked[] = {false, false, false, false, false, step28_node5_marked, step28_node6_marked, step28_node7_marked, };
bool step28_node_fixed[] = {false, false, false, false, false, step28_node5_fixed, step28_node6_fixed, step28_node7_fixed, };
int step28_node_num_factors[] = {0, 0, 0, 0, 0, step28_node5_num_factors, step28_node6_num_factors, step28_node7_num_factors, };
int step28_node_relin_cost[] = {0, 0, 0, 0, 0, step28_node5_relin_cost, step28_node6_relin_cost, step28_node7_relin_cost, };
int step28_node_sym_cost[] = {0, 0, 0, 0, 0, step28_node5_sym_cost, step28_node6_sym_cost, step28_node7_sym_cost, };
int* step28_node_factor_height[] = {0, 0, 0, 0, 0, step28_node5_factor_height, step28_node6_factor_height, step28_node7_factor_height, };
int* step28_node_factor_width[] = {0, 0, 0, 0, 0, step28_node5_factor_width, step28_node6_factor_width, step28_node7_factor_width, };
int** step28_node_factor_ridx[] = {0, 0, 0, 0, 0, step28_node5_factor_ridx, step28_node6_factor_ridx, step28_node7_factor_ridx, };
float** step28_node_factor_data[] = {0, 0, 0, 0, 0, step28_node5_factor_data, step28_node6_factor_data, step28_node7_factor_data, };
int* step28_node_factor_num_blks[] = {0, 0, 0, 0, 0, step28_node5_factor_num_blks, step28_node6_factor_num_blks, step28_node7_factor_num_blks, };
int** step28_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, step28_node5_factor_A_blk_start, step28_node6_factor_A_blk_start, step28_node7_factor_A_blk_start, };
int** step28_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, step28_node5_factor_B_blk_start, step28_node6_factor_B_blk_start, step28_node7_factor_B_blk_start, };
int** step28_node_factor_blk_width[] = {0, 0, 0, 0, 0, step28_node5_factor_blk_width, step28_node6_factor_blk_width, step28_node7_factor_blk_width, };
int step28_node_parent[] = {0, 0, 0, 0, 0, step28_node5_parent, step28_node6_parent, step28_node7_parent, };
int step28_node_height[] = {0, 0, 0, 0, 0, step28_node5_height, step28_node6_height, step28_node7_height, };
int step28_node_width[] = {0, 0, 0, 0, 0, step28_node5_width, step28_node6_width, step28_node7_width, };
float* step28_node_data[] = {0, 0, 0, 0, 0, step28_node5_data, step28_node6_data, step28_node7_data, };
int step28_node_num_blks[] = {0, 0, 0, 0, 0, step28_node5_num_blks, step28_node6_num_blks, step28_node7_num_blks, };
int* step28_node_A_blk_start[] = {0, 0, 0, 0, 0, step28_node5_A_blk_start, step28_node6_A_blk_start, step28_node7_A_blk_start, };
int* step28_node_B_blk_start[] = {0, 0, 0, 0, 0, step28_node5_B_blk_start, step28_node6_B_blk_start, step28_node7_B_blk_start, };
int* step28_node_blk_width[] = {0, 0, 0, 0, 0, step28_node5_blk_width, step28_node6_blk_width, step28_node7_blk_width, };
int* step28_node_ridx[] = {step28_node0_ridx, step28_node1_ridx, step28_node2_ridx, step28_node3_ridx, step28_node4_ridx, step28_node5_ridx, step28_node6_ridx, step28_node7_ridx, };


float step28_x_data[175] = {};
const int step28_workspace_needed = 6648;

