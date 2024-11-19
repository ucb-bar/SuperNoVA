#pragma once

const bool step76_is_reconstruct = true;

const int step76_num_threads = 1;

const uint64_t step76_scaled_relin_cost = 60000;

const bool step76_run_model = false;

const int step76_factor235_height = 13;
const int step76_factor235_width = 6;
int step76_factor235_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 30, };
float step76_factor235_data[78] = {0};

const int step76_factor235_num_blks = 1;
int step76_factor235_A_blk_start[] = {0, };
int step76_factor235_B_blk_start[] = {12, };
int step76_factor235_blk_width[] = {12, };

const int step76_factor236_height = 13;
const int step76_factor236_width = 6;
int step76_factor236_ridx[] = {6, 7, 8, 9, 10, 11, 18, 19, 20, 21, 22, 23, 30, };
float step76_factor236_data[78] = {0};

const int step76_factor236_num_blks = 2;
int step76_factor236_A_blk_start[] = {0, 6, };
int step76_factor236_B_blk_start[] = {6, 18, };
int step76_factor236_blk_width[] = {6, 6, };

const int step76_factor237_height = 7;
const int step76_factor237_width = 6;
int step76_factor237_ridx[] = {24, 25, 26, 27, 28, 29, 30, };
float step76_factor237_data[42] = {0};

const int step76_factor237_num_blks = 1;
int step76_factor237_A_blk_start[] = {0, };
int step76_factor237_B_blk_start[] = {24, };
int step76_factor237_blk_width[] = {6, };

const int step76_factor238_height = 13;
const int step76_factor238_width = 6;
int step76_factor238_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step76_factor238_data[78] = {0};

const int step76_factor238_num_blks = 1;
int step76_factor238_A_blk_start[] = {0, };
int step76_factor238_B_blk_start[] = {18, };
int step76_factor238_blk_width[] = {12, };

const int step76_factor228_height = 7;
const int step76_factor228_width = 6;
int step76_factor228_ridx[] = {0, 1, 2, 3, 4, 5, 30, };
float step76_factor228_data[42] = {0};

const int step76_factor228_num_blks = 1;
int step76_factor228_A_blk_start[] = {0, };
int step76_factor228_B_blk_start[] = {0, };
int step76_factor228_blk_width[] = {6, };

const int step76_factor229_height = 13;
const int step76_factor229_width = 6;
int step76_factor229_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step76_factor229_data[78] = {0};

const int step76_factor229_num_blks = 1;
int step76_factor229_A_blk_start[] = {0, };
int step76_factor229_B_blk_start[] = {18, };
int step76_factor229_blk_width[] = {12, };

const int step76_factor230_height = 7;
const int step76_factor230_width = 6;
int step76_factor230_ridx[] = {6, 7, 8, 9, 10, 11, 30, };
float step76_factor230_data[42] = {0};

const int step76_factor230_num_blks = 1;
int step76_factor230_A_blk_start[] = {0, };
int step76_factor230_B_blk_start[] = {6, };
int step76_factor230_blk_width[] = {6, };

const int step76_factor231_height = 13;
const int step76_factor231_width = 6;
int step76_factor231_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 30, };
float step76_factor231_data[78] = {0};

const int step76_factor231_num_blks = 1;
int step76_factor231_A_blk_start[] = {0, };
int step76_factor231_B_blk_start[] = {0, };
int step76_factor231_blk_width[] = {12, };

const int step76_factor232_height = 7;
const int step76_factor232_width = 6;
int step76_factor232_ridx[] = {12, 13, 14, 15, 16, 17, 30, };
float step76_factor232_data[42] = {0};

const int step76_factor232_num_blks = 1;
int step76_factor232_A_blk_start[] = {0, };
int step76_factor232_B_blk_start[] = {12, };
int step76_factor232_blk_width[] = {6, };

const int step76_factor233_height = 13;
const int step76_factor233_width = 6;
int step76_factor233_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 30, };
float step76_factor233_data[78] = {0};

const int step76_factor233_num_blks = 1;
int step76_factor233_A_blk_start[] = {0, };
int step76_factor233_B_blk_start[] = {6, };
int step76_factor233_blk_width[] = {12, };

const int step76_factor234_height = 7;
const int step76_factor234_width = 6;
int step76_factor234_ridx[] = {18, 19, 20, 21, 22, 23, 30, };
float step76_factor234_data[42] = {0};

const int step76_factor234_num_blks = 1;
int step76_factor234_A_blk_start[] = {0, };
int step76_factor234_B_blk_start[] = {18, };
int step76_factor234_blk_width[] = {6, };

const int step76_node14_num_factors = 1;
const int step76_node14_relin_cost = 0;
const int step76_node14_sym_cost = 16000;
const bool step76_node14_marked = false;
const bool step76_node14_fixed = true;
int step76_node14_factor_height[] = {step76_factor229_height, };
int step76_node14_factor_width[] = {step76_factor229_width, };
int* step76_node14_factor_ridx[] = {step76_factor229_ridx, };
float* step76_node14_factor_data[] = {step76_factor229_data, };
int step76_node14_factor_num_blks[] = {step76_factor229_num_blks, };
int* step76_node14_factor_A_blk_start[] = {step76_factor229_A_blk_start, };
int* step76_node14_factor_B_blk_start[] = {step76_factor229_B_blk_start, };
int* step76_node14_factor_blk_width[] = {step76_factor229_blk_width, };
const int step76_node14_parent = 15;
const int step76_node14_height = 31;
const int step76_node14_width = 24;
float step76_node14_data[744] = {0};
const int step76_node14_num_blks = 1;
int step76_node14_A_blk_start[] = {0, };
int step76_node14_B_blk_start[] = {0, };
int step76_node14_blk_width[] = {6, };


const int step76_node15_num_factors = 10;
const int step76_node15_relin_cost = 60000;
const int step76_node15_sym_cost = 20000;
const bool step76_node15_marked = true;
const bool step76_node15_fixed = false;
int step76_node15_factor_height[] = {step76_factor228_height, step76_factor230_height, step76_factor231_height, step76_factor232_height, step76_factor233_height, step76_factor234_height, step76_factor235_height, step76_factor236_height, step76_factor237_height, step76_factor238_height, };
int step76_node15_factor_width[] = {step76_factor228_width, step76_factor230_width, step76_factor231_width, step76_factor232_width, step76_factor233_width, step76_factor234_width, step76_factor235_width, step76_factor236_width, step76_factor237_width, step76_factor238_width, };
int* step76_node15_factor_ridx[] = {step76_factor228_ridx, step76_factor230_ridx, step76_factor231_ridx, step76_factor232_ridx, step76_factor233_ridx, step76_factor234_ridx, step76_factor235_ridx, step76_factor236_ridx, step76_factor237_ridx, step76_factor238_ridx, };
float* step76_node15_factor_data[] = {step76_factor228_data, step76_factor230_data, step76_factor231_data, step76_factor232_data, step76_factor233_data, step76_factor234_data, step76_factor235_data, step76_factor236_data, step76_factor237_data, step76_factor238_data, };
int step76_node15_factor_num_blks[] = {step76_factor228_num_blks, step76_factor230_num_blks, step76_factor231_num_blks, step76_factor232_num_blks, step76_factor233_num_blks, step76_factor234_num_blks, step76_factor235_num_blks, step76_factor236_num_blks, step76_factor237_num_blks, step76_factor238_num_blks, };
int* step76_node15_factor_A_blk_start[] = {step76_factor228_A_blk_start, step76_factor230_A_blk_start, step76_factor231_A_blk_start, step76_factor232_A_blk_start, step76_factor233_A_blk_start, step76_factor234_A_blk_start, step76_factor235_A_blk_start, step76_factor236_A_blk_start, step76_factor237_A_blk_start, step76_factor238_A_blk_start, };
int* step76_node15_factor_B_blk_start[] = {step76_factor228_B_blk_start, step76_factor230_B_blk_start, step76_factor231_B_blk_start, step76_factor232_B_blk_start, step76_factor233_B_blk_start, step76_factor234_B_blk_start, step76_factor235_B_blk_start, step76_factor236_B_blk_start, step76_factor237_B_blk_start, step76_factor238_B_blk_start, };
int* step76_node15_factor_blk_width[] = {step76_factor228_blk_width, step76_factor230_blk_width, step76_factor231_blk_width, step76_factor232_blk_width, step76_factor233_blk_width, step76_factor234_blk_width, step76_factor235_blk_width, step76_factor236_blk_width, step76_factor237_blk_width, step76_factor238_blk_width, };
const int step76_node15_parent = 16;
const int step76_node15_height = 31;
const int step76_node15_width = 30;
float step76_node15_data[930] = {0};
const int step76_node15_num_blks = 0;
int step76_node15_A_blk_start[] = {};
int step76_node15_B_blk_start[] = {};
int step76_node15_blk_width[] = {};


const int step76_node16_num_factors = 0;
const int step76_node16_relin_cost = 0;
const int step76_node16_sym_cost = 4000;
const bool step76_node16_marked = true;
const bool step76_node16_fixed = false;
int step76_node16_factor_height[] = {};
int step76_node16_factor_width[] = {};
int* step76_node16_factor_ridx[] = {};
float* step76_node16_factor_data[] = {};
int step76_node16_factor_num_blks[] = {};
int* step76_node16_factor_A_blk_start[] = {};
int* step76_node16_factor_B_blk_start[] = {};
int* step76_node16_factor_blk_width[] = {};
const int step76_node16_parent = -1;
const int step76_node16_height = 1;
const int step76_node16_width = 1;
float step76_node16_data[1] = {0};
const int step76_node16_num_blks = 0;
int step76_node16_A_blk_start[] = {};
int step76_node16_B_blk_start[] = {};
int step76_node16_blk_width[] = {};


int step76_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 462, };
int step76_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 462, };
int step76_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 108, 109, 110, 111, 112, 113, 462, };
int step76_node3_ridx[] = {
90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 294, 295, 296, 297, 298, 299, 318, 319, 320, 321, 322, 323, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 462, };
int step76_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 348, 349, 350, 351, 352, 353, 384, 385, 386, 387, 388, 389, 462, };
int step76_node5_ridx[] = {
138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 270, 271, 272, 273, 274, 275, 288, 289, 290, 291, 292, 293, 372, 373, 374, 375, 376, 377, 384, 385, 386, 387, 388, 389, 462, };
int step76_node6_ridx[] = {
162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 462, };
int step76_node7_ridx[] = {
198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 354, 355, 356, 357, 358, 359, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 462, };
int step76_node8_ridx[] = {
228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 378, 379, 380, 381, 382, 383, 462, };
int step76_node9_ridx[] = {
252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 372, 373, 374, 375, 376, 377, 384, 385, 386, 387, 388, 389, 462, };
int step76_node10_ridx[] = {
276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 372, 373, 374, 375, 376, 377, 384, 385, 386, 387, 388, 389, 462, };
int step76_node11_ridx[] = {
300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 462, };
int step76_node12_ridx[] = {
354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 462, };
int step76_node13_ridx[] = {
384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 462, };
int step76_node14_ridx[] = {
408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 462, };
int step76_node15_ridx[] = {
432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, };
int step76_node16_ridx[] = {
462, };
const int step76_nnodes = 17;
bool step76_node_marked[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, step76_node14_marked, step76_node15_marked, step76_node16_marked, };
bool step76_node_fixed[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, step76_node14_fixed, step76_node15_fixed, step76_node16_fixed, };
int step76_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_num_factors, step76_node15_num_factors, step76_node16_num_factors, };
int step76_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_relin_cost, step76_node15_relin_cost, step76_node16_relin_cost, };
int step76_node_sym_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_sym_cost, step76_node15_sym_cost, step76_node16_sym_cost, };
int* step76_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_factor_height, step76_node15_factor_height, step76_node16_factor_height, };
int* step76_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_factor_width, step76_node15_factor_width, step76_node16_factor_width, };
int** step76_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_factor_ridx, step76_node15_factor_ridx, step76_node16_factor_ridx, };
float** step76_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_factor_data, step76_node15_factor_data, step76_node16_factor_data, };
int* step76_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_factor_num_blks, step76_node15_factor_num_blks, step76_node16_factor_num_blks, };
int** step76_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_factor_A_blk_start, step76_node15_factor_A_blk_start, step76_node16_factor_A_blk_start, };
int** step76_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_factor_B_blk_start, step76_node15_factor_B_blk_start, step76_node16_factor_B_blk_start, };
int** step76_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_factor_blk_width, step76_node15_factor_blk_width, step76_node16_factor_blk_width, };
int step76_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_parent, step76_node15_parent, step76_node16_parent, };
int step76_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_height, step76_node15_height, step76_node16_height, };
int step76_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_width, step76_node15_width, step76_node16_width, };
float* step76_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_data, step76_node15_data, step76_node16_data, };
int step76_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_num_blks, step76_node15_num_blks, step76_node16_num_blks, };
int* step76_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_A_blk_start, step76_node15_A_blk_start, step76_node16_A_blk_start, };
int* step76_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_B_blk_start, step76_node15_B_blk_start, step76_node16_B_blk_start, };
int* step76_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, step76_node14_blk_width, step76_node15_blk_width, step76_node16_blk_width, };
int* step76_node_ridx[] = {step76_node0_ridx, step76_node1_ridx, step76_node2_ridx, step76_node3_ridx, step76_node4_ridx, step76_node5_ridx, step76_node6_ridx, step76_node7_ridx, step76_node8_ridx, step76_node9_ridx, step76_node10_ridx, step76_node11_ridx, step76_node12_ridx, step76_node13_ridx, step76_node14_ridx, step76_node15_ridx, step76_node16_ridx, };


float step76_x_data[463] = {};
const int step76_workspace_needed = 7992;

