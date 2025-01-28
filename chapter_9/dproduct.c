#include <stdio.h>
#include <stdlib.h>

#define N 10

double inner_product(double a[], double b[], int n);

int main(int argc, char *argv[])
{
  double a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  double b[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  printf("The product of arrays a and b is: %lg\n", inner_product(a, b, N));

  return EXIT_SUCCESS;
}

double inner_product(double a[], double b[], int n){

  int i;
  double product = 0;

  for (i = 0; i < n; i++){
    product += a[i] * b[i];
  }

  return product; 

}

