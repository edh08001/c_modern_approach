#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 20

char *c_fgets(char * restrict s, int n, FILE * restrict stream);

int main(void)
{
    FILE *fp = fopen("test.txt", "r");
    char *string = malloc(STRING_SIZE);

    if (string == NULL){
        fprintf(stderr, "Error allocating memory for string\n");
        free(string);
        exit(EXIT_FAILURE);
    }

    string = c_fgets(string, STRING_SIZE, fp);

    fprintf(stdout, "%s", string);

}

char *c_fgets(char * restrict s, int n, FILE * restrict stream)
{
    char ch;
    int index = 0;
    while ((ch = fgetc(stream)) != EOF && index < n){
        s[index++] = ch;
        if (ch == '\n')
            break;
    }

    if (index == 0 || ferror(stream))
        return NULL;

    s[index] = '\0';

    if (ch != '\n')
        fprintf(stderr, "Warning: line size too large for buffer.\n");
    
    return s;
}

