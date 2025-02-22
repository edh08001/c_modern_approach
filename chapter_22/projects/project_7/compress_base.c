#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define READ_BINARY "rb"

FILE *open_file(char *name, char *mode);

int main(int argc, char *argv[])
{

  if (argc != 2){
    fprintf(stderr, "Error: improper program entry. Use format: ./main <file_to_print>\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  char ch, chars[11];
  int offset = 0, line = 1;

  fp = open_file(argv[1], READ_BINARY);

  fprintf(stdout, "Offset               Bytes             Characters\n");
  fprintf(stdout, "------  -----------------------------  ----------\n");
  fprintf(stdout, "%6d  ", offset);

  while ((ch = fgetc(fp)) != EOF){
    printf("%02hhX ", ch);

    if (isprint(ch)) {
      chars[offset] = ch;
    } else {
      chars[offset] = '.';
    }

    if (++offset == 10) {
      chars[offset] = '\0';
      fprintf(stdout, " %s\n%6d  ", chars, offset * line++);
      offset = 0;
    }
  }

  chars[offset] = '\0';

  for (int i = offset; offset < 10; offset++) {
    fprintf(stdout, "   ");
  }

  fprintf(stdout, " %s\n", chars);

  fclose(fp);
  
  return EXIT_SUCCESS;
}

FILE *open_file(char *name, char *mode)
{
      FILE *fp;
      if ((fp = fopen(name, mode)) == NULL){
            fprintf(stderr, "Error opening file %s\n", name);
            exit(EXIT_FAILURE);
      }          

      return fp;
}
