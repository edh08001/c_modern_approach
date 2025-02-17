#include <stdio.h>

#define INT_BITS 32

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

int main(void)
{
    unsigned int i, j;

    printf("Enter a 32-bit (8 digit) hex number: ");
    scanf("%x", &i);
    printf("Enter amount to shift by: ");
    scanf("%d", &j);

    printf("%x rotated left by %d places is %x\n", i, j, rotate_left(i, j)); 
    printf("%x rotated right by %d places is %x\n", i, j, rotate_right(i, j)); 
}

unsigned int rotate_left(unsigned int i, int n)
{
    return((i << n) ^ (i >> (INT_BITS - n)));  
}

unsigned int rotate_right(unsigned int i, int n)
{
    return((i >> n) ^ (i << (INT_BITS - n)));
}
