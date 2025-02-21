#include <stdio.h>

#define BLOCK_SIZE 64L

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("test.o", "rb");
    int n;

    //Navigate to beginning of file
    fseek(fp, n * BLOCK_SIZE, SEEK_SET);

    //Navigate to the last record on file
    fseek(fp, -BLOCK_SIZE, SEEK_END);

    //Move backward two records
    fseek(fp, -(BLOCK_SIZE * 2), SEEK_SET);

    //Move forward another record
    fseek(fp, BLOCK_SIZE, SEEK_CUR);
}
