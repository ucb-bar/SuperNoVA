#pragma once

const bool step7_is_reconstruct = true;

const int step7_num_threads = 1;

const uint64_t step7_scaled_relin_cost = 60000;

const bool step7_run_model = false;

const int step7_factor10_height = 13;
const int step7_factor10_width = 6;
int step7_factor10_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step7_factor10_data[78] = {0};

const int step7_factor10_num_blks = 1;
int step7_factor10_A_blk_start[] = {0, };
int step7_factor10_B_blk_start[] = {18, };
int step7_factor10_blk_width[] = {12, };

const int step7_factor11_height = 7;
const int step7_factor11_width = 6;
int step7_factor11_ridx[] = {18, 19, 20, 21, 22, 23, 24, };
float step7_factor11_data[42] = {0};

const int step7_factor11_num_blks = 1;
int step7_factor11_A_blk_start[] = {0, };
int step7_factor11_B_blk_start[] = {18, };
int step7_factor11_blk_width[] = {6, };

const int step7_factor12_height = 13;
const int step7_factor12_width = 6;
int step7_factor12_ridx[] = {0, 1, 2, 3, 4, 5, 18, 19, 20, 21, 22, 23, 24, };
float step7_factor12_data[78] = {0};

const int step7_factor12_num_blks = 2;
int step7_factor12_A_blk_start[] = {0, 6, };
int step7_factor12_B_blk_start[] = {0, 18, };
int step7_factor12_blk_width[] = {6, 6, };

const int step7_factor13_height = 7;
const int step7_factor13_width = 6;
int step7_factor13_ridx[] = {12, 13, 14, 15, 16, 17, 24, };
float step7_factor13_data[42] = {0};

const int step7_factor13_num_blks = 1;
int step7_factor13_A_blk_start[] = {0, };
int step7_factor13_B_blk_start[] = {12, };
int step7_factor13_blk_width[] = {6, };

const int step7_factor14_height = 13;
const int step7_factor14_width = 6;
int step7_factor14_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, };
float step7_factor14_data[78] = {0};

const int step7_factor14_num_blks = 1;
int step7_factor14_A_blk_start[] = {0, };
int step7_factor14_B_blk_start[] = {12, };
int step7_factor14_blk_width[] = {12, };

const int step7_factor15_height = 13;
const int step7_factor15_width = 6;
int step7_factor15_ridx[] = {0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 24, };
float step7_factor15_data[78] = {0};

const int step7_factor15_num_blks = 2;
int step7_factor15_A_blk_start[] = {0, 6, };
int step7_factor15_B_blk_start[] = {0, 12, };
int step7_factor15_blk_width[] = {6, 6, };

const int step7_factor16_height = 7;
const int step7_factor16_width = 6;
int step7_factor16_ridx[] = {6, 7, 8, 9, 10, 11, 24, };
float step7_factor16_data[42] = {0};

const int step7_factor16_num_blks = 1;
int step7_factor16_A_blk_start[] = {0, };
int step7_factor16_B_blk_start[] = {6, };
int step7_factor16_blk_width[] = {6, };

const int step7_factor17_height = 13;
const int step7_factor17_width = 6;
int step7_factor17_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 24, };
float step7_factor17_data[78] = {0};

const int step7_factor17_num_blks = 1;
int step7_factor17_A_blk_start[] = {0, };
int step7_factor17_B_blk_start[] = {6, };
int step7_factor17_blk_width[] = {12, };

const int step7_factor18_height = 13;
const int step7_factor18_width = 6;
int step7_factor18_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 24, };
float step7_factor18_data[78] = {0};

const int step7_factor18_num_blks = 1;
int step7_factor18_A_blk_start[] = {0, };
int step7_factor18_B_blk_start[] = {0, };
int step7_factor18_blk_width[] = {12, };

const int step7_factor19_height = 13;
const int step7_factor19_width = 6;
int step7_factor19_ridx[] = {6, 7, 8, 9, 10, 11, 18, 19, 20, 21, 22, 23, 24, };
float step7_factor19_data[78] = {0};

const int step7_factor19_num_blks = 2;
int step7_factor19_A_blk_start[] = {0, 6, };
int step7_factor19_B_blk_start[] = {6, 18, };
int step7_factor19_blk_width[] = {6, 6, };

const int step7_factor9_height = 7;
const int step7_factor9_width = 6;
int step7_factor9_ridx[] = {0, 1, 2, 3, 4, 5, 24, };
float step7_factor9_data[42] = {0};

const int step7_factor9_num_blks = 1;
int step7_factor9_A_blk_start[] = {0, };
int step7_factor9_B_blk_start[] = {0, };
int step7_factor9_blk_width[] = {6, };

const int step7_node0_num_factors = 1;
const int step7_node0_relin_cost = 0;
const int step7_node0_sym_cost = 16000;
const bool step7_node0_marked = false;
const bool step7_node0_fixed = true;
int step7_node0_factor_height[] = {step7_factor10_height, };
int step7_node0_factor_width[] = {step7_factor10_width, };
int* step7_node0_factor_ridx[] = {step7_factor10_ridx, };
float* step7_node0_factor_data[] = {step7_factor10_data, };
int step7_node0_factor_num_blks[] = {step7_factor10_num_blks, };
int* step7_node0_factor_A_blk_start[] = {step7_factor10_A_blk_start, };
int* step7_node0_factor_B_blk_start[] = {step7_factor10_B_blk_start, };
int* step7_node0_factor_blk_width[] = {step7_factor10_blk_width, };
const int step7_node0_parent = 1;
const int step7_node0_height = 31;
const int step7_node0_width = 24;
float step7_node0_data[744] = {0};
const int step7_node0_num_blks = 1;
int step7_node0_A_blk_start[] = {0, };
int step7_node0_B_blk_start[] = {0, };
int step7_node0_blk_width[] = {6, };


const int step7_node1_num_factors = 10;
const int step7_node1_relin_cost = 60000;
const int step7_node1_sym_cost = 16000;
const bool step7_node1_marked = true;
const bool step7_node1_fixed = false;
int step7_node1_factor_height[] = {step7_factor9_height, step7_factor11_height, step7_factor12_height, step7_factor13_height, step7_factor14_height, step7_factor15_height, step7_factor16_height, step7_factor17_height, step7_factor18_height, step7_factor19_height, };
int step7_node1_factor_width[] = {step7_factor9_width, step7_factor11_width, step7_factor12_width, step7_factor13_width, step7_factor14_width, step7_factor15_width, step7_factor16_width, step7_factor17_width, step7_factor18_width, step7_factor19_width, };
int* step7_node1_factor_ridx[] = {step7_factor9_ridx, step7_factor11_ridx, step7_factor12_ridx, step7_factor13_ridx, step7_factor14_ridx, step7_factor15_ridx, step7_factor16_ridx, step7_factor17_ridx, step7_factor18_ridx, step7_factor19_ridx, };
float* step7_node1_factor_data[] = {step7_factor9_data, step7_factor11_data, step7_factor12_data, step7_factor13_data, step7_factor14_data, step7_factor15_data, step7_factor16_data, step7_factor17_data, step7_factor18_data, step7_factor19_data, };
int step7_node1_factor_num_blks[] = {step7_factor9_num_blks, step7_factor11_num_blks, step7_factor12_num_blks, step7_factor13_num_blks, step7_factor14_num_blks, step7_factor15_num_blks, step7_factor16_num_blks, step7_factor17_num_blks, step7_factor18_num_blks, step7_factor19_num_blks, };
int* step7_node1_factor_A_blk_start[] = {step7_factor9_A_blk_start, step7_factor11_A_blk_start, step7_factor12_A_blk_start, step7_factor13_A_blk_start, step7_factor14_A_blk_start, step7_factor15_A_blk_start, step7_factor16_A_blk_start, step7_factor17_A_blk_start, step7_factor18_A_blk_start, step7_factor19_A_blk_start, };
int* step7_node1_factor_B_blk_start[] = {step7_factor9_B_blk_start, step7_factor11_B_blk_start, step7_factor12_B_blk_start, step7_factor13_B_blk_start, step7_factor14_B_blk_start, step7_factor15_B_blk_start, step7_factor16_B_blk_start, step7_factor17_B_blk_start, step7_factor18_B_blk_start, step7_factor19_B_blk_start, };
int* step7_node1_factor_blk_width[] = {step7_factor9_blk_width, step7_factor11_blk_width, step7_factor12_blk_width, step7_factor13_blk_width, step7_factor14_blk_width, step7_factor15_blk_width, step7_factor16_blk_width, step7_factor17_blk_width, step7_factor18_blk_width, step7_factor19_blk_width, };
const int step7_node1_parent = 2;
const int step7_node1_height = 25;
const int step7_node1_width = 24;
float step7_node1_data[600] = {0};
const int step7_node1_num_blks = 0;
int step7_node1_A_blk_start[] = {};
int step7_node1_B_blk_start[] = {};
int step7_node1_blk_width[] = {};


const int step7_node2_num_factors = 0;
const int step7_node2_relin_cost = 0;
const int step7_node2_sym_cost = 4000;
const bool step7_node2_marked = true;
const bool step7_node2_fixed = false;
int step7_node2_factor_height[] = {};
int step7_node2_factor_width[] = {};
int* step7_node2_factor_ridx[] = {};
float* step7_node2_factor_data[] = {};
int step7_node2_factor_num_blks[] = {};
int* step7_node2_factor_A_blk_start[] = {};
int* step7_node2_factor_B_blk_start[] = {};
int* step7_node2_factor_blk_width[] = {};
const int step7_node2_parent = -1;
const int step7_node2_height = 1;
const int step7_node2_width = 1;
float step7_node2_data[1] = {0};
const int step7_node2_num_blks = 0;
int step7_node2_A_blk_start[] = {};
int step7_node2_B_blk_start[] = {};
int step7_node2_blk_width[] = {};


int step7_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 48, };
int step7_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, };
int step7_node2_ridx[] = {
48, };
const int step7_nnodes = 3;
bool step7_node_marked[] = {step7_node0_marked, step7_node1_marked, step7_node2_marked, };
bool step7_node_fixed[] = {step7_node0_fixed, step7_node1_fixed, step7_node2_fixed, };
int step7_node_num_factors[] = {step7_node0_num_factors, step7_node1_num_factors, step7_node2_num_factors, };
int step7_node_relin_cost[] = {step7_node0_relin_cost, step7_node1_relin_cost, step7_node2_relin_cost, };
int step7_node_sym_cost[] = {step7_node0_sym_cost, step7_node1_sym_cost, step7_node2_sym_cost, };
int* step7_node_factor_height[] = {step7_node0_factor_height, step7_node1_factor_height, step7_node2_factor_height, };
int* step7_node_factor_width[] = {step7_node0_factor_width, step7_node1_factor_width, step7_node2_factor_width, };
int** step7_node_factor_ridx[] = {step7_node0_factor_ridx, step7_node1_factor_ridx, step7_node2_factor_ridx, };
float** step7_node_factor_data[] = {step7_node0_factor_data, step7_node1_factor_data, step7_node2_factor_data, };
int* step7_node_factor_num_blks[] = {step7_node0_factor_num_blks, step7_node1_factor_num_blks, step7_node2_factor_num_blks, };
int** step7_node_factor_A_blk_start[] = {step7_node0_factor_A_blk_start, step7_node1_factor_A_blk_start, step7_node2_factor_A_blk_start, };
int** step7_node_factor_B_blk_start[] = {step7_node0_factor_B_blk_start, step7_node1_factor_B_blk_start, step7_node2_factor_B_blk_start, };
int** step7_node_factor_blk_width[] = {step7_node0_factor_blk_width, step7_node1_factor_blk_width, step7_node2_factor_blk_width, };
int step7_node_parent[] = {step7_node0_parent, step7_node1_parent, step7_node2_parent, };
int step7_node_height[] = {step7_node0_height, step7_node1_height, step7_node2_height, };
int step7_node_width[] = {step7_node0_width, step7_node1_width, step7_node2_width, };
float* step7_node_data[] = {step7_node0_data, step7_node1_data, step7_node2_data, };
int step7_node_num_blks[] = {step7_node0_num_blks, step7_node1_num_blks, step7_node2_num_blks, };
int* step7_node_A_blk_start[] = {step7_node0_A_blk_start, step7_node1_A_blk_start, step7_node2_A_blk_start, };
int* step7_node_B_blk_start[] = {step7_node0_B_blk_start, step7_node1_B_blk_start, step7_node2_B_blk_start, };
int* step7_node_blk_width[] = {step7_node0_blk_width, step7_node1_blk_width, step7_node2_blk_width, };
int* step7_node_ridx[] = {step7_node0_ridx, step7_node1_ridx, step7_node2_ridx, };


float step7_x_data[49] = {};
const int step7_workspace_needed = 6648;

