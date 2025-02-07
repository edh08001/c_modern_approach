#include <stdio.h>
#include <stdlib.h>

#define FIB_SIZE 40

int main(int argc, char *argv[])
{
  long fib_numbers[FIB_SIZE] = {0, 1};

  printf("0 1 ");
  for (int i = 2; i < FIB_SIZE; i++){
    fib_numbers[i] = fib_numbers[i - 2] + fib_numbers[i-1];
    printf("%ld ", fib_numbers[i]);
    if (!(i % 5)) printf("\n");
  }

  printf("\n");
  return EXIT_SUCCESS;
}
