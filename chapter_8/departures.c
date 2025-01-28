#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  int hr, min, to_midnight;
  int closest = 9999, best_flight = 0;
  int f1, f2, f3, f4, f5, f6, f7, f8;

  int departures[8] = {8 * 60, 
    9 * 60 + 43, 
    11 * 60 + 19, 
    12 * 60 + 19,
    14 * 60,
    15 * 60 + 45,
    19 * 60,
    21 * 60 + 45
  };

  int arrivals[8] = {10 * 60 + 16,
    11 * 60 + 52,
    13 * 60 + 31,
    15 * 60,
    16 * 60 + 8,
    17 * 60 + 55,
    21 * 60 + 20,
    23 * 60 + 58
  };
                       

  printf("Enter a time in 24h format: ");
  scanf("%d:%d", &hr, &min);

  to_midnight = hr * 60 + min;
  
  for (int i = 0; i < 8; i++){
    if (abs(departures[i] - to_midnight) <= closest)
    {
      closest = abs(departures[i] - to_midnight);
      best_flight = i;
    }
  }

 printf("Closest departure time is %d:%d, arriving at %d:%d\n", departures[best_flight] / 60, departures[best_flight] % 60,
                                                                arrivals[best_flight] / 60, arrivals[best_flight] % 60);


  return 0;
}

