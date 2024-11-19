#pragma once

const bool step26_is_reconstruct = true;

const int step26_num_threads = 1;

const uint64_t step26_scaled_relin_cost = 0;

const bool step26_run_model = false;

const int step26_factor71_height = 7;
const int step26_factor71_width = 6;
int step26_factor71_ridx[] = {6, 7, 8, 9, 10, 11, 12, };
float step26_factor71_data[42] = {0};

const int step26_factor71_num_blks = 1;
int step26_factor71_A_blk_start[] = {0, };
int step26_factor71_B_blk_start[] = {6, };
int step26_factor71_blk_width[] = {6, };

const int step26_factor69_height = 7;
const int step26_factor69_width = 6;
int step26_factor69_ridx[] = {0, 1, 2, 3, 4, 5, 12, };
float step26_factor69_data[42] = {0};

const int step26_factor69_num_blks = 1;
int step26_factor69_A_blk_start[] = {0, };
int step26_factor69_B_blk_start[] = {0, };
int step26_factor69_blk_width[] = {6, };

const int step26_factor72_height = 13;
const int step26_factor72_width = 6;
int step26_factor72_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, };
float step26_factor72_data[78] = {0};

const int step26_factor72_num_blks = 1;
int step26_factor72_A_blk_start[] = {0, };
int step26_factor72_B_blk_start[] = {0, };
int step26_factor72_blk_width[] = {12, };

const int step26_factor70_height = 13;
const int step26_factor70_width = 6;
int step26_factor70_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step26_factor70_data[78] = {0};

const int step26_factor70_num_blks = 1;
int step26_factor70_A_blk_start[] = {0, };
int step26_factor70_B_blk_start[] = {18, };
int step26_factor70_blk_width[] = {12, };

const int step26_node5_num_factors = 1;
const int step26_node5_relin_cost = 30000;
const bool step26_node5_marked = false;
const bool step26_node5_fixed = true;
int step26_node5_factor_height[] = {step26_factor70_height, };
int step26_node5_factor_width[] = {step26_factor70_width, };
int* step26_node5_factor_ridx[] = {step26_factor70_ridx, };
float* step26_node5_factor_data[] = {step26_factor70_data, };
int step26_node5_factor_num_blks[] = {step26_factor70_num_blks, };
int* step26_node5_factor_A_blk_start[] = {step26_factor70_A_blk_start, };
int* step26_node5_factor_B_blk_start[] = {step26_factor70_B_blk_start, };
int* step26_node5_factor_blk_width[] = {step26_factor70_blk_width, };
const int step26_node5_parent = 6;
const int step26_node5_height = 31;
const int step26_node5_width = 24;
float step26_node5_data[744] = {0};
const int step26_node5_num_blks = 1;
int step26_node5_A_blk_start[] = {0, };
int step26_node5_B_blk_start[] = {0, };
int step26_node5_blk_width[] = {6, };


const int step26_node6_num_factors = 3;
const int step26_node6_relin_cost = 90000;
const bool step26_node6_marked = true;
const bool step26_node6_fixed = false;
int step26_node6_factor_height[] = {step26_factor69_height, step26_factor71_height, step26_factor72_height, };
int step26_node6_factor_width[] = {step26_factor69_width, step26_factor71_width, step26_factor72_width, };
int* step26_node6_factor_ridx[] = {step26_factor69_ridx, step26_factor71_ridx, step26_factor72_ridx, };
float* step26_node6_factor_data[] = {step26_factor69_data, step26_factor71_data, step26_factor72_data, };
int step26_node6_factor_num_blks[] = {step26_factor69_num_blks, step26_factor71_num_blks, step26_factor72_num_blks, };
int* step26_node6_factor_A_blk_start[] = {step26_factor69_A_blk_start, step26_factor71_A_blk_start, step26_factor72_A_blk_start, };
int* step26_node6_factor_B_blk_start[] = {step26_factor69_B_blk_start, step26_factor71_B_blk_start, step26_factor72_B_blk_start, };
int* step26_node6_factor_blk_width[] = {step26_factor69_blk_width, step26_factor71_blk_width, step26_factor72_blk_width, };
const int step26_node6_parent = 7;
const int step26_node6_height = 13;
const int step26_node6_width = 12;
float step26_node6_data[156] = {0};
const int step26_node6_num_blks = 0;
int step26_node6_A_blk_start[] = {};
int step26_node6_B_blk_start[] = {};
int step26_node6_blk_width[] = {};


const int step26_node7_num_factors = 0;
const int step26_node7_relin_cost = 0;
const bool step26_node7_marked = true;
const bool step26_node7_fixed = false;
int step26_node7_factor_height[] = {};
int step26_node7_factor_width[] = {};
int* step26_node7_factor_ridx[] = {};
float* step26_node7_factor_data[] = {};
int step26_node7_factor_num_blks[] = {};
int* step26_node7_factor_A_blk_start[] = {};
int* step26_node7_factor_B_blk_start[] = {};
int* step26_node7_factor_blk_width[] = {};
const int step26_node7_parent = -1;
const int step26_node7_height = 1;
const int step26_node7_width = 1;
float step26_node7_data[1] = {0};
const int step26_node7_num_blks = 0;
int step26_node7_A_blk_start[] = {};
int step26_node7_B_blk_start[] = {};
int step26_node7_blk_width[] = {};


int step26_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 162, };
int step26_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 162, };
int step26_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 162, };
int step26_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 162, };
int step26_node4_ridx[] = {
102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 162, };
int step26_node5_ridx[] = {
126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 162, };
int step26_node6_ridx[] = {
150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, };
int step26_node7_ridx[] = {
162, };
const int step26_nnodes = 8;
bool step26_node_marked[] = {false, false, false, false, false, step26_node5_marked, step26_node6_marked, step26_node7_marked, };
bool step26_node_fixed[] = {false, false, false, false, false, step26_node5_fixed, step26_node6_fixed, step26_node7_fixed, };
int step26_node_num_factors[] = {0, 0, 0, 0, 0, step26_node5_num_factors, step26_node6_num_factors, step26_node7_num_factors, };
int step26_node_relin_cost[] = {0, 0, 0, 0, 0, step26_node5_relin_cost, step26_node6_relin_cost, step26_node7_relin_cost, };
int* step26_node_factor_height[] = {0, 0, 0, 0, 0, step26_node5_factor_height, step26_node6_factor_height, step26_node7_factor_height, };
int* step26_node_factor_width[] = {0, 0, 0, 0, 0, step26_node5_factor_width, step26_node6_factor_width, step26_node7_factor_width, };
int** step26_node_factor_ridx[] = {0, 0, 0, 0, 0, step26_node5_factor_ridx, step26_node6_factor_ridx, step26_node7_factor_ridx, };
float** step26_node_factor_data[] = {0, 0, 0, 0, 0, step26_node5_factor_data, step26_node6_factor_data, step26_node7_factor_data, };
int* step26_node_factor_num_blks[] = {0, 0, 0, 0, 0, step26_node5_factor_num_blks, step26_node6_factor_num_blks, step26_node7_factor_num_blks, };
int** step26_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, step26_node5_factor_A_blk_start, step26_node6_factor_A_blk_start, step26_node7_factor_A_blk_start, };
int** step26_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, step26_node5_factor_B_blk_start, step26_node6_factor_B_blk_start, step26_node7_factor_B_blk_start, };
int** step26_node_factor_blk_width[] = {0, 0, 0, 0, 0, step26_node5_factor_blk_width, step26_node6_factor_blk_width, step26_node7_factor_blk_width, };
int step26_node_parent[] = {0, 0, 0, 0, 0, step26_node5_parent, step26_node6_parent, step26_node7_parent, };
int step26_node_height[] = {0, 0, 0, 0, 0, step26_node5_height, step26_node6_height, step26_node7_height, };
int step26_node_width[] = {0, 0, 0, 0, 0, step26_node5_width, step26_node6_width, step26_node7_width, };
float* step26_node_data[] = {0, 0, 0, 0, 0, step26_node5_data, step26_node6_data, step26_node7_data, };
int step26_node_num_blks[] = {0, 0, 0, 0, 0, step26_node5_num_blks, step26_node6_num_blks, step26_node7_num_blks, };
int* step26_node_A_blk_start[] = {0, 0, 0, 0, 0, step26_node5_A_blk_start, step26_node6_A_blk_start, step26_node7_A_blk_start, };
int* step26_node_B_blk_start[] = {0, 0, 0, 0, 0, step26_node5_B_blk_start, step26_node6_B_blk_start, step26_node7_B_blk_start, };
int* step26_node_blk_width[] = {0, 0, 0, 0, 0, step26_node5_blk_width, step26_node6_blk_width, step26_node7_blk_width, };
int* step26_node_ridx[] = {step26_node0_ridx, step26_node1_ridx, step26_node2_ridx, step26_node3_ridx, step26_node4_ridx, step26_node5_ridx, step26_node6_ridx, step26_node7_ridx, };


float step26_x_data[163] = {};
const int step26_workspace_needed = 4824;

