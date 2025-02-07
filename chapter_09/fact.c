#include <stdio.h>
#include <stdlib.h>

int fact(int n);

int main(int argc, char *argv[])
{
  
  printf("3 factoral is: %d\n", fact(3));
  return EXIT_SUCCESS;
}

int fact(int n){
  int i, result = 1;
  for (i = 2; i <= n; i++) {
    result *= i;
  }
  return result;

  //return n <= 1 ? 1 : (n * fact(n-1));


}
