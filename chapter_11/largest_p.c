#include <stdio.h>
#include <stdlib.h>

#define N 10

/************************************************************
 * Finds the maximum and minimum value of array b. Requires *
 * the length (n) to be provided.                           *
 ************************************************************/
int *find_largest(int a[], int n);

int main(int argc, char *argv[])
{
  int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int *b = find_largest(a, N);

  printf("Largest: %d\n", *b);

  return EXIT_SUCCESS;
}

int *find_largest(int a[], int n){
  int *max = &a[0];
  for (int i = 0; i < N; i++){
    if (a[i] > *max)
      max = &a[i];
  }

  return max;
  
}
