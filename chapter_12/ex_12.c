#include <stdio.h>
#include <stdlib.h>

#define N 10

/*******************************************
 * Find the largest two numbers in an array*
 *******************************************/ 
void find_two_largest(const int *a, int n, int *largest, int* second_largest);

void find_largest(int a[], int n, int *largest);
int main(int argc, char *argv[])
{
  int a[N] = {12, 1, 2, 3, 9, 4, 10, 6, 7, 8};
  int largest, second_largest;

  find_two_largest(a, N, &largest, &second_largest);
  printf("The largest is: %d\n", largest);
  printf("The second largest is: %d\n", second_largest);
  
  return EXIT_SUCCESS;
}

void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
  const int *i = a;
  *largest = *second_largest = *a;
  while (i++ < a + n - 1){
    if(*i > *largest){
      *second_largest = *largest;
      *largest = *i;
    }
  }
  if (*second_largest == *largest){
    i = a;
    *second_largest = 0;
    
    while (i++ < a + n - 1){
      if(*i > *second_largest && *i != *largest){
        *second_largest = *i;
      }
    }
  }
}
