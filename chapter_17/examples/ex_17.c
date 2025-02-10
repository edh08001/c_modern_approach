#include <stdlib.h>

#define NUM_PARTS 50

int compar(const void *a, const void *b);

int main(void)
{
  int a[100];
  qsort(a, NUM_PARTS, sizeof(a[0]), compar);
}

int compar(const void *a, const void *b){
  const int *x = a;
  const int *y = b;
  return *x - *y;
}
