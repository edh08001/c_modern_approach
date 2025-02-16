#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackADT.h"

int main(int argc, char *argv[])
{
  initscr();
  addstr("---------------------\n | codedrome.com |\n| ncurses Demo |\n-----------------\n\n");
  refresh();
  char in;
  Stack s = create_stack();
  bool break_while = false;
  printf("Enter patentheses and/or braces: ");
  while((in = getchar()) != '\n' && !break_while){
    switch(in){
      case '(': push(s, '(');
      break;
      case '{': push(s, '{');
      break;
      case ')': {
        if (pop(s) != '('){
          printf("Parentheses are not nested correctly\n");
          break_while = true;
        }
      break;
      case '}': {
        if (pop(s) != '{'){
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
