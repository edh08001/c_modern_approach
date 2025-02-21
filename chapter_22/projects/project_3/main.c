#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;
    int i;

    if (argc < 2) {
        printf("usage: canopen filename\n");
        exit (EXIT_FAILURE);
    }

    for (i = 1; i < argc; i++){
        if ((fp = fopen(argv[i], "rb")) == NULL) {
            printf("%s can't be opened\n", argv[i]);
            exit(EXIT_FAILURE);
        } else {
            while ((ch = fgetc(fp)) != EOF)
                fputc(ch, stdout);
        }
    }

    fclose(fp);
    return 0;
}
