#include <stdio.h>
#include <stdlib.h>

#define N 10

/*****************************************
* Sums the contents of an array          *
*****************************************/
int sum_array(const int *a, int n);

int main(int argc, char *argv[])
{
  int sum, a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  sum = sum_array(a, N);

  printf("The sum is %d\n", sum);
  return EXIT_SUCCESS;
}

int sum_array(const int *a, int n)
{
  int i = 0, sum = 0;

  //for (i = 0; i < N; i++){
  //  sum += *(a + i);
  //}

  //Or: 
  do {
    sum += *(a + i);
  } while (++i < N);

  // OR can be done like this, but I feel like this is not 
  // "Fewest changes possible" as mentioned. 
  //
  // int *p, sum = 0;
  // for(p = a; p < a + N; p++){
  //   sum += *p;
  // }

  return sum;
}
