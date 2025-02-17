#include <stdio.h>

typedef unsigned char BYTE;

#define MK_COLOR(r,g,b) (unsigned long)(((r) ^ ((g) << 8)) ^ ((b) << 16))
#define GET_RED(c) (BYTE)((c) & (0xFF))
#define GET_GREEN(c) (BYTE)(((c) >> 8) & 0xFF)
#define GET_BLUE(c) (BYTE)(((c) >> 16) & 0xFF)


int main(void)
{
    unsigned long i;
    i = MK_COLOR(1, 255, 255);

    printf("%lu\n", i);

    printf("Red: %d\n", GET_RED(i));
    printf("Green: %d\n", GET_GREEN(i));
    printf("Blue: %d\n", GET_BLUE(i));
}
