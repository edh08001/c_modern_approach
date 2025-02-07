#include <stdio.h>

int main(void)
{
  int month, day, year;
  printf("Enter a date (mm/dd/yyyy):");
  scanf("%d/%d/%d", &month, &day, &year);
  printf("You entered the date %d%d%d\n", month, day, year);
  return 0; 
}
