#include <stdio.h>

int main(void) {
  int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, sum1, result;
  
  printf("Enter the first 11 digits of a UPC: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11);
  sum1 = i2 + i4 + i6 + i8 + i10;
  result = 9 - ((((i1 + i3 + i5 + i7 + i9 + i11) * 3 + sum1) - 1) % 10);
  printf("The check digit of your UPC is: %d\n", result);
}
