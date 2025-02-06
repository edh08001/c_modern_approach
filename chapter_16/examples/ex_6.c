#include <stdio.h>

struct time {
  int hour, minute, second;
};

struct time split_time(long total_seconds)
{
  return (struct time) {.hour = total_seconds / (60*60),
                        .minute = (total_seconds%(60*60))/60,
                        .second = (total_seconds%(60*60))%60};
}

int main(void)
{
  struct time t = split_time(6000L);

  printf("%d hours, %d minutes, %d seconds\n", t.hour, t.minute, t.second);

  return 1;
}
