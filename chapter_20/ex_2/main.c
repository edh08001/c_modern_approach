#include <stdio.h>

int main(void)
{
    unsigned short i, j;
    i = 8; j = 1;
    printf("%d\n", i ^ (j << 3));
}
