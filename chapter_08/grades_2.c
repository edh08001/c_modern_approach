/* Takes student grades and calculates various highs, lows and averages */
#include <stdio.h>
#include <stdlib.h>

#define SQUARE 5
#define CURRENT_QUIZ quizzes[student][quiz]

int main(int argc, char *argv[]) {
  int col_total = 0;
  int quiz_total = 0;
  int quiz_high[SQUARE] = {0};
  int quiz_low[SQUARE] = {100, 100, 100, 100, 100};
  int quizzes[SQUARE][SQUARE] = {0};
  float quiz_average[SQUARE] = {0};
  float student_average[SQUARE] = {0};

  for (int student = 0; student < SQUARE; student++) {
    printf("Enter 5 grades for student %d: ", student + 1);
    for (int quiz = 0; quiz < SQUARE; quiz++){
      scanf("%d", &CURRENT_QUIZ);
      quiz_total += CURRENT_QUIZ;

      if(quiz_high[quiz] < CURRENT_QUIZ)
        quiz_high[quiz] = CURRENT_QUIZ;

      if(quiz_low[quiz] > CURRENT_QUIZ)
        quiz_low[quiz] = CURRENT_QUIZ;
    }
    student_average[student] = (float) quiz_total / SQUARE;
    quiz_total = 0;
  }

  for (int quiz = 0; quiz < SQUARE; quiz++){
    for (int student = 0; student < SQUARE; student++){
      quiz_total += quizzes[student][quiz];
    }
    quiz_average[quiz] = (float) quiz_total / SQUARE;
    quiz_total = 0;
  }

  printf("\n");

  for (int i = 0; i < SQUARE; i++){
    printf("Student %d average score is: %.1f\n", i + 1, student_average[i]);
  }

  for (int i = 0; i < SQUARE; i++){
    printf("\nQuiz %d high score is: %d\n", i + 1, quiz_high[i]);
    printf("Quiz %d low score is: %d\n", i + 1, quiz_low[i]);
    printf("Quiz %d average score is: %.1f\n", i + 1, quiz_average[i]);
  }

  return EXIT_SUCCESS;
}
