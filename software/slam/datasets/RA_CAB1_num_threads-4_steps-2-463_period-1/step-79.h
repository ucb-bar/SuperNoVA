#pragma once

const bool step79_is_reconstruct = true;

const int step79_num_threads = 1;

const uint64_t step79_scaled_relin_cost = 0;

const bool step79_run_model = false;

const int step79_factor243_height = 7;
const int step79_factor243_width = 6;
int step79_factor243_ridx[] = {6, 7, 8, 9, 10, 11, 18, };
float step79_factor243_data[42] = {0};

const int step79_factor243_num_blks = 1;
int step79_factor243_A_blk_start[] = {0, };
int step79_factor243_B_blk_start[] = {6, };
int step79_factor243_blk_width[] = {6, };

const int step79_factor244_height = 13;
const int step79_factor244_width = 6;
int step79_factor244_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 18, };
float step79_factor244_data[78] = {0};

const int step79_factor244_num_blks = 1;
int step79_factor244_A_blk_start[] = {0, };
int step79_factor244_B_blk_start[] = {0, };
int step79_factor244_blk_width[] = {12, };

const int step79_factor245_height = 7;
const int step79_factor245_width = 6;
int step79_factor245_ridx[] = {12, 13, 14, 15, 16, 17, 18, };
float step79_factor245_data[42] = {0};

const int step79_factor245_num_blks = 1;
int step79_factor245_A_blk_start[] = {0, };
int step79_factor245_B_blk_start[] = {12, };
int step79_factor245_blk_width[] = {6, };

const int step79_factor246_height = 13;
const int step79_factor246_width = 6;
int step79_factor246_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, };
float step79_factor246_data[78] = {0};

const int step79_factor246_num_blks = 1;
int step79_factor246_A_blk_start[] = {0, };
int step79_factor246_B_blk_start[] = {6, };
int step79_factor246_blk_width[] = {12, };

const int step79_factor239_height = 7;
const int step79_factor239_width = 6;
int step79_factor239_ridx[] = {0, 1, 2, 3, 4, 5, 18, };
float step79_factor239_data[42] = {0};

const int step79_factor239_num_blks = 1;
int step79_factor239_A_blk_start[] = {0, };
int step79_factor239_B_blk_start[] = {0, };
int step79_factor239_blk_width[] = {6, };

const int step79_factor240_height = 13;
const int step79_factor240_width = 6;
int step79_factor240_ridx[] = {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, };
float step79_factor240_data[78] = {0};

const int step79_factor240_num_blks = 1;
int step79_factor240_A_blk_start[] = {0, };
int step79_factor240_B_blk_start[] = {24, };
int step79_factor240_blk_width[] = {12, };

const int step79_factor241_height = 13;
const int step79_factor241_width = 6;
int step79_factor241_ridx[] = {12, 13, 14, 15, 16, 17, 30, 31, 32, 33, 34, 35, 36, };
float step79_factor241_data[78] = {0};

const int step79_factor241_num_blks = 2;
int step79_factor241_A_blk_start[] = {0, 6, };
int step79_factor241_B_blk_start[] = {12, 30, };
int step79_factor241_blk_width[] = {6, 6, };

const int step79_factor242_height = 13;
const int step79_factor242_width = 6;
int step79_factor242_ridx[] = {18, 19, 20, 21, 22, 23, 30, 31, 32, 33, 34, 35, 36, };
float step79_factor242_data[78] = {0};

const int step79_factor242_num_blks = 2;
int step79_factor242_A_blk_start[] = {0, 6, };
int step79_factor242_B_blk_start[] = {18, 30, };
int step79_factor242_blk_width[] = {6, 6, };

const int step79_node15_num_factors = 3;
const int step79_node15_relin_cost = 0;
const int step79_node15_sym_cost = 20000;
const bool step79_node15_marked = false;
const bool step79_node15_fixed = true;
int step79_node15_factor_height[] = {step79_factor240_height, step79_factor241_height, step79_factor242_height, };
int step79_node15_factor_width[] = {step79_factor240_width, step79_factor241_width, step79_factor242_width, };
int* step79_node15_factor_ridx[] = {step79_factor240_ridx, step79_factor241_ridx, step79_factor242_ridx, };
float* step79_node15_factor_data[] = {step79_factor240_data, step79_factor241_data, step79_factor242_data, };
int step79_node15_factor_num_blks[] = {step79_factor240_num_blks, step79_factor241_num_blks, step79_factor242_num_blks, };
int* step79_node15_factor_A_blk_start[] = {step79_factor240_A_blk_start, step79_factor241_A_blk_start, step79_factor242_A_blk_start, };
int* step79_node15_factor_B_blk_start[] = {step79_factor240_B_blk_start, step79_factor241_B_blk_start, step79_factor242_B_blk_start, };
int* step79_node15_factor_blk_width[] = {step79_factor240_blk_width, step79_factor241_blk_width, step79_factor242_blk_width, };
const int step79_node15_parent = 16;
const int step79_node15_height = 37;
const int step79_node15_width = 30;
float step79_node15_data[1110] = {0};
const int step79_node15_num_blks = 1;
int step79_node15_A_blk_start[] = {0, };
int step79_node15_B_blk_start[] = {0, };
int step79_node15_blk_width[] = {6, };


const int step79_node16_num_factors = 5;
const int step79_node16_relin_cost = 0;
const int step79_node16_sym_cost = 12000;
const bool step79_node16_marked = true;
const bool step79_node16_fixed = false;
int step79_node16_factor_height[] = {step79_factor239_height, step79_factor243_height, step79_factor244_height, step79_factor245_height, step79_factor246_height, };
int step79_node16_factor_width[] = {step79_factor239_width, step79_factor243_width, step79_factor244_width, step79_factor245_width, step79_factor246_width, };
int* step79_node16_factor_ridx[] = {step79_factor239_ridx, step79_factor243_ridx, step79_factor244_ridx, step79_factor245_ridx, step79_factor246_ridx, };
float* step79_node16_factor_data[] = {step79_factor239_data, step79_factor243_data, step79_factor244_data, step79_factor245_data, step79_factor246_data, };
int step79_node16_factor_num_blks[] = {step79_factor239_num_blks, step79_factor243_num_blks, step79_factor244_num_blks, step79_factor245_num_blks, step79_factor246_num_blks, };
int* step79_node16_factor_A_blk_start[] = {step79_factor239_A_blk_start, step79_factor243_A_blk_start, step79_factor244_A_blk_start, step79_factor245_A_blk_start, step79_factor246_A_blk_start, };
int* step79_node16_factor_B_blk_start[] = {step79_factor239_B_blk_start, step79_factor243_B_blk_start, step79_factor244_B_blk_start, step79_factor245_B_blk_start, step79_factor246_B_blk_start, };
int* step79_node16_factor_blk_width[] = {step79_factor239_blk_width, step79_factor243_blk_width, step79_factor244_blk_width, step79_factor245_blk_width, step79_factor246_blk_width, };
const int step79_node16_parent = 17;
const int step79_node16_height = 19;
const int step79_node16_width = 18;
float step79_node16_data[342] = {0};
const int step79_node16_num_blks = 0;
int step79_node16_A_blk_start[] = {};
int step79_node16_B_blk_start[] = {};
int step79_node16_blk_width[] = {};


const int step79_node17_num_factors = 0;
const int step79_node17_relin_cost = 0;
const int step79_node17_sym_cost = 4000;
const bool step79_node17_marked = true;
const bool step79_node17_fixed = false;
int step79_node17_factor_height[] = {};
int step79_node17_factor_width[] = {};
int* step79_node17_factor_ridx[] = {};
float* step79_node17_factor_data[] = {};
int step79_node17_factor_num_blks[] = {};
int* step79_node17_factor_A_blk_start[] = {};
int* step79_node17_factor_B_blk_start[] = {};
int* step79_node17_factor_blk_width[] = {};
const int step79_node17_parent = -1;
const int step79_node17_height = 1;
const int step79_node17_width = 1;
float step79_node17_data[1] = {0};
const int step79_node17_num_blks = 0;
int step79_node17_A_blk_start[] = {};
int step79_node17_B_blk_start[] = {};
int step79_node17_blk_width[] = {};


int step79_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 480, };
int step79_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 480, };
int step79_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 108, 109, 110, 111, 112, 113, 480, };
int step79_node3_ridx[] = {
90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 294, 295, 296, 297, 298, 299, 318, 319, 320, 321, 322, 323, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 480, };
int step79_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 348, 349, 350, 351, 352, 353, 384, 385, 386, 387, 388, 389, 480, };
int step79_node5_ridx[] = {
138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 270, 271, 272, 273, 274, 275, 288, 289, 290, 291, 292, 293, 372, 373, 374, 375, 376, 377, 384, 385, 386, 387, 388, 389, 480, };
int step79_node6_ridx[] = {
162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 480, };
int step79_node7_ridx[] = {
198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 354, 355, 356, 357, 358, 359, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 480, };
int step79_node8_ridx[] = {
228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 378, 379, 380, 381, 382, 383, 480, };
int step79_node9_ridx[] = {
252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 372, 373, 374, 375, 376, 377, 384, 385, 386, 387, 388, 389, 480, };
int step79_node10_ridx[] = {
276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 372, 373, 374, 375, 376, 377, 384, 385, 386, 387, 388, 389, 480, };
int step79_node11_ridx[] = {
300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 480, };
int step79_node12_ridx[] = {
354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 480, };
int step79_node13_ridx[] = {
384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 480, };
int step79_node14_ridx[] = {
408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 480, };
int step79_node15_ridx[] = {
432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 480, };
int step79_node16_ridx[] = {
462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, };
int step79_node17_ridx[] = {
480, };
const int step79_nnodes = 18;
bool step79_node_marked[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, step79_node15_marked, step79_node16_marked, step79_node17_marked, };
bool step79_node_fixed[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, step79_node15_fixed, step79_node16_fixed, step79_node17_fixed, };
int step79_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_num_factors, step79_node16_num_factors, step79_node17_num_factors, };
int step79_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_relin_cost, step79_node16_relin_cost, step79_node17_relin_cost, };
int step79_node_sym_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_sym_cost, step79_node16_sym_cost, step79_node17_sym_cost, };
int* step79_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_factor_height, step79_node16_factor_height, step79_node17_factor_height, };
int* step79_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_factor_width, step79_node16_factor_width, step79_node17_factor_width, };
int** step79_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_factor_ridx, step79_node16_factor_ridx, step79_node17_factor_ridx, };
float** step79_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_factor_data, step79_node16_factor_data, step79_node17_factor_data, };
int* step79_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_factor_num_blks, step79_node16_factor_num_blks, step79_node17_factor_num_blks, };
int** step79_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_factor_A_blk_start, step79_node16_factor_A_blk_start, step79_node17_factor_A_blk_start, };
int** step79_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_factor_B_blk_start, step79_node16_factor_B_blk_start, step79_node17_factor_B_blk_start, };
int** step79_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_factor_blk_width, step79_node16_factor_blk_width, step79_node17_factor_blk_width, };
int step79_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_parent, step79_node16_parent, step79_node17_parent, };
int step79_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_height, step79_node16_height, step79_node17_height, };
int step79_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_width, step79_node16_width, step79_node17_width, };
float* step79_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_data, step79_node16_data, step79_node17_data, };
int step79_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_num_blks, step79_node16_num_blks, step79_node17_num_blks, };
int* step79_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_A_blk_start, step79_node16_A_blk_start, step79_node17_A_blk_start, };
int* step79_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_B_blk_start, step79_node16_B_blk_start, step79_node17_B_blk_start, };
int* step79_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step79_node15_blk_width, step79_node16_blk_width, step79_node17_blk_width, };
int* step79_node_ridx[] = {step79_node0_ridx, step79_node1_ridx, step79_node2_ridx, step79_node3_ridx, step79_node4_ridx, step79_node5_ridx, step79_node6_ridx, step79_node7_ridx, step79_node8_ridx, step79_node9_ridx, step79_node10_ridx, step79_node11_ridx, step79_node12_ridx, step79_node13_ridx, step79_node14_ridx, step79_node15_ridx, step79_node16_ridx, step79_node17_ridx, };


float step79_x_data[481] = {};
const int step79_workspace_needed = 7224;
