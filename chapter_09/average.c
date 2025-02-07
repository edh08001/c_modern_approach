#include <stdio.h>
#include <stdlib.h>

double average(double x, double y){
  return ((x + y) / 2);
}

int main(int argc, char *argv[])
{
  double a, b, c;
  printf("Enter three decimal noumbers: ");

  scanf("%lf%lf%lf", &a, &b, &c);

  printf("Average of number %g and %g is: %g\n", a, b, average(a, b));
  printf("Average of number %g and %g is: %g\n", b, c, average(b, c));
  printf("Average of number %g and %g is: %g\n", a, c, average(a, c));

  return EXIT_SUCCESS;
}
