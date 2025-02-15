#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

struct vstring {
  int len;
  char chars[];
};

int read_line(char str[], int n);

int main(void)
{
  char *reminders[MAX_REMIND];
  struct vstring *v_reminders[MAX_REMIND];
  char day_str[3], msg_str[MSG_LEN+1];
  int day, i, j, num_remind = 0;

  for (;;){
    if (num_remind == MAX_REMIND){
      printf("-- No space left --\n");
      break;
    }
    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0)
      break;
    sprintf(day_str, "%2d", day);
    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++)
      if (strcmp(day_str, v_reminders[i]->chars) < 0)
        break;
    for (j = num_remind; j > i; j--)
      v_reminders[j] = v_reminders[j-1];

    v_reminders[i] = malloc(sizeof(int) + 2 + strlen(msg_str) + 1);
    v_reminders[i]->len = 2 + strlen(msg_str);
    if (v_reminders[i] == NULL) {
      printf("-- No memory space left --\n");
      break;
    }

    strcpy(v_reminders[i]->chars, day_str);
    strcat(v_reminders[i]->chars, msg_str);

    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", v_reminders[i]->chars);

  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
