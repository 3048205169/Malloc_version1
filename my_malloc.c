#include "my_malloc.h"
#include <unistd.h>
Node *head = NULL;


void * bf_malloc(size_t size){
  return NULL;
}
void bf_free(void *ptr){

}



void * ff_malloc(size_t size){
  if(head==NULL){
    head = sbrk(sizeof(Node)+size);
    head->size = size;
    head->is_free = 0;
    head->next = head;
    return (void*)(head+1);
  }else{//head!=NULL
    Node *cur = head;
    while(cur->next!=head){//cur结束以后要么是末尾元素要么是空闲可用空间
      if(cur->is_free == 1&&cur->size>=size){
	break;
      }
      cur=cur->next;
    }
    if(cur->is_free == 1&&cur->size>=size){//空闲空间可被使用
      cur->size = size;
      cur->is_free = 0;
      return (void*)(cur+1);
    }else{//末尾元素且非空闲空间
      Node* n1=sbrk(size+sizeof(Node));
      n1->next = head;
      cur->next = n1;
      n1->size =size;
      n1->is_free = 0;
      return (void*)(n1+1);
    }
    
  }
  return NULL;
}

void ff_free(void *ptr){
  if(ptr==NULL){//无效指针
    //打印错误信息
    return;
  }
  //有效指针
  Node *header =(Node*)ptr-1;
  header->is_free=1;
  ff_coal();
}

void ff_coal(){//合并size>=2的free的共同空间
  Node *start;
  Node *end;
  int count=0;
  int sumsize=0;
  for(start =head;start->next!=head;){
    if(start->is_free == 0){
      start = start->next;
      continue;
    }
    if(start->next->is_free == 1){
      //合并start和start->next
      start->size = start->size+sizeof(Node)+start->next->size;
      start->next = start->next->next;
    }else{
      start = start->next;
    }
    
  }

  
}

