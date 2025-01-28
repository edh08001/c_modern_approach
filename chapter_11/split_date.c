#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**************************************************
 * Takes in a day of year, and a year and outputs *
 * the month and the day. This does factor in both*
 * leap years as well as variable day months      *
 **************************************************/
void split_date(int day_of_year, int year, int *month, int *day);

int main(int argc, char *argv[])
{
  int month, day, year = 2004;

  split_date(45, year, &month, &day);

  printf("Month: %d Day: %d\n", month, day);
  return EXIT_SUCCESS;
}

void split_date(int day_of_year, int year, int *month, int *day){
 
  bool leap = false;
  if ((year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){
    leap = true;
  }

  
  int i = 0, day_count = 0, month_days[12] = {31, (leap ? 29 : 28), 31, 30, 31, 30,
                   31, 31, 30, 31, 30, 31};

  for (;;){
    if (day_count > day_of_year)
      break;
    day_count+=month_days[i];
    i++;
  }

  *month = i;

  *day = month_days[i-1] - (day_count - day_of_year);

}
