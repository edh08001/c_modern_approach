/* Computes e utilizing a user input term (value of 1/i) with which to end on */
#include <stdio.h>

int main(int argc, char *argv[])
{
  float n;
  float val;
  float e;

  printf("Enter a term value to end the computation for e: ");
  scanf("%f", &n);

  for (int i = 1; ; i++)
  {
    val = 1.0f/i;
    if (val < n) break;
    e += val;
  }

  printf("e is: %f\n", e);

  return 0;
}

