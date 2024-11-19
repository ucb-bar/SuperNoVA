#pragma once

const bool step13_is_reconstruct = true;

const int step13_num_threads = 1;

const uint64_t step13_scaled_relin_cost = 80000;

const bool step13_run_model = false;

const int step13_factor11_height = 7;
const int step13_factor11_width = 6;
int step13_factor11_ridx[] = {12, 13, 14, 15, 16, 17, 30, };
float step13_factor11_data[42] = {0};

const int step13_factor11_num_blks = 1;
int step13_factor11_A_blk_start[] = {0, };
int step13_factor11_B_blk_start[] = {12, };
int step13_factor11_blk_width[] = {6, };

const int step13_factor12_height = 13;
const int step13_factor12_width = 6;
int step13_factor12_ridx[] = {18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 48, };
float step13_factor12_data[78] = {0};

const int step13_factor12_num_blks = 2;
int step13_factor12_A_blk_start[] = {0, 6, };
int step13_factor12_B_blk_start[] = {18, 42, };
int step13_factor12_blk_width[] = {6, 6, };

const int step13_factor13_height = 7;
const int step13_factor13_width = 6;
int step13_factor13_ridx[] = {6, 7, 8, 9, 10, 11, 30, };
float step13_factor13_data[42] = {0};

const int step13_factor13_num_blks = 1;
int step13_factor13_A_blk_start[] = {0, };
int step13_factor13_B_blk_start[] = {6, };
int step13_factor13_blk_width[] = {6, };

const int step13_factor14_height = 13;
const int step13_factor14_width = 6;
int step13_factor14_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 30, };
float step13_factor14_data[78] = {0};

const int step13_factor14_num_blks = 1;
int step13_factor14_A_blk_start[] = {0, };
int step13_factor14_B_blk_start[] = {6, };
int step13_factor14_blk_width[] = {12, };

const int step13_factor15_height = 13;
const int step13_factor15_width = 6;
int step13_factor15_ridx[] = {18, 19, 20, 21, 22, 23, 36, 37, 38, 39, 40, 41, 48, };
float step13_factor15_data[78] = {0};

const int step13_factor15_num_blks = 2;
int step13_factor15_A_blk_start[] = {0, 6, };
int step13_factor15_B_blk_start[] = {18, 36, };
int step13_factor15_blk_width[] = {6, 6, };

const int step13_factor17_height = 13;
const int step13_factor17_width = 6;
int step13_factor17_ridx[] = {12, 13, 14, 15, 16, 17, 36, 37, 38, 39, 40, 41, 48, };
float step13_factor17_data[78] = {0};

const int step13_factor17_num_blks = 2;
int step13_factor17_A_blk_start[] = {0, 6, };
int step13_factor17_B_blk_start[] = {12, 36, };
int step13_factor17_blk_width[] = {6, 6, };

const int step13_factor19_height = 13;
const int step13_factor19_width = 6;
int step13_factor19_ridx[] = {12, 13, 14, 15, 16, 17, 42, 43, 44, 45, 46, 47, 48, };
float step13_factor19_data[78] = {0};

const int step13_factor19_num_blks = 2;
int step13_factor19_A_blk_start[] = {0, 6, };
int step13_factor19_B_blk_start[] = {12, 42, };
int step13_factor19_blk_width[] = {6, 6, };

const int step13_factor23_height = 13;
const int step13_factor23_width = 6;
int step13_factor23_ridx[] = {24, 25, 26, 27, 28, 29, 42, 43, 44, 45, 46, 47, 48, };
float step13_factor23_data[78] = {0};

const int step13_factor23_num_blks = 2;
int step13_factor23_A_blk_start[] = {0, 6, };
int step13_factor23_B_blk_start[] = {24, 42, };
int step13_factor23_blk_width[] = {6, 6, };

const int step13_factor24_height = 13;
const int step13_factor24_width = 6;
int step13_factor24_ridx[] = {24, 25, 26, 27, 28, 29, 36, 37, 38, 39, 40, 41, 48, };
float step13_factor24_data[78] = {0};

const int step13_factor24_num_blks = 2;
int step13_factor24_A_blk_start[] = {0, 6, };
int step13_factor24_B_blk_start[] = {24, 36, };
int step13_factor24_blk_width[] = {6, 6, };

const int step13_factor28_height = 13;
const int step13_factor28_width = 6;
int step13_factor28_ridx[] = {6, 7, 8, 9, 10, 11, 42, 43, 44, 45, 46, 47, 48, };
float step13_factor28_data[78] = {0};

const int step13_factor28_num_blks = 2;
int step13_factor28_A_blk_start[] = {0, 6, };
int step13_factor28_B_blk_start[] = {6, 42, };
int step13_factor28_blk_width[] = {6, 6, };

const int step13_factor29_height = 13;
const int step13_factor29_width = 6;
int step13_factor29_ridx[] = {6, 7, 8, 9, 10, 11, 36, 37, 38, 39, 40, 41, 48, };
float step13_factor29_data[78] = {0};

const int step13_factor29_num_blks = 2;
int step13_factor29_A_blk_start[] = {0, 6, };
int step13_factor29_B_blk_start[] = {6, 36, };
int step13_factor29_blk_width[] = {6, 6, };

const int step13_factor33_height = 7;
const int step13_factor33_width = 6;
int step13_factor33_ridx[] = {0, 1, 2, 3, 4, 5, 30, };
float step13_factor33_data[42] = {0};

const int step13_factor33_num_blks = 1;
int step13_factor33_A_blk_start[] = {0, };
int step13_factor33_B_blk_start[] = {0, };
int step13_factor33_blk_width[] = {6, };

const int step13_factor34_height = 13;
const int step13_factor34_width = 6;
int step13_factor34_ridx[] = {0, 1, 2, 3, 4, 5, 30, 31, 32, 33, 34, 35, 48, };
float step13_factor34_data[78] = {0};

const int step13_factor34_num_blks = 2;
int step13_factor34_A_blk_start[] = {0, 6, };
int step13_factor34_B_blk_start[] = {0, 30, };
int step13_factor34_blk_width[] = {6, 6, };

const int step13_factor35_height = 13;
const int step13_factor35_width = 6;
int step13_factor35_ridx[] = {18, 19, 20, 21, 22, 23, 30, 31, 32, 33, 34, 35, 48, };
float step13_factor35_data[78] = {0};

const int step13_factor35_num_blks = 2;
int step13_factor35_A_blk_start[] = {0, 6, };
int step13_factor35_B_blk_start[] = {18, 30, };
int step13_factor35_blk_width[] = {6, 6, };

const int step13_factor36_height = 13;
const int step13_factor36_width = 6;
int step13_factor36_ridx[] = {0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 30, };
float step13_factor36_data[78] = {0};

const int step13_factor36_num_blks = 2;
int step13_factor36_A_blk_start[] = {0, 6, };
int step13_factor36_B_blk_start[] = {0, 12, };
int step13_factor36_blk_width[] = {6, 6, };

const int step13_factor37_height = 13;
const int step13_factor37_width = 6;
int step13_factor37_ridx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 30, };
float step13_factor37_data[78] = {0};

const int step13_factor37_num_blks = 1;
int step13_factor37_A_blk_start[] = {0, };
int step13_factor37_B_blk_start[] = {0, };
int step13_factor37_blk_width[] = {12, };

const int step13_factor38_height = 13;
const int step13_factor38_width = 6;
int step13_factor38_ridx[] = {12, 13, 14, 15, 16, 17, 30, 31, 32, 33, 34, 35, 48, };
float step13_factor38_data[78] = {0};

const int step13_factor38_num_blks = 2;
int step13_factor38_A_blk_start[] = {0, 6, };
int step13_factor38_B_blk_start[] = {12, 30, };
int step13_factor38_blk_width[] = {6, 6, };

const int step13_factor39_height = 13;
const int step13_factor39_width = 6;
int step13_factor39_ridx[] = {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 48, };
float step13_factor39_data[78] = {0};

const int step13_factor39_num_blks = 1;
int step13_factor39_A_blk_start[] = {0, };
int step13_factor39_B_blk_start[] = {24, };
int step13_factor39_blk_width[] = {12, };

const int step13_factor40_height = 13;
const int step13_factor40_width = 6;
int step13_factor40_ridx[] = {6, 7, 8, 9, 10, 11, 30, 31, 32, 33, 34, 35, 48, };
float step13_factor40_data[78] = {0};

const int step13_factor40_num_blks = 2;
int step13_factor40_A_blk_start[] = {0, 6, };
int step13_factor40_B_blk_start[] = {6, 30, };
int step13_factor40_blk_width[] = {6, 6, };

const int step13_factor41_height = 7;
const int step13_factor41_width = 6;
int step13_factor41_ridx[] = {18, 19, 20, 21, 22, 23, 30, };
float step13_factor41_data[42] = {0};

const int step13_factor41_num_blks = 1;
int step13_factor41_A_blk_start[] = {0, };
int step13_factor41_B_blk_start[] = {18, };
int step13_factor41_blk_width[] = {6, };

const int step13_factor42_height = 13;
const int step13_factor42_width = 6;
int step13_factor42_ridx[] = {0, 1, 2, 3, 4, 5, 18, 19, 20, 21, 22, 23, 30, };
float step13_factor42_data[78] = {0};

const int step13_factor42_num_blks = 2;
int step13_factor42_A_blk_start[] = {0, 6, };
int step13_factor42_B_blk_start[] = {0, 18, };
int step13_factor42_blk_width[] = {6, 6, };

const int step13_factor43_height = 13;
const int step13_factor43_width = 6;
int step13_factor43_ridx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 30, };
float step13_factor43_data[78] = {0};

const int step13_factor43_num_blks = 1;
int step13_factor43_A_blk_start[] = {0, };
int step13_factor43_B_blk_start[] = {12, };
int step13_factor43_blk_width[] = {12, };

const int step13_factor44_height = 13;
const int step13_factor44_width = 6;
int step13_factor44_ridx[] = {6, 7, 8, 9, 10, 11, 18, 19, 20, 21, 22, 23, 30, };
float step13_factor44_data[78] = {0};

const int step13_factor44_num_blks = 2;
int step13_factor44_A_blk_start[] = {0, 6, };
int step13_factor44_B_blk_start[] = {6, 18, };
int step13_factor44_blk_width[] = {6, 6, };

const int step13_factor45_height = 7;
const int step13_factor45_width = 6;
int step13_factor45_ridx[] = {24, 25, 26, 27, 28, 29, 30, };
float step13_factor45_data[42] = {0};

const int step13_factor45_num_blks = 1;
int step13_factor45_A_blk_start[] = {0, };
int step13_factor45_B_blk_start[] = {24, };
int step13_factor45_blk_width[] = {6, };

const int step13_factor46_height = 13;
const int step13_factor46_width = 6;
int step13_factor46_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, };
float step13_factor46_data[78] = {0};

const int step13_factor46_num_blks = 1;
int step13_factor46_A_blk_start[] = {0, };
int step13_factor46_B_blk_start[] = {18, };
int step13_factor46_blk_width[] = {12, };

const int step13_node1_num_factors = 13;
const int step13_node1_relin_cost = 0;
const int step13_node1_sym_cost = 20000;
const bool step13_node1_marked = false;
const bool step13_node1_fixed = true;
int step13_node1_factor_height[] = {step13_factor12_height, step13_factor15_height, step13_factor17_height, step13_factor19_height, step13_factor23_height, step13_factor24_height, step13_factor28_height, step13_factor29_height, step13_factor34_height, step13_factor35_height, step13_factor38_height, step13_factor39_height, step13_factor40_height, };
int step13_node1_factor_width[] = {step13_factor12_width, step13_factor15_width, step13_factor17_width, step13_factor19_width, step13_factor23_width, step13_factor24_width, step13_factor28_width, step13_factor29_width, step13_factor34_width, step13_factor35_width, step13_factor38_width, step13_factor39_width, step13_factor40_width, };
int* step13_node1_factor_ridx[] = {step13_factor12_ridx, step13_factor15_ridx, step13_factor17_ridx, step13_factor19_ridx, step13_factor23_ridx, step13_factor24_ridx, step13_factor28_ridx, step13_factor29_ridx, step13_factor34_ridx, step13_factor35_ridx, step13_factor38_ridx, step13_factor39_ridx, step13_factor40_ridx, };
float* step13_node1_factor_data[] = {step13_factor12_data, step13_factor15_data, step13_factor17_data, step13_factor19_data, step13_factor23_data, step13_factor24_data, step13_factor28_data, step13_factor29_data, step13_factor34_data, step13_factor35_data, step13_factor38_data, step13_factor39_data, step13_factor40_data, };
int step13_node1_factor_num_blks[] = {step13_factor12_num_blks, step13_factor15_num_blks, step13_factor17_num_blks, step13_factor19_num_blks, step13_factor23_num_blks, step13_factor24_num_blks, step13_factor28_num_blks, step13_factor29_num_blks, step13_factor34_num_blks, step13_factor35_num_blks, step13_factor38_num_blks, step13_factor39_num_blks, step13_factor40_num_blks, };
int* step13_node1_factor_A_blk_start[] = {step13_factor12_A_blk_start, step13_factor15_A_blk_start, step13_factor17_A_blk_start, step13_factor19_A_blk_start, step13_factor23_A_blk_start, step13_factor24_A_blk_start, step13_factor28_A_blk_start, step13_factor29_A_blk_start, step13_factor34_A_blk_start, step13_factor35_A_blk_start, step13_factor38_A_blk_start, step13_factor39_A_blk_start, step13_factor40_A_blk_start, };
int* step13_node1_factor_B_blk_start[] = {step13_factor12_B_blk_start, step13_factor15_B_blk_start, step13_factor17_B_blk_start, step13_factor19_B_blk_start, step13_factor23_B_blk_start, step13_factor24_B_blk_start, step13_factor28_B_blk_start, step13_factor29_B_blk_start, step13_factor34_B_blk_start, step13_factor35_B_blk_start, step13_factor38_B_blk_start, step13_factor39_B_blk_start, step13_factor40_B_blk_start, };
int* step13_node1_factor_blk_width[] = {step13_factor12_blk_width, step13_factor15_blk_width, step13_factor17_blk_width, step13_factor19_blk_width, step13_factor23_blk_width, step13_factor24_blk_width, step13_factor28_blk_width, step13_factor29_blk_width, step13_factor34_blk_width, step13_factor35_blk_width, step13_factor38_blk_width, step13_factor39_blk_width, step13_factor40_blk_width, };
const int step13_node1_parent = 2;
const int step13_node1_height = 49;
const int step13_node1_width = 30;
float step13_node1_data[1470] = {0};
const int step13_node1_num_blks = 1;
int step13_node1_A_blk_start[] = {0, };
int step13_node1_B_blk_start[] = {0, };
int step13_node1_blk_width[] = {18, };


const int step13_node2_num_factors = 12;
const int step13_node2_relin_cost = 80000;
const int step13_node2_sym_cost = 20000;
const bool step13_node2_marked = true;
const bool step13_node2_fixed = false;
int step13_node2_factor_height[] = {step13_factor11_height, step13_factor13_height, step13_factor14_height, step13_factor33_height, step13_factor36_height, step13_factor37_height, step13_factor41_height, step13_factor42_height, step13_factor43_height, step13_factor44_height, step13_factor45_height, step13_factor46_height, };
int step13_node2_factor_width[] = {step13_factor11_width, step13_factor13_width, step13_factor14_width, step13_factor33_width, step13_factor36_width, step13_factor37_width, step13_factor41_width, step13_factor42_width, step13_factor43_width, step13_factor44_width, step13_factor45_width, step13_factor46_width, };
int* step13_node2_factor_ridx[] = {step13_factor11_ridx, step13_factor13_ridx, step13_factor14_ridx, step13_factor33_ridx, step13_factor36_ridx, step13_factor37_ridx, step13_factor41_ridx, step13_factor42_ridx, step13_factor43_ridx, step13_factor44_ridx, step13_factor45_ridx, step13_factor46_ridx, };
float* step13_node2_factor_data[] = {step13_factor11_data, step13_factor13_data, step13_factor14_data, step13_factor33_data, step13_factor36_data, step13_factor37_data, step13_factor41_data, step13_factor42_data, step13_factor43_data, step13_factor44_data, step13_factor45_data, step13_factor46_data, };
int step13_node2_factor_num_blks[] = {step13_factor11_num_blks, step13_factor13_num_blks, step13_factor14_num_blks, step13_factor33_num_blks, step13_factor36_num_blks, step13_factor37_num_blks, step13_factor41_num_blks, step13_factor42_num_blks, step13_factor43_num_blks, step13_factor44_num_blks, step13_factor45_num_blks, step13_factor46_num_blks, };
int* step13_node2_factor_A_blk_start[] = {step13_factor11_A_blk_start, step13_factor13_A_blk_start, step13_factor14_A_blk_start, step13_factor33_A_blk_start, step13_factor36_A_blk_start, step13_factor37_A_blk_start, step13_factor41_A_blk_start, step13_factor42_A_blk_start, step13_factor43_A_blk_start, step13_factor44_A_blk_start, step13_factor45_A_blk_start, step13_factor46_A_blk_start, };
int* step13_node2_factor_B_blk_start[] = {step13_factor11_B_blk_start, step13_factor13_B_blk_start, step13_factor14_B_blk_start, step13_factor33_B_blk_start, step13_factor36_B_blk_start, step13_factor37_B_blk_start, step13_factor41_B_blk_start, step13_factor42_B_blk_start, step13_factor43_B_blk_start, step13_factor44_B_blk_start, step13_factor45_B_blk_start, step13_factor46_B_blk_start, };
int* step13_node2_factor_blk_width[] = {step13_factor11_blk_width, step13_factor13_blk_width, step13_factor14_blk_width, step13_factor33_blk_width, step13_factor36_blk_width, step13_factor37_blk_width, step13_factor41_blk_width, step13_factor42_blk_width, step13_factor43_blk_width, step13_factor44_blk_width, step13_factor45_blk_width, step13_factor46_blk_width, };
const int step13_node2_parent = 3;
const int step13_node2_height = 31;
const int step13_node2_width = 30;
float step13_node2_data[930] = {0};
const int step13_node2_num_blks = 0;
int step13_node2_A_blk_start[] = {};
int step13_node2_B_blk_start[] = {};
int step13_node2_blk_width[] = {};


const int step13_node3_num_factors = 0;
const int step13_node3_relin_cost = 0;
const int step13_node3_sym_cost = 4000;
const bool step13_node3_marked = true;
const bool step13_node3_fixed = false;
int step13_node3_factor_height[] = {};
int step13_node3_factor_width[] = {};
int* step13_node3_factor_ridx[] = {};
float* step13_node3_factor_data[] = {};
int step13_node3_factor_num_blks[] = {};
int* step13_node3_factor_A_blk_start[] = {};
int* step13_node3_factor_B_blk_start[] = {};
int* step13_node3_factor_blk_width[] = {};
const int step13_node3_parent = -1;
const int step13_node3_height = 1;
const int step13_node3_width = 1;
float step13_node3_data[1] = {0};
const int step13_node3_num_blks = 0;
int step13_node3_A_blk_start[] = {};
int step13_node3_B_blk_start[] = {};
int step13_node3_blk_width[] = {};


int step13_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 84, };
int step13_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 84, };
int step13_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, };
int step13_node3_ridx[] = {
84, };
const int step13_nnodes = 4;
bool step13_node_marked[] = {false, step13_node1_marked, step13_node2_marked, step13_node3_marked, };
bool step13_node_fixed[] = {false, step13_node1_fixed, step13_node2_fixed, step13_node3_fixed, };
int step13_node_num_factors[] = {0, step13_node1_num_factors, step13_node2_num_factors, step13_node3_num_factors, };
int step13_node_relin_cost[] = {0, step13_node1_relin_cost, step13_node2_relin_cost, step13_node3_relin_cost, };
int step13_node_sym_cost[] = {0, step13_node1_sym_cost, step13_node2_sym_cost, step13_node3_sym_cost, };
int* step13_node_factor_height[] = {0, step13_node1_factor_height, step13_node2_factor_height, step13_node3_factor_height, };
int* step13_node_factor_width[] = {0, step13_node1_factor_width, step13_node2_factor_width, step13_node3_factor_width, };
int** step13_node_factor_ridx[] = {0, step13_node1_factor_ridx, step13_node2_factor_ridx, step13_node3_factor_ridx, };
float** step13_node_factor_data[] = {0, step13_node1_factor_data, step13_node2_factor_data, step13_node3_factor_data, };
int* step13_node_factor_num_blks[] = {0, step13_node1_factor_num_blks, step13_node2_factor_num_blks, step13_node3_factor_num_blks, };
int** step13_node_factor_A_blk_start[] = {0, step13_node1_factor_A_blk_start, step13_node2_factor_A_blk_start, step13_node3_factor_A_blk_start, };
int** step13_node_factor_B_blk_start[] = {0, step13_node1_factor_B_blk_start, step13_node2_factor_B_blk_start, step13_node3_factor_B_blk_start, };
int** step13_node_factor_blk_width[] = {0, step13_node1_factor_blk_width, step13_node2_factor_blk_width, step13_node3_factor_blk_width, };
int step13_node_parent[] = {0, step13_node1_parent, step13_node2_parent, step13_node3_parent, };
int step13_node_height[] = {0, step13_node1_height, step13_node2_height, step13_node3_height, };
int step13_node_width[] = {0, step13_node1_width, step13_node2_width, step13_node3_width, };
float* step13_node_data[] = {0, step13_node1_data, step13_node2_data, step13_node3_data, };
int step13_node_num_blks[] = {0, step13_node1_num_blks, step13_node2_num_blks, step13_node3_num_blks, };
int* step13_node_A_blk_start[] = {0, step13_node1_A_blk_start, step13_node2_A_blk_start, step13_node3_A_blk_start, };
int* step13_node_B_blk_start[] = {0, step13_node1_B_blk_start, step13_node2_B_blk_start, step13_node3_B_blk_start, };
int* step13_node_blk_width[] = {0, step13_node1_blk_width, step13_node2_blk_width, step13_node3_blk_width, };
int* step13_node_ridx[] = {step13_node0_ridx, step13_node1_ridx, step13_node2_ridx, step13_node3_ridx, };


float step13_x_data[85] = {};
const int step13_workspace_needed = 13752;

