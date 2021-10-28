#include <stdlib.h>
#include <stdio.h>

//First Fit malloc/free
void * ff_malloc(size_t size);
void ff_free(void *ptr);
//Best Fit malloc/free
void * bf_malloc(size_t size);
void bf_free(void *ptr);

typedef struct Node{
  size_t size;//represents the size of this heap memory
  struct Node* next;//store the pointer points at next Node
  int is_free;//1=free 0=malloc
}Node;

void ff_coal();

unsigned long get_largest_free_data_segment_size();

unsigned long get_total_free_size();
