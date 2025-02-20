#include <stdio.h>

int count_periods(const char *filename)
{
    FILE *fp;
    int n = 0;
    char ch;

    if ((fp = fopen(filename, "r")) != NULL) {
        while ((ch = fgetc(fp)) != EOF)
            if (ch == '.')
                n++;
        fclose(fp);
    }
    return n;
}

int main(int argc, char *argv[])
{
    
    int n;
    n = count_periods(argv[1]);
    
    printf("There are %d periods in %s.\n", n, argv[1]);
    
    return 0;
}
