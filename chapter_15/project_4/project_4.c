#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_string.h"

#define REMINDER_COUNT 10
#define REMINDER_SIZE 101

/****************************************************
 * Iterates through the REMINDER_COUNT number of    *
 * opportunities to query the user for a reminder   *
 ****************************************************/
int query_user(char reminders[][REMINDER_SIZE], int n);

/****************************************************
 * Sort the reminder array so that the soonest come *
 * first. Using simple sort.                        *
 ****************************************************/
int sort_reminders(char (*reminders)[REMINDER_SIZE], int n);

/****************************************************
 * Prints the reminders, in order of the array      *
 ****************************************************/
void print_reminders(char (*reminders)[REMINDER_SIZE], int n);

int main(int argc, char *argv[])
{
  char reminders[REMINDER_COUNT][REMINDER_SIZE];
  int end_index;

  end_index = query_user(reminders, REMINDER_COUNT);

  sort_reminders(&reminders[0], end_index);

  print_reminders(&reminders[0], end_index);

  return EXIT_SUCCESS;
}

int query_user(char reminders[][REMINDER_SIZE], int n)
{
  int i;
  for (i = 0; i < n; i++){
    printf("Enter day and reminder: ");
    read_string(reminders[i], REMINDER_SIZE - 1);
    if (*reminders[i] == '0' && *(reminders[i] + 1) == '\0') break;
  }
  return i - 1;
}


int sort_reminders(char (*reminders)[REMINDER_SIZE], int n)
{
  while (n > 0){
    char *max_position = *reminders, temp[REMINDER_SIZE], *end = reminders[n];
    do {
      if (strcmp(max_position, *reminders) < 0) {
        max_position = *reminders;
      }
    } while (*++reminders <= end);
    strcpy(temp, end);
    strcpy(end, max_position);
    strcpy(max_position, temp);
    return sort_reminders(reminders - (n + 1), n - 1);
  }
  return 1;
}

void print_reminders(char (*reminders)[REMINDER_SIZE], int n){
  char *end = *(reminders + n);
  do {
    printf("%s\n", *reminders);
  } while(*++reminders <= end);
}

