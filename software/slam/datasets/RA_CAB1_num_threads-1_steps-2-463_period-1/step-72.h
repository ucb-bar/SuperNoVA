#pragma once

const bool step72_is_reconstruct = true;

const int step72_num_threads = 1;

const uint64_t step72_scaled_relin_cost = 0;

const bool step72_run_model = false;

const int step72_factor219_height = 7;
const int step72_factor219_width = 6;
int step72_factor219_ridx[] = {0, 1, 2, 3, 4, 5, 30, };
float step72_factor219_data[42] = {0};

const int step72_factor219_num_blks = 1;
int step72_factor219_A_blk_start[] = {0, };
int step72_factor219_B_blk_start[] = {0, };
int step72_factor219_blk_width[] = {6, };

const int step72_factor220_height = 13;
const int step72_factor220_width = 6;
int step72_factor220_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step72_factor220_data[78] = {0};

const int step72_factor220_num_blks = 1;
int step72_factor220_A_blk_start[] = {0, };
int step72_factor220_B_blk_start[] = {18, };
int step72_factor220_blk_width[] = {12, };

const int step72_factor221_height = 7;
const int step72_factor221_width = 6;
int step72_factor221_ridx[] = {6, 7, 8, 9, 10, 11, 30, };
float step72_factor221_data[42] = {0};

const int step72_factor221_num_blks = 1;
int step72_factor221_A_blk_start[] = {0, };
int step72_factor221_B_blk_start[] = {6, };
int step72_factor221_blk_width[] = {6, };

const int step72_factor222_height = 13;
const int step72_factor222_width = 6;
int step72_factor222_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 30, };
float step72_factor222_data[78] = {0};

const int step72_factor222_num_blks = 1;
int step72_factor222_A_blk_start[] = {0, };
int step72_factor222_B_blk_start[] = {0, };
int step72_factor222_blk_width[] = {12, };

const int step72_factor223_height = 7;
const int step72_factor223_width = 6;
int step72_factor223_ridx[] = {12, 13, 14, 15, 16, 17, 30, };
float step72_factor223_data[42] = {0};

const int step72_factor223_num_blks = 1;
int step72_factor223_A_blk_start[] = {0, };
int step72_factor223_B_blk_start[] = {12, };
int step72_factor223_blk_width[] = {6, };

const int step72_factor224_height = 13;
const int step72_factor224_width = 6;
int step72_factor224_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 30, };
float step72_factor224_data[78] = {0};

const int step72_factor224_num_blks = 1;
int step72_factor224_A_blk_start[] = {0, };
int step72_factor224_B_blk_start[] = {6, };
int step72_factor224_blk_width[] = {12, };

const int step72_factor225_height = 13;
const int step72_factor225_width = 6;
int step72_factor225_ridx[] = {0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 30, };
float step72_factor225_data[78] = {0};

const int step72_factor225_num_blks = 2;
int step72_factor225_A_blk_start[] = {0, 6, };
int step72_factor225_B_blk_start[] = {0, 12, };
int step72_factor225_blk_width[] = {6, 6, };

const int step72_factor226_height = 7;
const int step72_factor226_width = 6;
int step72_factor226_ridx[] = {18, 19, 20, 21, 22, 23, 30, };
float step72_factor226_data[42] = {0};

const int step72_factor226_num_blks = 1;
int step72_factor226_A_blk_start[] = {0, };
int step72_factor226_B_blk_start[] = {18, };
int step72_factor226_blk_width[] = {6, };

const int step72_factor227_height = 13;
const int step72_factor227_width = 6;
int step72_factor227_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 30, };
float step72_factor227_data[78] = {0};

const int step72_factor227_num_blks = 1;
int step72_factor227_A_blk_start[] = {0, };
int step72_factor227_B_blk_start[] = {12, };
int step72_factor227_blk_width[] = {12, };

const int step72_factor228_height = 7;
const int step72_factor228_width = 6;
int step72_factor228_ridx[] = {24, 25, 26, 27, 28, 29, 30, };
float step72_factor228_data[42] = {0};

const int step72_factor228_num_blks = 1;
int step72_factor228_A_blk_start[] = {0, };
int step72_factor228_B_blk_start[] = {24, };
int step72_factor228_blk_width[] = {6, };

const int step72_factor229_height = 13;
const int step72_factor229_width = 6;
int step72_factor229_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step72_factor229_data[78] = {0};

const int step72_factor229_num_blks = 1;
int step72_factor229_A_blk_start[] = {0, };
int step72_factor229_B_blk_start[] = {18, };
int step72_factor229_blk_width[] = {12, };

const int step72_node13_num_factors = 1;
const int step72_node13_relin_cost = 0;
const int step72_node13_sym_cost = 16000;
const bool step72_node13_marked = false;
const bool step72_node13_fixed = true;
int step72_node13_factor_height[] = {step72_factor220_height, };
int step72_node13_factor_width[] = {step72_factor220_width, };
int* step72_node13_factor_ridx[] = {step72_factor220_ridx, };
float* step72_node13_factor_data[] = {step72_factor220_data, };
int step72_node13_factor_num_blks[] = {step72_factor220_num_blks, };
int* step72_node13_factor_A_blk_start[] = {step72_factor220_A_blk_start, };
int* step72_node13_factor_B_blk_start[] = {step72_factor220_B_blk_start, };
int* step72_node13_factor_blk_width[] = {step72_factor220_blk_width, };
const int step72_node13_parent = 14;
const int step72_node13_height = 31;
const int step72_node13_width = 24;
float step72_node13_data[744] = {0};
const int step72_node13_num_blks = 1;
int step72_node13_A_blk_start[] = {0, };
int step72_node13_B_blk_start[] = {0, };
int step72_node13_blk_width[] = {6, };


const int step72_node14_num_factors = 10;
const int step72_node14_relin_cost = 0;
const int step72_node14_sym_cost = 20000;
const bool step72_node14_marked = true;
const bool step72_node14_fixed = false;
int step72_node14_factor_height[] = {step72_factor219_height, step72_factor221_height, step72_factor222_height, step72_factor223_height, step72_factor224_height, step72_factor225_height, step72_factor226_height, step72_factor227_height, step72_factor228_height, step72_factor229_height, };
int step72_node14_factor_width[] = {step72_factor219_width, step72_factor221_width, step72_factor222_width, step72_factor223_width, step72_factor224_width, step72_factor225_width, step72_factor226_width, step72_factor227_width, step72_factor228_width, step72_factor229_width, };
int* step72_node14_factor_ridx[] = {step72_factor219_ridx, step72_factor221_ridx, step72_factor222_ridx, step72_factor223_ridx, step72_factor224_ridx, step72_factor225_ridx, step72_factor226_ridx, step72_factor227_ridx, step72_factor228_ridx, step72_factor229_ridx, };
float* step72_node14_factor_data[] = {step72_factor219_data, step72_factor221_data, step72_factor222_data, step72_factor223_data, step72_factor224_data, step72_factor225_data, step72_factor226_data, step72_factor227_data, step72_factor228_data, step72_factor229_data, };
int step72_node14_factor_num_blks[] = {step72_factor219_num_blks, step72_factor221_num_blks, step72_factor222_num_blks, step72_factor223_num_blks, step72_factor224_num_blks, step72_factor225_num_blks, step72_factor226_num_blks, step72_factor227_num_blks, step72_factor228_num_blks, step72_factor229_num_blks, };
int* step72_node14_factor_A_blk_start[] = {step72_factor219_A_blk_start, step72_factor221_A_blk_start, step72_factor222_A_blk_start, step72_factor223_A_blk_start, step72_factor224_A_blk_start, step72_factor225_A_blk_start, step72_factor226_A_blk_start, step72_factor227_A_blk_start, step72_factor228_A_blk_start, step72_factor229_A_blk_start, };
int* step72_node14_factor_B_blk_start[] = {step72_factor219_B_blk_start, step72_factor221_B_blk_start, step72_factor222_B_blk_start, step72_factor223_B_blk_start, step72_factor224_B_blk_start, step72_factor225_B_blk_start, step72_factor226_B_blk_start, step72_factor227_B_blk_start, step72_factor228_B_blk_start, step72_factor229_B_blk_start, };
int* step72_node14_factor_blk_width[] = {step72_factor219_blk_width, step72_factor221_blk_width, step72_factor222_blk_width, step72_factor223_blk_width, step72_factor224_blk_width, step72_factor225_blk_width, step72_factor226_blk_width, step72_factor227_blk_width, step72_factor228_blk_width, step72_factor229_blk_width, };
const int step72_node14_parent = 15;
const int step72_node14_height = 31;
const int step72_node14_width = 30;
float step72_node14_data[930] = {0};
const int step72_node14_num_blks = 0;
int step72_node14_A_blk_start[] = {};
int step72_node14_B_blk_start[] = {};
int step72_node14_blk_width[] = {};


const int step72_node15_num_factors = 0;
const int step72_node15_relin_cost = 0;
const int step72_node15_sym_cost = 4000;
const bool step72_node15_marked = true;
const bool step72_node15_fixed = false;
int step72_node15_factor_height[] = {};
int step72_node15_factor_width[] = {};
int* step72_node15_factor_ridx[] = {};
float* step72_node15_factor_data[] = {};
int step72_node15_factor_num_blks[] = {};
int* step72_node15_factor_A_blk_start[] = {};
int* step72_node15_factor_B_blk_start[] = {};
int* step72_node15_factor_blk_width[] = {};
const int step72_node15_parent = -1;
const int step72_node15_height = 1;
const int step72_node15_width = 1;
float step72_node15_data[1] = {0};
const int step72_node15_num_blks = 0;
int step72_node15_A_blk_start[] = {};
int step72_node15_B_blk_start[] = {};
int step72_node15_blk_width[] = {};


int step72_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 438, };
int step72_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 438, };
int step72_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 108, 109, 110, 111, 112, 113, 438, };
int step72_node3_ridx[] = {
90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 294, 295, 296, 297, 298, 299, 318, 319, 320, 321, 322, 323, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 438, };
int step72_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 348, 349, 350, 351, 352, 353, 384, 385, 386, 387, 388, 389, 438, };
int step72_node5_ridx[] = {
138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 270, 271, 272, 273, 274, 275, 288, 289, 290, 291, 292, 293, 372, 373, 374, 375, 376, 377, 384, 385, 386, 387, 388, 389, 438, };
int step72_node6_ridx[] = {
162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 438, };
int step72_node7_ridx[] = {
198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 354, 355, 356, 357, 358, 359, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 438, };
int step72_node8_ridx[] = {
228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 378, 379, 380, 381, 382, 383, 438, };
int step72_node9_ridx[] = {
252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 372, 373, 374, 375, 376, 377, 384, 385, 386, 387, 388, 389, 438, };
int step72_node10_ridx[] = {
276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 372, 373, 374, 375, 376, 377, 384, 385, 386, 387, 388, 389, 438, };
int step72_node11_ridx[] = {
300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 438, };
int step72_node12_ridx[] = {
354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 438, };
int step72_node13_ridx[] = {
384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 438, };
int step72_node14_ridx[] = {
408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, };
int step72_node15_ridx[] = {
438, };
const int step72_nnodes = 16;
bool step72_node_marked[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, step72_node13_marked, step72_node14_marked, step72_node15_marked, };
bool step72_node_fixed[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, step72_node13_fixed, step72_node14_fixed, step72_node15_fixed, };
int step72_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_num_factors, step72_node14_num_factors, step72_node15_num_factors, };
int step72_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_relin_cost, step72_node14_relin_cost, step72_node15_relin_cost, };
int step72_node_sym_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_sym_cost, step72_node14_sym_cost, step72_node15_sym_cost, };
int* step72_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_factor_height, step72_node14_factor_height, step72_node15_factor_height, };
int* step72_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_factor_width, step72_node14_factor_width, step72_node15_factor_width, };
int** step72_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_factor_ridx, step72_node14_factor_ridx, step72_node15_factor_ridx, };
float** step72_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_factor_data, step72_node14_factor_data, step72_node15_factor_data, };
int* step72_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_factor_num_blks, step72_node14_factor_num_blks, step72_node15_factor_num_blks, };
int** step72_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_factor_A_blk_start, step72_node14_factor_A_blk_start, step72_node15_factor_A_blk_start, };
int** step72_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_factor_B_blk_start, step72_node14_factor_B_blk_start, step72_node15_factor_B_blk_start, };
int** step72_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_factor_blk_width, step72_node14_factor_blk_width, step72_node15_factor_blk_width, };
int step72_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_parent, step72_node14_parent, step72_node15_parent, };
int step72_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_height, step72_node14_height, step72_node15_height, };
int step72_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_width, step72_node14_width, step72_node15_width, };
float* step72_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_data, step72_node14_data, step72_node15_data, };
int step72_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_num_blks, step72_node14_num_blks, step72_node15_num_blks, };
int* step72_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_A_blk_start, step72_node14_A_blk_start, step72_node15_A_blk_start, };
int* step72_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_B_blk_start, step72_node14_B_blk_start, step72_node15_B_blk_start, };
int* step72_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step72_node13_blk_width, step72_node14_blk_width, step72_node15_blk_width, };
int* step72_node_ridx[] = {step72_node0_ridx, step72_node1_ridx, step72_node2_ridx, step72_node3_ridx, step72_node4_ridx, step72_node5_ridx, step72_node6_ridx, step72_node7_ridx, step72_node8_ridx, step72_node9_ridx, step72_node10_ridx, step72_node11_ridx, step72_node12_ridx, step72_node13_ridx, step72_node14_ridx, step72_node15_ridx, };


float step72_x_data[439] = {};
const int step72_workspace_needed = 7992;

