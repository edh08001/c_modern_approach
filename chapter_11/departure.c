#include <stdio.h>

/************************************************************
 * Finds the closest flight based on a desired time. Desired*
 * time is represented in hours since midnight              *
 ************************************************************/
void find_closest_flight(int desired_time, int *departure_time,
                         int *arrival_time);

int main(int argc, char *argv[])
{
  int hr, min, desired_time, departure_time, arrival_time;

  printf("Enter a time in 24h format: ");
  scanf("%d:%d", &hr, &min);

  desired_time = hr * 60 + min;
  find_closest_flight(desired_time, &departure_time, &arrival_time);

  printf("Departure time = %.2d:%.2d\nArrival time = %.2d:%.2d\n",
         departure_time/60, departure_time%60,
         arrival_time/60, arrival_time%60);

  return 0;
}

void find_closest_flight(int desired_time, int *departure_time,
                         int *arrival_time)
{
  int f1, f2, f3, f4, f5, f6, f7, f8;

  f1 = 8 * 60;
  f2 = 9 * 60 + 43;
  f3 = 11 * 60 + 19;
  f4 = 12 * 60 + 19;
  f5 = 14 * 60;
  f6 = 15 * 60 + 45;
  f7 = 19 * 60;
  f8 = 21 * 60 + 45;
  
  if(desired_time <= f1) 
  {
    *departure_time = f1;
    *arrival_time = 10 * 60 + 16;
  }
  else if(desired_time <= f2) 
  {
    *departure_time = f2;
    *arrival_time = 11 * 60 + 52;
  }
  else if(desired_time <= f3) 
  {
    *departure_time = f3;
    *arrival_time = 13 * 60 + 31;
  }
  else if(desired_time <= f4) 
  {
    *departure_time = f4;
    *arrival_time = 15 * 60;
  }
  else if(desired_time <= f5) 
  {
    *departure_time = f5;
    *arrival_time = 16 * 60 + 8;
  }
  else if(desired_time <= f6) 
  {
    *departure_time = f6;
    *arrival_time = 17 * 60 + 55;
  }
  else if(desired_time <= f7) 
  {
    *departure_time = f7;
    *arrival_time = 21 * 60 + 20;
  }
  else 
  {
    *departure_time = f8;
    *arrival_time = 23 * 60 + 58;
  }

}
