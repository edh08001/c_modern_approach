#include <stdio.h>

unsigned short create_short(unsigned char high_byte,
                            unsigned char low_byte);

int main(void)
{
    printf("%d\n", create_short(0x09, 0x09));
}

unsigned short create_short(unsigned char high_byte,
                            unsigned char low_byte)
{
    return (high_byte << 8) + low_byte;
}
