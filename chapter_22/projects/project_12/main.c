#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int item, day, month, year;
    double price;
    FILE *fp;

    fp = fopen("dates.dat", "r");

    fprintf(stdout, "Item             Unit Price             Purchase Date\n");

    while (fscanf(fp, "%d,%lf,%02d/%02d/%04d", &item, &price, &month, &day, &year) == 5){
        fprintf(stdout, "%-16d $%7.2lf%17.2d/%02d/%02d\n", item, price, month, day, year);
    }
    return EXIT_SUCCESS;
}
