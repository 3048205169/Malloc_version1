#include "my_malloc.c"

void print_mem_list(){
  Node* curr = head;
  printf("head address = %p,size = %zu,is_free=%u,next = %p\n",(void*)curr,curr->size,curr->is_free,(void*)curr->next);
}


int main(){
  int* a = ff_malloc(10*sizeof(int));
  for(int i=0;i<10;i++){
    print_mem_list();
  }
  return EXIT_SUCCESS;
}


