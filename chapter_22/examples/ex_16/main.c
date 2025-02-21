#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RANK_LEN 20

int main(int argc, char *argv[])
{
    char *str = "abcd1,456,789abd#1,145,011aldf";
    char rank[RANK_LEN];
    char group[5];
    int d[3], count;

    while (*str++ != '#')
        ;

    count = sscanf(str, "%d,%d,%d",&d[0], &d[1], &d[2]); 

    snprintf(rank, 4, "%d", d[0]);
    count--;

    for (int i = 1; count > 0; count--, i++){
        snprintf(group, 5, ",%03d", d[i]);

        strcat(rank, group);
    }

    printf("%s\n", rank);

    return EXIT_SUCCESS;
}
