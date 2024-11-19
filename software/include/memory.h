#pragma once

#include <stdint.h>
#include <stdio.h>

#ifndef MAX_WORKSPACE_NEEDED
#define MAX_WORKSPACE_NEEDED 1638400
#endif

#define MEMORY_SIZE (2048*1024) //MAX_WORKSPACE_NEEDED // bytes

// Define a char array to represent the memory space
static double _memory[MEMORY_SIZE / 8];
static int stack_ptr = 0;

// Function to allocate memory
void* my_malloc(unsigned int size) {
  int size_div_8 = (size + 7) / 8;

  // Check memory bound
  if(stack_ptr + size_div_8 >= MEMORY_SIZE / 8) {
    //printf("Out of memory!\n");
    //exit(1);
    stack_ptr = 0;
  }

  double* ret = _memory + stack_ptr;
  stack_ptr += size_div_8;
  return (void*) ret;
}

// Function to reallocate memory
void* my_realloc(void* ptr, int size);

// Function to free all allocated memory
void my_free_all(void* ptr) {
  stack_ptr = 0;
}

// Function to free all allocated memory after ptr
void my_free_after(void* ptr) {
  stack_ptr = (double*) ptr - _memory;
}

void my_memcpy(void* dest, void* src, unsigned int len) {
  for(int i = 0; i < len; i++) {
    ((char*) dest)[i] = ((char*) src)[i];
  }
}

void my_memset(void* dest, char a, unsigned int len) {
  char* d = (char*) dest;
  for(int i = 0; i < len; i++) {
    *d = a;
    d++;
  }
}
