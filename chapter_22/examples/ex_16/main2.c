#include <stdio.h>
#include <stdlib.h>

#define RANK_LEN 20

int main(int argc, char *argv[])
{
    char *str = "a#1,045,011aldf";
    char rank[RANK_LEN];
    char group[5];
    int d[3], count;

    sscanf(str, str[0] == '#' ? "%*[#]%[0123456789,]" : "%*[^#]*[#]%[0123456789,]",
       rank);

    printf("%s\n", rank);
    return EXIT_SUCCESS;
}
