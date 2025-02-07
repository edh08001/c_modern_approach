/* Print all Even Squares of a number */
#include <stdio.h>

int main(int argc, char *argv[])
{

  int days, start;

  printf("Enter number of days in month: ");
  scanf("%d", &days);
  printf("Enter starting day in week (1 = Sun, 7 = Sat): ");
  scanf("%d", &start);

  for (int i = 1; i < days + start; i++)
  {
    if(i < start) printf("   ");
    else printf("%3d", i - start + 1);
    
    if(!(i % 7)) printf("\n");
  }

  printf("\n");
  return 0;
}

