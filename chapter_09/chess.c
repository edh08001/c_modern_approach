#include <stdio.h>
#include <stdlib.h>

#define N 8

int evaluate_position(char board[][N]);

int main(int argc, char *argv[])
{

  char board[N][N] = {
    {' ', ' ', ' ', 'K', 'Q', ' ', 'R', ' '},
    {'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', 'P', 'p', 'p', ' ', ' '},
    {' ', ' ', ' ', ' ', 'q', ' ', 'r', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', 'b', 'k', ' ', ' ', ' ', ' '}
  };

  printf("The advantage is as follows: %d\n", evaluate_position(board));


  return EXIT_SUCCESS;
}

int evaluate_position(char board[][N]){
  int i, j, sum_white, sum_black;
  sum_white = sum_black = 0;

  for (i = 0; i < N; i++){
    for (j = 0; j < N; j++){
      switch(board[i][j]){
        case 'Q': sum_white += 9;
        break;
        case 'R': sum_white += 5;
        break;
        case 'B': /* fallthrough */
        case 'N': sum_white += 3;
        break;
        case 'P': sum_white += 1;
        break;
        case 'q': sum_black += 9;
        break;
        case 'r': sum_black += 5;
        break;
        case 'b': /* fallthrough */
        case 'n': sum_black += 3;
        break;
        case 'p': sum_black += 1;
        break;
      }
    }
  }

  return sum_white - sum_black;
}
