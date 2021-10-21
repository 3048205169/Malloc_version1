#include "my_malloc.c"

void print_mem_list(){
  Node* curr = head;
  printf("head address = %p,size = %zu,is_free=%u,next = %p\n",(void*)curr,curr->size,curr->is_free,(void*)curr->next);
}


int main(){
  int* p1 = ff_malloc(10*sizeof(int));//malloc p1
  for(int i=0;i<10;i++){
    p1[i]=i*i;
    printf("p1[%d]=%d  ",i,p1[i]);
  }
  printf("=================\n");
  print_mem_list();
  //=====================
  ff_free(p1);//free p1
  printf("adress of p1 =%p\n",p1);
  print_mem_list();

  char *p2 = ff_malloc(5*sizeof(char));//malloc p2

  for(int i=0;i<5;i++){
    p2[i]='a'+i;
    printf("p2[%d]=%c",i,p2[i]);
  }
  printf("=================\n");
  print_mem_list();
  return EXIT_SUCCESS;
}


