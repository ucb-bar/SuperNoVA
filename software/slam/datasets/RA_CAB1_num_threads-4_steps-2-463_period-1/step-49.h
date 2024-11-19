#pragma once

const bool step49_is_reconstruct = true;

const int step49_num_threads = 1;

const uint64_t step49_scaled_relin_cost = 0;

const bool step49_run_model = false;

const int step49_factor160_height = 13;
const int step49_factor160_width = 6;
int step49_factor160_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, };
float step49_factor160_data[78] = {0};

const int step49_factor160_num_blks = 1;
int step49_factor160_A_blk_start[] = {0, };
int step49_factor160_B_blk_start[] = {6, };
int step49_factor160_blk_width[] = {12, };

const int step49_factor161_height = 13;
const int step49_factor161_width = 6;
int step49_factor161_ridx[] = {6, 7, 8, 9, 10, 11, 30, 31, 32, 33, 34, 35, 36, };
float step49_factor161_data[78] = {0};

const int step49_factor161_num_blks = 2;
int step49_factor161_A_blk_start[] = {0, 6, };
int step49_factor161_B_blk_start[] = {6, 30, };
int step49_factor161_blk_width[] = {6, 6, };

const int step49_factor162_height = 13;
const int step49_factor162_width = 6;
int step49_factor162_ridx[] = {18, 19, 20, 21, 22, 23, 30, 31, 32, 33, 34, 35, 36, };
float step49_factor162_data[78] = {0};

const int step49_factor162_num_blks = 2;
int step49_factor162_A_blk_start[] = {0, 6, };
int step49_factor162_B_blk_start[] = {18, 30, };
int step49_factor162_blk_width[] = {6, 6, };

const int step49_factor163_height = 13;
const int step49_factor163_width = 6;
int step49_factor163_ridx[] = {0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 18, };
float step49_factor163_data[78] = {0};

const int step49_factor163_num_blks = 2;
int step49_factor163_A_blk_start[] = {0, 6, };
int step49_factor163_B_blk_start[] = {0, 12, };
int step49_factor163_blk_width[] = {6, 6, };

const int step49_factor153_height = 7;
const int step49_factor153_width = 6;
int step49_factor153_ridx[] = {0, 1, 2, 3, 4, 5, 18, };
float step49_factor153_data[42] = {0};

const int step49_factor153_num_blks = 1;
int step49_factor153_A_blk_start[] = {0, };
int step49_factor153_B_blk_start[] = {0, };
int step49_factor153_blk_width[] = {6, };

const int step49_factor154_height = 13;
const int step49_factor154_width = 6;
int step49_factor154_ridx[] = {12, 13, 14, 15, 16, 17, 24, 25, 26, 27, 28, 29, 36, };
float step49_factor154_data[78] = {0};

const int step49_factor154_num_blks = 2;
int step49_factor154_A_blk_start[] = {0, 6, };
int step49_factor154_B_blk_start[] = {12, 24, };
int step49_factor154_blk_width[] = {6, 6, };

const int step49_factor155_height = 13;
const int step49_factor155_width = 6;
int step49_factor155_ridx[] = {6, 7, 8, 9, 10, 11, 24, 25, 26, 27, 28, 29, 36, };
float step49_factor155_data[78] = {0};

const int step49_factor155_num_blks = 2;
int step49_factor155_A_blk_start[] = {0, 6, };
int step49_factor155_B_blk_start[] = {6, 24, };
int step49_factor155_blk_width[] = {6, 6, };

const int step49_factor156_height = 13;
const int step49_factor156_width = 6;
int step49_factor156_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 36, };
float step49_factor156_data[78] = {0};

const int step49_factor156_num_blks = 1;
int step49_factor156_A_blk_start[] = {0, };
int step49_factor156_B_blk_start[] = {18, };
int step49_factor156_blk_width[] = {12, };

const int step49_factor157_height = 7;
const int step49_factor157_width = 6;
int step49_factor157_ridx[] = {6, 7, 8, 9, 10, 11, 18, };
float step49_factor157_data[42] = {0};

const int step49_factor157_num_blks = 1;
int step49_factor157_A_blk_start[] = {0, };
int step49_factor157_B_blk_start[] = {6, };
int step49_factor157_blk_width[] = {6, };

const int step49_factor158_height = 13;
const int step49_factor158_width = 6;
int step49_factor158_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 18, };
float step49_factor158_data[78] = {0};

const int step49_factor158_num_blks = 1;
int step49_factor158_A_blk_start[] = {0, };
int step49_factor158_B_blk_start[] = {0, };
int step49_factor158_blk_width[] = {12, };

const int step49_factor159_height = 7;
const int step49_factor159_width = 6;
int step49_factor159_ridx[] = {12, 13, 14, 15, 16, 17, 18, };
float step49_factor159_data[42] = {0};

const int step49_factor159_num_blks = 1;
int step49_factor159_A_blk_start[] = {0, };
int step49_factor159_B_blk_start[] = {12, };
int step49_factor159_blk_width[] = {6, };

const int step49_node9_num_factors = 5;
const int step49_node9_relin_cost = 0;
const int step49_node9_sym_cost = 16000;
const bool step49_node9_marked = false;
const bool step49_node9_fixed = true;
int step49_node9_factor_height[] = {step49_factor154_height, step49_factor155_height, step49_factor156_height, step49_factor161_height, step49_factor162_height, };
int step49_node9_factor_width[] = {step49_factor154_width, step49_factor155_width, step49_factor156_width, step49_factor161_width, step49_factor162_width, };
int* step49_node9_factor_ridx[] = {step49_factor154_ridx, step49_factor155_ridx, step49_factor156_ridx, step49_factor161_ridx, step49_factor162_ridx, };
float* step49_node9_factor_data[] = {step49_factor154_data, step49_factor155_data, step49_factor156_data, step49_factor161_data, step49_factor162_data, };
int step49_node9_factor_num_blks[] = {step49_factor154_num_blks, step49_factor155_num_blks, step49_factor156_num_blks, step49_factor161_num_blks, step49_factor162_num_blks, };
int* step49_node9_factor_A_blk_start[] = {step49_factor154_A_blk_start, step49_factor155_A_blk_start, step49_factor156_A_blk_start, step49_factor161_A_blk_start, step49_factor162_A_blk_start, };
int* step49_node9_factor_B_blk_start[] = {step49_factor154_B_blk_start, step49_factor155_B_blk_start, step49_factor156_B_blk_start, step49_factor161_B_blk_start, step49_factor162_B_blk_start, };
int* step49_node9_factor_blk_width[] = {step49_factor154_blk_width, step49_factor155_blk_width, step49_factor156_blk_width, step49_factor161_blk_width, step49_factor162_blk_width, };
const int step49_node9_parent = 10;
const int step49_node9_height = 37;
const int step49_node9_width = 24;
float step49_node9_data[888] = {0};
const int step49_node9_num_blks = 2;
int step49_node9_A_blk_start[] = {0, 6, };
int step49_node9_B_blk_start[] = {0, 12, };
int step49_node9_blk_width[] = {6, 6, };


const int step49_node10_num_factors = 6;
const int step49_node10_relin_cost = 0;
const int step49_node10_sym_cost = 12000;
const bool step49_node10_marked = true;
const bool step49_node10_fixed = false;
int step49_node10_factor_height[] = {step49_factor153_height, step49_factor157_height, step49_factor158_height, step49_factor159_height, step49_factor160_height, step49_factor163_height, };
int step49_node10_factor_width[] = {step49_factor153_width, step49_factor157_width, step49_factor158_width, step49_factor159_width, step49_factor160_width, step49_factor163_width, };
int* step49_node10_factor_ridx[] = {step49_factor153_ridx, step49_factor157_ridx, step49_factor158_ridx, step49_factor159_ridx, step49_factor160_ridx, step49_factor163_ridx, };
float* step49_node10_factor_data[] = {step49_factor153_data, step49_factor157_data, step49_factor158_data, step49_factor159_data, step49_factor160_data, step49_factor163_data, };
int step49_node10_factor_num_blks[] = {step49_factor153_num_blks, step49_factor157_num_blks, step49_factor158_num_blks, step49_factor159_num_blks, step49_factor160_num_blks, step49_factor163_num_blks, };
int* step49_node10_factor_A_blk_start[] = {step49_factor153_A_blk_start, step49_factor157_A_blk_start, step49_factor158_A_blk_start, step49_factor159_A_blk_start, step49_factor160_A_blk_start, step49_factor163_A_blk_start, };
int* step49_node10_factor_B_blk_start[] = {step49_factor153_B_blk_start, step49_factor157_B_blk_start, step49_factor158_B_blk_start, step49_factor159_B_blk_start, step49_factor160_B_blk_start, step49_factor163_B_blk_start, };
int* step49_node10_factor_blk_width[] = {step49_factor153_blk_width, step49_factor157_blk_width, step49_factor158_blk_width, step49_factor159_blk_width, step49_factor160_blk_width, step49_factor163_blk_width, };
const int step49_node10_parent = 11;
const int step49_node10_height = 19;
const int step49_node10_width = 18;
float step49_node10_data[342] = {0};
const int step49_node10_num_blks = 0;
int step49_node10_A_blk_start[] = {};
int step49_node10_B_blk_start[] = {};
int step49_node10_blk_width[] = {};


const int step49_node11_num_factors = 0;
const int step49_node11_relin_cost = 0;
const int step49_node11_sym_cost = 4000;
const bool step49_node11_marked = true;
const bool step49_node11_fixed = false;
int step49_node11_factor_height[] = {};
int step49_node11_factor_width[] = {};
int* step49_node11_factor_ridx[] = {};
float* step49_node11_factor_data[] = {};
int step49_node11_factor_num_blks[] = {};
int* step49_node11_factor_A_blk_start[] = {};
int* step49_node11_factor_B_blk_start[] = {};
int* step49_node11_factor_blk_width[] = {};
const int step49_node11_parent = -1;
const int step49_node11_height = 1;
const int step49_node11_width = 1;
float step49_node11_data[1] = {0};
const int step49_node11_num_blks = 0;
int step49_node11_A_blk_start[] = {};
int step49_node11_B_blk_start[] = {};
int step49_node11_blk_width[] = {};


int step49_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 300, };
int step49_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 300, };
int step49_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 300, };
int step49_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 132, 133, 134, 135, 136, 137, 300, };
int step49_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 228, 229, 230, 231, 232, 233, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 300, };
int step49_node5_ridx[] = {
138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 258, 259, 260, 261, 262, 263, 276, 277, 278, 279, 280, 281, 300, };
int step49_node6_ridx[] = {
162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 270, 271, 272, 273, 274, 275, 300, };
int step49_node7_ridx[] = {
198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 300, };
int step49_node8_ridx[] = {
234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 300, };
int step49_node9_ridx[] = {
258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 294, 295, 296, 297, 298, 299, 300, };
int step49_node10_ridx[] = {
282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, };
int step49_node11_ridx[] = {
300, };
const int step49_nnodes = 12;
bool step49_node_marked[] = {false, false, false, false, false, false, false, false, false, step49_node9_marked, step49_node10_marked, step49_node11_marked, };
bool step49_node_fixed[] = {false, false, false, false, false, false, false, false, false, step49_node9_fixed, step49_node10_fixed, step49_node11_fixed, };
int step49_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_num_factors, step49_node10_num_factors, step49_node11_num_factors, };
int step49_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_relin_cost, step49_node10_relin_cost, step49_node11_relin_cost, };
int step49_node_sym_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_sym_cost, step49_node10_sym_cost, step49_node11_sym_cost, };
int* step49_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_factor_height, step49_node10_factor_height, step49_node11_factor_height, };
int* step49_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_factor_width, step49_node10_factor_width, step49_node11_factor_width, };
int** step49_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_factor_ridx, step49_node10_factor_ridx, step49_node11_factor_ridx, };
float** step49_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_factor_data, step49_node10_factor_data, step49_node11_factor_data, };
int* step49_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_factor_num_blks, step49_node10_factor_num_blks, step49_node11_factor_num_blks, };
int** step49_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_factor_A_blk_start, step49_node10_factor_A_blk_start, step49_node11_factor_A_blk_start, };
int** step49_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_factor_B_blk_start, step49_node10_factor_B_blk_start, step49_node11_factor_B_blk_start, };
int** step49_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_factor_blk_width, step49_node10_factor_blk_width, step49_node11_factor_blk_width, };
int step49_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_parent, step49_node10_parent, step49_node11_parent, };
int step49_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_height, step49_node10_height, step49_node11_height, };
int step49_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_width, step49_node10_width, step49_node11_width, };
float* step49_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_data, step49_node10_data, step49_node11_data, };
int step49_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_num_blks, step49_node10_num_blks, step49_node11_num_blks, };
int* step49_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_A_blk_start, step49_node10_A_blk_start, step49_node11_A_blk_start, };
int* step49_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_B_blk_start, step49_node10_B_blk_start, step49_node11_B_blk_start, };
int* step49_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step49_node9_blk_width, step49_node10_blk_width, step49_node11_blk_width, };
int* step49_node_ridx[] = {step49_node0_ridx, step49_node1_ridx, step49_node2_ridx, step49_node3_ridx, step49_node4_ridx, step49_node5_ridx, step49_node6_ridx, step49_node7_ridx, step49_node8_ridx, step49_node9_ridx, step49_node10_ridx, step49_node11_ridx, };


float step49_x_data[301] = {};
const int step49_workspace_needed = 7224;

