#include <stdio.h>
int main(int argc, char *argv[])
{
  int hr, min, to_midnight;
  int f1, f2, f3, f4, f5, f6, f7, f8;

  f1 = 8 * 60;
  f2 = 9 * 60 + 43;
  f3 = 11 * 60 + 19;
  f4 = 12 * 60 + 19;
  f5 = 14 * 60;
  f6 = 15 * 60 + 45;
  f7 = 19 * 60;
  f8 = 21 * 60 + 45;

  printf("Enter a time in 24h format: ");
  scanf("%d:%d", &hr, &min);

  to_midnight = hr * 60 + min;
  
  if(to_midnight <= f1) 
  {
    printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
  }
  else if(to_midnight <= f2) 
  {
    printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
  }
  else if(to_midnight <= f3) 
  {
    printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
  }
  else if(to_midnight <= f4) 
  {
    printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
  }
  else if(to_midnight <= f5) 
  {
    printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
  }
  else if(to_midnight <= f6) 
  {
    printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
  }
  else if(to_midnight <= f7) 
  {
    printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
  }
  else 
  {
    printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
  }
  



  return 0;
}
