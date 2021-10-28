#include "my_malloc.c"

void print_mem_list(){
  Node* node = head;
  if(node==NULL){
    return;
  }
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
  char *p1 = ff_malloc(3*sizeof(char));
  
  char *p2 = ff_malloc(5*sizeof(char));
  
  char *p3 = ff_malloc(7*sizeof(char));
  
  ff_free(p2);
  
  char *p4 = ff_malloc(4*sizeof(char));
  
  ff_free(p3);

  ff_free(p3);

  ff_free(p4);
  
  ff_free(p1);
  
  char *p5 = ff_malloc(10*sizeof(char));
  
  char *p6 = ff_malloc(3*sizeof(char));

  printf("largest free data segment size = %lu",get_largest_free_data_segment_size());
  printf("total free size = %lu",get_total_free_size());
  return EXIT_SUCCESS;
}


