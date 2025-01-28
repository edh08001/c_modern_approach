#include <stdio.h>
#include <stdlib.h>

#define N 10

/************************************************************
 * Finds the maximum and minimum value of array b. Requires *
 * the length (n) to be provided.                           *
 ************************************************************/
void max_min(int b[], int n, int *max, int *min);

/***************External Variables**************************
 ***********************************************************/


int main(int argc, char *argv[])
{
  int b[N], min, max;
  printf("Enter %d numbers: ", N);
  for (int i = 0; i < N; i++)
    scanf("%d", &b[i]);

  max_min(b, N, &max, &min);

  printf("The minimum is %d and the maximum is %d'\n'", min, max);
  return EXIT_SUCCESS;
}

void max_min(int b[], int n, int *max, int *min){

  *max = *min = b[0];
  for (int i = 0; i < n; i++){
    if (b[i] > *max)
      *max = b[i];
    else if (b[i] < *min)
      *min = b[i];
  }
}
