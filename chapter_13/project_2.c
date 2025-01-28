#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line (char str[], int n);

int main(void)
{
  char reminders[MAX_REMIND][MSG_LEN+15];
  char day_str[8], time_str[7], day_time_str[15], msg_str[MSG_LEN+1];
  int day, mo, hh, mm, i, j, num_remind = 0;

  for (;;){
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter day & month (mm/dd), 24h time, and reminder: ");
    scanf("%2d/%2d", &mo, &day);
    if (mo == 0)
      break;
    scanf("%2d:%2d", &hh, &mm); 

    sprintf(day_str, "%2.2d/%2.2d", mo, day);
    sprintf(time_str, " %2.2d:%2.2d", hh, mm);

    strcpy(day_time_str, day_str);
    strcat(day_time_str, time_str);

    read_line(msg_str, MSG_LEN);

    if (day > 31 || day < 0){
      printf("Error: Invalid day entered, enter a valid day\n");
      continue;
    }

    for (i = 0; i < num_remind; i++)
      if (strcmp(day_time_str, reminders[i]) < 0)
        break;
    for (j = num_remind; j > i; j--)
      strcpy(reminders[j], reminders[j-1]);

    strcpy(reminders[i], day_time_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nDay/Mo Time  Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);

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
