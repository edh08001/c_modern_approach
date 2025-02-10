#include <stdlib.h>
#include <stdio.h>

void * my_malloc(int n);

int main(void)
{
  char *x = my_malloc(12);
  int *y = my_malloc(12);
}

void * my_malloc(int n)
{
  void * p = malloc(n);
  if (p == NULL) {
    printf("Insufficient memory for my_malloc");
    exit(EXIT_FAILURE);
  }

  return p;
}
