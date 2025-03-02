#include <stdio.h>
#include "word.h"

int read_char(FILE *fp)
{
  int ch = fgetc(fp);
  if (ch == '\n' || ch == '\t')
    return ' ';
  return ch;
}

int read_word(char *word, int len, FILE *fp)
{
  int ch, pos = 0;
  while ((ch = read_char(fp)) == ' ')
    ;
  while (ch != ' ' && ch != EOF) {
    if (pos < len)
      word[pos++] = ch;
    ch = read_char(fp);
  }
  word[pos] = '\0';
  if (pos == len) {
    word[pos - 1] = '*';
  }
  return pos;
}

