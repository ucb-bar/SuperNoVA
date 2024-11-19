// incremental + backsolve
// See LICENSE for license details.
#define _GNU_SOURCE
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <sched.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <float.h>
#ifndef BAREMETAL
#include <sys/mman.h>
#endif
#define ReRoCC 1
#define SPICA 1
#define MATADD ReRoCC
#define NUM_CORE 2 // number of multithreading
#include "include/gemmini_testutils.h"
#include "include/cholesky.h"
#include "datasets/incremental_M3500a_steps-2-3499_period-25/incremental_dataset.h"
//#include "datasets/RA_sphere2500_num_threads-4_steps-2-2000_period-25/incremental_dataset.h"
pthread_barrier_t barrier_global;
pthread_mutex_t ex_queue_mutex;
#include "include/workload.h"
#define acc_CFGID 0
#define dma_CFGID 4 // assume 1 DMA
#define add_CFGID 0
#define INTERVAL 25

#define max_factor_height 13
#define max_factor_width 6

#define ATA_SPACE (SPAD_TOTAL_BYTES/NUM_CORE)
float AtA_space[NUM_CORE][ATA_SPACE/4] row_align(MAX_BLOCK_LEN); 

struct thread_args{
    int cid, num_array, start_acc;
    int turn, step;
    uint64_t backsolve_cycles, incremental_cycles;
};

bool slam_done = false; // later when doing with DNN

void *slam_thread(void *arg){
    //pthread_barrier_wait(&barrier_global);
    pthread_barrier_wait(&barrier_slam);
    struct thread_args * slam_args = (struct thread_args *) arg;
    int cid = slam_args->cid;
    int step = slam_args -> step;
    //int num_array = slam_args -> num_array;
    //for(int i = 0; i < num_array; i++){
    //  rr_acquire_single(i, i + start_acc);
    //  rr_set_opc(XCUSTOM_ACC, i); 
    //  gemmini_flush(0);
    //}
    // for now, assume 1 accel
    // TODO: need to track occupancy
    bool acquire = rr_acquire_single(dma_CFGID, DMA_START+cid);// TODO: dma, add from back?
    if(!acquire)
	printf("failed acquire dma thread %d\n", cid);
    fflush(stdout); 
    rr_set_opc(XCUSTOM_DMA, dma_CFGID);
    acquire = rr_acquire_single(acc_CFGID, ACC_START+cid);
    if(!acquire)
	printf("failed acquire acc thread %d\n", cid);
    fflush(stdout); 
    rr_set_opc(XCUSTOM_ACC, acc_CFGID);
    //acquire = rr_acquire_single(add_CFGID, ADD_START+cid);
    //if(!acquire)
	//printf("failed acquire add thread %d\n", cid);
    //fflush(stdout); 
    //rr_set_opc(XCUSTOM_MATADD, add_CFGID);
    gemmini_flush(0);
    dma_flush(0);
    //matadd_flush(0);
    //printf("flushed \n");  
    int turn = 0;
    pthread_barrier_wait(&barrier_slam);
    int avail_mem = SPAD_TOTAL_BYTES / 2;
    float* AtA_workspace = AtA_space[cid];//(float*) malloc(avail_mem);

    uint64_t start = read_cycles();
    step_processing(step, AtA_workspace, avail_mem, cid, acc_CFGID, dma_CFGID, add_CFGID);

    uint64_t mid = read_cycles();
    for(int i = 0; i < 8; i ++)
      rr_release(i);
    slam_args->incremental_cycles = mid - start;
    //free(AtA_workspace);  
    pthread_barrier_wait(&barrier_slam);
    
    acquire = rr_acquire_single(dma_CFGID, DMA_START+cid);// TODO: dma, add from back?
    if(!acquire)
	printf("failed acquire dma thread %d\n", cid);
    fflush(stdout); 
    rr_set_opc(XCUSTOM_DMA, dma_CFGID);
    acquire = rr_acquire_single(acc_CFGID, ACC_START+cid);
    if(!acquire)
	printf("failed acquire acc thread %d\n", cid);
    fflush(stdout); 
    rr_set_opc(XCUSTOM_ACC, acc_CFGID);
    dma_flush(0);
    gemmini_flush(0);

    mid = read_cycles();
    step_backsolve_processing(step, cid, acc_CFGID, dma_CFGID); 
    uint64_t end = read_cycles();
    slam_args->backsolve_cycles = end - mid;
    rr_release(acc_CFGID);
    rr_release(dma_CFGID);
    //rr_release(add_CFGID);
    //printf("cid %d finished\n", cid);
    //for(int i = 0; i < num_array; i++)
    //    rr_release(i);
    pthread_exit(NULL);
}

void *print_message(void *ptr){
    int cpu_id = sched_getcpu();
   // char *msg;
   // msg = (char *) ptr;
    printf("print msg - cpu_id: %d \n", cpu_id);
   // printf("%s \n", msg);
}

int main() {
#ifndef BAREMETAL
    if (mlockall(MCL_CURRENT | MCL_FUTURE) != 0) {
      perror("mlockall failed");
      exit(1);
    }
#endif
    int cpu_id;
    cpu_id = sched_getcpu();
    printf("main thread cpuid: %d \n", cpu_id);

    cpu_set_t cpuset[NUM_CORE];
    pthread_t thread[NUM_CORE];
    pthread_attr_t attr[NUM_CORE];
    for(int i = 0; i < NUM_CORE; i++)
	pthread_attr_init(&attr[i]);
    struct thread_args slam_args[NUM_CORE];

    printf("create threading \n");
    for(int i = 0; i < NUM_CORE; i++){
	  CPU_ZERO(&cpuset[i]);
	  CPU_SET(i, &cpuset[i]);
	  pthread_attr_setaffinity_np(&attr[i], sizeof(cpu_set_t), &cpuset[i]);
	  pthread_create(&thread[i], &attr[i], print_message, NULL);
    }

    for(int i = 0; i < NUM_CORE; i++){
      pthread_join(thread[i], NULL);
    }
    printf("thread joined after message printing\n");
    if (pthread_mutex_init(&queue_lock, NULL) != 0){
      printf("\n mutex init failed\n");
      return 1;
    }
    for(int n = 0; n < MAX_NNODE; n++){
      if (pthread_mutex_init(&node_locks[n], NULL) != 0){
        printf("\n mutex init failed\n");
        return 1;
      } 
    }

    pthread_barrier_init(&barrier_slam, NULL, NUM_CORE);
    //pthread_barrier_init(&barrier_slam, NULL, NUM_CORE);
    int step_start = 0;
    int step_end = num_timesteps;
    for(int step = step_start; step < step_end; step++){
      int true_step = (step+1)*INTERVAL;//step + timestep_start;
      //if(step == 12)
	 //  continue;
      printf("true step %d\n", true_step);
      step_setup(step, NUM_CORE);
      for(int i = 0; i < NUM_CORE; i++){
          slam_args[i].cid = i;
          slam_args[i].step = step;
          pthread_create(&thread[i], &attr[i], slam_thread, &slam_args[i]);
      }
      for(int i = 0; i < NUM_CORE; i++)
          pthread_join(thread[i], NULL);
      
      step_free(step);
      uint64_t max_cholesky = 0;
      uint64_t max_backsolve = 0;
      for(int i = 0; i < NUM_CORE; i++){
          printf("thread %d cholesky_cycles: %llu\n", i, slam_args[i].incremental_cycles);
          printf("thread %d backsolve_cycles: %llu\n", i, slam_args[i].backsolve_cycles);
          fflush(stdout);
          if(max_cholesky < slam_args[i].incremental_cycles)
              max_cholesky = slam_args[i].incremental_cycles;
          if(max_backsolve < slam_args[i].backsolve_cycles)
              max_backsolve = slam_args[i].backsolve_cycles;
      }
      printf("step %d slam total cycle: %llu\n", step, max_backsolve+max_cholesky);
      fflush(stdout);
    }

    printf("end of test\n");
      for(int node = 0; node < MAX_NNODE; node++) {
          pthread_mutex_destroy(&node_locks[node]);
      }
      pthread_mutex_destroy(&queue_lock);

    
    pthread_barrier_destroy(&barrier_slam);
    printf("==================================\n");
}
