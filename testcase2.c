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
  int *p1 = ff_malloc(10*sizeof(int));//malloc p1
  /**
  print_mem_list();
  printf("p1 point at %p\n",p1);
  //=====================
  */  
  ff_free(p1);//free p1
  /**
  print_mem_list();
  printf("p point at %p\n",p1);
  */
  char *p2 = ff_malloc(5*sizeof(char));//malloc p2
  print_mem_list();
  printf("p2 point at %p\n",p2);
  printf("================================\n");
  double *p3 = ff_malloc(6*sizeof(double));//malloc p3
  print_mem_list();
  printf("p3 point at %p\n",p3);
  printf("================================\n");
  int *p4 = ff_malloc(3*sizeof(int));//malloc p4
  print_mem_list();
  printf("p4 point at %p\n",p4);
  printf("================================\n");
  return EXIT_SUCCESS;
}


