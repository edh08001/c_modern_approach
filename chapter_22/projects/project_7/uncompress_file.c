#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define READ_BINARY "rb"
#define WRITE_BINARY "wb"

FILE *open_file(char *name, char *mode);
int uncompress_file(FILE *fp, char* name);
void remove_ext(char **name);

int main(int argc, char *argv[])
{
  
  
  if (argc != 2){
    fprintf(stderr, "Error: improper program entry. Use format: ./main <file_to_compress>\n");
    exit(EXIT_FAILURE);
  }
 
  FILE *fp;
  fp = open_file(argv[1], READ_BINARY);

  char *f_name = malloc(64);
  if (f_name == NULL){
    fprintf(stderr, "Error allocating memory for file name string\n");
    exit(EXIT_FAILURE);
  }

  strcpy(f_name, argv[1]);

  remove_ext(&f_name);

  uncompress_file(fp, f_name);

  fclose(fp);
  free(f_name);

  return EXIT_SUCCESS;
}

void remove_ext(char **name){
  int name_len, i = 0;
  char *c_name, *c_ext = ".rle";
  c_name = *name;

  while (strcmp(c_name++, c_ext) != 0){
      i++;
  }

  (*name)[i] = '\0';
}

int uncompress_file(FILE *fin, char* name)
{
  FILE *fout;
  int count = 0;
  char ch;

  fout = open_file(name, WRITE_BINARY);
  
  
  while ((ch = fgetc(fin)) != EOF){
    if (count == 0){
      count = ch;
    } else {
      while(count > 0){
        fputc(ch, fout);
        count--;
      }
    }
  }
  fclose(fout);

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
