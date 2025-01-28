#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_SIDES 6

int roll_dice(void);

bool play_game(void);

int main(int argc, char *argv[]) {
  int count_wins = 0, count_losses = 0;
  bool play_again = true;

  while (play_again) {
    char response;
    if (play_game()) {
      count_wins++;
      printf("You win!\n");
    } else {
      count_losses++;
      printf("You lose!\n");
    }

    printf("\nPlay again? ");
    while ((response = getchar()) == '\n')
      ;

    if (response == 'y' || response == 'Y') {
      play_again = true;
    } else {
      play_again = false;
    }
  }

  printf("\n");

  printf("Wins: %d  Losses: %d\n", count_wins, count_losses);

  return EXIT_SUCCESS;
}

int roll_dice(void) {
  int dice1 = 1 + (rand() % (DICE_SIDES - 1));
  int dice2 = 1 + (rand() % (DICE_SIDES - 1));

  return dice1 + dice2;
}

bool play_game(void) {
  srand((unsigned)time(NULL));
  bool keep_playing = true;
  int roll_count = 0, point = 0;

  while (keep_playing) {
    int current_roll = roll_dice();
    printf("You rolled: %d\n", current_roll);
    if (roll_count == 0) {
      if (current_roll == 7 || current_roll == 11) {
        break;
      } else if (current_roll == 2 || current_roll == 3 || current_roll == 12) {
        keep_playing = false;
      } else {
        printf("Your point is %d\n", current_roll);
        roll_count++;
        point = current_roll;
      }
    } else {
      if (current_roll == point) {
        break;
      } else if (current_roll == 7) {
        keep_playing = false;
      }
      roll_count++;
    }
  }

  return keep_playing;
}
