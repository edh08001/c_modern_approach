/* Computes e utilizing a total of n iterations */
#include <stdio.h>

int main(int argc, char *argv[])
{

  int n;
  float e;

  printf("Enter a number of values to compute e: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
  {
    e += 1.0f/i;
  }

  printf("e is: %f\n", e);

  return 0;
}

