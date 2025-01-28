#include <stdio.h>
#include <stdlib.h>

#define N 10

/*******************************************
 * Fills and prints an identity matrix     *
 *******************************************/
void fill_ident(int a[N][N], int n);

int main(int argc, char *argv[]) {
  int a[N][N];

  fill_ident(a, N);

  return EXIT_SUCCESS;
}

void fill_ident(int a[N][N], int n) {
  int *p = &a[0][0], count_zeros = 1, index = -1;

  do {
    if (--count_zeros == 0) {
      *p = 1;
      count_zeros = N + 1;
    } else {
      *p = 0;
    }
    if (++index % N == N - 1)
      printf("%d\n", *p);
    else
      printf("%d", *p);
  } while (++p < &a[0][0] + N * N);
}
