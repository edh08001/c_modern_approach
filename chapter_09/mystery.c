#include <stdio.h>
#include <stdlib.h>

void pb(int n);

int main(int argc, char *argv[])
{
  pb(12);
  printf("\n");

  return EXIT_SUCCESS;
}

void pb(int n){
  if (n != 0) {
    pb(n / 2);
    putchar('0' + n % 2);
  }
}
