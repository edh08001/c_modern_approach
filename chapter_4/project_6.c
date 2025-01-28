#include <stdio.h>

int main(void) {
  int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, sum1, result;
  
  printf("Enter the first 12 digits of an EAN: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12);
  sum1 = i2 + i4 + i6 + i8 + i10 + i12;
  result = 9 - ((((i1 + i3 + i5 + i7 + i9 + i11) + (sum1 * 3)) - 1) % 10);
  printf("The check digit of your EAN is: %d\n", result);
}
