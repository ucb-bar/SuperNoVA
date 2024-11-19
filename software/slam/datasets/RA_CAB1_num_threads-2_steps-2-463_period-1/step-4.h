#pragma once

const bool step4_is_reconstruct = true;

const int step4_num_threads = 1;

const uint64_t step4_scaled_relin_cost = 0;

const bool step4_run_model = false;

const int step4_factor7_height = 7;
const int step4_factor7_width = 6;
int step4_factor7_ridx[] = {18, 19, 20, 21, 22, 23, 30, };
float step4_factor7_data[42] = {0};

const int step4_factor7_num_blks = 1;
int step4_factor7_A_blk_start[] = {0, };
int step4_factor7_B_blk_start[] = {18, };
int step4_factor7_blk_width[] = {6, };

const int step4_factor8_height = 13;
const int step4_factor8_width = 6;
int step4_factor8_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 30, };
float step4_factor8_data[78] = {0};

const int step4_factor8_num_blks = 1;
int step4_factor8_A_blk_start[] = {0, };
int step4_factor8_B_blk_start[] = {12, };
int step4_factor8_blk_width[] = {12, };

const int step4_factor0_height = 7;
const int step4_factor0_width = 6;
int step4_factor0_ridx[] = {0, 1, 2, 3, 4, 5, 30, };
float step4_factor0_data[42] = {0};

const int step4_factor0_num_blks = 1;
int step4_factor0_A_blk_start[] = {0, };
int step4_factor0_B_blk_start[] = {0, };
int step4_factor0_blk_width[] = {6, };

const int step4_factor9_height = 7;
const int step4_factor9_width = 6;
int step4_factor9_ridx[] = {24, 25, 26, 27, 28, 29, 30, };
float step4_factor9_data[42] = {0};

const int step4_factor9_num_blks = 1;
int step4_factor9_A_blk_start[] = {0, };
int step4_factor9_B_blk_start[] = {24, };
int step4_factor9_blk_width[] = {6, };

const int step4_factor10_height = 13;
const int step4_factor10_width = 6;
int step4_factor10_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step4_factor10_data[78] = {0};

const int step4_factor10_num_blks = 1;
int step4_factor10_A_blk_start[] = {0, };
int step4_factor10_B_blk_start[] = {18, };
int step4_factor10_blk_width[] = {12, };

const int step4_factor1_height = 7;
const int step4_factor1_width = 6;
int step4_factor1_ridx[] = {6, 7, 8, 9, 10, 11, 30, };
float step4_factor1_data[42] = {0};

const int step4_factor1_num_blks = 1;
int step4_factor1_A_blk_start[] = {0, };
int step4_factor1_B_blk_start[] = {6, };
int step4_factor1_blk_width[] = {6, };

const int step4_factor2_height = 7;
const int step4_factor2_width = 6;
int step4_factor2_ridx[] = {12, 13, 14, 15, 16, 17, 30, };
float step4_factor2_data[42] = {0};

const int step4_factor2_num_blks = 1;
int step4_factor2_A_blk_start[] = {0, };
int step4_factor2_B_blk_start[] = {12, };
int step4_factor2_blk_width[] = {6, };

const int step4_factor3_height = 7;
const int step4_factor3_width = 6;
int step4_factor3_ridx[] = {0, 1, 2, 3, 4, 5, 30, };
float step4_factor3_data[42] = {0};

const int step4_factor3_num_blks = 1;
int step4_factor3_A_blk_start[] = {0, };
int step4_factor3_B_blk_start[] = {0, };
int step4_factor3_blk_width[] = {6, };

const int step4_factor4_height = 13;
const int step4_factor4_width = 6;
int step4_factor4_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 30, };
float step4_factor4_data[78] = {0};

const int step4_factor4_num_blks = 1;
int step4_factor4_A_blk_start[] = {0, };
int step4_factor4_B_blk_start[] = {0, };
int step4_factor4_blk_width[] = {12, };

const int step4_factor5_height = 13;
const int step4_factor5_width = 6;
int step4_factor5_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 30, };
float step4_factor5_data[78] = {0};

const int step4_factor5_num_blks = 1;
int step4_factor5_A_blk_start[] = {0, };
int step4_factor5_B_blk_start[] = {6, };
int step4_factor5_blk_width[] = {12, };

const int step4_factor6_height = 13;
const int step4_factor6_width = 6;
int step4_factor6_ridx[] = {0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 30, };
float step4_factor6_data[78] = {0};

const int step4_factor6_num_blks = 2;
int step4_factor6_A_blk_start[] = {0, 6, };
int step4_factor6_B_blk_start[] = {0, 12, };
int step4_factor6_blk_width[] = {6, 6, };

const int step4_node0_num_factors = 11;
const int step4_node0_relin_cost = 0;
const int step4_node0_sym_cost = 20000;
const bool step4_node0_marked = true;
const bool step4_node0_fixed = false;
int step4_node0_factor_height[] = {step4_factor0_height, step4_factor1_height, step4_factor2_height, step4_factor3_height, step4_factor4_height, step4_factor5_height, step4_factor6_height, step4_factor7_height, step4_factor8_height, step4_factor9_height, step4_factor10_height, };
int step4_node0_factor_width[] = {step4_factor0_width, step4_factor1_width, step4_factor2_width, step4_factor3_width, step4_factor4_width, step4_factor5_width, step4_factor6_width, step4_factor7_width, step4_factor8_width, step4_factor9_width, step4_factor10_width, };
int* step4_node0_factor_ridx[] = {step4_factor0_ridx, step4_factor1_ridx, step4_factor2_ridx, step4_factor3_ridx, step4_factor4_ridx, step4_factor5_ridx, step4_factor6_ridx, step4_factor7_ridx, step4_factor8_ridx, step4_factor9_ridx, step4_factor10_ridx, };
float* step4_node0_factor_data[] = {step4_factor0_data, step4_factor1_data, step4_factor2_data, step4_factor3_data, step4_factor4_data, step4_factor5_data, step4_factor6_data, step4_factor7_data, step4_factor8_data, step4_factor9_data, step4_factor10_data, };
int step4_node0_factor_num_blks[] = {step4_factor0_num_blks, step4_factor1_num_blks, step4_factor2_num_blks, step4_factor3_num_blks, step4_factor4_num_blks, step4_factor5_num_blks, step4_factor6_num_blks, step4_factor7_num_blks, step4_factor8_num_blks, step4_factor9_num_blks, step4_factor10_num_blks, };
int* step4_node0_factor_A_blk_start[] = {step4_factor0_A_blk_start, step4_factor1_A_blk_start, step4_factor2_A_blk_start, step4_factor3_A_blk_start, step4_factor4_A_blk_start, step4_factor5_A_blk_start, step4_factor6_A_blk_start, step4_factor7_A_blk_start, step4_factor8_A_blk_start, step4_factor9_A_blk_start, step4_factor10_A_blk_start, };
int* step4_node0_factor_B_blk_start[] = {step4_factor0_B_blk_start, step4_factor1_B_blk_start, step4_factor2_B_blk_start, step4_factor3_B_blk_start, step4_factor4_B_blk_start, step4_factor5_B_blk_start, step4_factor6_B_blk_start, step4_factor7_B_blk_start, step4_factor8_B_blk_start, step4_factor9_B_blk_start, step4_factor10_B_blk_start, };
int* step4_node0_factor_blk_width[] = {step4_factor0_blk_width, step4_factor1_blk_width, step4_factor2_blk_width, step4_factor3_blk_width, step4_factor4_blk_width, step4_factor5_blk_width, step4_factor6_blk_width, step4_factor7_blk_width, step4_factor8_blk_width, step4_factor9_blk_width, step4_factor10_blk_width, };
const int step4_node0_parent = 1;
const int step4_node0_height = 31;
const int step4_node0_width = 30;
float step4_node0_data[930] = {0};
const int step4_node0_num_blks = 0;
int step4_node0_A_blk_start[] = {};
int step4_node0_B_blk_start[] = {};
int step4_node0_blk_width[] = {};


const int step4_node1_num_factors = 0;
const int step4_node1_relin_cost = 0;
const int step4_node1_sym_cost = 4000;
const bool step4_node1_marked = true;
const bool step4_node1_fixed = false;
int step4_node1_factor_height[] = {};
int step4_node1_factor_width[] = {};
int* step4_node1_factor_ridx[] = {};
float* step4_node1_factor_data[] = {};
int step4_node1_factor_num_blks[] = {};
int* step4_node1_factor_A_blk_start[] = {};
int* step4_node1_factor_B_blk_start[] = {};
int* step4_node1_factor_blk_width[] = {};
const int step4_node1_parent = -1;
const int step4_node1_height = 1;
const int step4_node1_width = 1;
float step4_node1_data[1] = {0};
const int step4_node1_num_blks = 0;
int step4_node1_A_blk_start[] = {};
int step4_node1_B_blk_start[] = {};
int step4_node1_blk_width[] = {};


int step4_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
int step4_node1_ridx[] = {
30, };
const int step4_nnodes = 2;
bool step4_node_marked[] = {step4_node0_marked, step4_node1_marked, };
bool step4_node_fixed[] = {step4_node0_fixed, step4_node1_fixed, };
int step4_node_num_factors[] = {step4_node0_num_factors, step4_node1_num_factors, };
int step4_node_relin_cost[] = {step4_node0_relin_cost, step4_node1_relin_cost, };
int step4_node_sym_cost[] = {step4_node0_sym_cost, step4_node1_sym_cost, };
int* step4_node_factor_height[] = {step4_node0_factor_height, step4_node1_factor_height, };
int* step4_node_factor_width[] = {step4_node0_factor_width, step4_node1_factor_width, };
int** step4_node_factor_ridx[] = {step4_node0_factor_ridx, step4_node1_factor_ridx, };
float** step4_node_factor_data[] = {step4_node0_factor_data, step4_node1_factor_data, };
int* step4_node_factor_num_blks[] = {step4_node0_factor_num_blks, step4_node1_factor_num_blks, };
int** step4_node_factor_A_blk_start[] = {step4_node0_factor_A_blk_start, step4_node1_factor_A_blk_start, };
int** step4_node_factor_B_blk_start[] = {step4_node0_factor_B_blk_start, step4_node1_factor_B_blk_start, };
int** step4_node_factor_blk_width[] = {step4_node0_factor_blk_width, step4_node1_factor_blk_width, };
int step4_node_parent[] = {step4_node0_parent, step4_node1_parent, };
int step4_node_height[] = {step4_node0_height, step4_node1_height, };
int step4_node_width[] = {step4_node0_width, step4_node1_width, };
float* step4_node_data[] = {step4_node0_data, step4_node1_data, };
int step4_node_num_blks[] = {step4_node0_num_blks, step4_node1_num_blks, };
int* step4_node_A_blk_start[] = {step4_node0_A_blk_start, step4_node1_A_blk_start, };
int* step4_node_B_blk_start[] = {step4_node0_B_blk_start, step4_node1_B_blk_start, };
int* step4_node_blk_width[] = {step4_node0_blk_width, step4_node1_blk_width, };
int* step4_node_ridx[] = {step4_node0_ridx, step4_node1_ridx, };


float step4_x_data[31] = {};
const int step4_workspace_needed = 4048;

