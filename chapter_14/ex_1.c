#include <stdio.h>
#include <stdlib.h>

#define CUBE(x) ((x)*(x)*(x))
#define FOURR(n) (n) % 4
#define HUNDRED(x, y) (x) * (y) < 100 ? 1 : 0

int main(int argc, char *argv[])
{

  printf("%d\n%d\n%d\n", CUBE(2), FOURR(5), HUNDRED(10, 5));

  return EXIT_SUCCESS;
}
