#pragma once

const bool step6_is_reconstruct = true;

const int step6_num_threads = 1;

const uint64_t step6_scaled_relin_cost = 0;

const bool step6_run_model = false;

const int step6_factor12_height = 13;
const int step6_factor12_width = 6;
int step6_factor12_ridx[] = {0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 18, };
float step6_factor12_data[78] = {0};

const int step6_factor12_num_blks = 2;
int step6_factor12_A_blk_start[] = {0, 6, };
int step6_factor12_B_blk_start[] = {0, 12, };
int step6_factor12_blk_width[] = {6, 6, };

const int step6_factor13_height = 7;
const int step6_factor13_width = 6;
int step6_factor13_ridx[] = {6, 7, 8, 9, 10, 11, 18, };
float step6_factor13_data[42] = {0};

const int step6_factor13_num_blks = 1;
int step6_factor13_A_blk_start[] = {0, };
int step6_factor13_B_blk_start[] = {6, };
int step6_factor13_blk_width[] = {6, };

const int step6_factor14_height = 13;
const int step6_factor14_width = 6;
int step6_factor14_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, };
float step6_factor14_data[78] = {0};

const int step6_factor14_num_blks = 1;
int step6_factor14_A_blk_start[] = {0, };
int step6_factor14_B_blk_start[] = {6, };
int step6_factor14_blk_width[] = {12, };

const int step6_factor15_height = 13;
const int step6_factor15_width = 6;
int step6_factor15_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 18, };
float step6_factor15_data[78] = {0};

const int step6_factor15_num_blks = 1;
int step6_factor15_A_blk_start[] = {0, };
int step6_factor15_B_blk_start[] = {0, };
int step6_factor15_blk_width[] = {12, };

const int step6_factor9_height = 7;
const int step6_factor9_width = 6;
int step6_factor9_ridx[] = {0, 1, 2, 3, 4, 5, 18, };
float step6_factor9_data[42] = {0};

const int step6_factor9_num_blks = 1;
int step6_factor9_A_blk_start[] = {0, };
int step6_factor9_B_blk_start[] = {0, };
int step6_factor9_blk_width[] = {6, };

const int step6_factor10_height = 13;
const int step6_factor10_width = 6;
int step6_factor10_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step6_factor10_data[78] = {0};

const int step6_factor10_num_blks = 1;
int step6_factor10_A_blk_start[] = {0, };
int step6_factor10_B_blk_start[] = {18, };
int step6_factor10_blk_width[] = {12, };

const int step6_factor11_height = 7;
const int step6_factor11_width = 6;
int step6_factor11_ridx[] = {12, 13, 14, 15, 16, 17, 18, };
float step6_factor11_data[42] = {0};

const int step6_factor11_num_blks = 1;
int step6_factor11_A_blk_start[] = {0, };
int step6_factor11_B_blk_start[] = {12, };
int step6_factor11_blk_width[] = {6, };

const int step6_node0_num_factors = 1;
const int step6_node0_relin_cost = 0;
const int step6_node0_sym_cost = 16000;
const bool step6_node0_marked = false;
const bool step6_node0_fixed = true;
int step6_node0_factor_height[] = {step6_factor10_height, };
int step6_node0_factor_width[] = {step6_factor10_width, };
int* step6_node0_factor_ridx[] = {step6_factor10_ridx, };
float* step6_node0_factor_data[] = {step6_factor10_data, };
int step6_node0_factor_num_blks[] = {step6_factor10_num_blks, };
int* step6_node0_factor_A_blk_start[] = {step6_factor10_A_blk_start, };
int* step6_node0_factor_B_blk_start[] = {step6_factor10_B_blk_start, };
int* step6_node0_factor_blk_width[] = {step6_factor10_blk_width, };
const int step6_node0_parent = 1;
const int step6_node0_height = 31;
const int step6_node0_width = 24;
float step6_node0_data[744] = {0};
const int step6_node0_num_blks = 1;
int step6_node0_A_blk_start[] = {0, };
int step6_node0_B_blk_start[] = {0, };
int step6_node0_blk_width[] = {6, };


const int step6_node1_num_factors = 6;
const int step6_node1_relin_cost = 0;
const int step6_node1_sym_cost = 12000;
const bool step6_node1_marked = true;
const bool step6_node1_fixed = false;
int step6_node1_factor_height[] = {step6_factor9_height, step6_factor11_height, step6_factor12_height, step6_factor13_height, step6_factor14_height, step6_factor15_height, };
int step6_node1_factor_width[] = {step6_factor9_width, step6_factor11_width, step6_factor12_width, step6_factor13_width, step6_factor14_width, step6_factor15_width, };
int* step6_node1_factor_ridx[] = {step6_factor9_ridx, step6_factor11_ridx, step6_factor12_ridx, step6_factor13_ridx, step6_factor14_ridx, step6_factor15_ridx, };
float* step6_node1_factor_data[] = {step6_factor9_data, step6_factor11_data, step6_factor12_data, step6_factor13_data, step6_factor14_data, step6_factor15_data, };
int step6_node1_factor_num_blks[] = {step6_factor9_num_blks, step6_factor11_num_blks, step6_factor12_num_blks, step6_factor13_num_blks, step6_factor14_num_blks, step6_factor15_num_blks, };
int* step6_node1_factor_A_blk_start[] = {step6_factor9_A_blk_start, step6_factor11_A_blk_start, step6_factor12_A_blk_start, step6_factor13_A_blk_start, step6_factor14_A_blk_start, step6_factor15_A_blk_start, };
int* step6_node1_factor_B_blk_start[] = {step6_factor9_B_blk_start, step6_factor11_B_blk_start, step6_factor12_B_blk_start, step6_factor13_B_blk_start, step6_factor14_B_blk_start, step6_factor15_B_blk_start, };
int* step6_node1_factor_blk_width[] = {step6_factor9_blk_width, step6_factor11_blk_width, step6_factor12_blk_width, step6_factor13_blk_width, step6_factor14_blk_width, step6_factor15_blk_width, };
const int step6_node1_parent = 2;
const int step6_node1_height = 19;
const int step6_node1_width = 18;
float step6_node1_data[342] = {0};
const int step6_node1_num_blks = 0;
int step6_node1_A_blk_start[] = {};
int step6_node1_B_blk_start[] = {};
int step6_node1_blk_width[] = {};


const int step6_node2_num_factors = 0;
const int step6_node2_relin_cost = 0;
const int step6_node2_sym_cost = 4000;
const bool step6_node2_marked = true;
const bool step6_node2_fixed = false;
int step6_node2_factor_height[] = {};
int step6_node2_factor_width[] = {};
int* step6_node2_factor_ridx[] = {};
float* step6_node2_factor_data[] = {};
int step6_node2_factor_num_blks[] = {};
int* step6_node2_factor_A_blk_start[] = {};
int* step6_node2_factor_B_blk_start[] = {};
int* step6_node2_factor_blk_width[] = {};
const int step6_node2_parent = -1;
const int step6_node2_height = 1;
const int step6_node2_width = 1;
float step6_node2_data[1] = {0};
const int step6_node2_num_blks = 0;
int step6_node2_A_blk_start[] = {};
int step6_node2_B_blk_start[] = {};
int step6_node2_blk_width[] = {};


int step6_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 42, };
int step6_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, };
int step6_node2_ridx[] = {
42, };
const int step6_nnodes = 3;
bool step6_node_marked[] = {step6_node0_marked, step6_node1_marked, step6_node2_marked, };
bool step6_node_fixed[] = {step6_node0_fixed, step6_node1_fixed, step6_node2_fixed, };
int step6_node_num_factors[] = {step6_node0_num_factors, step6_node1_num_factors, step6_node2_num_factors, };
int step6_node_relin_cost[] = {step6_node0_relin_cost, step6_node1_relin_cost, step6_node2_relin_cost, };
int step6_node_sym_cost[] = {step6_node0_sym_cost, step6_node1_sym_cost, step6_node2_sym_cost, };
int* step6_node_factor_height[] = {step6_node0_factor_height, step6_node1_factor_height, step6_node2_factor_height, };
int* step6_node_factor_width[] = {step6_node0_factor_width, step6_node1_factor_width, step6_node2_factor_width, };
int** step6_node_factor_ridx[] = {step6_node0_factor_ridx, step6_node1_factor_ridx, step6_node2_factor_ridx, };
float** step6_node_factor_data[] = {step6_node0_factor_data, step6_node1_factor_data, step6_node2_factor_data, };
int* step6_node_factor_num_blks[] = {step6_node0_factor_num_blks, step6_node1_factor_num_blks, step6_node2_factor_num_blks, };
int** step6_node_factor_A_blk_start[] = {step6_node0_factor_A_blk_start, step6_node1_factor_A_blk_start, step6_node2_factor_A_blk_start, };
int** step6_node_factor_B_blk_start[] = {step6_node0_factor_B_blk_start, step6_node1_factor_B_blk_start, step6_node2_factor_B_blk_start, };
int** step6_node_factor_blk_width[] = {step6_node0_factor_blk_width, step6_node1_factor_blk_width, step6_node2_factor_blk_width, };
int step6_node_parent[] = {step6_node0_parent, step6_node1_parent, step6_node2_parent, };
int step6_node_height[] = {step6_node0_height, step6_node1_height, step6_node2_height, };
int step6_node_width[] = {step6_node0_width, step6_node1_width, step6_node2_width, };
float* step6_node_data[] = {step6_node0_data, step6_node1_data, step6_node2_data, };
int step6_node_num_blks[] = {step6_node0_num_blks, step6_node1_num_blks, step6_node2_num_blks, };
int* step6_node_A_blk_start[] = {step6_node0_A_blk_start, step6_node1_A_blk_start, step6_node2_A_blk_start, };
int* step6_node_B_blk_start[] = {step6_node0_B_blk_start, step6_node1_B_blk_start, step6_node2_B_blk_start, };
int* step6_node_blk_width[] = {step6_node0_blk_width, step6_node1_blk_width, step6_node2_blk_width, };
int* step6_node_ridx[] = {step6_node0_ridx, step6_node1_ridx, step6_node2_ridx, };


float step6_x_data[43] = {};
const int step6_workspace_needed = 5592;

