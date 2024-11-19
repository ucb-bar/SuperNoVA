#pragma once

const bool step99_is_reconstruct = true;

const int step99_num_threads = 1;

const uint64_t step99_scaled_relin_cost = 0;

const bool step99_run_model = false;

const int step99_factor352_height = 13;
const int step99_factor352_width = 6;
int step99_factor352_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, };
float step99_factor352_data[78] = {0};

const int step99_factor352_num_blks = 1;
int step99_factor352_A_blk_start[] = {0, };
int step99_factor352_B_blk_start[] = {0, };
int step99_factor352_blk_width[] = {12, };

const int step99_factor350_height = 13;
const int step99_factor350_width = 6;
int step99_factor350_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step99_factor350_data[78] = {0};

const int step99_factor350_num_blks = 1;
int step99_factor350_A_blk_start[] = {0, };
int step99_factor350_B_blk_start[] = {18, };
int step99_factor350_blk_width[] = {12, };

const int step99_factor351_height = 7;
const int step99_factor351_width = 6;
int step99_factor351_ridx[] = {6, 7, 8, 9, 10, 11, 12, };
float step99_factor351_data[42] = {0};

const int step99_factor351_num_blks = 1;
int step99_factor351_A_blk_start[] = {0, };
int step99_factor351_B_blk_start[] = {6, };
int step99_factor351_blk_width[] = {6, };

const int step99_factor349_height = 7;
const int step99_factor349_width = 6;
int step99_factor349_ridx[] = {0, 1, 2, 3, 4, 5, 12, };
float step99_factor349_data[42] = {0};

const int step99_factor349_num_blks = 1;
int step99_factor349_A_blk_start[] = {0, };
int step99_factor349_B_blk_start[] = {0, };
int step99_factor349_blk_width[] = {6, };

const int step99_node19_num_factors = 1;
const int step99_node19_relin_cost = 30000;
const bool step99_node19_marked = false;
const bool step99_node19_fixed = true;
int step99_node19_factor_height[] = {step99_factor350_height, };
int step99_node19_factor_width[] = {step99_factor350_width, };
int* step99_node19_factor_ridx[] = {step99_factor350_ridx, };
float* step99_node19_factor_data[] = {step99_factor350_data, };
int step99_node19_factor_num_blks[] = {step99_factor350_num_blks, };
int* step99_node19_factor_A_blk_start[] = {step99_factor350_A_blk_start, };
int* step99_node19_factor_B_blk_start[] = {step99_factor350_B_blk_start, };
int* step99_node19_factor_blk_width[] = {step99_factor350_blk_width, };
const int step99_node19_parent = 20;
const int step99_node19_height = 31;
const int step99_node19_width = 24;
float step99_node19_data[744] = {0};
const int step99_node19_num_blks = 1;
int step99_node19_A_blk_start[] = {0, };
int step99_node19_B_blk_start[] = {0, };
int step99_node19_blk_width[] = {6, };


const int step99_node20_num_factors = 3;
const int step99_node20_relin_cost = 90000;
const bool step99_node20_marked = true;
const bool step99_node20_fixed = false;
int step99_node20_factor_height[] = {step99_factor349_height, step99_factor351_height, step99_factor352_height, };
int step99_node20_factor_width[] = {step99_factor349_width, step99_factor351_width, step99_factor352_width, };
int* step99_node20_factor_ridx[] = {step99_factor349_ridx, step99_factor351_ridx, step99_factor352_ridx, };
float* step99_node20_factor_data[] = {step99_factor349_data, step99_factor351_data, step99_factor352_data, };
int step99_node20_factor_num_blks[] = {step99_factor349_num_blks, step99_factor351_num_blks, step99_factor352_num_blks, };
int* step99_node20_factor_A_blk_start[] = {step99_factor349_A_blk_start, step99_factor351_A_blk_start, step99_factor352_A_blk_start, };
int* step99_node20_factor_B_blk_start[] = {step99_factor349_B_blk_start, step99_factor351_B_blk_start, step99_factor352_B_blk_start, };
int* step99_node20_factor_blk_width[] = {step99_factor349_blk_width, step99_factor351_blk_width, step99_factor352_blk_width, };
const int step99_node20_parent = 21;
const int step99_node20_height = 13;
const int step99_node20_width = 12;
float step99_node20_data[156] = {0};
const int step99_node20_num_blks = 0;
int step99_node20_A_blk_start[] = {};
int step99_node20_B_blk_start[] = {};
int step99_node20_blk_width[] = {};


const int step99_node21_num_factors = 0;
const int step99_node21_relin_cost = 0;
const bool step99_node21_marked = true;
const bool step99_node21_fixed = false;
int step99_node21_factor_height[] = {};
int step99_node21_factor_width[] = {};
int* step99_node21_factor_ridx[] = {};
float* step99_node21_factor_data[] = {};
int step99_node21_factor_num_blks[] = {};
int* step99_node21_factor_A_blk_start[] = {};
int* step99_node21_factor_B_blk_start[] = {};
int* step99_node21_factor_blk_width[] = {};
const int step99_node21_parent = -1;
const int step99_node21_height = 1;
const int step99_node21_width = 1;
float step99_node21_data[1] = {0};
const int step99_node21_num_blks = 0;
int step99_node21_A_blk_start[] = {};
int step99_node21_B_blk_start[] = {};
int step99_node21_blk_width[] = {};


int step99_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 600, };
int step99_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 600, };
int step99_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 600, };
int step99_node3_ridx[] = {
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 246, 247, 248, 249, 250, 251, 600, };
int step99_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 276, 277, 278, 279, 280, 281, 600, };
int step99_node5_ridx[] = {
150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 240, 241, 242, 243, 244, 245, 270, 271, 272, 273, 274, 275, 600, };
int step99_node6_ridx[] = {
174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 240, 241, 242, 243, 244, 245, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 600, };
int step99_node7_ridx[] = {
198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 600, };
int step99_node8_ridx[] = {
222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 600, };
int step99_node9_ridx[] = {
264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 396, 397, 398, 399, 400, 401, 600, };
int step99_node10_ridx[] = {
288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 396, 397, 398, 399, 400, 401, 600, };
int step99_node11_ridx[] = {
312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 384, 385, 386, 387, 388, 389, 396, 397, 398, 399, 400, 401, 600, };
int step99_node12_ridx[] = {
342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 384, 385, 386, 387, 388, 389, 396, 397, 398, 399, 400, 401, 600, };
int step99_node13_ridx[] = {
366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 558, 559, 560, 561, 562, 563, 600, };
int step99_node14_ridx[] = {
396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 558, 559, 560, 561, 562, 563, 600, };
int step99_node15_ridx[] = {
420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 558, 559, 560, 561, 562, 563, 600, };
int step99_node16_ridx[] = {
444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 558, 559, 560, 561, 562, 563, 600, };
int step99_node17_ridx[] = {
468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 600, };
int step99_node18_ridx[] = {
510, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 600, };
int step99_node19_ridx[] = {
564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589, 590, 591, 592, 593, 600, };
int step99_node20_ridx[] = {
588, 589, 590, 591, 592, 593, 594, 595, 596, 597, 598, 599, 600, };
int step99_node21_ridx[] = {
600, };
const int step99_nnodes = 22;
bool step99_node_marked[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, step99_node19_marked, step99_node20_marked, step99_node21_marked, };
bool step99_node_fixed[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, step99_node19_fixed, step99_node20_fixed, step99_node21_fixed, };
int step99_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_num_factors, step99_node20_num_factors, step99_node21_num_factors, };
int step99_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_relin_cost, step99_node20_relin_cost, step99_node21_relin_cost, };
int* step99_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_factor_height, step99_node20_factor_height, step99_node21_factor_height, };
int* step99_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_factor_width, step99_node20_factor_width, step99_node21_factor_width, };
int** step99_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_factor_ridx, step99_node20_factor_ridx, step99_node21_factor_ridx, };
float** step99_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_factor_data, step99_node20_factor_data, step99_node21_factor_data, };
int* step99_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_factor_num_blks, step99_node20_factor_num_blks, step99_node21_factor_num_blks, };
int** step99_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_factor_A_blk_start, step99_node20_factor_A_blk_start, step99_node21_factor_A_blk_start, };
int** step99_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_factor_B_blk_start, step99_node20_factor_B_blk_start, step99_node21_factor_B_blk_start, };
int** step99_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_factor_blk_width, step99_node20_factor_blk_width, step99_node21_factor_blk_width, };
int step99_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_parent, step99_node20_parent, step99_node21_parent, };
int step99_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_height, step99_node20_height, step99_node21_height, };
int step99_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_width, step99_node20_width, step99_node21_width, };
float* step99_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_data, step99_node20_data, step99_node21_data, };
int step99_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_num_blks, step99_node20_num_blks, step99_node21_num_blks, };
int* step99_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_A_blk_start, step99_node20_A_blk_start, step99_node21_A_blk_start, };
int* step99_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_B_blk_start, step99_node20_B_blk_start, step99_node21_B_blk_start, };
int* step99_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step99_node19_blk_width, step99_node20_blk_width, step99_node21_blk_width, };
int* step99_node_ridx[] = {step99_node0_ridx, step99_node1_ridx, step99_node2_ridx, step99_node3_ridx, step99_node4_ridx, step99_node5_ridx, step99_node6_ridx, step99_node7_ridx, step99_node8_ridx, step99_node9_ridx, step99_node10_ridx, step99_node11_ridx, step99_node12_ridx, step99_node13_ridx, step99_node14_ridx, step99_node15_ridx, step99_node16_ridx, step99_node17_ridx, step99_node18_ridx, step99_node19_ridx, step99_node20_ridx, step99_node21_ridx, };


float step99_x_data[601] = {};
const int step99_workspace_needed = 4824;

