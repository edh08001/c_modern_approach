#include <stdio.h>
int main(int argc, char *argv[])
{
  float wind_speed;
  char* output;
  printf("Enter wind speed (in knots): ");
  scanf("%f", &wind_speed);
  
  if (wind_speed < 1.0f) output = "Calm";
  else if (wind_speed <= 3.0f) output = "Light air";
  else if (wind_speed <= 27.0f) output = "Breeze";
  else if (wind_speed <= 47.0f) output = "Gale";
  else if (wind_speed <= 63.0f) output = "Storm";
  else output = "Hurricane";

  printf("The Beaufort Scale desctiption corresponding to %.2f knots is: %s\n", wind_speed, output);

  return 0;
}
