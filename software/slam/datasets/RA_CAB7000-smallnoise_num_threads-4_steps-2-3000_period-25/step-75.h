#pragma once

const bool step75_is_reconstruct = true;

const int step75_num_threads = -1;

const uint64_t step75_scaled_relin_cost = -1;

const bool step75_run_model = false;

const int step75_factor188_height = 7;
const int step75_factor188_width = 6;
int step75_factor188_ridx[] = {0, 1, 2, 3, 4, 5, 12, };
float step75_factor188_data[42] = {0};

const int step75_factor188_num_blks = 1;
int step75_factor188_A_blk_start[] = {0, };
int step75_factor188_B_blk_start[] = {0, };
int step75_factor188_blk_width[] = {6, };

const int step75_factor189_height = 13;
const int step75_factor189_width = 6;
int step75_factor189_ridx[] = {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, };
float step75_factor189_data[78] = {0};

const int step75_factor189_num_blks = 1;
int step75_factor189_A_blk_start[] = {0, };
int step75_factor189_B_blk_start[] = {24, };
int step75_factor189_blk_width[] = {12, };

const int step75_factor190_height = 13;
const int step75_factor190_width = 6;
int step75_factor190_ridx[] = {6, 7, 8, 9, 10, 11, 30, 31, 32, 33, 34, 35, 36, };
float step75_factor190_data[78] = {0};

const int step75_factor190_num_blks = 2;
int step75_factor190_A_blk_start[] = {0, 6, };
int step75_factor190_B_blk_start[] = {6, 30, };
int step75_factor190_blk_width[] = {6, 6, };

const int step75_factor191_height = 7;
const int step75_factor191_width = 6;
int step75_factor191_ridx[] = {6, 7, 8, 9, 10, 11, 12, };
float step75_factor191_data[42] = {0};

const int step75_factor191_num_blks = 1;
int step75_factor191_A_blk_start[] = {0, };
int step75_factor191_B_blk_start[] = {6, };
int step75_factor191_blk_width[] = {6, };

const int step75_factor192_height = 13;
const int step75_factor192_width = 6;
int step75_factor192_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, };
float step75_factor192_data[78] = {0};

const int step75_factor192_num_blks = 1;
int step75_factor192_A_blk_start[] = {0, };
int step75_factor192_B_blk_start[] = {0, };
int step75_factor192_blk_width[] = {12, };

const int step75_node15_num_factors = 2;
const int step75_node15_relin_cost = 40000;
const int step75_node15_sym_cost = 10000;
const bool step75_node15_marked = false;
const bool step75_node15_fixed = true;
int step75_node15_factor_height[] = {step75_factor189_height, step75_factor190_height, };
int step75_node15_factor_width[] = {step75_factor189_width, step75_factor190_width, };
int* step75_node15_factor_ridx[] = {step75_factor189_ridx, step75_factor190_ridx, };
float* step75_node15_factor_data[] = {step75_factor189_data, step75_factor190_data, };
int step75_node15_factor_num_blks[] = {step75_factor189_num_blks, step75_factor190_num_blks, };
int* step75_node15_factor_A_blk_start[] = {step75_factor189_A_blk_start, step75_factor190_A_blk_start, };
int* step75_node15_factor_B_blk_start[] = {step75_factor189_B_blk_start, step75_factor190_B_blk_start, };
int* step75_node15_factor_blk_width[] = {step75_factor189_blk_width, step75_factor190_blk_width, };
const int step75_node15_parent = 16;
const int step75_node15_height = 37;
const int step75_node15_width = 30;
float step75_node15_data[1110] = {0};
const int step75_node15_num_blks = 1;
int step75_node15_A_blk_start[] = {0, };
int step75_node15_B_blk_start[] = {0, };
int step75_node15_blk_width[] = {6, };


const int step75_node16_num_factors = 3;
const int step75_node16_relin_cost = 20000;
const int step75_node16_sym_cost = 4000;
const bool step75_node16_marked = true;
const bool step75_node16_fixed = false;
int step75_node16_factor_height[] = {step75_factor188_height, step75_factor191_height, step75_factor192_height, };
int step75_node16_factor_width[] = {step75_factor188_width, step75_factor191_width, step75_factor192_width, };
int* step75_node16_factor_ridx[] = {step75_factor188_ridx, step75_factor191_ridx, step75_factor192_ridx, };
float* step75_node16_factor_data[] = {step75_factor188_data, step75_factor191_data, step75_factor192_data, };
int step75_node16_factor_num_blks[] = {step75_factor188_num_blks, step75_factor191_num_blks, step75_factor192_num_blks, };
int* step75_node16_factor_A_blk_start[] = {step75_factor188_A_blk_start, step75_factor191_A_blk_start, step75_factor192_A_blk_start, };
int* step75_node16_factor_B_blk_start[] = {step75_factor188_B_blk_start, step75_factor191_B_blk_start, step75_factor192_B_blk_start, };
int* step75_node16_factor_blk_width[] = {step75_factor188_blk_width, step75_factor191_blk_width, step75_factor192_blk_width, };
const int step75_node16_parent = 17;
const int step75_node16_height = 13;
const int step75_node16_width = 12;
float step75_node16_data[156] = {0};
const int step75_node16_num_blks = 0;
int step75_node16_A_blk_start[] = {};
int step75_node16_B_blk_start[] = {};
int step75_node16_blk_width[] = {};


const int step75_node17_num_factors = 0;
const int step75_node17_relin_cost = 0;
const int step75_node17_sym_cost = 2000;
const bool step75_node17_marked = true;
const bool step75_node17_fixed = false;
int step75_node17_factor_height[] = {};
int step75_node17_factor_width[] = {};
int* step75_node17_factor_ridx[] = {};
float* step75_node17_factor_data[] = {};
int step75_node17_factor_num_blks[] = {};
int* step75_node17_factor_A_blk_start[] = {};
int* step75_node17_factor_B_blk_start[] = {};
int* step75_node17_factor_blk_width[] = {};
const int step75_node17_parent = -1;
const int step75_node17_height = 1;
const int step75_node17_width = 1;
float step75_node17_data[1] = {0};
const int step75_node17_num_blks = 0;
int step75_node17_A_blk_start[] = {};
int step75_node17_B_blk_start[] = {};
int step75_node17_blk_width[] = {};


int step75_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 456, };
int step75_node1_ridx[] = {
36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 456, };
int step75_node2_ridx[] = {
60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 114, 115, 116, 117, 118, 119, 456, };
int step75_node3_ridx[] = {
84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 456, };
int step75_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 456, };
int step75_node5_ridx[] = {
150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 186, 187, 188, 189, 190, 191, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 456, };
int step75_node6_ridx[] = {
174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 456, };
int step75_node7_ridx[] = {
204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 456, };
int step75_node8_ridx[] = {
240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 282, 283, 284, 285, 286, 287, 456, };
int step75_node9_ridx[] = {
264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 456, };
int step75_node10_ridx[] = {
288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 456, };
int step75_node11_ridx[] = {
312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 456, };
int step75_node12_ridx[] = {
336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 456, };
int step75_node13_ridx[] = {
360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 456, };
int step75_node14_ridx[] = {
384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 456, };
int step75_node15_ridx[] = {
414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 456, };
int step75_node16_ridx[] = {
444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, };
int step75_node17_ridx[] = {
456, };
const int step75_nnodes = 18;
bool step75_node_marked[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, step75_node15_marked, step75_node16_marked, step75_node17_marked, };
bool step75_node_fixed[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, step75_node15_fixed, step75_node16_fixed, step75_node17_fixed, };
int step75_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_num_factors, step75_node16_num_factors, step75_node17_num_factors, };
int step75_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_relin_cost, step75_node16_relin_cost, step75_node17_relin_cost, };
int step75_node_sym_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_sym_cost, step75_node16_sym_cost, step75_node17_sym_cost, };
int* step75_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_factor_height, step75_node16_factor_height, step75_node17_factor_height, };
int* step75_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_factor_width, step75_node16_factor_width, step75_node17_factor_width, };
int** step75_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_factor_ridx, step75_node16_factor_ridx, step75_node17_factor_ridx, };
float** step75_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_factor_data, step75_node16_factor_data, step75_node17_factor_data, };
int* step75_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_factor_num_blks, step75_node16_factor_num_blks, step75_node17_factor_num_blks, };
int** step75_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_factor_A_blk_start, step75_node16_factor_A_blk_start, step75_node17_factor_A_blk_start, };
int** step75_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_factor_B_blk_start, step75_node16_factor_B_blk_start, step75_node17_factor_B_blk_start, };
int** step75_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_factor_blk_width, step75_node16_factor_blk_width, step75_node17_factor_blk_width, };
int step75_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_parent, step75_node16_parent, step75_node17_parent, };
int step75_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_height, step75_node16_height, step75_node17_height, };
int step75_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_width, step75_node16_width, step75_node17_width, };
float* step75_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_data, step75_node16_data, step75_node17_data, };
int step75_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_num_blks, step75_node16_num_blks, step75_node17_num_blks, };
int* step75_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_A_blk_start, step75_node16_A_blk_start, step75_node17_A_blk_start, };
int* step75_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_B_blk_start, step75_node16_B_blk_start, step75_node17_B_blk_start, };
int* step75_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step75_node15_blk_width, step75_node16_blk_width, step75_node17_blk_width, };
int* step75_node_ridx[] = {step75_node0_ridx, step75_node1_ridx, step75_node2_ridx, step75_node3_ridx, step75_node4_ridx, step75_node5_ridx, step75_node6_ridx, step75_node7_ridx, step75_node8_ridx, step75_node9_ridx, step75_node10_ridx, step75_node11_ridx, step75_node12_ridx, step75_node13_ridx, step75_node14_ridx, step75_node15_ridx, step75_node16_ridx, step75_node17_ridx, };


float step75_x_data[457] = {};
const int step75_workspace_needed = 6456;

