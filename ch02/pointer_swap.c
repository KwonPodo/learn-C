#include <stdio.h>
#include <stdlib.h>


void swap(int ** fdp, int ** sdp) {
    int * temp;
    temp = *fdp;
    *fdp = *sdp;
    *sdp = temp;
}

void main() {
    int a = 10, b = 9;
    int * fp = &a;
    int * sp = &b;

    printf("Before swap, *fp: %d, *sp: %d\n", *fp, *sp);
    swap(&fp, &sp);
    printf("After swap, *fp: %d, *sp: %d\n", *fp, *sp);
}

