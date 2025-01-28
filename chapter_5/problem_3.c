#include <stdio.h>
int main(int argc, char *argv[])
{
  int count_shares;
  float price_shares, total_price, us_commission, them_commission;
  printf("Enter share count and price delineated by a space: ");
  scanf("%d $%f", &count_shares, &price_shares);
  
  total_price = count_shares * price_shares;

  if (total_price < 2500.00f) them_commission = 30.00f + total_price * 0.017f;
  else if (total_price <= 6250.00f) them_commission = 56.00f + total_price * 0.0066f;
  else if (total_price <= 20000.00f) them_commission = 76.00f + total_price * 0.0034f;
  else if (total_price <= 50000.00f) them_commission = 100.00f + total_price * 0.0022f;
  else if (total_price <= 500000.00f) them_commission = 155.00f  + total_price * 0.0011f;
  else them_commission = 255.00f + total_price * 0.0009f;

  if (count_shares < 2000) us_commission = 33 + 0.03f * count_shares;
  else us_commission = 33 + 0.02f * count_shares;

  printf("Our Commission: %.2f\nTheir Commission: %.2f\n", us_commission, them_commission);

  return 0;
}
