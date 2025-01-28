#include <stdio.h>
#include <stdlib.h>

#define N 10

/*****************************************
* Changes all array elements to 0        *
*****************************************/
void store_zeros(int *a, int n);

int main(int argc, char *argv[])
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  store_zeros(a, N);

  for(int i = 0; i < N; i++){
    printf("%d", *(a + i));
  }

  printf("\n");

  return EXIT_SUCCESS;
}

void store_zeros(int *a, int n)
{
  int *p;

  for (p = a; p < a + N; p++){
    *p = 0;
  }
}
