#include <stdio.h>

int main(int argc, char *argv[])
{
    int widget = 2;

    printf(widget == 1 ? "%d widget\n" : "%d widgets\n", widget);
}
