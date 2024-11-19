#ifndef WORKLOAD
#define WORKLOAD 1

#ifndef MAX_NNODE
#define MAX_NNODE 1000
#endif

#ifndef PRINT_MORE
#define PRINT_MORE 0
#endif

#define PRINT_DEBUG false

float** node_arr = NULL;
//pthread_mutex_t* node_locks;
int* node_num_children;
int* node_done_children;

pthread_barrier_t barrier_slam;
pthread_mutex_t queue_lock;
pthread_mutex_t node_locks[MAX_NNODE]; // to track parent node that is written
int node_ready_index = 0;
int node_ready_size = 0;
int* node_ready_queue;
int num_active_nodes = 0;
int curr_add_parent[NUM_CORE] = {0};
uint64_t* node_time; // TODO: AtA/cholesky breakdown 
uint64_t* AtA_time;
uint64_t* merge_time;
uint64_t* chol_time;
uint64_t* init_time;
uint64_t* backsolve_time;
uint64_t** AtA_profile_cycles;
uint64_t** merge_profile_cycles;
uint64_t** chol_profile_cycles;
uint64_t** init_profile_cycles;
uint64_t** backsolve_profile_cycles;
int* node_thread;
int* node_corunning;
int* chol_num_array;
int* backsolve_thread;
bool* did_memset;

int backsolve_ready_index = 0;
int backsolve_ready_size = 0;
int** backsolve_children;
int* backsolve_ready_queue;

bool active_thread[NUM_CORE] = {0};

//uint64_t total_dnn_cycles[2][MAX_DNN_STEP] = {0};
//uint64_t total_slam_cycles[num_timesteps] = {0};

void step_setup(int step, int num_max_thread){
  
  for(int i = 0; i < num_max_thread; i++){
    curr_add_parent[i] = -1;
    active_thread[i] = true;
  }
  int true_step = step + timestep_start;
  printf("step = %d\n", true_step);

  int nnodes = step_nnodes[step];

  bool* node_marked = step_node_marked[step];
  bool* node_fixed = step_node_fixed[step];

  int* node_parent = step_node_parent[step];
  int* node_height = step_node_height[step];

  int* node_num_factors = step_node_num_factors[step];
  
  node_num_children = malloc(nnodes * sizeof(int));
  node_done_children = malloc(nnodes * sizeof(int));
  node_ready_queue = malloc(nnodes * sizeof(int));
  memset(node_num_children, 0, nnodes * sizeof(int));
  memset(node_done_children, 0, nnodes * sizeof(int));
  
  node_thread = malloc(nnodes*sizeof(int));
  memset(node_thread, 0, nnodes*sizeof(int));
  node_corunning = malloc(nnodes*sizeof(int));
  memset(node_corunning, 0, nnodes*sizeof(int));
  chol_num_array = malloc(nnodes*sizeof(int));
  memset(chol_num_array, 0, nnodes*sizeof(int));
  backsolve_thread = malloc(nnodes*sizeof(int));
  memset(backsolve_thread, 0, nnodes*sizeof(int));
  node_time = malloc(nnodes*sizeof(uint64_t));
  memset(node_time, 0, nnodes*sizeof(uint64_t));
  init_time = malloc(nnodes*sizeof(uint64_t));
  AtA_time = malloc(nnodes*sizeof(uint64_t));
  merge_time = malloc(nnodes*sizeof(uint64_t));
  chol_time = malloc(nnodes*sizeof(uint64_t));
  backsolve_time = malloc(nnodes*sizeof(uint64_t));
  memset(backsolve_time, 0, nnodes*sizeof(uint64_t));
#if PRINT_MORE == 1
  did_memset = malloc(nnodes*sizeof(bool));
  memset(did_memset, 0, nnodes*sizeof(bool));
#endif
  num_active_nodes = 0;
  node_ready_size = 0;
  node_ready_index = 0; 

  for(int node = 0; node < nnodes - 1; node++) {
      bool marked = node_marked[node];
      bool fixed = node_fixed[node];

      if(!marked && !fixed) { continue; }

      num_active_nodes++;

      if(node_num_children[node] == 0) {
          node_ready_queue[node_ready_size] = node;
          node_ready_size++;
      }

      int parent = node_parent[node];
      node_num_children[parent]++;
  }

  node_arr = malloc(nnodes * sizeof(float*));
  memset(node_arr, 0, nnodes * sizeof(float*));
  
  printf("active node size: %d\n", num_active_nodes);
  //printf("num children: \n");
  //for(int node = 0; node < nnodes - 1; node++) {
  //    printf("%d ", node_num_children[node]);
  //}
  //printf("\n");
  
  backsolve_ready_index = 0;
  backsolve_ready_size = 0;
  backsolve_ready_queue = malloc(nnodes * sizeof(int));
  backsolve_children = malloc(nnodes * sizeof(int*));
  memset(backsolve_children, 0, nnodes * sizeof(int*));
  // Backsolve. First set up a list of children for each node
  for(int node = nnodes - 2; node >= 0; node--) {
      bool marked = node_marked[node];
      bool fixed = node_fixed[node];

      if(!marked && !fixed) { continue; }

      backsolve_children[node] = malloc(node_num_children[node] * sizeof(int));

      // Reset this so we can have some sort of indexing
      node_num_children[node] = 0;

      int parent = node_parent[node];
      if(parent == nnodes - 1) {
          backsolve_ready_queue[backsolve_ready_size] = node;
          backsolve_ready_size++;
      }
      else {
          backsolve_children[parent][node_num_children[parent]] = node;
          node_num_children[parent]++;
      }
  }
}

void profile_setup(int nstep){
  AtA_profile_cycles = malloc(nstep*sizeof(uint64_t*));
  chol_profile_cycles = malloc(nstep*sizeof(uint64_t*));
  merge_profile_cycles = malloc(nstep*sizeof(uint64_t*));
  init_profile_cycles = malloc(nstep*sizeof(uint64_t*));
  backsolve_profile_cycles = malloc(nstep*sizeof(uint64_t*));
  for(int step = 0; step < nstep; step ++){
    int nnodes = step_nnodes[step];
    AtA_profile_cycles[step] = malloc(nnodes * sizeof(uint64_t));
    chol_profile_cycles[step] = malloc(nnodes * sizeof(uint64_t));
    merge_profile_cycles[step] = malloc(nnodes * sizeof(uint64_t));
    init_profile_cycles[step] = malloc(nnodes * sizeof(uint64_t));
    backsolve_profile_cycles[step] = malloc(nnodes * sizeof(uint64_t));
  }
}

void profile_free(int nstep){
  for(int step = 0; step < nstep; step ++){
    int nnodes = step_nnodes[step];
    free(AtA_profile_cycles[step]); 
    free(chol_profile_cycles[step]);
    free(merge_profile_cycles[step]);
    free(init_profile_cycles[step]);
    free(backsolve_profile_cycles[step]);
  }
  free(AtA_profile_cycles);
  free(chol_profile_cycles);
  free(merge_profile_cycles);
  free(init_profile_cycles);
  free(backsolve_profile_cycles);
}

void step_free_profile(int step){
   int nnode = step_nnodes[step];
   //free(node_locks);
   for(int node = 0; node < nnode; node++){
     if(node_time[node] != 0){
       printf("step %d node %d total increment time: %llu\n", step, node, node_time[node]);
#if PRINT_MORE == 1
       printf("profile %d node %d width %d height %d\n", step, node, step_node_width[step][node], step_node_height[step][node]); 
       printf("profile %d node %d is memset: %d\n", step, node, did_memset[node]);
       printf("profile %d node %d num factors: %d\n", step, node, step_node_num_factors[step][node]);
#endif
       printf("profile %d node %d init time: %llu\n", step, node, init_time[node]);
       printf("profile %d node %d AtA time: %llu\n", step, node, AtA_time[node]);
       printf("profile %d node %d chol time: %llu\n", step, node, chol_time[node]);
       printf("profile %d node %d merge time: %llu\n", step, node, merge_time[node]);
       printf("profile %d node %d backsolve time: %llu\n", step, node, backsolve_time[node]);
       //printf("step %d node %d increment thread: %d\n", step, node, node_thread[node]-10);
       //printf("step %d node %d backsolve thread: %d\n", step, node, backsolve_thread[node]-10);
     }
   }
   free(merge_time);
   free(chol_time);
   free(init_time);
   free(node_time);
   free(AtA_time);
   free(backsolve_time);
   free(node_thread);
   free(backsolve_thread);
#if PRINT_MORE == 1
   free(did_memset);
   did_memset = NULL;
#endif

   free(node_num_children);
   free(node_done_children);
   free(node_ready_queue);
   free(node_arr);
   my_free_all(NULL);
   for(int node = 0; node < nnode - 1; node++){
     free(backsolve_children[node]);
   }
   free(backsolve_children);
   backsolve_children = NULL;

   node_arr = NULL;
   node_ready_queue = NULL;
   node_done_children = NULL;
   node_num_children = NULL;
   merge_time = NULL;
   chol_time = NULL;
   init_time = NULL;
   node_time = NULL;
   AtA_time = NULL;
   backsolve_time = NULL;
   node_thread = NULL;
   backsolve_thread = NULL;
   backsolve_children = NULL;
   //node_locks = NULL;
}

void step_free(int step){
   int nnode = step_nnodes[step];
   //printf("step %d relin cost: %llu\n", step, (uint64_t)(step_scaled_relin_cost[step]/NUM_CORE));
   //free(node_locks);
   /*
   for(int node = 0; node < nnode; node++){
     if(node_time[node] != 0){
       printf("step %d node %d total increment time: %llu\n", step, node, node_time[node]);
       printf("step %d node %d init time: %llu\n", step, node, init_time[node]);
       printf("step %d node %d width %d height %d\n", step, node, step_node_width[step][node], step_node_height[step][node]); 
       printf("step %d node %d AtA time: %llu\n", step, node, AtA_time[node]);
       printf("step %d node %d chol time: %llu\n", step, node, chol_time[node]);
       printf("step %d node %d chol marked: %d\n", step, node, step_node_marked[step][node]);
       printf("step %d node %d merge time: %llu\n", step, node, merge_time[node]);
       printf("step %d node %d backsolve time: %llu\n", step, node, backsolve_time[node]);
       printf("step %d node %d corunning threads: %d\n", step, node, node_corunning[node]-1);
       printf("step %d node %d cholesky arrays: %d\n", step, node, chol_num_array[node]);
       printf("step %d node %d increment thread: %d\n", step, node, node_thread[node]-10);
       printf("step %d node %d backsolve thread: %d\n", step, node, backsolve_thread[node]-10);
     }
   }
   */
   free(merge_time);
   free(chol_time);
   free(init_time);
   free(node_time);
   free(AtA_time);
   free(backsolve_time);
   free(node_thread);
   free(node_corunning);
   free(chol_num_array);
   free(backsolve_thread);
  
   free(node_num_children);
   free(node_done_children);
   free(node_ready_queue);
   free(node_arr);
   my_free_all(NULL);
   for(int node = 0; node < nnode - 1; node++){
     free(backsolve_children[node]);
   }
   free(backsolve_children);
   backsolve_children = NULL;

   node_arr = NULL;
   node_ready_queue = NULL;
   node_done_children = NULL;
   node_num_children = NULL;
   merge_time = NULL;
   chol_time = NULL;
   init_time = NULL;
   node_time = NULL;
   AtA_time = NULL;
   backsolve_time = NULL;
   node_thread = NULL;
   backsolve_thread = NULL;
   backsolve_children = NULL;
   //node_locks = NULL;
}

void step_backsolve_processing_mono(int step, int cid, int acc_cfgid, int dma_cfgid){
  int nnodes = step_nnodes[step];

  bool* node_marked = step_node_marked[step];
  bool* node_fixed = step_node_fixed[step];

  int* node_parent = step_node_parent[step];
  int* node_height = step_node_height[step];
  int* node_width = step_node_width[step];
  int** node_ridx = step_node_ridx[step];
  float** node_data = step_node_data[step];
  float* x_data = step_x_data[step];

  int wait_turn = 0;

  while(true) {
      bool done_flag = false;
      bool wait_flag = false;
      int node = -1;
      //pthread_mutex_lock(&queue_lock);

      if(backsolve_ready_index < backsolve_ready_size) {
          node = backsolve_ready_queue[backsolve_ready_index];
          backsolve_ready_index++;
	  wait_turn = 0;
      }
      else if(backsolve_ready_size == num_active_nodes) {
          done_flag = true;
      }
      else if(backsolve_ready_size > num_active_nodes) {
          printf("backsolve thread %d: Ready queue size %d greater than active nodes %d!\n", cid, backsolve_ready_size, num_active_nodes);
          exit(1);
      }
      else {
        wait_flag = true;
	wait_turn ++;
	if(wait_turn %10 == 1){
           printf("illegal wait %d, %d, %d\n", backsolve_ready_index, backsolve_ready_size, num_active_nodes);
	}
      }


      //pthread_mutex_unlock(&queue_lock);

      if(done_flag) {
          break;
      }
      else if(wait_flag) {
          continue;
      }
          
      //printf("thread %d backsolve node = %d\n", cid, node);
      //fflush(stdout);
      int width = node_width[node];
      int height = node_height[node];
      int* ridx = node_ridx[node];
      int channel = 0;
      backsolve_thread[node] += (cid + 10);
 
      uint64_t start = read_cycles();     
      partial_backsolve(node_data[node], width, height, height, ridx, x_data, channel, dma_cfgid, acc_cfgid);

      //pthread_mutex_lock(&queue_lock);
      for(int i = 0; i < node_num_children[node]; i++) {
          int child = backsolve_children[node][i];
          backsolve_ready_queue[backsolve_ready_size] = child;
          backsolve_ready_size++;

      }
      //pthread_mutex_unlock(&queue_lock);
      uint64_t end = read_cycles();
      backsolve_time[node] = end - start;
      backsolve_profile_cycles[step][node] = end - start;
  }
}

void step_backsolve_processing(int step, int cid, int acc_cfgid, int dma_cfgid){
  int nnodes = step_nnodes[step];

  bool* node_marked = step_node_marked[step];
  bool* node_fixed = step_node_fixed[step];

  int* node_parent = step_node_parent[step];
  int* node_height = step_node_height[step];
  int* node_width = step_node_width[step];
  int** node_ridx = step_node_ridx[step];
  float** node_data = step_node_data[step];
  float* x_data = step_x_data[step];

  while(true) {
      bool done_flag = false;
      bool wait_flag = false;
      int node = -1;
      pthread_mutex_lock(&queue_lock);

      if(backsolve_ready_index < backsolve_ready_size) {
          node = backsolve_ready_queue[backsolve_ready_index];
          backsolve_ready_index++;
      }
      else if(backsolve_ready_size == num_active_nodes) {
          done_flag = true;
      }
      else if(backsolve_ready_size > num_active_nodes) {
          printf("backsolve thread %d: Ready queue size %d greater than active nodes %d!\n", cid, backsolve_ready_size, num_active_nodes);
          exit(1);
      }
      else {
          wait_flag = true;
      }

      uint64_t start = read_cycles();

      pthread_mutex_unlock(&queue_lock);

      if(done_flag) {
          break;
      }
      else if(wait_flag) {
          continue;
      }
          
      //printf("thread %d solve node = %d\n", cid, node);
      int width = node_width[node];
      int height = node_height[node];
      int* ridx = node_ridx[node];
      int channel = 0;
      backsolve_thread[node] += (cid + 10);
      
      partial_backsolve(node_data[node], width, height, height, ridx, x_data, channel, dma_cfgid, acc_cfgid);

      pthread_mutex_lock(&queue_lock);
      for(int i = 0; i < node_num_children[node]; i++) {
          int child = backsolve_children[node][i];
          backsolve_ready_queue[backsolve_ready_size] = child;
          backsolve_ready_size++;

      }
      pthread_mutex_unlock(&queue_lock);
      uint64_t end = read_cycles();
      backsolve_time[node] = end - start;

  }
}
#if USE_PROFILE == 1
void step_processing_debug(int step, float* AtA_workspace, int avail_mem, int cid){
  bool* node_marked = step_node_marked[step];
  bool* node_fixed = step_node_fixed[step];

  int* node_parent = step_node_parent[step];
  int* node_height = step_node_height[step];
  int* node_width = step_node_width[step];
  float** node_data = step_node_data[step];
  int* node_num_blks = step_node_num_blks[step];
  int** node_A_blk_start = step_node_A_blk_start[step];
  int** node_B_blk_start = step_node_B_blk_start[step];
  int** node_blk_width = step_node_blk_width[step];

  int nnodes = step_nnodes[step];
  int* node_num_factors = step_node_num_factors[step];
  int** node_factor_height = step_node_factor_height[step];
  int** node_factor_width = step_node_factor_width[step];
  float*** node_factor_data = step_node_factor_data[step];
  int** node_factor_num_blks = step_node_factor_num_blks[step];
  int*** node_factor_A_blk_start = step_node_factor_A_blk_start[step];
  int*** node_factor_B_blk_start = step_node_factor_B_blk_start[step];
  int*** node_factor_blk_width = step_node_factor_blk_width[step];
 
  uint64_t chol_start = 0, chol_end = 0, chol = 0;
  uint64_t merge_start = 0, merge_end = 0, merge = 0;
  uint64_t AtA_start = 0, AtA_end = 0, AtA = 0;
  uint64_t init_start = 0, init_end = 0, init = 0;
  // Setup
  bool granted = false;
  int channel = 0;
  int index = 0;
  uint64_t expected_cycles = 0; 
  pthread_barrier_wait(&barrier_slam);
  int accel = 1;
  int co_running = 1;
  int co_thread = 1;
  if(cid == 1) co_thread = 0;
  else if(cid == 2) co_thread = 3;
  else if(cid == 3) co_thread = 2;

  // start processing
  while(true) {
    bool done_flag = false;
    bool wait_flag = false;
    int node = -1;
    pthread_mutex_lock(&queue_lock);

    if(node_ready_index < node_ready_size) {
        node = node_ready_queue[node_ready_index];
        node_ready_index++;
        if(!active_thread[co_thread] && accel == 1 && NUM_CORE > 1){
          accel++; // currently, allow up to 2 sets
        }
        co_running = 0;
        for(int i = 0; i < NUM_CORE; i++){
           if(active_thread[i]) co_running ++;
        }
    }
    else if(node_ready_size == num_active_nodes) {
        done_flag = true;
    }
    else if(node_ready_size > num_active_nodes) {
        printf("thread %d: Ready queue size greater than active nodes!\n", cid);
        exit(1);
    }
    else {
        active_thread[cid] = false;
        wait_flag = true;
    }

    pthread_mutex_unlock(&queue_lock);

    if(done_flag) {
        break;
    }
    else if(wait_flag) {
	// exit as there is no parallelizable node
        break;
        //continue;
    }
        
    //printf("thread %d node = %d\n", cid, node);

    //pthread_mutex_lock(&node_locks[node]);
    bool marked = node_marked[node];
    bool fixed = node_fixed[node];

    //if(!marked && !fixed) { continue; }
    if(!marked && !fixed) { 
       //pthread_mutex_unlock(&node_locks[node]);
       printf("this should not happen - thread %d node %d\n", cid, node);
       exit(1);
       //continue; 
    }

    int parent = node_parent[node];
    int H_h = node_height[node];
    int H_w = node_width[node];
    float* H_data = node_data[node];

    int num_factors = node_num_factors[node];
    int* factor_height = node_factor_height[node];
    int* factor_width = node_factor_width[node];
    float** factor_data = node_factor_data[node];
    int* factor_num_blks = node_factor_num_blks[node];
    int** factor_A_blk_start = node_factor_A_blk_start[node];
    int** factor_B_blk_start = node_factor_B_blk_start[node];
    int** factor_blk_width = node_factor_blk_width[node];
    
    init_start = read_cycles();
    // assign workspace
    if(node_arr[node] == 0) {
       node_arr[node] = (float*) my_malloc(H_h * H_h * sizeof(float));
       uint64_t init_togo = init_profiled_cycles[step][node];
       if (co_running >= 3 && accel == 1) 
	   init_profiled_cycles[step][node] *= 1.2;
       init_end = read_cycles();
       uint64_t diff_cycles = init_end - init_start;
       // can divide into two dma call for 2 accels
       while(diff_cycles < init_profiled_cycles[step][node]){
           init_end = read_cycles();
	   diff_cycles = init_end - init_start;
       }
    }
    init_end = read_cycles();
    init_time[node] = init_end - init_start;
    node_thread[node] += (cid + 10);
    float* H_workspace = node_arr[node];
    
    // Marked nodes
    // 1. AtA
    // 2. Cholesky (partial_factorization)
    // 3. Add LC to parent
    // 4. Copy [A B] back from workspace
    // Fixed nodes
    // 1. AtA
    // 2. LC = -LB LB^T
    // 3. Add LC to parent
    // 4. Don't copy [A B] back from workspace

    // 1. AtA

    // AtA
    AtA_start = read_cycles();
    AtA_end = AtA_start + 10;
    uint64_t AtA_diff = AtA_end - AtA_start;
    uint64_t AtA_togo = (accel == 1 || NUM_CORE == 1) ? AtA_profiled_cycles[step][node] : ((num_factors >= 20 && NUM_CORE > 1) ? AtA_profiled_cycles2[step][node] * 0.85 : AtA_profiled_cycles2[step][node]);
    if(co_running > 2) {
	if(AtA_togo < 10000){
	  AtA_togo += (AtA_togo * 0.05 * (co_running - 2))/2;
	} 
	else if (AtA_togo < 20000) {
	  AtA_togo += (AtA_togo * 0.1 * (co_running - 2))/2;
	}
	else {
	  AtA_togo += (AtA_togo * 0.15 * (co_running - 2))/2;
	}
    }
    else if(co_running == 2){
	AtA_togo += AtA_togo * 0.03;
    }	
    while(AtA_diff < AtA_togo){
        AtA_end = read_cycles();
        AtA_diff = AtA_end - AtA_start;
    }
    AtA_time[node] = AtA_end - AtA_start;

    // do memset background 
    //printf("thread %d width %d height %d\n", cid, H_w, H_h);         
    //int parent = node_parent[node];
    chol_start = read_cycles();
    chol_end = chol_start + 10;
    co_running = 0;
    for(int i = 0; i < NUM_CORE; i++){
	if(active_thread[i]) co_running ++;
//	if(!active_thread[i] && accel == 1) accel ++;
    }
    if(!active_thread[co_thread] && accel == 1 && NUM_CORE > 1){
	accel++; // currently, allow up to 2 sets
    }
    node_corunning[node] = co_running;
    chol_num_array[node] = accel;
    uint64_t chol_diff = chol_end - chol_start;
    uint64_t chol_togo = accel == 1 ? chol_profiled_cycles[step][node] : chol_profiled_cycles2[step][node];
    if(co_running > 2) {
	if(chol_togo < 20000){
	  chol_togo += (chol_togo * 0.05 * (co_running - 2))/2;
	} 
	else if(chol_togo < 60000){
	  chol_togo += (chol_togo * 0.1 * (co_running - 2))/2;
	} 
	else if (chol_togo < 120000){
	  chol_togo += (chol_togo * 0.15 * (co_running - 2))/2;
	}
	else if (chol_togo < 200000){
	  chol_togo += (chol_togo * 0.2 * (co_running - 2))/2;
	}
	else if (chol_togo > 1000000){
	  chol_togo += (chol_togo * 0.1 * (co_running - 2))/2;
	}
	else {
	  chol_togo += (chol_togo * 0.18 * (co_running - 2))/2;
	}
    }	
    else if(co_running == 2){
	if(chol_togo < 100000) chol_togo += chol_togo * 0.02;
	else chol_togo += chol_togo * 0.04;
    }
    while(chol_diff < chol_togo){
        chol_end = read_cycles();
        chol_diff = chol_end - chol_start;
    }
    chol_time[node] = chol_end - chol_start;
    //printf("thread %d done cholesky\n", cid);

    merge_start = read_cycles();
    // 3. Add LC to parent
    if(parent != -1 && parent != nnodes - 1) {
      // lock parent
      pthread_mutex_lock(&node_locks[parent]);
      merge_start = read_cycles();
      merge_end = merge_start + 10;
      uint64_t merge_diff = merge_end - merge_start;
      uint64_t merge_togo = merge_profiled_cycles[step][node];
      if(accel > 1 && merge_togo > 20000) {merge_togo *= 0.8;}
      if(co_running > 2) {
     	merge_togo += (int)(merge_togo * 0.1 * (co_running - 2))/2;
      }	

      while(merge_diff < merge_profiled_cycles[step][node]){
          merge_end = read_cycles();
          merge_diff = merge_end - merge_start;
      }
      node_done_children[parent]++;
      if(node_done_children[parent] == node_num_children[parent]) {
          pthread_mutex_lock(&queue_lock);
          node_ready_queue[node_ready_size] = parent;
          node_ready_size++;
          pthread_mutex_unlock(&queue_lock);
      } 
      merge_end = read_cycles();
      merge_time[node] = merge_end - merge_start;
 
      pthread_mutex_unlock(&node_locks[parent]);
    }
    //free(H_workspace);
    node_arr[node] = NULL;
    //pthread_mutex_unlock(&node_locks[node]);

    merge_end = read_cycles();
    merge_time[node] = merge_end - merge_start;
    node_time[node] = merge_time[node] + chol_time[node] + init_time[node] + AtA_time[node];
/*
    printf("node %d total cycles: %llu\n", node, AtA+chol+merge+init);
    printf("init cycles: %llu\n", init);
    printf("AtA cycles: %llu\n", AtA);
    printf("chol cycles: %llu\n", chol);
    printf("merge cycles: %llu\n", merge);
*/
  }
}
void step_backsolve_processing_debug(int step, int cid){
  int nnodes = step_nnodes[step];
  active_thread[cid] = true;

  bool* node_marked = step_node_marked[step];
  bool* node_fixed = step_node_fixed[step];

  int* node_parent = step_node_parent[step];
  int* node_height = step_node_height[step];
  int* node_width = step_node_width[step];
  int** node_ridx = step_node_ridx[step];
  float** node_data = step_node_data[step];
  float* x_data = step_x_data[step];
  int co_running = 1;

  while(true) {
      bool done_flag = false;
      bool wait_flag = false;
      int node = -1;
      pthread_mutex_lock(&queue_lock);

      if(backsolve_ready_index < backsolve_ready_size) {
        node = backsolve_ready_queue[backsolve_ready_index];
        backsolve_ready_index++;
	co_running = 0;
	for(int i = 0; i < NUM_CORE; i++){
	   if(active_thread[i]) co_running ++;
	}
      }
      else if(backsolve_ready_size == num_active_nodes) {
          done_flag = true;
      }
      else if(backsolve_ready_size > num_active_nodes) {
          printf("backsolve thread %d: Ready queue size %d greater than active nodes %d!\n", cid, backsolve_ready_size, num_active_nodes);
          exit(1);
      }
      else {
        active_thread[cid] = false;
        wait_flag = true;
      }

      pthread_mutex_unlock(&queue_lock);

      if(done_flag) {
          break;
      }
      else if(wait_flag) {
          continue;
      }
 
      //printf("thread %d solve node = %d\n", cid, node);
      int width = node_width[node];
      int height = node_height[node];
      int* ridx = node_ridx[node];
      int channel = 0;
      backsolve_thread[node] += (cid + 10);
 
      uint64_t start = read_cycles(); 
      uint64_t end = start + 10;
      uint64_t back_diff = end - start;
      uint64_t backsolve_togo = backsolve_profiled_cycles[step][node];
      if(co_running > 2) {
	if (backsolve_togo < 10000) {
	  backsolve_togo += (backsolve_togo * 0.04 * (co_running - 2))/2;
	}
	else {
	  backsolve_togo += (backsolve_togo * 0.08 * (co_running - 2))/2;
	}
      }
      while(back_diff < backsolve_togo){
          end = read_cycles();
          back_diff = end - start;
      }

      pthread_mutex_lock(&queue_lock);
      for(int i = 0; i < node_num_children[node]; i++) {
          int child = backsolve_children[node][i];
          backsolve_ready_queue[backsolve_ready_size] = child;
          backsolve_ready_size++;

      }
      pthread_mutex_unlock(&queue_lock);
      backsolve_time[node] = end - start;

  }
}
#endif
void step_processing(int step, float* AtA_workspace, int avail_mem, int cid, int acc_cfgid, int dma_cfgid, int add_cfgid){
  bool* node_marked = step_node_marked[step];
  bool* node_fixed = step_node_fixed[step];

  int* node_parent = step_node_parent[step];
  int* node_height = step_node_height[step];
  int* node_width = step_node_width[step];
  float** node_data = step_node_data[step];
  int* node_num_blks = step_node_num_blks[step];
  int** node_A_blk_start = step_node_A_blk_start[step];
  int** node_B_blk_start = step_node_B_blk_start[step];
  int** node_blk_width = step_node_blk_width[step];

  int nnodes = step_nnodes[step];
  int* node_num_factors = step_node_num_factors[step];
  int** node_factor_height = step_node_factor_height[step];
  int** node_factor_width = step_node_factor_width[step];
  float*** node_factor_data = step_node_factor_data[step];
  int** node_factor_num_blks = step_node_factor_num_blks[step];
  int*** node_factor_A_blk_start = step_node_factor_A_blk_start[step];
  int*** node_factor_B_blk_start = step_node_factor_B_blk_start[step];
  int*** node_factor_blk_width = step_node_factor_blk_width[step];
 
  uint64_t chol_start = 0, chol_end = 0, chol = 0;
  uint64_t merge_start = 0, merge_end = 0, merge = 0;
  uint64_t AtA_start = 0, AtA_end = 0, AtA = 0;
  uint64_t init_start = 0, init_end = 0, init = 0;
  // Setup
  bool granted = false;
  int channel = 0;
  int index = 0;
  uint64_t expected_cycles = 0; 
  pthread_barrier_wait(&barrier_slam);
  int accel = 1;
  int co_running = 1;
  /*
  int co_thread = 0;
  if(cid == 1) co_thread = 0;
  else if(cid == 2) co_thread = 3;
  else if(cid == 3) co_thread = 2;
  */
  // start processing
  while(true) {
    bool done_flag = false;
    bool wait_flag = false;
    int node = -1;
    //printf("thread %d \n", cid);
    //fflush(stdout);
    pthread_mutex_lock(&queue_lock);

    if(node_ready_index < node_ready_size) {
      node = node_ready_queue[node_ready_index];
      node_ready_index++;
      
      co_running = 0;
      for(int i = 0; i < NUM_CORE; i++)
        if(active_thread[i]) co_running++;
      if(co_running == 1){
        if(accel < NUM_CORE){
          for(int i = 0; i < NUM_CORE; i++){
            if(i != cid){
              bool acquire = rr_acquire_single(dma_cfgid+accel, DMA_START+i);
              if(acquire){
                rr_acquire_single(acc_cfgid+accel, ACC_START+i);
                accel ++;
                if(accel == NUM_CORE)
                  break;
              }
            }
          }
        }
      }
      else if(co_running < NUM_CORE){
        if(accel == 1){
          for(int i = 0; i < NUM_CORE; i++){
            if(i!=cid){
              bool acquire = rr_acquire_single(dma_cfgid+accel, DMA_START+i);
              if(acquire){
                rr_acquire_single(acc_cfgid+accel, ACC_START+i);
                accel ++;
                break;
              }
            }
          }
        }
      }
/*
      if(!active_thread[co_thread] && accel == 1 && NUM_CORE > 1){
        accel++;
        bool acquire = false;
        while(!acquire)
          rr_acquire_single(dma_cfgid+1, DMA_START+co_thread);
        acquire = false;
        while(!acquire)
          rr_acquire_single(acc_cfgid+1, ACC_START+co_thread);
      }
      co_running = 0;
      for(int i = 0; i < NUM_CORE; i++)
        if(active_thread[i]) co_running++;
      // if it is the only thread active
      if(co_running == 1 && NUM_ACCEL > 2 && accel == 2){
        for(int i = 0; i < NUM_CORE; i++){
          if(i != cid && i != co_thread){
            bool acquire = false;
            while(!acquire){
              rr_acquire_single(dma_cfgid+accel, DMA_START + i);
            }
            acquire = false;
            while(!acquire){
              rr_acquire_single(acc_cfgid+accel, ACC_START + i);
            }
          }
        }
      }
      */
    }
    
    else if(node_ready_size == num_active_nodes) {
        done_flag = true;
    }
    else if(node_ready_size > num_active_nodes) {
        printf("thread %d: Ready queue size %d reater than active nodes %d!\n", cid, backsolve_ready_size, num_active_nodes);
        exit(1);
    }
    else {
        // release in advance
        for(int i = 0; i < accel; i++){
          rr_release(acc_cfgid + i);
          rr_release(dma_cfgid + i);
        }
        active_thread[cid] = false;
        wait_flag = true;
    }

    pthread_mutex_unlock(&queue_lock);

    if(done_flag) {
        break;
    }
    else if(wait_flag) {
#if PRINT_DEBUG
        printf("thread %d exit\n", cid);
#endif
        break;
        //continue;
    }
    int H_h = node_height[node];
    int H_w = node_width[node];
    
#if PRINT_DEBUG
    printf("thread %d node = %d (H %d, W %d), num accel: %d\n", cid, node, H_h, H_w, accel);
    fflush(stdout);
#endif
    //pthread_mutex_lock(&node_locks[node]);
    bool marked = node_marked[node];
    bool fixed = node_fixed[node];

    //if(!marked && !fixed) { continue; }
    if(!marked && !fixed) { 
       //pthread_mutex_unlock(&node_locks[node]);
       printf("this should not happen - thread %d node %d\n", cid, node);
       exit(1);
       //continue; 
    }

    int parent = node_parent[node];
    float* H_data = node_data[node];

    int num_factors = node_num_factors[node];
    int* factor_height = node_factor_height[node];
    int* factor_width = node_factor_width[node];
    float** factor_data = node_factor_data[node];
    int* factor_num_blks = node_factor_num_blks[node];
    int** factor_A_blk_start = node_factor_A_blk_start[node];
    int** factor_B_blk_start = node_factor_B_blk_start[node];
    int** factor_blk_width = node_factor_blk_width[node];
    
    init_start = read_cycles();
    // assign workspace
    if(node_arr[node] == 0) {
       node_arr[node] = (float*) my_malloc(H_h * H_h * sizeof(float));
       int memset_channel = 2;
       int col_block = H_h > 128 ? ceil_divide_int(H_h, 2) : H_h; 
       for(int col = 0; col < H_h; col += col_block){
         if(col != 0 && accel > 1)
            rr_set_opc(XCUSTOM_DMA, dma_cfgid+1);
         if(memset_channel >= NUM_CHANNEL){
           printf("node too large\n");
           exit(1);
         }
         int columns = H_h - col > col_block ? col_block : H_h - col; 
         float* workspace_start = (float*) node_arr[node] + col; 
         granted = false;
         while(!granted)
           dma_source_config(memset_channel, granted, false, NULL, H_h * sizeof(float));
         dma_nord_dest_config(memset_channel, false, workspace_start, H_h * sizeof(float));
         granted = false;
         while(!granted)
           dma_memcpy_tile(memset_channel, granted, 0, 0, 0, H_h, columns * sizeof(float));
         memset_channel ++;
       }
       rr_fence(dma_cfgid);
       if(accel > 1 && col_block < H_h){
         rr_fence(dma_cfgid+1);
         rr_set_opc(XCUSTOM_DMA, dma_cfgid);
       }
    }
    init_end = read_cycles();
    init_time[node] = init_end - init_start;
    node_thread[node] += (cid + 10);
    float* H_workspace = node_arr[node];
     
#if PRINT_DEBUG
    printf("thread %d num factors %d\n", cid, num_factors);    
    fflush(stdout);     
#endif
    // Marked nodes
    // 1. AtA
    // 2. Cholesky (partial_factorization)
    // 3. Add LC to parent
    // 4. Copy [A B] back from workspace
    // Fixed nodes
    // 1. AtA
    // 2. LC = -LB LB^T
    // 3. Add LC to parent
    // 4. Don't copy [A B] back from workspace

    // 1. AtA

    // AtA
    AtA_start = read_cycles();
    int tile_nfactor = tiling_AtA_nfactor(num_factors, max_factor_height, max_factor_width, avail_mem);
    //printf("num factors: %d, tile nfactor: %d\n", num_factors, tile_nfactor);

    // AtA workspace: AtA
    // workspace: A
    float* workspace = (float*) AtA_workspace + max_factor_height * max_factor_height * tile_nfactor;//node_nfactors[node];
    for(int f = 0; f < num_factors; f += tile_nfactor){
      int this_nfactors = f + tile_nfactor < num_factors ? tile_nfactor : num_factors - f;
      int dma_i = 0; // todo
      //workspace = (float*) base_addr;
      // just allow up to 2 for Hessian for now
      if(accel == 1)
        tile_AtA_supernode_pointer(f, this_nfactors, max_factor_height, node_factor_height[node], node_factor_width[node], node_factor_data[node], H_h, H_w, NULL, H_workspace, (float*) AtA_workspace, (float*) workspace, factor_A_blk_start, factor_B_blk_start, factor_blk_width, factor_num_blks, dma_i, NUM_CHANNEL, acc_cfgid, dma_cfgid, add_cfgid); 
      else 
        dual_tile_AtA_supernode_pointer(f, this_nfactors, max_factor_height, node_factor_height[node], node_factor_width[node], node_factor_data[node], H_h, H_w, NULL, H_workspace, (float*) AtA_workspace, (float*) workspace, factor_A_blk_start, factor_B_blk_start, factor_blk_width, factor_num_blks, dma_i, NUM_CHANNEL, acc_cfgid, acc_cfgid+1, dma_cfgid, add_cfgid);
    }
    AtA_end = read_cycles();
    AtA_time[node] = AtA_end - AtA_start;

#if PRINT_DEBUG
    // do memset background 
    printf("thread %d width %d height %d\n", cid, H_w, H_h);    
    fflush(stdout);    
#endif
    //int parent = node_parent[node]; 
    chol_start = read_cycles();
    if(parent != -1 && parent != nnodes - 1){
       //pthread_mutex_lock(&node_locks[parent]);
       if(node_arr[parent] ==0){
         int next_H_h = node_height[parent];
         node_arr[parent] = (float*) my_malloc(next_H_h * next_H_h * sizeof(float));
         if(node_arr[parent] == NULL){
             printf("parent not allocated\n");
             exit(0);
         }
         channel = 2;
         int col_block = next_H_h > 128 ? ceil_divide_int(next_H_h, 2) : next_H_h; 
         for(int col = 0; col < next_H_h; col += col_block){
           if(col != 0 && accel > 1)
             rr_set_opc(XCUSTOM_DMA, dma_cfgid+1);
           if(channel >= NUM_CHANNEL){
             printf("node too large\n");
             exit(1);
           }
           int columns = next_H_h - col > col_block ? col_block : next_H_h - col; 
           float* workspace_start = node_arr[parent] + col; 
           granted = false;
           while(!granted)
             dma_source_config(channel, granted, false, NULL, next_H_h * sizeof(float));
           dma_nord_dest_config(channel, false, workspace_start, next_H_h * sizeof(float));
           granted = false;
           while(!granted)
             dma_memcpy_tile(channel, granted, 0, 0, 0, next_H_h, columns * sizeof(float));
           channel ++;
         } 
         if(accel > 1 && col_block < next_H_h){
           rr_set_opc(XCUSTOM_DMA, dma_cfgid);
         }
       }
       //pthread_mutex_unlock(&node_locks[parent]);
    }
    if(marked) { 
        // 2. Cholesky
        //partial_factorization4(H_workspace, H_w, H_h);
        channel = 0;
        int chol_block_size = H_w < CHOL_BLOCK_SIZE ? H_w : CHOL_BLOCK_SIZE;
        multi_workspace_partial_factorization(H_workspace, H_data, H_w, H_h, chol_block_size, channel, acc_cfgid, dma_cfgid, accel);
      //partial_factorization4(ABC, H_w, H_h);

    }
    else if(fixed) {
        //printf("no cholesky, width %d height %d\n", H_w, H_h);
        // 2. LC = -LB LB^T
        int subdiag_h = H_h - H_w;
        float* LB = H_data + H_w;
        float* LC = H_workspace + H_w * (H_h + 1);

        tiled_matmul_auto(subdiag_h, subdiag_h, H_w,
                LB, LB, LC, LC,
                H_h, H_h, H_h, H_h,
                -1, 1, 1,
                NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
                true, false,
                false, false, 0, WS);
    }
    rr_fence(dma_cfgid);
    rr_fence(acc_cfgid);
    chol_end = read_cycles();
    chol_time[node] = chol_end - chol_start;
    chol_num_array[node] = accel;
    node_corunning[node] = co_running;
    
#if PRINT_DEBUG
    printf("thread %d done cholesky marked %d\n", cid, marked);
    fflush(stdout);
#endif
    merge_start = read_cycles();
    // 3. Add LC to parent
    if(parent != -1 && parent != nnodes - 1) {

      // lock parent
      pthread_mutex_lock(&node_locks[parent]);
      int subdiag_h = H_h - H_w;
      float* C = H_workspace + H_w * (H_h + 1);
      int next_H_h = node_height[parent];
      int next_H_w = node_width[parent];


      float* next_H_workspace = node_arr[parent];

      int next_num_blks = node_num_blks[node];
      int* A_blk_start = node_A_blk_start[node];
      int* B_blk_start = node_B_blk_start[node];
      int* next_blk_width = node_blk_width[node];
     
      packed_dense_block_add(C, next_H_workspace, 
              H_h, next_H_h, next_blk_width,
              H_h, next_H_h,
              A_blk_start, B_blk_start, //C_blk, next_blk,
              next_num_blks, true);

      node_done_children[parent]++;
      if(node_done_children[parent] == node_num_children[parent]) {
          pthread_mutex_lock(&queue_lock);
          node_ready_queue[node_ready_size] = parent;
          node_ready_size++;
          pthread_mutex_unlock(&queue_lock);
      } 

      //rr_fence(add_cfgid);
      rr_fence(acc_cfgid);
      pthread_mutex_unlock(&node_locks[parent]);
    }
    //free(H_workspace);
    node_arr[node] = NULL;
    //pthread_mutex_unlock(&node_locks[node]);

    merge_end = read_cycles();
    merge_time[node] = merge_end - merge_start;
    node_time[node] = merge_time[node] + chol_time[node] + init_time[node] + AtA_time[node];
#if PRINT_DEBUG
    printf("thread %d done node %d\n", cid, node);
    fflush(stdout);
#endif
/*
    printf("node %d total cycles: %llu\n", node, AtA+chol+merge+init);
    printf("init cycles: %llu\n", init);
    printf("AtA cycles: %llu\n", AtA);
    printf("chol cycles: %llu\n", chol);
    printf("merge cycles: %llu\n", merge);
*/
  }
}
// for profiling
void step_processing_mono(int step, float* AtA_workspace, int avail_mem, int cid, int acc_cfgid, int dma_cfgid, int add_cfgid){
  bool* node_marked = step_node_marked[step];
  bool* node_fixed = step_node_fixed[step];

  int* node_parent = step_node_parent[step];
  int* node_height = step_node_height[step];
  int* node_width = step_node_width[step];
  float** node_data = step_node_data[step];
  int* node_num_blks = step_node_num_blks[step];
  int** node_A_blk_start = step_node_A_blk_start[step];
  int** node_B_blk_start = step_node_B_blk_start[step];
  int** node_blk_width = step_node_blk_width[step];

  int nnodes = step_nnodes[step];
  int* node_num_factors = step_node_num_factors[step];
  int** node_factor_height = step_node_factor_height[step];
  int** node_factor_width = step_node_factor_width[step];
  float*** node_factor_data = step_node_factor_data[step];
  int** node_factor_num_blks = step_node_factor_num_blks[step];
  int*** node_factor_A_blk_start = step_node_factor_A_blk_start[step];
  int*** node_factor_B_blk_start = step_node_factor_B_blk_start[step];
  int*** node_factor_blk_width = step_node_factor_blk_width[step];
 
  uint64_t chol_start = 0, chol_end = 0, chol = 0;
  uint64_t merge_start = 0, merge_end = 0, merge = 0;
  uint64_t AtA_start = 0, AtA_end = 0, AtA = 0;
  uint64_t init_start = 0, init_end = 0, init = 0;
  // Setup
  bool granted = false;
  int channel = 0;
  int index = 0;
  uint64_t expected_cycles = 0; 

  int wait_turn = 0;
  // start processing
  while(true) {
    bool done_flag = false;
    bool wait_flag = false;
    int node = -1;
    //pthread_mutex_lock(&queue_lock);

    if(node_ready_index < node_ready_size) {
        node = node_ready_queue[node_ready_index];
        node_ready_index++;
	wait_turn = 0;
    }
    else if(node_ready_size == num_active_nodes) {
        done_flag = true;
    }
    else if(node_ready_size > num_active_nodes) {
        printf("thread %d: Ready queue size %d reater than active nodes %d!\n", cid, backsolve_ready_size, num_active_nodes);
        exit(1);
    }
    else {
        wait_flag = true;
	wait_turn ++;
	if(wait_turn %10 == 1){
           printf("illegal wait %d, %d, %d\n", node_ready_index, node_ready_size, num_active_nodes);
	}
    }

    //pthread_mutex_unlock(&queue_lock);

    if(done_flag) {
        break;
    }
    else if(wait_flag) {
        continue;
    }
        
   // printf("thread %d node = %d\n", cid, node);
   // fflush(stdout);

    //pthread_mutex_lock(&node_locks[node]);
    bool marked = node_marked[node];
    bool fixed = node_fixed[node];

    //if(!marked && !fixed) { continue; }
    if(!marked && !fixed) { 
       //pthread_mutex_unlock(&node_locks[node]);
       printf("this should not happen - thread %d node %d\n", cid, node);
       exit(1);
       //continue; 
    }

    int parent = node_parent[node];
    int H_h = node_height[node];
    int H_w = node_width[node];
    float* H_data = node_data[node];

    int num_factors = node_num_factors[node];
    int* factor_height = node_factor_height[node];
    int* factor_width = node_factor_width[node];
    float** factor_data = node_factor_data[node];
    int* factor_num_blks = node_factor_num_blks[node];
    int** factor_A_blk_start = node_factor_A_blk_start[node];
    int** factor_B_blk_start = node_factor_B_blk_start[node];
    int** factor_blk_width = node_factor_blk_width[node];
    
    init_start = read_cycles();
    // assign workspace
    if(node_arr[node] == 0) {
       node_arr[node] = (float*) my_malloc(H_h * H_h * sizeof(float));
       /*
       int memset_channel = 2;
       granted = false;
       while(!granted)
         dma_source_config(memset_channel, granted, false, NULL, H_h * sizeof(float));
       dma_nord_dest_config(memset_channel, false, (float*) node_arr[node], H_h * sizeof(float));
      
       granted = false;
       while(!granted)
         dma_memcpy_tile(memset_channel, granted, 0, 0, 0, H_h, H_h * sizeof(elem_t));
      //my_memset(node_arr[node], 0, H_h * H_h * sizeof(float));
       */
       int memset_channel = 2;
       int col_block = H_h > 128 ? ceil_divide_int(H_h, 2) : H_h; 
       for(int col = 0; col < H_h; col += col_block){
         if(memset_channel >= NUM_CHANNEL){
           printf("node too large\n");
           exit(1);
         }
         int columns = H_h - col > col_block ? col_block : H_h - col; 
         float* workspace_start = (float*) node_arr[node] + col; 
         granted = false;
         while(!granted)
           dma_source_config(memset_channel, granted, false, NULL, H_h * sizeof(float));
         dma_nord_dest_config(memset_channel, false, workspace_start, H_h * sizeof(float));
         granted = false;
         while(!granted)
           dma_memcpy_tile(memset_channel, granted, 0, 0, 0, H_h, columns * sizeof(float));
         memset_channel ++;
       }
       rr_fence(dma_cfgid);
    }
    init_end = read_cycles();
    init_time[node] = init_end - init_start;
    init_profile_cycles[step][node] = init_end - init_start;
    node_thread[node] += (cid + 10);
    float* H_workspace = node_arr[node];
    
    // Marked nodes
    // 1. AtA
    // 2. Cholesky (partial_factorization)
    // 3. Add LC to parent
    // 4. Copy [A B] back from workspace
    // Fixed nodes
    // 1. AtA
    // 2. LC = -LB LB^T
    // 3. Add LC to parent
    // 4. Don't copy [A B] back from workspace

    // 1. AtA

    // AtA
    AtA_start = read_cycles();
    int tile_nfactor = tiling_AtA_nfactor(num_factors, max_factor_height, max_factor_width, avail_mem);
    //printf("num factors: %d, tile nfactor: %d\n", num_factors, tile_nfactor);
    //fflush(stdout);

    // AtA workspace: AtA
    // workspace: A
    float* workspace = (float*) AtA_workspace + max_factor_height * max_factor_height * tile_nfactor;//node_nfactors[node];
    for(int f = 0; f < num_factors; f += tile_nfactor){
      int this_nfactors = f + tile_nfactor < num_factors ? tile_nfactor : num_factors - f;
      int dma_i = 0; // todo
      //workspace = (float*) base_addr;
      tile_AtA_supernode_pointer(f, this_nfactors, max_factor_height, node_factor_height[node], node_factor_width[node], node_factor_data[node], H_h, H_w, NULL, H_workspace, (float*) AtA_workspace, (float*) workspace, factor_A_blk_start, factor_B_blk_start, factor_blk_width, factor_num_blks, dma_i, NUM_CHANNEL, acc_cfgid, dma_cfgid, add_cfgid);   
    }
    AtA_end = read_cycles();
    AtA_time[node] = AtA_end - AtA_start;
    AtA_profile_cycles[step][node] = AtA_end - AtA_start;

    // do memset background 
    //printf("thread %d width %d height %d\n", cid, H_w, H_h);    
    //fflush(stdout);     
    //int parent = node_parent[node];
    chol_start = read_cycles();
    if(parent != -1 && parent != nnodes - 1){
       //pthread_mutex_lock(&node_locks[parent]);
       if(node_arr[parent] ==0){
         int next_H_h = node_height[parent];
         node_arr[parent] = (float*) my_malloc(next_H_h * next_H_h * sizeof(float));
         if(node_arr[parent] == NULL){
             printf("parent not allocated\n");
             exit(0);
         }
/*
         channel = 2;
         granted = false;
	 printf("before grant \n"); 
         fflush(stdout);     
         while(!granted)
           dma_source_config(channel, granted, false, NULL, next_H_h * sizeof(float));
         dma_nord_dest_config(channel, false, node_arr[parent], next_H_h * sizeof(float));
	 printf("after grant \n"); 
         fflush(stdout);     
         
         granted = false;
         while(!granted)
           dma_memcpy_tile(channel, granted, 0, 0, 0, next_H_h, next_H_h * sizeof(float));
         //my_memset(H_workspace_arr[parent], 0, next_H_h * next_H_h * sizeof(float));
	 rr_fence(dma_cfgid);
	 printf("memset done\n");
         fflush(stdout);  
*/  
          channel = 2;
          int col_block = next_H_h > 128 ? ceil_divide_int(next_H_h, 2) : next_H_h; 
          for(int col = 0; col < next_H_h; col += col_block){
            if(channel >= NUM_CHANNEL){
              printf("node too large\n");
              exit(1);
            }
            int columns = next_H_h - col > col_block ? col_block : next_H_h - col; 
            float* workspace_start = node_arr[parent] + col; 
            granted = false;
            while(!granted)
              dma_source_config(channel, granted, false, NULL, next_H_h * sizeof(float));
            dma_nord_dest_config(channel, false, workspace_start, next_H_h * sizeof(float));
            granted = false;
            while(!granted)
              dma_memcpy_tile(channel, granted, 0, 0, 0, next_H_h, columns * sizeof(float));
            channel ++;
          }
 
       }
       //pthread_mutex_unlock(&node_locks[parent]);
    }
    if(marked) { 
        // 2. Cholesky
        //partial_factorization4(H_workspace, H_w, H_h);
        channel = 0;
        int chol_block_size = H_w < CHOL_BLOCK_SIZE ? H_w : CHOL_BLOCK_SIZE;
        full_workspace_partial_factorization(H_workspace, H_data, H_w, H_h, chol_block_size, channel, acc_cfgid, dma_cfgid);
      //partial_factorization4(ABC, H_w, H_h);

    }
    else if(fixed) {
        //printf("no cholesky, width %d height %d\n", H_w, H_h);
        // 2. LC = -LB LB^T
        int subdiag_h = H_h - H_w;
        float* LB = H_data + H_w;
        float* LC = H_workspace + H_w * (H_h + 1);

        tiled_matmul_auto(subdiag_h, subdiag_h, H_w,
                LB, LB, LC, LC,
                H_h, H_h, H_h, H_h,
                -1, 1, 1,
                NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
                true, false,
                false, false, 0, WS);
    }

    rr_fence(dma_cfgid);
    rr_fence(acc_cfgid);
    chol_end = read_cycles();
    chol_time[node] = chol_end - chol_start;
    chol_profile_cycles[step][node] = chol_end - chol_start;
    //printf("thread %d done cholesky\n", cid);
    //fflush(stdout);

    merge_start = read_cycles();
    // 3. Add LC to parent
    if(parent != -1 && parent != nnodes - 1) {

      // lock parent
      //pthread_mutex_lock(&node_locks[parent]);
      int subdiag_h = H_h - H_w;
      float* C = H_workspace + H_w * (H_h + 1);
      int next_H_h = node_height[parent];
      int next_H_w = node_width[parent];


      float* next_H_workspace = node_arr[parent];

      int next_num_blks = node_num_blks[node];
      int* A_blk_start = node_A_blk_start[node];
      int* B_blk_start = node_B_blk_start[node];
      int* next_blk_width = node_blk_width[node];
     
      packed_dense_block_add(C, next_H_workspace, 
              H_h, next_H_h, next_blk_width,
              H_h, next_H_h,
              A_blk_start, B_blk_start, //C_blk, next_blk,
              next_num_blks, true);

      node_done_children[parent]++;
      if(node_done_children[parent] == node_num_children[parent]) {
          //pthread_mutex_lock(&queue_lock);
          node_ready_queue[node_ready_size] = parent;
          node_ready_size++;
          //pthread_mutex_unlock(&queue_lock);
      } 
#if MATADD == 1
      rr_fence(add_cfgid);
#else
      rr_fence(acc_cfgid);
#endif
      //pthread_mutex_unlock(&node_locks[parent]);
    }
    //free(H_workspace);
    node_arr[node] = NULL;
    //pthread_mutex_unlock(&node_locks[node]);

    merge_end = read_cycles();
    merge_time[node] = merge_end - merge_start;
    merge_profile_cycles[step][node] = merge_end - merge_start;
    node_time[node] = merge_time[node] + chol_time[node] + init_time[node] + AtA_time[node];
/*
    printf("node %d total cycles: %llu\n", node, AtA+chol+merge+init);
    printf("init cycles: %llu\n", init);
    printf("AtA cycles: %llu\n", AtA);
    printf("chol cycles: %llu\n", chol);
    printf("merge cycles: %llu\n", merge);
*/
  }
}


// for profiling
void dual_step_processing_mono(int step, float* AtA_workspace, int avail_mem, int cid, int acc_cfgid1, int acc_cfgid2, int dma_cfgid1, int dma_cfgid2, int add_cfgid){
  bool* node_marked = step_node_marked[step];
  bool* node_fixed = step_node_fixed[step];

  int* node_parent = step_node_parent[step];
  int* node_height = step_node_height[step];
  int* node_width = step_node_width[step];
  float** node_data = step_node_data[step];
  int* node_num_blks = step_node_num_blks[step];
  int** node_A_blk_start = step_node_A_blk_start[step];
  int** node_B_blk_start = step_node_B_blk_start[step];
  int** node_blk_width = step_node_blk_width[step];

  int nnodes = step_nnodes[step];
  int* node_num_factors = step_node_num_factors[step];
  int** node_factor_height = step_node_factor_height[step];
  int** node_factor_width = step_node_factor_width[step];
  float*** node_factor_data = step_node_factor_data[step];
  int** node_factor_num_blks = step_node_factor_num_blks[step];
  int*** node_factor_A_blk_start = step_node_factor_A_blk_start[step];
  int*** node_factor_B_blk_start = step_node_factor_B_blk_start[step];
  int*** node_factor_blk_width = step_node_factor_blk_width[step];
 
  uint64_t chol_start = 0, chol_end = 0, chol = 0;
  uint64_t merge_start = 0, merge_end = 0, merge = 0;
  uint64_t AtA_start = 0, AtA_end = 0, AtA = 0;
  uint64_t init_start = 0, init_end = 0, init = 0;
  // Setup
  bool granted = false;
  int channel = 0;
  int index = 0;
  uint64_t expected_cycles = 0; 

  int wait_turn = 0;
  // start processing
  while(true) {
    bool done_flag = false;
    bool wait_flag = false;
    int node = -1;
    //pthread_mutex_lock(&queue_lock);

    if(node_ready_index < node_ready_size) {
        node = node_ready_queue[node_ready_index];
        node_ready_index++;
	wait_turn = 0;
    }
    else if(node_ready_size == num_active_nodes) {
        done_flag = true;
    }
    else if(node_ready_size > num_active_nodes) {
        printf("thread %d: Ready queue size %d reater than active nodes %d!\n", cid, backsolve_ready_size, num_active_nodes);
        exit(1);
    }
    else {
        wait_flag = true;
	wait_turn ++;
	if(wait_turn %10 == 1){
           printf("illegal wait %d, %d, %d\n", node_ready_index, node_ready_size, num_active_nodes);
	}
    }

    //pthread_mutex_unlock(&queue_lock);

    if(done_flag) {
        break;
    }
    else if(wait_flag) {
        continue;
    }
        
    //printf("thread %d node = %d\n", cid, node);
    //fflush(stdout);

    //pthread_mutex_lock(&node_locks[node]);
    bool marked = node_marked[node];
    bool fixed = node_fixed[node];

    //if(!marked && !fixed) { continue; }
    if(!marked && !fixed) { 
       //pthread_mutex_unlock(&node_locks[node]);
       printf("this should not happen - thread %d node %d\n", cid, node);
       exit(1);
       //continue; 
    }

    int parent = node_parent[node];
    int H_h = node_height[node];
    int H_w = node_width[node];
    float* H_data = node_data[node];

    int num_factors = node_num_factors[node];
    int* factor_height = node_factor_height[node];
    int* factor_width = node_factor_width[node];
    float** factor_data = node_factor_data[node];
    int* factor_num_blks = node_factor_num_blks[node];
    int** factor_A_blk_start = node_factor_A_blk_start[node];
    int** factor_B_blk_start = node_factor_B_blk_start[node];
    int** factor_blk_width = node_factor_blk_width[node];
    
    init_start = read_cycles();
    // assign workspace
    if(node_arr[node] == 0) {
       node_arr[node] = (float*) my_malloc(H_h * H_h * sizeof(float));
       /*
       int memset_channel = 2;
       granted = false;
       while(!granted)
         dma_source_config(memset_channel, granted, false, NULL, H_h * sizeof(float));
       dma_nord_dest_config(memset_channel, false, (float*) node_arr[node], H_h * sizeof(float));
      
       granted = false;
       while(!granted)
         dma_memcpy_tile(memset_channel, granted, 0, 0, 0, H_h, H_h * sizeof(elem_t));
	 */
       int memset_channel = 2;
       int col_block = H_h > 128 ? ceil_divide_int(H_h, 2) : H_h; 
       for(int col = 0; col < H_h; col += col_block){
         if(memset_channel >= NUM_CHANNEL){
           printf("node too large\n");
           exit(1);
         }
         int columns = H_h - col > col_block ? col_block : H_h - col; 
         float* workspace_start = (float*) node_arr[node] + col; 
         granted = false;
         while(!granted)
           dma_source_config(memset_channel, granted, false, NULL, H_h * sizeof(float));
         dma_nord_dest_config(memset_channel, false, workspace_start, H_h * sizeof(float));
         granted = false;
         while(!granted)
           dma_memcpy_tile(memset_channel, granted, 0, 0, 0, H_h, columns * sizeof(float));
         memset_channel ++;
       }
       rr_fence(dma_cfgid1);
      //my_memset(node_arr[node], 0, H_h * H_h * sizeof(float));
    }
    init_end = read_cycles();
    init_time[node] = init_end - init_start;
    init_profile_cycles[step][node] = init_end - init_start;
    node_thread[node] += (cid + 10);
    float* H_workspace = node_arr[node];
    
    // Marked nodes
    // 1. AtA
    // 2. Cholesky (partial_factorization)
    // 3. Add LC to parent
    // 4. Copy [A B] back from workspace
    // Fixed nodes
    // 1. AtA
    // 2. LC = -LB LB^T
    // 3. Add LC to parent
    // 4. Don't copy [A B] back from workspace

    // 1. AtA

    // AtA
    AtA_start = read_cycles();
    int tile_nfactor = tiling_AtA_nfactor(num_factors, max_factor_height, max_factor_width, avail_mem);
    //printf("num factors: %d, tile nfactor: %d\n", num_factors, tile_nfactor);
    //fflush(stdout);

    // AtA workspace: AtA
    // workspace: A
    float* workspace = (float*) AtA_workspace + max_factor_height * max_factor_height * tile_nfactor;//node_nfactors[node];
    for(int f = 0; f < num_factors; f += tile_nfactor){
      int this_nfactors = f + tile_nfactor < num_factors ? tile_nfactor : num_factors - f;
      int dma_i = 0; // todo
      //workspace = (float*) base_addr;
      dual_tile_AtA_supernode_pointer(f, this_nfactors, max_factor_height, node_factor_height[node], node_factor_width[node], node_factor_data[node], H_h, H_w, NULL, H_workspace, (float*) AtA_workspace, (float*) workspace, factor_A_blk_start, factor_B_blk_start, factor_blk_width, factor_num_blks, dma_i, NUM_CHANNEL, acc_cfgid1, acc_cfgid2, dma_cfgid1, add_cfgid);   
    }
    AtA_end = read_cycles();
    AtA_time[node] = AtA_end - AtA_start;
    AtA_profile_cycles[step][node] = AtA_end - AtA_start;

    // do memset background 
    //printf("thread %d width %d height %d\n", cid, H_w, H_h);    
    //fflush(stdout);     
    //int parent = node_parent[node];
    chol_start = read_cycles();
    if(parent != -1 && parent != nnodes - 1){
       //pthread_mutex_lock(&node_locks[parent]);
       if(node_arr[parent] ==0){
         int next_H_h = node_height[parent];
         node_arr[parent] = (float*) my_malloc(next_H_h * next_H_h * sizeof(float));
         if(node_arr[parent] == NULL){
             printf("parent not allocated\n");
             exit(0);
         }
#if ReRoCC == 1
         rr_set_opc(XCUSTOM_DMA, dma_cfgid2);
#endif
          channel = 2;
          int col_block = next_H_h > 128 ? ceil_divide_int(next_H_h, 2) : next_H_h; 
          for(int col = 0; col < next_H_h; col += col_block){
            if(channel >= NUM_CHANNEL){
              printf("node too large\n");
              exit(1);
            }
            int columns = next_H_h - col > col_block ? col_block : next_H_h - col; 
            float* workspace_start = node_arr[parent] + col; 
            granted = false;
            while(!granted)
              dma_source_config(channel, granted, false, NULL, next_H_h * sizeof(float));
            dma_nord_dest_config(channel, false, workspace_start, next_H_h * sizeof(float));
            granted = false;
            while(!granted)
              dma_memcpy_tile(channel, granted, 0, 0, 0, next_H_h, columns * sizeof(float));
            channel ++;
          }
#if ReRoCC == 1
          rr_set_opc(XCUSTOM_DMA, dma_cfgid1);
#endif
 
       }
       //pthread_mutex_unlock(&node_locks[parent]);
    }
    if(marked) { 
        // 2. Cholesky
        //partial_factorization4(H_workspace, H_w, H_h);
        channel = 0;
        int chol_block_size = H_w < CHOL_BLOCK_SIZE ? H_w : CHOL_BLOCK_SIZE;
        dual_workspace_partial_factorization(H_workspace, H_data, H_w, H_h, chol_block_size, channel, acc_cfgid1, acc_cfgid2, dma_cfgid1);
      //partial_factorization4(ABC, H_w, H_h);

    }
    else if(fixed) {
        //printf("no cholesky, width %d height %d\n", H_w, H_h);
        // 2. LC = -LB LB^T
        int subdiag_h = H_h - H_w;
        float* LB = H_data + H_w;
        float* LC = H_workspace + H_w * (H_h + 1);

        tiled_matmul_auto(subdiag_h, subdiag_h, H_w,
                LB, LB, LC, LC,
                H_h, H_h, H_h, H_h,
                -1, 1, 1,
                NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
                true, false,
                false, false, 0, WS);
    }

    rr_fence(dma_cfgid1);
    rr_fence(acc_cfgid1);
    rr_fence(dma_cfgid2);
    chol_end = read_cycles();
    chol_time[node] = chol_end - chol_start;
    chol_profile_cycles[step][node] = chol_end - chol_start;
    //printf("thread %d done cholesky\n", cid);
    //fflush(stdout);

    merge_start = read_cycles();
    // 3. Add LC to parent
    if(parent != -1 && parent != nnodes - 1) {

      // lock parent
      //pthread_mutex_lock(&node_locks[parent]);
      int subdiag_h = H_h - H_w;
      float* C = H_workspace + H_w * (H_h + 1);
      int next_H_h = node_height[parent];
      int next_H_w = node_width[parent];


      float* next_H_workspace = node_arr[parent];

      int next_num_blks = node_num_blks[node];
      int* A_blk_start = node_A_blk_start[node];
      int* B_blk_start = node_B_blk_start[node];
      int* next_blk_width = node_blk_width[node];
     
      packed_dense_block_add(C, next_H_workspace, 
              H_h, next_H_h, next_blk_width,
              H_h, next_H_h,
              A_blk_start, B_blk_start, //C_blk, next_blk,
              next_num_blks, true);

      node_done_children[parent]++;
      if(node_done_children[parent] == node_num_children[parent]) {
          //pthread_mutex_lock(&queue_lock);
          node_ready_queue[node_ready_size] = parent;
          node_ready_size++;
          //pthread_mutex_unlock(&queue_lock);
      } 

#if MATADD == 1
      rr_fence(add_cfgid);
#else
      rr_fence(acc_cfgid1);
#endif
      //pthread_mutex_unlock(&node_locks[parent]);
    }
    //free(H_workspace);
    node_arr[node] = NULL;
    //pthread_mutex_unlock(&node_locks[node]);

    merge_end = read_cycles();
    merge_time[node] = merge_end - merge_start;
    merge_profile_cycles[step][node] = merge_end - merge_start;
    node_time[node] = merge_time[node] + chol_time[node] + init_time[node] + AtA_time[node];
/*
    printf("node %d total cycles: %llu\n", node, AtA+chol+merge+init);
    printf("init cycles: %llu\n", init);
    printf("AtA cycles: %llu\n", AtA);
    printf("chol cycles: %llu\n", chol);
    printf("merge cycles: %llu\n", merge);
*/
  }

}
/*
void dnn_function(int cid, int wid, int step){
  int num_array = dnn_avg_num_array[wid];
  int target_cycles = dnn_target[wid];
  int num_layer = dnn_num_layer[wid];

  bool canceled = false;
  uint64_t start = read_cycles();
  // TODO: repartition
  // for debug
  if(wid == EMF){
    if(step_run_model[step*5] == false){ 
      pthread_mutex_lock(&drop_request);
      drop_frame[i] = false;
      canceled = true;
      pthread_mutex_unlock(&drop_request);
    }
    int num_layer_kws = dnn_num_layer[wid+1];
    for(int l = 0; l < num_layer_kws; l++){
      uint64_t layer_start = read_cycles();
      uint64_t layer_end = layer_start + 10;
      int n = num_array; // needs to repartitioned
      uint64_t layer_cycles = dnn_layer_cycles[wid+1][n][l];
      while(layer_end - layer_start < layer_cycles){
        for(int k = 0; k < 10000; k *= 2){}
        layer_end = read_cycles();
      }
    }
  }
  else{
    pthread_mutex_lock(&drop_request);
    if(drop_frame[i] == true){
      pthread_mutex_unlock(&drop_request);
      step ++;
      drop_frame[i] = false;
      printf("cid %d - frame dropped at step %d\n", cid, step);
      end = read_cycles();
      // skip this frame
      while(end - start < frame_target[wid]){
        for(int k = 0; k < 100000; k *= 2){}
        end = read_cycles();
      }
      continue;
    }
    pthread_mutex_unlock(&drop_request);
  }
  // TODO: separate KWS + emformer
  
  for(int l = 0; l < num_layer; l++){
    if(canceled)
      break;
    uint64_t layer_start = read_cycles();
    uint64_t layer_end = layer_start + 10;
    int n = num_array; // needs to repartitioned
    uint64_t layer_cycles = dnn_layer_cycles[wid][n][l];
    while(layer_end - layer_start < layer_cycles){
      for(int k = 0; k < 10000; k *= 2){}
      layer_end = read_cycles();
    }
  }
  uint64_t end = read_cycles();
  total_dnn_cycles[cid][step] = end - start;
}
*/
  // real
  /*
  if(wid == 0){
    res18net_function_1(-1, num_array, cid);
  }
  else if(wid == 1){
    trailnet_function_1(-1, num_array, cid);
  }
  else if(wid == 2){
    yolonet_function_1(-1, num_array, cid);
  }
  else if(wid == 3){
    depthnet_function_1(-1, num_array, cid);
  }
  else if(wid == 2){
    kwsnet_function_1(-1, num_array, cid);
    emformer_function_1(-1, num_array, cid);
  }
  else if(wid == 2){
    control_function_1(-1, num_array, cid);
  }
  */

// to drop accelerator
// np dma 
/*
void step_processing_only_gemm(int step, float* AtA_workspace, int avail_mem, int cid, int acc_cfgid, int add_cfgid){
  bool* node_marked = step_node_marked[step];
  bool* node_fixed = step_node_fixed[step];

  int* node_parent = step_node_parent[step];
  int* node_height = step_node_height[step];
  int* node_width = step_node_width[step];
  float** node_data = step_node_data[step];
  int* node_num_blks = step_node_num_blks[step];
  int** node_A_blk_start = step_node_A_blk_start[step];
  int** node_B_blk_start = step_node_B_blk_start[step];
  int** node_blk_width = step_node_blk_width[step];

  int nnodes = step_nnodes[step];
  int* node_num_factors = step_node_num_factors[step];
  int** node_factor_height = step_node_factor_height[step];
  int** node_factor_width = step_node_factor_width[step];
  float*** node_factor_data = step_node_factor_data[step];
  int** node_factor_num_blks = step_node_factor_num_blks[step];
  int*** node_factor_A_blk_start = step_node_factor_A_blk_start[step];
  int*** node_factor_B_blk_start = step_node_factor_B_blk_start[step];
  int*** node_factor_blk_width = step_node_factor_blk_width[step];
 
  uint64_t chol_start = 0, chol_end = 0, chol = 0;
  uint64_t merge_start = 0, merge_end = 0, merge = 0;
  uint64_t AtA_start = 0, AtA_end = 0, AtA = 0;
  uint64_t init_start = 0, init_end = 0, init = 0;
  // Setup
  bool granted = false;
  int channel = 0;
  int index = 0;
  uint64_t expected_cycles = 0; 

  int wait_turn = 0;
  // start processing
  while(true) {
    bool done_flag = false;
    bool wait_flag = false;
    int node = -1;
    //pthread_mutex_lock(&queue_lock);

    if(node_ready_index < node_ready_size) {
        node = node_ready_queue[node_ready_index];
        node_ready_index++;
	wait_turn = 0;
    }
    else if(node_ready_size == num_active_nodes) {
        done_flag = true;
    }
    else if(node_ready_size > num_active_nodes) {
        printf("thread %d: Ready queue size %d reater than active nodes %d!\n", cid, backsolve_ready_size, num_active_nodes);
        exit(1);
    }
    else {
        wait_flag = true;
	wait_turn ++;
	if(wait_turn %10 == 1){
           printf("illegal wait %d, %d, %d\n", node_ready_index, node_ready_size, num_active_nodes);
	}
    }

    //pthread_mutex_unlock(&queue_lock);

    if(done_flag) {
        break;
    }
    else if(wait_flag) {
        continue;
    }
        
    //printf("thread %d node = %d\n", cid, node);
    //fflush(stdout);

    //pthread_mutex_lock(&node_locks[node]);
    bool marked = node_marked[node];
    bool fixed = node_fixed[node];

    //if(!marked && !fixed) { continue; }
    if(!marked && !fixed) { 
       //pthread_mutex_unlock(&node_locks[node]);
       printf("this should not happen - thread %d node %d\n", cid, node);
       exit(1);
       //continue; 
    }

    int parent = node_parent[node];
    int H_h = node_height[node];
    int H_w = node_width[node];
    float* H_data = node_data[node];

    int num_factors = node_num_factors[node];
    int* factor_height = node_factor_height[node];
    int* factor_width = node_factor_width[node];
    float** factor_data = node_factor_data[node];
    int* factor_num_blks = node_factor_num_blks[node];
    int** factor_A_blk_start = node_factor_A_blk_start[node];
    int** factor_B_blk_start = node_factor_B_blk_start[node];
    int** factor_blk_width = node_factor_blk_width[node];
    
    init_start = read_cycles();
    if(node_arr[node] == 0) {
       node_arr[node] = (float*) my_malloc(H_h * H_h * sizeof(float));
       memset(node_arr[node], 0, H_h * H_h * sizeof(float));
      //my_memset(node_arr[node], 0, H_h * H_h * sizeof(float));
      did_memset[node] = true;
    }
    init_end = read_cycles();
    init_time[node] = init_end - init_start;
    init_profile_cycles[step][node] = init_end - init_start;
    node_thread[node] += (cid + 10);
    float* H_workspace = node_arr[node];
    
    // Marked nodes
    // 1. AtA
    // 2. Cholesky (partial_factorization)
    // 3. Add LC to parent
    // 4. Copy [A B] back from workspace
    // Fixed nodes
    // 1. AtA
    // 2. LC = -LB LB^T
    // 3. Add LC to parent
    // 4. Don't copy [A B] back from workspace

    // 1. AtA

    // AtA
    AtA_start = read_cycles();
    int tile_nfactor = tiling_AtA_nfactor(num_factors, max_factor_height, max_factor_width, avail_mem);
    //printf("num factors: %d, tile nfactor: %d\n", num_factors, tile_nfactor);
    //fflush(stdout);

    // AtA workspace: AtA
    // workspace: A
    float* workspace = (float*) AtA_workspace + max_factor_height * max_factor_height * tile_nfactor;//node_nfactors[node];
    for(int f = 0; f < num_factors; f += tile_nfactor){
      int this_nfactors = f + tile_nfactor < num_factors ? tile_nfactor : num_factors - f;
      int dma_i = 0; // todo
      //workspace = (float*) base_addr;
      tile_AtA_supernode_pointer_nodma(f, this_nfactors, max_factor_height, node_factor_height[node], node_factor_width[node], node_factor_data[node], H_h, H_w, NULL, H_workspace, (float*) AtA_workspace, (float*) workspace, factor_A_blk_start, factor_B_blk_start, factor_blk_width, factor_num_blks, dma_i, acc_cfgid, add_cfgid);   
    }
    AtA_end = read_cycles();
    AtA_time[node] = AtA_end - AtA_start;
    AtA_profile_cycles[step][node] = AtA_end - AtA_start;

    // do memset background 
    //printf("thread %d width %d height %d\n", cid, H_w, H_h);    
    //fflush(stdout);     
    //int parent = node_parent[node];
    chol_start = read_cycles();
    if(marked) { 
        // 2. Cholesky
        //partial_factorization4(H_workspace, H_w, H_h);
        channel = 0;
        int chol_block_size = H_w < CHOL_BLOCK_SIZE ? H_w : CHOL_BLOCK_SIZE;
        full_workspace_partial_factorization(H_workspace, H_data, H_w, H_h, chol_block_size, channel, acc_cfgid, -1);
      //partial_factorization4(ABC, H_w, H_h);

    }
    else if(fixed) {
        //printf("no cholesky, width %d height %d\n", H_w, H_h);
        // 2. LC = -LB LB^T
        int subdiag_h = H_h - H_w;
        float* LB = H_data + H_w;
        float* LC = H_workspace + H_w * (H_h + 1);

        tiled_matmul_auto(subdiag_h, subdiag_h, H_w,
                LB, LB, LC, LC,
                H_h, H_h, H_h, H_h,
                -1, 1, 1,
                NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
                true, false,
                false, false, 0, WS);
    }

    //rr_fence(dma_cfgid);
    rr_fence(acc_cfgid);
    chol_end = read_cycles();
    chol_time[node] = chol_end - chol_start;
    chol_profile_cycles[step][node] = chol_end - chol_start;
    //printf("thread %d done cholesky\n", cid);
    //fflush(stdout);

    merge_start = read_cycles();
    // 3. Add LC to parent
    if(parent != -1 && parent != nnodes - 1) {

      // lock parent
      //pthread_mutex_lock(&node_locks[parent]);
      int subdiag_h = H_h - H_w;
      float* C = H_workspace + H_w * (H_h + 1);
      int next_H_h = node_height[parent];
      int next_H_w = node_width[parent];

      if(node_arr[parent] == 0) {
          node_arr[parent] = malloc(next_H_h * next_H_h * sizeof(float));
          memset(node_arr[parent], 0, next_H_h * next_H_h * sizeof(float));
          did_memset[node] = true;
      }

      float* next_H_workspace = node_arr[parent];

      int next_num_blks = node_num_blks[node];
      int* A_blk_start = node_A_blk_start[node];
      int* B_blk_start = node_B_blk_start[node];
      int* next_blk_width = node_blk_width[node];
     
      packed_dense_block_add(C, next_H_workspace, 
              H_h, next_H_h, next_blk_width,
              H_h, next_H_h,
              A_blk_start, B_blk_start, //C_blk, next_blk,
              next_num_blks, true);

      node_done_children[parent]++;
      if(node_done_children[parent] == node_num_children[parent]) {
          //pthread_mutex_lock(&queue_lock);
          node_ready_queue[node_ready_size] = parent;
          node_ready_size++;
          //pthread_mutex_unlock(&queue_lock);
      } 
#if MATADD == 1
      rr_fence(add_cfgid);
#else
      rr_fence(acc_cfgid);
#endif
      //pthread_mutex_unlock(&node_locks[parent]);
    }
    //free(H_workspace);
    node_arr[node] = NULL;
    //pthread_mutex_unlock(&node_locks[node]);

    merge_end = read_cycles();
    merge_time[node] = merge_end - merge_start;
    merge_profile_cycles[step][node] = merge_end - merge_start;
    node_time[node] = merge_time[node] + chol_time[node] + init_time[node] + AtA_time[node];
  }
}
*/
void step_processing_only_gemm(int step, float* AtA_workspace, int avail_mem, int cid, int acc_cfgid, int add_cfgid){
  bool* node_marked = step_node_marked[step];
  bool* node_fixed = step_node_fixed[step];

  int* node_parent = step_node_parent[step];
  int* node_height = step_node_height[step];
  int* node_width = step_node_width[step];
  float** node_data = step_node_data[step];
  int* node_num_blks = step_node_num_blks[step];
  int** node_A_blk_start = step_node_A_blk_start[step];
  int** node_B_blk_start = step_node_B_blk_start[step];
  int** node_blk_width = step_node_blk_width[step];

  int nnodes = step_nnodes[step];
  int* node_num_factors = step_node_num_factors[step];
  int** node_factor_height = step_node_factor_height[step];
  int** node_factor_width = step_node_factor_width[step];
  float*** node_factor_data = step_node_factor_data[step];
  int** node_factor_num_blks = step_node_factor_num_blks[step];
  int*** node_factor_A_blk_start = step_node_factor_A_blk_start[step];
  int*** node_factor_B_blk_start = step_node_factor_B_blk_start[step];
  int*** node_factor_blk_width = step_node_factor_blk_width[step];
 
  uint64_t chol_start = 0, chol_end = 0, chol = 0;
  uint64_t merge_start = 0, merge_end = 0, merge = 0;
  uint64_t AtA_start = 0, AtA_end = 0, AtA = 0;
  uint64_t init_start = 0, init_end = 0, init = 0;
  // Setup
  bool granted = false;
  int channel = 0;
  int index = 0;
  uint64_t expected_cycles = 0; 
  pthread_barrier_wait(&barrier_slam);
  int accel = 1;
  int co_running = 1;

  // start processing
  while(true) {
    bool done_flag = false;
    bool wait_flag = false;
    int node = -1;
    //printf("thread %d \n", cid);
    //fflush(stdout);
    pthread_mutex_lock(&queue_lock);

    if(node_ready_index < node_ready_size) {
      node = node_ready_queue[node_ready_index];
      node_ready_index++;
      
      co_running = 0;
      for(int i = 0; i < NUM_CORE; i++)
        if(active_thread[i]) co_running++;
      if(co_running == 1){
        if(accel < NUM_CORE){
          for(int i = 0; i < NUM_CORE; i++){
            if(i != cid){
              bool acquire = rr_acquire_single(acc_cfgid+accel, ACC_START+i);
              if(acquire){
                //rr_acquire_single(acc_cfgid+accel, ACC_START+i);
                accel ++;
                if(accel == NUM_CORE)
                  break;
              }
            }
          }
        }
      }
      else if(co_running < NUM_CORE){
        if(accel == 1){
          for(int i = 0; i < NUM_CORE; i++){
            if(i!=cid){
              bool acquire = rr_acquire_single(acc_cfgid+accel, ACC_START+i);
              if(acquire){
                //rr_acquire_single(acc_cfgid+accel, ACC_START+i);
                accel ++;
                break;
              }
            }
          }
        }
      }
    }
    
    else if(node_ready_size == num_active_nodes) {
        done_flag = true;
    }
    else if(node_ready_size > num_active_nodes) {
        printf("thread %d: Ready queue size %d reater than active nodes %d!\n", cid, backsolve_ready_size, num_active_nodes);
        exit(1);
    }
    else {
        // release in advance
        for(int i = 0; i < accel; i++){
          rr_release(acc_cfgid + i);
          //rr_release(dma_cfgid + i);
        }
        active_thread[cid] = false;
        wait_flag = true;
    }

    pthread_mutex_unlock(&queue_lock);

    if(done_flag) {
        break;
    }
    else if(wait_flag) {
#if PRINT_DEBUG
        printf("thread %d exit\n", cid);
#endif
        break;
        //continue;
    }
    int H_h = node_height[node];
    int H_w = node_width[node];
    
#if PRINT_DEBUG
    printf("thread %d node = %d (H %d, W %d), num accel: %d\n", cid, node, H_h, H_w, accel);
    fflush(stdout);
#endif
    //pthread_mutex_lock(&node_locks[node]);
    bool marked = node_marked[node];
    bool fixed = node_fixed[node];

    //if(!marked && !fixed) { continue; }
    if(!marked && !fixed) { 
       //pthread_mutex_unlock(&node_locks[node]);
       printf("this should not happen - thread %d node %d\n", cid, node);
       exit(1);
       //continue; 
    }

    int parent = node_parent[node];
    float* H_data = node_data[node];

    int num_factors = node_num_factors[node];
    int* factor_height = node_factor_height[node];
    int* factor_width = node_factor_width[node];
    float** factor_data = node_factor_data[node];
    int* factor_num_blks = node_factor_num_blks[node];
    int** factor_A_blk_start = node_factor_A_blk_start[node];
    int** factor_B_blk_start = node_factor_B_blk_start[node];
    int** factor_blk_width = node_factor_blk_width[node];
    
    init_start = read_cycles();
    // assign workspace
    if(node_arr[node] == 0) {
       node_arr[node] = (float*) my_malloc(H_h * H_h * sizeof(float));
       memset(node_arr[node], 0, H_h * H_h * sizeof(float));
      //my_memset(node_arr[node], 0, H_h * H_h * sizeof(float));
      did_memset[node] = true;
    }
    init_end = read_cycles();
    init_time[node] = init_end - init_start;
    node_thread[node] += (cid + 10);
    float* H_workspace = node_arr[node];
     
#if PRINT_DEBUG
    printf("thread %d num factors %d\n", cid, num_factors);    
    fflush(stdout);     
#endif
    // Marked nodes
    // 1. AtA
    // 2. Cholesky (partial_factorization)
    // 3. Add LC to parent
    // 4. Copy [A B] back from workspace
    // Fixed nodes
    // 1. AtA
    // 2. LC = -LB LB^T
    // 3. Add LC to parent
    // 4. Don't copy [A B] back from workspace

    // 1. AtA

    // AtA
    AtA_start = read_cycles();
    int tile_nfactor = tiling_AtA_nfactor(num_factors, max_factor_height, max_factor_width, avail_mem);
    //printf("num factors: %d, tile nfactor: %d\n", num_factors, tile_nfactor);

    // AtA workspace: AtA
    // workspace: A
    float* workspace = (float*) AtA_workspace + max_factor_height * max_factor_height * tile_nfactor;//node_nfactors[node];
    for(int f = 0; f < num_factors; f += tile_nfactor){
      int this_nfactors = f + tile_nfactor < num_factors ? tile_nfactor : num_factors - f;
      int dma_i = 0; // todo
      //workspace = (float*) base_addr;
    
      tile_AtA_supernode_pointer_nodma(f, this_nfactors, max_factor_height, node_factor_height[node], node_factor_width[node], node_factor_data[node], H_h, H_w, NULL, H_workspace, (float*) AtA_workspace, (float*) workspace, factor_A_blk_start, factor_B_blk_start, factor_blk_width, factor_num_blks, dma_i, acc_cfgid, add_cfgid);
      //dual_tile_AtA_supernode_pointer(f, this_nfactors, max_factor_height, node_factor_height[node], node_factor_width[node], node_factor_data[node], H_h, H_w, NULL, H_workspace, (float*) AtA_workspace, (float*) workspace, factor_A_blk_start, factor_B_blk_start, factor_blk_width, factor_num_blks, dma_i, NUM_CHANNEL, acc_cfgid, acc_cfgid+1, dma_cfgid, add_cfgid);
    }
    AtA_end = read_cycles();
    AtA_time[node] = AtA_end - AtA_start;

#if PRINT_DEBUG
    // do memset background 
    printf("thread %d width %d height %d\n", cid, H_w, H_h);    
    fflush(stdout);    
#endif
    //int parent = node_parent[node]; 
    chol_start = read_cycles(); 
    if(marked) { 
        // 2. Cholesky
        //partial_factorization4(H_workspace, H_w, H_h);
        channel = 0;
        int chol_block_size = H_w < CHOL_BLOCK_SIZE ? H_w : CHOL_BLOCK_SIZE;
        multi_workspace_partial_factorization(H_workspace, H_data, H_w, H_h, chol_block_size, channel, acc_cfgid, -1, accel);
      //partial_factorization4(ABC, H_w, H_h);

    }
    else if(fixed) {
        //printf("no cholesky, width %d height %d\n", H_w, H_h);
        // 2. LC = -LB LB^T
        int subdiag_h = H_h - H_w;
        float* LB = H_data + H_w;
        float* LC = H_workspace + H_w * (H_h + 1);

        tiled_matmul_auto(subdiag_h, subdiag_h, H_w,
                LB, LB, LC, LC,
                H_h, H_h, H_h, H_h,
                -1, 1, 1,
                NO_ACTIVATION, ACC_SCALE_IDENTITY, 0, false,
                true, false,
                false, false, 0, WS);
    }
    rr_fence(acc_cfgid);
    chol_end = read_cycles();
    chol_time[node] = chol_end - chol_start;
    chol_num_array[node] = accel;
    node_corunning[node] = co_running;
    
#if PRINT_DEBUG
    printf("thread %d done cholesky marked %d\n", cid, marked);
    fflush(stdout);
#endif
    merge_start = read_cycles();
    // 3. Add LC to parent
    if(parent != -1 && parent != nnodes - 1) {

      // lock parent
      pthread_mutex_lock(&node_locks[parent]);
      int subdiag_h = H_h - H_w;
      float* C = H_workspace + H_w * (H_h + 1);
      int next_H_h = node_height[parent];
      int next_H_w = node_width[parent];

      if(node_arr[parent] == 0) {
          node_arr[parent] = malloc(next_H_h * next_H_h * sizeof(float));
          memset(node_arr[parent], 0, next_H_h * next_H_h * sizeof(float));
          did_memset[node] = true;
      }

      float* next_H_workspace = node_arr[parent];

      int next_num_blks = node_num_blks[node];
      int* A_blk_start = node_A_blk_start[node];
      int* B_blk_start = node_B_blk_start[node];
      int* next_blk_width = node_blk_width[node];
     
      packed_dense_block_add(C, next_H_workspace, 
              H_h, next_H_h, next_blk_width,
              H_h, next_H_h,
              A_blk_start, B_blk_start, //C_blk, next_blk,
              next_num_blks, true);

      node_done_children[parent]++;
      if(node_done_children[parent] == node_num_children[parent]) {
          pthread_mutex_lock(&queue_lock);
          node_ready_queue[node_ready_size] = parent;
          node_ready_size++;
          pthread_mutex_unlock(&queue_lock);
      } 

      //rr_fence(add_cfgid);
      rr_fence(acc_cfgid);
      pthread_mutex_unlock(&node_locks[parent]);
    }
    //free(H_workspace);
    node_arr[node] = NULL;
    //pthread_mutex_unlock(&node_locks[node]);

    merge_end = read_cycles();
    merge_time[node] = merge_end - merge_start;
    node_time[node] = merge_time[node] + chol_time[node] + init_time[node] + AtA_time[node];
#if PRINT_DEBUG
    printf("thread %d done node %d\n", cid, node);
    fflush(stdout);
#endif
  }
}

#endif
