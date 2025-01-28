#include <stdio.h>

int main(void)
{
  int d;
  printf("Enter a 2 digit number: ");
  scanf("%d", &d);
  printf("The reversal of that number is: %d\n", ((d % 10) * 10 + d / 10));
}
