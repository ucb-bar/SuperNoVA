#pragma once

const bool step17_is_reconstruct = true;

const int step17_factor32_height = 4;
const int step17_factor32_width = 3;
int step17_factor32_ridx[] = {0, 1, 2, 6, };
float step17_factor32_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step17_factor32_num_blks = 1;
int step17_factor32_A_blk_start[] = {0, };
int step17_factor32_B_blk_start[] = {0, };
int step17_factor32_blk_width[] = {3, };

const int step17_factor34_height = 4;
const int step17_factor34_width = 3;
int step17_factor34_ridx[] = {3, 4, 5, 6, };
float step17_factor34_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step17_factor34_num_blks = 1;
int step17_factor34_A_blk_start[] = {0, };
int step17_factor34_B_blk_start[] = {3, };
int step17_factor34_blk_width[] = {3, };

const int step17_factor33_height = 7;
const int step17_factor33_width = 3;
int step17_factor33_ridx[] = {21, 22, 23, 24, 25, 26, 27, };
float step17_factor33_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step17_factor33_num_blks = 1;
int step17_factor33_A_blk_start[] = {0, };
int step17_factor33_B_blk_start[] = {21, };
int step17_factor33_blk_width[] = {6, };

const int step17_factor35_height = 7;
const int step17_factor35_width = 3;
int step17_factor35_ridx[] = {0, 1, 2, 3, 4, 5, 6, };
float step17_factor35_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step17_factor35_num_blks = 1;
int step17_factor35_A_blk_start[] = {0, };
int step17_factor35_B_blk_start[] = {0, };
int step17_factor35_blk_width[] = {6, };

const int step17_node1_num_factors = 1;
const bool step17_node1_marked = false;
const bool step17_node1_fixed = true;
int step17_node1_factor_height[] = {step17_factor33_height, };
int step17_node1_factor_width[] = {step17_factor33_width, };
int* step17_node1_factor_ridx[] = {step17_factor33_ridx, };
float* step17_node1_factor_data[] = {step17_factor33_data, };
int step17_node1_factor_num_blks[] = {step17_factor33_num_blks, };
int* step17_node1_factor_A_blk_start[] = {step17_factor33_A_blk_start, };
int* step17_node1_factor_B_blk_start[] = {step17_factor33_B_blk_start, };
int* step17_node1_factor_blk_width[] = {step17_factor33_blk_width, };
const int step17_node1_parent = 2;
const int step17_node1_height = 28;
const int step17_node1_width = 24;
float step17_node1_data[] = {
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
const int step17_node1_num_blks = 1;
int step17_node1_A_blk_start[] = {0, };
int step17_node1_B_blk_start[] = {0, };
int step17_node1_blk_width[] = {3, };


const int step17_node2_num_factors = 3;
const bool step17_node2_marked = true;
const bool step17_node2_fixed = false;
int step17_node2_factor_height[] = {step17_factor32_height, step17_factor34_height, step17_factor35_height, };
int step17_node2_factor_width[] = {step17_factor32_width, step17_factor34_width, step17_factor35_width, };
int* step17_node2_factor_ridx[] = {step17_factor32_ridx, step17_factor34_ridx, step17_factor35_ridx, };
float* step17_node2_factor_data[] = {step17_factor32_data, step17_factor34_data, step17_factor35_data, };
int step17_node2_factor_num_blks[] = {step17_factor32_num_blks, step17_factor34_num_blks, step17_factor35_num_blks, };
int* step17_node2_factor_A_blk_start[] = {step17_factor32_A_blk_start, step17_factor34_A_blk_start, step17_factor35_A_blk_start, };
int* step17_node2_factor_B_blk_start[] = {step17_factor32_B_blk_start, step17_factor34_B_blk_start, step17_factor35_B_blk_start, };
int* step17_node2_factor_blk_width[] = {step17_factor32_blk_width, step17_factor34_blk_width, step17_factor35_blk_width, };
const int step17_node2_parent = 3;
const int step17_node2_height = 7;
const int step17_node2_width = 6;
float step17_node2_data[] = {
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
};
const int step17_node2_num_blks = 0;
int step17_node2_A_blk_start[] = {};
int step17_node2_B_blk_start[] = {};
int step17_node2_blk_width[] = {};


const int step17_node3_num_factors = 0;
const bool step17_node3_marked = true;
const bool step17_node3_fixed = false;
int step17_node3_factor_height[] = {};
int step17_node3_factor_width[] = {};
int* step17_node3_factor_ridx[] = {};
float* step17_node3_factor_data[] = {};
int step17_node3_factor_num_blks[] = {};
int* step17_node3_factor_A_blk_start[] = {};
int* step17_node3_factor_B_blk_start[] = {};
int* step17_node3_factor_blk_width[] = {};
const int step17_node3_parent = -1;
const int step17_node3_height = 1;
const int step17_node3_width = 1;
float step17_node3_data[] = {
0, 
};
const int step17_node3_num_blks = 0;
int step17_node3_A_blk_start[] = {};
int step17_node3_B_blk_start[] = {};
int step17_node3_blk_width[] = {};


int step17_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 54, };
int step17_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 54, };
int step17_node2_ridx[] = {
48, 49, 50, 51, 52, 53, 54, };
int step17_node3_ridx[] = {
54, };
const int step17_nnodes = 4;
bool step17_node_marked[] = {false, step17_node1_marked, step17_node2_marked, step17_node3_marked, };
bool step17_node_fixed[] = {false, step17_node1_fixed, step17_node2_fixed, step17_node3_fixed, };
int step17_node_num_factors[] = {0, step17_node1_num_factors, step17_node2_num_factors, step17_node3_num_factors, };
int* step17_node_factor_height[] = {0, step17_node1_factor_height, step17_node2_factor_height, step17_node3_factor_height, };
int* step17_node_factor_width[] = {0, step17_node1_factor_width, step17_node2_factor_width, step17_node3_factor_width, };
int** step17_node_factor_ridx[] = {0, step17_node1_factor_ridx, step17_node2_factor_ridx, step17_node3_factor_ridx, };
float** step17_node_factor_data[] = {0, step17_node1_factor_data, step17_node2_factor_data, step17_node3_factor_data, };
int* step17_node_factor_num_blks[] = {0, step17_node1_factor_num_blks, step17_node2_factor_num_blks, step17_node3_factor_num_blks, };
int** step17_node_factor_A_blk_start[] = {0, step17_node1_factor_A_blk_start, step17_node2_factor_A_blk_start, step17_node3_factor_A_blk_start, };
int** step17_node_factor_B_blk_start[] = {0, step17_node1_factor_B_blk_start, step17_node2_factor_B_blk_start, step17_node3_factor_B_blk_start, };
int** step17_node_factor_blk_width[] = {0, step17_node1_factor_blk_width, step17_node2_factor_blk_width, step17_node3_factor_blk_width, };
int step17_node_parent[] = {0, step17_node1_parent, step17_node2_parent, step17_node3_parent, };
int step17_node_height[] = {0, step17_node1_height, step17_node2_height, step17_node3_height, };
int step17_node_width[] = {0, step17_node1_width, step17_node2_width, step17_node3_width, };
float* step17_node_data[] = {0, step17_node1_data, step17_node2_data, step17_node3_data, };
int step17_node_num_blks[] = {0, step17_node1_num_blks, step17_node2_num_blks, step17_node3_num_blks, };
int* step17_node_A_blk_start[] = {0, step17_node1_A_blk_start, step17_node2_A_blk_start, step17_node3_A_blk_start, };
int* step17_node_B_blk_start[] = {0, step17_node1_B_blk_start, step17_node2_B_blk_start, step17_node3_B_blk_start, };
int* step17_node_blk_width[] = {0, step17_node1_blk_width, step17_node2_blk_width, step17_node3_blk_width, };
int* step17_node_ridx[] = {step17_node0_ridx, step17_node1_ridx, step17_node2_ridx, step17_node3_ridx, };


float step17_x_data[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
