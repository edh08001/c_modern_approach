#include <stdio.h>


#define GENERIC_MAX(type)     \
type type##_max(type x, type y)     \
{                                   \
  return x > y ? x : y;             \
}

typedef unsigned long ULONG;

GENERIC_MAX(ULONG)

int main(void)
{
  printf("%lu\n", ULONG_max(1, 2));
}


