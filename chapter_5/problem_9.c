#include <stdio.h>
int main(int argc, char *argv[])
{

  int m1, y1, d1, m2, y2, d2;

  printf("Enter first date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &m1, &y1, &d1);
  printf("Enter second date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &m2, &y2, &d2);

  if (y1 == y2)
  {
    if (m1 == m2)
    {
      if (d1 == d2)
      {
        printf("The dates are the same\n");
      }
      else if (d1 < d2)
      {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, y1, d1, m2, y2, d2);
      }
    }
    else if (m1 < m2)
    {
      printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, y1, d1, m2, y2, d2);
    }
    else
    {
      printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, y2, d2, m1, y1, d1);
    }
  } 
  else if (y1 < y2)
  {
    printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, y1, d1, m2, y2, d2);
  }
  else
  {
    printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, y2, d2, m1, y1, d1);
  }

  return 0;
}
