/* This program prints the size of various types */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  printf("Size of Int: %zu\n", sizeof(int));
  printf("Size of Short: %zu\n", sizeof(short));
  printf("Size of Long: %zu\n", sizeof(long));
  printf("Size of Float: %zu\n", sizeof(float));
  printf("Size of Double: %zu\n", sizeof(double));
  printf("Size of Long Double: %zu\n", sizeof(long double));
  return EXIT_SUCCESS;
}
