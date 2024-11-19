#pragma once

const bool step33_is_reconstruct = true;

const int step33_num_threads = 1;

const uint64_t step33_scaled_relin_cost = 100000;

const bool step33_run_model = false;

const int step33_factor89_height = 13;
const int step33_factor89_width = 6;
int step33_factor89_ridx[] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 48, };
float step33_factor89_data[78] = {0};

const int step33_factor89_num_blks = 1;
int step33_factor89_A_blk_start[] = {0, };
int step33_factor89_B_blk_start[] = {30, };
int step33_factor89_blk_width[] = {12, };

const int step33_factor79_height = 7;
const int step33_factor79_width = 6;
int step33_factor79_ridx[] = {6, 7, 8, 9, 10, 11, 18, };
float step33_factor79_data[42] = {0};

const int step33_factor79_num_blks = 1;
int step33_factor79_A_blk_start[] = {0, };
int step33_factor79_B_blk_start[] = {6, };
int step33_factor79_blk_width[] = {6, };

const int step33_factor90_height = 13;
const int step33_factor90_width = 6;
int step33_factor90_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 18, };
float step33_factor90_data[78] = {0};

const int step33_factor90_num_blks = 1;
int step33_factor90_A_blk_start[] = {0, };
int step33_factor90_B_blk_start[] = {0, };
int step33_factor90_blk_width[] = {12, };

const int step33_factor80_height = 13;
const int step33_factor80_width = 6;
int step33_factor80_ridx[] = {18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 48, };
float step33_factor80_data[78] = {0};

const int step33_factor80_num_blks = 2;
int step33_factor80_A_blk_start[] = {0, 6, };
int step33_factor80_B_blk_start[] = {18, 42, };
int step33_factor80_blk_width[] = {6, 6, };

const int step33_factor91_height = 13;
const int step33_factor91_width = 6;
int step33_factor91_ridx[] = {18, 19, 20, 21, 22, 23, 36, 37, 38, 39, 40, 41, 48, };
float step33_factor91_data[78] = {0};

const int step33_factor91_num_blks = 2;
int step33_factor91_A_blk_start[] = {0, 6, };
int step33_factor91_B_blk_start[] = {18, 36, };
int step33_factor91_blk_width[] = {6, 6, };

const int step33_factor81_height = 13;
const int step33_factor81_width = 6;
int step33_factor81_ridx[] = {30, 31, 32, 33, 34, 35, 42, 43, 44, 45, 46, 47, 48, };
float step33_factor81_data[78] = {0};

const int step33_factor81_num_blks = 2;
int step33_factor81_A_blk_start[] = {0, 6, };
int step33_factor81_B_blk_start[] = {30, 42, };
int step33_factor81_blk_width[] = {6, 6, };

const int step33_factor92_height = 7;
const int step33_factor92_width = 6;
int step33_factor92_ridx[] = {12, 13, 14, 15, 16, 17, 18, };
float step33_factor92_data[42] = {0};

const int step33_factor92_num_blks = 1;
int step33_factor92_A_blk_start[] = {0, };
int step33_factor92_B_blk_start[] = {12, };
int step33_factor92_blk_width[] = {6, };

const int step33_factor93_height = 13;
const int step33_factor93_width = 6;
int step33_factor93_ridx[] = {0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 18, };
float step33_factor93_data[78] = {0};

const int step33_factor93_num_blks = 2;
int step33_factor93_A_blk_start[] = {0, 6, };
int step33_factor93_B_blk_start[] = {0, 12, };
int step33_factor93_blk_width[] = {6, 6, };

const int step33_factor83_height = 13;
const int step33_factor83_width = 6;
int step33_factor83_ridx[] = {24, 25, 26, 27, 28, 29, 42, 43, 44, 45, 46, 47, 48, };
float step33_factor83_data[78] = {0};

const int step33_factor83_num_blks = 2;
int step33_factor83_A_blk_start[] = {0, 6, };
int step33_factor83_B_blk_start[] = {24, 42, };
int step33_factor83_blk_width[] = {6, 6, };

const int step33_factor87_height = 7;
const int step33_factor87_width = 6;
int step33_factor87_ridx[] = {0, 1, 2, 3, 4, 5, 18, };
float step33_factor87_data[42] = {0};

const int step33_factor87_num_blks = 1;
int step33_factor87_A_blk_start[] = {0, };
int step33_factor87_B_blk_start[] = {0, };
int step33_factor87_blk_width[] = {6, };

const int step33_factor88_height = 13;
const int step33_factor88_width = 6;
int step33_factor88_ridx[] = {24, 25, 26, 27, 28, 29, 36, 37, 38, 39, 40, 41, 48, };
float step33_factor88_data[78] = {0};

const int step33_factor88_num_blks = 2;
int step33_factor88_A_blk_start[] = {0, 6, };
int step33_factor88_B_blk_start[] = {24, 36, };
int step33_factor88_blk_width[] = {6, 6, };

const int step33_node6_num_factors = 6;
const int step33_node6_relin_cost = 60000;
const int step33_node6_sym_cost = 24000;
const bool step33_node6_marked = false;
const bool step33_node6_fixed = true;
int step33_node6_factor_height[] = {step33_factor80_height, step33_factor81_height, step33_factor83_height, step33_factor88_height, step33_factor89_height, step33_factor91_height, };
int step33_node6_factor_width[] = {step33_factor80_width, step33_factor81_width, step33_factor83_width, step33_factor88_width, step33_factor89_width, step33_factor91_width, };
int* step33_node6_factor_ridx[] = {step33_factor80_ridx, step33_factor81_ridx, step33_factor83_ridx, step33_factor88_ridx, step33_factor89_ridx, step33_factor91_ridx, };
float* step33_node6_factor_data[] = {step33_factor80_data, step33_factor81_data, step33_factor83_data, step33_factor88_data, step33_factor89_data, step33_factor91_data, };
int step33_node6_factor_num_blks[] = {step33_factor80_num_blks, step33_factor81_num_blks, step33_factor83_num_blks, step33_factor88_num_blks, step33_factor89_num_blks, step33_factor91_num_blks, };
int* step33_node6_factor_A_blk_start[] = {step33_factor80_A_blk_start, step33_factor81_A_blk_start, step33_factor83_A_blk_start, step33_factor88_A_blk_start, step33_factor89_A_blk_start, step33_factor91_A_blk_start, };
int* step33_node6_factor_B_blk_start[] = {step33_factor80_B_blk_start, step33_factor81_B_blk_start, step33_factor83_B_blk_start, step33_factor88_B_blk_start, step33_factor89_B_blk_start, step33_factor91_B_blk_start, };
int* step33_node6_factor_blk_width[] = {step33_factor80_blk_width, step33_factor81_blk_width, step33_factor83_blk_width, step33_factor88_blk_width, step33_factor89_blk_width, step33_factor91_blk_width, };
const int step33_node6_parent = 7;
const int step33_node6_height = 49;
const int step33_node6_width = 36;
float step33_node6_data[1764] = {0};
const int step33_node6_num_blks = 1;
int step33_node6_A_blk_start[] = {0, };
int step33_node6_B_blk_start[] = {0, };
int step33_node6_blk_width[] = {12, };


const int step33_node7_num_factors = 5;
const int step33_node7_relin_cost = 40000;
const int step33_node7_sym_cost = 12000;
const bool step33_node7_marked = true;
const bool step33_node7_fixed = false;
int step33_node7_factor_height[] = {step33_factor79_height, step33_factor87_height, step33_factor90_height, step33_factor92_height, step33_factor93_height, };
int step33_node7_factor_width[] = {step33_factor79_width, step33_factor87_width, step33_factor90_width, step33_factor92_width, step33_factor93_width, };
int* step33_node7_factor_ridx[] = {step33_factor79_ridx, step33_factor87_ridx, step33_factor90_ridx, step33_factor92_ridx, step33_factor93_ridx, };
float* step33_node7_factor_data[] = {step33_factor79_data, step33_factor87_data, step33_factor90_data, step33_factor92_data, step33_factor93_data, };
int step33_node7_factor_num_blks[] = {step33_factor79_num_blks, step33_factor87_num_blks, step33_factor90_num_blks, step33_factor92_num_blks, step33_factor93_num_blks, };
int* step33_node7_factor_A_blk_start[] = {step33_factor79_A_blk_start, step33_factor87_A_blk_start, step33_factor90_A_blk_start, step33_factor92_A_blk_start, step33_factor93_A_blk_start, };
int* step33_node7_factor_B_blk_start[] = {step33_factor79_B_blk_start, step33_factor87_B_blk_start, step33_factor90_B_blk_start, step33_factor92_B_blk_start, step33_factor93_B_blk_start, };
int* step33_node7_factor_blk_width[] = {step33_factor79_blk_width, step33_factor87_blk_width, step33_factor90_blk_width, step33_factor92_blk_width, step33_factor93_blk_width, };
const int step33_node7_parent = 8;
const int step33_node7_height = 19;
const int step33_node7_width = 18;
float step33_node7_data[342] = {0};
const int step33_node7_num_blks = 0;
int step33_node7_A_blk_start[] = {};
int step33_node7_B_blk_start[] = {};
int step33_node7_blk_width[] = {};


const int step33_node8_num_factors = 0;
const int step33_node8_relin_cost = 0;
const int step33_node8_sym_cost = 4000;
const bool step33_node8_marked = true;
const bool step33_node8_fixed = false;
int step33_node8_factor_height[] = {};
int step33_node8_factor_width[] = {};
int* step33_node8_factor_ridx[] = {};
float* step33_node8_factor_data[] = {};
int step33_node8_factor_num_blks[] = {};
int* step33_node8_factor_A_blk_start[] = {};
int* step33_node8_factor_B_blk_start[] = {};
int* step33_node8_factor_blk_width[] = {};
const int step33_node8_parent = -1;
const int step33_node8_height = 1;
const int step33_node8_width = 1;
float step33_node8_data[1] = {0};
const int step33_node8_num_blks = 0;
int step33_node8_A_blk_start[] = {};
int step33_node8_B_blk_start[] = {};
int step33_node8_blk_width[] = {};


int step33_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 204, };
int step33_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 204, };
int step33_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 150, 151, 152, 153, 154, 155, 204, };
int step33_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 162, 163, 164, 165, 166, 167, 204, };
int step33_node4_ridx[] = {
102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 162, 163, 164, 165, 166, 167, 204, };
int step33_node5_ridx[] = {
126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 204, };
int step33_node6_ridx[] = {
150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 204, };
int step33_node7_ridx[] = {
186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, };
int step33_node8_ridx[] = {
204, };
const int step33_nnodes = 9;
bool step33_node_marked[] = {false, false, false, false, false, false, step33_node6_marked, step33_node7_marked, step33_node8_marked, };
bool step33_node_fixed[] = {false, false, false, false, false, false, step33_node6_fixed, step33_node7_fixed, step33_node8_fixed, };
int step33_node_num_factors[] = {0, 0, 0, 0, 0, 0, step33_node6_num_factors, step33_node7_num_factors, step33_node8_num_factors, };
int step33_node_relin_cost[] = {0, 0, 0, 0, 0, 0, step33_node6_relin_cost, step33_node7_relin_cost, step33_node8_relin_cost, };
int step33_node_sym_cost[] = {0, 0, 0, 0, 0, 0, step33_node6_sym_cost, step33_node7_sym_cost, step33_node8_sym_cost, };
int* step33_node_factor_height[] = {0, 0, 0, 0, 0, 0, step33_node6_factor_height, step33_node7_factor_height, step33_node8_factor_height, };
int* step33_node_factor_width[] = {0, 0, 0, 0, 0, 0, step33_node6_factor_width, step33_node7_factor_width, step33_node8_factor_width, };
int** step33_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, step33_node6_factor_ridx, step33_node7_factor_ridx, step33_node8_factor_ridx, };
float** step33_node_factor_data[] = {0, 0, 0, 0, 0, 0, step33_node6_factor_data, step33_node7_factor_data, step33_node8_factor_data, };
int* step33_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, step33_node6_factor_num_blks, step33_node7_factor_num_blks, step33_node8_factor_num_blks, };
int** step33_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, step33_node6_factor_A_blk_start, step33_node7_factor_A_blk_start, step33_node8_factor_A_blk_start, };
int** step33_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, step33_node6_factor_B_blk_start, step33_node7_factor_B_blk_start, step33_node8_factor_B_blk_start, };
int** step33_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, step33_node6_factor_blk_width, step33_node7_factor_blk_width, step33_node8_factor_blk_width, };
int step33_node_parent[] = {0, 0, 0, 0, 0, 0, step33_node6_parent, step33_node7_parent, step33_node8_parent, };
int step33_node_height[] = {0, 0, 0, 0, 0, 0, step33_node6_height, step33_node7_height, step33_node8_height, };
int step33_node_width[] = {0, 0, 0, 0, 0, 0, step33_node6_width, step33_node7_width, step33_node8_width, };
float* step33_node_data[] = {0, 0, 0, 0, 0, 0, step33_node6_data, step33_node7_data, step33_node8_data, };
int step33_node_num_blks[] = {0, 0, 0, 0, 0, 0, step33_node6_num_blks, step33_node7_num_blks, step33_node8_num_blks, };
int* step33_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, step33_node6_A_blk_start, step33_node7_A_blk_start, step33_node8_A_blk_start, };
int* step33_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, step33_node6_B_blk_start, step33_node7_B_blk_start, step33_node8_B_blk_start, };
int* step33_node_blk_width[] = {0, 0, 0, 0, 0, 0, step33_node6_blk_width, step33_node7_blk_width, step33_node8_blk_width, };
int* step33_node_ridx[] = {step33_node0_ridx, step33_node1_ridx, step33_node2_ridx, step33_node3_ridx, step33_node4_ridx, step33_node5_ridx, step33_node6_ridx, step33_node7_ridx, step33_node8_ridx, };


float step33_x_data[205] = {};
const int step33_workspace_needed = 11352;

