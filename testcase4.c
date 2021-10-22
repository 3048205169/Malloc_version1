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
  print_mem_list();
  double *p1 = bf_malloc(8*sizeof(double));
  printf("char *p1 = bf_malloc(8*sizeof(double));\n");
  print_mem_list();
  printf("p1 point at %p\n",p1);
  printf("=======================\n");
  
  char *p2 = bf_malloc(18*sizeof(char));
  printf("char *p2 = bf_malloc(18*sizeof(char));\n");
  print_mem_list();
  printf("p2 point at %p\n",p2);
  printf("=======================\n");
  
  
  double *p3 = bf_malloc(6*sizeof(double));
  printf("double *p3 = bf_malloc(6*sizeof(double));\n");
  print_mem_list();
  printf("p3 point at %p\n",p3);
  printf("=======================\n");
  
  char *p4 = bf_malloc(3*sizeof(char));
  printf("char *p4 = ff_malloc(3*sizeof(char));\n");
  print_mem_list();
  printf("p4 point at %p\n",p4);
  printf("=======================\n");
  
  bf_free(p2);
  printf("ff_free(p2);\n");
  print_mem_list();
  printf("p2 point at %p\n",p2);
  printf("=======================\n");
  
  bf_free(p4);
  printf("ff_free(p4)\n");
  print_mem_list();
  printf("p3 point at %p\n",p3);
  printf("=======================\n");

  
  char *p5 = ff_malloc(3*sizeof(char));
  printf("char *p5 = ff_malloc(3*sizeof(char));\n");
  print_mem_list();
  printf("p5 point at %p\n",p5);
  printf("=======================\n");
  
  
  return EXIT_SUCCESS;
}


