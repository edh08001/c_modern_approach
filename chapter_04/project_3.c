#include <stdio.h>

int main(void)
{
  int hundred, ten, one;
  int remainder;
  printf("Enter a 3 digit number: ");
  scanf("%1d%1d%1d", &hundred, &ten, &one);
  printf("The reversal of that number is: %d%d%d\n", one, ten, hundred);
}
