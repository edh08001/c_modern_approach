#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

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
  int first, second;
  printf("Enter an RPN Expression: ");
  for (;;){
    scanf(" %c", &in);
      if (in == 'q') break;

      if(isdigit(in)) {
        push(in - '0');
      } else {
        switch(in) {
          case '*': {
            second = pop();
            first = pop();
            push(first * second);
          }
          break;
          case '/': {
            second = pop();
            first = pop();
            push(first / second);
          }
          break;
          case '+': {
            second = pop();
            first = pop();
            push(first + second);
          }
          break;
          case '-': {
            second = pop();
            first = pop();
            push(first - second);
          }
          break;
          case '=': {
            printf("Value of expression: %d\n", pop());
            make_empty();
            printf("Enter an RPN Expression: ");
          }
          break;
        }
      }
   } 
  return EXIT_SUCCESS;
}
