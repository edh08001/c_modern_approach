#include <stdio.h>
#include "line.h"
#include "word.h"
#include "readline.h"

#define MAX_WORD_LEN 20

int main(void)
{
  char ch, word[MAX_WORD_LEN+2];
  char read_file_name[MAX_WORD_LEN * 2];
  char write_file_name[MAX_WORD_LEN * 2];
  int word_len;
  FILE *fpr, *fpw;

  fprintf(stdout, "Enter file name to justify: ");
  read_line(read_file_name, MAX_WORD_LEN*2 + 1);

  fpr = fopen(read_file_name, "r");
  if(fpr == NULL)
        fprintf(stderr, "Error opening %s\n", read_file_name);

  fprintf(stdout, "Enter file name to write to: ");
  read_line(write_file_name, MAX_WORD_LEN*2+1);

  fpw = fopen(write_file_name, "w");
  if (fpw == NULL)
      fprintf(stderr, "Error opening %s\n", read_file_name);

  for(;;) {
    word_len = read_word(word, MAX_WORD_LEN+1, fpr);
    if(word_len == 0) {
      flush_line(fpw);
      return 0;
    }
    if(word_len + 1 > space_remaining()) {
      write_line(fpw);
      clear_line();
    }
    add_word(word);
  }
}
