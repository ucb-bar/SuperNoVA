#pragma once

const bool step10_is_reconstruct = true;

const int step10_factor21_height = 7;
const int step10_factor21_width = 3;
int step10_factor21_ridx[] = {3, 4, 5, 6, 7, 8, 9, };
float step10_factor21_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step10_factor21_num_blks = 1;
int step10_factor21_A_blk_start[] = {0, };
int step10_factor21_B_blk_start[] = {3, };
int step10_factor21_blk_width[] = {6, };

const int step10_factor20_height = 4;
const int step10_factor20_width = 3;
int step10_factor20_ridx[] = {6, 7, 8, 9, };
float step10_factor20_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step10_factor20_num_blks = 1;
int step10_factor20_A_blk_start[] = {0, };
int step10_factor20_B_blk_start[] = {6, };
int step10_factor20_blk_width[] = {3, };

const int step10_factor17_height = 7;
const int step10_factor17_width = 3;
int step10_factor17_ridx[] = {21, 22, 23, 24, 25, 26, 27, };
float step10_factor17_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step10_factor17_num_blks = 1;
int step10_factor17_A_blk_start[] = {0, };
int step10_factor17_B_blk_start[] = {21, };
int step10_factor17_blk_width[] = {6, };

const int step10_factor16_height = 4;
const int step10_factor16_width = 3;
int step10_factor16_ridx[] = {0, 1, 2, 9, };
float step10_factor16_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step10_factor16_num_blks = 1;
int step10_factor16_A_blk_start[] = {0, };
int step10_factor16_B_blk_start[] = {0, };
int step10_factor16_blk_width[] = {3, };

const int step10_factor19_height = 7;
const int step10_factor19_width = 3;
int step10_factor19_ridx[] = {0, 1, 2, 3, 4, 5, 9, };
float step10_factor19_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step10_factor19_num_blks = 1;
int step10_factor19_A_blk_start[] = {0, };
int step10_factor19_B_blk_start[] = {0, };
int step10_factor19_blk_width[] = {6, };

const int step10_factor18_height = 4;
const int step10_factor18_width = 3;
int step10_factor18_ridx[] = {3, 4, 5, 9, };
float step10_factor18_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step10_factor18_num_blks = 1;
int step10_factor18_A_blk_start[] = {0, };
int step10_factor18_B_blk_start[] = {3, };
int step10_factor18_blk_width[] = {3, };

const int step10_node0_num_factors = 1;
const bool step10_node0_marked = false;
const bool step10_node0_fixed = true;
int step10_node0_factor_height[] = {step10_factor17_height, };
int step10_node0_factor_width[] = {step10_factor17_width, };
int* step10_node0_factor_ridx[] = {step10_factor17_ridx, };
float* step10_node0_factor_data[] = {step10_factor17_data, };
int step10_node0_factor_num_blks[] = {step10_factor17_num_blks, };
int* step10_node0_factor_A_blk_start[] = {step10_factor17_A_blk_start, };
int* step10_node0_factor_B_blk_start[] = {step10_factor17_B_blk_start, };
int* step10_node0_factor_blk_width[] = {step10_factor17_blk_width, };
const int step10_node0_parent = 1;
const int step10_node0_height = 28;
const int step10_node0_width = 24;
float step10_node0_data[] = {
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
const int step10_node0_num_blks = 1;
int step10_node0_A_blk_start[] = {0, };
int step10_node0_B_blk_start[] = {0, };
int step10_node0_blk_width[] = {3, };


const int step10_node1_num_factors = 5;
const bool step10_node1_marked = true;
const bool step10_node1_fixed = false;
int step10_node1_factor_height[] = {step10_factor16_height, step10_factor18_height, step10_factor19_height, step10_factor20_height, step10_factor21_height, };
int step10_node1_factor_width[] = {step10_factor16_width, step10_factor18_width, step10_factor19_width, step10_factor20_width, step10_factor21_width, };
int* step10_node1_factor_ridx[] = {step10_factor16_ridx, step10_factor18_ridx, step10_factor19_ridx, step10_factor20_ridx, step10_factor21_ridx, };
float* step10_node1_factor_data[] = {step10_factor16_data, step10_factor18_data, step10_factor19_data, step10_factor20_data, step10_factor21_data, };
int step10_node1_factor_num_blks[] = {step10_factor16_num_blks, step10_factor18_num_blks, step10_factor19_num_blks, step10_factor20_num_blks, step10_factor21_num_blks, };
int* step10_node1_factor_A_blk_start[] = {step10_factor16_A_blk_start, step10_factor18_A_blk_start, step10_factor19_A_blk_start, step10_factor20_A_blk_start, step10_factor21_A_blk_start, };
int* step10_node1_factor_B_blk_start[] = {step10_factor16_B_blk_start, step10_factor18_B_blk_start, step10_factor19_B_blk_start, step10_factor20_B_blk_start, step10_factor21_B_blk_start, };
int* step10_node1_factor_blk_width[] = {step10_factor16_blk_width, step10_factor18_blk_width, step10_factor19_blk_width, step10_factor20_blk_width, step10_factor21_blk_width, };
const int step10_node1_parent = 2;
const int step10_node1_height = 10;
const int step10_node1_width = 9;
float step10_node1_data[] = {
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
const int step10_node1_num_blks = 0;
int step10_node1_A_blk_start[] = {};
int step10_node1_B_blk_start[] = {};
int step10_node1_blk_width[] = {};


const int step10_node2_num_factors = 0;
const bool step10_node2_marked = true;
const bool step10_node2_fixed = false;
int step10_node2_factor_height[] = {};
int step10_node2_factor_width[] = {};
int* step10_node2_factor_ridx[] = {};
float* step10_node2_factor_data[] = {};
int step10_node2_factor_num_blks[] = {};
int* step10_node2_factor_A_blk_start[] = {};
int* step10_node2_factor_B_blk_start[] = {};
int* step10_node2_factor_blk_width[] = {};
const int step10_node2_parent = -1;
const int step10_node2_height = 1;
const int step10_node2_width = 1;
float step10_node2_data[] = {
0, 
};
const int step10_node2_num_blks = 0;
int step10_node2_A_blk_start[] = {};
int step10_node2_B_blk_start[] = {};
int step10_node2_blk_width[] = {};


int step10_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 33, };
int step10_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, };
int step10_node2_ridx[] = {
33, };
const int step10_nnodes = 3;
bool step10_node_marked[] = {step10_node0_marked, step10_node1_marked, step10_node2_marked, };
bool step10_node_fixed[] = {step10_node0_fixed, step10_node1_fixed, step10_node2_fixed, };
int step10_node_num_factors[] = {step10_node0_num_factors, step10_node1_num_factors, step10_node2_num_factors, };
int* step10_node_factor_height[] = {step10_node0_factor_height, step10_node1_factor_height, step10_node2_factor_height, };
int* step10_node_factor_width[] = {step10_node0_factor_width, step10_node1_factor_width, step10_node2_factor_width, };
int** step10_node_factor_ridx[] = {step10_node0_factor_ridx, step10_node1_factor_ridx, step10_node2_factor_ridx, };
float** step10_node_factor_data[] = {step10_node0_factor_data, step10_node1_factor_data, step10_node2_factor_data, };
int* step10_node_factor_num_blks[] = {step10_node0_factor_num_blks, step10_node1_factor_num_blks, step10_node2_factor_num_blks, };
int** step10_node_factor_A_blk_start[] = {step10_node0_factor_A_blk_start, step10_node1_factor_A_blk_start, step10_node2_factor_A_blk_start, };
int** step10_node_factor_B_blk_start[] = {step10_node0_factor_B_blk_start, step10_node1_factor_B_blk_start, step10_node2_factor_B_blk_start, };
int** step10_node_factor_blk_width[] = {step10_node0_factor_blk_width, step10_node1_factor_blk_width, step10_node2_factor_blk_width, };
int step10_node_parent[] = {step10_node0_parent, step10_node1_parent, step10_node2_parent, };
int step10_node_height[] = {step10_node0_height, step10_node1_height, step10_node2_height, };
int step10_node_width[] = {step10_node0_width, step10_node1_width, step10_node2_width, };
float* step10_node_data[] = {step10_node0_data, step10_node1_data, step10_node2_data, };
int step10_node_num_blks[] = {step10_node0_num_blks, step10_node1_num_blks, step10_node2_num_blks, };
int* step10_node_A_blk_start[] = {step10_node0_A_blk_start, step10_node1_A_blk_start, step10_node2_A_blk_start, };
int* step10_node_B_blk_start[] = {step10_node0_B_blk_start, step10_node1_B_blk_start, step10_node2_B_blk_start, };
int* step10_node_blk_width[] = {step10_node0_blk_width, step10_node1_blk_width, step10_node2_blk_width, };
int* step10_node_ridx[] = {step10_node0_ridx, step10_node1_ridx, step10_node2_ridx, };


float step10_x_data[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
