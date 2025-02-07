/* Print all Even Squares of a number */
#include <stdio.h>

int main(int argc, char *argv[])
{
  int d, next;
  printf("Enter a number to print all even squares: ");
  scanf("%d", &d);
 
  for(int i = 2; i * i <= d; i += 2)
  {
    printf("%d\n", i * i);
  }

  return 0;
}

