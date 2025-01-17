#pragma once

const bool step2_is_reconstruct = true;

const int step2_num_threads = 1;

const uint64_t step2_scaled_relin_cost = 0;

const bool step2_run_model = false;

const int step2_factor0_height = 7;
const int step2_factor0_width = 6;
int step2_factor0_ridx[] = {0, 1, 2, 3, 4, 5, 18, };
float step2_factor0_data[42] = {0};

const int step2_factor0_num_blks = 1;
int step2_factor0_A_blk_start[] = {0, };
int step2_factor0_B_blk_start[] = {0, };
int step2_factor0_blk_width[] = {6, };

const int step2_factor1_height = 7;
const int step2_factor1_width = 6;
int step2_factor1_ridx[] = {12, 13, 14, 15, 16, 17, 18, };
float step2_factor1_data[42] = {0};

const int step2_factor1_num_blks = 1;
int step2_factor1_A_blk_start[] = {0, };
int step2_factor1_B_blk_start[] = {12, };
int step2_factor1_blk_width[] = {6, };

const int step2_factor5_height = 13;
const int step2_factor5_width = 6;
int step2_factor5_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, };
float step2_factor5_data[78] = {0};

const int step2_factor5_num_blks = 1;
int step2_factor5_A_blk_start[] = {0, };
int step2_factor5_B_blk_start[] = {6, };
int step2_factor5_blk_width[] = {12, };

const int step2_factor3_height = 7;
const int step2_factor3_width = 6;
int step2_factor3_ridx[] = {0, 1, 2, 3, 4, 5, 18, };
float step2_factor3_data[42] = {0};

const int step2_factor3_num_blks = 1;
int step2_factor3_A_blk_start[] = {0, };
int step2_factor3_B_blk_start[] = {0, };
int step2_factor3_blk_width[] = {6, };

const int step2_factor4_height = 13;
const int step2_factor4_width = 6;
int step2_factor4_ridx[] = {0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 18, };
float step2_factor4_data[78] = {0};

const int step2_factor4_num_blks = 2;
int step2_factor4_A_blk_start[] = {0, 6, };
int step2_factor4_B_blk_start[] = {0, 12, };
int step2_factor4_blk_width[] = {6, 6, };

const int step2_factor6_height = 13;
const int step2_factor6_width = 6;
int step2_factor6_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 18, };
float step2_factor6_data[78] = {0};

const int step2_factor6_num_blks = 1;
int step2_factor6_A_blk_start[] = {0, };
int step2_factor6_B_blk_start[] = {0, };
int step2_factor6_blk_width[] = {12, };

const int step2_factor2_height = 7;
const int step2_factor2_width = 6;
int step2_factor2_ridx[] = {6, 7, 8, 9, 10, 11, 18, };
float step2_factor2_data[42] = {0};

const int step2_factor2_num_blks = 1;
int step2_factor2_A_blk_start[] = {0, };
int step2_factor2_B_blk_start[] = {6, };
int step2_factor2_blk_width[] = {6, };

const int step2_node0_num_factors = 7;
const int step2_node0_relin_cost = 0;
const int step2_node0_sym_cost = 6000;
const bool step2_node0_marked = true;
const bool step2_node0_fixed = false;
int step2_node0_factor_height[] = {step2_factor0_height, step2_factor1_height, step2_factor2_height, step2_factor3_height, step2_factor4_height, step2_factor5_height, step2_factor6_height, };
int step2_node0_factor_width[] = {step2_factor0_width, step2_factor1_width, step2_factor2_width, step2_factor3_width, step2_factor4_width, step2_factor5_width, step2_factor6_width, };
int* step2_node0_factor_ridx[] = {step2_factor0_ridx, step2_factor1_ridx, step2_factor2_ridx, step2_factor3_ridx, step2_factor4_ridx, step2_factor5_ridx, step2_factor6_ridx, };
float* step2_node0_factor_data[] = {step2_factor0_data, step2_factor1_data, step2_factor2_data, step2_factor3_data, step2_factor4_data, step2_factor5_data, step2_factor6_data, };
int step2_node0_factor_num_blks[] = {step2_factor0_num_blks, step2_factor1_num_blks, step2_factor2_num_blks, step2_factor3_num_blks, step2_factor4_num_blks, step2_factor5_num_blks, step2_factor6_num_blks, };
int* step2_node0_factor_A_blk_start[] = {step2_factor0_A_blk_start, step2_factor1_A_blk_start, step2_factor2_A_blk_start, step2_factor3_A_blk_start, step2_factor4_A_blk_start, step2_factor5_A_blk_start, step2_factor6_A_blk_start, };
int* step2_node0_factor_B_blk_start[] = {step2_factor0_B_blk_start, step2_factor1_B_blk_start, step2_factor2_B_blk_start, step2_factor3_B_blk_start, step2_factor4_B_blk_start, step2_factor5_B_blk_start, step2_factor6_B_blk_start, };
int* step2_node0_factor_blk_width[] = {step2_factor0_blk_width, step2_factor1_blk_width, step2_factor2_blk_width, step2_factor3_blk_width, step2_factor4_blk_width, step2_factor5_blk_width, step2_factor6_blk_width, };
const int step2_node0_parent = 1;
const int step2_node0_height = 19;
const int step2_node0_width = 18;
float step2_node0_data[342] = {0};
const int step2_node0_num_blks = 0;
int step2_node0_A_blk_start[] = {};
int step2_node0_B_blk_start[] = {};
int step2_node0_blk_width[] = {};


const int step2_node1_num_factors = 0;
const int step2_node1_relin_cost = 0;
const int step2_node1_sym_cost = 2000;
const bool step2_node1_marked = true;
const bool step2_node1_fixed = false;
int step2_node1_factor_height[] = {};
int step2_node1_factor_width[] = {};
int* step2_node1_factor_ridx[] = {};
float* step2_node1_factor_data[] = {};
int step2_node1_factor_num_blks[] = {};
int* step2_node1_factor_A_blk_start[] = {};
int* step2_node1_factor_B_blk_start[] = {};
int* step2_node1_factor_blk_width[] = {};
const int step2_node1_parent = -1;
const int step2_node1_height = 1;
const int step2_node1_width = 1;
float step2_node1_data[1] = {0};
const int step2_node1_num_blks = 0;
int step2_node1_A_blk_start[] = {};
int step2_node1_B_blk_start[] = {};
int step2_node1_blk_width[] = {};


int step2_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, };
int step2_node1_ridx[] = {
18, };
const int step2_nnodes = 2;
bool step2_node_marked[] = {step2_node0_marked, step2_node1_marked, };
bool step2_node_fixed[] = {step2_node0_fixed, step2_node1_fixed, };
int step2_node_num_factors[] = {step2_node0_num_factors, step2_node1_num_factors, };
int step2_node_relin_cost[] = {step2_node0_relin_cost, step2_node1_relin_cost, };
int step2_node_sym_cost[] = {step2_node0_sym_cost, step2_node1_sym_cost, };
int* step2_node_factor_height[] = {step2_node0_factor_height, step2_node1_factor_height, };
int* step2_node_factor_width[] = {step2_node0_factor_width, step2_node1_factor_width, };
int** step2_node_factor_ridx[] = {step2_node0_factor_ridx, step2_node1_factor_ridx, };
float** step2_node_factor_data[] = {step2_node0_factor_data, step2_node1_factor_data, };
int* step2_node_factor_num_blks[] = {step2_node0_factor_num_blks, step2_node1_factor_num_blks, };
int** step2_node_factor_A_blk_start[] = {step2_node0_factor_A_blk_start, step2_node1_factor_A_blk_start, };
int** step2_node_factor_B_blk_start[] = {step2_node0_factor_B_blk_start, step2_node1_factor_B_blk_start, };
int** step2_node_factor_blk_width[] = {step2_node0_factor_blk_width, step2_node1_factor_blk_width, };
int step2_node_parent[] = {step2_node0_parent, step2_node1_parent, };
int step2_node_height[] = {step2_node0_height, step2_node1_height, };
int step2_node_width[] = {step2_node0_width, step2_node1_width, };
float* step2_node_data[] = {step2_node0_data, step2_node1_data, };
int step2_node_num_blks[] = {step2_node0_num_blks, step2_node1_num_blks, };
int* step2_node_A_blk_start[] = {step2_node0_A_blk_start, step2_node1_A_blk_start, };
int* step2_node_B_blk_start[] = {step2_node0_B_blk_start, step2_node1_B_blk_start, };
int* step2_node_blk_width[] = {step2_node0_blk_width, step2_node1_blk_width, };
int* step2_node_ridx[] = {step2_node0_ridx, step2_node1_ridx, };


float step2_x_data[19] = {};
const int step2_workspace_needed = 1648;

