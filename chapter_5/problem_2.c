#include <stdio.h>

int main(int argc, char *argv[])
{
  int hr, min, count;
  printf("Enter a 24h time in hh:mm format: ");
  scanf("%d:%d", &hr, &min);
  
  if(hr > 12) hr -= 12;

  printf("12 hr time is: %.2d:%.2d\n", hr, min);
  
  return 0;
}
