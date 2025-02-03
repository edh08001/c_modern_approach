/* This program accepts a list of N numbers and uses quicksort to display them in order */
#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

#define N 10

int main(int argc, char *argv[])
{
  int a[N], i;

  printf("Enter %d numbers to be sorted: ", N);
  for(i = 0; i < N; i++)
    scanf("%d", &a[i]);


  quicksort(a, 0, N-1);

  printf("In sorted order: ");
  for(i = 0; i < N; i++)
    printf("%d ", a[i]);

  printf("\n");

  return EXIT_SUCCESS;
}

