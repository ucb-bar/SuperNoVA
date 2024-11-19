#pragma once

const bool step67_is_reconstruct = true;

const int step67_num_threads = 1;

const uint64_t step67_scaled_relin_cost = 0;

const bool step67_run_model = false;

const int step67_factor214_height = 7;
const int step67_factor214_width = 6;
int step67_factor214_ridx[] = {0, 1, 2, 3, 4, 5, 12, };
float step67_factor214_data[42] = {0};

const int step67_factor214_num_blks = 1;
int step67_factor214_A_blk_start[] = {0, };
int step67_factor214_B_blk_start[] = {0, };
int step67_factor214_blk_width[] = {6, };

const int step67_factor215_height = 13;
const int step67_factor215_width = 6;
int step67_factor215_ridx[] = {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, };
float step67_factor215_data[78] = {0};

const int step67_factor215_num_blks = 1;
int step67_factor215_A_blk_start[] = {0, };
int step67_factor215_B_blk_start[] = {24, };
int step67_factor215_blk_width[] = {12, };

const int step67_factor216_height = 13;
const int step67_factor216_width = 6;
int step67_factor216_ridx[] = {6, 7, 8, 9, 10, 11, 48, 49, 50, 51, 52, 53, 54, };
float step67_factor216_data[78] = {0};

const int step67_factor216_num_blks = 2;
int step67_factor216_A_blk_start[] = {0, 6, };
int step67_factor216_B_blk_start[] = {6, 48, };
int step67_factor216_blk_width[] = {6, 6, };

const int step67_factor217_height = 7;
const int step67_factor217_width = 6;
int step67_factor217_ridx[] = {6, 7, 8, 9, 10, 11, 12, };
float step67_factor217_data[42] = {0};

const int step67_factor217_num_blks = 1;
int step67_factor217_A_blk_start[] = {0, };
int step67_factor217_B_blk_start[] = {6, };
int step67_factor217_blk_width[] = {6, };

const int step67_factor218_height = 13;
const int step67_factor218_width = 6;
int step67_factor218_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, };
float step67_factor218_data[78] = {0};

const int step67_factor218_num_blks = 1;
int step67_factor218_A_blk_start[] = {0, };
int step67_factor218_B_blk_start[] = {0, };
int step67_factor218_blk_width[] = {12, };

const int step67_node9_num_factors = 1;
const int step67_node9_relin_cost = 30000;
const bool step67_node9_marked = false;
const bool step67_node9_fixed = true;
int step67_node9_factor_height[] = {step67_factor216_height, };
int step67_node9_factor_width[] = {step67_factor216_width, };
int* step67_node9_factor_ridx[] = {step67_factor216_ridx, };
float* step67_node9_factor_data[] = {step67_factor216_data, };
int step67_node9_factor_num_blks[] = {step67_factor216_num_blks, };
int* step67_node9_factor_A_blk_start[] = {step67_factor216_A_blk_start, };
int* step67_node9_factor_B_blk_start[] = {step67_factor216_B_blk_start, };
int* step67_node9_factor_blk_width[] = {step67_factor216_blk_width, };
const int step67_node9_parent = 10;
const int step67_node9_height = 55;
const int step67_node9_width = 24;
float step67_node9_data[1320] = {0};
const int step67_node9_num_blks = 3;
int step67_node9_A_blk_start[] = {0, 12, 24, };
int step67_node9_B_blk_start[] = {0, 18, 42, };
int step67_node9_blk_width[] = {12, 12, 6, };


const int step67_node10_num_factors = 0;
const int step67_node10_relin_cost = 0;
const bool step67_node10_marked = false;
const bool step67_node10_fixed = true;
int step67_node10_factor_height[] = {};
int step67_node10_factor_width[] = {};
int* step67_node10_factor_ridx[] = {};
float* step67_node10_factor_data[] = {};
int step67_node10_factor_num_blks[] = {};
int* step67_node10_factor_A_blk_start[] = {};
int* step67_node10_factor_B_blk_start[] = {};
int* step67_node10_factor_blk_width[] = {};
const int step67_node10_parent = 11;
const int step67_node10_height = 49;
const int step67_node10_width = 24;
float step67_node10_data[1176] = {0};
const int step67_node10_num_blks = 3;
int step67_node10_A_blk_start[] = {0, 6, 18, };
int step67_node10_B_blk_start[] = {0, 36, 54, };
int step67_node10_blk_width[] = {6, 12, 6, };


const int step67_node11_num_factors = 0;
const int step67_node11_relin_cost = 0;
const bool step67_node11_marked = false;
const bool step67_node11_fixed = true;
int step67_node11_factor_height[] = {};
int step67_node11_factor_width[] = {};
int* step67_node11_factor_ridx[] = {};
float* step67_node11_factor_data[] = {};
int step67_node11_factor_num_blks[] = {};
int* step67_node11_factor_A_blk_start[] = {};
int* step67_node11_factor_B_blk_start[] = {};
int* step67_node11_factor_blk_width[] = {};
const int step67_node11_parent = 12;
const int step67_node11_height = 61;
const int step67_node11_width = 30;
float step67_node11_data[1830] = {0};
const int step67_node11_num_blks = 3;
int step67_node11_A_blk_start[] = {0, 6, 18, };
int step67_node11_B_blk_start[] = {0, 12, 30, };
int step67_node11_blk_width[] = {6, 12, 12, };


const int step67_node12_num_factors = 0;
const int step67_node12_relin_cost = 0;
const bool step67_node12_marked = false;
const bool step67_node12_fixed = true;
int step67_node12_factor_height[] = {};
int step67_node12_factor_width[] = {};
int* step67_node12_factor_ridx[] = {};
float* step67_node12_factor_data[] = {};
int step67_node12_factor_num_blks[] = {};
int* step67_node12_factor_A_blk_start[] = {};
int* step67_node12_factor_B_blk_start[] = {};
int* step67_node12_factor_blk_width[] = {};
const int step67_node12_parent = 13;
const int step67_node12_height = 43;
const int step67_node12_width = 24;
float step67_node12_data[1032] = {0};
const int step67_node12_num_blks = 3;
int step67_node12_A_blk_start[] = {0, 6, 12, };
int step67_node12_B_blk_start[] = {0, 18, 30, };
int step67_node12_blk_width[] = {6, 6, 6, };


const int step67_node13_num_factors = 1;
const int step67_node13_relin_cost = 30000;
const bool step67_node13_marked = false;
const bool step67_node13_fixed = true;
int step67_node13_factor_height[] = {step67_factor215_height, };
int step67_node13_factor_width[] = {step67_factor215_width, };
int* step67_node13_factor_ridx[] = {step67_factor215_ridx, };
float* step67_node13_factor_data[] = {step67_factor215_data, };
int step67_node13_factor_num_blks[] = {step67_factor215_num_blks, };
int* step67_node13_factor_A_blk_start[] = {step67_factor215_A_blk_start, };
int* step67_node13_factor_B_blk_start[] = {step67_factor215_B_blk_start, };
int* step67_node13_factor_blk_width[] = {step67_factor215_blk_width, };
const int step67_node13_parent = 14;
const int step67_node13_height = 37;
const int step67_node13_width = 30;
float step67_node13_data[1110] = {0};
const int step67_node13_num_blks = 1;
int step67_node13_A_blk_start[] = {0, };
int step67_node13_B_blk_start[] = {0, };
int step67_node13_blk_width[] = {6, };


const int step67_node14_num_factors = 3;
const int step67_node14_relin_cost = 90000;
const bool step67_node14_marked = true;
const bool step67_node14_fixed = false;
int step67_node14_factor_height[] = {step67_factor214_height, step67_factor217_height, step67_factor218_height, };
int step67_node14_factor_width[] = {step67_factor214_width, step67_factor217_width, step67_factor218_width, };
int* step67_node14_factor_ridx[] = {step67_factor214_ridx, step67_factor217_ridx, step67_factor218_ridx, };
float* step67_node14_factor_data[] = {step67_factor214_data, step67_factor217_data, step67_factor218_data, };
int step67_node14_factor_num_blks[] = {step67_factor214_num_blks, step67_factor217_num_blks, step67_factor218_num_blks, };
int* step67_node14_factor_A_blk_start[] = {step67_factor214_A_blk_start, step67_factor217_A_blk_start, step67_factor218_A_blk_start, };
int* step67_node14_factor_B_blk_start[] = {step67_factor214_B_blk_start, step67_factor217_B_blk_start, step67_factor218_B_blk_start, };
int* step67_node14_factor_blk_width[] = {step67_factor214_blk_width, step67_factor217_blk_width, step67_factor218_blk_width, };
const int step67_node14_parent = 15;
const int step67_node14_height = 13;
const int step67_node14_width = 12;
float step67_node14_data[156] = {0};
const int step67_node14_num_blks = 0;
int step67_node14_A_blk_start[] = {};
int step67_node14_B_blk_start[] = {};
int step67_node14_blk_width[] = {};


const int step67_node15_num_factors = 0;
const int step67_node15_relin_cost = 0;
const bool step67_node15_marked = true;
const bool step67_node15_fixed = false;
int step67_node15_factor_height[] = {};
int step67_node15_factor_width[] = {};
int* step67_node15_factor_ridx[] = {};
float* step67_node15_factor_data[] = {};
int step67_node15_factor_num_blks[] = {};
int* step67_node15_factor_A_blk_start[] = {};
int* step67_node15_factor_B_blk_start[] = {};
int* step67_node15_factor_blk_width[] = {};
const int step67_node15_parent = -1;
const int step67_node15_height = 1;
const int step67_node15_width = 1;
float step67_node15_data[1] = {0};
const int step67_node15_num_blks = 0;
int step67_node15_A_blk_start[] = {};
int step67_node15_B_blk_start[] = {};
int step67_node15_blk_width[] = {};


int step67_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 408, };
int step67_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 408, };
int step67_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 408, };
int step67_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 246, 247, 248, 249, 250, 251, 408, };
int step67_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 276, 277, 278, 279, 280, 281, 408, };
int step67_node5_ridx[] = {
150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 240, 241, 242, 243, 244, 245, 270, 271, 272, 273, 274, 275, 408, };
int step67_node6_ridx[] = {
174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 240, 241, 242, 243, 244, 245, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 408, };
int step67_node7_ridx[] = {
198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 408, };
int step67_node8_ridx[] = {
222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 408, };
int step67_node9_ridx[] = {
264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 396, 397, 398, 399, 400, 401, 408, };
int step67_node10_ridx[] = {
288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 396, 397, 398, 399, 400, 401, 408, };
int step67_node11_ridx[] = {
312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 384, 385, 386, 387, 388, 389, 396, 397, 398, 399, 400, 401, 408, };
int step67_node12_ridx[] = {
342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 384, 385, 386, 387, 388, 389, 396, 397, 398, 399, 400, 401, 408, };
int step67_node13_ridx[] = {
366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 408, };
int step67_node14_ridx[] = {
396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, };
int step67_node15_ridx[] = {
408, };
const int step67_nnodes = 16;
bool step67_node_marked[] = {false, false, false, false, false, false, false, false, false, step67_node9_marked, step67_node10_marked, step67_node11_marked, step67_node12_marked, step67_node13_marked, step67_node14_marked, step67_node15_marked, };
bool step67_node_fixed[] = {false, false, false, false, false, false, false, false, false, step67_node9_fixed, step67_node10_fixed, step67_node11_fixed, step67_node12_fixed, step67_node13_fixed, step67_node14_fixed, step67_node15_fixed, };
int step67_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_num_factors, step67_node10_num_factors, step67_node11_num_factors, step67_node12_num_factors, step67_node13_num_factors, step67_node14_num_factors, step67_node15_num_factors, };
int step67_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_relin_cost, step67_node10_relin_cost, step67_node11_relin_cost, step67_node12_relin_cost, step67_node13_relin_cost, step67_node14_relin_cost, step67_node15_relin_cost, };
int* step67_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_factor_height, step67_node10_factor_height, step67_node11_factor_height, step67_node12_factor_height, step67_node13_factor_height, step67_node14_factor_height, step67_node15_factor_height, };
int* step67_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_factor_width, step67_node10_factor_width, step67_node11_factor_width, step67_node12_factor_width, step67_node13_factor_width, step67_node14_factor_width, step67_node15_factor_width, };
int** step67_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_factor_ridx, step67_node10_factor_ridx, step67_node11_factor_ridx, step67_node12_factor_ridx, step67_node13_factor_ridx, step67_node14_factor_ridx, step67_node15_factor_ridx, };
float** step67_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_factor_data, step67_node10_factor_data, step67_node11_factor_data, step67_node12_factor_data, step67_node13_factor_data, step67_node14_factor_data, step67_node15_factor_data, };
int* step67_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_factor_num_blks, step67_node10_factor_num_blks, step67_node11_factor_num_blks, step67_node12_factor_num_blks, step67_node13_factor_num_blks, step67_node14_factor_num_blks, step67_node15_factor_num_blks, };
int** step67_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_factor_A_blk_start, step67_node10_factor_A_blk_start, step67_node11_factor_A_blk_start, step67_node12_factor_A_blk_start, step67_node13_factor_A_blk_start, step67_node14_factor_A_blk_start, step67_node15_factor_A_blk_start, };
int** step67_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_factor_B_blk_start, step67_node10_factor_B_blk_start, step67_node11_factor_B_blk_start, step67_node12_factor_B_blk_start, step67_node13_factor_B_blk_start, step67_node14_factor_B_blk_start, step67_node15_factor_B_blk_start, };
int** step67_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_factor_blk_width, step67_node10_factor_blk_width, step67_node11_factor_blk_width, step67_node12_factor_blk_width, step67_node13_factor_blk_width, step67_node14_factor_blk_width, step67_node15_factor_blk_width, };
int step67_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_parent, step67_node10_parent, step67_node11_parent, step67_node12_parent, step67_node13_parent, step67_node14_parent, step67_node15_parent, };
int step67_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_height, step67_node10_height, step67_node11_height, step67_node12_height, step67_node13_height, step67_node14_height, step67_node15_height, };
int step67_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_width, step67_node10_width, step67_node11_width, step67_node12_width, step67_node13_width, step67_node14_width, step67_node15_width, };
float* step67_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_data, step67_node10_data, step67_node11_data, step67_node12_data, step67_node13_data, step67_node14_data, step67_node15_data, };
int step67_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_num_blks, step67_node10_num_blks, step67_node11_num_blks, step67_node12_num_blks, step67_node13_num_blks, step67_node14_num_blks, step67_node15_num_blks, };
int* step67_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_A_blk_start, step67_node10_A_blk_start, step67_node11_A_blk_start, step67_node12_A_blk_start, step67_node13_A_blk_start, step67_node14_A_blk_start, step67_node15_A_blk_start, };
int* step67_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_B_blk_start, step67_node10_B_blk_start, step67_node11_B_blk_start, step67_node12_B_blk_start, step67_node13_B_blk_start, step67_node14_B_blk_start, step67_node15_B_blk_start, };
int* step67_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step67_node9_blk_width, step67_node10_blk_width, step67_node11_blk_width, step67_node12_blk_width, step67_node13_blk_width, step67_node14_blk_width, step67_node15_blk_width, };
int* step67_node_ridx[] = {step67_node0_ridx, step67_node1_ridx, step67_node2_ridx, step67_node3_ridx, step67_node4_ridx, step67_node5_ridx, step67_node6_ridx, step67_node7_ridx, step67_node8_ridx, step67_node9_ridx, step67_node10_ridx, step67_node11_ridx, step67_node12_ridx, step67_node13_ridx, step67_node14_ridx, step67_node15_ridx, };


float step67_x_data[409] = {};
const int step67_workspace_needed = 50840;

