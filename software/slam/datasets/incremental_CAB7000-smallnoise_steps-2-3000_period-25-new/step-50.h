#pragma once

const bool step50_is_reconstruct = true;

const int step50_num_threads = 1;

const uint64_t step50_scaled_relin_cost = 0;

const bool step50_run_model = false;

const int step50_factor129_height = 7;
const int step50_factor129_width = 6;
int step50_factor129_ridx[] = {6, 7, 8, 9, 10, 11, 18, };
float step50_factor129_data[42] = {0};

const int step50_factor129_num_blks = 1;
int step50_factor129_A_blk_start[] = {0, };
int step50_factor129_B_blk_start[] = {6, };
int step50_factor129_blk_width[] = {6, };

const int step50_factor130_height = 13;
const int step50_factor130_width = 6;
int step50_factor130_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 18, };
float step50_factor130_data[78] = {0};

const int step50_factor130_num_blks = 1;
int step50_factor130_A_blk_start[] = {0, };
int step50_factor130_B_blk_start[] = {0, };
int step50_factor130_blk_width[] = {12, };

const int step50_factor131_height = 7;
const int step50_factor131_width = 6;
int step50_factor131_ridx[] = {12, 13, 14, 15, 16, 17, 18, };
float step50_factor131_data[42] = {0};

const int step50_factor131_num_blks = 1;
int step50_factor131_A_blk_start[] = {0, };
int step50_factor131_B_blk_start[] = {12, };
int step50_factor131_blk_width[] = {6, };

const int step50_factor132_height = 13;
const int step50_factor132_width = 6;
int step50_factor132_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, };
float step50_factor132_data[78] = {0};

const int step50_factor132_num_blks = 1;
int step50_factor132_A_blk_start[] = {0, };
int step50_factor132_B_blk_start[] = {6, };
int step50_factor132_blk_width[] = {12, };

const int step50_factor127_height = 7;
const int step50_factor127_width = 6;
int step50_factor127_ridx[] = {0, 1, 2, 3, 4, 5, 18, };
float step50_factor127_data[42] = {0};

const int step50_factor127_num_blks = 1;
int step50_factor127_A_blk_start[] = {0, };
int step50_factor127_B_blk_start[] = {0, };
int step50_factor127_blk_width[] = {6, };

const int step50_factor128_height = 13;
const int step50_factor128_width = 6;
int step50_factor128_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step50_factor128_data[78] = {0};

const int step50_factor128_num_blks = 1;
int step50_factor128_A_blk_start[] = {0, };
int step50_factor128_B_blk_start[] = {18, };
int step50_factor128_blk_width[] = {12, };

const int step50_node9_num_factors = 1;
const int step50_node9_relin_cost = 0;
const int step50_node9_sym_cost = 8000;
const bool step50_node9_marked = false;
const bool step50_node9_fixed = true;
int step50_node9_factor_height[] = {step50_factor128_height, };
int step50_node9_factor_width[] = {step50_factor128_width, };
int* step50_node9_factor_ridx[] = {step50_factor128_ridx, };
float* step50_node9_factor_data[] = {step50_factor128_data, };
int step50_node9_factor_num_blks[] = {step50_factor128_num_blks, };
int* step50_node9_factor_A_blk_start[] = {step50_factor128_A_blk_start, };
int* step50_node9_factor_B_blk_start[] = {step50_factor128_B_blk_start, };
int* step50_node9_factor_blk_width[] = {step50_factor128_blk_width, };
const int step50_node9_parent = 10;
const int step50_node9_height = 31;
const int step50_node9_width = 24;
float step50_node9_data[744] = {0};
const int step50_node9_num_blks = 1;
int step50_node9_A_blk_start[] = {0, };
int step50_node9_B_blk_start[] = {0, };
int step50_node9_blk_width[] = {6, };


const int step50_node10_num_factors = 5;
const int step50_node10_relin_cost = 0;
const int step50_node10_sym_cost = 6000;
const bool step50_node10_marked = true;
const bool step50_node10_fixed = false;
int step50_node10_factor_height[] = {step50_factor127_height, step50_factor129_height, step50_factor130_height, step50_factor131_height, step50_factor132_height, };
int step50_node10_factor_width[] = {step50_factor127_width, step50_factor129_width, step50_factor130_width, step50_factor131_width, step50_factor132_width, };
int* step50_node10_factor_ridx[] = {step50_factor127_ridx, step50_factor129_ridx, step50_factor130_ridx, step50_factor131_ridx, step50_factor132_ridx, };
float* step50_node10_factor_data[] = {step50_factor127_data, step50_factor129_data, step50_factor130_data, step50_factor131_data, step50_factor132_data, };
int step50_node10_factor_num_blks[] = {step50_factor127_num_blks, step50_factor129_num_blks, step50_factor130_num_blks, step50_factor131_num_blks, step50_factor132_num_blks, };
int* step50_node10_factor_A_blk_start[] = {step50_factor127_A_blk_start, step50_factor129_A_blk_start, step50_factor130_A_blk_start, step50_factor131_A_blk_start, step50_factor132_A_blk_start, };
int* step50_node10_factor_B_blk_start[] = {step50_factor127_B_blk_start, step50_factor129_B_blk_start, step50_factor130_B_blk_start, step50_factor131_B_blk_start, step50_factor132_B_blk_start, };
int* step50_node10_factor_blk_width[] = {step50_factor127_blk_width, step50_factor129_blk_width, step50_factor130_blk_width, step50_factor131_blk_width, step50_factor132_blk_width, };
const int step50_node10_parent = 11;
const int step50_node10_height = 19;
const int step50_node10_width = 18;
float step50_node10_data[342] = {0};
const int step50_node10_num_blks = 0;
int step50_node10_A_blk_start[] = {};
int step50_node10_B_blk_start[] = {};
int step50_node10_blk_width[] = {};


const int step50_node11_num_factors = 0;
const int step50_node11_relin_cost = 0;
const int step50_node11_sym_cost = 2000;
const bool step50_node11_marked = true;
const bool step50_node11_fixed = false;
int step50_node11_factor_height[] = {};
int step50_node11_factor_width[] = {};
int* step50_node11_factor_ridx[] = {};
float* step50_node11_factor_data[] = {};
int step50_node11_factor_num_blks[] = {};
int* step50_node11_factor_A_blk_start[] = {};
int* step50_node11_factor_B_blk_start[] = {};
int* step50_node11_factor_blk_width[] = {};
const int step50_node11_parent = -1;
const int step50_node11_height = 1;
const int step50_node11_width = 1;
float step50_node11_data[1] = {0};
const int step50_node11_num_blks = 0;
int step50_node11_A_blk_start[] = {};
int step50_node11_B_blk_start[] = {};
int step50_node11_blk_width[] = {};


int step50_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 306, };
int step50_node1_ridx[] = {
36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 306, };
int step50_node2_ridx[] = {
60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 114, 115, 116, 117, 118, 119, 306, };
int step50_node3_ridx[] = {
84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 306, };
int step50_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 306, };
int step50_node5_ridx[] = {
150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 186, 187, 188, 189, 190, 191, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 306, };
int step50_node6_ridx[] = {
174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 306, };
int step50_node7_ridx[] = {
204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 306, };
int step50_node8_ridx[] = {
240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 282, 283, 284, 285, 286, 287, 306, };
int step50_node9_ridx[] = {
264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 306, };
int step50_node10_ridx[] = {
288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, };
int step50_node11_ridx[] = {
306, };
const int step50_nnodes = 12;
bool step50_node_marked[] = {false, false, false, false, false, false, false, false, false, step50_node9_marked, step50_node10_marked, step50_node11_marked, };
bool step50_node_fixed[] = {false, false, false, false, false, false, false, false, false, step50_node9_fixed, step50_node10_fixed, step50_node11_fixed, };
int step50_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_num_factors, step50_node10_num_factors, step50_node11_num_factors, };
int step50_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_relin_cost, step50_node10_relin_cost, step50_node11_relin_cost, };
int step50_node_sym_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_sym_cost, step50_node10_sym_cost, step50_node11_sym_cost, };
int* step50_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_factor_height, step50_node10_factor_height, step50_node11_factor_height, };
int* step50_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_factor_width, step50_node10_factor_width, step50_node11_factor_width, };
int** step50_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_factor_ridx, step50_node10_factor_ridx, step50_node11_factor_ridx, };
float** step50_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_factor_data, step50_node10_factor_data, step50_node11_factor_data, };
int* step50_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_factor_num_blks, step50_node10_factor_num_blks, step50_node11_factor_num_blks, };
int** step50_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_factor_A_blk_start, step50_node10_factor_A_blk_start, step50_node11_factor_A_blk_start, };
int** step50_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_factor_B_blk_start, step50_node10_factor_B_blk_start, step50_node11_factor_B_blk_start, };
int** step50_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_factor_blk_width, step50_node10_factor_blk_width, step50_node11_factor_blk_width, };
int step50_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_parent, step50_node10_parent, step50_node11_parent, };
int step50_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_height, step50_node10_height, step50_node11_height, };
int step50_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_width, step50_node10_width, step50_node11_width, };
float* step50_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_data, step50_node10_data, step50_node11_data, };
int step50_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_num_blks, step50_node10_num_blks, step50_node11_num_blks, };
int* step50_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_A_blk_start, step50_node10_A_blk_start, step50_node11_A_blk_start, };
int* step50_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_B_blk_start, step50_node10_B_blk_start, step50_node11_B_blk_start, };
int* step50_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_blk_width, step50_node10_blk_width, step50_node11_blk_width, };
int* step50_node_ridx[] = {step50_node0_ridx, step50_node1_ridx, step50_node2_ridx, step50_node3_ridx, step50_node4_ridx, step50_node5_ridx, step50_node6_ridx, step50_node7_ridx, step50_node8_ridx, step50_node9_ridx, step50_node10_ridx, step50_node11_ridx, };


float step50_x_data[307] = {};
const int step50_workspace_needed = 5592;

