#pragma once

const bool step59_is_reconstruct = true;

const int step59_num_threads = 1;

const uint64_t step59_scaled_relin_cost = 0;

const bool step59_run_model = false;

const int step59_factor191_height = 7;
const int step59_factor191_width = 6;
int step59_factor191_ridx[] = {0, 1, 2, 3, 4, 5, 18, };
float step59_factor191_data[42] = {0};

const int step59_factor191_num_blks = 1;
int step59_factor191_A_blk_start[] = {0, };
int step59_factor191_B_blk_start[] = {0, };
int step59_factor191_blk_width[] = {6, };

const int step59_factor192_height = 13;
const int step59_factor192_width = 6;
int step59_factor192_ridx[] = {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 42, };
float step59_factor192_data[78] = {0};

const int step59_factor192_num_blks = 1;
int step59_factor192_A_blk_start[] = {0, };
int step59_factor192_B_blk_start[] = {24, };
int step59_factor192_blk_width[] = {12, };

const int step59_factor193_height = 13;
const int step59_factor193_width = 6;
int step59_factor193_ridx[] = {0, 1, 2, 3, 4, 5, 30, 31, 32, 33, 34, 35, 42, };
float step59_factor193_data[78] = {0};

const int step59_factor193_num_blks = 2;
int step59_factor193_A_blk_start[] = {0, 6, };
int step59_factor193_B_blk_start[] = {0, 30, };
int step59_factor193_blk_width[] = {6, 6, };

const int step59_factor194_height = 7;
const int step59_factor194_width = 6;
int step59_factor194_ridx[] = {6, 7, 8, 9, 10, 11, 18, };
float step59_factor194_data[42] = {0};

const int step59_factor194_num_blks = 1;
int step59_factor194_A_blk_start[] = {0, };
int step59_factor194_B_blk_start[] = {6, };
int step59_factor194_blk_width[] = {6, };

const int step59_factor195_height = 13;
const int step59_factor195_width = 6;
int step59_factor195_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 18, };
float step59_factor195_data[78] = {0};

const int step59_factor195_num_blks = 1;
int step59_factor195_A_blk_start[] = {0, };
int step59_factor195_B_blk_start[] = {0, };
int step59_factor195_blk_width[] = {12, };

const int step59_factor196_height = 7;
const int step59_factor196_width = 6;
int step59_factor196_ridx[] = {12, 13, 14, 15, 16, 17, 18, };
float step59_factor196_data[42] = {0};

const int step59_factor196_num_blks = 1;
int step59_factor196_A_blk_start[] = {0, };
int step59_factor196_B_blk_start[] = {12, };
int step59_factor196_blk_width[] = {6, };

const int step59_factor197_height = 13;
const int step59_factor197_width = 6;
int step59_factor197_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, };
float step59_factor197_data[78] = {0};

const int step59_factor197_num_blks = 1;
int step59_factor197_A_blk_start[] = {0, };
int step59_factor197_B_blk_start[] = {6, };
int step59_factor197_blk_width[] = {12, };

const int step59_factor198_height = 13;
const int step59_factor198_width = 6;
int step59_factor198_ridx[] = {18, 19, 20, 21, 22, 23, 30, 31, 32, 33, 34, 35, 36, };
float step59_factor198_data[78] = {0};

const int step59_factor198_num_blks = 2;
int step59_factor198_A_blk_start[] = {0, 6, };
int step59_factor198_B_blk_start[] = {18, 30, };
int step59_factor198_blk_width[] = {6, 6, };

const int step59_node10_num_factors = 1;
const int step59_node10_relin_cost = 30000;
const bool step59_node10_marked = false;
const bool step59_node10_fixed = true;
int step59_node10_factor_height[] = {step59_factor198_height, };
int step59_node10_factor_width[] = {step59_factor198_width, };
int* step59_node10_factor_ridx[] = {step59_factor198_ridx, };
float* step59_node10_factor_data[] = {step59_factor198_data, };
int step59_node10_factor_num_blks[] = {step59_factor198_num_blks, };
int* step59_node10_factor_A_blk_start[] = {step59_factor198_A_blk_start, };
int* step59_node10_factor_B_blk_start[] = {step59_factor198_B_blk_start, };
int* step59_node10_factor_blk_width[] = {step59_factor198_blk_width, };
const int step59_node10_parent = 11;
const int step59_node10_height = 37;
const int step59_node10_width = 24;
float step59_node10_data[888] = {0};
const int step59_node10_num_blks = 2;
int step59_node10_A_blk_start[] = {0, 6, };
int step59_node10_B_blk_start[] = {0, 36, };
int step59_node10_blk_width[] = {6, 6, };


const int step59_node11_num_factors = 2;
const int step59_node11_relin_cost = 60000;
const bool step59_node11_marked = false;
const bool step59_node11_fixed = true;
int step59_node11_factor_height[] = {step59_factor192_height, step59_factor193_height, };
int step59_node11_factor_width[] = {step59_factor192_width, step59_factor193_width, };
int* step59_node11_factor_ridx[] = {step59_factor192_ridx, step59_factor193_ridx, };
float* step59_node11_factor_data[] = {step59_factor192_data, step59_factor193_data, };
int step59_node11_factor_num_blks[] = {step59_factor192_num_blks, step59_factor193_num_blks, };
int* step59_node11_factor_A_blk_start[] = {step59_factor192_A_blk_start, step59_factor193_A_blk_start, };
int* step59_node11_factor_B_blk_start[] = {step59_factor192_B_blk_start, step59_factor193_B_blk_start, };
int* step59_node11_factor_blk_width[] = {step59_factor192_blk_width, step59_factor193_blk_width, };
const int step59_node11_parent = 12;
const int step59_node11_height = 43;
const int step59_node11_width = 30;
float step59_node11_data[1290] = {0};
const int step59_node11_num_blks = 2;
int step59_node11_A_blk_start[] = {0, 6, };
int step59_node11_B_blk_start[] = {0, 12, };
int step59_node11_blk_width[] = {6, 6, };


const int step59_node12_num_factors = 5;
const int step59_node12_relin_cost = 150000;
const bool step59_node12_marked = true;
const bool step59_node12_fixed = false;
int step59_node12_factor_height[] = {step59_factor191_height, step59_factor194_height, step59_factor195_height, step59_factor196_height, step59_factor197_height, };
int step59_node12_factor_width[] = {step59_factor191_width, step59_factor194_width, step59_factor195_width, step59_factor196_width, step59_factor197_width, };
int* step59_node12_factor_ridx[] = {step59_factor191_ridx, step59_factor194_ridx, step59_factor195_ridx, step59_factor196_ridx, step59_factor197_ridx, };
float* step59_node12_factor_data[] = {step59_factor191_data, step59_factor194_data, step59_factor195_data, step59_factor196_data, step59_factor197_data, };
int step59_node12_factor_num_blks[] = {step59_factor191_num_blks, step59_factor194_num_blks, step59_factor195_num_blks, step59_factor196_num_blks, step59_factor197_num_blks, };
int* step59_node12_factor_A_blk_start[] = {step59_factor191_A_blk_start, step59_factor194_A_blk_start, step59_factor195_A_blk_start, step59_factor196_A_blk_start, step59_factor197_A_blk_start, };
int* step59_node12_factor_B_blk_start[] = {step59_factor191_B_blk_start, step59_factor194_B_blk_start, step59_factor195_B_blk_start, step59_factor196_B_blk_start, step59_factor197_B_blk_start, };
int* step59_node12_factor_blk_width[] = {step59_factor191_blk_width, step59_factor194_blk_width, step59_factor195_blk_width, step59_factor196_blk_width, step59_factor197_blk_width, };
const int step59_node12_parent = 13;
const int step59_node12_height = 19;
const int step59_node12_width = 18;
float step59_node12_data[342] = {0};
const int step59_node12_num_blks = 0;
int step59_node12_A_blk_start[] = {};
int step59_node12_B_blk_start[] = {};
int step59_node12_blk_width[] = {};


const int step59_node13_num_factors = 0;
const int step59_node13_relin_cost = 0;
const bool step59_node13_marked = true;
const bool step59_node13_fixed = false;
int step59_node13_factor_height[] = {};
int step59_node13_factor_width[] = {};
int* step59_node13_factor_ridx[] = {};
float* step59_node13_factor_data[] = {};
int step59_node13_factor_num_blks[] = {};
int* step59_node13_factor_A_blk_start[] = {};
int* step59_node13_factor_B_blk_start[] = {};
int* step59_node13_factor_blk_width[] = {};
const int step59_node13_parent = -1;
const int step59_node13_height = 1;
const int step59_node13_width = 1;
float step59_node13_data[1] = {0};
const int step59_node13_num_blks = 0;
int step59_node13_A_blk_start[] = {};
int step59_node13_B_blk_start[] = {};
int step59_node13_blk_width[] = {};


int step59_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 360, };
int step59_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 360, };
int step59_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 360, };
int step59_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 246, 247, 248, 249, 250, 251, 360, };
int step59_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 276, 277, 278, 279, 280, 281, 360, };
int step59_node5_ridx[] = {
150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 240, 241, 242, 243, 244, 245, 270, 271, 272, 273, 274, 275, 360, };
int step59_node6_ridx[] = {
174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 240, 241, 242, 243, 244, 245, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 360, };
int step59_node7_ridx[] = {
198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 360, };
int step59_node8_ridx[] = {
222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 360, };
int step59_node9_ridx[] = {
264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 360, };
int step59_node10_ridx[] = {
288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 354, 355, 356, 357, 358, 359, 360, };
int step59_node11_ridx[] = {
312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 354, 355, 356, 357, 358, 359, 360, };
int step59_node12_ridx[] = {
342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, };
int step59_node13_ridx[] = {
360, };
const int step59_nnodes = 14;
bool step59_node_marked[] = {false, false, false, false, false, false, false, false, false, false, step59_node10_marked, step59_node11_marked, step59_node12_marked, step59_node13_marked, };
bool step59_node_fixed[] = {false, false, false, false, false, false, false, false, false, false, step59_node10_fixed, step59_node11_fixed, step59_node12_fixed, step59_node13_fixed, };
int step59_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_num_factors, step59_node11_num_factors, step59_node12_num_factors, step59_node13_num_factors, };
int step59_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_relin_cost, step59_node11_relin_cost, step59_node12_relin_cost, step59_node13_relin_cost, };
int* step59_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_factor_height, step59_node11_factor_height, step59_node12_factor_height, step59_node13_factor_height, };
int* step59_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_factor_width, step59_node11_factor_width, step59_node12_factor_width, step59_node13_factor_width, };
int** step59_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_factor_ridx, step59_node11_factor_ridx, step59_node12_factor_ridx, step59_node13_factor_ridx, };
float** step59_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_factor_data, step59_node11_factor_data, step59_node12_factor_data, step59_node13_factor_data, };
int* step59_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_factor_num_blks, step59_node11_factor_num_blks, step59_node12_factor_num_blks, step59_node13_factor_num_blks, };
int** step59_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_factor_A_blk_start, step59_node11_factor_A_blk_start, step59_node12_factor_A_blk_start, step59_node13_factor_A_blk_start, };
int** step59_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_factor_B_blk_start, step59_node11_factor_B_blk_start, step59_node12_factor_B_blk_start, step59_node13_factor_B_blk_start, };
int** step59_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_factor_blk_width, step59_node11_factor_blk_width, step59_node12_factor_blk_width, step59_node13_factor_blk_width, };
int step59_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_parent, step59_node11_parent, step59_node12_parent, step59_node13_parent, };
int step59_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_height, step59_node11_height, step59_node12_height, step59_node13_height, };
int step59_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_width, step59_node11_width, step59_node12_width, step59_node13_width, };
float* step59_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_data, step59_node11_data, step59_node12_data, step59_node13_data, };
int step59_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_num_blks, step59_node11_num_blks, step59_node12_num_blks, step59_node13_num_blks, };
int* step59_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_A_blk_start, step59_node11_A_blk_start, step59_node12_A_blk_start, step59_node13_A_blk_start, };
int* step59_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_B_blk_start, step59_node11_B_blk_start, step59_node12_B_blk_start, step59_node13_B_blk_start, };
int* step59_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step59_node10_blk_width, step59_node11_blk_width, step59_node12_blk_width, step59_node13_blk_width, };
int* step59_node_ridx[] = {step59_node0_ridx, step59_node1_ridx, step59_node2_ridx, step59_node3_ridx, step59_node4_ridx, step59_node5_ridx, step59_node6_ridx, step59_node7_ridx, step59_node8_ridx, step59_node9_ridx, step59_node10_ridx, step59_node11_ridx, step59_node12_ridx, step59_node13_ridx, };


float step59_x_data[361] = {};
const int step59_workspace_needed = 14720;

