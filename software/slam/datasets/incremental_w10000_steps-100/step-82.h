#pragma once

const bool step82_is_reconstruct = true;

const int step82_factor355_height = 7;
const int step82_factor355_width = 3;
int step82_factor355_ridx[] = {21, 22, 23, 24, 25, 26, 27, };
float step82_factor355_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step82_factor355_num_blks = 1;
int step82_factor355_A_blk_start[] = {0, };
int step82_factor355_B_blk_start[] = {21, };
int step82_factor355_blk_width[] = {6, };

const int step82_factor356_height = 4;
const int step82_factor356_width = 3;
int step82_factor356_ridx[] = {3, 4, 5, 6, };
float step82_factor356_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step82_factor356_num_blks = 1;
int step82_factor356_A_blk_start[] = {0, };
int step82_factor356_B_blk_start[] = {3, };
int step82_factor356_blk_width[] = {3, };

const int step82_factor354_height = 4;
const int step82_factor354_width = 3;
int step82_factor354_ridx[] = {0, 1, 2, 6, };
float step82_factor354_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step82_factor354_num_blks = 1;
int step82_factor354_A_blk_start[] = {0, };
int step82_factor354_B_blk_start[] = {0, };
int step82_factor354_blk_width[] = {3, };

const int step82_factor357_height = 7;
const int step82_factor357_width = 3;
int step82_factor357_ridx[] = {0, 1, 2, 3, 4, 5, 6, };
float step82_factor357_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step82_factor357_num_blks = 1;
int step82_factor357_A_blk_start[] = {0, };
int step82_factor357_B_blk_start[] = {0, };
int step82_factor357_blk_width[] = {6, };

const int step82_node8_num_factors = 1;
const bool step82_node8_marked = false;
const bool step82_node8_fixed = true;
int step82_node8_factor_height[] = {step82_factor355_height, };
int step82_node8_factor_width[] = {step82_factor355_width, };
int* step82_node8_factor_ridx[] = {step82_factor355_ridx, };
float* step82_node8_factor_data[] = {step82_factor355_data, };
int step82_node8_factor_num_blks[] = {step82_factor355_num_blks, };
int* step82_node8_factor_A_blk_start[] = {step82_factor355_A_blk_start, };
int* step82_node8_factor_B_blk_start[] = {step82_factor355_B_blk_start, };
int* step82_node8_factor_blk_width[] = {step82_factor355_blk_width, };
const int step82_node8_parent = 9;
const int step82_node8_height = 28;
const int step82_node8_width = 24;
float step82_node8_data[] = {
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
const int step82_node8_num_blks = 1;
int step82_node8_A_blk_start[] = {0, };
int step82_node8_B_blk_start[] = {0, };
int step82_node8_blk_width[] = {3, };


const int step82_node9_num_factors = 3;
const bool step82_node9_marked = true;
const bool step82_node9_fixed = false;
int step82_node9_factor_height[] = {step82_factor354_height, step82_factor356_height, step82_factor357_height, };
int step82_node9_factor_width[] = {step82_factor354_width, step82_factor356_width, step82_factor357_width, };
int* step82_node9_factor_ridx[] = {step82_factor354_ridx, step82_factor356_ridx, step82_factor357_ridx, };
float* step82_node9_factor_data[] = {step82_factor354_data, step82_factor356_data, step82_factor357_data, };
int step82_node9_factor_num_blks[] = {step82_factor354_num_blks, step82_factor356_num_blks, step82_factor357_num_blks, };
int* step82_node9_factor_A_blk_start[] = {step82_factor354_A_blk_start, step82_factor356_A_blk_start, step82_factor357_A_blk_start, };
int* step82_node9_factor_B_blk_start[] = {step82_factor354_B_blk_start, step82_factor356_B_blk_start, step82_factor357_B_blk_start, };
int* step82_node9_factor_blk_width[] = {step82_factor354_blk_width, step82_factor356_blk_width, step82_factor357_blk_width, };
const int step82_node9_parent = 10;
const int step82_node9_height = 7;
const int step82_node9_width = 6;
float step82_node9_data[] = {
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
};
const int step82_node9_num_blks = 0;
int step82_node9_A_blk_start[] = {};
int step82_node9_B_blk_start[] = {};
int step82_node9_blk_width[] = {};


const int step82_node10_num_factors = 0;
const bool step82_node10_marked = true;
const bool step82_node10_fixed = false;
int step82_node10_factor_height[] = {};
int step82_node10_factor_width[] = {};
int* step82_node10_factor_ridx[] = {};
float* step82_node10_factor_data[] = {};
int step82_node10_factor_num_blks[] = {};
int* step82_node10_factor_A_blk_start[] = {};
int* step82_node10_factor_B_blk_start[] = {};
int* step82_node10_factor_blk_width[] = {};
const int step82_node10_parent = -1;
const int step82_node10_height = 1;
const int step82_node10_width = 1;
float step82_node10_data[] = {
0, 
};
const int step82_node10_num_blks = 0;
int step82_node10_A_blk_start[] = {};
int step82_node10_B_blk_start[] = {};
int step82_node10_blk_width[] = {};


int step82_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 153, 154, 155, 156, 157, 158, 159, 160, 161, 249, };
int step82_node1_ridx[] = {
27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 153, 154, 155, 156, 157, 158, 159, 160, 161, 249, };
int step82_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 153, 154, 155, 156, 157, 158, 159, 160, 161, 249, };
int step82_node3_ridx[] = {
81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 153, 154, 155, 156, 157, 158, 159, 160, 161, 249, };
int step82_node4_ridx[] = {
108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 153, 154, 155, 156, 157, 158, 159, 160, 161, 249, };
int step82_node5_ridx[] = {
135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 249, };
int step82_node6_ridx[] = {
171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 249, };
int step82_node7_ridx[] = {
195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 249, };
int step82_node8_ridx[] = {
219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 249, };
int step82_node9_ridx[] = {
243, 244, 245, 246, 247, 248, 249, };
int step82_node10_ridx[] = {
249, };
const int step82_nnodes = 11;
bool step82_node_marked[] = {false, false, false, false, false, false, false, false, step82_node8_marked, step82_node9_marked, step82_node10_marked, };
bool step82_node_fixed[] = {false, false, false, false, false, false, false, false, step82_node8_fixed, step82_node9_fixed, step82_node10_fixed, };
int step82_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_num_factors, step82_node9_num_factors, step82_node10_num_factors, };
int* step82_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_factor_height, step82_node9_factor_height, step82_node10_factor_height, };
int* step82_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_factor_width, step82_node9_factor_width, step82_node10_factor_width, };
int** step82_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_factor_ridx, step82_node9_factor_ridx, step82_node10_factor_ridx, };
float** step82_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_factor_data, step82_node9_factor_data, step82_node10_factor_data, };
int* step82_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_factor_num_blks, step82_node9_factor_num_blks, step82_node10_factor_num_blks, };
int** step82_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_factor_A_blk_start, step82_node9_factor_A_blk_start, step82_node10_factor_A_blk_start, };
int** step82_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_factor_B_blk_start, step82_node9_factor_B_blk_start, step82_node10_factor_B_blk_start, };
int** step82_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_factor_blk_width, step82_node9_factor_blk_width, step82_node10_factor_blk_width, };
int step82_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_parent, step82_node9_parent, step82_node10_parent, };
int step82_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_height, step82_node9_height, step82_node10_height, };
int step82_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_width, step82_node9_width, step82_node10_width, };
float* step82_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_data, step82_node9_data, step82_node10_data, };
int step82_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_num_blks, step82_node9_num_blks, step82_node10_num_blks, };
int* step82_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_A_blk_start, step82_node9_A_blk_start, step82_node10_A_blk_start, };
int* step82_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_B_blk_start, step82_node9_B_blk_start, step82_node10_B_blk_start, };
int* step82_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, step82_node8_blk_width, step82_node9_blk_width, step82_node10_blk_width, };
int* step82_node_ridx[] = {step82_node0_ridx, step82_node1_ridx, step82_node2_ridx, step82_node3_ridx, step82_node4_ridx, step82_node5_ridx, step82_node6_ridx, step82_node7_ridx, step82_node8_ridx, step82_node9_ridx, step82_node10_ridx, };


float step82_x_data[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
