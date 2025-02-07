#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int m, n, remainder;

  printf("Enter two Integers: ");
  scanf("%d %d", &m, &n);

  while (n != 0) 
  {
    remainder = m % n;
    m = n;
    n = remainder;
  }

  printf("Greatest common divisor: %d\n", m);

  return EXIT_SUCCESS;
}
