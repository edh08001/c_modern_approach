/* This program allows you to add, subtract, multiply, or divide fractions */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n1, d1, n2, d2, rn, rd;
  char operator;

  printf("Enter two fractions and an arithmetic operator (1/2+3/4): ");
  scanf("%d/%d%c%d/%d", &n1, &d1, &operator, &n2, &d2);

  switch(operator){
    case '+': {
      rd = d1 * d2;
      rn = (n1 * d2) + (n2 * d1);
    } break;
    case '-': {
      rd = d1 * d2;
      rn = (n1 * d2) - (n2 * d1);
    } break;
    case '*': {
      rd = d1 * d2;
      rn = n1 * n2; 
    } break;
    case '/': {
      rd = n2 * d1;
      rn = n1 * d2; 
    } break;
  }

  printf("The answer is: %d/%d\n", rn, rd);
  return EXIT_SUCCESS;
}
