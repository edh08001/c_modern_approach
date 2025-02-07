/* Print the earliest date among entries by user */
#include <stdio.h>

int main(int argc, char *argv[])
{
  int m1, y1, d1, min_month = 12, min_year = 9999, min_day = 31;

  for( ; ; )
  {
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &m1, &d1, &y1);

    if (y1 == 0 && m1 == 0 && d1 == 0) break;

    if (y1 == min_year)
    {
      if (m1 == min_month)
      {
        if (d1 < min_day)
        {
          min_day = d1;
          min_year = y1;
          min_month = m1;
        }
      }
      else if (m1 < min_month)
      {
        min_day = d1;
        min_year = y1;
        min_month = m1;
      }
    } 
    else if (y1 < min_year)
    {
      min_day = d1;
      min_year = y1;
      min_month = m1;
    }
  }

  printf("%d/%d/%d is the earliest date\n", min_month, min_day, min_year);

  return 0;
}

