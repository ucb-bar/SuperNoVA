#pragma once

const bool step25_is_reconstruct = true;

const int step25_num_threads = 1;

const uint64_t step25_scaled_relin_cost = 0;

const bool step25_run_model = false;

const int step25_factor66_height = 13;
const int step25_factor66_width = 6;
int step25_factor66_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 30, };
float step25_factor66_data[78] = {0};

const int step25_factor66_num_blks = 1;
int step25_factor66_A_blk_start[] = {0, };
int step25_factor66_B_blk_start[] = {6, };
int step25_factor66_blk_width[] = {12, };

const int step25_factor67_height = 7;
const int step25_factor67_width = 6;
int step25_factor67_ridx[] = {18, 19, 20, 21, 22, 23, 30, };
float step25_factor67_data[42] = {0};

const int step25_factor67_num_blks = 1;
int step25_factor67_A_blk_start[] = {0, };
int step25_factor67_B_blk_start[] = {18, };
int step25_factor67_blk_width[] = {6, };

const int step25_factor68_height = 13;
const int step25_factor68_width = 6;
int step25_factor68_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 30, };
float step25_factor68_data[78] = {0};

const int step25_factor68_num_blks = 1;
int step25_factor68_A_blk_start[] = {0, };
int step25_factor68_B_blk_start[] = {12, };
int step25_factor68_blk_width[] = {12, };

const int step25_factor69_height = 7;
const int step25_factor69_width = 6;
int step25_factor69_ridx[] = {24, 25, 26, 27, 28, 29, 30, };
float step25_factor69_data[42] = {0};

const int step25_factor69_num_blks = 1;
int step25_factor69_A_blk_start[] = {0, };
int step25_factor69_B_blk_start[] = {24, };
int step25_factor69_blk_width[] = {6, };

const int step25_factor70_height = 13;
const int step25_factor70_width = 6;
int step25_factor70_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step25_factor70_data[78] = {0};

const int step25_factor70_num_blks = 1;
int step25_factor70_A_blk_start[] = {0, };
int step25_factor70_B_blk_start[] = {18, };
int step25_factor70_blk_width[] = {12, };

const int step25_factor61_height = 7;
const int step25_factor61_width = 6;
int step25_factor61_ridx[] = {0, 1, 2, 3, 4, 5, 30, };
float step25_factor61_data[42] = {0};

const int step25_factor61_num_blks = 1;
int step25_factor61_A_blk_start[] = {0, };
int step25_factor61_B_blk_start[] = {0, };
int step25_factor61_blk_width[] = {6, };

const int step25_factor62_height = 13;
const int step25_factor62_width = 6;
int step25_factor62_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step25_factor62_data[78] = {0};

const int step25_factor62_num_blks = 1;
int step25_factor62_A_blk_start[] = {0, };
int step25_factor62_B_blk_start[] = {18, };
int step25_factor62_blk_width[] = {12, };

const int step25_factor63_height = 7;
const int step25_factor63_width = 6;
int step25_factor63_ridx[] = {6, 7, 8, 9, 10, 11, 30, };
float step25_factor63_data[42] = {0};

const int step25_factor63_num_blks = 1;
int step25_factor63_A_blk_start[] = {0, };
int step25_factor63_B_blk_start[] = {6, };
int step25_factor63_blk_width[] = {6, };

const int step25_factor64_height = 13;
const int step25_factor64_width = 6;
int step25_factor64_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 30, };
float step25_factor64_data[78] = {0};

const int step25_factor64_num_blks = 1;
int step25_factor64_A_blk_start[] = {0, };
int step25_factor64_B_blk_start[] = {0, };
int step25_factor64_blk_width[] = {12, };

const int step25_factor65_height = 7;
const int step25_factor65_width = 6;
int step25_factor65_ridx[] = {12, 13, 14, 15, 16, 17, 30, };
float step25_factor65_data[42] = {0};

const int step25_factor65_num_blks = 1;
int step25_factor65_A_blk_start[] = {0, };
int step25_factor65_B_blk_start[] = {12, };
int step25_factor65_blk_width[] = {6, };

const int step25_node4_num_factors = 1;
const int step25_node4_relin_cost = 0;
const int step25_node4_sym_cost = 16000;
const bool step25_node4_marked = false;
const bool step25_node4_fixed = true;
int step25_node4_factor_height[] = {step25_factor62_height, };
int step25_node4_factor_width[] = {step25_factor62_width, };
int* step25_node4_factor_ridx[] = {step25_factor62_ridx, };
float* step25_node4_factor_data[] = {step25_factor62_data, };
int step25_node4_factor_num_blks[] = {step25_factor62_num_blks, };
int* step25_node4_factor_A_blk_start[] = {step25_factor62_A_blk_start, };
int* step25_node4_factor_B_blk_start[] = {step25_factor62_B_blk_start, };
int* step25_node4_factor_blk_width[] = {step25_factor62_blk_width, };
const int step25_node4_parent = 5;
const int step25_node4_height = 31;
const int step25_node4_width = 24;
float step25_node4_data[744] = {0};
const int step25_node4_num_blks = 1;
int step25_node4_A_blk_start[] = {0, };
int step25_node4_B_blk_start[] = {0, };
int step25_node4_blk_width[] = {6, };


const int step25_node5_num_factors = 9;
const int step25_node5_relin_cost = 0;
const int step25_node5_sym_cost = 20000;
const bool step25_node5_marked = true;
const bool step25_node5_fixed = false;
int step25_node5_factor_height[] = {step25_factor61_height, step25_factor63_height, step25_factor64_height, step25_factor65_height, step25_factor66_height, step25_factor67_height, step25_factor68_height, step25_factor69_height, step25_factor70_height, };
int step25_node5_factor_width[] = {step25_factor61_width, step25_factor63_width, step25_factor64_width, step25_factor65_width, step25_factor66_width, step25_factor67_width, step25_factor68_width, step25_factor69_width, step25_factor70_width, };
int* step25_node5_factor_ridx[] = {step25_factor61_ridx, step25_factor63_ridx, step25_factor64_ridx, step25_factor65_ridx, step25_factor66_ridx, step25_factor67_ridx, step25_factor68_ridx, step25_factor69_ridx, step25_factor70_ridx, };
float* step25_node5_factor_data[] = {step25_factor61_data, step25_factor63_data, step25_factor64_data, step25_factor65_data, step25_factor66_data, step25_factor67_data, step25_factor68_data, step25_factor69_data, step25_factor70_data, };
int step25_node5_factor_num_blks[] = {step25_factor61_num_blks, step25_factor63_num_blks, step25_factor64_num_blks, step25_factor65_num_blks, step25_factor66_num_blks, step25_factor67_num_blks, step25_factor68_num_blks, step25_factor69_num_blks, step25_factor70_num_blks, };
int* step25_node5_factor_A_blk_start[] = {step25_factor61_A_blk_start, step25_factor63_A_blk_start, step25_factor64_A_blk_start, step25_factor65_A_blk_start, step25_factor66_A_blk_start, step25_factor67_A_blk_start, step25_factor68_A_blk_start, step25_factor69_A_blk_start, step25_factor70_A_blk_start, };
int* step25_node5_factor_B_blk_start[] = {step25_factor61_B_blk_start, step25_factor63_B_blk_start, step25_factor64_B_blk_start, step25_factor65_B_blk_start, step25_factor66_B_blk_start, step25_factor67_B_blk_start, step25_factor68_B_blk_start, step25_factor69_B_blk_start, step25_factor70_B_blk_start, };
int* step25_node5_factor_blk_width[] = {step25_factor61_blk_width, step25_factor63_blk_width, step25_factor64_blk_width, step25_factor65_blk_width, step25_factor66_blk_width, step25_factor67_blk_width, step25_factor68_blk_width, step25_factor69_blk_width, step25_factor70_blk_width, };
const int step25_node5_parent = 6;
const int step25_node5_height = 31;
const int step25_node5_width = 30;
float step25_node5_data[930] = {0};
const int step25_node5_num_blks = 0;
int step25_node5_A_blk_start[] = {};
int step25_node5_B_blk_start[] = {};
int step25_node5_blk_width[] = {};


const int step25_node6_num_factors = 0;
const int step25_node6_relin_cost = 0;
const int step25_node6_sym_cost = 4000;
const bool step25_node6_marked = true;
const bool step25_node6_fixed = false;
int step25_node6_factor_height[] = {};
int step25_node6_factor_width[] = {};
int* step25_node6_factor_ridx[] = {};
float* step25_node6_factor_data[] = {};
int step25_node6_factor_num_blks[] = {};
int* step25_node6_factor_A_blk_start[] = {};
int* step25_node6_factor_B_blk_start[] = {};
int* step25_node6_factor_blk_width[] = {};
const int step25_node6_parent = -1;
const int step25_node6_height = 1;
const int step25_node6_width = 1;
float step25_node6_data[1] = {0};
const int step25_node6_num_blks = 0;
int step25_node6_A_blk_start[] = {};
int step25_node6_B_blk_start[] = {};
int step25_node6_blk_width[] = {};


int step25_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 156, };
int step25_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 156, };
int step25_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 156, };
int step25_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 156, };
int step25_node4_ridx[] = {
102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 156, };
int step25_node5_ridx[] = {
126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, };
int step25_node6_ridx[] = {
156, };
const int step25_nnodes = 7;
bool step25_node_marked[] = {false, false, false, false, step25_node4_marked, step25_node5_marked, step25_node6_marked, };
bool step25_node_fixed[] = {false, false, false, false, step25_node4_fixed, step25_node5_fixed, step25_node6_fixed, };
int step25_node_num_factors[] = {0, 0, 0, 0, step25_node4_num_factors, step25_node5_num_factors, step25_node6_num_factors, };
int step25_node_relin_cost[] = {0, 0, 0, 0, step25_node4_relin_cost, step25_node5_relin_cost, step25_node6_relin_cost, };
int step25_node_sym_cost[] = {0, 0, 0, 0, step25_node4_sym_cost, step25_node5_sym_cost, step25_node6_sym_cost, };
int* step25_node_factor_height[] = {0, 0, 0, 0, step25_node4_factor_height, step25_node5_factor_height, step25_node6_factor_height, };
int* step25_node_factor_width[] = {0, 0, 0, 0, step25_node4_factor_width, step25_node5_factor_width, step25_node6_factor_width, };
int** step25_node_factor_ridx[] = {0, 0, 0, 0, step25_node4_factor_ridx, step25_node5_factor_ridx, step25_node6_factor_ridx, };
float** step25_node_factor_data[] = {0, 0, 0, 0, step25_node4_factor_data, step25_node5_factor_data, step25_node6_factor_data, };
int* step25_node_factor_num_blks[] = {0, 0, 0, 0, step25_node4_factor_num_blks, step25_node5_factor_num_blks, step25_node6_factor_num_blks, };
int** step25_node_factor_A_blk_start[] = {0, 0, 0, 0, step25_node4_factor_A_blk_start, step25_node5_factor_A_blk_start, step25_node6_factor_A_blk_start, };
int** step25_node_factor_B_blk_start[] = {0, 0, 0, 0, step25_node4_factor_B_blk_start, step25_node5_factor_B_blk_start, step25_node6_factor_B_blk_start, };
int** step25_node_factor_blk_width[] = {0, 0, 0, 0, step25_node4_factor_blk_width, step25_node5_factor_blk_width, step25_node6_factor_blk_width, };
int step25_node_parent[] = {0, 0, 0, 0, step25_node4_parent, step25_node5_parent, step25_node6_parent, };
int step25_node_height[] = {0, 0, 0, 0, step25_node4_height, step25_node5_height, step25_node6_height, };
int step25_node_width[] = {0, 0, 0, 0, step25_node4_width, step25_node5_width, step25_node6_width, };
float* step25_node_data[] = {0, 0, 0, 0, step25_node4_data, step25_node5_data, step25_node6_data, };
int step25_node_num_blks[] = {0, 0, 0, 0, step25_node4_num_blks, step25_node5_num_blks, step25_node6_num_blks, };
int* step25_node_A_blk_start[] = {0, 0, 0, 0, step25_node4_A_blk_start, step25_node5_A_blk_start, step25_node6_A_blk_start, };
int* step25_node_B_blk_start[] = {0, 0, 0, 0, step25_node4_B_blk_start, step25_node5_B_blk_start, step25_node6_B_blk_start, };
int* step25_node_blk_width[] = {0, 0, 0, 0, step25_node4_blk_width, step25_node5_blk_width, step25_node6_blk_width, };
int* step25_node_ridx[] = {step25_node0_ridx, step25_node1_ridx, step25_node2_ridx, step25_node3_ridx, step25_node4_ridx, step25_node5_ridx, step25_node6_ridx, };


float step25_x_data[157] = {};
const int step25_workspace_needed = 7992;

