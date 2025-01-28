#include <stdio.h>
/* Displays the number of digits */
int main(int argc, char *argv[])
{

  int n, count = 0;
  printf("Enter a number: ");
  scanf("%d", &n);
  do 
  {
    count++;
    n /= 10;
  } while (n != 0);

  printf("The number has %d digits\n", count);

  return 0;
}
