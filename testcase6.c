#include "my_malloc.c"

void print_mem_list(){
  Node* node = head;
  for(;node->next!=head;node=node->next){
    if(node==NULL){
      continue;
    }
    printf("node address = %p,size = %zu,is_free=%u,next = %p\n",(void*)node
	   ,node->size,node->is_free,(void*)node->next);
  }

  printf("node address = %p,size = %zu,is_free=%u,next = %p\n",(void*)node
           ,node->size,node->is_free,(void*)node->next);
    
}

int main(){
  int *p1 = bf_malloc(10*sizeof(int));//malloc p1

  bf_free(p1);//free p1
  p1=NULL;
  char *p2 = bf_malloc(5*sizeof(char));//malloc p2

  double *p3 = bf_malloc(6*sizeof(double));//malloc p3

  int *p4 = bf_malloc(3*sizeof(int));//malloc p4

  ff_free(p2);
  ff_free(p4);
  printf("largest free data segment size = %lu",get_largest_free_data_segment_size());
  
  printf("total free size = %lu",get_total_free_size());
  
  return EXIT_SUCCESS;
}


