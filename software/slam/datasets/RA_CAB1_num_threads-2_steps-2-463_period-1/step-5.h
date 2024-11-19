#pragma once

const bool step5_is_reconstruct = true;

const int step5_num_threads = 1;

const uint64_t step5_scaled_relin_cost = 0;

const bool step5_run_model = false;

const int step5_factor9_height = 7;
const int step5_factor9_width = 6;
int step5_factor9_ridx[] = {0, 1, 2, 3, 4, 5, 12, };
float step5_factor9_data[42] = {0};

const int step5_factor9_num_blks = 1;
int step5_factor9_A_blk_start[] = {0, };
int step5_factor9_B_blk_start[] = {0, };
int step5_factor9_blk_width[] = {6, };

const int step5_factor12_height = 13;
const int step5_factor12_width = 6;
int step5_factor12_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, };
float step5_factor12_data[78] = {0};

const int step5_factor12_num_blks = 1;
int step5_factor12_A_blk_start[] = {0, };
int step5_factor12_B_blk_start[] = {0, };
int step5_factor12_blk_width[] = {12, };

const int step5_factor10_height = 13;
const int step5_factor10_width = 6;
int step5_factor10_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step5_factor10_data[78] = {0};

const int step5_factor10_num_blks = 1;
int step5_factor10_A_blk_start[] = {0, };
int step5_factor10_B_blk_start[] = {18, };
int step5_factor10_blk_width[] = {12, };

const int step5_factor11_height = 7;
const int step5_factor11_width = 6;
int step5_factor11_ridx[] = {6, 7, 8, 9, 10, 11, 12, };
float step5_factor11_data[42] = {0};

const int step5_factor11_num_blks = 1;
int step5_factor11_A_blk_start[] = {0, };
int step5_factor11_B_blk_start[] = {6, };
int step5_factor11_blk_width[] = {6, };

const int step5_node0_num_factors = 1;
const int step5_node0_relin_cost = 0;
const int step5_node0_sym_cost = 16000;
const bool step5_node0_marked = false;
const bool step5_node0_fixed = true;
int step5_node0_factor_height[] = {step5_factor10_height, };
int step5_node0_factor_width[] = {step5_factor10_width, };
int* step5_node0_factor_ridx[] = {step5_factor10_ridx, };
float* step5_node0_factor_data[] = {step5_factor10_data, };
int step5_node0_factor_num_blks[] = {step5_factor10_num_blks, };
int* step5_node0_factor_A_blk_start[] = {step5_factor10_A_blk_start, };
int* step5_node0_factor_B_blk_start[] = {step5_factor10_B_blk_start, };
int* step5_node0_factor_blk_width[] = {step5_factor10_blk_width, };
const int step5_node0_parent = 1;
const int step5_node0_height = 31;
const int step5_node0_width = 24;
float step5_node0_data[744] = {0};
const int step5_node0_num_blks = 1;
int step5_node0_A_blk_start[] = {0, };
int step5_node0_B_blk_start[] = {0, };
int step5_node0_blk_width[] = {6, };


const int step5_node1_num_factors = 3;
const int step5_node1_relin_cost = 0;
const int step5_node1_sym_cost = 8000;
const bool step5_node1_marked = true;
const bool step5_node1_fixed = false;
int step5_node1_factor_height[] = {step5_factor9_height, step5_factor11_height, step5_factor12_height, };
int step5_node1_factor_width[] = {step5_factor9_width, step5_factor11_width, step5_factor12_width, };
int* step5_node1_factor_ridx[] = {step5_factor9_ridx, step5_factor11_ridx, step5_factor12_ridx, };
float* step5_node1_factor_data[] = {step5_factor9_data, step5_factor11_data, step5_factor12_data, };
int step5_node1_factor_num_blks[] = {step5_factor9_num_blks, step5_factor11_num_blks, step5_factor12_num_blks, };
int* step5_node1_factor_A_blk_start[] = {step5_factor9_A_blk_start, step5_factor11_A_blk_start, step5_factor12_A_blk_start, };
int* step5_node1_factor_B_blk_start[] = {step5_factor9_B_blk_start, step5_factor11_B_blk_start, step5_factor12_B_blk_start, };
int* step5_node1_factor_blk_width[] = {step5_factor9_blk_width, step5_factor11_blk_width, step5_factor12_blk_width, };
const int step5_node1_parent = 2;
const int step5_node1_height = 13;
const int step5_node1_width = 12;
float step5_node1_data[156] = {0};
const int step5_node1_num_blks = 0;
int step5_node1_A_blk_start[] = {};
int step5_node1_B_blk_start[] = {};
int step5_node1_blk_width[] = {};


const int step5_node2_num_factors = 0;
const int step5_node2_relin_cost = 0;
const int step5_node2_sym_cost = 4000;
const bool step5_node2_marked = true;
const bool step5_node2_fixed = false;
int step5_node2_factor_height[] = {};
int step5_node2_factor_width[] = {};
int* step5_node2_factor_ridx[] = {};
float* step5_node2_factor_data[] = {};
int step5_node2_factor_num_blks[] = {};
int* step5_node2_factor_A_blk_start[] = {};
int* step5_node2_factor_B_blk_start[] = {};
int* step5_node2_factor_blk_width[] = {};
const int step5_node2_parent = -1;
const int step5_node2_height = 1;
const int step5_node2_width = 1;
float step5_node2_data[1] = {0};
const int step5_node2_num_blks = 0;
int step5_node2_A_blk_start[] = {};
int step5_node2_B_blk_start[] = {};
int step5_node2_blk_width[] = {};


int step5_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 36, };
int step5_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, };
int step5_node2_ridx[] = {
36, };
const int step5_nnodes = 3;
bool step5_node_marked[] = {step5_node0_marked, step5_node1_marked, step5_node2_marked, };
bool step5_node_fixed[] = {step5_node0_fixed, step5_node1_fixed, step5_node2_fixed, };
int step5_node_num_factors[] = {step5_node0_num_factors, step5_node1_num_factors, step5_node2_num_factors, };
int step5_node_relin_cost[] = {step5_node0_relin_cost, step5_node1_relin_cost, step5_node2_relin_cost, };
int step5_node_sym_cost[] = {step5_node0_sym_cost, step5_node1_sym_cost, step5_node2_sym_cost, };
int* step5_node_factor_height[] = {step5_node0_factor_height, step5_node1_factor_height, step5_node2_factor_height, };
int* step5_node_factor_width[] = {step5_node0_factor_width, step5_node1_factor_width, step5_node2_factor_width, };
int** step5_node_factor_ridx[] = {step5_node0_factor_ridx, step5_node1_factor_ridx, step5_node2_factor_ridx, };
float** step5_node_factor_data[] = {step5_node0_factor_data, step5_node1_factor_data, step5_node2_factor_data, };
int* step5_node_factor_num_blks[] = {step5_node0_factor_num_blks, step5_node1_factor_num_blks, step5_node2_factor_num_blks, };
int** step5_node_factor_A_blk_start[] = {step5_node0_factor_A_blk_start, step5_node1_factor_A_blk_start, step5_node2_factor_A_blk_start, };
int** step5_node_factor_B_blk_start[] = {step5_node0_factor_B_blk_start, step5_node1_factor_B_blk_start, step5_node2_factor_B_blk_start, };
int** step5_node_factor_blk_width[] = {step5_node0_factor_blk_width, step5_node1_factor_blk_width, step5_node2_factor_blk_width, };
int step5_node_parent[] = {step5_node0_parent, step5_node1_parent, step5_node2_parent, };
int step5_node_height[] = {step5_node0_height, step5_node1_height, step5_node2_height, };
int step5_node_width[] = {step5_node0_width, step5_node1_width, step5_node2_width, };
float* step5_node_data[] = {step5_node0_data, step5_node1_data, step5_node2_data, };
int step5_node_num_blks[] = {step5_node0_num_blks, step5_node1_num_blks, step5_node2_num_blks, };
int* step5_node_A_blk_start[] = {step5_node0_A_blk_start, step5_node1_A_blk_start, step5_node2_A_blk_start, };
int* step5_node_B_blk_start[] = {step5_node0_B_blk_start, step5_node1_B_blk_start, step5_node2_B_blk_start, };
int* step5_node_blk_width[] = {step5_node0_blk_width, step5_node1_blk_width, step5_node2_blk_width, };
int* step5_node_ridx[] = {step5_node0_ridx, step5_node1_ridx, step5_node2_ridx, };


float step5_x_data[37] = {};
const int step5_workspace_needed = 4824;

