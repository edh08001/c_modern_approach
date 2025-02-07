#include <stdio.h>

int main(void)
{
  int month, day, year;
  int item_number;
  float purchase_price;

  printf("Enter item number: ");
  scanf("%d", &item_number);
  printf("Enter unit price: ");
  scanf("%f", &purchase_price);
  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &day, &year);
  printf("Item\t\tUnit Price\t\tPurchase Date\n");
  printf("%-d\t\t$%7.2f\t\t%-d/%-d/%-d\n", item_number, purchase_price, month, day, year);
  printf("You entered the date %d%d%d\n", month, day, year);
  return 0; 
}
