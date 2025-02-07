/* This program creates a magic square of a specified size */
#include <stdio.h>
#include <stdlib.h>

void create_magic_square(int n, char square[n][n]);

void print_magic_square(int n, char square[n][n]);

int main(int argc, char *argv[])
{
  int size, cur_row, cur_col, prev_row, prev_col;
  cur_row = prev_row = 0;

  printf("Enter size of magic square (odd, betwen 1 and 99): ");
  scanf("%d", &size);

  char square[size][size];

  create_magic_square(size, square);

  print_magic_square(size, square);
  
  return EXIT_SUCCESS;
}

void create_magic_square(int n, char square[][n]){
  int cur_row, cur_col, prev_row, prev_col;
  cur_row = prev_row = 0;

  cur_col = prev_col = n/2;
  

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      square[i][j] = 0;
  

  square[cur_row][cur_col] = 1;

  for (int i = 2; i <= n * n; i++){
    if (cur_row - 1 < 0)
      cur_row = n - 1;
    else 
      cur_row--;
    if (cur_col + 1 >= n)
      cur_col = 0;
    else
      cur_col++;

    if (square[cur_row][cur_col] != 0){
      cur_col = prev_col;
      if(prev_row + 1 < n){
        cur_row = prev_row + 1;
      } else {
        cur_row = 0;
      }
    }
    square[cur_row][cur_col] = i;
    prev_row = cur_row;
    prev_col = cur_col;
  }
}

void print_magic_square(int n, char square[][n]){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      printf("%5d", square[i][j]);
    }
    printf("\n");
  }

}
