#pragma once

const bool step90_is_reconstruct = true;

const int step90_factor377_height = 4;
const int step90_factor377_width = 3;
int step90_factor377_ridx[] = {3, 4, 5, 6, };
float step90_factor377_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step90_factor377_num_blks = 1;
int step90_factor377_A_blk_start[] = {0, };
int step90_factor377_B_blk_start[] = {3, };
int step90_factor377_blk_width[] = {3, };

const int step90_factor375_height = 4;
const int step90_factor375_width = 3;
int step90_factor375_ridx[] = {0, 1, 2, 6, };
float step90_factor375_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step90_factor375_num_blks = 1;
int step90_factor375_A_blk_start[] = {0, };
int step90_factor375_B_blk_start[] = {0, };
int step90_factor375_blk_width[] = {3, };

const int step90_factor378_height = 7;
const int step90_factor378_width = 3;
int step90_factor378_ridx[] = {0, 1, 2, 3, 4, 5, 6, };
float step90_factor378_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step90_factor378_num_blks = 1;
int step90_factor378_A_blk_start[] = {0, };
int step90_factor378_B_blk_start[] = {0, };
int step90_factor378_blk_width[] = {6, };

const int step90_factor376_height = 7;
const int step90_factor376_width = 3;
int step90_factor376_ridx[] = {3, 4, 5, 24, 25, 26, 27, };
float step90_factor376_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step90_factor376_num_blks = 2;
int step90_factor376_A_blk_start[] = {0, 3, };
int step90_factor376_B_blk_start[] = {3, 24, };
int step90_factor376_blk_width[] = {3, 3, };

const int step90_node9_num_factors = 1;
const bool step90_node9_marked = false;
const bool step90_node9_fixed = true;
int step90_node9_factor_height[] = {step90_factor376_height, };
int step90_node9_factor_width[] = {step90_factor376_width, };
int* step90_node9_factor_ridx[] = {step90_factor376_ridx, };
float* step90_node9_factor_data[] = {step90_factor376_data, };
int step90_node9_factor_num_blks[] = {step90_factor376_num_blks, };
int* step90_node9_factor_A_blk_start[] = {step90_factor376_A_blk_start, };
int* step90_node9_factor_B_blk_start[] = {step90_factor376_B_blk_start, };
int* step90_node9_factor_blk_width[] = {step90_factor376_blk_width, };
const int step90_node9_parent = 10;
const int step90_node9_height = 28;
const int step90_node9_width = 24;
float step90_node9_data[] = {
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
};
const int step90_node9_num_blks = 1;
int step90_node9_A_blk_start[] = {0, };
int step90_node9_B_blk_start[] = {0, };
int step90_node9_blk_width[] = {3, };


const int step90_node10_num_factors = 3;
const bool step90_node10_marked = true;
const bool step90_node10_fixed = false;
int step90_node10_factor_height[] = {step90_factor375_height, step90_factor377_height, step90_factor378_height, };
int step90_node10_factor_width[] = {step90_factor375_width, step90_factor377_width, step90_factor378_width, };
int* step90_node10_factor_ridx[] = {step90_factor375_ridx, step90_factor377_ridx, step90_factor378_ridx, };
float* step90_node10_factor_data[] = {step90_factor375_data, step90_factor377_data, step90_factor378_data, };
int step90_node10_factor_num_blks[] = {step90_factor375_num_blks, step90_factor377_num_blks, step90_factor378_num_blks, };
int* step90_node10_factor_A_blk_start[] = {step90_factor375_A_blk_start, step90_factor377_A_blk_start, step90_factor378_A_blk_start, };
int* step90_node10_factor_B_blk_start[] = {step90_factor375_B_blk_start, step90_factor377_B_blk_start, step90_factor378_B_blk_start, };
int* step90_node10_factor_blk_width[] = {step90_factor375_blk_width, step90_factor377_blk_width, step90_factor378_blk_width, };
const int step90_node10_parent = 11;
const int step90_node10_height = 7;
const int step90_node10_width = 6;
float step90_node10_data[] = {
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
};
const int step90_node10_num_blks = 0;
int step90_node10_A_blk_start[] = {};
int step90_node10_B_blk_start[] = {};
int step90_node10_blk_width[] = {};


const int step90_node11_num_factors = 0;
const bool step90_node11_marked = true;
const bool step90_node11_fixed = false;
int step90_node11_factor_height[] = {};
int step90_node11_factor_width[] = {};
int* step90_node11_factor_ridx[] = {};
float* step90_node11_factor_data[] = {};
int step90_node11_factor_num_blks[] = {};
int* step90_node11_factor_A_blk_start[] = {};
int* step90_node11_factor_B_blk_start[] = {};
int* step90_node11_factor_blk_width[] = {};
const int step90_node11_parent = -1;
const int step90_node11_height = 1;
const int step90_node11_width = 1;
float step90_node11_data[] = {
0, 
};
const int step90_node11_num_blks = 0;
int step90_node11_A_blk_start[] = {};
int step90_node11_B_blk_start[] = {};
int step90_node11_blk_width[] = {};


int step90_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 153, 154, 155, 156, 157, 158, 159, 160, 161, 273, };
int step90_node1_ridx[] = {
27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 153, 154, 155, 156, 157, 158, 159, 160, 161, 273, };
int step90_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 153, 154, 155, 156, 157, 158, 159, 160, 161, 273, };
int step90_node3_ridx[] = {
81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 153, 154, 155, 156, 157, 158, 159, 160, 161, 273, };
int step90_node4_ridx[] = {
108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 153, 154, 155, 156, 157, 158, 159, 160, 161, 273, };
int step90_node5_ridx[] = {
135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 273, };
int step90_node6_ridx[] = {
171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 258, 259, 260, 273, };
int step90_node7_ridx[] = {
195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 258, 259, 260, 261, 262, 263, 264, 265, 266, 273, };
int step90_node8_ridx[] = {
219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 273, };
int step90_node9_ridx[] = {
243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 273, };
int step90_node10_ridx[] = {
267, 268, 269, 270, 271, 272, 273, };
int step90_node11_ridx[] = {
273, };
const int step90_nnodes = 12;
bool step90_node_marked[] = {false, false, false, false, false, false, false, false, false, step90_node9_marked, step90_node10_marked, step90_node11_marked, };
bool step90_node_fixed[] = {false, false, false, false, false, false, false, false, false, step90_node9_fixed, step90_node10_fixed, step90_node11_fixed, };
int step90_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_num_factors, step90_node10_num_factors, step90_node11_num_factors, };
int* step90_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_factor_height, step90_node10_factor_height, step90_node11_factor_height, };
int* step90_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_factor_width, step90_node10_factor_width, step90_node11_factor_width, };
int** step90_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_factor_ridx, step90_node10_factor_ridx, step90_node11_factor_ridx, };
float** step90_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_factor_data, step90_node10_factor_data, step90_node11_factor_data, };
int* step90_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_factor_num_blks, step90_node10_factor_num_blks, step90_node11_factor_num_blks, };
int** step90_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_factor_A_blk_start, step90_node10_factor_A_blk_start, step90_node11_factor_A_blk_start, };
int** step90_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_factor_B_blk_start, step90_node10_factor_B_blk_start, step90_node11_factor_B_blk_start, };
int** step90_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_factor_blk_width, step90_node10_factor_blk_width, step90_node11_factor_blk_width, };
int step90_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_parent, step90_node10_parent, step90_node11_parent, };
int step90_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_height, step90_node10_height, step90_node11_height, };
int step90_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_width, step90_node10_width, step90_node11_width, };
float* step90_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_data, step90_node10_data, step90_node11_data, };
int step90_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_num_blks, step90_node10_num_blks, step90_node11_num_blks, };
int* step90_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_A_blk_start, step90_node10_A_blk_start, step90_node11_A_blk_start, };
int* step90_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_B_blk_start, step90_node10_B_blk_start, step90_node11_B_blk_start, };
int* step90_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step90_node9_blk_width, step90_node10_blk_width, step90_node11_blk_width, };
int* step90_node_ridx[] = {step90_node0_ridx, step90_node1_ridx, step90_node2_ridx, step90_node3_ridx, step90_node4_ridx, step90_node5_ridx, step90_node6_ridx, step90_node7_ridx, step90_node8_ridx, step90_node9_ridx, step90_node10_ridx, step90_node11_ridx, };


float step90_x_data[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };