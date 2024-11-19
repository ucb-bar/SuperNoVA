#pragma once

const bool step53_is_reconstruct = true;

const int step53_num_threads = 1;

const uint64_t step53_scaled_relin_cost = 140000;

const bool step53_run_model = false;

const int step53_factor183_height = 13;
const int step53_factor183_width = 6;
int step53_factor183_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, };
float step53_factor183_data[78] = {0};

const int step53_factor183_num_blks = 1;
int step53_factor183_A_blk_start[] = {0, };
int step53_factor183_B_blk_start[] = {0, };
int step53_factor183_blk_width[] = {12, };

const int step53_factor175_height = 7;
const int step53_factor175_width = 6;
int step53_factor175_ridx[] = {0, 1, 2, 3, 4, 5, 12, };
float step53_factor175_data[42] = {0};

const int step53_factor175_num_blks = 1;
int step53_factor175_A_blk_start[] = {0, };
int step53_factor175_B_blk_start[] = {0, };
int step53_factor175_blk_width[] = {6, };

const int step53_factor176_height = 13;
const int step53_factor176_width = 6;
int step53_factor176_ridx[] = {36, 37, 38, 39, 40, 41, 60, 61, 62, 63, 64, 65, 66, };
float step53_factor176_data[78] = {0};

const int step53_factor176_num_blks = 2;
int step53_factor176_A_blk_start[] = {0, 6, };
int step53_factor176_B_blk_start[] = {36, 60, };
int step53_factor176_blk_width[] = {6, 6, };

const int step53_factor177_height = 13;
const int step53_factor177_width = 6;
int step53_factor177_ridx[] = {42, 43, 44, 45, 46, 47, 60, 61, 62, 63, 64, 65, 66, };
float step53_factor177_data[78] = {0};

const int step53_factor177_num_blks = 2;
int step53_factor177_A_blk_start[] = {0, 6, };
int step53_factor177_B_blk_start[] = {42, 60, };
int step53_factor177_blk_width[] = {6, 6, };

const int step53_factor178_height = 13;
const int step53_factor178_width = 6;
int step53_factor178_ridx[] = {48, 49, 50, 51, 52, 53, 60, 61, 62, 63, 64, 65, 66, };
float step53_factor178_data[78] = {0};

const int step53_factor178_num_blks = 2;
int step53_factor178_A_blk_start[] = {0, 6, };
int step53_factor178_B_blk_start[] = {48, 60, };
int step53_factor178_blk_width[] = {6, 6, };

const int step53_factor179_height = 13;
const int step53_factor179_width = 6;
int step53_factor179_ridx[] = {54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, };
float step53_factor179_data[78] = {0};

const int step53_factor179_num_blks = 1;
int step53_factor179_A_blk_start[] = {0, };
int step53_factor179_B_blk_start[] = {54, };
int step53_factor179_blk_width[] = {12, };

const int step53_factor180_height = 13;
const int step53_factor180_width = 6;
int step53_factor180_ridx[] = {24, 25, 26, 27, 28, 29, 60, 61, 62, 63, 64, 65, 66, };
float step53_factor180_data[78] = {0};

const int step53_factor180_num_blks = 2;
int step53_factor180_A_blk_start[] = {0, 6, };
int step53_factor180_B_blk_start[] = {24, 60, };
int step53_factor180_blk_width[] = {6, 6, };

const int step53_factor181_height = 13;
const int step53_factor181_width = 6;
int step53_factor181_ridx[] = {30, 31, 32, 33, 34, 35, 60, 61, 62, 63, 64, 65, 66, };
float step53_factor181_data[78] = {0};

const int step53_factor181_num_blks = 2;
int step53_factor181_A_blk_start[] = {0, 6, };
int step53_factor181_B_blk_start[] = {30, 60, };
int step53_factor181_blk_width[] = {6, 6, };

const int step53_factor182_height = 7;
const int step53_factor182_width = 6;
int step53_factor182_ridx[] = {6, 7, 8, 9, 10, 11, 12, };
float step53_factor182_data[42] = {0};

const int step53_factor182_num_blks = 1;
int step53_factor182_A_blk_start[] = {0, };
int step53_factor182_B_blk_start[] = {6, };
int step53_factor182_blk_width[] = {6, };

const int step53_node9_num_factors = 6;
const int step53_node9_relin_cost = 120000;
const int step53_node9_sym_cost = 40000;
const bool step53_node9_marked = false;
const bool step53_node9_fixed = true;
int step53_node9_factor_height[] = {step53_factor176_height, step53_factor177_height, step53_factor178_height, step53_factor179_height, step53_factor180_height, step53_factor181_height, };
int step53_node9_factor_width[] = {step53_factor176_width, step53_factor177_width, step53_factor178_width, step53_factor179_width, step53_factor180_width, step53_factor181_width, };
int* step53_node9_factor_ridx[] = {step53_factor176_ridx, step53_factor177_ridx, step53_factor178_ridx, step53_factor179_ridx, step53_factor180_ridx, step53_factor181_ridx, };
float* step53_node9_factor_data[] = {step53_factor176_data, step53_factor177_data, step53_factor178_data, step53_factor179_data, step53_factor180_data, step53_factor181_data, };
int step53_node9_factor_num_blks[] = {step53_factor176_num_blks, step53_factor177_num_blks, step53_factor178_num_blks, step53_factor179_num_blks, step53_factor180_num_blks, step53_factor181_num_blks, };
int* step53_node9_factor_A_blk_start[] = {step53_factor176_A_blk_start, step53_factor177_A_blk_start, step53_factor178_A_blk_start, step53_factor179_A_blk_start, step53_factor180_A_blk_start, step53_factor181_A_blk_start, };
int* step53_node9_factor_B_blk_start[] = {step53_factor176_B_blk_start, step53_factor177_B_blk_start, step53_factor178_B_blk_start, step53_factor179_B_blk_start, step53_factor180_B_blk_start, step53_factor181_B_blk_start, };
int* step53_node9_factor_blk_width[] = {step53_factor176_blk_width, step53_factor177_blk_width, step53_factor178_blk_width, step53_factor179_blk_width, step53_factor180_blk_width, step53_factor181_blk_width, };
const int step53_node9_parent = 10;
const int step53_node9_height = 67;
const int step53_node9_width = 60;
float step53_node9_data[4020] = {0};
const int step53_node9_num_blks = 1;
int step53_node9_A_blk_start[] = {0, };
int step53_node9_B_blk_start[] = {0, };
int step53_node9_blk_width[] = {6, };


const int step53_node10_num_factors = 3;
const int step53_node10_relin_cost = 20000;
const int step53_node10_sym_cost = 8000;
const bool step53_node10_marked = true;
const bool step53_node10_fixed = false;
int step53_node10_factor_height[] = {step53_factor175_height, step53_factor182_height, step53_factor183_height, };
int step53_node10_factor_width[] = {step53_factor175_width, step53_factor182_width, step53_factor183_width, };
int* step53_node10_factor_ridx[] = {step53_factor175_ridx, step53_factor182_ridx, step53_factor183_ridx, };
float* step53_node10_factor_data[] = {step53_factor175_data, step53_factor182_data, step53_factor183_data, };
int step53_node10_factor_num_blks[] = {step53_factor175_num_blks, step53_factor182_num_blks, step53_factor183_num_blks, };
int* step53_node10_factor_A_blk_start[] = {step53_factor175_A_blk_start, step53_factor182_A_blk_start, step53_factor183_A_blk_start, };
int* step53_node10_factor_B_blk_start[] = {step53_factor175_B_blk_start, step53_factor182_B_blk_start, step53_factor183_B_blk_start, };
int* step53_node10_factor_blk_width[] = {step53_factor175_blk_width, step53_factor182_blk_width, step53_factor183_blk_width, };
const int step53_node10_parent = 11;
const int step53_node10_height = 13;
const int step53_node10_width = 12;
float step53_node10_data[156] = {0};
const int step53_node10_num_blks = 0;
int step53_node10_A_blk_start[] = {};
int step53_node10_B_blk_start[] = {};
int step53_node10_blk_width[] = {};


const int step53_node11_num_factors = 0;
const int step53_node11_relin_cost = 0;
const int step53_node11_sym_cost = 4000;
const bool step53_node11_marked = true;
const bool step53_node11_fixed = false;
int step53_node11_factor_height[] = {};
int step53_node11_factor_width[] = {};
int* step53_node11_factor_ridx[] = {};
float* step53_node11_factor_data[] = {};
int step53_node11_factor_num_blks[] = {};
int* step53_node11_factor_A_blk_start[] = {};
int* step53_node11_factor_B_blk_start[] = {};
int* step53_node11_factor_blk_width[] = {};
const int step53_node11_parent = -1;
const int step53_node11_height = 1;
const int step53_node11_width = 1;
float step53_node11_data[1] = {0};
const int step53_node11_num_blks = 0;
int step53_node11_A_blk_start[] = {};
int step53_node11_B_blk_start[] = {};
int step53_node11_blk_width[] = {};


int step53_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 324, };
int step53_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 324, };
int step53_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 108, 109, 110, 111, 112, 113, 324, };
int step53_node3_ridx[] = {
90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 246, 247, 248, 249, 250, 251, 270, 271, 272, 273, 274, 275, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 324, };
int step53_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 180, 181, 182, 183, 184, 185, 294, 295, 296, 297, 298, 299, 324, };
int step53_node5_ridx[] = {
138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 240, 241, 242, 243, 244, 245, 288, 289, 290, 291, 292, 293, 324, };
int step53_node6_ridx[] = {
162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 324, };
int step53_node7_ridx[] = {
192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 324, };
int step53_node8_ridx[] = {
228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 270, 271, 272, 273, 274, 275, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 324, };
int step53_node9_ridx[] = {
252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 324, };
int step53_node10_ridx[] = {
312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, };
int step53_node11_ridx[] = {
324, };
const int step53_nnodes = 12;
bool step53_node_marked[] = {false, false, false, false, false, false, false, false, false, step53_node9_marked, step53_node10_marked, step53_node11_marked, };
bool step53_node_fixed[] = {false, false, false, false, false, false, false, false, false, step53_node9_fixed, step53_node10_fixed, step53_node11_fixed, };
int step53_node_num_factors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_num_factors, step53_node10_num_factors, step53_node11_num_factors, };
int step53_node_relin_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_relin_cost, step53_node10_relin_cost, step53_node11_relin_cost, };
int step53_node_sym_cost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_sym_cost, step53_node10_sym_cost, step53_node11_sym_cost, };
int* step53_node_factor_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_factor_height, step53_node10_factor_height, step53_node11_factor_height, };
int* step53_node_factor_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_factor_width, step53_node10_factor_width, step53_node11_factor_width, };
int** step53_node_factor_ridx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_factor_ridx, step53_node10_factor_ridx, step53_node11_factor_ridx, };
float** step53_node_factor_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_factor_data, step53_node10_factor_data, step53_node11_factor_data, };
int* step53_node_factor_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_factor_num_blks, step53_node10_factor_num_blks, step53_node11_factor_num_blks, };
int** step53_node_factor_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_factor_A_blk_start, step53_node10_factor_A_blk_start, step53_node11_factor_A_blk_start, };
int** step53_node_factor_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_factor_B_blk_start, step53_node10_factor_B_blk_start, step53_node11_factor_B_blk_start, };
int** step53_node_factor_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_factor_blk_width, step53_node10_factor_blk_width, step53_node11_factor_blk_width, };
int step53_node_parent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_parent, step53_node10_parent, step53_node11_parent, };
int step53_node_height[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_height, step53_node10_height, step53_node11_height, };
int step53_node_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_width, step53_node10_width, step53_node11_width, };
float* step53_node_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_data, step53_node10_data, step53_node11_data, };
int step53_node_num_blks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_num_blks, step53_node10_num_blks, step53_node11_num_blks, };
int* step53_node_A_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_A_blk_start, step53_node10_A_blk_start, step53_node11_A_blk_start, };
int* step53_node_B_blk_start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_B_blk_start, step53_node10_B_blk_start, step53_node11_B_blk_start, };
int* step53_node_blk_width[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, step53_node9_blk_width, step53_node10_blk_width, step53_node11_blk_width, };
int* step53_node_ridx[] = {step53_node0_ridx, step53_node1_ridx, step53_node2_ridx, step53_node3_ridx, step53_node4_ridx, step53_node5_ridx, step53_node6_ridx, step53_node7_ridx, step53_node8_ridx, step53_node9_ridx, step53_node10_ridx, step53_node11_ridx, };


float step53_x_data[325] = {};
const int step53_workspace_needed = 18936;

