#include <stdio.h>
#include <stdlib.h>

#define N 10

/*******************************************
 * Find the middle point of an array       *
 *******************************************/ 
int *find_middle(int a[], int n);

int main(int argc, char *argv[])
{
  int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int *p = find_middle(a, N);

  printf("The middle number is: %d\n", *p);
  return EXIT_SUCCESS;
}

int *find_middle(int a[], int n)
{
  return a + ((a + n) - a) / 2;
}
