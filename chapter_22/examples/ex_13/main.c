#include <stdlib.h>
#include <stdio.h>

#define LINE 3

int line_length(const char *filename, int n)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }
        
    char ch;
    int count, line;
    count = 0;
    line = 1;

    while ((ch = fgetc(fp)) != EOF){
        count++;
        if (ch == '\n'){
            if (line++ == n)
                return count - 1;
            else 
                count = 0;
        }
    }
    
    return 0;
}

int main(void)
{
    printf("Line %d is %d bytes long\n", LINE, line_length("test.txt", LINE));
}
