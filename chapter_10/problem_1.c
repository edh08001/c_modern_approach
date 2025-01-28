#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;


void make_empty(void){
  top = 0;
}

bool is_empty(void){
  return top == 0;
}

bool is_full(void){
  return top == STACK_SIZE;
}

void push(int i){
  if (is_full())
    printf("Stack Overflow!");
  else
    contents[top++] = i;
}

int pop(void){
  if (is_empty()){
    printf("Stack Underflow!");
    return 0;
  } 
  else
    return contents[--top];
}


int main(int argc, char *argv[])
{
  char in;
  bool break_while = false;
  printf("Enter patentheses and/or braces: ");
  while((in = getchar()) != '\n' && !break_while){
    switch(in){
      case '(': push('(');
      break;
      case '{': push('{');
      break;
      case ')': {
        if (pop() != '('){
          printf("Parentheses are not nested correctly\n");
          break_while = true;
        }
      break;
      case '}': {
        if (pop() != '{'){
            printf("Braces are not nested correctly\n");
            break_while = true;
          }
        }
      }
      break;
    }
  }
  if (!break_while) printf("Braces and parentheses are nested correctly\n");

  return EXIT_SUCCESS;
}
