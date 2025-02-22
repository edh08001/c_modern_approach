#include <stdio.h>
#include <stdlib.h>

#define READ_BINARY "rb"

FILE *open_file(char *name, char *mode);
int print_row(FILE *fp, int offset);

int main(int argc, char *argv[])
{

  if (argc != 2){
    fprintf(stderr, "Error: improper program entry. Use format: ./main <file_to_print>\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  char ch;
  int offset = 0;
  fp = open_file(argv[1], READ_BINARY);

  fprintf(stdout, "Offset               Bytes               Characters\n");
  fprintf(stdout, "------  -------------------------------  ----------\n");

  while ((ch = fgetc(fp)) != EOF){
    
    
  }
  
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
