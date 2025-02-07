#include <stdio.h>

int main(void)
{
  int area, mid, end;
  printf("Enter phone number [(xxx) xxx-xxxx]: ");
  scanf("(%d) %d-%d", &area, &mid, &end);
  printf("You entered: %.3d.%.3d.%.4d\n", area, mid, end);
  
  return 0;
}
