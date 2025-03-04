#include <stdio.h>
#include <stdlib.h>

#define MAX_HTM 1440

struct flight {
    int arr, dep;
};

int main(int argc, char *argv[])
{
    FILE *fp;
    struct flight flight_cur, flight_prev;
    int qh, qm, dh, dm, ah, am, tsm_q, tsm_cur, tsm_prev, tsm_c_diff, tsm_p_diff;
    tsm_p_diff = MAX_HTM;
    fp = fopen("flights.dat", "rb");
    if (fp == NULL){
        fprintf(stderr, "Error opening flights.dat\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Enter a departure time in hh:mm 24h format: ");
    fscanf(stdin, "%d:%d", &qh, &qm);
    tsm_q = qh * 60 + qm;


    while (fscanf(fp, "%d:%d %d:%d", &dh, &dm, &ah, &am) == 4){
        flight_cur.arr = ah * 60 + am;
        flight_cur.dep = dh * 60 + dm;
        tsm_c_diff = abs(flight_cur.dep - tsm_q);

        if (tsm_c_diff > tsm_p_diff)
            break;

        flight_prev = flight_cur;
        tsm_p_diff = tsm_c_diff;
    }
    
    fprintf(stdout, "depart: %02d:%02d arrive: %02d:%02d\n", 
            flight_prev.dep/60, flight_prev.dep%60,
            flight_prev.arr/60, flight_prev.arr%60); 

    fclose(fp);

    return EXIT_SUCCESS;
}
