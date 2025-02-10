#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct contents {
  int n;
  struct contents *next;
};

struct contents *top = NULL;

void make_empty(void)
{ 
  struct contents *prev;
  while (top != NULL) {
    prev = top;
    top = top->next;
    free(prev);
  } 
}

bool is_empty(void){
  return top == NULL;
}

void push(int i){
  struct contents *push;
  push = malloc(sizeof(struct contents));
  if (push == NULL){
    printf("Not enough space for push\n");
  } else {
    push->n = i;
    push->next = top;
    top = push;
  }
}

int pop(void){
  if (top == NULL){
    printf("Nothing on Stack!");
    return 0;
  } else { 
    struct contents *prev = top;
    int num = top->n;
    top = top->next;
    free(prev);

    return num;
  }
    
}
