#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define STACK_SIZE 100

/*****************************************************************
* Reads a user inputted string and converts it to an array of    *
* chars. Ignores any chars in strings longer than WORD_SIZE and  *
* appends the nul character at the end of the string             *
******************************************************************/
int read_string(char input[], int n);

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

int evaluate_RPN_expression(const char *expression);

int main(int argc, char *argv[])
{
  char in;
  char expression[21];
  int first, second;
  for (;;){
    printf("Enter an RPN Expression: ");
    read_string(expression, 20);
    if (expression[0] == 'q' || expression[0] == 'Q')
      break;
    printf("The answer is: %d\n", evaluate_RPN_expression(expression));
  }
  return EXIT_SUCCESS;
}

int read_string(char input[], int n)
{
  int in, i = 0, day;
  while((in = getchar()) != '\n'){
    if (i < n && in != ' ') {
      input[i++] = in;
    }
  }
  input[i] = '\0';
  return i;
}

int evaluate_RPN_expression(const char *expression)
{
 int first, second, answer = 0;
  do {
    if(isdigit(*expression)) {
        push(*expression - '0');
      } else {
        switch(*expression) {
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
            answer = pop();
            make_empty();
          }
          break;
        }
      }
    } while(*++expression);
  return answer;
}
