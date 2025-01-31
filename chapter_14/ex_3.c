#include <stdio.h>

#define DOUBLE(x) (2*(x))

int main(void)
{

  printf("%d\n%d\n", DOUBLE(1+2), 4/DOUBLE(2));
}
