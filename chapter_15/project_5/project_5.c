#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "stack.h"

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

