#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int n){
  int divisor;

  if (n <= 1)
    return false;
  for (divisor = 2; divisor * divisor <= n; divisor++)
    if (n % divisor == 0)
      return false;
  return true;
}

int main(int argc, char *argv[])
{
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  if(is_prime(n))
    printf("Prime\n");
  else
    printf("Not Prime\n");

  return EXIT_SUCCESS;
}
