#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define READ_BINARY "rb"
#define WRITE_BINARY "wb"

FILE *open_file(char *name, char *mode);
int compress_file(FILE *fp, char* name);

int main(int argc, char *argv[])
{

  if (argc != 2){
    fprintf(stderr, "Error: improper program entry. Use format: ./main <file_to_compress>\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  fp = open_file(argv[1], READ_BINARY);

  compress_file(fp, argv[1]);

  fclose(fp);

  return EXIT_SUCCESS;
}

int compress_file(FILE *fin, char* name)
{
  FILE *fout;
  int count = 1;
  char ch, ch_prev, *c_name;
  c_name = malloc(64);
  strcat(c_name, name);
  strcat(c_name, ".rle");

  fout = open_file(c_name, WRITE_BINARY);

  ch_prev = fgetc(fin);

  while ((ch = fgetc(fin)) != EOF){
    if (ch == ch_prev) {
      count++;
    } else {
      fprintf(fout, "%hhX%c", count, ch_prev);
      ch_prev = ch;
      count = 1;
    }
  }

  fclose(fout);
  free(c_name);

  return 1;
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
