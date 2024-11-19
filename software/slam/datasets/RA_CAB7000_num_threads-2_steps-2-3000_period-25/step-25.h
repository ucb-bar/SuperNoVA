#pragma once

const bool step25_is_reconstruct = true;

const int step25_num_threads = 1;

const uint64_t step25_scaled_relin_cost = 0;

const bool step25_run_model = false;

const int step25_factor63_height = 7;
const int step25_factor63_width = 6;
int step25_factor63_ridx[] = {36, 37, 38, 39, 40, 41, 42, };
float step25_factor63_data[42] = {0};

const int step25_factor63_num_blks = 1;
int step25_factor63_A_blk_start[] = {0, };
int step25_factor63_B_blk_start[] = {36, };
int step25_factor63_blk_width[] = {6, };

const int step25_factor64_height = 13;
const int step25_factor64_width = 6;
int step25_factor64_ridx[] = {12, 13, 14, 15, 16, 17, 54, 55, 56, 57, 58, 59, 60, };
float step25_factor64_data[78] = {0};

const int step25_factor64_num_blks = 2;
int step25_factor64_A_blk_start[] = {0, 6, };
int step25_factor64_B_blk_start[] = {12, 54, };
int step25_factor64_blk_width[] = {6, 6, };

const int step25_factor65_height = 13;
const int step25_factor65_width = 6;
int step25_factor65_ridx[] = {18, 19, 20, 21, 22, 23, 36, 37, 38, 39, 40, 41, 42, };
float step25_factor65_data[78] = {0};

const int step25_factor65_num_blks = 2;
int step25_factor65_A_blk_start[] = {0, 6, };
int step25_factor65_B_blk_start[] = {18, 36, };
int step25_factor65_blk_width[] = {6, 6, };

const int step25_factor66_height = 13;
const int step25_factor66_width = 6;
int step25_factor66_ridx[] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, };
float step25_factor66_data[78] = {0};

const int step25_factor66_num_blks = 1;
int step25_factor66_A_blk_start[] = {0, };
int step25_factor66_B_blk_start[] = {30, };
int step25_factor66_blk_width[] = {12, };

const int step25_factor44_height = 7;
const int step25_factor44_width = 6;
int step25_factor44_ridx[] = {0, 1, 2, 3, 4, 5, 42, };
float step25_factor44_data[42] = {0};

const int step25_factor44_num_blks = 1;
int step25_factor44_A_blk_start[] = {0, };
int step25_factor44_B_blk_start[] = {0, };
int step25_factor44_blk_width[] = {6, };

const int step25_factor45_height = 13;
const int step25_factor45_width = 6;
int step25_factor45_ridx[] = {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 60, };
float step25_factor45_data[78] = {0};

const int step25_factor45_num_blks = 1;
int step25_factor45_A_blk_start[] = {0, };
int step25_factor45_B_blk_start[] = {24, };
int step25_factor45_blk_width[] = {12, };

const int step25_factor46_height = 13;
const int step25_factor46_width = 6;
int step25_factor46_ridx[] = {18, 19, 20, 21, 22, 23, 30, 31, 32, 33, 34, 35, 60, };
float step25_factor46_data[78] = {0};

const int step25_factor46_num_blks = 2;
int step25_factor46_A_blk_start[] = {0, 6, };
int step25_factor46_B_blk_start[] = {18, 30, };
int step25_factor46_blk_width[] = {6, 6, };

const int step25_factor47_height = 7;
const int step25_factor47_width = 6;
int step25_factor47_ridx[] = {6, 7, 8, 9, 10, 11, 42, };
float step25_factor47_data[42] = {0};

const int step25_factor47_num_blks = 1;
int step25_factor47_A_blk_start[] = {0, };
int step25_factor47_B_blk_start[] = {6, };
int step25_factor47_blk_width[] = {6, };

const int step25_factor48_height = 13;
const int step25_factor48_width = 6;
int step25_factor48_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 42, };
float step25_factor48_data[78] = {0};

const int step25_factor48_num_blks = 1;
int step25_factor48_A_blk_start[] = {0, };
int step25_factor48_B_blk_start[] = {0, };
int step25_factor48_blk_width[] = {12, };

const int step25_factor49_height = 7;
const int step25_factor49_width = 6;
int step25_factor49_ridx[] = {12, 13, 14, 15, 16, 17, 42, };
float step25_factor49_data[42] = {0};

const int step25_factor49_num_blks = 1;
int step25_factor49_A_blk_start[] = {0, };
int step25_factor49_B_blk_start[] = {12, };
int step25_factor49_blk_width[] = {6, };

const int step25_factor50_height = 13;
const int step25_factor50_width = 6;
int step25_factor50_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 42, };
float step25_factor50_data[78] = {0};

const int step25_factor50_num_blks = 1;
int step25_factor50_A_blk_start[] = {0, };
int step25_factor50_B_blk_start[] = {6, };
int step25_factor50_blk_width[] = {12, };

const int step25_factor51_height = 7;
const int step25_factor51_width = 6;
int step25_factor51_ridx[] = {18, 19, 20, 21, 22, 23, 42, };
float step25_factor51_data[42] = {0};

const int step25_factor51_num_blks = 1;
int step25_factor51_A_blk_start[] = {0, };
int step25_factor51_B_blk_start[] = {18, };
int step25_factor51_blk_width[] = {6, };

const int step25_factor52_height = 13;
const int step25_factor52_width = 6;
int step25_factor52_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, };
float step25_factor52_data[78] = {0};

const int step25_factor52_num_blks = 1;
int step25_factor52_A_blk_start[] = {0, };
int step25_factor52_B_blk_start[] = {12, };
int step25_factor52_blk_width[] = {12, };

const int step25_factor53_height = 13;
const int step25_factor53_width = 6;
int step25_factor53_ridx[] = {6, 7, 8, 9, 10, 11, 36, 37, 38, 39, 40, 41, 60, };
float step25_factor53_data[78] = {0};

const int step25_factor53_num_blks = 2;
int step25_factor53_A_blk_start[] = {0, 6, };
int step25_factor53_B_blk_start[] = {6, 36, };
int step25_factor53_blk_width[] = {6, 6, };

const int step25_factor54_height = 13;
const int step25_factor54_width = 6;
int step25_factor54_ridx[] = {12, 13, 14, 15, 16, 17, 36, 37, 38, 39, 40, 41, 60, };
float step25_factor54_data[78] = {0};

const int step25_factor54_num_blks = 2;
int step25_factor54_A_blk_start[] = {0, 6, };
int step25_factor54_B_blk_start[] = {12, 36, };
int step25_factor54_blk_width[] = {6, 6, };

const int step25_factor55_height = 7;
const int step25_factor55_width = 6;
int step25_factor55_ridx[] = {24, 25, 26, 27, 28, 29, 42, };
float step25_factor55_data[42] = {0};

const int step25_factor55_num_blks = 1;
int step25_factor55_A_blk_start[] = {0, };
int step25_factor55_B_blk_start[] = {24, };
int step25_factor55_blk_width[] = {6, };

const int step25_factor56_height = 13;
const int step25_factor56_width = 6;
int step25_factor56_ridx[] = {6, 7, 8, 9, 10, 11, 42, 43, 44, 45, 46, 47, 60, };
float step25_factor56_data[78] = {0};

const int step25_factor56_num_blks = 2;
int step25_factor56_A_blk_start[] = {0, 6, };
int step25_factor56_B_blk_start[] = {6, 42, };
int step25_factor56_blk_width[] = {6, 6, };

const int step25_factor57_height = 13;
const int step25_factor57_width = 6;
int step25_factor57_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 42, };
float step25_factor57_data[78] = {0};

const int step25_factor57_num_blks = 1;
int step25_factor57_A_blk_start[] = {0, };
int step25_factor57_B_blk_start[] = {18, };
int step25_factor57_blk_width[] = {12, };

const int step25_factor58_height = 7;
const int step25_factor58_width = 6;
int step25_factor58_ridx[] = {30, 31, 32, 33, 34, 35, 42, };
float step25_factor58_data[42] = {0};

const int step25_factor58_num_blks = 1;
int step25_factor58_A_blk_start[] = {0, };
int step25_factor58_B_blk_start[] = {30, };
int step25_factor58_blk_width[] = {6, };

const int step25_factor59_height = 13;
const int step25_factor59_width = 6;
int step25_factor59_ridx[] = {6, 7, 8, 9, 10, 11, 48, 49, 50, 51, 52, 53, 60, };
float step25_factor59_data[78] = {0};

const int step25_factor59_num_blks = 2;
int step25_factor59_A_blk_start[] = {0, 6, };
int step25_factor59_B_blk_start[] = {6, 48, };
int step25_factor59_blk_width[] = {6, 6, };

const int step25_factor60_height = 13;
const int step25_factor60_width = 6;
int step25_factor60_ridx[] = {18, 19, 20, 21, 22, 23, 30, 31, 32, 33, 34, 35, 42, };
float step25_factor60_data[78] = {0};

const int step25_factor60_num_blks = 2;
int step25_factor60_A_blk_start[] = {0, 6, };
int step25_factor60_B_blk_start[] = {18, 30, };
int step25_factor60_blk_width[] = {6, 6, };

const int step25_factor61_height = 13;
const int step25_factor61_width = 6;
int step25_factor61_ridx[] = {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 42, };
float step25_factor61_data[78] = {0};

const int step25_factor61_num_blks = 1;
int step25_factor61_A_blk_start[] = {0, };
int step25_factor61_B_blk_start[] = {24, };
int step25_factor61_blk_width[] = {12, };

const int step25_factor62_height = 13;
const int step25_factor62_width = 6;
int step25_factor62_ridx[] = {12, 13, 14, 15, 16, 17, 48, 49, 50, 51, 52, 53, 60, };
float step25_factor62_data[78] = {0};

const int step25_factor62_num_blks = 2;
int step25_factor62_A_blk_start[] = {0, 6, };
int step25_factor62_B_blk_start[] = {12, 48, };
int step25_factor62_blk_width[] = {6, 6, };

const int step25_node3_num_factors = 8;
const int step25_node3_relin_cost = 240000;
const bool step25_node3_marked = false;
const bool step25_node3_fixed = true;
int step25_node3_factor_height[] = {step25_factor45_height, step25_factor46_height, step25_factor53_height, step25_factor54_height, step25_factor56_height, step25_factor59_height, step25_factor62_height, step25_factor64_height, };
int step25_node3_factor_width[] = {step25_factor45_width, step25_factor46_width, step25_factor53_width, step25_factor54_width, step25_factor56_width, step25_factor59_width, step25_factor62_width, step25_factor64_width, };
int* step25_node3_factor_ridx[] = {step25_factor45_ridx, step25_factor46_ridx, step25_factor53_ridx, step25_factor54_ridx, step25_factor56_ridx, step25_factor59_ridx, step25_factor62_ridx, step25_factor64_ridx, };
float* step25_node3_factor_data[] = {step25_factor45_data, step25_factor46_data, step25_factor53_data, step25_factor54_data, step25_factor56_data, step25_factor59_data, step25_factor62_data, step25_factor64_data, };
int step25_node3_factor_num_blks[] = {step25_factor45_num_blks, step25_factor46_num_blks, step25_factor53_num_blks, step25_factor54_num_blks, step25_factor56_num_blks, step25_factor59_num_blks, step25_factor62_num_blks, step25_factor64_num_blks, };
int* step25_node3_factor_A_blk_start[] = {step25_factor45_A_blk_start, step25_factor46_A_blk_start, step25_factor53_A_blk_start, step25_factor54_A_blk_start, step25_factor56_A_blk_start, step25_factor59_A_blk_start, step25_factor62_A_blk_start, step25_factor64_A_blk_start, };
int* step25_node3_factor_B_blk_start[] = {step25_factor45_B_blk_start, step25_factor46_B_blk_start, step25_factor53_B_blk_start, step25_factor54_B_blk_start, step25_factor56_B_blk_start, step25_factor59_B_blk_start, step25_factor62_B_blk_start, step25_factor64_B_blk_start, };
int* step25_node3_factor_blk_width[] = {step25_factor45_blk_width, step25_factor46_blk_width, step25_factor53_blk_width, step25_factor54_blk_width, step25_factor56_blk_width, step25_factor59_blk_width, step25_factor62_blk_width, step25_factor64_blk_width, };
const int step25_node3_parent = 4;
const int step25_node3_height = 61;
const int step25_node3_width = 30;
float step25_node3_data[1830] = {0};
const int step25_node3_num_blks = 2;
int step25_node3_A_blk_start[] = {0, 6, };
int step25_node3_B_blk_start[] = {0, 18, };
int step25_node3_blk_width[] = {6, 24, };


const int step25_node4_num_factors = 15;
const int step25_node4_relin_cost = 450000;
const bool step25_node4_marked = true;
const bool step25_node4_fixed = false;
int step25_node4_factor_height[] = {step25_factor44_height, step25_factor47_height, step25_factor48_height, step25_factor49_height, step25_factor50_height, step25_factor51_height, step25_factor52_height, step25_factor55_height, step25_factor57_height, step25_factor58_height, step25_factor60_height, step25_factor61_height, step25_factor63_height, step25_factor65_height, step25_factor66_height, };
int step25_node4_factor_width[] = {step25_factor44_width, step25_factor47_width, step25_factor48_width, step25_factor49_width, step25_factor50_width, step25_factor51_width, step25_factor52_width, step25_factor55_width, step25_factor57_width, step25_factor58_width, step25_factor60_width, step25_factor61_width, step25_factor63_width, step25_factor65_width, step25_factor66_width, };
int* step25_node4_factor_ridx[] = {step25_factor44_ridx, step25_factor47_ridx, step25_factor48_ridx, step25_factor49_ridx, step25_factor50_ridx, step25_factor51_ridx, step25_factor52_ridx, step25_factor55_ridx, step25_factor57_ridx, step25_factor58_ridx, step25_factor60_ridx, step25_factor61_ridx, step25_factor63_ridx, step25_factor65_ridx, step25_factor66_ridx, };
float* step25_node4_factor_data[] = {step25_factor44_data, step25_factor47_data, step25_factor48_data, step25_factor49_data, step25_factor50_data, step25_factor51_data, step25_factor52_data, step25_factor55_data, step25_factor57_data, step25_factor58_data, step25_factor60_data, step25_factor61_data, step25_factor63_data, step25_factor65_data, step25_factor66_data, };
int step25_node4_factor_num_blks[] = {step25_factor44_num_blks, step25_factor47_num_blks, step25_factor48_num_blks, step25_factor49_num_blks, step25_factor50_num_blks, step25_factor51_num_blks, step25_factor52_num_blks, step25_factor55_num_blks, step25_factor57_num_blks, step25_factor58_num_blks, step25_factor60_num_blks, step25_factor61_num_blks, step25_factor63_num_blks, step25_factor65_num_blks, step25_factor66_num_blks, };
int* step25_node4_factor_A_blk_start[] = {step25_factor44_A_blk_start, step25_factor47_A_blk_start, step25_factor48_A_blk_start, step25_factor49_A_blk_start, step25_factor50_A_blk_start, step25_factor51_A_blk_start, step25_factor52_A_blk_start, step25_factor55_A_blk_start, step25_factor57_A_blk_start, step25_factor58_A_blk_start, step25_factor60_A_blk_start, step25_factor61_A_blk_start, step25_factor63_A_blk_start, step25_factor65_A_blk_start, step25_factor66_A_blk_start, };
int* step25_node4_factor_B_blk_start[] = {step25_factor44_B_blk_start, step25_factor47_B_blk_start, step25_factor48_B_blk_start, step25_factor49_B_blk_start, step25_factor50_B_blk_start, step25_factor51_B_blk_start, step25_factor52_B_blk_start, step25_factor55_B_blk_start, step25_factor57_B_blk_start, step25_factor58_B_blk_start, step25_factor60_B_blk_start, step25_factor61_B_blk_start, step25_factor63_B_blk_start, step25_factor65_B_blk_start, step25_factor66_B_blk_start, };
int* step25_node4_factor_blk_width[] = {step25_factor44_blk_width, step25_factor47_blk_width, step25_factor48_blk_width, step25_factor49_blk_width, step25_factor50_blk_width, step25_factor51_blk_width, step25_factor52_blk_width, step25_factor55_blk_width, step25_factor57_blk_width, step25_factor58_blk_width, step25_factor60_blk_width, step25_factor61_blk_width, step25_factor63_blk_width, step25_factor65_blk_width, step25_factor66_blk_width, };
const int step25_node4_parent = 5;
const int step25_node4_height = 43;
const int step25_node4_width = 42;
float step25_node4_data[1806] = {0};
const int step25_node4_num_blks = 0;
int step25_node4_A_blk_start[] = {};
int step25_node4_B_blk_start[] = {};
int step25_node4_blk_width[] = {};


const int step25_node5_num_factors = 0;
const int step25_node5_relin_cost = 0;
const bool step25_node5_marked = true;
const bool step25_node5_fixed = false;
int step25_node5_factor_height[] = {};
int step25_node5_factor_width[] = {};
int* step25_node5_factor_ridx[] = {};
float* step25_node5_factor_data[] = {};
int step25_node5_factor_num_blks[] = {};
int* step25_node5_factor_A_blk_start[] = {};
int* step25_node5_factor_B_blk_start[] = {};
int* step25_node5_factor_blk_width[] = {};
const int step25_node5_parent = -1;
const int step25_node5_height = 1;
const int step25_node5_width = 1;
float step25_node5_data[1] = {0};
const int step25_node5_num_blks = 0;
int step25_node5_A_blk_start[] = {};
int step25_node5_B_blk_start[] = {};
int step25_node5_blk_width[] = {};


int step25_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 156, };
int step25_node1_ridx[] = {
36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 156, };
int step25_node2_ridx[] = {
60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 156, };
int step25_node3_ridx[] = {
84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, };
int step25_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, };
int step25_node5_ridx[] = {
156, };
const int step25_nnodes = 6;
bool step25_node_marked[] = {false, false, false, step25_node3_marked, step25_node4_marked, step25_node5_marked, };
bool step25_node_fixed[] = {false, false, false, step25_node3_fixed, step25_node4_fixed, step25_node5_fixed, };
int step25_node_num_factors[] = {0, 0, 0, step25_node3_num_factors, step25_node4_num_factors, step25_node5_num_factors, };
int step25_node_relin_cost[] = {0, 0, 0, step25_node3_relin_cost, step25_node4_relin_cost, step25_node5_relin_cost, };
int* step25_node_factor_height[] = {0, 0, 0, step25_node3_factor_height, step25_node4_factor_height, step25_node5_factor_height, };
int* step25_node_factor_width[] = {0, 0, 0, step25_node3_factor_width, step25_node4_factor_width, step25_node5_factor_width, };
int** step25_node_factor_ridx[] = {0, 0, 0, step25_node3_factor_ridx, step25_node4_factor_ridx, step25_node5_factor_ridx, };
float** step25_node_factor_data[] = {0, 0, 0, step25_node3_factor_data, step25_node4_factor_data, step25_node5_factor_data, };
int* step25_node_factor_num_blks[] = {0, 0, 0, step25_node3_factor_num_blks, step25_node4_factor_num_blks, step25_node5_factor_num_blks, };
int** step25_node_factor_A_blk_start[] = {0, 0, 0, step25_node3_factor_A_blk_start, step25_node4_factor_A_blk_start, step25_node5_factor_A_blk_start, };
int** step25_node_factor_B_blk_start[] = {0, 0, 0, step25_node3_factor_B_blk_start, step25_node4_factor_B_blk_start, step25_node5_factor_B_blk_start, };
int** step25_node_factor_blk_width[] = {0, 0, 0, step25_node3_factor_blk_width, step25_node4_factor_blk_width, step25_node5_factor_blk_width, };
int step25_node_parent[] = {0, 0, 0, step25_node3_parent, step25_node4_parent, step25_node5_parent, };
int step25_node_height[] = {0, 0, 0, step25_node3_height, step25_node4_height, step25_node5_height, };
int step25_node_width[] = {0, 0, 0, step25_node3_width, step25_node4_width, step25_node5_width, };
float* step25_node_data[] = {0, 0, 0, step25_node3_data, step25_node4_data, step25_node5_data, };
int step25_node_num_blks[] = {0, 0, 0, step25_node3_num_blks, step25_node4_num_blks, step25_node5_num_blks, };
int* step25_node_A_blk_start[] = {0, 0, 0, step25_node3_A_blk_start, step25_node4_A_blk_start, step25_node5_A_blk_start, };
int* step25_node_B_blk_start[] = {0, 0, 0, step25_node3_B_blk_start, step25_node4_B_blk_start, step25_node5_B_blk_start, };
int* step25_node_blk_width[] = {0, 0, 0, step25_node3_blk_width, step25_node4_blk_width, step25_node5_blk_width, };
int* step25_node_ridx[] = {step25_node0_ridx, step25_node1_ridx, step25_node2_ridx, step25_node3_ridx, step25_node4_ridx, step25_node5_ridx, };


float step25_x_data[157] = {};
const int step25_workspace_needed = 22584;

