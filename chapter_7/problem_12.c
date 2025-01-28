/* This program takes a First Last name and outputs Last, First Initial */

#include <stdio.h>

int main(int argc, char *argv[])
{
  char o1, o2;
  float f1, f2, f3, v1, ans;

  printf("Enter an expression: ");
  
  scanf("%f%c%f%c%f", &f1, &o1, &f2, &o2, &f3);

  switch(o1){
    case '+': {
      v1 = f1 + f2;
    } break;
    case '-': {
      v1 = f1 - f2;
    } break;
    case '*': {
      v1 = f1 * f2;
    } break;
    case '/': {
      v1 = f1 / f2;
    } break;
  }

  switch(o2){
    case '+': {
      ans = v1 + f3;
    } break;
    case '-': {
      ans = v1 - f3;
    } break;
    case '*': {
      ans = v1 * f3;
    } break;
    case '/': {
      ans = v1 / f3;
    } break;
  }

  printf("Value of expression: %.2f\n", ans);

  return 0;
}

