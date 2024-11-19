#pragma once

const bool step18_is_reconstruct = true;

const int step18_factor34_height = 4;
const int step18_factor34_width = 3;
int step18_factor34_ridx[] = {3, 4, 5, 9, };
float step18_factor34_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step18_factor34_num_blks = 1;
int step18_factor34_A_blk_start[] = {0, };
int step18_factor34_B_blk_start[] = {3, };
int step18_factor34_blk_width[] = {3, };

const int step18_factor35_height = 7;
const int step18_factor35_width = 3;
int step18_factor35_ridx[] = {0, 1, 2, 3, 4, 5, 9, };
float step18_factor35_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step18_factor35_num_blks = 1;
int step18_factor35_A_blk_start[] = {0, };
int step18_factor35_B_blk_start[] = {0, };
int step18_factor35_blk_width[] = {6, };

const int step18_factor33_height = 7;
const int step18_factor33_width = 3;
int step18_factor33_ridx[] = {21, 22, 23, 24, 25, 26, 27, };
float step18_factor33_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step18_factor33_num_blks = 1;
int step18_factor33_A_blk_start[] = {0, };
int step18_factor33_B_blk_start[] = {21, };
int step18_factor33_blk_width[] = {6, };

const int step18_factor36_height = 4;
const int step18_factor36_width = 3;
int step18_factor36_ridx[] = {6, 7, 8, 9, };
float step18_factor36_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step18_factor36_num_blks = 1;
int step18_factor36_A_blk_start[] = {0, };
int step18_factor36_B_blk_start[] = {6, };
int step18_factor36_blk_width[] = {3, };

const int step18_factor37_height = 7;
const int step18_factor37_width = 3;
int step18_factor37_ridx[] = {3, 4, 5, 6, 7, 8, 9, };
float step18_factor37_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step18_factor37_num_blks = 1;
int step18_factor37_A_blk_start[] = {0, };
int step18_factor37_B_blk_start[] = {3, };
int step18_factor37_blk_width[] = {6, };

const int step18_factor32_height = 4;
const int step18_factor32_width = 3;
int step18_factor32_ridx[] = {0, 1, 2, 9, };
float step18_factor32_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step18_factor32_num_blks = 1;
int step18_factor32_A_blk_start[] = {0, };
int step18_factor32_B_blk_start[] = {0, };
int step18_factor32_blk_width[] = {3, };

const int step18_node1_num_factors = 1;
const bool step18_node1_marked = false;
const bool step18_node1_fixed = true;
int step18_node1_factor_height[] = {step18_factor33_height, };
int step18_node1_factor_width[] = {step18_factor33_width, };
int* step18_node1_factor_ridx[] = {step18_factor33_ridx, };
float* step18_node1_factor_data[] = {step18_factor33_data, };
int step18_node1_factor_num_blks[] = {step18_factor33_num_blks, };
int* step18_node1_factor_A_blk_start[] = {step18_factor33_A_blk_start, };
int* step18_node1_factor_B_blk_start[] = {step18_factor33_B_blk_start, };
int* step18_node1_factor_blk_width[] = {step18_factor33_blk_width, };
const int step18_node1_parent = 2;
const int step18_node1_height = 28;
const int step18_node1_width = 24;
float step18_node1_data[] = {
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
};
const int step18_node1_num_blks = 1;
int step18_node1_A_blk_start[] = {0, };
int step18_node1_B_blk_start[] = {0, };
int step18_node1_blk_width[] = {3, };


const int step18_node2_num_factors = 5;
const bool step18_node2_marked = true;
const bool step18_node2_fixed = false;
int step18_node2_factor_height[] = {step18_factor32_height, step18_factor34_height, step18_factor35_height, step18_factor36_height, step18_factor37_height, };
int step18_node2_factor_width[] = {step18_factor32_width, step18_factor34_width, step18_factor35_width, step18_factor36_width, step18_factor37_width, };
int* step18_node2_factor_ridx[] = {step18_factor32_ridx, step18_factor34_ridx, step18_factor35_ridx, step18_factor36_ridx, step18_factor37_ridx, };
float* step18_node2_factor_data[] = {step18_factor32_data, step18_factor34_data, step18_factor35_data, step18_factor36_data, step18_factor37_data, };
int step18_node2_factor_num_blks[] = {step18_factor32_num_blks, step18_factor34_num_blks, step18_factor35_num_blks, step18_factor36_num_blks, step18_factor37_num_blks, };
int* step18_node2_factor_A_blk_start[] = {step18_factor32_A_blk_start, step18_factor34_A_blk_start, step18_factor35_A_blk_start, step18_factor36_A_blk_start, step18_factor37_A_blk_start, };
int* step18_node2_factor_B_blk_start[] = {step18_factor32_B_blk_start, step18_factor34_B_blk_start, step18_factor35_B_blk_start, step18_factor36_B_blk_start, step18_factor37_B_blk_start, };
int* step18_node2_factor_blk_width[] = {step18_factor32_blk_width, step18_factor34_blk_width, step18_factor35_blk_width, step18_factor36_blk_width, step18_factor37_blk_width, };
const int step18_node2_parent = 3;
const int step18_node2_height = 10;
const int step18_node2_width = 9;
float step18_node2_data[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
};
const int step18_node2_num_blks = 0;
int step18_node2_A_blk_start[] = {};
int step18_node2_B_blk_start[] = {};
int step18_node2_blk_width[] = {};


const int step18_node3_num_factors = 0;
const bool step18_node3_marked = true;
const bool step18_node3_fixed = false;
int step18_node3_factor_height[] = {};
int step18_node3_factor_width[] = {};
int* step18_node3_factor_ridx[] = {};
float* step18_node3_factor_data[] = {};
int step18_node3_factor_num_blks[] = {};
int* step18_node3_factor_A_blk_start[] = {};
int* step18_node3_factor_B_blk_start[] = {};
int* step18_node3_factor_blk_width[] = {};
const int step18_node3_parent = -1;
const int step18_node3_height = 1;
const int step18_node3_width = 1;
float step18_node3_data[] = {
0, 
};
const int step18_node3_num_blks = 0;
int step18_node3_A_blk_start[] = {};
int step18_node3_B_blk_start[] = {};
int step18_node3_blk_width[] = {};


int step18_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 57, };
int step18_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 57, };
int step18_node2_ridx[] = {
48, 49, 50, 51, 52, 53, 54, 55, 56, 57, };
int step18_node3_ridx[] = {
57, };
const int step18_nnodes = 4;
bool step18_node_marked[] = {false, step18_node1_marked, step18_node2_marked, step18_node3_marked, };
bool step18_node_fixed[] = {false, step18_node1_fixed, step18_node2_fixed, step18_node3_fixed, };
int step18_node_num_factors[] = {0, step18_node1_num_factors, step18_node2_num_factors, step18_node3_num_factors, };
int* step18_node_factor_height[] = {0, step18_node1_factor_height, step18_node2_factor_height, step18_node3_factor_height, };
int* step18_node_factor_width[] = {0, step18_node1_factor_width, step18_node2_factor_width, step18_node3_factor_width, };
int** step18_node_factor_ridx[] = {0, step18_node1_factor_ridx, step18_node2_factor_ridx, step18_node3_factor_ridx, };
float** step18_node_factor_data[] = {0, step18_node1_factor_data, step18_node2_factor_data, step18_node3_factor_data, };
int* step18_node_factor_num_blks[] = {0, step18_node1_factor_num_blks, step18_node2_factor_num_blks, step18_node3_factor_num_blks, };
int** step18_node_factor_A_blk_start[] = {0, step18_node1_factor_A_blk_start, step18_node2_factor_A_blk_start, step18_node3_factor_A_blk_start, };
int** step18_node_factor_B_blk_start[] = {0, step18_node1_factor_B_blk_start, step18_node2_factor_B_blk_start, step18_node3_factor_B_blk_start, };
int** step18_node_factor_blk_width[] = {0, step18_node1_factor_blk_width, step18_node2_factor_blk_width, step18_node3_factor_blk_width, };
int step18_node_parent[] = {0, step18_node1_parent, step18_node2_parent, step18_node3_parent, };
int step18_node_height[] = {0, step18_node1_height, step18_node2_height, step18_node3_height, };
int step18_node_width[] = {0, step18_node1_width, step18_node2_width, step18_node3_width, };
float* step18_node_data[] = {0, step18_node1_data, step18_node2_data, step18_node3_data, };
int step18_node_num_blks[] = {0, step18_node1_num_blks, step18_node2_num_blks, step18_node3_num_blks, };
int* step18_node_A_blk_start[] = {0, step18_node1_A_blk_start, step18_node2_A_blk_start, step18_node3_A_blk_start, };
int* step18_node_B_blk_start[] = {0, step18_node1_B_blk_start, step18_node2_B_blk_start, step18_node3_B_blk_start, };
int* step18_node_blk_width[] = {0, step18_node1_blk_width, step18_node2_blk_width, step18_node3_blk_width, };
int* step18_node_ridx[] = {step18_node0_ridx, step18_node1_ridx, step18_node2_ridx, step18_node3_ridx, };


float step18_x_data[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
