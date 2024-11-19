#pragma once

const bool step9_is_reconstruct = true;

const int step9_factor16_height = 4;
const int step9_factor16_width = 3;
int step9_factor16_ridx[] = {0, 1, 2, 6, };
float step9_factor16_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step9_factor16_num_blks = 1;
int step9_factor16_A_blk_start[] = {0, };
int step9_factor16_B_blk_start[] = {0, };
int step9_factor16_blk_width[] = {3, };

const int step9_factor19_height = 7;
const int step9_factor19_width = 3;
int step9_factor19_ridx[] = {0, 1, 2, 3, 4, 5, 6, };
float step9_factor19_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step9_factor19_num_blks = 1;
int step9_factor19_A_blk_start[] = {0, };
int step9_factor19_B_blk_start[] = {0, };
int step9_factor19_blk_width[] = {6, };

const int step9_factor18_height = 4;
const int step9_factor18_width = 3;
int step9_factor18_ridx[] = {3, 4, 5, 6, };
float step9_factor18_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step9_factor18_num_blks = 1;
int step9_factor18_A_blk_start[] = {0, };
int step9_factor18_B_blk_start[] = {3, };
int step9_factor18_blk_width[] = {3, };

const int step9_factor17_height = 7;
const int step9_factor17_width = 3;
int step9_factor17_ridx[] = {21, 22, 23, 24, 25, 26, 27, };
float step9_factor17_data[] = {
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 
};

const int step9_factor17_num_blks = 1;
int step9_factor17_A_blk_start[] = {0, };
int step9_factor17_B_blk_start[] = {21, };
int step9_factor17_blk_width[] = {6, };

const int step9_node0_num_factors = 1;
const bool step9_node0_marked = false;
const bool step9_node0_fixed = true;
int step9_node0_factor_height[] = {step9_factor17_height, };
int step9_node0_factor_width[] = {step9_factor17_width, };
int* step9_node0_factor_ridx[] = {step9_factor17_ridx, };
float* step9_node0_factor_data[] = {step9_factor17_data, };
int step9_node0_factor_num_blks[] = {step9_factor17_num_blks, };
int* step9_node0_factor_A_blk_start[] = {step9_factor17_A_blk_start, };
int* step9_node0_factor_B_blk_start[] = {step9_factor17_B_blk_start, };
int* step9_node0_factor_blk_width[] = {step9_factor17_blk_width, };
const int step9_node0_parent = 1;
const int step9_node0_height = 28;
const int step9_node0_width = 24;
float step9_node0_data[] = {
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
const int step9_node0_num_blks = 1;
int step9_node0_A_blk_start[] = {0, };
int step9_node0_B_blk_start[] = {0, };
int step9_node0_blk_width[] = {3, };


const int step9_node1_num_factors = 3;
const bool step9_node1_marked = true;
const bool step9_node1_fixed = false;
int step9_node1_factor_height[] = {step9_factor16_height, step9_factor18_height, step9_factor19_height, };
int step9_node1_factor_width[] = {step9_factor16_width, step9_factor18_width, step9_factor19_width, };
int* step9_node1_factor_ridx[] = {step9_factor16_ridx, step9_factor18_ridx, step9_factor19_ridx, };
float* step9_node1_factor_data[] = {step9_factor16_data, step9_factor18_data, step9_factor19_data, };
int step9_node1_factor_num_blks[] = {step9_factor16_num_blks, step9_factor18_num_blks, step9_factor19_num_blks, };
int* step9_node1_factor_A_blk_start[] = {step9_factor16_A_blk_start, step9_factor18_A_blk_start, step9_factor19_A_blk_start, };
int* step9_node1_factor_B_blk_start[] = {step9_factor16_B_blk_start, step9_factor18_B_blk_start, step9_factor19_B_blk_start, };
int* step9_node1_factor_blk_width[] = {step9_factor16_blk_width, step9_factor18_blk_width, step9_factor19_blk_width, };
const int step9_node1_parent = 2;
const int step9_node1_height = 7;
const int step9_node1_width = 6;
float step9_node1_data[] = {
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 
};
const int step9_node1_num_blks = 0;
int step9_node1_A_blk_start[] = {};
int step9_node1_B_blk_start[] = {};
int step9_node1_blk_width[] = {};


const int step9_node2_num_factors = 0;
const bool step9_node2_marked = true;
const bool step9_node2_fixed = false;
int step9_node2_factor_height[] = {};
int step9_node2_factor_width[] = {};
int* step9_node2_factor_ridx[] = {};
float* step9_node2_factor_data[] = {};
int step9_node2_factor_num_blks[] = {};
int* step9_node2_factor_A_blk_start[] = {};
int* step9_node2_factor_B_blk_start[] = {};
int* step9_node2_factor_blk_width[] = {};
const int step9_node2_parent = -1;
const int step9_node2_height = 1;
const int step9_node2_width = 1;
float step9_node2_data[] = {
0, 
};
const int step9_node2_num_blks = 0;
int step9_node2_A_blk_start[] = {};
int step9_node2_B_blk_start[] = {};
int step9_node2_blk_width[] = {};


int step9_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 30, };
int step9_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, };
int step9_node2_ridx[] = {
30, };
const int step9_nnodes = 3;
bool step9_node_marked[] = {step9_node0_marked, step9_node1_marked, step9_node2_marked, };
bool step9_node_fixed[] = {step9_node0_fixed, step9_node1_fixed, step9_node2_fixed, };
int step9_node_num_factors[] = {step9_node0_num_factors, step9_node1_num_factors, step9_node2_num_factors, };
int* step9_node_factor_height[] = {step9_node0_factor_height, step9_node1_factor_height, step9_node2_factor_height, };
int* step9_node_factor_width[] = {step9_node0_factor_width, step9_node1_factor_width, step9_node2_factor_width, };
int** step9_node_factor_ridx[] = {step9_node0_factor_ridx, step9_node1_factor_ridx, step9_node2_factor_ridx, };
float** step9_node_factor_data[] = {step9_node0_factor_data, step9_node1_factor_data, step9_node2_factor_data, };
int* step9_node_factor_num_blks[] = {step9_node0_factor_num_blks, step9_node1_factor_num_blks, step9_node2_factor_num_blks, };
int** step9_node_factor_A_blk_start[] = {step9_node0_factor_A_blk_start, step9_node1_factor_A_blk_start, step9_node2_factor_A_blk_start, };
int** step9_node_factor_B_blk_start[] = {step9_node0_factor_B_blk_start, step9_node1_factor_B_blk_start, step9_node2_factor_B_blk_start, };
int** step9_node_factor_blk_width[] = {step9_node0_factor_blk_width, step9_node1_factor_blk_width, step9_node2_factor_blk_width, };
int step9_node_parent[] = {step9_node0_parent, step9_node1_parent, step9_node2_parent, };
int step9_node_height[] = {step9_node0_height, step9_node1_height, step9_node2_height, };
int step9_node_width[] = {step9_node0_width, step9_node1_width, step9_node2_width, };
float* step9_node_data[] = {step9_node0_data, step9_node1_data, step9_node2_data, };
int step9_node_num_blks[] = {step9_node0_num_blks, step9_node1_num_blks, step9_node2_num_blks, };
int* step9_node_A_blk_start[] = {step9_node0_A_blk_start, step9_node1_A_blk_start, step9_node2_A_blk_start, };
int* step9_node_B_blk_start[] = {step9_node0_B_blk_start, step9_node1_B_blk_start, step9_node2_B_blk_start, };
int* step9_node_blk_width[] = {step9_node0_blk_width, step9_node1_blk_width, step9_node2_blk_width, };
int* step9_node_ridx[] = {step9_node0_ridx, step9_node1_ridx, step9_node2_ridx, };


float step9_x_data[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
