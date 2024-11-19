#pragma once

const bool step8_is_reconstruct = true;

const int step8_num_threads = 1;

const uint64_t step8_scaled_relin_cost = 80000;

const bool step8_run_model = false;

const int step8_factor16_height = 7;
const int step8_factor16_width = 6;
int step8_factor16_ridx[] = {12, 13, 14, 15, 16, 17, 30, };
float step8_factor16_data[42] = {0};

const int step8_factor16_num_blks = 1;
int step8_factor16_A_blk_start[] = {0, };
int step8_factor16_B_blk_start[] = {12, };
int step8_factor16_blk_width[] = {6, };

const int step8_factor17_height = 13;
const int step8_factor17_width = 6;
int step8_factor17_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 30, };
float step8_factor17_data[78] = {0};

const int step8_factor17_num_blks = 1;
int step8_factor17_A_blk_start[] = {0, };
int step8_factor17_B_blk_start[] = {12, };
int step8_factor17_blk_width[] = {12, };

const int step8_factor18_height = 13;
const int step8_factor18_width = 6;
int step8_factor18_ridx[] = {0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 30, };
float step8_factor18_data[78] = {0};

const int step8_factor18_num_blks = 2;
int step8_factor18_A_blk_start[] = {0, 6, };
int step8_factor18_B_blk_start[] = {0, 12, };
int step8_factor18_blk_width[] = {6, 6, };

const int step8_factor19_height = 13;
const int step8_factor19_width = 6;
int step8_factor19_ridx[] = {12, 13, 14, 15, 16, 17, 24, 25, 26, 27, 28, 29, 30, };
float step8_factor19_data[78] = {0};

const int step8_factor19_num_blks = 2;
int step8_factor19_A_blk_start[] = {0, 6, };
int step8_factor19_B_blk_start[] = {12, 24, };
int step8_factor19_blk_width[] = {6, 6, };

const int step8_factor9_height = 7;
const int step8_factor9_width = 6;
int step8_factor9_ridx[] = {0, 1, 2, 3, 4, 5, 30, };
float step8_factor9_data[42] = {0};

const int step8_factor9_num_blks = 1;
int step8_factor9_A_blk_start[] = {0, };
int step8_factor9_B_blk_start[] = {0, };
int step8_factor9_blk_width[] = {6, };

const int step8_factor20_height = 7;
const int step8_factor20_width = 6;
int step8_factor20_ridx[] = {6, 7, 8, 9, 10, 11, 30, };
float step8_factor20_data[42] = {0};

const int step8_factor20_num_blks = 1;
int step8_factor20_A_blk_start[] = {0, };
int step8_factor20_B_blk_start[] = {6, };
int step8_factor20_blk_width[] = {6, };

const int step8_factor10_height = 13;
const int step8_factor10_width = 6;
int step8_factor10_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step8_factor10_data[78] = {0};

const int step8_factor10_num_blks = 1;
int step8_factor10_A_blk_start[] = {0, };
int step8_factor10_B_blk_start[] = {18, };
int step8_factor10_blk_width[] = {12, };

const int step8_factor21_height = 13;
const int step8_factor21_width = 6;
int step8_factor21_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 30, };
float step8_factor21_data[78] = {0};

const int step8_factor21_num_blks = 1;
int step8_factor21_A_blk_start[] = {0, };
int step8_factor21_B_blk_start[] = {6, };
int step8_factor21_blk_width[] = {12, };

const int step8_factor11_height = 7;
const int step8_factor11_width = 6;
int step8_factor11_ridx[] = {24, 25, 26, 27, 28, 29, 30, };
float step8_factor11_data[42] = {0};

const int step8_factor11_num_blks = 1;
int step8_factor11_A_blk_start[] = {0, };
int step8_factor11_B_blk_start[] = {24, };
int step8_factor11_blk_width[] = {6, };

const int step8_factor22_height = 13;
const int step8_factor22_width = 6;
int step8_factor22_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 30, };
float step8_factor22_data[78] = {0};

const int step8_factor22_num_blks = 1;
int step8_factor22_A_blk_start[] = {0, };
int step8_factor22_B_blk_start[] = {0, };
int step8_factor22_blk_width[] = {12, };

const int step8_factor12_height = 13;
const int step8_factor12_width = 6;
int step8_factor12_ridx[] = {0, 1, 2, 3, 4, 5, 24, 25, 26, 27, 28, 29, 30, };
float step8_factor12_data[78] = {0};

const int step8_factor12_num_blks = 2;
int step8_factor12_A_blk_start[] = {0, 6, };
int step8_factor12_B_blk_start[] = {0, 24, };
int step8_factor12_blk_width[] = {6, 6, };

const int step8_factor23_height = 13;
const int step8_factor23_width = 6;
int step8_factor23_ridx[] = {6, 7, 8, 9, 10, 11, 24, 25, 26, 27, 28, 29, 30, };
float step8_factor23_data[78] = {0};

const int step8_factor23_num_blks = 2;
int step8_factor23_A_blk_start[] = {0, 6, };
int step8_factor23_B_blk_start[] = {6, 24, };
int step8_factor23_blk_width[] = {6, 6, };

const int step8_factor13_height = 7;
const int step8_factor13_width = 6;
int step8_factor13_ridx[] = {18, 19, 20, 21, 22, 23, 30, };
float step8_factor13_data[42] = {0};

const int step8_factor13_num_blks = 1;
int step8_factor13_A_blk_start[] = {0, };
int step8_factor13_B_blk_start[] = {18, };
int step8_factor13_blk_width[] = {6, };

const int step8_factor24_height = 13;
const int step8_factor24_width = 6;
int step8_factor24_ridx[] = {6, 7, 8, 9, 10, 11, 18, 19, 20, 21, 22, 23, 30, };
float step8_factor24_data[78] = {0};

const int step8_factor24_num_blks = 2;
int step8_factor24_A_blk_start[] = {0, 6, };
int step8_factor24_B_blk_start[] = {6, 18, };
int step8_factor24_blk_width[] = {6, 6, };

const int step8_factor14_height = 13;
const int step8_factor14_width = 6;
int step8_factor14_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step8_factor14_data[78] = {0};

const int step8_factor14_num_blks = 1;
int step8_factor14_A_blk_start[] = {0, };
int step8_factor14_B_blk_start[] = {18, };
int step8_factor14_blk_width[] = {12, };

const int step8_factor15_height = 13;
const int step8_factor15_width = 6;
int step8_factor15_ridx[] = {0, 1, 2, 3, 4, 5, 18, 19, 20, 21, 22, 23, 30, };
float step8_factor15_data[78] = {0};

const int step8_factor15_num_blks = 2;
int step8_factor15_A_blk_start[] = {0, 6, };
int step8_factor15_B_blk_start[] = {0, 18, };
int step8_factor15_blk_width[] = {6, 6, };

const int step8_node0_num_factors = 1;
const int step8_node0_relin_cost = 0;
const int step8_node0_sym_cost = 16000;
const bool step8_node0_marked = false;
const bool step8_node0_fixed = true;
int step8_node0_factor_height[] = {step8_factor10_height, };
int step8_node0_factor_width[] = {step8_factor10_width, };
int* step8_node0_factor_ridx[] = {step8_factor10_ridx, };
float* step8_node0_factor_data[] = {step8_factor10_data, };
int step8_node0_factor_num_blks[] = {step8_factor10_num_blks, };
int* step8_node0_factor_A_blk_start[] = {step8_factor10_A_blk_start, };
int* step8_node0_factor_B_blk_start[] = {step8_factor10_B_blk_start, };
int* step8_node0_factor_blk_width[] = {step8_factor10_blk_width, };
const int step8_node0_parent = 1;
const int step8_node0_height = 31;
const int step8_node0_width = 24;
float step8_node0_data[744] = {0};
const int step8_node0_num_blks = 1;
int step8_node0_A_blk_start[] = {0, };
int step8_node0_B_blk_start[] = {0, };
int step8_node0_blk_width[] = {6, };


const int step8_node1_num_factors = 15;
const int step8_node1_relin_cost = 80000;
const int step8_node1_sym_cost = 20000;
const bool step8_node1_marked = true;
const bool step8_node1_fixed = false;
int step8_node1_factor_height[] = {step8_factor9_height, step8_factor11_height, step8_factor12_height, step8_factor13_height, step8_factor14_height, step8_factor15_height, step8_factor16_height, step8_factor17_height, step8_factor18_height, step8_factor19_height, step8_factor20_height, step8_factor21_height, step8_factor22_height, step8_factor23_height, step8_factor24_height, };
int step8_node1_factor_width[] = {step8_factor9_width, step8_factor11_width, step8_factor12_width, step8_factor13_width, step8_factor14_width, step8_factor15_width, step8_factor16_width, step8_factor17_width, step8_factor18_width, step8_factor19_width, step8_factor20_width, step8_factor21_width, step8_factor22_width, step8_factor23_width, step8_factor24_width, };
int* step8_node1_factor_ridx[] = {step8_factor9_ridx, step8_factor11_ridx, step8_factor12_ridx, step8_factor13_ridx, step8_factor14_ridx, step8_factor15_ridx, step8_factor16_ridx, step8_factor17_ridx, step8_factor18_ridx, step8_factor19_ridx, step8_factor20_ridx, step8_factor21_ridx, step8_factor22_ridx, step8_factor23_ridx, step8_factor24_ridx, };
float* step8_node1_factor_data[] = {step8_factor9_data, step8_factor11_data, step8_factor12_data, step8_factor13_data, step8_factor14_data, step8_factor15_data, step8_factor16_data, step8_factor17_data, step8_factor18_data, step8_factor19_data, step8_factor20_data, step8_factor21_data, step8_factor22_data, step8_factor23_data, step8_factor24_data, };
int step8_node1_factor_num_blks[] = {step8_factor9_num_blks, step8_factor11_num_blks, step8_factor12_num_blks, step8_factor13_num_blks, step8_factor14_num_blks, step8_factor15_num_blks, step8_factor16_num_blks, step8_factor17_num_blks, step8_factor18_num_blks, step8_factor19_num_blks, step8_factor20_num_blks, step8_factor21_num_blks, step8_factor22_num_blks, step8_factor23_num_blks, step8_factor24_num_blks, };
int* step8_node1_factor_A_blk_start[] = {step8_factor9_A_blk_start, step8_factor11_A_blk_start, step8_factor12_A_blk_start, step8_factor13_A_blk_start, step8_factor14_A_blk_start, step8_factor15_A_blk_start, step8_factor16_A_blk_start, step8_factor17_A_blk_start, step8_factor18_A_blk_start, step8_factor19_A_blk_start, step8_factor20_A_blk_start, step8_factor21_A_blk_start, step8_factor22_A_blk_start, step8_factor23_A_blk_start, step8_factor24_A_blk_start, };
int* step8_node1_factor_B_blk_start[] = {step8_factor9_B_blk_start, step8_factor11_B_blk_start, step8_factor12_B_blk_start, step8_factor13_B_blk_start, step8_factor14_B_blk_start, step8_factor15_B_blk_start, step8_factor16_B_blk_start, step8_factor17_B_blk_start, step8_factor18_B_blk_start, step8_factor19_B_blk_start, step8_factor20_B_blk_start, step8_factor21_B_blk_start, step8_factor22_B_blk_start, step8_factor23_B_blk_start, step8_factor24_B_blk_start, };
int* step8_node1_factor_blk_width[] = {step8_factor9_blk_width, step8_factor11_blk_width, step8_factor12_blk_width, step8_factor13_blk_width, step8_factor14_blk_width, step8_factor15_blk_width, step8_factor16_blk_width, step8_factor17_blk_width, step8_factor18_blk_width, step8_factor19_blk_width, step8_factor20_blk_width, step8_factor21_blk_width, step8_factor22_blk_width, step8_factor23_blk_width, step8_factor24_blk_width, };
const int step8_node1_parent = 2;
const int step8_node1_height = 31;
const int step8_node1_width = 30;
float step8_node1_data[930] = {0};
const int step8_node1_num_blks = 0;
int step8_node1_A_blk_start[] = {};
int step8_node1_B_blk_start[] = {};
int step8_node1_blk_width[] = {};


const int step8_node2_num_factors = 0;
const int step8_node2_relin_cost = 0;
const int step8_node2_sym_cost = 4000;
const bool step8_node2_marked = true;
const bool step8_node2_fixed = false;
int step8_node2_factor_height[] = {};
int step8_node2_factor_width[] = {};
int* step8_node2_factor_ridx[] = {};
float* step8_node2_factor_data[] = {};
int step8_node2_factor_num_blks[] = {};
int* step8_node2_factor_A_blk_start[] = {};
int* step8_node2_factor_B_blk_start[] = {};
int* step8_node2_factor_blk_width[] = {};
const int step8_node2_parent = -1;
const int step8_node2_height = 1;
const int step8_node2_width = 1;
float step8_node2_data[1] = {0};
const int step8_node2_num_blks = 0;
int step8_node2_A_blk_start[] = {};
int step8_node2_B_blk_start[] = {};
int step8_node2_blk_width[] = {};


int step8_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 54, };
int step8_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, };
int step8_node2_ridx[] = {
54, };
const int step8_nnodes = 3;
bool step8_node_marked[] = {step8_node0_marked, step8_node1_marked, step8_node2_marked, };
bool step8_node_fixed[] = {step8_node0_fixed, step8_node1_fixed, step8_node2_fixed, };
int step8_node_num_factors[] = {step8_node0_num_factors, step8_node1_num_factors, step8_node2_num_factors, };
int step8_node_relin_cost[] = {step8_node0_relin_cost, step8_node1_relin_cost, step8_node2_relin_cost, };
int step8_node_sym_cost[] = {step8_node0_sym_cost, step8_node1_sym_cost, step8_node2_sym_cost, };
int* step8_node_factor_height[] = {step8_node0_factor_height, step8_node1_factor_height, step8_node2_factor_height, };
int* step8_node_factor_width[] = {step8_node0_factor_width, step8_node1_factor_width, step8_node2_factor_width, };
int** step8_node_factor_ridx[] = {step8_node0_factor_ridx, step8_node1_factor_ridx, step8_node2_factor_ridx, };
float** step8_node_factor_data[] = {step8_node0_factor_data, step8_node1_factor_data, step8_node2_factor_data, };
int* step8_node_factor_num_blks[] = {step8_node0_factor_num_blks, step8_node1_factor_num_blks, step8_node2_factor_num_blks, };
int** step8_node_factor_A_blk_start[] = {step8_node0_factor_A_blk_start, step8_node1_factor_A_blk_start, step8_node2_factor_A_blk_start, };
int** step8_node_factor_B_blk_start[] = {step8_node0_factor_B_blk_start, step8_node1_factor_B_blk_start, step8_node2_factor_B_blk_start, };
int** step8_node_factor_blk_width[] = {step8_node0_factor_blk_width, step8_node1_factor_blk_width, step8_node2_factor_blk_width, };
int step8_node_parent[] = {step8_node0_parent, step8_node1_parent, step8_node2_parent, };
int step8_node_height[] = {step8_node0_height, step8_node1_height, step8_node2_height, };
int step8_node_width[] = {step8_node0_width, step8_node1_width, step8_node2_width, };
float* step8_node_data[] = {step8_node0_data, step8_node1_data, step8_node2_data, };
int step8_node_num_blks[] = {step8_node0_num_blks, step8_node1_num_blks, step8_node2_num_blks, };
int* step8_node_A_blk_start[] = {step8_node0_A_blk_start, step8_node1_A_blk_start, step8_node2_A_blk_start, };
int* step8_node_B_blk_start[] = {step8_node0_B_blk_start, step8_node1_B_blk_start, step8_node2_B_blk_start, };
int* step8_node_blk_width[] = {step8_node0_blk_width, step8_node1_blk_width, step8_node2_blk_width, };
int* step8_node_ridx[] = {step8_node0_ridx, step8_node1_ridx, step8_node2_ridx, };


float step8_x_data[55] = {};
const int step8_workspace_needed = 7992;

