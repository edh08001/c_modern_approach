#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int item, day, month, year;
    double price;
    FILE *fp;

    fp = fopen("dates.dat", "r");

    fprintf(stdout, "Item             Unit Price             Purchase Date\n");

    while (fscanf(fp, "%d,%lf,%02d/%02d/%04d", &item, &price, &month, &day, &year) == 1){
        fprintf(stdout, "%d %17.2lf%10d/%d/%d\n", item, price, month, day, year);
    }
    return EXIT_SUCCESS;
}
