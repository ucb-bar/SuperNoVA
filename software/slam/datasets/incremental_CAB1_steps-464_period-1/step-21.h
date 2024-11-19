#pragma once

const bool step21_is_reconstruct = true;

const int step21_num_threads = 1;

const uint64_t step21_scaled_relin_cost = 0;

const bool step21_run_model = false;

const int step21_factor60_height = 13;
const int step21_factor60_width = 6;
int step21_factor60_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 30, };
float step21_factor60_data[78] = {0};

const int step21_factor60_num_blks = 1;
int step21_factor60_A_blk_start[] = {0, };
int step21_factor60_B_blk_start[] = {12, };
int step21_factor60_blk_width[] = {12, };

const int step21_factor61_height = 7;
const int step21_factor61_width = 6;
int step21_factor61_ridx[] = {24, 25, 26, 27, 28, 29, 30, };
float step21_factor61_data[42] = {0};

const int step21_factor61_num_blks = 1;
int step21_factor61_A_blk_start[] = {0, };
int step21_factor61_B_blk_start[] = {24, };
int step21_factor61_blk_width[] = {6, };

const int step21_factor62_height = 13;
const int step21_factor62_width = 6;
int step21_factor62_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step21_factor62_data[78] = {0};

const int step21_factor62_num_blks = 1;
int step21_factor62_A_blk_start[] = {0, };
int step21_factor62_B_blk_start[] = {18, };
int step21_factor62_blk_width[] = {12, };

const int step21_factor53_height = 7;
const int step21_factor53_width = 6;
int step21_factor53_ridx[] = {0, 1, 2, 3, 4, 5, 30, };
float step21_factor53_data[42] = {0};

const int step21_factor53_num_blks = 1;
int step21_factor53_A_blk_start[] = {0, };
int step21_factor53_B_blk_start[] = {0, };
int step21_factor53_blk_width[] = {6, };

const int step21_factor54_height = 13;
const int step21_factor54_width = 6;
int step21_factor54_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step21_factor54_data[78] = {0};

const int step21_factor54_num_blks = 1;
int step21_factor54_A_blk_start[] = {0, };
int step21_factor54_B_blk_start[] = {18, };
int step21_factor54_blk_width[] = {12, };

const int step21_factor55_height = 7;
const int step21_factor55_width = 6;
int step21_factor55_ridx[] = {6, 7, 8, 9, 10, 11, 30, };
float step21_factor55_data[42] = {0};

const int step21_factor55_num_blks = 1;
int step21_factor55_A_blk_start[] = {0, };
int step21_factor55_B_blk_start[] = {6, };
int step21_factor55_blk_width[] = {6, };

const int step21_factor56_height = 13;
const int step21_factor56_width = 6;
int step21_factor56_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 30, };
float step21_factor56_data[78] = {0};

const int step21_factor56_num_blks = 1;
int step21_factor56_A_blk_start[] = {0, };
int step21_factor56_B_blk_start[] = {0, };
int step21_factor56_blk_width[] = {12, };

const int step21_factor57_height = 7;
const int step21_factor57_width = 6;
int step21_factor57_ridx[] = {12, 13, 14, 15, 16, 17, 30, };
float step21_factor57_data[42] = {0};

const int step21_factor57_num_blks = 1;
int step21_factor57_A_blk_start[] = {0, };
int step21_factor57_B_blk_start[] = {12, };
int step21_factor57_blk_width[] = {6, };

const int step21_factor58_height = 13;
const int step21_factor58_width = 6;
int step21_factor58_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 30, };
float step21_factor58_data[78] = {0};

const int step21_factor58_num_blks = 1;
int step21_factor58_A_blk_start[] = {0, };
int step21_factor58_B_blk_start[] = {6, };
int step21_factor58_blk_width[] = {12, };

const int step21_factor59_height = 7;
const int step21_factor59_width = 6;
int step21_factor59_ridx[] = {18, 19, 20, 21, 22, 23, 30, };
float step21_factor59_data[42] = {0};

const int step21_factor59_num_blks = 1;
int step21_factor59_A_blk_start[] = {0, };
int step21_factor59_B_blk_start[] = {18, };
int step21_factor59_blk_width[] = {6, };

const int step21_node3_num_factors = 1;
const int step21_node3_relin_cost = 30000;
const bool step21_node3_marked = false;
const bool step21_node3_fixed = true;
int step21_node3_factor_height[] = {step21_factor54_height, };
int step21_node3_factor_width[] = {step21_factor54_width, };
int* step21_node3_factor_ridx[] = {step21_factor54_ridx, };
float* step21_node3_factor_data[] = {step21_factor54_data, };
int step21_node3_factor_num_blks[] = {step21_factor54_num_blks, };
int* step21_node3_factor_A_blk_start[] = {step21_factor54_A_blk_start, };
int* step21_node3_factor_B_blk_start[] = {step21_factor54_B_blk_start, };
int* step21_node3_factor_blk_width[] = {step21_factor54_blk_width, };
const int step21_node3_parent = 4;
const int step21_node3_height = 31;
const int step21_node3_width = 24;
float step21_node3_data[744] = {0};
const int step21_node3_num_blks = 1;
int step21_node3_A_blk_start[] = {0, };
int step21_node3_B_blk_start[] = {0, };
int step21_node3_blk_width[] = {6, };


const int step21_node4_num_factors = 9;
const int step21_node4_relin_cost = 270000;
const bool step21_node4_marked = true;
const bool step21_node4_fixed = false;
int step21_node4_factor_height[] = {step21_factor53_height, step21_factor55_height, step21_factor56_height, step21_factor57_height, step21_factor58_height, step21_factor59_height, step21_factor60_height, step21_factor61_height, step21_factor62_height, };
int step21_node4_factor_width[] = {step21_factor53_width, step21_factor55_width, step21_factor56_width, step21_factor57_width, step21_factor58_width, step21_factor59_width, step21_factor60_width, step21_factor61_width, step21_factor62_width, };
int* step21_node4_factor_ridx[] = {step21_factor53_ridx, step21_factor55_ridx, step21_factor56_ridx, step21_factor57_ridx, step21_factor58_ridx, step21_factor59_ridx, step21_factor60_ridx, step21_factor61_ridx, step21_factor62_ridx, };
float* step21_node4_factor_data[] = {step21_factor53_data, step21_factor55_data, step21_factor56_data, step21_factor57_data, step21_factor58_data, step21_factor59_data, step21_factor60_data, step21_factor61_data, step21_factor62_data, };
int step21_node4_factor_num_blks[] = {step21_factor53_num_blks, step21_factor55_num_blks, step21_factor56_num_blks, step21_factor57_num_blks, step21_factor58_num_blks, step21_factor59_num_blks, step21_factor60_num_blks, step21_factor61_num_blks, step21_factor62_num_blks, };
int* step21_node4_factor_A_blk_start[] = {step21_factor53_A_blk_start, step21_factor55_A_blk_start, step21_factor56_A_blk_start, step21_factor57_A_blk_start, step21_factor58_A_blk_start, step21_factor59_A_blk_start, step21_factor60_A_blk_start, step21_factor61_A_blk_start, step21_factor62_A_blk_start, };
int* step21_node4_factor_B_blk_start[] = {step21_factor53_B_blk_start, step21_factor55_B_blk_start, step21_factor56_B_blk_start, step21_factor57_B_blk_start, step21_factor58_B_blk_start, step21_factor59_B_blk_start, step21_factor60_B_blk_start, step21_factor61_B_blk_start, step21_factor62_B_blk_start, };
int* step21_node4_factor_blk_width[] = {step21_factor53_blk_width, step21_factor55_blk_width, step21_factor56_blk_width, step21_factor57_blk_width, step21_factor58_blk_width, step21_factor59_blk_width, step21_factor60_blk_width, step21_factor61_blk_width, step21_factor62_blk_width, };
const int step21_node4_parent = 5;
const int step21_node4_height = 31;
const int step21_node4_width = 30;
float step21_node4_data[930] = {0};
const int step21_node4_num_blks = 0;
int step21_node4_A_blk_start[] = {};
int step21_node4_B_blk_start[] = {};
int step21_node4_blk_width[] = {};


const int step21_node5_num_factors = 0;
const int step21_node5_relin_cost = 0;
const bool step21_node5_marked = true;
const bool step21_node5_fixed = false;
int step21_node5_factor_height[] = {};
int step21_node5_factor_width[] = {};
int* step21_node5_factor_ridx[] = {};
float* step21_node5_factor_data[] = {};
int step21_node5_factor_num_blks[] = {};
int* step21_node5_factor_A_blk_start[] = {};
int* step21_node5_factor_B_blk_start[] = {};
int* step21_node5_factor_blk_width[] = {};
const int step21_node5_parent = -1;
const int step21_node5_height = 1;
const int step21_node5_width = 1;
float step21_node5_data[1] = {0};
const int step21_node5_num_blks = 0;
int step21_node5_A_blk_start[] = {};
int step21_node5_B_blk_start[] = {};
int step21_node5_blk_width[] = {};


int step21_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 132, };
int step21_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 132, };
int step21_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 132, };
int step21_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 132, };
int step21_node4_ridx[] = {
102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, };
int step21_node5_ridx[] = {
132, };
const int step21_nnodes = 6;
bool step21_node_marked[] = {false, false, false, step21_node3_marked, step21_node4_marked, step21_node5_marked, };
bool step21_node_fixed[] = {false, false, false, step21_node3_fixed, step21_node4_fixed, step21_node5_fixed, };
int step21_node_num_factors[] = {0, 0, 0, step21_node3_num_factors, step21_node4_num_factors, step21_node5_num_factors, };
int step21_node_relin_cost[] = {0, 0, 0, step21_node3_relin_cost, step21_node4_relin_cost, step21_node5_relin_cost, };
int* step21_node_factor_height[] = {0, 0, 0, step21_node3_factor_height, step21_node4_factor_height, step21_node5_factor_height, };
int* step21_node_factor_width[] = {0, 0, 0, step21_node3_factor_width, step21_node4_factor_width, step21_node5_factor_width, };
int** step21_node_factor_ridx[] = {0, 0, 0, step21_node3_factor_ridx, step21_node4_factor_ridx, step21_node5_factor_ridx, };
float** step21_node_factor_data[] = {0, 0, 0, step21_node3_factor_data, step21_node4_factor_data, step21_node5_factor_data, };
int* step21_node_factor_num_blks[] = {0, 0, 0, step21_node3_factor_num_blks, step21_node4_factor_num_blks, step21_node5_factor_num_blks, };
int** step21_node_factor_A_blk_start[] = {0, 0, 0, step21_node3_factor_A_blk_start, step21_node4_factor_A_blk_start, step21_node5_factor_A_blk_start, };
int** step21_node_factor_B_blk_start[] = {0, 0, 0, step21_node3_factor_B_blk_start, step21_node4_factor_B_blk_start, step21_node5_factor_B_blk_start, };
int** step21_node_factor_blk_width[] = {0, 0, 0, step21_node3_factor_blk_width, step21_node4_factor_blk_width, step21_node5_factor_blk_width, };
int step21_node_parent[] = {0, 0, 0, step21_node3_parent, step21_node4_parent, step21_node5_parent, };
int step21_node_height[] = {0, 0, 0, step21_node3_height, step21_node4_height, step21_node5_height, };
int step21_node_width[] = {0, 0, 0, step21_node3_width, step21_node4_width, step21_node5_width, };
float* step21_node_data[] = {0, 0, 0, step21_node3_data, step21_node4_data, step21_node5_data, };
int step21_node_num_blks[] = {0, 0, 0, step21_node3_num_blks, step21_node4_num_blks, step21_node5_num_blks, };
int* step21_node_A_blk_start[] = {0, 0, 0, step21_node3_A_blk_start, step21_node4_A_blk_start, step21_node5_A_blk_start, };
int* step21_node_B_blk_start[] = {0, 0, 0, step21_node3_B_blk_start, step21_node4_B_blk_start, step21_node5_B_blk_start, };
int* step21_node_blk_width[] = {0, 0, 0, step21_node3_blk_width, step21_node4_blk_width, step21_node5_blk_width, };
int* step21_node_ridx[] = {step21_node0_ridx, step21_node1_ridx, step21_node2_ridx, step21_node3_ridx, step21_node4_ridx, step21_node5_ridx, };


float step21_x_data[133] = {};
const int step21_workspace_needed = 7992;

