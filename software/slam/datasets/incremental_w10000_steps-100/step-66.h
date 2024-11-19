#pragma once

const bool step66_is_reconstruct = true;

const int step66_factor322_height = 4;
const int step66_factor322_width = 3;
int step66_factor322_ridx[] = {0, 1, 2, 6, };
float step66_factor322_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step66_factor322_num_blks = 1;
int step66_factor322_A_blk_start[] = {0, };
int step66_factor322_B_blk_start[] = {0, };
int step66_factor322_blk_width[] = {3, };

const int step66_factor325_height = 7;
const int step66_factor325_width = 3;
int step66_factor325_ridx[] = {0, 1, 2, 3, 4, 5, 6, };
float step66_factor325_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step66_factor325_num_blks = 1;
int step66_factor325_A_blk_start[] = {0, };
int step66_factor325_B_blk_start[] = {0, };
int step66_factor325_blk_width[] = {6, };

const int step66_factor323_height = 7;
const int step66_factor323_width = 3;
int step66_factor323_ridx[] = {21, 22, 23, 24, 25, 26, 27, };
float step66_factor323_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step66_factor323_num_blks = 1;
int step66_factor323_A_blk_start[] = {0, };
int step66_factor323_B_blk_start[] = {21, };
int step66_factor323_blk_width[] = {6, };

const int step66_factor324_height = 4;
const int step66_factor324_width = 3;
int step66_factor324_ridx[] = {3, 4, 5, 6, };
float step66_factor324_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step66_factor324_num_blks = 1;
int step66_factor324_A_blk_start[] = {0, };
int step66_factor324_B_blk_start[] = {3, };
int step66_factor324_blk_width[] = {3, };

const int step66_node6_num_factors = 1;
const bool step66_node6_marked = false;
const bool step66_node6_fixed = true;
int step66_node6_factor_height[] = {step66_factor323_height, };
int step66_node6_factor_width[] = {step66_factor323_width, };
int* step66_node6_factor_ridx[] = {step66_factor323_ridx, };
float* step66_node6_factor_data[] = {step66_factor323_data, };
int step66_node6_factor_num_blks[] = {step66_factor323_num_blks, };
int* step66_node6_factor_A_blk_start[] = {step66_factor323_A_blk_start, };
int* step66_node6_factor_B_blk_start[] = {step66_factor323_B_blk_start, };
int* step66_node6_factor_blk_width[] = {step66_factor323_blk_width, };
const int step66_node6_parent = 7;
const int step66_node6_height = 28;
const int step66_node6_width = 24;
float step66_node6_data[] = {
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
const int step66_node6_num_blks = 1;
int step66_node6_A_blk_start[] = {0, };
int step66_node6_B_blk_start[] = {0, };
int step66_node6_blk_width[] = {3, };


const int step66_node7_num_factors = 3;
const bool step66_node7_marked = true;
const bool step66_node7_fixed = false;
int step66_node7_factor_height[] = {step66_factor322_height, step66_factor324_height, step66_factor325_height, };
int step66_node7_factor_width[] = {step66_factor322_width, step66_factor324_width, step66_factor325_width, };
int* step66_node7_factor_ridx[] = {step66_factor322_ridx, step66_factor324_ridx, step66_factor325_ridx, };
float* step66_node7_factor_data[] = {step66_factor322_data, step66_factor324_data, step66_factor325_data, };
int step66_node7_factor_num_blks[] = {step66_factor322_num_blks, step66_factor324_num_blks, step66_factor325_num_blks, };
int* step66_node7_factor_A_blk_start[] = {step66_factor322_A_blk_start, step66_factor324_A_blk_start, step66_factor325_A_blk_start, };
int* step66_node7_factor_B_blk_start[] = {step66_factor322_B_blk_start, step66_factor324_B_blk_start, step66_factor325_B_blk_start, };
int* step66_node7_factor_blk_width[] = {step66_factor322_blk_width, step66_factor324_blk_width, step66_factor325_blk_width, };
const int step66_node7_parent = 8;
const int step66_node7_height = 7;
const int step66_node7_width = 6;
float step66_node7_data[] = {
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
};
const int step66_node7_num_blks = 0;
int step66_node7_A_blk_start[] = {};
int step66_node7_B_blk_start[] = {};
int step66_node7_blk_width[] = {};


const int step66_node8_num_factors = 0;
const bool step66_node8_marked = true;
const bool step66_node8_fixed = false;
int step66_node8_factor_height[] = {};
int step66_node8_factor_width[] = {};
int* step66_node8_factor_ridx[] = {};
float* step66_node8_factor_data[] = {};
int step66_node8_factor_num_blks[] = {};
int* step66_node8_factor_A_blk_start[] = {};
int* step66_node8_factor_B_blk_start[] = {};
int* step66_node8_factor_blk_width[] = {};
const int step66_node8_parent = -1;
const int step66_node8_height = 1;
const int step66_node8_width = 1;
float step66_node8_data[] = {
0, 
};
const int step66_node8_num_blks = 0;
int step66_node8_A_blk_start[] = {};
int step66_node8_B_blk_start[] = {};
int step66_node8_blk_width[] = {};


int step66_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 153, 154, 155, 156, 157, 158, 159, 160, 161, 201, };
int step66_node1_ridx[] = {
27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 153, 154, 155, 156, 157, 158, 159, 160, 161, 201, };
int step66_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 153, 154, 155, 156, 157, 158, 159, 160, 161, 201, };
int step66_node3_ridx[] = {
81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 153, 154, 155, 156, 157, 158, 159, 160, 161, 201, };
int step66_node4_ridx[] = {
108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 153, 154, 155, 156, 157, 158, 159, 160, 161, 201, };
int step66_node5_ridx[] = {
135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 201, };
int step66_node6_ridx[] = {
171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 201, };
int step66_node7_ridx[] = {
195, 196, 197, 198, 199, 200, 201, };
int step66_node8_ridx[] = {
201, };
const int step66_nnodes = 9;
bool step66_node_marked[] = {false, false, false, false, false, false, step66_node6_marked, step66_node7_marked, step66_node8_marked, };
bool step66_node_fixed[] = {false, false, false, false, false, false, step66_node6_fixed, step66_node7_fixed, step66_node8_fixed, };
int step66_node_num_factors[] = {0, 0, 0, 0, 0, 0, step66_node6_num_factors, step66_node7_num_factors, step66_node8_num_factors, };
int* step66_node_factor_height[] = {0, 0, 0, 0, 0, 0, step66_node6_factor_height, step66_node7_factor_height, step66_node8_factor_height, };
int* step66_node_factor_width[] = {0, 0, 0, 0, 0, 0, step66_node6_factor_width, step66_node7_factor_width, step66_node8_factor_width, };
int** step66_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, step66_node6_factor_ridx, step66_node7_factor_ridx, step66_node8_factor_ridx, };
float** step66_node_factor_data[] = {0, 0, 0, 0, 0, 0, step66_node6_factor_data, step66_node7_factor_data, step66_node8_factor_data, };
int* step66_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, step66_node6_factor_num_blks, step66_node7_factor_num_blks, step66_node8_factor_num_blks, };
int** step66_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, step66_node6_factor_A_blk_start, step66_node7_factor_A_blk_start, step66_node8_factor_A_blk_start, };
int** step66_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, step66_node6_factor_B_blk_start, step66_node7_factor_B_blk_start, step66_node8_factor_B_blk_start, };
int** step66_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, step66_node6_factor_blk_width, step66_node7_factor_blk_width, step66_node8_factor_blk_width, };
int step66_node_parent[] = {0, 0, 0, 0, 0, 0, step66_node6_parent, step66_node7_parent, step66_node8_parent, };
int step66_node_height[] = {0, 0, 0, 0, 0, 0, step66_node6_height, step66_node7_height, step66_node8_height, };
int step66_node_width[] = {0, 0, 0, 0, 0, 0, step66_node6_width, step66_node7_width, step66_node8_width, };
float* step66_node_data[] = {0, 0, 0, 0, 0, 0, step66_node6_data, step66_node7_data, step66_node8_data, };
int step66_node_num_blks[] = {0, 0, 0, 0, 0, 0, step66_node6_num_blks, step66_node7_num_blks, step66_node8_num_blks, };
int* step66_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, step66_node6_A_blk_start, step66_node7_A_blk_start, step66_node8_A_blk_start, };
int* step66_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, step66_node6_B_blk_start, step66_node7_B_blk_start, step66_node8_B_blk_start, };
int* step66_node_blk_width[] = {0, 0, 0, 0, 0, 0, step66_node6_blk_width, step66_node7_blk_width, step66_node8_blk_width, };
int* step66_node_ridx[] = {step66_node0_ridx, step66_node1_ridx, step66_node2_ridx, step66_node3_ridx, step66_node4_ridx, step66_node5_ridx, step66_node6_ridx, step66_node7_ridx, step66_node8_ridx, };


float step66_x_data[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
