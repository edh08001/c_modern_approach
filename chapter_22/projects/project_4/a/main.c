#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    FILE *fp;
    char ch;
    int count = 0;

    if (argc != 2) {
        printf("usage: canopen filename\n");
        exit (EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        printf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    } else {
        while ((ch = fgetc(fp)) != EOF)
            count++;
    }

    printf("There are %d chars in file %s\n", count, argv[1]);

    fclose(fp);
    return EXIT_SUCCESS;
}
