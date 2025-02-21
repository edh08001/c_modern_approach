#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    FILE *fp;
    char str[1024];
    int count = 0;


    if (argc != 2) {
        printf("usage: canopen filename\n");
        exit (EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        printf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    } else {
        while (fgets(str, 1024, fp) != NULL)
            count++;
    }

    printf("There are %d lines in file %s\n", count, argv[1]);

    fclose(fp);
    return EXIT_SUCCESS;
}
