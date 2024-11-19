#pragma once

const bool step50_is_reconstruct = true;

const int step50_num_threads = 1;

const uint64_t step50_scaled_relin_cost = 0;

const bool step50_run_model = false;

const int step50_factor160_height = 13;
const int step50_factor160_width = 6;
int step50_factor160_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 18, };
float step50_factor160_data[78] = {0};

const int step50_factor160_num_blks = 1;
int step50_factor160_A_blk_start[] = {0, };
int step50_factor160_B_blk_start[] = {0, };
int step50_factor160_blk_width[] = {12, };

const int step50_factor161_height = 13;
const int step50_factor161_width = 6;
int step50_factor161_ridx[] = {0, 1, 2, 3, 4, 5, 30, 31, 32, 33, 34, 35, 36, };
float step50_factor161_data[78] = {0};

const int step50_factor161_num_blks = 2;
int step50_factor161_A_blk_start[] = {0, 6, };
int step50_factor161_B_blk_start[] = {0, 30, };
int step50_factor161_blk_width[] = {6, 6, };

const int step50_factor162_height = 13;
const int step50_factor162_width = 6;
int step50_factor162_ridx[] = {6, 7, 8, 9, 10, 11, 30, 31, 32, 33, 34, 35, 36, };
float step50_factor162_data[78] = {0};

const int step50_factor162_num_blks = 2;
int step50_factor162_A_blk_start[] = {0, 6, };
int step50_factor162_B_blk_start[] = {6, 30, };
int step50_factor162_blk_width[] = {6, 6, };

const int step50_factor163_height = 13;
const int step50_factor163_width = 6;
int step50_factor163_ridx[] = {18, 19, 20, 21, 22, 23, 30, 31, 32, 33, 34, 35, 36, };
float step50_factor163_data[78] = {0};

const int step50_factor163_num_blks = 2;
int step50_factor163_A_blk_start[] = {0, 6, };
int step50_factor163_B_blk_start[] = {18, 30, };
int step50_factor163_blk_width[] = {6, 6, };

const int step50_factor164_height = 7;
const int step50_factor164_width = 6;
int step50_factor164_ridx[] = {12, 13, 14, 15, 16, 17, 18, };
float step50_factor164_data[42] = {0};

const int step50_factor164_num_blks = 1;
int step50_factor164_A_blk_start[] = {0, };
int step50_factor164_B_blk_start[] = {12, };
int step50_factor164_blk_width[] = {6, };

const int step50_factor165_height = 13;
const int step50_factor165_width = 6;
int step50_factor165_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, };
float step50_factor165_data[78] = {0};

const int step50_factor165_num_blks = 1;
int step50_factor165_A_blk_start[] = {0, };
int step50_factor165_B_blk_start[] = {6, };
int step50_factor165_blk_width[] = {12, };

const int step50_factor166_height = 13;
const int step50_factor166_width = 6;
int step50_factor166_ridx[] = {0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 18, };
float step50_factor166_data[78] = {0};

const int step50_factor166_num_blks = 2;
int step50_factor166_A_blk_start[] = {0, 6, };
int step50_factor166_B_blk_start[] = {0, 12, };
int step50_factor166_blk_width[] = {6, 6, };

const int step50_factor157_height = 7;
const int step50_factor157_width = 6;
int step50_factor157_ridx[] = {0, 1, 2, 3, 4, 5, 18, };
float step50_factor157_data[42] = {0};

const int step50_factor157_num_blks = 1;
int step50_factor157_A_blk_start[] = {0, };
int step50_factor157_B_blk_start[] = {0, };
int step50_factor157_blk_width[] = {6, };

const int step50_factor158_height = 13;
const int step50_factor158_width = 6;
int step50_factor158_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 36, };
float step50_factor158_data[78] = {0};

const int step50_factor158_num_blks = 1;
int step50_factor158_A_blk_start[] = {0, };
int step50_factor158_B_blk_start[] = {18, };
int step50_factor158_blk_width[] = {12, };

const int step50_factor159_height = 7;
const int step50_factor159_width = 6;
int step50_factor159_ridx[] = {6, 7, 8, 9, 10, 11, 18, };
float step50_factor159_data[42] = {0};

const int step50_factor159_num_blks = 1;
int step50_factor159_A_blk_start[] = {0, };
int step50_factor159_B_blk_start[] = {6, };
int step50_factor159_blk_width[] = {6, };

const int step50_node9_num_factors = 4;
const int step50_node9_relin_cost = 120000;
const bool step50_node9_marked = false;
const bool step50_node9_fixed = true;
int step50_node9_factor_height[] = {step50_factor158_height, step50_factor161_height, step50_factor162_height, step50_factor163_height, };
int step50_node9_factor_width[] = {step50_factor158_width, step50_factor161_width, step50_factor162_width, step50_factor163_width, };
int* step50_node9_factor_ridx[] = {step50_factor158_ridx, step50_factor161_ridx, step50_factor162_ridx, step50_factor163_ridx, };
float* step50_node9_factor_data[] = {step50_factor158_data, step50_factor161_data, step50_factor162_data, step50_factor163_data, };
int step50_node9_factor_num_blks[] = {step50_factor158_num_blks, step50_factor161_num_blks, step50_factor162_num_blks, step50_factor163_num_blks, };
int* step50_node9_factor_A_blk_start[] = {step50_factor158_A_blk_start, step50_factor161_A_blk_start, step50_factor162_A_blk_start, step50_factor163_A_blk_start, };
int* step50_node9_factor_B_blk_start[] = {step50_factor158_B_blk_start, step50_factor161_B_blk_start, step50_factor162_B_blk_start, step50_factor163_B_blk_start, };
int* step50_node9_factor_blk_width[] = {step50_factor158_blk_width, step50_factor161_blk_width, step50_factor162_blk_width, step50_factor163_blk_width, };
const int step50_node9_parent = 10;
const int step50_node9_height = 37;
const int step50_node9_width = 24;
float step50_node9_data[888] = {0};
const int step50_node9_num_blks = 1;
int step50_node9_A_blk_start[] = {0, };
int step50_node9_B_blk_start[] = {0, };
int step50_node9_blk_width[] = {12, };


const int step50_node10_num_factors = 6;
const int step50_node10_relin_cost = 180000;
const bool step50_node10_marked = true;
const bool step50_node10_fixed = false;
int step50_node10_factor_height[] = {step50_factor157_height, step50_factor159_height, step50_factor160_height, step50_factor164_height, step50_factor165_height, step50_factor166_height, };
int step50_node10_factor_width[] = {step50_factor157_width, step50_factor159_width, step50_factor160_width, step50_factor164_width, step50_factor165_width, step50_factor166_width, };
int* step50_node10_factor_ridx[] = {step50_factor157_ridx, step50_factor159_ridx, step50_factor160_ridx, step50_factor164_ridx, step50_factor165_ridx, step50_factor166_ridx, };
float* step50_node10_factor_data[] = {step50_factor157_data, step50_factor159_data, step50_factor160_data, step50_factor164_data, step50_factor165_data, step50_factor166_data, };
int step50_node10_factor_num_blks[] = {step50_factor157_num_blks, step50_factor159_num_blks, step50_factor160_num_blks, step50_factor164_num_blks, step50_factor165_num_blks, step50_factor166_num_blks, };
int* step50_node10_factor_A_blk_start[] = {step50_factor157_A_blk_start, step50_factor159_A_blk_start, step50_factor160_A_blk_start, step50_factor164_A_blk_start, step50_factor165_A_blk_start, step50_factor166_A_blk_start, };
int* step50_node10_factor_B_blk_start[] = {step50_factor157_B_blk_start, step50_factor159_B_blk_start, step50_factor160_B_blk_start, step50_factor164_B_blk_start, step50_factor165_B_blk_start, step50_factor166_B_blk_start, };
int* step50_node10_factor_blk_width[] = {step50_factor157_blk_width, step50_factor159_blk_width, step50_factor160_blk_width, step50_factor164_blk_width, step50_factor165_blk_width, step50_factor166_blk_width, };
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
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 306, };
int step50_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 306, };
int step50_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 306, };
int step50_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 246, 247, 248, 249, 250, 251, 306, };
int step50_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 276, 277, 278, 279, 280, 281, 306, };
int step50_node5_ridx[] = {
150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 240, 241, 242, 243, 244, 245, 270, 271, 272, 273, 274, 275, 306, };
int step50_node6_ridx[] = {
174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 240, 241, 242, 243, 244, 245, 306, };
int step50_node7_ridx[] = {
198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 306, };
int step50_node8_ridx[] = {
222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 306, };
int step50_node9_ridx[] = {
264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 306, };
int step50_node10_ridx[] = {
288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, };
int step50_node11_ridx[] = {
306, };
const int step50_nnodes = 12;
bool step50_node_marked[] = {false, false, false, false, false, false, false, false, false, step50_node9_marked, step50_node10_marked, step50_node11_marked, };
bool step50_node_fixed[] = {false, false, false, false, false, false, false, false, false, step50_node9_fixed, step50_node10_fixed, step50_node11_fixed, };
int step50_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_num_factors, step50_node10_num_factors, step50_node11_num_factors, };
int step50_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step50_node9_relin_cost, step50_node10_relin_cost, step50_node11_relin_cost, };
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
const int step50_workspace_needed = 7224;

