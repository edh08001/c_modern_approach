#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int day, month, year;
    char *months[13] = {"", 
                       "January",
                       "February",
                       "March",
                       "April",
                       "May",
                       "June",
                       "July",
                       "August",
                       "September",
                       "October",
                       "November",
                       "December"};

    if (argc == 2) {
        sscanf(argv[1], "%02d%*[-/]%d%*[-/]%4d", &month, &day, &year);
        fprintf(stdout, "%s %02d, %4d\n", months[month], day, year);
    } else {
        fprintf(stderr, "Please enter exactly one argument in the below formats:\nmm-dd-yyyy\nmm/dd/yyyy\n");
    }
    
    return EXIT_SUCCESS;
}
