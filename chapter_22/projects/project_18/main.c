#include <stdio.h>
#include <stdlib.h>

#define ARGS 2

int compare(const void *a, const void *b);
int get_int(FILE *fp, char ch);
void check_argc(int argc);
FILE *open_file(char *file_name, char *open_type);

int main(int argc, char *argv[])
{
    int i = 0, nums[10000];
    char ch;
    FILE *fp = open_file(argv[1], "rb");

    if (argc != ARGS){
        fprintf(stderr, "Please enter exactly one argument: ./main filename\n");
        exit(EXIT_FAILURE);
    }

    for (;;){
        
        while ((ch = fgetc(fp)) == ' ' || ch == '\n')
            ;

        if (ch == EOF) 
            break;

        if((nums[i++] = get_int(fp, ch)) == -1)
            i--;
    }

    qsort(nums, i, sizeof(int), compare);

    fprintf(stdout, "Smallest: %d\nLargest: %d\nMedian: %d\n", nums[0], nums[i-1], 
            i % 2 == 0 ? ((nums[i/2] + nums[(i/2)+1])/2) : nums[i/2]);

    return EXIT_SUCCESS;
}

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int get_int(FILE *fp, char ch)
{
    char num[11];
    int i = 0;
    num[i++] = ch;
    while ((ch = fgetc(fp)) != ' ' && ch != EOF){
        if (i == 10){
            fprintf(stderr, "Error, number %.10s at limit for integer type." 
                            " Skipping.\n", num);

            while ((ch = fgetc(fp)) != ' ' && ch != EOF)
                ;

            return -1;
        }

        num[i++] = ch;
    }
    num[i] = '\0';

    return atoi(num);
}

FILE *open_file(char *file_name, char *open_type)
{
    FILE *fp = fopen(file_name, open_type);
    if (fp == NULL){
        fprintf(stderr, "Error opening file %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    return fp;
}
