#include <stdlib.h>
#include <stdio.h>

#define DIGIT_HEIGHT 3
#define DIGIT_WIDTH 4
#define MAX_DIGITS 10
#define ZERO_SEGMENT {1, 1, 1, 1, 1, 1}
#define ONE_SEGMENT {[1] = 1, 1}
#define TWO_SEGMENT {1, 1, 0, 1, 1, 0, 1}
#define THREE_SEGMENT {1, 1, 1, 1, [6] = 1}
#define FOUR_SEGMENT {0, 1, 1, [5] = 1, 1}
#define FIVE_SEGMENT {1, 0, 1, 1, 0, 1, 1}
#define SIX_SEGMENT {1, 0, 1, 1, 1, 1, 1}
#define SEVEN_SEGMENT {1, 1, 1}
#define EIGHT_SEGMENT {1, 1, 1, 1, 1, 1, 1}
#define NINE_SEGMENT {1, 1, 1, 1, 0, 1, 1}

/********************************************************
* *
********************************************************/ 

/********************************************************
* Reset all digits with ' ' chars by looping through    *
* [DIGIT_HEIGHT][MAX_DIGITS]                            *
********************************************************/ 
void clear_digits(char digit[][MAX_DIGITS * DIGIT_WIDTH]);

/********************************************************
* Process a digit at a certain position inside of the   *
* digit array. Takes a digit as well as the position in *
* the array it will be found                            *
********************************************************/ 
void process_digit(int digit, int position);

/********************************************************
* Prints the digits utilizing the digits array. This    *
* function prints row by row, not digit by digit        *
********************************************************/ 
void print_digits_array(void);

/*****************External Variables*********************
********************************************************/
char digits[DIGIT_HEIGHT][MAX_DIGITS * DIGIT_WIDTH];
const int segments[10][7] = {
  ZERO_SEGMENT,
  ONE_SEGMENT,
  TWO_SEGMENT,
  THREE_SEGMENT,
  FOUR_SEGMENT,
  FIVE_SEGMENT,
  SIX_SEGMENT,
  SEVEN_SEGMENT,
  EIGHT_SEGMENT,
  NINE_SEGMENT
};

int main(int argc, char *argv[])
{
  clear_digits(digits);

  char in;
  int index = 0;
  printf("Enter a number: ");

  while ((in = getchar()) != '\n')
  {
    if(in - '0' <= 9 && in - '0' >= 0 && index < 10)
      process_digit(in - '0', index++);
  }
  
  print_digits_array();
  


  return EXIT_SUCCESS;
}

void clear_digits(char digit[][MAX_DIGITS * DIGIT_WIDTH]){
  for(int i = 0; i < DIGIT_HEIGHT; i++){
    for(int j = 0; j < MAX_DIGITS * DIGIT_WIDTH; j++){
      digit[i][j] = ' ';
    }
  }
}

void process_digit(int digit, int position){
  for(int i = 0; i < 7; i++){
    switch(i){
      case 0: if (segments[digit][i] == 1){ 
                digits[0][position * DIGIT_WIDTH + 1] = '_';   
      }
      break;
      case 1: if (segments[digit][i] == 1){ 
                digits[1][position * DIGIT_WIDTH + 2] = '|';   
      }
      break;
      case 2: if (segments[digit][i] == 1){ 
                digits[2][position * DIGIT_WIDTH + 2] = '|';   
      }
      break;
      case 3: if (segments[digit][i] == 1){ 
                digits[2][position * DIGIT_WIDTH + 1] = '_';   
      }
      break;
      case 4: if (segments[digit][i] == 1){ 
                digits[2][position * DIGIT_WIDTH] = '|';   
      }
      break;
      case 5: if (segments[digit][i] == 1){ 
                digits[1][position * DIGIT_WIDTH] = '|';   
      }
      break;
      case 6: if (segments[digit][i] == 1){ 
                digits[1][position * DIGIT_WIDTH + 1] = '_';   
      }
      break;
    }
  }
}

void print_digits_array(void){
  for (int i = 0; i < DIGIT_HEIGHT; i++){
    printf("\n");
    for (int j = 0; j < MAX_DIGITS * DIGIT_WIDTH; j++){
      printf("%c", digits[i][j]);
    }
  }
  printf("\n\n");
}
