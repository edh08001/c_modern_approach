/* Sorts an array of n values using selection sort, recursively */

#include <stdio.h>
#include <stdlib.h>

#define N 10

void selection_sort(int a[], int n);

int main(int argc, char *argv[])
{

  int a[N];

  printf("Please enter %d integers: ", N);
  for (int i = 0; i < N; i++){
    scanf("%d", &a[i]);
  }

  selection_sort(a, N);

  for (int i = 0; i < N; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}

void selection_sort(int a[], int n){
  int i, temp, max_position, max = 0;
  if (n > 1) {
    for (i = 0; i < n; i++){
      if (a[i] > max) {
        max = a[i];
        max_position = i;
      }
    }
    
    temp = a[n-1];
    a[n-1] = max;
    a[max_position] = temp;

    selection_sort(a, n-1);
  }
}
