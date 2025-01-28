#include <stdio.h>
#include <stdlib.h>

double median(double x, double y, double z);

int main(int argc, char *argv[])
{

  printf("The median of 1, 3, 2 is %lf\n", median(1, 3, 2));
  return EXIT_SUCCESS;
}

double median(double x, double y, double z){
  double median = 0;
  if (x <= y){
    if (y <= z) {
      median = y;
    } else if (x <= z) {
      median = z;
    } else median = x;
  } else if (z <= y) {
    median = y;
  } else if (x <= z) {
    median = x;
  }

 return median; 
}
