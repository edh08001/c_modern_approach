#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define FIELD_SIZE 10
#define UPPER_LIMIT 9
#define LOWER_LIMIT 0
#define DIRECTIONS 4
#define FWD_ONE cur_col + 1
#define UP_ONE cur_row - 1
#define DOWN_ONE cur_row + 1
#define BACK_ONE cur_col -1

void generate_random_walk(char walk[10][10]);

void print_array(char walk[10][10]);

int main(int argc, char *argv[])
{
  char field[FIELD_SIZE][FIELD_SIZE];

  for(int row = 0; row < FIELD_SIZE; row++){
    for(int col = 0; col < FIELD_SIZE; col++){
      field[row][col] = '.';
    }
  }

  srand((unsigned) time(NULL));

  generate_random_walk(field);

  print_array(field);

  printf("\n");

  return EXIT_SUCCESS;
}

void generate_random_walk(char walk[10][10]){
  bool next_move_complete = false;
  bool attempted_direction[4] = {false};
  int direction, cur_row, cur_col;
  cur_row = cur_col = 0;

  walk[cur_row][cur_col] = 'A';

  for (int letter = 'B'; letter <= 'Z'; letter++){
    do {
      next_move_complete = false;
      direction = rand() % DIRECTIONS;
      if (!attempted_direction[direction]){
        switch(direction){
          case 0: {
            if (UP_ONE >= LOWER_LIMIT && walk[UP_ONE][cur_col] == '.'){
              walk[UP_ONE][cur_col] = letter;
              cur_row -= 1;
              
              for (int i = 0; i < DIRECTIONS; i++) attempted_direction[i] = false;
              next_move_complete = true;
            } else {
              attempted_direction[0] = true;
            }
            break;
          } 
          case 1: {
            if (FWD_ONE <= UPPER_LIMIT && walk[cur_row][FWD_ONE] == '.'){
              walk[cur_row][FWD_ONE] = letter;
              cur_col += 1;
             
              for (int i = 0; i < DIRECTIONS; i++) attempted_direction[i] = false;
              next_move_complete = true;
            } else {
              attempted_direction[1] = true;
            }
          break;
          }
          case 2: {
            if (DOWN_ONE <= UPPER_LIMIT && walk[DOWN_ONE][cur_col] == '.'){
              walk[DOWN_ONE][cur_col] = letter;
              cur_row += 1;
             
              for (int i = 0; i < DIRECTIONS; i++) attempted_direction[i] = false;
              next_move_complete = true;
            } else {
              attempted_direction[2] = true;
            }
          break;
          } 
          case 3: {
            if (BACK_ONE >= LOWER_LIMIT && walk[cur_row][BACK_ONE] == '.'){
              walk[cur_row][BACK_ONE] = letter;
              cur_col -= 1;
             
              for (int i = 0; i < DIRECTIONS; i++) attempted_direction[i] = false;
              next_move_complete = true;
            } else {
              attempted_direction[3] = true;
            }
          break;
          }
        }
      }

      // Check if all 4 directions have been attempted, break if so. 
      if (attempted_direction[0] == true 
          && attempted_direction[1] == true
          && attempted_direction[2] == true
          && attempted_direction[3] == true){
        break;
      }

    } while (!next_move_complete);
  }
}

void print_array(char walk[10][10]){
  for(int row = 0; row < FIELD_SIZE; row++){
    printf("\n");
    for (int col = 0; col < FIELD_SIZE; col++){
      printf("%c ", walk[row][col]);
    }
  }

  printf("\n");

}
