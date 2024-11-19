#pragma once

const bool step87_is_reconstruct = true;

const int step87_num_threads = 1;

const uint64_t step87_scaled_relin_cost = 0;

const bool step87_run_model = false;

const int step87_factor269_height = 13;
const int step87_factor269_width = 6;
int step87_factor269_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 18, };
float step87_factor269_data[78] = {0};

const int step87_factor269_num_blks = 1;
int step87_factor269_A_blk_start[] = {0, };
int step87_factor269_B_blk_start[] = {0, };
int step87_factor269_blk_width[] = {12, };

const int step87_factor270_height = 7;
const int step87_factor270_width = 6;
int step87_factor270_ridx[] = {12, 13, 14, 15, 16, 17, 18, };
float step87_factor270_data[42] = {0};

const int step87_factor270_num_blks = 1;
int step87_factor270_A_blk_start[] = {0, };
int step87_factor270_B_blk_start[] = {12, };
int step87_factor270_blk_width[] = {6, };

const int step87_factor271_height = 13;
const int step87_factor271_width = 6;
int step87_factor271_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, };
float step87_factor271_data[78] = {0};

const int step87_factor271_num_blks = 1;
int step87_factor271_A_blk_start[] = {0, };
int step87_factor271_B_blk_start[] = {6, };
int step87_factor271_blk_width[] = {12, };

const int step87_factor263_height = 7;
const int step87_factor263_width = 6;
int step87_factor263_ridx[] = {0, 1, 2, 3, 4, 5, 18, };
float step87_factor263_data[42] = {0};

const int step87_factor263_num_blks = 1;
int step87_factor263_A_blk_start[] = {0, };
int step87_factor263_B_blk_start[] = {0, };
int step87_factor263_blk_width[] = {6, };

const int step87_factor264_height = 13;
const int step87_factor264_width = 6;
int step87_factor264_ridx[] = {36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, };
float step87_factor264_data[78] = {0};

const int step87_factor264_num_blks = 1;
int step87_factor264_A_blk_start[] = {0, };
int step87_factor264_B_blk_start[] = {36, };
int step87_factor264_blk_width[] = {12, };

const int step87_factor265_height = 13;
const int step87_factor265_width = 6;
int step87_factor265_ridx[] = {12, 13, 14, 15, 16, 17, 42, 43, 44, 45, 46, 47, 48, };
float step87_factor265_data[78] = {0};

const int step87_factor265_num_blks = 2;
int step87_factor265_A_blk_start[] = {0, 6, };
int step87_factor265_B_blk_start[] = {12, 42, };
int step87_factor265_blk_width[] = {6, 6, };

const int step87_factor266_height = 13;
const int step87_factor266_width = 6;
int step87_factor266_ridx[] = {24, 25, 26, 27, 28, 29, 42, 43, 44, 45, 46, 47, 48, };
float step87_factor266_data[78] = {0};

const int step87_factor266_num_blks = 2;
int step87_factor266_A_blk_start[] = {0, 6, };
int step87_factor266_B_blk_start[] = {24, 42, };
int step87_factor266_blk_width[] = {6, 6, };

const int step87_factor267_height = 13;
const int step87_factor267_width = 6;
int step87_factor267_ridx[] = {30, 31, 32, 33, 34, 35, 42, 43, 44, 45, 46, 47, 48, };
float step87_factor267_data[78] = {0};

const int step87_factor267_num_blks = 2;
int step87_factor267_A_blk_start[] = {0, 6, };
int step87_factor267_B_blk_start[] = {30, 42, };
int step87_factor267_blk_width[] = {6, 6, };

const int step87_factor268_height = 7;
const int step87_factor268_width = 6;
int step87_factor268_ridx[] = {6, 7, 8, 9, 10, 11, 18, };
float step87_factor268_data[42] = {0};

const int step87_factor268_num_blks = 1;
int step87_factor268_A_blk_start[] = {0, };
int step87_factor268_B_blk_start[] = {6, };
int step87_factor268_blk_width[] = {6, };

const int step87_node17_num_factors = 4;
const int step87_node17_relin_cost = 120000;
const bool step87_node17_marked = false;
const bool step87_node17_fixed = true;
int step87_node17_factor_height[] = {step87_factor264_height, step87_factor265_height, step87_factor266_height, step87_factor267_height, };
int step87_node17_factor_width[] = {step87_factor264_width, step87_factor265_width, step87_factor266_width, step87_factor267_width, };
int* step87_node17_factor_ridx[] = {step87_factor264_ridx, step87_factor265_ridx, step87_factor266_ridx, step87_factor267_ridx, };
float* step87_node17_factor_data[] = {step87_factor264_data, step87_factor265_data, step87_factor266_data, step87_factor267_data, };
int step87_node17_factor_num_blks[] = {step87_factor264_num_blks, step87_factor265_num_blks, step87_factor266_num_blks, step87_factor267_num_blks, };
int* step87_node17_factor_A_blk_start[] = {step87_factor264_A_blk_start, step87_factor265_A_blk_start, step87_factor266_A_blk_start, step87_factor267_A_blk_start, };
int* step87_node17_factor_B_blk_start[] = {step87_factor264_B_blk_start, step87_factor265_B_blk_start, step87_factor266_B_blk_start, step87_factor267_B_blk_start, };
int* step87_node17_factor_blk_width[] = {step87_factor264_blk_width, step87_factor265_blk_width, step87_factor266_blk_width, step87_factor267_blk_width, };
const int step87_node17_parent = 18;
const int step87_node17_height = 49;
const int step87_node17_width = 42;
float step87_node17_data[2058] = {0};
const int step87_node17_num_blks = 1;
int step87_node17_A_blk_start[] = {0, };
int step87_node17_B_blk_start[] = {0, };
int step87_node17_blk_width[] = {6, };


const int step87_node18_num_factors = 5;
const int step87_node18_relin_cost = 150000;
const bool step87_node18_marked = true;
const bool step87_node18_fixed = false;
int step87_node18_factor_height[] = {step87_factor263_height, step87_factor268_height, step87_factor269_height, step87_factor270_height, step87_factor271_height, };
int step87_node18_factor_width[] = {step87_factor263_width, step87_factor268_width, step87_factor269_width, step87_factor270_width, step87_factor271_width, };
int* step87_node18_factor_ridx[] = {step87_factor263_ridx, step87_factor268_ridx, step87_factor269_ridx, step87_factor270_ridx, step87_factor271_ridx, };
float* step87_node18_factor_data[] = {step87_factor263_data, step87_factor268_data, step87_factor269_data, step87_factor270_data, step87_factor271_data, };
int step87_node18_factor_num_blks[] = {step87_factor263_num_blks, step87_factor268_num_blks, step87_factor269_num_blks, step87_factor270_num_blks, step87_factor271_num_blks, };
int* step87_node18_factor_A_blk_start[] = {step87_factor263_A_blk_start, step87_factor268_A_blk_start, step87_factor269_A_blk_start, step87_factor270_A_blk_start, step87_factor271_A_blk_start, };
int* step87_node18_factor_B_blk_start[] = {step87_factor263_B_blk_start, step87_factor268_B_blk_start, step87_factor269_B_blk_start, step87_factor270_B_blk_start, step87_factor271_B_blk_start, };
int* step87_node18_factor_blk_width[] = {step87_factor263_blk_width, step87_factor268_blk_width, step87_factor269_blk_width, step87_factor270_blk_width, step87_factor271_blk_width, };
const int step87_node18_parent = 19;
const int step87_node18_height = 19;
const int step87_node18_width = 18;
float step87_node18_data[342] = {0};
const int step87_node18_num_blks = 0;
int step87_node18_A_blk_start[] = {};
int step87_node18_B_blk_start[] = {};
int step87_node18_blk_width[] = {};


const int step87_node19_num_factors = 0;
const int step87_node19_relin_cost = 0;
const bool step87_node19_marked = true;
const bool step87_node19_fixed = false;
int step87_node19_factor_height[] = {};
int step87_node19_factor_width[] = {};
int* step87_node19_factor_ridx[] = {};
float* step87_node19_factor_data[] = {};
int step87_node19_factor_num_blks[] = {};
int* step87_node19_factor_A_blk_start[] = {};
int* step87_node19_factor_B_blk_start[] = {};
int* step87_node19_factor_blk_width[] = {};
const int step87_node19_parent = -1;
const int step87_node19_height = 1;
const int step87_node19_width = 1;
float step87_node19_data[1] = {0};
const int step87_node19_num_blks = 0;
int step87_node19_A_blk_start[] = {};
int step87_node19_B_blk_start[] = {};
int step87_node19_blk_width[] = {};


int step87_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 528, };
int step87_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 528, };
int step87_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 528, };
int step87_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 246, 247, 248, 249, 250, 251, 528, };
int step87_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 276, 277, 278, 279, 280, 281, 528, };
int step87_node5_ridx[] = {
150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 240, 241, 242, 243, 244, 245, 270, 271, 272, 273, 274, 275, 528, };
int step87_node6_ridx[] = {
174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 240, 241, 242, 243, 244, 245, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 528, };
int step87_node7_ridx[] = {
198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 528, };
int step87_node8_ridx[] = {
222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 528, };
int step87_node9_ridx[] = {
264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 396, 397, 398, 399, 400, 401, 528, };
int step87_node10_ridx[] = {
288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 396, 397, 398, 399, 400, 401, 528, };
int step87_node11_ridx[] = {
312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 384, 385, 386, 387, 388, 389, 396, 397, 398, 399, 400, 401, 528, };
int step87_node12_ridx[] = {
342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 384, 385, 386, 387, 388, 389, 396, 397, 398, 399, 400, 401, 528, };
int step87_node13_ridx[] = {
366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 528, };
int step87_node14_ridx[] = {
396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 528, };
int step87_node15_ridx[] = {
420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 528, };
int step87_node16_ridx[] = {
444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 528, };
int step87_node17_ridx[] = {
468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 528, };
int step87_node18_ridx[] = {
510, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528, };
int step87_node19_ridx[] = {
528, };
const int step87_nnodes = 20;
bool step87_node_marked[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, step87_node17_marked, step87_node18_marked, step87_node19_marked, };
bool step87_node_fixed[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, step87_node17_fixed, step87_node18_fixed, step87_node19_fixed, };
int step87_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_num_factors, step87_node18_num_factors, step87_node19_num_factors, };
int step87_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_relin_cost, step87_node18_relin_cost, step87_node19_relin_cost, };
int* step87_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_factor_height, step87_node18_factor_height, step87_node19_factor_height, };
int* step87_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_factor_width, step87_node18_factor_width, step87_node19_factor_width, };
int** step87_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_factor_ridx, step87_node18_factor_ridx, step87_node19_factor_ridx, };
float** step87_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_factor_data, step87_node18_factor_data, step87_node19_factor_data, };
int* step87_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_factor_num_blks, step87_node18_factor_num_blks, step87_node19_factor_num_blks, };
int** step87_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_factor_A_blk_start, step87_node18_factor_A_blk_start, step87_node19_factor_A_blk_start, };
int** step87_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_factor_B_blk_start, step87_node18_factor_B_blk_start, step87_node19_factor_B_blk_start, };
int** step87_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_factor_blk_width, step87_node18_factor_blk_width, step87_node19_factor_blk_width, };
int step87_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_parent, step87_node18_parent, step87_node19_parent, };
int step87_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_height, step87_node18_height, step87_node19_height, };
int step87_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_width, step87_node18_width, step87_node19_width, };
float* step87_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_data, step87_node18_data, step87_node19_data, };
int step87_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_num_blks, step87_node18_num_blks, step87_node19_num_blks, };
int* step87_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_A_blk_start, step87_node18_A_blk_start, step87_node19_A_blk_start, };
int* step87_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_B_blk_start, step87_node18_B_blk_start, step87_node19_B_blk_start, };
int* step87_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step87_node17_blk_width, step87_node18_blk_width, step87_node19_blk_width, };
int* step87_node_ridx[] = {step87_node0_ridx, step87_node1_ridx, step87_node2_ridx, step87_node3_ridx, step87_node4_ridx, step87_node5_ridx, step87_node6_ridx, step87_node7_ridx, step87_node8_ridx, step87_node9_ridx, step87_node10_ridx, step87_node11_ridx, step87_node12_ridx, step87_node13_ridx, step87_node14_ridx, step87_node15_ridx, step87_node16_ridx, step87_node17_ridx, step87_node18_ridx, step87_node19_ridx, };


float step87_x_data[529] = {};
const int step87_workspace_needed = 11352;

