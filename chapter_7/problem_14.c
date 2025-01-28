#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int x;
  double old_y = 0;

  printf("Enter a positive number: ");
  scanf("%d", &x);

  for (double y = 1; ;y = (y + x/y)/2){

    if (fabs(old_y - y) < (y * 0.00001f)){
      old_y = y;
      break;
    }
    old_y = y;
  }

  printf("Square Root: %lf\n", old_y);

  return EXIT_SUCCESS;

}
