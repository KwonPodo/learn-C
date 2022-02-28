#include <stdio.h>
#include <stdbool.h>

int main() {
    int a[7] = {0};
    a[6] |= 1 << 2;

    unsigned int b = 0;
    b |= 1 << 2;

    bool c[5] = {1};
    c[3] |= 1;

    int d = 1 << 0;

    int h = 5;
    int *x = &h;
    *x++ = 6;

}