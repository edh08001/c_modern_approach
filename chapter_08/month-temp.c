#include <stdlib.h>

#define DAYS_PER_MONTH 30
#define HOURS_PER_DAY 24

int main(int argc, char *argv[])
{

  int total, count = DAYS_PER_MONTH * HOURS_PER_DAY;
  int temperature_readings[DAYS_PER_MONTH][HOURS_PER_DAY];
  float average;

  for (int i = 0; i < DAYS_PER_MONTH; i++){
    for (int j = 0; j < HOURS_PER_DAY; j++) {
      total += temperature_readings[i][j];
    }
  }

  average = (float) total / count;

  return EXIT_SUCCESS;
}
