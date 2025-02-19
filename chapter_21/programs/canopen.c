#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2){
        printf("Error, invalid number of arguments passed. Please provide exactly one file.\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    if ((fp = fopen(argv[1], "r")) == NULL)
        printf("Error, file provided cannot be opened\n");
    else
        printf("File can be opened successfully\n");

    fclose(fp);

    return 0;
}
