#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define NUM_LEN 16

int main(int argc, char *argv[])
{
    char *num = malloc(NUM_LEN + 1);
    short area, first, last;
    if (num == NULL){
        fprintf(stderr, "Error allocating memory for number storage\n");
        exit(EXIT_FAILURE);
    }
    
    if (argc >= 2){
        fprintf(stderr, "Supply exactly one file name to the program\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen("numbers.txt", "r");
    if (fp == NULL){
        fprintf(stderr, "Error opening %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }


//This doesn't work for 100% of the cases. Would need to use a custom getc implemenation
    while ((num = fgets(num, NUM_LEN, fp)) != NULL){
        int i = 0; 
        if (strlen(num) == 11) {
           sscanf(num, "%3hd%3hd%4hd", &area, &first, &last);
       }else if(isdigit(num[0])) {
           sscanf(num, "%3hd%*[^0123456789]%3hd%*[^0123456789]%4hd", &area, &first, &last);
       } else {
           sscanf(num, "%*[-().]%3hd%*[-().]%3hd%*[-().]%4hd", &area, &first, &last);
       }

       fprintf(stdout, "(%03hd) %03hd-%04hd\n", area, first, last);
    }

    return EXIT_SUCCESS;
}
