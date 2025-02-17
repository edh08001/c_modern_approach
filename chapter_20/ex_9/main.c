#include <stdio.h>

int count_ones(unsigned char ch);

int main(void)
{
    printf("There are %d ones in the binary representation of %d\n", count_ones(20), 20);
}

int count_ones(unsigned char ch)
{
    int count = 0, i;
    for (i = 0; i < sizeof(ch) * 8; i++)
        if ((ch >> i) & 1)
            count++;
    return count;
}
