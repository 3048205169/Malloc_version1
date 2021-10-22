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
  printf("int *p1 = bf_malloc(10*sizeof(int));\n");
  print_mem_list();
  printf("p1 point at %p\n",p1);  
  printf("================================\n");

  bf_free(p1);//free p1
  printf("bf_free(p1);\n");
  print_mem_list();
  printf("p1 point at %p\n",p1);
  printf("================================\n");
  
  char *p2 = bf_malloc(5*sizeof(char));//malloc p2
  printf("char *p2 = bf_malloc(5*sizeof(char));\n");
  print_mem_list();
  printf("p2 point at %p\n",p2);
  printf("================================\n");

  double *p3 = bf_malloc(6*sizeof(double));//malloc p3
  printf("double *p3 = bf_malloc(6*sizeof(double));\n");
  print_mem_list();
  printf("p3 point at %p\n",p3);
  printf("================================\n");

  int *p4 = bf_malloc(3*sizeof(int));//malloc p4
  printf("int *p4 = bf_malloc(3*sizeof(int));\n");
  print_mem_list();
  printf("p4 point at %p\n",p4);
  printf("================================\n");
  return EXIT_SUCCESS;
}


