#include <stdio.h>

int c_fputs(const char *restrict s, FILE * restrict stream); 

int main(void)
{

    c_fputs("Hello, world!\n", stdout);
}

int c_fputs(const char *restrict s, FILE * restrict stream) 
{
    int index = 0;
    while (s[index] != '\0' && s[index] != EOF){ 
        fputc(s[index++], stream);
    }

    if (ferror(stream)){
        fprintf(stderr, "Error writing to stream\n");
        return EOF;
    }

    return index;
}
