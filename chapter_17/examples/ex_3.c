#include <stdlib.h>
#include <stdio.h>

void * my_malloc(int n);

int *create_array(int n, int initial_value);

int main(void)
{
  int *a = create_array(12, 1);

  for (int i = 0; i < 12; i++)
    printf("%d", a[i]);

  printf("\n");
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

int *create_array(int n, int initial_value)
{
  int i, *a = my_malloc(n * sizeof(int));

  for(i = 0; i < n; i++){
    a[i] = initial_value;
  }
  return a;
}
