#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int* top = &contents[0];


void make_empty(void){
  top = &contents[0];
}

bool is_empty(void){
  return top == &contents[0];
}

bool is_full(void){
  return top == &contents[STACK_SIZE];
}

void push(int i){
  if (is_full())
    printf("Stack Overflow!");
  else
    *top++ = i;
}

int pop(void){
  if (is_empty()){
    printf("Stack Underflow!");
    return 0;
  } 
  else
    return *--top;
}

int main(int argc, char *argv[])
{

  return EXIT_SUCCESS;
}
