#pragma once

const bool step71_is_reconstruct = true;

const int step71_num_threads = 1;

const uint64_t step71_scaled_relin_cost = 0;

const bool step71_run_model = false;

const int step71_factor223_height = 7;
const int step71_factor223_width = 6;
int step71_factor223_ridx[] = {0, 1, 2, 3, 4, 5, 12, };
float step71_factor223_data[42] = {0};

const int step71_factor223_num_blks = 1;
int step71_factor223_A_blk_start[] = {0, };
int step71_factor223_B_blk_start[] = {0, };
int step71_factor223_blk_width[] = {6, };

const int step71_factor224_height = 13;
const int step71_factor224_width = 6;
int step71_factor224_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step71_factor224_data[78] = {0};

const int step71_factor224_num_blks = 1;
int step71_factor224_A_blk_start[] = {0, };
int step71_factor224_B_blk_start[] = {18, };
int step71_factor224_blk_width[] = {12, };

const int step71_factor225_height = 13;
const int step71_factor225_width = 6;
int step71_factor225_ridx[] = {12, 13, 14, 15, 16, 17, 24, 25, 26, 27, 28, 29, 30, };
float step71_factor225_data[78] = {0};

const int step71_factor225_num_blks = 2;
int step71_factor225_A_blk_start[] = {0, 6, };
int step71_factor225_B_blk_start[] = {12, 24, };
int step71_factor225_blk_width[] = {6, 6, };

const int step71_factor226_height = 7;
const int step71_factor226_width = 6;
int step71_factor226_ridx[] = {6, 7, 8, 9, 10, 11, 12, };
float step71_factor226_data[42] = {0};

const int step71_factor226_num_blks = 1;
int step71_factor226_A_blk_start[] = {0, };
int step71_factor226_B_blk_start[] = {6, };
int step71_factor226_blk_width[] = {6, };

const int step71_factor227_height = 13;
const int step71_factor227_width = 6;
int step71_factor227_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, };
float step71_factor227_data[78] = {0};

const int step71_factor227_num_blks = 1;
int step71_factor227_A_blk_start[] = {0, };
int step71_factor227_B_blk_start[] = {0, };
int step71_factor227_blk_width[] = {12, };

const int step71_node14_num_factors = 2;
const int step71_node14_relin_cost = 60000;
const bool step71_node14_marked = false;
const bool step71_node14_fixed = true;
int step71_node14_factor_height[] = {step71_factor224_height, step71_factor225_height, };
int step71_node14_factor_width[] = {step71_factor224_width, step71_factor225_width, };
int* step71_node14_factor_ridx[] = {step71_factor224_ridx, step71_factor225_ridx, };
float* step71_node14_factor_data[] = {step71_factor224_data, step71_factor225_data, };
int step71_node14_factor_num_blks[] = {step71_factor224_num_blks, step71_factor225_num_blks, };
int* step71_node14_factor_A_blk_start[] = {step71_factor224_A_blk_start, step71_factor225_A_blk_start, };
int* step71_node14_factor_B_blk_start[] = {step71_factor224_B_blk_start, step71_factor225_B_blk_start, };
int* step71_node14_factor_blk_width[] = {step71_factor224_blk_width, step71_factor225_blk_width, };
const int step71_node14_parent = 15;
const int step71_node14_height = 31;
const int step71_node14_width = 24;
float step71_node14_data[744] = {0};
const int step71_node14_num_blks = 1;
int step71_node14_A_blk_start[] = {0, };
int step71_node14_B_blk_start[] = {0, };
int step71_node14_blk_width[] = {6, };


const int step71_node15_num_factors = 3;
const int step71_node15_relin_cost = 90000;
const bool step71_node15_marked = true;
const bool step71_node15_fixed = false;
int step71_node15_factor_height[] = {step71_factor223_height, step71_factor226_height, step71_factor227_height, };
int step71_node15_factor_width[] = {step71_factor223_width, step71_factor226_width, step71_factor227_width, };
int* step71_node15_factor_ridx[] = {step71_factor223_ridx, step71_factor226_ridx, step71_factor227_ridx, };
float* step71_node15_factor_data[] = {step71_factor223_data, step71_factor226_data, step71_factor227_data, };
int step71_node15_factor_num_blks[] = {step71_factor223_num_blks, step71_factor226_num_blks, step71_factor227_num_blks, };
int* step71_node15_factor_A_blk_start[] = {step71_factor223_A_blk_start, step71_factor226_A_blk_start, step71_factor227_A_blk_start, };
int* step71_node15_factor_B_blk_start[] = {step71_factor223_B_blk_start, step71_factor226_B_blk_start, step71_factor227_B_blk_start, };
int* step71_node15_factor_blk_width[] = {step71_factor223_blk_width, step71_factor226_blk_width, step71_factor227_blk_width, };
const int step71_node15_parent = 16;
const int step71_node15_height = 13;
const int step71_node15_width = 12;
float step71_node15_data[156] = {0};
const int step71_node15_num_blks = 0;
int step71_node15_A_blk_start[] = {};
int step71_node15_B_blk_start[] = {};
int step71_node15_blk_width[] = {};


const int step71_node16_num_factors = 0;
const int step71_node16_relin_cost = 0;
const bool step71_node16_marked = true;
const bool step71_node16_fixed = false;
int step71_node16_factor_height[] = {};
int step71_node16_factor_width[] = {};
int* step71_node16_factor_ridx[] = {};
float* step71_node16_factor_data[] = {};
int step71_node16_factor_num_blks[] = {};
int* step71_node16_factor_A_blk_start[] = {};
int* step71_node16_factor_B_blk_start[] = {};
int* step71_node16_factor_blk_width[] = {};
const int step71_node16_parent = -1;
const int step71_node16_height = 1;
const int step71_node16_width = 1;
float step71_node16_data[1] = {0};
const int step71_node16_num_blks = 0;
int step71_node16_A_blk_start[] = {};
int step71_node16_B_blk_start[] = {};
int step71_node16_blk_width[] = {};


int step71_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 432, };
int step71_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 432, };
int step71_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 432, };
int step71_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 246, 247, 248, 249, 250, 251, 432, };
int step71_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 276, 277, 278, 279, 280, 281, 432, };
int step71_node5_ridx[] = {
150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 240, 241, 242, 243, 244, 245, 270, 271, 272, 273, 274, 275, 432, };
int step71_node6_ridx[] = {
174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 240, 241, 242, 243, 244, 245, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 432, };
int step71_node7_ridx[] = {
198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 432, };
int step71_node8_ridx[] = {
222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 432, };
int step71_node9_ridx[] = {
264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 396, 397, 398, 399, 400, 401, 432, };
int step71_node10_ridx[] = {
288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 396, 397, 398, 399, 400, 401, 432, };
int step71_node11_ridx[] = {
312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 384, 385, 386, 387, 388, 389, 396, 397, 398, 399, 400, 401, 432, };
int step71_node12_ridx[] = {
342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 384, 385, 386, 387, 388, 389, 396, 397, 398, 399, 400, 401, 432, };
int step71_node13_ridx[] = {
366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 432, };
int step71_node14_ridx[] = {
396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 432, };
int step71_node15_ridx[] = {
420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, };
int step71_node16_ridx[] = {
432, };
const int step71_nnodes = 17;
bool step71_node_marked[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, step71_node14_marked, step71_node15_marked, step71_node16_marked, };
bool step71_node_fixed[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, step71_node14_fixed, step71_node15_fixed, step71_node16_fixed, };
int step71_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_num_factors, step71_node15_num_factors, step71_node16_num_factors, };
int step71_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_relin_cost, step71_node15_relin_cost, step71_node16_relin_cost, };
int* step71_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_factor_height, step71_node15_factor_height, step71_node16_factor_height, };
int* step71_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_factor_width, step71_node15_factor_width, step71_node16_factor_width, };
int** step71_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_factor_ridx, step71_node15_factor_ridx, step71_node16_factor_ridx, };
float** step71_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_factor_data, step71_node15_factor_data, step71_node16_factor_data, };
int* step71_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_factor_num_blks, step71_node15_factor_num_blks, step71_node16_factor_num_blks, };
int** step71_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_factor_A_blk_start, step71_node15_factor_A_blk_start, step71_node16_factor_A_blk_start, };
int** step71_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_factor_B_blk_start, step71_node15_factor_B_blk_start, step71_node16_factor_B_blk_start, };
int** step71_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_factor_blk_width, step71_node15_factor_blk_width, step71_node16_factor_blk_width, };
int step71_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_parent, step71_node15_parent, step71_node16_parent, };
int step71_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_height, step71_node15_height, step71_node16_height, };
int step71_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_width, step71_node15_width, step71_node16_width, };
float* step71_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_data, step71_node15_data, step71_node16_data, };
int step71_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_num_blks, step71_node15_num_blks, step71_node16_num_blks, };
int* step71_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_A_blk_start, step71_node15_A_blk_start, step71_node16_A_blk_start, };
int* step71_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_B_blk_start, step71_node15_B_blk_start, step71_node16_B_blk_start, };
int* step71_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step71_node14_blk_width, step71_node15_blk_width, step71_node16_blk_width, };
int* step71_node_ridx[] = {step71_node0_ridx, step71_node1_ridx, step71_node2_ridx, step71_node3_ridx, step71_node4_ridx, step71_node5_ridx, step71_node6_ridx, step71_node7_ridx, step71_node8_ridx, step71_node9_ridx, step71_node10_ridx, step71_node11_ridx, step71_node12_ridx, step71_node13_ridx, step71_node14_ridx, step71_node15_ridx, step71_node16_ridx, };


float step71_x_data[433] = {};
const int step71_workspace_needed = 4824;

