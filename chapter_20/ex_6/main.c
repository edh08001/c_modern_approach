#include <stdio.h>

typedef unsigned char BYTE;

unsigned short swap_bytes(unsigned short i)
{
    BYTE j, k;
    j = i & 0xFF;
    k = i >> 8;
    
    return (unsigned short)(j << 8) ^ k;

}

unsigned short swap_bytes_b(unsigned short i)
{
    return (unsigned short)(i << 8) ^ (i >> 8);
}

int main(void)
{
    char ch;
    unsigned short i;

    printf("Enter a hexadecimal number (up to four digits): ");
    scanf("%hx", &i);

    printf("Number with bytes swapped: %hx\n", swap_bytes_b(i));
}
