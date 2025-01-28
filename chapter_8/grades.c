#include <stdio.h>
#include <stdlib.h>

#define SQUARE 5

int main(int argc, char *argv[])
{
  int col_total = 0;
  int row_total = 0;
  int quizzes[SQUARE][SQUARE] = {
    {8, 3, 9, 0, 10},
    {3, 5, 17, 1, 1},
    {2, 8, 6, 23, 1},
    {15, 7, 3, 2, 9},
    {6, 14, 2, 6, 0}
  };

  printf("Row totals: ");
  for(int rows = 0; rows < SQUARE; rows++){
    for(int cols = 0; cols < SQUARE; cols++){
      row_total += quizzes[rows][cols];
      //Could just as easily put col_total here and skip
      //the entire next part of the program, but output
      //would be different. 
    }
    printf("%d ", row_total);
    row_total = 0;
  }
  
  printf("\nColumn totals: ");
  for(int rows = 0; rows < SQUARE; rows++){
    for(int cols = 0; cols < SQUARE; cols++){
      col_total += quizzes[cols][rows];
    }
    printf("%d ", col_total);
    col_total = 0;
  }

  printf("\n");
  
  return EXIT_SUCCESS;
}
