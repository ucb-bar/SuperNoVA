#pragma once

const bool step95_is_reconstruct = true;

const int step95_num_threads = 1;

const uint64_t step95_scaled_relin_cost = 0;

const bool step95_run_model = false;

const int step95_factor321_height = 7;
const int step95_factor321_width = 6;
int step95_factor321_ridx[] = {0, 1, 2, 3, 4, 5, 12, };
float step95_factor321_data[42] = {0};

const int step95_factor321_num_blks = 1;
int step95_factor321_A_blk_start[] = {0, };
int step95_factor321_B_blk_start[] = {0, };
int step95_factor321_blk_width[] = {6, };

const int step95_factor322_height = 13;
const int step95_factor322_width = 6;
int step95_factor322_ridx[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, };
float step95_factor322_data[78] = {0};

const int step95_factor322_num_blks = 1;
int step95_factor322_A_blk_start[] = {0, };
int step95_factor322_B_blk_start[] = {48, };
int step95_factor322_blk_width[] = {12, };

const int step95_factor323_height = 13;
const int step95_factor323_width = 6;
int step95_factor323_ridx[] = {6, 7, 8, 9, 10, 11, 54, 55, 56, 57, 58, 59, 60, };
float step95_factor323_data[78] = {0};

const int step95_factor323_num_blks = 2;
int step95_factor323_A_blk_start[] = {0, 6, };
int step95_factor323_B_blk_start[] = {6, 54, };
int step95_factor323_blk_width[] = {6, 6, };

const int step95_factor324_height = 7;
const int step95_factor324_width = 6;
int step95_factor324_ridx[] = {6, 7, 8, 9, 10, 11, 12, };
float step95_factor324_data[42] = {0};

const int step95_factor324_num_blks = 1;
int step95_factor324_A_blk_start[] = {0, };
int step95_factor324_B_blk_start[] = {6, };
int step95_factor324_blk_width[] = {6, };

const int step95_factor325_height = 13;
const int step95_factor325_width = 6;
int step95_factor325_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, };
float step95_factor325_data[78] = {0};

const int step95_factor325_num_blks = 1;
int step95_factor325_A_blk_start[] = {0, };
int step95_factor325_B_blk_start[] = {0, };
int step95_factor325_blk_width[] = {12, };

const int step95_node17_num_factors = 2;
const int step95_node17_relin_cost = 0;
const int step95_node17_sym_cost = 36000;
const bool step95_node17_marked = false;
const bool step95_node17_fixed = true;
int step95_node17_factor_height[] = {step95_factor322_height, step95_factor323_height, };
int step95_node17_factor_width[] = {step95_factor322_width, step95_factor323_width, };
int* step95_node17_factor_ridx[] = {step95_factor322_ridx, step95_factor323_ridx, };
float* step95_node17_factor_data[] = {step95_factor322_data, step95_factor323_data, };
int step95_node17_factor_num_blks[] = {step95_factor322_num_blks, step95_factor323_num_blks, };
int* step95_node17_factor_A_blk_start[] = {step95_factor322_A_blk_start, step95_factor323_A_blk_start, };
int* step95_node17_factor_B_blk_start[] = {step95_factor322_B_blk_start, step95_factor323_B_blk_start, };
int* step95_node17_factor_blk_width[] = {step95_factor322_blk_width, step95_factor323_blk_width, };
const int step95_node17_parent = 18;
const int step95_node17_height = 61;
const int step95_node17_width = 54;
float step95_node17_data[3294] = {0};
const int step95_node17_num_blks = 1;
int step95_node17_A_blk_start[] = {0, };
int step95_node17_B_blk_start[] = {0, };
int step95_node17_blk_width[] = {6, };


const int step95_node18_num_factors = 3;
const int step95_node18_relin_cost = 0;
const int step95_node18_sym_cost = 8000;
const bool step95_node18_marked = true;
const bool step95_node18_fixed = false;
int step95_node18_factor_height[] = {step95_factor321_height, step95_factor324_height, step95_factor325_height, };
int step95_node18_factor_width[] = {step95_factor321_width, step95_factor324_width, step95_factor325_width, };
int* step95_node18_factor_ridx[] = {step95_factor321_ridx, step95_factor324_ridx, step95_factor325_ridx, };
float* step95_node18_factor_data[] = {step95_factor321_data, step95_factor324_data, step95_factor325_data, };
int step95_node18_factor_num_blks[] = {step95_factor321_num_blks, step95_factor324_num_blks, step95_factor325_num_blks, };
int* step95_node18_factor_A_blk_start[] = {step95_factor321_A_blk_start, step95_factor324_A_blk_start, step95_factor325_A_blk_start, };
int* step95_node18_factor_B_blk_start[] = {step95_factor321_B_blk_start, step95_factor324_B_blk_start, step95_factor325_B_blk_start, };
int* step95_node18_factor_blk_width[] = {step95_factor321_blk_width, step95_factor324_blk_width, step95_factor325_blk_width, };
const int step95_node18_parent = 19;
const int step95_node18_height = 13;
const int step95_node18_width = 12;
float step95_node18_data[156] = {0};
const int step95_node18_num_blks = 0;
int step95_node18_A_blk_start[] = {};
int step95_node18_B_blk_start[] = {};
int step95_node18_blk_width[] = {};


const int step95_node19_num_factors = 0;
const int step95_node19_relin_cost = 0;
const int step95_node19_sym_cost = 4000;
const bool step95_node19_marked = true;
const bool step95_node19_fixed = false;
int step95_node19_factor_height[] = {};
int step95_node19_factor_width[] = {};
int* step95_node19_factor_ridx[] = {};
float* step95_node19_factor_data[] = {};
int step95_node19_factor_num_blks[] = {};
int* step95_node19_factor_A_blk_start[] = {};
int* step95_node19_factor_B_blk_start[] = {};
int* step95_node19_factor_blk_width[] = {};
const int step95_node19_parent = -1;
const int step95_node19_height = 1;
const int step95_node19_width = 1;
float step95_node19_data[1] = {0};
const int step95_node19_num_blks = 0;
int step95_node19_A_blk_start[] = {};
int step95_node19_B_blk_start[] = {};
int step95_node19_blk_width[] = {};


int step95_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 576, };
int step95_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 576, };
int step95_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 108, 109, 110, 111, 112, 113, 576, };
int step95_node3_ridx[] = {
90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 294, 295, 296, 297, 298, 299, 318, 319, 320, 321, 322, 323, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 576, };
int step95_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 348, 349, 350, 351, 352, 353, 384, 385, 386, 387, 388, 389, 576, };
int step95_node5_ridx[] = {
138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 270, 271, 272, 273, 274, 275, 288, 289, 290, 291, 292, 293, 372, 373, 374, 375, 376, 377, 384, 385, 386, 387, 388, 389, 576, };
int step95_node6_ridx[] = {
162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 576, };
int step95_node7_ridx[] = {
198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 354, 355, 356, 357, 358, 359, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 576, };
int step95_node8_ridx[] = {
228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 378, 379, 380, 381, 382, 383, 576, };
int step95_node9_ridx[] = {
252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 372, 373, 374, 375, 376, 377, 384, 385, 386, 387, 388, 389, 576, };
int step95_node10_ridx[] = {
276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 372, 373, 374, 375, 376, 377, 384, 385, 386, 387, 388, 389, 576, };
int step95_node11_ridx[] = {
300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 576, };
int step95_node12_ridx[] = {
354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 558, 559, 560, 561, 562, 563, 576, };
int step95_node13_ridx[] = {
384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 558, 559, 560, 561, 562, 563, 576, };
int step95_node14_ridx[] = {
408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 558, 559, 560, 561, 562, 563, 576, };
int step95_node15_ridx[] = {
432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 558, 559, 560, 561, 562, 563, 576, };
int step95_node16_ridx[] = {
462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 576, };
int step95_node17_ridx[] = {
510, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 576, };
int step95_node18_ridx[] = {
564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, };
int step95_node19_ridx[] = {
576, };
const int step95_nnodes = 20;
bool step95_node_marked[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, step95_node17_marked, step95_node18_marked, step95_node19_marked, };
bool step95_node_fixed[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, step95_node17_fixed, step95_node18_fixed, step95_node19_fixed, };
int step95_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_num_factors, step95_node18_num_factors, step95_node19_num_factors, };
int step95_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_relin_cost, step95_node18_relin_cost, step95_node19_relin_cost, };
int step95_node_sym_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_sym_cost, step95_node18_sym_cost, step95_node19_sym_cost, };
int* step95_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_factor_height, step95_node18_factor_height, step95_node19_factor_height, };
int* step95_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_factor_width, step95_node18_factor_width, step95_node19_factor_width, };
int** step95_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_factor_ridx, step95_node18_factor_ridx, step95_node19_factor_ridx, };
float** step95_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_factor_data, step95_node18_factor_data, step95_node19_factor_data, };
int* step95_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_factor_num_blks, step95_node18_factor_num_blks, step95_node19_factor_num_blks, };
int** step95_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_factor_A_blk_start, step95_node18_factor_A_blk_start, step95_node19_factor_A_blk_start, };
int** step95_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_factor_B_blk_start, step95_node18_factor_B_blk_start, step95_node19_factor_B_blk_start, };
int** step95_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_factor_blk_width, step95_node18_factor_blk_width, step95_node19_factor_blk_width, };
int step95_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_parent, step95_node18_parent, step95_node19_parent, };
int step95_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_height, step95_node18_height, step95_node19_height, };
int step95_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_width, step95_node18_width, step95_node19_width, };
float* step95_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_data, step95_node18_data, step95_node19_data, };
int step95_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_num_blks, step95_node18_num_blks, step95_node19_num_blks, };
int* step95_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_A_blk_start, step95_node18_A_blk_start, step95_node19_A_blk_start, };
int* step95_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_B_blk_start, step95_node18_B_blk_start, step95_node19_B_blk_start, };
int* step95_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step95_node17_blk_width, step95_node18_blk_width, step95_node19_blk_width, };
int* step95_node_ridx[] = {step95_node0_ridx, step95_node1_ridx, step95_node2_ridx, step95_node3_ridx, step95_node4_ridx, step95_node5_ridx, step95_node6_ridx, step95_node7_ridx, step95_node8_ridx, step95_node9_ridx, step95_node10_ridx, step95_node11_ridx, step95_node12_ridx, step95_node13_ridx, step95_node14_ridx, step95_node15_ridx, step95_node16_ridx, step95_node17_ridx, step95_node18_ridx, step95_node19_ridx, };


float step95_x_data[577] = {};
const int step95_workspace_needed = 15864;

