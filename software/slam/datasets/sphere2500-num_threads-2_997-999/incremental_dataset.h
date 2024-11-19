#pragma once

#include "step-997.h"
#include "step-998.h"


const bool no_values = true;

const int timestep_start = 997;

#define NUM_TIMESTEPS 2

const int num_timesteps = 2;

#define MAX_NNODE 180

#define MAX_FACTOR_HEIGHT 13

#define MAX_FACTOR_WIDTH 6

const int max_factor_height = 13;
const int max_factor_width = 6;

bool step_is_reconstruct[] = {step997_is_reconstruct, step998_is_reconstruct, };
int step_num_threads[] = {step997_num_threads, step998_num_threads, };
bool step_run_model[] = {step997_run_model, step998_run_model, };
int step_nnodes[] = {step997_nnodes, step998_nnodes, };
bool* step_node_marked[] = {step997_node_marked, step998_node_marked, };
bool* step_node_fixed[] = {step997_node_fixed, step998_node_fixed, };
int* step_node_num_factors[] = {step997_node_num_factors, step998_node_num_factors, };
int** step_node_factor_height[] = {step997_node_factor_height, step998_node_factor_height, };
int** step_node_factor_width[] = {step997_node_factor_width, step998_node_factor_width, };
int*** step_node_factor_ridx[] = {step997_node_factor_ridx, step998_node_factor_ridx, };
float*** step_node_factor_data[] = {step997_node_factor_data, step998_node_factor_data, };
int** step_node_factor_num_blks[] = {step997_node_factor_num_blks, step998_node_factor_num_blks, };
int*** step_node_factor_A_blk_start[] = {step997_node_factor_A_blk_start, step998_node_factor_A_blk_start, };
int*** step_node_factor_B_blk_start[] = {step997_node_factor_B_blk_start, step998_node_factor_B_blk_start, };
int*** step_node_factor_blk_width[] = {step997_node_factor_blk_width, step998_node_factor_blk_width, };
int* step_node_parent[] = {step997_node_parent, step998_node_parent, };
int* step_node_height[] = {step997_node_height, step998_node_height, };
int* step_node_width[] = {step997_node_width, step998_node_width, };
float** step_node_data[] = {step997_node_data, step998_node_data, };
int* step_node_num_blks[] = {step997_node_num_blks, step998_node_num_blks, };
int** step_node_A_blk_start[] = {step997_node_A_blk_start, step998_node_A_blk_start, };
int** step_node_B_blk_start[] = {step997_node_B_blk_start, step998_node_B_blk_start, };
int** step_node_blk_width[] = {step997_node_blk_width, step998_node_blk_width, };
int** step_node_ridx[] = {step997_node_ridx, step998_node_ridx, };
float* step_x_data[] = {step997_x_data, step998_x_data, };


