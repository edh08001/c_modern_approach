#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_NUMBER 100

int secret_number;

void initialize_number_generator(void);
void choose_new_secret_number(void);
void read_guesses(void);

int main(int argc, char *argv[])
{
  char response;
  printf("Guess the secret number between 1 and 100.\n\n");

    initialize_number_generator();
  do {
    choose_new_secret_number();
    read_guesses();  

    printf("Play again? (Y/N) ");
    scanf(" %c", &response);
  } while (response == 'y' || response == 'Y');
  

  return EXIT_SUCCESS;
}

void initialize_number_generator(void){
  srand((unsigned) time(NULL));
}

void choose_new_secret_number(void){
  secret_number = rand() % MAX_NUMBER;
  printf("A new number has been chosen.\n");
}

void read_guesses(void){
  int guess, guess_count = 0;
  do {
    printf("Enter guess: ");
    scanf(" %d", &guess);
    guess_count++;
    if (guess == secret_number)
      printf("You won in %d guesses!\n\n", guess_count);
    else
      if (guess > secret_number)
        printf("Too high, try again.\n");
      else
        printf("Too low, try again.\n");
  } while (guess != secret_number);
}
