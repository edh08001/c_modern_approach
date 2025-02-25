#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "readline.h"

#define FILE_NAME_SIZE 64
#define NAME_LENGTH 25

typedef struct {
  int part_number;
  char part_name[NAME_LENGTH+1];
  int on_hand;
  double price;
} part;

FILE *open_file(FILE *fp, char *file_name, char *mode);
size_t get_file_size(FILE *fp);
void * my_malloc(int n);
void * my_realloc(int n, void *a);
void dump(FILE *fp, part *array, size_t sz);
void restore(FILE *fp, part *array, size_t sz);
size_t merge_arrays(part *a1, size_t sz1, part *a2, size_t sz2);
int compare_parts(const void *p1, const void *p2);

int main(int argc, char *argv[])
{
    char file_1[FILE_NAME_SIZE];
    char file_2[FILE_NAME_SIZE];
    char file_3[FILE_NAME_SIZE];
    FILE *fp1, *fp2, *fp3;
    size_t sz1, sz2;
    part *a1, *a2;

    printf("Enter the first file name to merge: ");
    read_line(file_1, FILE_NAME_SIZE);
    printf("Enter the second file name to merge: ");
    read_line(file_2, FILE_NAME_SIZE);
    printf("Enter the name for the merged file: ");
    read_line(file_3, FILE_NAME_SIZE);

    fp1 = open_file(fp1, file_1, "rb");
    fp2 = open_file(fp2, file_2, "rb");
    fp3 = open_file(fp3, file_3, "wb");
    
    sz1 = get_file_size(fp1);
    sz2 = get_file_size(fp2);

    a1 = my_malloc(sz1 + sz2);
    a2 = my_malloc(sz2);

    restore(fp1, a1, sz1);
    restore(fp2, a2, sz2);

    sz1 = (merge_arrays(a1, sz1, a2, sz2) * sizeof(part));   
    
    qsort(a1, sz1/sizeof(part), sizeof(part), compare_parts);

    a1 = my_realloc(sz1, a1);
    
    dump(fp3, a1, sz1);

    free(a2);
    free(a1);

    return EXIT_SUCCESS;
}

int compare_parts(const void *p1, const void *p2)
{
  const part *q1 = p1;
  const part *q2 = p2;
  
  return q1->part_number - q2->part_number;
}

size_t merge_arrays(part *a1, size_t sz1, part *a2, size_t sz2)
{
    int i, j, n;
    bool match = false;
    n = (sz1/sizeof(part));

    for (i = 0; i < (sz2 / sizeof(part)); i++){
        for (j = 0; j < (sz1 / sizeof(part)); j++){
            if(a2[i].part_number == a1[j].part_number){
                a1[j].on_hand += a2[i].on_hand;
                if(strcmp(a2[i].part_name, a1[j].part_name) != 0){
                    fprintf(stderr, "Error: part number %d has two names:\n"
                            "Name 1: %s\nName 2: %s\n"
                            "Names merged to %s\n", a2[i].part_number,
                            a2[j].part_name, a1[i].part_name, a1[i].part_name);
                }
                match = true;
                break;
            }
        }
        if (!match){
            a1[n++] = a2[i];
            match = false;
        }
    }
    return n;
}

void dump(FILE *fp, part *array, size_t sz)
{
    fwrite(array, sizeof(part), sz / sizeof(part), fp);

    fclose(fp);
}

void restore(FILE *fp, part *array, size_t sz)
{
    fread(array, sizeof(part), sz / sizeof(part), fp);

    fclose(fp);
}

FILE *open_file(FILE *fp, char *file_name, char *mode)
{
    fp = fopen(file_name, mode);
    if (fp == NULL){
        fprintf(stderr, "Error opening file %s.\n", file_name);
        exit(EXIT_FAILURE);
    }
    return fp;
}

size_t get_file_size(FILE *fp)
{
    size_t sz;
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    rewind(fp);

    return sz;
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

void * my_realloc(int n, void *a)
{
  void * p = realloc(a, (size_t)n);
  if (p == NULL) {
    printf("Insufficient memory for my_malloc");
    exit(EXIT_FAILURE);
  }

  return p;
}
