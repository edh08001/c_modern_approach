#include <stdio.h>
#include <stdlib.h>
#include "part.h"
#include "inventory.h"
#include "readline.h"

#define FILE_NAME_SIZE 80

void * my_malloc(int n);
void dump(part *parts, int num_parts);
part *restore(part *parts, int *num_parts);

int main(void)
{
  num_parts = 0;
  inventory_size = 2;

  char ch[2];
  part *parts = my_malloc(sizeof(part) * inventory_size);

  for (;;){
    printf("Enter Menu Option (i,s,u,c,p,d,r,q): ");
    read_line(ch, 1);
    switch(ch[0]){
      case 'i': add_part(&parts, inventory_size); 
      break;
      case 's': search_part(parts);
      break;
      case 'u': update_part_quantity(parts);
      break;
      case 'c': update_part_price(parts);
      break;
      case 'p': display_all_parts(parts);
      break;
      case 'd': dump(parts, num_parts);
      break;
      case 'r': parts = restore(parts, &num_parts);
      break;
      case 'q': return 1; 
      break;
    }
  }
  free(parts);
}

void dump(part *parts, int num_parts){
    char file_name[FILE_NAME_SIZE];
    FILE *fp;

    printf("Enter name of output file: ");
    read_line(file_name, FILE_NAME_SIZE);
    printf("\n");

    fp = fopen(file_name, "wb");
    if (fp == NULL){
        fprintf(stderr, "Error opening file for write\n");
        exit(EXIT_FAILURE);
    }

    fwrite(parts, sizeof(part), num_parts, fp);

    fclose(fp);
}

part *restore(part *parts, int *num_parts){
    char file_name[FILE_NAME_SIZE];
    FILE *fp;
    size_t sz, n;

    free(parts);

    printf("Enter name of input file: ");
    read_line(file_name, FILE_NAME_SIZE);
    printf("\n");

    fp = fopen(file_name, "rb");
    if (fp == NULL){
        fprintf(stderr, "Error opening file for read\n");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    rewind(fp);
    
    part *new_parts = my_malloc(sz);

    *num_parts = sz / sizeof(part);
    fread(new_parts, sizeof(part), *num_parts, fp);

    fclose(fp);

    return new_parts;
}

void * my_malloc(int n)
{
  void * p = malloc(n);
  if (p == NULL) {
    printf("Insufficient memory for my_malloc");
    exit(EXIT_FAILURE);
  }

  return p;
}
