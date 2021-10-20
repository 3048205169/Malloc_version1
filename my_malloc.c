#include "my_malloc.h"
#include <unistd.h>
Node *head = NULL;
void * ff_malloc(size_t size){
  if(head==NULL){
    head = sbrk(sizeof(Node));
    head->size = size;
    head->is_free = 0;
    head->next = head;
    head = sbrk(size);
    return head+1;
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
      return cur+1;
    }else{//末尾元素且非空闲空间
      Node* n1=sbrk(size);
      n1->next = head;
      cur->next = n1;
      n1->size =2;
      n1->is_free = 0;
      return n1+1;
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
  Node *header = ptr-1;
  header->is_free=1;
  ff_coal(header);
  ptr = NULL;
}

void ff_coal(Node *header){//合并size>=2的free的共同空间
  Node *start;
  Node *end;
  int count;
  int sumsize;
  for(start =header;start!=head;start=start->next){
    if(start->is_free==0){
      continue;
    }
    count=0;
    sumsize =0;
    for(end = start->next;end->is_free!=0;end = end->next){
      count = count+1;
      sumsize = sumsize+end->size;
      sumsize = sumsize+sizeof(Node);
    }
    break;
  }

  if(count>=1){
    start->next = end->next;
    start->size = start->size+sumsize;
  }
  
}


void * bf_malloc(size_t size){

}
void bf_free(void *ptr){

}
