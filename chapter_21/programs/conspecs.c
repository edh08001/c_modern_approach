#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    char ch, mv;
    printf("Enter a char in decimal: ");
    scanf("%2hhd", &ch);

    while ((mv = getchar()) != '\n')
        ;

    // scanf("%*[^\n]"), getchar(); //A weird but workable way to get to the next line

    char str[100];
    printf("Enter a string. Will cancel if any chars in 'abc' are found: ");
    scanf("%[^abc]", str); 

    printf("%hhd\n", ch);
    printf("%s\n", str);
    return 0;
}
