#include <stdio.h>

struct flight_time{
  int departure;
  int arrival;
};

int main(int argc, char *argv[])
{
  int hr, min, to_midnight;
  int f1, f2, f3, f4, f5, f6, f7, f8;
  
  struct flight_time table[] = 
    {{8 * 60,       10 * 60 + 16},
     {9 * 60 + 43,  11 * 60 + 52},
     {11 * 60 + 19, 13 * 60 + 31},
     {12 * 60 + 47, 15 * 60     },
     {14 * 60,      16 * 60 + 8 },
     {15 * 60 + 45, 17 * 60 + 55},
     {19 * 60,      21 * 60 + 20},
     {21 * 60 + 45, 23 * 60 + 58}};
                                
  printf("Enter a time in 24h format: ");
  scanf("%d:%d", &hr, &min);

  to_midnight = hr * 60 + min;
 
  for (int i = 0; i < 8; i++){
    if (table[i].departure > to_midnight){
      
    }
  }

  return 0;
}
