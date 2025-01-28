#include <stdio.h>
#include <stdlib.h>

#define N 10

/*****************************************
* Changes all array elements to 0        *
*****************************************/
double inner_product(const double *a, const double *b, int n);

int main(int argc, char *argv[])
{
  double a[] = {10, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  double b[] = {10, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int product = inner_product(a, b, N);

  printf("The inner product is: %d\n", product);

  return EXIT_SUCCESS;
}

double inner_product(const double *a, const double *b, int n)
{
  double product = 0;
  int i = 0;

  //Can be done below, but more complex
  //double *p, *q;
  //for (p = a, q = b; p < a + N; p++, q++){
  //  product += *p * *q;
  //}

  while(i++ < n)
    product += *a++ * *b++;

  return product;
}

