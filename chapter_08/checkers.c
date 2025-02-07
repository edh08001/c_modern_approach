#include <stdio.h>
#include <stdlib.h>

#define BOARD_HEIGHT 8
#define BOARD_WIDTH 8

int main(int argc, char *argv[])
{

  char checker_board[BOARD_HEIGHT][BOARD_WIDTH];

  for (int i = 0; i < BOARD_HEIGHT; i++){
    for (int j = 0; j < BOARD_WIDTH; j++){
      if ((i + j) % 2 == 0){
        checker_board[i][j] = 'B';
      } else {
        checker_board[i][j] = 'R';
      }
      printf("%c ", checker_board[i][j]);
    }
    printf("\n");
  }


  return EXIT_SUCCESS;
}
