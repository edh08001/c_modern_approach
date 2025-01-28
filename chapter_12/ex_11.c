#include <stdio.h>
#include <stdlib.h>

#define N 10

/*******************************************
 * Find the largest number in an array     *
 *******************************************/ 
void find_largest(int a[], int n, int *largest);

int main(int argc, char *argv[])
{
  int largest = 0;
  int a[N] = {5, 4, 3, 2, 1, 10, 6, 7, 8, 9};
  find_largest(a, N, &largest);

  printf("Largest is: %d\n", largest);


  return EXIT_SUCCESS;
}

void find_largest(int a[], int n, int *largest)
{
  int i = 0;

  while (i++ < n){
    if (*a++ > *largest) *largest = *(a-1);
  }
}
