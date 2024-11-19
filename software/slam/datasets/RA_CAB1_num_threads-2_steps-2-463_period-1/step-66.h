#pragma once

const bool step66_is_reconstruct = true;

const int step66_num_threads = 1;

const uint64_t step66_scaled_relin_cost = 60000;

const bool step66_run_model = false;

const int step66_factor216_height = 13;
const int step66_factor216_width = 6;
int step66_factor216_ridx[] = {0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 18, };
float step66_factor216_data[78] = {0};

const int step66_factor216_num_blks = 2;
int step66_factor216_A_blk_start[] = {0, 6, };
int step66_factor216_B_blk_start[] = {0, 12, };
int step66_factor216_blk_width[] = {6, 6, };

const int step66_factor174_height = 13;
const int step66_factor174_width = 6;
int step66_factor174_ridx[] = {18, 19, 20, 21, 22, 23, 54, 55, 56, 57, 58, 59, 72, };
float step66_factor174_data[78] = {0};

const int step66_factor174_num_blks = 2;
int step66_factor174_A_blk_start[] = {0, 6, };
int step66_factor174_B_blk_start[] = {18, 54, };
int step66_factor174_blk_width[] = {6, 6, };

const int step66_factor175_height = 7;
const int step66_factor175_width = 6;
int step66_factor175_ridx[] = {24, 25, 26, 27, 28, 29, 42, };
float step66_factor175_data[42] = {0};

const int step66_factor175_num_blks = 1;
int step66_factor175_A_blk_start[] = {0, };
int step66_factor175_B_blk_start[] = {24, };
int step66_factor175_blk_width[] = {6, };

const int step66_factor176_height = 13;
const int step66_factor176_width = 6;
int step66_factor176_ridx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 42, };
float step66_factor176_data[78] = {0};

const int step66_factor176_num_blks = 1;
int step66_factor176_A_blk_start[] = {0, };
int step66_factor176_B_blk_start[] = {18, };
int step66_factor176_blk_width[] = {12, };

const int step66_factor177_height = 13;
const int step66_factor177_width = 6;
int step66_factor177_ridx[] = {48, 49, 50, 51, 52, 53, 60, 61, 62, 63, 64, 65, 72, };
float step66_factor177_data[78] = {0};

const int step66_factor177_num_blks = 2;
int step66_factor177_A_blk_start[] = {0, 6, };
int step66_factor177_B_blk_start[] = {48, 60, };
int step66_factor177_blk_width[] = {6, 6, };

const int step66_factor178_height = 13;
const int step66_factor178_width = 6;
int step66_factor178_ridx[] = {36, 37, 38, 39, 40, 41, 60, 61, 62, 63, 64, 65, 72, };
float step66_factor178_data[78] = {0};

const int step66_factor178_num_blks = 2;
int step66_factor178_A_blk_start[] = {0, 6, };
int step66_factor178_B_blk_start[] = {36, 60, };
int step66_factor178_blk_width[] = {6, 6, };

const int step66_factor179_height = 13;
const int step66_factor179_width = 6;
int step66_factor179_ridx[] = {30, 31, 32, 33, 34, 35, 60, 61, 62, 63, 64, 65, 72, };
float step66_factor179_data[78] = {0};

const int step66_factor179_num_blks = 2;
int step66_factor179_A_blk_start[] = {0, 6, };
int step66_factor179_B_blk_start[] = {30, 60, };
int step66_factor179_blk_width[] = {6, 6, };

const int step66_factor180_height = 13;
const int step66_factor180_width = 6;
int step66_factor180_ridx[] = {42, 43, 44, 45, 46, 47, 60, 61, 62, 63, 64, 65, 72, };
float step66_factor180_data[78] = {0};

const int step66_factor180_num_blks = 2;
int step66_factor180_A_blk_start[] = {0, 6, };
int step66_factor180_B_blk_start[] = {42, 60, };
int step66_factor180_blk_width[] = {6, 6, };

const int step66_factor181_height = 13;
const int step66_factor181_width = 6;
int step66_factor181_ridx[] = {24, 25, 26, 27, 28, 29, 60, 61, 62, 63, 64, 65, 72, };
float step66_factor181_data[78] = {0};

const int step66_factor181_num_blks = 2;
int step66_factor181_A_blk_start[] = {0, 6, };
int step66_factor181_B_blk_start[] = {24, 60, };
int step66_factor181_blk_width[] = {6, 6, };

const int step66_factor183_height = 13;
const int step66_factor183_width = 6;
int step66_factor183_ridx[] = {12, 13, 14, 15, 16, 17, 36, 37, 38, 39, 40, 41, 42, };
float step66_factor183_data[78] = {0};

const int step66_factor183_num_blks = 2;
int step66_factor183_A_blk_start[] = {0, 6, };
int step66_factor183_B_blk_start[] = {12, 36, };
int step66_factor183_blk_width[] = {6, 6, };

const int step66_factor191_height = 7;
const int step66_factor191_width = 6;
int step66_factor191_ridx[] = {0, 1, 2, 3, 4, 5, 42, };
float step66_factor191_data[42] = {0};

const int step66_factor191_num_blks = 1;
int step66_factor191_A_blk_start[] = {0, };
int step66_factor191_B_blk_start[] = {0, };
int step66_factor191_blk_width[] = {6, };

const int step66_factor192_height = 13;
const int step66_factor192_width = 6;
int step66_factor192_ridx[] = {0, 1, 2, 3, 4, 5, 24, 25, 26, 27, 28, 29, 42, };
float step66_factor192_data[78] = {0};

const int step66_factor192_num_blks = 2;
int step66_factor192_A_blk_start[] = {0, 6, };
int step66_factor192_B_blk_start[] = {0, 24, };
int step66_factor192_blk_width[] = {6, 6, };

const int step66_factor193_height = 13;
const int step66_factor193_width = 6;
int step66_factor193_ridx[] = {0, 1, 2, 3, 4, 5, 24, 25, 26, 27, 28, 29, 42, };
float step66_factor193_data[78] = {0};

const int step66_factor193_num_blks = 2;
int step66_factor193_A_blk_start[] = {0, 6, };
int step66_factor193_B_blk_start[] = {0, 24, };
int step66_factor193_blk_width[] = {6, 6, };

const int step66_factor67_height = 7;
const int step66_factor67_width = 6;
int step66_factor67_ridx[] = {0, 1, 2, 3, 4, 5, 18, };
float step66_factor67_data[42] = {0};

const int step66_factor67_num_blks = 1;
int step66_factor67_A_blk_start[] = {0, };
int step66_factor67_B_blk_start[] = {0, };
int step66_factor67_blk_width[] = {6, };

const int step66_factor68_height = 13;
const int step66_factor68_width = 6;
int step66_factor68_ridx[] = {18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 48, };
float step66_factor68_data[78] = {0};

const int step66_factor68_num_blks = 2;
int step66_factor68_A_blk_start[] = {0, 6, };
int step66_factor68_B_blk_start[] = {18, 42, };
int step66_factor68_blk_width[] = {6, 6, };

const int step66_factor195_height = 13;
const int step66_factor195_width = 6;
int step66_factor195_ridx[] = {0, 1, 2, 3, 4, 5, 30, 31, 32, 33, 34, 35, 48, };
float step66_factor195_data[78] = {0};

const int step66_factor195_num_blks = 2;
int step66_factor195_A_blk_start[] = {0, 6, };
int step66_factor195_B_blk_start[] = {0, 30, };
int step66_factor195_blk_width[] = {6, 6, };

const int step66_factor70_height = 13;
const int step66_factor70_width = 6;
int step66_factor70_ridx[] = {0, 1, 2, 3, 4, 5, 30, 31, 32, 33, 34, 35, 36, };
float step66_factor70_data[78] = {0};

const int step66_factor70_num_blks = 2;
int step66_factor70_A_blk_start[] = {0, 6, };
int step66_factor70_B_blk_start[] = {0, 30, };
int step66_factor70_blk_width[] = {6, 6, };

const int step66_factor198_height = 13;
const int step66_factor198_width = 6;
int step66_factor198_ridx[] = {24, 25, 26, 27, 28, 29, 42, 43, 44, 45, 46, 47, 48, };
float step66_factor198_data[78] = {0};

const int step66_factor198_num_blks = 2;
int step66_factor198_A_blk_start[] = {0, 6, };
int step66_factor198_B_blk_start[] = {24, 42, };
int step66_factor198_blk_width[] = {6, 6, };

const int step66_factor156_height = 13;
const int step66_factor156_width = 6;
int step66_factor156_ridx[] = {18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 48, };
float step66_factor156_data[78] = {0};

const int step66_factor156_num_blks = 2;
int step66_factor156_A_blk_start[] = {0, 6, };
int step66_factor156_B_blk_start[] = {18, 42, };
int step66_factor156_blk_width[] = {6, 6, };

const int step66_factor201_height = 13;
const int step66_factor201_width = 6;
int step66_factor201_ridx[] = {18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 48, };
float step66_factor201_data[78] = {0};

const int step66_factor201_num_blks = 2;
int step66_factor201_A_blk_start[] = {0, 6, };
int step66_factor201_B_blk_start[] = {18, 42, };
int step66_factor201_blk_width[] = {6, 6, };

const int step66_factor162_height = 13;
const int step66_factor162_width = 6;
int step66_factor162_ridx[] = {12, 13, 14, 15, 16, 17, 42, 43, 44, 45, 46, 47, 48, };
float step66_factor162_data[78] = {0};

const int step66_factor162_num_blks = 2;
int step66_factor162_A_blk_start[] = {0, 6, };
int step66_factor162_B_blk_start[] = {12, 42, };
int step66_factor162_blk_width[] = {6, 6, };

const int step66_factor206_height = 7;
const int step66_factor206_width = 6;
int step66_factor206_ridx[] = {12, 13, 14, 15, 16, 17, 42, };
float step66_factor206_data[42] = {0};

const int step66_factor206_num_blks = 1;
int step66_factor206_A_blk_start[] = {0, };
int step66_factor206_B_blk_start[] = {12, };
int step66_factor206_blk_width[] = {6, };

const int step66_factor207_height = 13;
const int step66_factor207_width = 6;
int step66_factor207_ridx[] = {12, 13, 14, 15, 16, 17, 36, 37, 38, 39, 40, 41, 48, };
float step66_factor207_data[78] = {0};

const int step66_factor207_num_blks = 2;
int step66_factor207_A_blk_start[] = {0, 6, };
int step66_factor207_B_blk_start[] = {12, 36, };
int step66_factor207_blk_width[] = {6, 6, };

const int step66_factor208_height = 7;
const int step66_factor208_width = 6;
int step66_factor208_ridx[] = {6, 7, 8, 9, 10, 11, 42, };
float step66_factor208_data[42] = {0};

const int step66_factor208_num_blks = 1;
int step66_factor208_A_blk_start[] = {0, };
int step66_factor208_B_blk_start[] = {6, };
int step66_factor208_blk_width[] = {6, };

const int step66_factor209_height = 13;
const int step66_factor209_width = 6;
int step66_factor209_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 42, };
float step66_factor209_data[78] = {0};

const int step66_factor209_num_blks = 1;
int step66_factor209_A_blk_start[] = {0, };
int step66_factor209_B_blk_start[] = {6, };
int step66_factor209_blk_width[] = {12, };

const int step66_factor167_height = 7;
const int step66_factor167_width = 6;
int step66_factor167_ridx[] = {18, 19, 20, 21, 22, 23, 42, };
float step66_factor167_data[42] = {0};

const int step66_factor167_num_blks = 1;
int step66_factor167_A_blk_start[] = {0, };
int step66_factor167_B_blk_start[] = {18, };
int step66_factor167_blk_width[] = {6, };

const int step66_factor210_height = 13;
const int step66_factor210_width = 6;
int step66_factor210_ridx[] = {18, 19, 20, 21, 22, 23, 30, 31, 32, 33, 34, 35, 42, };
float step66_factor210_data[78] = {0};

const int step66_factor210_num_blks = 2;
int step66_factor210_A_blk_start[] = {0, 6, };
int step66_factor210_B_blk_start[] = {18, 30, };
int step66_factor210_blk_width[] = {6, 6, };

const int step66_factor168_height = 13;
const int step66_factor168_width = 6;
int step66_factor168_ridx[] = {6, 7, 8, 9, 10, 11, 36, 37, 38, 39, 40, 41, 48, };
float step66_factor168_data[78] = {0};

const int step66_factor168_num_blks = 2;
int step66_factor168_A_blk_start[] = {0, 6, };
int step66_factor168_B_blk_start[] = {6, 36, };
int step66_factor168_blk_width[] = {6, 6, };

const int step66_factor211_height = 7;
const int step66_factor211_width = 6;
int step66_factor211_ridx[] = {6, 7, 8, 9, 10, 11, 18, };
float step66_factor211_data[42] = {0};

const int step66_factor211_num_blks = 1;
int step66_factor211_A_blk_start[] = {0, };
int step66_factor211_B_blk_start[] = {6, };
int step66_factor211_blk_width[] = {6, };

const int step66_factor169_height = 13;
const int step66_factor169_width = 6;
int step66_factor169_ridx[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 72, };
float step66_factor169_data[78] = {0};

const int step66_factor169_num_blks = 1;
int step66_factor169_A_blk_start[] = {0, };
int step66_factor169_B_blk_start[] = {48, };
int step66_factor169_blk_width[] = {12, };

const int step66_factor212_height = 13;
const int step66_factor212_width = 6;
int step66_factor212_ridx[] = {6, 7, 8, 9, 10, 11, 36, 37, 38, 39, 40, 41, 42, };
float step66_factor212_data[78] = {0};

const int step66_factor212_num_blks = 2;
int step66_factor212_A_blk_start[] = {0, 6, };
int step66_factor212_B_blk_start[] = {6, 36, };
int step66_factor212_blk_width[] = {6, 6, };

const int step66_factor170_height = 13;
const int step66_factor170_width = 6;
int step66_factor170_ridx[] = {36, 37, 38, 39, 40, 41, 54, 55, 56, 57, 58, 59, 72, };
float step66_factor170_data[78] = {0};

const int step66_factor170_num_blks = 2;
int step66_factor170_A_blk_start[] = {0, 6, };
int step66_factor170_B_blk_start[] = {36, 54, };
int step66_factor170_blk_width[] = {6, 6, };

const int step66_factor213_height = 13;
const int step66_factor213_width = 6;
int step66_factor213_ridx[] = {12, 13, 14, 15, 16, 17, 36, 37, 38, 39, 40, 41, 42, };
float step66_factor213_data[78] = {0};

const int step66_factor213_num_blks = 2;
int step66_factor213_A_blk_start[] = {0, 6, };
int step66_factor213_B_blk_start[] = {12, 36, };
int step66_factor213_blk_width[] = {6, 6, };

const int step66_factor171_height = 13;
const int step66_factor171_width = 6;
int step66_factor171_ridx[] = {30, 31, 32, 33, 34, 35, 54, 55, 56, 57, 58, 59, 72, };
float step66_factor171_data[78] = {0};

const int step66_factor171_num_blks = 2;
int step66_factor171_A_blk_start[] = {0, 6, };
int step66_factor171_B_blk_start[] = {30, 54, };
int step66_factor171_blk_width[] = {6, 6, };

const int step66_factor214_height = 7;
const int step66_factor214_width = 6;
int step66_factor214_ridx[] = {12, 13, 14, 15, 16, 17, 18, };
float step66_factor214_data[42] = {0};

const int step66_factor214_num_blks = 1;
int step66_factor214_A_blk_start[] = {0, };
int step66_factor214_B_blk_start[] = {12, };
int step66_factor214_blk_width[] = {6, };

const int step66_factor172_height = 13;
const int step66_factor172_width = 6;
int step66_factor172_ridx[] = {42, 43, 44, 45, 46, 47, 54, 55, 56, 57, 58, 59, 72, };
float step66_factor172_data[78] = {0};

const int step66_factor172_num_blks = 2;
int step66_factor172_A_blk_start[] = {0, 6, };
int step66_factor172_B_blk_start[] = {42, 54, };
int step66_factor172_blk_width[] = {6, 6, };

const int step66_factor215_height = 13;
const int step66_factor215_width = 6;
int step66_factor215_ridx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, };
float step66_factor215_data[78] = {0};

const int step66_factor215_num_blks = 1;
int step66_factor215_A_blk_start[] = {0, };
int step66_factor215_B_blk_start[] = {6, };
int step66_factor215_blk_width[] = {12, };

const int step66_factor173_height = 13;
const int step66_factor173_width = 6;
int step66_factor173_ridx[] = {24, 25, 26, 27, 28, 29, 54, 55, 56, 57, 58, 59, 72, };
float step66_factor173_data[78] = {0};

const int step66_factor173_num_blks = 2;
int step66_factor173_A_blk_start[] = {0, 6, };
int step66_factor173_B_blk_start[] = {24, 54, };
int step66_factor173_blk_width[] = {6, 6, };

const int step66_node4_num_factors = 1;
const int step66_node4_relin_cost = 0;
const int step66_node4_sym_cost = 16000;
const bool step66_node4_marked = false;
const bool step66_node4_fixed = true;
int step66_node4_factor_height[] = {step66_factor70_height, };
int step66_node4_factor_width[] = {step66_factor70_width, };
int* step66_node4_factor_ridx[] = {step66_factor70_ridx, };
float* step66_node4_factor_data[] = {step66_factor70_data, };
int step66_node4_factor_num_blks[] = {step66_factor70_num_blks, };
int* step66_node4_factor_A_blk_start[] = {step66_factor70_A_blk_start, };
int* step66_node4_factor_B_blk_start[] = {step66_factor70_B_blk_start, };
int* step66_node4_factor_blk_width[] = {step66_factor70_blk_width, };
const int step66_node4_parent = 11;
const int step66_node4_height = 37;
const int step66_node4_width = 24;
float step66_node4_data[888] = {0};
const int step66_node4_num_blks = 2;
int step66_node4_A_blk_start[] = {0, 6, };
int step66_node4_B_blk_start[] = {48, 66, };
int step66_node4_blk_width[] = {6, 6, };


const int step66_node5_num_factors = 3;
const int step66_node5_relin_cost = 0;
const int step66_node5_sym_cost = 16000;
const bool step66_node5_marked = false;
const bool step66_node5_fixed = true;
int step66_node5_factor_height[] = {step66_factor156_height, step66_factor162_height, step66_factor168_height, };
int step66_node5_factor_width[] = {step66_factor156_width, step66_factor162_width, step66_factor168_width, };
int* step66_node5_factor_ridx[] = {step66_factor156_ridx, step66_factor162_ridx, step66_factor168_ridx, };
float* step66_node5_factor_data[] = {step66_factor156_data, step66_factor162_data, step66_factor168_data, };
int step66_node5_factor_num_blks[] = {step66_factor156_num_blks, step66_factor162_num_blks, step66_factor168_num_blks, };
int* step66_node5_factor_A_blk_start[] = {step66_factor156_A_blk_start, step66_factor162_A_blk_start, step66_factor168_A_blk_start, };
int* step66_node5_factor_B_blk_start[] = {step66_factor156_B_blk_start, step66_factor162_B_blk_start, step66_factor168_B_blk_start, };
int* step66_node5_factor_blk_width[] = {step66_factor156_blk_width, step66_factor162_blk_width, step66_factor168_blk_width, };
const int step66_node5_parent = 9;
const int step66_node5_height = 49;
const int step66_node5_width = 24;
float step66_node5_data[1176] = {0};
const int step66_node5_num_blks = 2;
int step66_node5_A_blk_start[] = {0, 12, };
int step66_node5_B_blk_start[] = {18, 36, };
int step66_node5_blk_width[] = {12, 12, };


const int step66_node7_num_factors = 4;
const int step66_node7_relin_cost = 20000;
const int step66_node7_sym_cost = 20000;
const bool step66_node7_marked = false;
const bool step66_node7_fixed = true;
int step66_node7_factor_height[] = {step66_factor195_height, step66_factor198_height, step66_factor201_height, step66_factor207_height, };
int step66_node7_factor_width[] = {step66_factor195_width, step66_factor198_width, step66_factor201_width, step66_factor207_width, };
int* step66_node7_factor_ridx[] = {step66_factor195_ridx, step66_factor198_ridx, step66_factor201_ridx, step66_factor207_ridx, };
float* step66_node7_factor_data[] = {step66_factor195_data, step66_factor198_data, step66_factor201_data, step66_factor207_data, };
int step66_node7_factor_num_blks[] = {step66_factor195_num_blks, step66_factor198_num_blks, step66_factor201_num_blks, step66_factor207_num_blks, };
int* step66_node7_factor_A_blk_start[] = {step66_factor195_A_blk_start, step66_factor198_A_blk_start, step66_factor201_A_blk_start, step66_factor207_A_blk_start, };
int* step66_node7_factor_B_blk_start[] = {step66_factor195_B_blk_start, step66_factor198_B_blk_start, step66_factor201_B_blk_start, step66_factor207_B_blk_start, };
int* step66_node7_factor_blk_width[] = {step66_factor195_blk_width, step66_factor198_blk_width, step66_factor201_blk_width, step66_factor207_blk_width, };
const int step66_node7_parent = 12;
const int step66_node7_height = 49;
const int step66_node7_width = 30;
float step66_node7_data[1470] = {0};
const int step66_node7_num_blks = 2;
int step66_node7_A_blk_start[] = {0, 6, };
int step66_node7_B_blk_start[] = {0, 12, };
int step66_node7_blk_width[] = {6, 12, };


const int step66_node8_num_factors = 3;
const int step66_node8_relin_cost = 0;
const int step66_node8_sym_cost = 16000;
const bool step66_node8_marked = false;
const bool step66_node8_fixed = true;
int step66_node8_factor_height[] = {step66_factor183_height, step66_factor192_height, step66_factor210_height, };
int step66_node8_factor_width[] = {step66_factor183_width, step66_factor192_width, step66_factor210_width, };
int* step66_node8_factor_ridx[] = {step66_factor183_ridx, step66_factor192_ridx, step66_factor210_ridx, };
float* step66_node8_factor_data[] = {step66_factor183_data, step66_factor192_data, step66_factor210_data, };
int step66_node8_factor_num_blks[] = {step66_factor183_num_blks, step66_factor192_num_blks, step66_factor210_num_blks, };
int* step66_node8_factor_A_blk_start[] = {step66_factor183_A_blk_start, step66_factor192_A_blk_start, step66_factor210_A_blk_start, };
int* step66_node8_factor_B_blk_start[] = {step66_factor183_B_blk_start, step66_factor192_B_blk_start, step66_factor210_B_blk_start, };
int* step66_node8_factor_blk_width[] = {step66_factor183_blk_width, step66_factor192_blk_width, step66_factor210_blk_width, };
const int step66_node8_parent = 12;
const int step66_node8_height = 43;
const int step66_node8_width = 24;
float step66_node8_data[1032] = {0};
const int step66_node8_num_blks = 2;
int step66_node8_A_blk_start[] = {0, 12, };
int step66_node8_B_blk_start[] = {0, 24, };
int step66_node8_blk_width[] = {12, 6, };


const int step66_node9_num_factors = 1;
const int step66_node9_relin_cost = 0;
const int step66_node9_sym_cost = 16000;
const bool step66_node9_marked = false;
const bool step66_node9_fixed = true;
int step66_node9_factor_height[] = {step66_factor68_height, };
int step66_node9_factor_width[] = {step66_factor68_width, };
int* step66_node9_factor_ridx[] = {step66_factor68_ridx, };
float* step66_node9_factor_data[] = {step66_factor68_data, };
int step66_node9_factor_num_blks[] = {step66_factor68_num_blks, };
int* step66_node9_factor_A_blk_start[] = {step66_factor68_A_blk_start, };
int* step66_node9_factor_B_blk_start[] = {step66_factor68_B_blk_start, };
int* step66_node9_factor_blk_width[] = {step66_factor68_blk_width, };
const int step66_node9_parent = 10;
const int step66_node9_height = 49;
const int step66_node9_width = 24;
float step66_node9_data[1176] = {0};
const int step66_node9_num_blks = 2;
int step66_node9_A_blk_start[] = {0, 12, };
int step66_node9_B_blk_start[] = {12, 48, };
int step66_node9_blk_width[] = {12, 12, };


const int step66_node10_num_factors = 0;
const int step66_node10_relin_cost = 0;
const int step66_node10_sym_cost = 16000;
const bool step66_node10_marked = false;
const bool step66_node10_fixed = true;
int step66_node10_factor_height[] = {};
int step66_node10_factor_width[] = {};
int* step66_node10_factor_ridx[] = {};
float* step66_node10_factor_data[] = {};
int step66_node10_factor_num_blks[] = {};
int* step66_node10_factor_A_blk_start[] = {};
int* step66_node10_factor_B_blk_start[] = {};
int* step66_node10_factor_blk_width[] = {};
const int step66_node10_parent = 11;
const int step66_node10_height = 61;
const int step66_node10_width = 24;
float step66_node10_data[1464] = {0};
const int step66_node10_num_blks = 3;
int step66_node10_A_blk_start[] = {0, 24, 30, };
int step66_node10_B_blk_start[] = {18, 54, 66, };
int step66_node10_blk_width[] = {24, 6, 6, };


const int step66_node11_num_factors = 11;
const int step66_node11_relin_cost = 0;
const int step66_node11_sym_cost = 36000;
const bool step66_node11_marked = false;
const bool step66_node11_fixed = true;
int step66_node11_factor_height[] = {step66_factor169_height, step66_factor170_height, step66_factor171_height, step66_factor172_height, step66_factor173_height, step66_factor174_height, step66_factor177_height, step66_factor178_height, step66_factor179_height, step66_factor180_height, step66_factor181_height, };
int step66_node11_factor_width[] = {step66_factor169_width, step66_factor170_width, step66_factor171_width, step66_factor172_width, step66_factor173_width, step66_factor174_width, step66_factor177_width, step66_factor178_width, step66_factor179_width, step66_factor180_width, step66_factor181_width, };
int* step66_node11_factor_ridx[] = {step66_factor169_ridx, step66_factor170_ridx, step66_factor171_ridx, step66_factor172_ridx, step66_factor173_ridx, step66_factor174_ridx, step66_factor177_ridx, step66_factor178_ridx, step66_factor179_ridx, step66_factor180_ridx, step66_factor181_ridx, };
float* step66_node11_factor_data[] = {step66_factor169_data, step66_factor170_data, step66_factor171_data, step66_factor172_data, step66_factor173_data, step66_factor174_data, step66_factor177_data, step66_factor178_data, step66_factor179_data, step66_factor180_data, step66_factor181_data, };
int step66_node11_factor_num_blks[] = {step66_factor169_num_blks, step66_factor170_num_blks, step66_factor171_num_blks, step66_factor172_num_blks, step66_factor173_num_blks, step66_factor174_num_blks, step66_factor177_num_blks, step66_factor178_num_blks, step66_factor179_num_blks, step66_factor180_num_blks, step66_factor181_num_blks, };
int* step66_node11_factor_A_blk_start[] = {step66_factor169_A_blk_start, step66_factor170_A_blk_start, step66_factor171_A_blk_start, step66_factor172_A_blk_start, step66_factor173_A_blk_start, step66_factor174_A_blk_start, step66_factor177_A_blk_start, step66_factor178_A_blk_start, step66_factor179_A_blk_start, step66_factor180_A_blk_start, step66_factor181_A_blk_start, };
int* step66_node11_factor_B_blk_start[] = {step66_factor169_B_blk_start, step66_factor170_B_blk_start, step66_factor171_B_blk_start, step66_factor172_B_blk_start, step66_factor173_B_blk_start, step66_factor174_B_blk_start, step66_factor177_B_blk_start, step66_factor178_B_blk_start, step66_factor179_B_blk_start, step66_factor180_B_blk_start, step66_factor181_B_blk_start, };
int* step66_node11_factor_blk_width[] = {step66_factor169_blk_width, step66_factor170_blk_width, step66_factor171_blk_width, step66_factor172_blk_width, step66_factor173_blk_width, step66_factor174_blk_width, step66_factor177_blk_width, step66_factor178_blk_width, step66_factor179_blk_width, step66_factor180_blk_width, step66_factor181_blk_width, };
const int step66_node11_parent = 12;
const int step66_node11_height = 73;
const int step66_node11_width = 54;
float step66_node11_data[3942] = {0};
const int step66_node11_num_blks = 1;
int step66_node11_A_blk_start[] = {0, };
int step66_node11_B_blk_start[] = {18, };
int step66_node11_blk_width[] = {18, };


const int step66_node12_num_factors = 10;
const int step66_node12_relin_cost = 40000;
const int step66_node12_sym_cost = 20000;
const bool step66_node12_marked = true;
const bool step66_node12_fixed = false;
int step66_node12_factor_height[] = {step66_factor167_height, step66_factor175_height, step66_factor176_height, step66_factor191_height, step66_factor193_height, step66_factor206_height, step66_factor208_height, step66_factor209_height, step66_factor212_height, step66_factor213_height, };
int step66_node12_factor_width[] = {step66_factor167_width, step66_factor175_width, step66_factor176_width, step66_factor191_width, step66_factor193_width, step66_factor206_width, step66_factor208_width, step66_factor209_width, step66_factor212_width, step66_factor213_width, };
int* step66_node12_factor_ridx[] = {step66_factor167_ridx, step66_factor175_ridx, step66_factor176_ridx, step66_factor191_ridx, step66_factor193_ridx, step66_factor206_ridx, step66_factor208_ridx, step66_factor209_ridx, step66_factor212_ridx, step66_factor213_ridx, };
float* step66_node12_factor_data[] = {step66_factor167_data, step66_factor175_data, step66_factor176_data, step66_factor191_data, step66_factor193_data, step66_factor206_data, step66_factor208_data, step66_factor209_data, step66_factor212_data, step66_factor213_data, };
int step66_node12_factor_num_blks[] = {step66_factor167_num_blks, step66_factor175_num_blks, step66_factor176_num_blks, step66_factor191_num_blks, step66_factor193_num_blks, step66_factor206_num_blks, step66_factor208_num_blks, step66_factor209_num_blks, step66_factor212_num_blks, step66_factor213_num_blks, };
int* step66_node12_factor_A_blk_start[] = {step66_factor167_A_blk_start, step66_factor175_A_blk_start, step66_factor176_A_blk_start, step66_factor191_A_blk_start, step66_factor193_A_blk_start, step66_factor206_A_blk_start, step66_factor208_A_blk_start, step66_factor209_A_blk_start, step66_factor212_A_blk_start, step66_factor213_A_blk_start, };
int* step66_node12_factor_B_blk_start[] = {step66_factor167_B_blk_start, step66_factor175_B_blk_start, step66_factor176_B_blk_start, step66_factor191_B_blk_start, step66_factor193_B_blk_start, step66_factor206_B_blk_start, step66_factor208_B_blk_start, step66_factor209_B_blk_start, step66_factor212_B_blk_start, step66_factor213_B_blk_start, };
int* step66_node12_factor_blk_width[] = {step66_factor167_blk_width, step66_factor175_blk_width, step66_factor176_blk_width, step66_factor191_blk_width, step66_factor193_blk_width, step66_factor206_blk_width, step66_factor208_blk_width, step66_factor209_blk_width, step66_factor212_blk_width, step66_factor213_blk_width, };
const int step66_node12_parent = 13;
const int step66_node12_height = 43;
const int step66_node12_width = 30;
float step66_node12_data[1290] = {0};
const int step66_node12_num_blks = 1;
int step66_node12_A_blk_start[] = {0, };
int step66_node12_B_blk_start[] = {0, };
int step66_node12_blk_width[] = {12, };


const int step66_node13_num_factors = 5;
const int step66_node13_relin_cost = 0;
const int step66_node13_sym_cost = 12000;
const bool step66_node13_marked = true;
const bool step66_node13_fixed = false;
int step66_node13_factor_height[] = {step66_factor67_height, step66_factor211_height, step66_factor214_height, step66_factor215_height, step66_factor216_height, };
int step66_node13_factor_width[] = {step66_factor67_width, step66_factor211_width, step66_factor214_width, step66_factor215_width, step66_factor216_width, };
int* step66_node13_factor_ridx[] = {step66_factor67_ridx, step66_factor211_ridx, step66_factor214_ridx, step66_factor215_ridx, step66_factor216_ridx, };
float* step66_node13_factor_data[] = {step66_factor67_data, step66_factor211_data, step66_factor214_data, step66_factor215_data, step66_factor216_data, };
int step66_node13_factor_num_blks[] = {step66_factor67_num_blks, step66_factor211_num_blks, step66_factor214_num_blks, step66_factor215_num_blks, step66_factor216_num_blks, };
int* step66_node13_factor_A_blk_start[] = {step66_factor67_A_blk_start, step66_factor211_A_blk_start, step66_factor214_A_blk_start, step66_factor215_A_blk_start, step66_factor216_A_blk_start, };
int* step66_node13_factor_B_blk_start[] = {step66_factor67_B_blk_start, step66_factor211_B_blk_start, step66_factor214_B_blk_start, step66_factor215_B_blk_start, step66_factor216_B_blk_start, };
int* step66_node13_factor_blk_width[] = {step66_factor67_blk_width, step66_factor211_blk_width, step66_factor214_blk_width, step66_factor215_blk_width, step66_factor216_blk_width, };
const int step66_node13_parent = 14;
const int step66_node13_height = 19;
const int step66_node13_width = 18;
float step66_node13_data[342] = {0};
const int step66_node13_num_blks = 0;
int step66_node13_A_blk_start[] = {};
int step66_node13_B_blk_start[] = {};
int step66_node13_blk_width[] = {};


const int step66_node14_num_factors = 0;
const int step66_node14_relin_cost = 0;
const int step66_node14_sym_cost = 4000;
const bool step66_node14_marked = true;
const bool step66_node14_fixed = false;
int step66_node14_factor_height[] = {};
int step66_node14_factor_width[] = {};
int* step66_node14_factor_ridx[] = {};
float* step66_node14_factor_data[] = {};
int step66_node14_factor_num_blks[] = {};
int* step66_node14_factor_A_blk_start[] = {};
int* step66_node14_factor_B_blk_start[] = {};
int* step66_node14_factor_blk_width[] = {};
const int step66_node14_parent = -1;
const int step66_node14_height = 1;
const int step66_node14_width = 1;
float step66_node14_data[1] = {0};
const int step66_node14_num_blks = 0;
int step66_node14_A_blk_start[] = {};
int step66_node14_B_blk_start[] = {};
int step66_node14_blk_width[] = {};


int step66_node0_ridx[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 42, 43, 44, 45, 46, 47, 402, };
int step66_node1_ridx[] = {
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 402, };
int step66_node2_ridx[] = {
54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 108, 109, 110, 111, 112, 113, 402, };
int step66_node3_ridx[] = {
90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 294, 295, 296, 297, 298, 299, 318, 319, 320, 321, 322, 323, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 402, };
int step66_node4_ridx[] = {
114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 348, 349, 350, 351, 352, 353, 384, 385, 386, 387, 388, 389, 402, };
int step66_node5_ridx[] = {
138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 270, 271, 272, 273, 274, 275, 288, 289, 290, 291, 292, 293, 372, 373, 374, 375, 376, 377, 384, 385, 386, 387, 388, 389, 402, };
int step66_node6_ridx[] = {
162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 402, };
int step66_node7_ridx[] = {
198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 354, 355, 356, 357, 358, 359, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 402, };
int step66_node8_ridx[] = {
228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 378, 379, 380, 381, 382, 383, 402, };
int step66_node9_ridx[] = {
252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 372, 373, 374, 375, 376, 377, 384, 385, 386, 387, 388, 389, 402, };
int step66_node10_ridx[] = {
276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 372, 373, 374, 375, 376, 377, 384, 385, 386, 387, 388, 389, 402, };
int step66_node11_ridx[] = {
300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 402, };
int step66_node12_ridx[] = {
354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 402, };
int step66_node13_ridx[] = {
384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, };
int step66_node14_ridx[] = {
402, };
const int step66_nnodes = 15;
bool step66_node_marked[] = {false, false, false, false, step66_node4_marked, step66_node5_marked, false, step66_node7_marked, step66_node8_marked, step66_node9_marked, step66_node10_marked, step66_node11_marked, step66_node12_marked, step66_node13_marked, step66_node14_marked, };
bool step66_node_fixed[] = {false, false, false, false, step66_node4_fixed, step66_node5_fixed, false, step66_node7_fixed, step66_node8_fixed, step66_node9_fixed, step66_node10_fixed, step66_node11_fixed, step66_node12_fixed, step66_node13_fixed, step66_node14_fixed, };
int step66_node_num_factors[] = {0, 0, 0, 0, step66_node4_num_factors, step66_node5_num_factors, 0, step66_node7_num_factors, step66_node8_num_factors, step66_node9_num_factors, step66_node10_num_factors, step66_node11_num_factors, step66_node12_num_factors, step66_node13_num_factors, step66_node14_num_factors, };
int step66_node_relin_cost[] = {0, 0, 0, 0, step66_node4_relin_cost, step66_node5_relin_cost, 0, step66_node7_relin_cost, step66_node8_relin_cost, step66_node9_relin_cost, step66_node10_relin_cost, step66_node11_relin_cost, step66_node12_relin_cost, step66_node13_relin_cost, step66_node14_relin_cost, };
int step66_node_sym_cost[] = {0, 0, 0, 0, step66_node4_sym_cost, step66_node5_sym_cost, 0, step66_node7_sym_cost, step66_node8_sym_cost, step66_node9_sym_cost, step66_node10_sym_cost, step66_node11_sym_cost, step66_node12_sym_cost, step66_node13_sym_cost, step66_node14_sym_cost, };
int* step66_node_factor_height[] = {0, 0, 0, 0, step66_node4_factor_height, step66_node5_factor_height, 0, step66_node7_factor_height, step66_node8_factor_height, step66_node9_factor_height, step66_node10_factor_height, step66_node11_factor_height, step66_node12_factor_height, step66_node13_factor_height, step66_node14_factor_height, };
int* step66_node_factor_width[] = {0, 0, 0, 0, step66_node4_factor_width, step66_node5_factor_width, 0, step66_node7_factor_width, step66_node8_factor_width, step66_node9_factor_width, step66_node10_factor_width, step66_node11_factor_width, step66_node12_factor_width, step66_node13_factor_width, step66_node14_factor_width, };
int** step66_node_factor_ridx[] = {0, 0, 0, 0, step66_node4_factor_ridx, step66_node5_factor_ridx, 0, step66_node7_factor_ridx, step66_node8_factor_ridx, step66_node9_factor_ridx, step66_node10_factor_ridx, step66_node11_factor_ridx, step66_node12_factor_ridx, step66_node13_factor_ridx, step66_node14_factor_ridx, };
float** step66_node_factor_data[] = {0, 0, 0, 0, step66_node4_factor_data, step66_node5_factor_data, 0, step66_node7_factor_data, step66_node8_factor_data, step66_node9_factor_data, step66_node10_factor_data, step66_node11_factor_data, step66_node12_factor_data, step66_node13_factor_data, step66_node14_factor_data, };
int* step66_node_factor_num_blks[] = {0, 0, 0, 0, step66_node4_factor_num_blks, step66_node5_factor_num_blks, 0, step66_node7_factor_num_blks, step66_node8_factor_num_blks, step66_node9_factor_num_blks, step66_node10_factor_num_blks, step66_node11_factor_num_blks, step66_node12_factor_num_blks, step66_node13_factor_num_blks, step66_node14_factor_num_blks, };
int** step66_node_factor_A_blk_start[] = {0, 0, 0, 0, step66_node4_factor_A_blk_start, step66_node5_factor_A_blk_start, 0, step66_node7_factor_A_blk_start, step66_node8_factor_A_blk_start, step66_node9_factor_A_blk_start, step66_node10_factor_A_blk_start, step66_node11_factor_A_blk_start, step66_node12_factor_A_blk_start, step66_node13_factor_A_blk_start, step66_node14_factor_A_blk_start, };
int** step66_node_factor_B_blk_start[] = {0, 0, 0, 0, step66_node4_factor_B_blk_start, step66_node5_factor_B_blk_start, 0, step66_node7_factor_B_blk_start, step66_node8_factor_B_blk_start, step66_node9_factor_B_blk_start, step66_node10_factor_B_blk_start, step66_node11_factor_B_blk_start, step66_node12_factor_B_blk_start, step66_node13_factor_B_blk_start, step66_node14_factor_B_blk_start, };
int** step66_node_factor_blk_width[] = {0, 0, 0, 0, step66_node4_factor_blk_width, step66_node5_factor_blk_width, 0, step66_node7_factor_blk_width, step66_node8_factor_blk_width, step66_node9_factor_blk_width, step66_node10_factor_blk_width, step66_node11_factor_blk_width, step66_node12_factor_blk_width, step66_node13_factor_blk_width, step66_node14_factor_blk_width, };
int step66_node_parent[] = {0, 0, 0, 0, step66_node4_parent, step66_node5_parent, 0, step66_node7_parent, step66_node8_parent, step66_node9_parent, step66_node10_parent, step66_node11_parent, step66_node12_parent, step66_node13_parent, step66_node14_parent, };
int step66_node_height[] = {0, 0, 0, 0, step66_node4_height, step66_node5_height, 0, step66_node7_height, step66_node8_height, step66_node9_height, step66_node10_height, step66_node11_height, step66_node12_height, step66_node13_height, step66_node14_height, };
int step66_node_width[] = {0, 0, 0, 0, step66_node4_width, step66_node5_width, 0, step66_node7_width, step66_node8_width, step66_node9_width, step66_node10_width, step66_node11_width, step66_node12_width, step66_node13_width, step66_node14_width, };
float* step66_node_data[] = {0, 0, 0, 0, step66_node4_data, step66_node5_data, 0, step66_node7_data, step66_node8_data, step66_node9_data, step66_node10_data, step66_node11_data, step66_node12_data, step66_node13_data, step66_node14_data, };
int step66_node_num_blks[] = {0, 0, 0, 0, step66_node4_num_blks, step66_node5_num_blks, 0, step66_node7_num_blks, step66_node8_num_blks, step66_node9_num_blks, step66_node10_num_blks, step66_node11_num_blks, step66_node12_num_blks, step66_node13_num_blks, step66_node14_num_blks, };
int* step66_node_A_blk_start[] = {0, 0, 0, 0, step66_node4_A_blk_start, step66_node5_A_blk_start, 0, step66_node7_A_blk_start, step66_node8_A_blk_start, step66_node9_A_blk_start, step66_node10_A_blk_start, step66_node11_A_blk_start, step66_node12_A_blk_start, step66_node13_A_blk_start, step66_node14_A_blk_start, };
int* step66_node_B_blk_start[] = {0, 0, 0, 0, step66_node4_B_blk_start, step66_node5_B_blk_start, 0, step66_node7_B_blk_start, step66_node8_B_blk_start, step66_node9_B_blk_start, step66_node10_B_blk_start, step66_node11_B_blk_start, step66_node12_B_blk_start, step66_node13_B_blk_start, step66_node14_B_blk_start, };
int* step66_node_blk_width[] = {0, 0, 0, 0, step66_node4_blk_width, step66_node5_blk_width, 0, step66_node7_blk_width, step66_node8_blk_width, step66_node9_blk_width, step66_node10_blk_width, step66_node11_blk_width, step66_node12_blk_width, step66_node13_blk_width, step66_node14_blk_width, };
int* step66_node_ridx[] = {step66_node0_ridx, step66_node1_ridx, step66_node2_ridx, step66_node3_ridx, step66_node4_ridx, step66_node5_ridx, step66_node6_ridx, step66_node7_ridx, step66_node8_ridx, step66_node9_ridx, step66_node10_ridx, step66_node11_ridx, step66_node12_ridx, step66_node13_ridx, step66_node14_ridx, };


float step66_x_data[403] = {};
const int step66_workspace_needed = 87728;

