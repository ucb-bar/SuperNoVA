#pragma once

const bool step100_is_reconstruct = true;

const int step100_num_threads = -1;

const uint64_t step100_scaled_relin_cost = -1;

const bool step100_run_model = false;

const int step100_factor306_height = 13;
const int step100_factor306_width = 6;
int step100_factor306_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 24, };
float step100_factor306_data[78] = {0};

const int step100_factor306_num_blks = 1;
int step100_factor306_A_blk_start[] = {0, };
int step100_factor306_B_blk_start[] = {6, };
int step100_factor306_blk_width[] = {12, };

const int step100_factor301_height = 7;
const int step100_factor301_width = 6;
int step100_factor301_ridx[] = {0, 1, 2, 3, 4, 5, 24, };
float step100_factor301_data[42] = {0};

const int step100_factor301_num_blks = 1;
int step100_factor301_A_blk_start[] = {0, };
int step100_factor301_B_blk_start[] = {0, };
int step100_factor301_blk_width[] = {6, };

const int step100_factor307_height = 7;
const int step100_factor307_width = 6;
int step100_factor307_ridx[] = {18, 19, 20, 21, 22, 23, 24, };
float step100_factor307_data[42] = {0};

const int step100_factor307_num_blks = 1;
int step100_factor307_A_blk_start[] = {0, };
int step100_factor307_B_blk_start[] = {18, };
int step100_factor307_blk_width[] = {6, };

const int step100_factor302_height = 13;
const int step100_factor302_width = 6;
int step100_factor302_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step100_factor302_data[78] = {0};

const int step100_factor302_num_blks = 1;
int step100_factor302_A_blk_start[] = {0, };
int step100_factor302_B_blk_start[] = {18, };
int step100_factor302_blk_width[] = {12, };

const int step100_factor308_height = 13;
const int step100_factor308_width = 6;
int step100_factor308_ridx[] = {6, 7, 8, 9, 10, 11, 18, 19, 20, 21, 22, 23, 24, };
float step100_factor308_data[78] = {0};

const int step100_factor308_num_blks = 2;
int step100_factor308_A_blk_start[] = {0, 6, };
int step100_factor308_B_blk_start[] = {6, 18, };
int step100_factor308_blk_width[] = {6, 6, };

const int step100_factor303_height = 7;
const int step100_factor303_width = 6;
int step100_factor303_ridx[] = {6, 7, 8, 9, 10, 11, 24, };
float step100_factor303_data[42] = {0};

const int step100_factor303_num_blks = 1;
int step100_factor303_A_blk_start[] = {0, };
int step100_factor303_B_blk_start[] = {6, };
int step100_factor303_blk_width[] = {6, };

const int step100_factor309_height = 13;
const int step100_factor309_width = 6;
int step100_factor309_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, };
float step100_factor309_data[78] = {0};

const int step100_factor309_num_blks = 1;
int step100_factor309_A_blk_start[] = {0, };
int step100_factor309_B_blk_start[] = {12, };
int step100_factor309_blk_width[] = {12, };

const int step100_factor304_height = 13;
const int step100_factor304_width = 6;
int step100_factor304_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 24, };
float step100_factor304_data[78] = {0};

const int step100_factor304_num_blks = 1;
int step100_factor304_A_blk_start[] = {0, };
int step100_factor304_B_blk_start[] = {0, };
int step100_factor304_blk_width[] = {12, };

const int step100_factor305_height = 7;
const int step100_factor305_width = 6;
int step100_factor305_ridx[] = {12, 13, 14, 15, 16, 17, 24, };
float step100_factor305_data[42] = {0};

const int step100_factor305_num_blks = 1;
int step100_factor305_A_blk_start[] = {0, };
int step100_factor305_B_blk_start[] = {12, };
int step100_factor305_blk_width[] = {6, };

const int step100_node19_num_factors = 1;
const int step100_node19_relin_cost = 0;
const int step100_node19_sym_cost = 8000;
const bool step100_node19_marked = false;
const bool step100_node19_fixed = true;
int step100_node19_factor_height[] = {step100_factor302_height, };
int step100_node19_factor_width[] = {step100_factor302_width, };
int* step100_node19_factor_ridx[] = {step100_factor302_ridx, };
float* step100_node19_factor_data[] = {step100_factor302_data, };
int step100_node19_factor_num_blks[] = {step100_factor302_num_blks, };
int* step100_node19_factor_A_blk_start[] = {step100_factor302_A_blk_start, };
int* step100_node19_factor_B_blk_start[] = {step100_factor302_B_blk_start, };
int* step100_node19_factor_blk_width[] = {step100_factor302_blk_width, };
const int step100_node19_parent = 20;
const int step100_node19_height = 31;
const int step100_node19_width = 24;
float step100_node19_data[744] = {0};
const int step100_node19_num_blks = 1;
int step100_node19_A_blk_start[] = {0, };
int step100_node19_B_blk_start[] = {0, };
int step100_node19_blk_width[] = {6, };


const int step100_node20_num_factors = 8;
const int step100_node20_relin_cost = 0;
const int step100_node20_sym_cost = 8000;
const bool step100_node20_marked = true;
const bool step100_node20_fixed = false;
int step100_node20_factor_height[] = {step100_factor301_height, step100_factor303_height, step100_factor304_height, step100_factor305_height, step100_factor306_height, step100_factor307_height, step100_factor308_height, step100_factor309_height, };
int step100_node20_factor_width[] = {step100_factor301_width, step100_factor303_width, step100_factor304_width, step100_factor305_width, step100_factor306_width, step100_factor307_width, step100_factor308_width, step100_factor309_width, };
int* step100_node20_factor_ridx[] = {step100_factor301_ridx, step100_factor303_ridx, step100_factor304_ridx, step100_factor305_ridx, step100_factor306_ridx, step100_factor307_ridx, step100_factor308_ridx, step100_factor309_ridx, };
float* step100_node20_factor_data[] = {step100_factor301_data, step100_factor303_data, step100_factor304_data, step100_factor305_data, step100_factor306_data, step100_factor307_data, step100_factor308_data, step100_factor309_data, };
int step100_node20_factor_num_blks[] = {step100_factor301_num_blks, step100_factor303_num_blks, step100_factor304_num_blks, step100_factor305_num_blks, step100_factor306_num_blks, step100_factor307_num_blks, step100_factor308_num_blks, step100_factor309_num_blks, };
int* step100_node20_factor_A_blk_start[] = {step100_factor301_A_blk_start, step100_factor303_A_blk_start, step100_factor304_A_blk_start, step100_factor305_A_blk_start, step100_factor306_A_blk_start, step100_factor307_A_blk_start, step100_factor308_A_blk_start, step100_factor309_A_blk_start, };
int* step100_node20_factor_B_blk_start[] = {step100_factor301_B_blk_start, step100_factor303_B_blk_start, step100_factor304_B_blk_start, step100_factor305_B_blk_start, step100_factor306_B_blk_start, step100_factor307_B_blk_start, step100_factor308_B_blk_start, step100_factor309_B_blk_start, };
int* step100_node20_factor_blk_width[] = {step100_factor301_blk_width, step100_factor303_blk_width, step100_factor304_blk_width, step100_factor305_blk_width, step100_factor306_blk_width, step100_factor307_blk_width, step100_factor308_blk_width, step100_factor309_blk_width, };
const int step100_node20_parent = 21;
const int step100_node20_height = 25;
const int step100_node20_width = 24;
float step100_node20_data[600] = {0};
const int step100_node20_num_blks = 0;
int step100_node20_A_blk_start[] = {};
int step100_node20_B_blk_start[] = {};
int step100_node20_blk_width[] = {};


const int step100_node21_num_factors = 0;
const int step100_node21_relin_cost = 0;
const int step100_node21_sym_cost = 2000;
const bool step100_node21_marked = true;
const bool step100_node21_fixed = false;
int step100_node21_factor_height[] = {};
int step100_node21_factor_width[] = {};
int* step100_node21_factor_ridx[] = {};
float* step100_node21_factor_data[] = {};
int step100_node21_factor_num_blks[] = {};
int* step100_node21_factor_A_blk_start[] = {};
int* step100_node21_factor_B_blk_start[] = {};
int* step100_node21_factor_blk_width[] = {};
const int step100_node21_parent = -1;
const int step100_node21_height = 1;
const int step100_node21_width = 1;
float step100_node21_data[1] = {0};
const int step100_node21_num_blks = 0;
int step100_node21_A_blk_start[] = {};
int step100_node21_B_blk_start[] = {};
int step100_node21_blk_width[] = {};


int step100_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 606, };
int step100_node1_ridx[] = {
36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 606, };
int step100_node2_ridx[] = {
60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 114, 115, 116, 117, 118, 119, 606, };
int step100_node3_ridx[] = {
84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 606, };
int step100_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 606, };
int step100_node5_ridx[] = {
150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 186, 187, 188, 189, 190, 191, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 606, };
int step100_node6_ridx[] = {
174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 606, };
int step100_node7_ridx[] = {
204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 606, };
int step100_node8_ridx[] = {
240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 282, 283, 284, 285, 286, 287, 606, };
int step100_node9_ridx[] = {
264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 606, };
int step100_node10_ridx[] = {
288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 606, };
int step100_node11_ridx[] = {
312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 606, };
int step100_node12_ridx[] = {
336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 606, };
int step100_node13_ridx[] = {
360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 606, };
int step100_node14_ridx[] = {
384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 444, 445, 446, 447, 448, 449, 606, };
int step100_node15_ridx[] = {
414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 606, };
int step100_node16_ridx[] = {
444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 606, };
int step100_node17_ridx[] = {
510, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 606, };
int step100_node18_ridx[] = {
534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 606, };
int step100_node19_ridx[] = {
558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 606, };
int step100_node20_ridx[] = {
582, 583, 584, 585, 586, 587, 588, 589, 590, 591, 592, 593, 594, 595, 596, 597, 598, 599, 600, 601, 602, 603, 604, 605, 606, };
int step100_node21_ridx[] = {
606, };
const int step100_nnodes = 22;
bool step100_node_marked[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, step100_node19_marked, step100_node20_marked, step100_node21_marked, };
bool step100_node_fixed[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, step100_node19_fixed, step100_node20_fixed, step100_node21_fixed, };
int step100_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_num_factors, step100_node20_num_factors, step100_node21_num_factors, };
int step100_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_relin_cost, step100_node20_relin_cost, step100_node21_relin_cost, };
int step100_node_sym_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_sym_cost, step100_node20_sym_cost, step100_node21_sym_cost, };
int* step100_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_factor_height, step100_node20_factor_height, step100_node21_factor_height, };
int* step100_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_factor_width, step100_node20_factor_width, step100_node21_factor_width, };
int** step100_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_factor_ridx, step100_node20_factor_ridx, step100_node21_factor_ridx, };
float** step100_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_factor_data, step100_node20_factor_data, step100_node21_factor_data, };
int* step100_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_factor_num_blks, step100_node20_factor_num_blks, step100_node21_factor_num_blks, };
int** step100_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_factor_A_blk_start, step100_node20_factor_A_blk_start, step100_node21_factor_A_blk_start, };
int** step100_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_factor_B_blk_start, step100_node20_factor_B_blk_start, step100_node21_factor_B_blk_start, };
int** step100_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_factor_blk_width, step100_node20_factor_blk_width, step100_node21_factor_blk_width, };
int step100_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_parent, step100_node20_parent, step100_node21_parent, };
int step100_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_height, step100_node20_height, step100_node21_height, };
int step100_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_width, step100_node20_width, step100_node21_width, };
float* step100_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_data, step100_node20_data, step100_node21_data, };
int step100_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_num_blks, step100_node20_num_blks, step100_node21_num_blks, };
int* step100_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_A_blk_start, step100_node20_A_blk_start, step100_node21_A_blk_start, };
int* step100_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_B_blk_start, step100_node20_B_blk_start, step100_node21_B_blk_start, };
int* step100_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step100_node19_blk_width, step100_node20_blk_width, step100_node21_blk_width, };
int* step100_node_ridx[] = {step100_node0_ridx, step100_node1_ridx, step100_node2_ridx, step100_node3_ridx, step100_node4_ridx, step100_node5_ridx, step100_node6_ridx, step100_node7_ridx, step100_node8_ridx, step100_node9_ridx, step100_node10_ridx, step100_node11_ridx, step100_node12_ridx, step100_node13_ridx, step100_node14_ridx, step100_node15_ridx, step100_node16_ridx, step100_node17_ridx, step100_node18_ridx, step100_node19_ridx, step100_node20_ridx, step100_node21_ridx, };


float step100_x_data[607] = {};
const int step100_workspace_needed = 6648;

