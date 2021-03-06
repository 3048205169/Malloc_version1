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
  char *p1 = bf_malloc(3*sizeof(char));

  bf_free(p1);

  bf_free(p1);
  print_mem_list();
  printf("===========================\n");
  
  char *p2 = ff_malloc(3*sizeof(char));

  char *p3 = ff_malloc(4*sizeof(char));

  char *p4 = ff_malloc(2*sizeof(char));

  char *p5 = ff_malloc(3*sizeof(char));

  print_mem_list();
  printf("===========================\n");

  
  ff_free(p3);

  ff_free(p4);

  print_mem_list();
  printf("===========================\n");

  
  return EXIT_SUCCESS;
}


