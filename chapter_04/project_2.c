#include <stdio.h>

int main(void)
{
  int input;
  int remainder;
  printf("Enter a 3 digit number: ");
  scanf("%d", &input);
  remainder = input % 100;
  printf("The reversal of that number is: %d\n", ((remainder % 10) * 100 + ((remainder / 10) * 10) + (input / 100)));
}
