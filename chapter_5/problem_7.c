#include <stdio.h>
int main(int argc, char *argv[])
{
  int n1, n2, n3, n4, max1, min1, max2, min2, max, min;
  printf("Enter 4 digits separated by a space: ");
  scanf("%d%d%d%d", &n1, &n2, &n3, &n4);

  if (n1 > n2) 
  {
    max1 = n1;
    min1 = n2;
  }
  else 
  {
    max1 = n2;
    min1 = n1;
  }

  if (n3 > n4)
  {
    max2 = n3;
    min2 = n4;
  }
  else
  {
    max2 = n4;
    min2 = n3;
  }

  if (max2 > max1)
  {
    max = max2;
  }
  else
  {
    max = max1;
  }

  if (min2 > min1)
  {
    min = min1;
  }
  else
  {
    min = min2;
  }

  printf("The max is: %d\nThe min is: %d\n", max, min);

  return 0;
}
