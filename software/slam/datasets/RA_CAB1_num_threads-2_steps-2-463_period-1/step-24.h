#pragma once

const bool step24_is_reconstruct = true;

const int step24_num_threads = 1;

const uint64_t step24_scaled_relin_cost = 0;

const bool step24_run_model = false;

const int step24_factor66_height = 13;
const int step24_factor66_width = 6;
int step24_factor66_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 24, };
float step24_factor66_data[78] = {0};

const int step24_factor66_num_blks = 1;
int step24_factor66_A_blk_start[] = {0, };
int step24_factor66_B_blk_start[] = {6, };
int step24_factor66_blk_width[] = {12, };

const int step24_factor67_height = 7;
const int step24_factor67_width = 6;
int step24_factor67_ridx[] = {18, 19, 20, 21, 22, 23, 24, };
float step24_factor67_data[42] = {0};

const int step24_factor67_num_blks = 1;
int step24_factor67_A_blk_start[] = {0, };
int step24_factor67_B_blk_start[] = {18, };
int step24_factor67_blk_width[] = {6, };

const int step24_factor68_height = 13;
const int step24_factor68_width = 6;
int step24_factor68_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, };
float step24_factor68_data[78] = {0};

const int step24_factor68_num_blks = 1;
int step24_factor68_A_blk_start[] = {0, };
int step24_factor68_B_blk_start[] = {12, };
int step24_factor68_blk_width[] = {12, };

const int step24_factor61_height = 7;
const int step24_factor61_width = 6;
int step24_factor61_ridx[] = {0, 1, 2, 3, 4, 5, 24, };
float step24_factor61_data[42] = {0};

const int step24_factor61_num_blks = 1;
int step24_factor61_A_blk_start[] = {0, };
int step24_factor61_B_blk_start[] = {0, };
int step24_factor61_blk_width[] = {6, };

const int step24_factor62_height = 13;
const int step24_factor62_width = 6;
int step24_factor62_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step24_factor62_data[78] = {0};

const int step24_factor62_num_blks = 1;
int step24_factor62_A_blk_start[] = {0, };
int step24_factor62_B_blk_start[] = {18, };
int step24_factor62_blk_width[] = {12, };

const int step24_factor63_height = 7;
const int step24_factor63_width = 6;
int step24_factor63_ridx[] = {6, 7, 8, 9, 10, 11, 24, };
float step24_factor63_data[42] = {0};

const int step24_factor63_num_blks = 1;
int step24_factor63_A_blk_start[] = {0, };
int step24_factor63_B_blk_start[] = {6, };
int step24_factor63_blk_width[] = {6, };

const int step24_factor64_height = 13;
const int step24_factor64_width = 6;
int step24_factor64_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 24, };
float step24_factor64_data[78] = {0};

const int step24_factor64_num_blks = 1;
int step24_factor64_A_blk_start[] = {0, };
int step24_factor64_B_blk_start[] = {0, };
int step24_factor64_blk_width[] = {12, };

const int step24_factor65_height = 7;
const int step24_factor65_width = 6;
int step24_factor65_ridx[] = {12, 13, 14, 15, 16, 17, 24, };
float step24_factor65_data[42] = {0};

const int step24_factor65_num_blks = 1;
int step24_factor65_A_blk_start[] = {0, };
int step24_factor65_B_blk_start[] = {12, };
int step24_factor65_blk_width[] = {6, };

const int step24_node4_num_factors = 1;
const int step24_node4_relin_cost = 0;
const int step24_node4_sym_cost = 16000;
const bool step24_node4_marked = false;
const bool step24_node4_fixed = true;
int step24_node4_factor_height[] = {step24_factor62_height, };
int step24_node4_factor_width[] = {step24_factor62_width, };
int* step24_node4_factor_ridx[] = {step24_factor62_ridx, };
float* step24_node4_factor_data[] = {step24_factor62_data, };
int step24_node4_factor_num_blks[] = {step24_factor62_num_blks, };
int* step24_node4_factor_A_blk_start[] = {step24_factor62_A_blk_start, };
int* step24_node4_factor_B_blk_start[] = {step24_factor62_B_blk_start, };
int* step24_node4_factor_blk_width[] = {step24_factor62_blk_width, };
const int step24_node4_parent = 5;
const int step24_node4_height = 31;
const int step24_node4_width = 24;
float step24_node4_data[744] = {0};
const int step24_node4_num_blks = 1;
int step24_node4_A_blk_start[] = {0, };
int step24_node4_B_blk_start[] = {0, };
int step24_node4_blk_width[] = {6, };


const int step24_node5_num_factors = 7;
const int step24_node5_relin_cost = 0;
const int step24_node5_sym_cost = 16000;
const bool step24_node5_marked = true;
const bool step24_node5_fixed = false;
int step24_node5_factor_height[] = {step24_factor61_height, step24_factor63_height, step24_factor64_height, step24_factor65_height, step24_factor66_height, step24_factor67_height, step24_factor68_height, };
int step24_node5_factor_width[] = {step24_factor61_width, step24_factor63_width, step24_factor64_width, step24_factor65_width, step24_factor66_width, step24_factor67_width, step24_factor68_width, };
int* step24_node5_factor_ridx[] = {step24_factor61_ridx, step24_factor63_ridx, step24_factor64_ridx, step24_factor65_ridx, step24_factor66_ridx, step24_factor67_ridx, step24_factor68_ridx, };
float* step24_node5_factor_data[] = {step24_factor61_data, step24_factor63_data, step24_factor64_data, step24_factor65_data, step24_factor66_data, step24_factor67_data, step24_factor68_data, };
int step24_node5_factor_num_blks[] = {step24_factor61_num_blks, step24_factor63_num_blks, step24_factor64_num_blks, step24_factor65_num_blks, step24_factor66_num_blks, step24_factor67_num_blks, step24_factor68_num_blks, };
int* step24_node5_factor_A_blk_start[] = {step24_factor61_A_blk_start, step24_factor63_A_blk_start, step24_factor64_A_blk_start, step24_factor65_A_blk_start, step24_factor66_A_blk_start, step24_factor67_A_blk_start, step24_factor68_A_blk_start, };
int* step24_node5_factor_B_blk_start[] = {step24_factor61_B_blk_start, step24_factor63_B_blk_start, step24_factor64_B_blk_start, step24_factor65_B_blk_start, step24_factor66_B_blk_start, step24_factor67_B_blk_start, step24_factor68_B_blk_start, };
int* step24_node5_factor_blk_width[] = {step24_factor61_blk_width, step24_factor63_blk_width, step24_factor64_blk_width, step24_factor65_blk_width, step24_factor66_blk_width, step24_factor67_blk_width, step24_factor68_blk_width, };
const int step24_node5_parent = 6;
const int step24_node5_height = 25;
const int step24_node5_width = 24;
float step24_node5_data[600] = {0};
const int step24_node5_num_blks = 0;
int step24_node5_A_blk_start[] = {};
int step24_node5_B_blk_start[] = {};
int step24_node5_blk_width[] = {};


const int step24_node6_num_factors = 0;
const int step24_node6_relin_cost = 0;
const int step24_node6_sym_cost = 4000;
const bool step24_node6_marked = true;
const bool step24_node6_fixed = false;
int step24_node6_factor_height[] = {};
int step24_node6_factor_width[] = {};
int* step24_node6_factor_ridx[] = {};
float* step24_node6_factor_data[] = {};
int step24_node6_factor_num_blks[] = {};
int* step24_node6_factor_A_blk_start[] = {};
int* step24_node6_factor_B_blk_start[] = {};
int* step24_node6_factor_blk_width[] = {};
const int step24_node6_parent = -1;
const int step24_node6_height = 1;
const int step24_node6_width = 1;
float step24_node6_data[1] = {0};
const int step24_node6_num_blks = 0;
int step24_node6_A_blk_start[] = {};
int step24_node6_B_blk_start[] = {};
int step24_node6_blk_width[] = {};


int step24_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 150, };
int step24_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 150, };
int step24_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 150, };
int step24_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 150, };
int step24_node4_ridx[] = {
102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 150, };
int step24_node5_ridx[] = {
126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, };
int step24_node6_ridx[] = {
150, };
const int step24_nnodes = 7;
bool step24_node_marked[] = {false, false, false, false, step24_node4_marked, step24_node5_marked, step24_node6_marked, };
bool step24_node_fixed[] = {false, false, false, false, step24_node4_fixed, step24_node5_fixed, step24_node6_fixed, };
int step24_node_num_factors[] = {0, 0, 0, 0, step24_node4_num_factors, step24_node5_num_factors, step24_node6_num_factors, };
int step24_node_relin_cost[] = {0, 0, 0, 0, step24_node4_relin_cost, step24_node5_relin_cost, step24_node6_relin_cost, };
int step24_node_sym_cost[] = {0, 0, 0, 0, step24_node4_sym_cost, step24_node5_sym_cost, step24_node6_sym_cost, };
int* step24_node_factor_height[] = {0, 0, 0, 0, step24_node4_factor_height, step24_node5_factor_height, step24_node6_factor_height, };
int* step24_node_factor_width[] = {0, 0, 0, 0, step24_node4_factor_width, step24_node5_factor_width, step24_node6_factor_width, };
int** step24_node_factor_ridx[] = {0, 0, 0, 0, step24_node4_factor_ridx, step24_node5_factor_ridx, step24_node6_factor_ridx, };
float** step24_node_factor_data[] = {0, 0, 0, 0, step24_node4_factor_data, step24_node5_factor_data, step24_node6_factor_data, };
int* step24_node_factor_num_blks[] = {0, 0, 0, 0, step24_node4_factor_num_blks, step24_node5_factor_num_blks, step24_node6_factor_num_blks, };
int** step24_node_factor_A_blk_start[] = {0, 0, 0, 0, step24_node4_factor_A_blk_start, step24_node5_factor_A_blk_start, step24_node6_factor_A_blk_start, };
int** step24_node_factor_B_blk_start[] = {0, 0, 0, 0, step24_node4_factor_B_blk_start, step24_node5_factor_B_blk_start, step24_node6_factor_B_blk_start, };
int** step24_node_factor_blk_width[] = {0, 0, 0, 0, step24_node4_factor_blk_width, step24_node5_factor_blk_width, step24_node6_factor_blk_width, };
int step24_node_parent[] = {0, 0, 0, 0, step24_node4_parent, step24_node5_parent, step24_node6_parent, };
int step24_node_height[] = {0, 0, 0, 0, step24_node4_height, step24_node5_height, step24_node6_height, };
int step24_node_width[] = {0, 0, 0, 0, step24_node4_width, step24_node5_width, step24_node6_width, };
float* step24_node_data[] = {0, 0, 0, 0, step24_node4_data, step24_node5_data, step24_node6_data, };
int step24_node_num_blks[] = {0, 0, 0, 0, step24_node4_num_blks, step24_node5_num_blks, step24_node6_num_blks, };
int* step24_node_A_blk_start[] = {0, 0, 0, 0, step24_node4_A_blk_start, step24_node5_A_blk_start, step24_node6_A_blk_start, };
int* step24_node_B_blk_start[] = {0, 0, 0, 0, step24_node4_B_blk_start, step24_node5_B_blk_start, step24_node6_B_blk_start, };
int* step24_node_blk_width[] = {0, 0, 0, 0, step24_node4_blk_width, step24_node5_blk_width, step24_node6_blk_width, };
int* step24_node_ridx[] = {step24_node0_ridx, step24_node1_ridx, step24_node2_ridx, step24_node3_ridx, step24_node4_ridx, step24_node5_ridx, step24_node6_ridx, };


float step24_x_data[151] = {};
const int step24_workspace_needed = 6648;

