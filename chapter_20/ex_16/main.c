#include <stdio.h>

typedef unsigned int DWORD;
typedef short WORD;
typedef char BYTE;

union {
    struct {
        DWORD eax, ebx, ecx, edx;
    } dword;
    struct {
        WORD axl, dax, bxl, dbx, cxl, cbx, dxl, ddx;
    } word;
    struct {
        BYTE al, ah, dal, dah, bl, bh, dbl, dbh, cl, ch, dcl, dch, dl, dh, ddl, ddh;
    } byte;
} regs;

void print_decimal(unsigned int n)
{
    int i;
    for (i = 31; i >= 0; i--){
        printf("%d", (n & (1 << i)) ? 1 : 0);
    }
    printf("\n");
}

int main(void)
{
    regs.dword.eax = 0x12345678;

    //regs.byte.ah = 0x12;
    //regs.byte.al = 0x34;

    printf("AH: %hx\n", regs.byte.ah);

    print_decimal(regs.dword.eax);
    print_decimal(regs.word.axl);
    print_decimal(regs.word.dax);
    print_decimal(regs.byte.dal);
    print_decimal(regs.byte.dah);

}
