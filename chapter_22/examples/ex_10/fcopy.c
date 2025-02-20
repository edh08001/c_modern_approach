#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp_1, *fp_2;

    if (argc != 3){
        printf("Please enter exactly 2 arguments.\n");
        exit(EXIT_FAILURE);
    }

    if ((fp_1 = fopen(argv[1], "rb")) == NULL){
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((fp_2 = fopen(argv[2], "wb")) == NULL){
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    char ch;
    while ((ch = fgetc(fp_1)) != EOF){
        if (fputc(ch, fp_2) == EOF){
            fprintf(stderr, "Error writing file\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(fp_1);
    fclose(fp_2);

    return 0;
}
