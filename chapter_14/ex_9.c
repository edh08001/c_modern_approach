#include <stdio.h>
#include <math.h>

#define CHECK(x,y,n) ((x) >= 0 && (x) <= ((n)-1)) && ((y) >= 0 && (y) <= ((n)-1)) ? 1 : 0 
#define MEDIAN(x,y,z) ((x) > (y) && (x) < (z)) || ((x) < (y) && (x) > (z)) ? x : ((y) > (x) && (y) > (z)) || ((y) < (x) && (y) > (z)) ? y : z
#define POLYNOMIAL(x) (3 * pow((x),5)) + (2 * pow((x),4)) - (5 * pow((x),3)) - pow((x), 2) + (7 * (x)) - 6
int main(void)
{
  printf("%d\n", CHECK(5,6,10));
  printf("%d\n", MEDIAN(4,6,3));
  printf("%.1f\n", POLYNOMIAL(5));

  return 1;
  
}
