#pragma once

const bool step62_is_reconstruct = true;

const int step62_num_threads = 1;

const uint64_t step62_scaled_relin_cost = 0;

const bool step62_run_model = false;

const int step62_factor203_height = 13;
const int step62_factor203_width = 6;
int step62_factor203_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step62_factor203_data[78] = {0};

const int step62_factor203_num_blks = 1;
int step62_factor203_A_blk_start[] = {0, };
int step62_factor203_B_blk_start[] = {18, };
int step62_factor203_blk_width[] = {12, };

const int step62_factor204_height = 7;
const int step62_factor204_width = 6;
int step62_factor204_ridx[] = {6, 7, 8, 9, 10, 11, 12, };
float step62_factor204_data[42] = {0};

const int step62_factor204_num_blks = 1;
int step62_factor204_A_blk_start[] = {0, };
int step62_factor204_B_blk_start[] = {6, };
int step62_factor204_blk_width[] = {6, };

const int step62_factor202_height = 7;
const int step62_factor202_width = 6;
int step62_factor202_ridx[] = {0, 1, 2, 3, 4, 5, 12, };
float step62_factor202_data[42] = {0};

const int step62_factor202_num_blks = 1;
int step62_factor202_A_blk_start[] = {0, };
int step62_factor202_B_blk_start[] = {0, };
int step62_factor202_blk_width[] = {6, };

const int step62_factor205_height = 13;
const int step62_factor205_width = 6;
int step62_factor205_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, };
float step62_factor205_data[78] = {0};

const int step62_factor205_num_blks = 1;
int step62_factor205_A_blk_start[] = {0, };
int step62_factor205_B_blk_start[] = {0, };
int step62_factor205_blk_width[] = {12, };

const int step62_node12_num_factors = 1;
const int step62_node12_relin_cost = 0;
const int step62_node12_sym_cost = 16000;
const bool step62_node12_marked = false;
const bool step62_node12_fixed = true;
int step62_node12_factor_height[] = {step62_factor203_height, };
int step62_node12_factor_width[] = {step62_factor203_width, };
int* step62_node12_factor_ridx[] = {step62_factor203_ridx, };
float* step62_node12_factor_data[] = {step62_factor203_data, };
int step62_node12_factor_num_blks[] = {step62_factor203_num_blks, };
int* step62_node12_factor_A_blk_start[] = {step62_factor203_A_blk_start, };
int* step62_node12_factor_B_blk_start[] = {step62_factor203_B_blk_start, };
int* step62_node12_factor_blk_width[] = {step62_factor203_blk_width, };
const int step62_node12_parent = 13;
const int step62_node12_height = 31;
const int step62_node12_width = 24;
float step62_node12_data[744] = {0};
const int step62_node12_num_blks = 1;
int step62_node12_A_blk_start[] = {0, };
int step62_node12_B_blk_start[] = {0, };
int step62_node12_blk_width[] = {6, };


const int step62_node13_num_factors = 3;
const int step62_node13_relin_cost = 0;
const int step62_node13_sym_cost = 8000;
const bool step62_node13_marked = true;
const bool step62_node13_fixed = false;
int step62_node13_factor_height[] = {step62_factor202_height, step62_factor204_height, step62_factor205_height, };
int step62_node13_factor_width[] = {step62_factor202_width, step62_factor204_width, step62_factor205_width, };
int* step62_node13_factor_ridx[] = {step62_factor202_ridx, step62_factor204_ridx, step62_factor205_ridx, };
float* step62_node13_factor_data[] = {step62_factor202_data, step62_factor204_data, step62_factor205_data, };
int step62_node13_factor_num_blks[] = {step62_factor202_num_blks, step62_factor204_num_blks, step62_factor205_num_blks, };
int* step62_node13_factor_A_blk_start[] = {step62_factor202_A_blk_start, step62_factor204_A_blk_start, step62_factor205_A_blk_start, };
int* step62_node13_factor_B_blk_start[] = {step62_factor202_B_blk_start, step62_factor204_B_blk_start, step62_factor205_B_blk_start, };
int* step62_node13_factor_blk_width[] = {step62_factor202_blk_width, step62_factor204_blk_width, step62_factor205_blk_width, };
const int step62_node13_parent = 14;
const int step62_node13_height = 13;
const int step62_node13_width = 12;
float step62_node13_data[156] = {0};
const int step62_node13_num_blks = 0;
int step62_node13_A_blk_start[] = {};
int step62_node13_B_blk_start[] = {};
int step62_node13_blk_width[] = {};


const int step62_node14_num_factors = 0;
const int step62_node14_relin_cost = 0;
const int step62_node14_sym_cost = 4000;
const bool step62_node14_marked = true;
const bool step62_node14_fixed = false;
int step62_node14_factor_height[] = {};
int step62_node14_factor_width[] = {};
int* step62_node14_factor_ridx[] = {};
float* step62_node14_factor_data[] = {};
int step62_node14_factor_num_blks[] = {};
int* step62_node14_factor_A_blk_start[] = {};
int* step62_node14_factor_B_blk_start[] = {};
int* step62_node14_factor_blk_width[] = {};
const int step62_node14_parent = -1;
const int step62_node14_height = 1;
const int step62_node14_width = 1;
float step62_node14_data[1] = {0};
const int step62_node14_num_blks = 0;
int step62_node14_A_blk_start[] = {};
int step62_node14_B_blk_start[] = {};
int step62_node14_blk_width[] = {};


int step62_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 378, };
int step62_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 378, };
int step62_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 108, 109, 110, 111, 112, 113, 378, };
int step62_node3_ridx[] = {
90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 246, 247, 248, 249, 250, 251, 270, 271, 272, 273, 274, 275, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 378, };
int step62_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 180, 181, 182, 183, 184, 185, 294, 295, 296, 297, 298, 299, 378, };
int step62_node5_ridx[] = {
138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 240, 241, 242, 243, 244, 245, 288, 289, 290, 291, 292, 293, 378, };
int step62_node6_ridx[] = {
162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 378, };
int step62_node7_ridx[] = {
192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 378, };
int step62_node8_ridx[] = {
228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 270, 271, 272, 273, 274, 275, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 378, };
int step62_node9_ridx[] = {
252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 378, };
int step62_node10_ridx[] = {
288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 378, };
int step62_node11_ridx[] = {
312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 378, };
int step62_node12_ridx[] = {
342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 378, };
int step62_node13_ridx[] = {
366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, };
int step62_node14_ridx[] = {
378, };
const int step62_nnodes = 15;
bool step62_node_marked[] = {false, false, false, false, false, false, false, false, false, false, false, false, step62_node12_marked, step62_node13_marked, step62_node14_marked, };
bool step62_node_fixed[] = {false, false, false, false, false, false, false, false, false, false, false, false, step62_node12_fixed, step62_node13_fixed, step62_node14_fixed, };
int step62_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_num_factors, step62_node13_num_factors, step62_node14_num_factors, };
int step62_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_relin_cost, step62_node13_relin_cost, step62_node14_relin_cost, };
int step62_node_sym_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_sym_cost, step62_node13_sym_cost, step62_node14_sym_cost, };
int* step62_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_factor_height, step62_node13_factor_height, step62_node14_factor_height, };
int* step62_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_factor_width, step62_node13_factor_width, step62_node14_factor_width, };
int** step62_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_factor_ridx, step62_node13_factor_ridx, step62_node14_factor_ridx, };
float** step62_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_factor_data, step62_node13_factor_data, step62_node14_factor_data, };
int* step62_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_factor_num_blks, step62_node13_factor_num_blks, step62_node14_factor_num_blks, };
int** step62_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_factor_A_blk_start, step62_node13_factor_A_blk_start, step62_node14_factor_A_blk_start, };
int** step62_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_factor_B_blk_start, step62_node13_factor_B_blk_start, step62_node14_factor_B_blk_start, };
int** step62_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_factor_blk_width, step62_node13_factor_blk_width, step62_node14_factor_blk_width, };
int step62_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_parent, step62_node13_parent, step62_node14_parent, };
int step62_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_height, step62_node13_height, step62_node14_height, };
int step62_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_width, step62_node13_width, step62_node14_width, };
float* step62_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_data, step62_node13_data, step62_node14_data, };
int step62_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_num_blks, step62_node13_num_blks, step62_node14_num_blks, };
int* step62_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_A_blk_start, step62_node13_A_blk_start, step62_node14_A_blk_start, };
int* step62_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_B_blk_start, step62_node13_B_blk_start, step62_node14_B_blk_start, };
int* step62_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step62_node12_blk_width, step62_node13_blk_width, step62_node14_blk_width, };
int* step62_node_ridx[] = {step62_node0_ridx, step62_node1_ridx, step62_node2_ridx, step62_node3_ridx, step62_node4_ridx, step62_node5_ridx, step62_node6_ridx, step62_node7_ridx, step62_node8_ridx, step62_node9_ridx, step62_node10_ridx, step62_node11_ridx, step62_node12_ridx, step62_node13_ridx, step62_node14_ridx, };


float step62_x_data[379] = {};
const int step62_workspace_needed = 4824;

