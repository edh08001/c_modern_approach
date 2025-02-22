#include <stdlib.h>
#include <stdio.h>

#define WRITE_BINARY "wb"
#define READ_BINARY "rb"
#define KEY '&'

FILE *open_file(char *name, char *mode);

int main(int argc, char *argv[])
{
      int orig_char, new_char;
      FILE *fp1, *fp2;
      
      if (argc != 3) {
            fprintf(stderr, "Please use following format: ./main file_read file_write\n");
            exit(EXIT_FAILURE);
      }

      fp1 = open_file(argv[1], READ_BINARY);
      fp2 = open_file(argv[2], WRITE_BINARY);

      while ((orig_char = fgetc(fp1)) != EOF) {
            new_char = orig_char ^ KEY;
            fputc(new_char, fp2);
      }

      return 0;
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
