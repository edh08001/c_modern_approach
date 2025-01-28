#include <stdio.h>
/* Sums a series of numbers */
int main(int argc, char *argv[])
{
  int j = 10;
  //for (int i = 10; i >= 1; i /= 2)
    //printf("%d", i++);

 // while(j >= 1)
 //   {
 //     printf("%d", j++);
 //     j/=2;
 //   }
  
  int n, d;
  printf("Enter n: ");
  scanf("%d", &n);
  
  for (d = 2; d * d <= n; d++)
    if (n % d == 0)
      break;

  if (d * d <= n)
    printf("%d is divisible by %d\n", n, d);
  else
    printf("%d is prime\n", n);

  
  return 0;
}
