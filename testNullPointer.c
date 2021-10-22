#include <stdlib.h>
#include <stdio.h>

int main(){
  int *p = malloc(10*sizeof(int));
  p[0]=1;
  printf("p[0]=%d",p[0]);
  free(p);
  printf("p[0]=%d",p[0]);
  return EXIT_SUCCESS;
}
