#include <stdio.h>
#include <stdlib.h>

#define SECONDS_HOUR 60 * 60
#define SECONDS_MINUTE 60

/**************************************************
 * Splits time in total seconds to hours, mins,   *
 * and seconds                                    *
 **************************************************/
void split_time(long total_sec, int *hr, int *min, int *sec);

int main(int argc, char *argv[])
{

  int hr, min, sec;

  split_time(85, &hr, &min, &sec);

  printf("%d hours, %d minutes, %d seconds\n", hr, min, sec);
  return EXIT_SUCCESS;
}

void split_time(long total_sec, int *hr, int *min, int *sec){
  *hr = total_sec / (SECONDS_HOUR);
  *min = total_sec % (SECONDS_HOUR) / SECONDS_MINUTE;
  *sec = total_sec % SECONDS_HOUR / SECONDS_MINUTE;
}
