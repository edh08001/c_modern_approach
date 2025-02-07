#include <stdio.h>

typedef struct {
  int day, month, year;
} Date;

int compare_dates(Date d1, Date d2)
{
  if (d1.year == d2.year){
    if (d1.month == d2.month){
      if (d1.day == d2.day){
        return 0;
      } else {
        return d1.day > d2.day ? 1 : -1;
      }
    } else {
      return d1.month > d2.month ? 1 : -1;
    }
  } else {
    return d1.year > d2.year ? 1 : -1;
  }
}

int main(int argc, char *argv[])
{

  Date d1, d2;

  printf("Enter first date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);
  printf("Enter second date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

  switch(compare_dates(d1, d2)){
    case 0: printf("Dates are the same!\n");
      break;
    case 1: printf("Second date is earlier than first!\n");
      break;
    case -1: printf("First date is earlier than second!\n");
      break; 
  }
  return 0;
}
