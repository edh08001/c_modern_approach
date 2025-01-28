#include <stdio.h>
#include <stdlib.h>

#define N 10

/**************************************************
 * Swaps two variables using pointers             *
 **************************************************/
void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(int argc, char *argv[])
{
  int a[] = {10, 12, 24, 87, 91, 15, 36, 76, 54, 45};
  int largest, second_largest;

  find_two_largest(a, N, &largest, &second_largest);

  printf("The largest is: %d\nThe second largest is: %d\n", largest, second_largest);

  return EXIT_SUCCESS;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest){
  *largest = *second_largest = a[0];
  for(int i = 0; i < N; i++){
    if (a[i] > *largest)
      *largest = a[i];
  }
  for(int i = 0; i < N; i++){
    if (a[i] != *largest && abs(a[i] - *largest) < a[i] - *second_largest){
      *second_largest = a[i];
    }
  }
}
