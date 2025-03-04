#include <stdlib.h>
#include <stdio.h>

#define BLOCK 512

int main(int argc, char *argv[])
{
    FILE *fp_1, *fp_2;
    char arr[512];
    long sz, count, pos = 0;

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

    fseek(fp_1, 0L, SEEK_END);
    sz = ftell(fp_1);
    rewind(fp_1);

    while ((count = fread(arr, sz < BLOCK ? sz : BLOCK, 1, fp_1)) > 0){
        fwrite(arr, sz < BLOCK ? sz : BLOCK, 1, fp_2);
        pos += BLOCK;
    }

    fread(arr, sz - pos, 1, fp_1);
    fwrite(arr, sz - pos, 1, fp_2);

    fclose(fp_1);
    fclose(fp_2);

    return 0;
}
