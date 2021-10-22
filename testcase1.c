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
  char *p1 = ff_malloc(3*sizeof(char));
  printf("char *p1 = ff_malloc(3*sizeof(char));\n");
  print_mem_list();
  printf("p1 point at %p\n",p1);
  printf("=======================\n");
  
  char *p2 = ff_malloc(5*sizeof(char));
  printf("char *p2 = ff_malloc(5*sizeof(char));\n");
  print_mem_list();
  printf("p2 point at %p\n",p2);
  printf("=======================\n");
  
  
  char *p3 = ff_malloc(7*sizeof(char));
  printf("char *p3 = ff_malloc(7*sizeof(char));\n");
  print_mem_list();
  printf("p3 point at %p\n",p3);
  printf("=======================\n");
  
  ff_free(p2);
  printf("ff_free(p2);\n");
  print_mem_list();
  printf("p2 point at %p\n",p2);
  printf("=======================\n");
  
  char *p4 = ff_malloc(4*sizeof(char));
  printf("char *p4 = ff_malloc(4*sizeof(char));\n");
  print_mem_list();
  printf("p4 point at %p\n",p4);
  printf("=======================\n");
  
  ff_free(p3);
  printf("ff_free(p3)\n");
  print_mem_list();
  printf("p3 point at %p\n",p3);
  printf("=======================\n");

  ff_free(p3);
  printf("ff_free(p3)\n");
  print_mem_list();
  printf("p3 point at %p\n",p3);
  printf("=======================\n");

  ff_free(p4);
  printf("ff_free(p4)\n");
  print_mem_list();
  printf("p4 point at %p\n",p4);
  printf("=======================\n");
  
  ff_free(p1);
  printf("ff_free(p1)\n");
  print_mem_list();
  printf("p1 point at %p\n",p1);
  printf("=======================\n");
  
  char *p5 = ff_malloc(10*sizeof(char));
  printf("char *p5 = ff_malloc(10*sizeof(char));\n");
  print_mem_list();
  printf("p5 point at %p\n",p5);
  printf("=======================\n");
  
  char *p6 = ff_malloc(3*sizeof(char));
  printf("char *p6 = ff_malloc(3*sizeof(char));\n");
  print_mem_list();
  printf("p6 point at %p\n",p6);
  printf("=======================\n");
  
  return EXIT_SUCCESS;
}


