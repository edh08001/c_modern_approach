#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char ch;
    FILE *fp;

    if (argc != 2){
        fprintf(stderr, "Enter only one file name");
        exit(EXIT_FAILURE);
    } else {
        fp = fopen(argv[1], "r");
    }

    while ((ch = fgetc(fp)) != EOF)
        fputc(toupper(ch), stdout);

    return EXIT_SUCCESS;
}
