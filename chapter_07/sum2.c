#include <stdbool.h>
#include <stdio.h>

/* Sums a series of numbers (using long variables) */

int main(int argc, char *argv[]) {
  double n, sum = 0;

  printf("This program sums a series of integers.\n");

  printf("Enter integers (0 to terminate): ");
  scanf("%lf", &n);
  while (n != 0) {
    sum += n;
    scanf("%lf", &n);
  }
  printf("The sum is: %lf\n", sum);

  return 0;
}
