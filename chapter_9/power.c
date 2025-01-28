#include <stdio.h>
#include <stdlib.h>

#define N 5
#define P 8 

long power(long x, int n);

int main(int argc, char *argv[])
{

  printf("The %d power of %d is %ld\n", P, N, power(N, P));

  return EXIT_SUCCESS;
}

long power(long x, int n){
  long i;
  if (n == 0)
    return 1;
  else if (n % 2 == 0) { 
    i = power(x, n / 2);
    return i * i;
  }
  else 
    return x * power(x, n - 1);
}
