#include <stdio.h>

#define NELEMS(a) (sizeof(a) / sizeof(a[0]))

int main(void)
{
  char a[10];
  printf("%d\n", (int) NELEMS(a));

  return 1;
}
