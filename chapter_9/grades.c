/* This program computes GPA from letter grades on a scale of 0-4 for F-A */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 10

float compute_GPA(char grades[], int n);

int main(int argc, char *argv[])
{
  
  char grades[N] = {'A', 'C', 'A', 'B', 'F', 
                    'C', 'B', 'A', 'B', 'A'};

  printf("The GPA of all grades is %4.2f\n", compute_GPA(grades, N)); 

  return EXIT_SUCCESS;
}

float compute_GPA(char grades[], int n){
  int i, total = 0;
  for (i = 0; i < n; i++){
    switch(toupper(grades[i])){
      case 'A': total += 4;
      break;
      case 'B': total += 3;
      break;
      case 'C': total += 2;
      break;
      case 'D': total += 1;
      break;
      case 'F': total += 0;
      break;
    }
  }
  return (float) total / n;
}
