#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;
static int num_lines = 1;

void clear_line(void)
{
  line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
  if (num_words > 0) {

    line[line_len] = ' ';
    line[line_len+1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(FILE *fp)
{
  int extra_spaces, spaces_to_insert, i, j;

  extra_spaces = space_remaining();
  for (i = 0; i < line_len; i++) {
    if (line[i] != ' ')
      fputc(line[i], fp);
    else {
      if (num_lines % 2 != 0){
        spaces_to_insert = extra_spaces / (num_words - 1);
      } else {
        spaces_to_insert = extra_spaces / 2 == 0 ? extra_spaces : extra_spaces / 2;
      }
      for (j = 1; j <= spaces_to_insert + 1; j++)
        fputc(' ', fp);
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }
  num_lines++;
  fputc('\n', fp);
}

void flush_line(FILE *fp)
{
  if (line_len > 0)
    fputs(line, fp);
}
