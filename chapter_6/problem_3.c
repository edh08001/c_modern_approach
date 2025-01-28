#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int m, n, original_m, original_n, remainder;

  printf("Enter a Fraction: ");
  scanf("%d/%d", &m, &n);
  original_m = m;
  original_n = n;

  while (n != 0) 
  {
    remainder = m % n;
    m = n;
    n = remainder;
  }

  printf("In lowest terms: %d/%d\n", original_m / m, original_n / m);

  return EXIT_SUCCESS;
}
