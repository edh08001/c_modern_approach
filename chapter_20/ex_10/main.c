#include <stdio.h>

unsigned int reverse_bits(unsigned int n);
void print_decimal(unsigned int n);

int main(void)
{
    unsigned int i;
    printf("Enter an integer: ");
    scanf("%d", &i);

    print_decimal(i);
    print_decimal(reverse_bits(i));
    printf("The number %d with bits reversed is %d.\n", i, reverse_bits(i));
}

unsigned int reverse_bits(unsigned int n)
{
    int hi = 31, lo = 0;
    unsigned int answer = 0;
    for (; lo < hi; lo++, hi--){
        answer ^= ((n & (1 << lo)) << (hi - lo));
        answer ^= ((n & (1 << hi)) >> (hi - lo));
    }

    return answer;
}


void print_decimal(unsigned int n)
{
    int i;
    for (i = 31; i >= 0; i--){
        printf("%d", (n & (1 << i)) ? 1 : 0);
    }
    printf("\n");
}
