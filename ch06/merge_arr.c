#include <stdio.h>
#include <stdlib.h>

void mergeArr(int a[], int b[], int c[], int na, int nb, int nc) {
    int pa, pb, pc;
    pa = pb = pc = 0;

    while (pc < nc) {
        if (pa >= na || pb >= nb) {
            break;
        } else if (a[pa] < b[pb]) {
            c[pc++] = a[pa++];
        } else {
            c[pc++] = b[pb++];
        }
    }

    if (pa >= na) {
        while (pb < nb) {
            c[pc++] = b[pb++];
        }
    } else if (pb >= nb) {
        while (pa < na) {
            c[pc++] = a[pa++];
        }
    }

}

void mergeArr2(const int a[], const int b[], int c[], int na, int nb, int nc) {
    int pa, pb, pc;
    
    pa = pb = pc = 0;

    while (pc < nc) {
        while (pa < na && pb < nb) {
            c[pc++] = (a[pa] < b[pb]) ? a[pa++] : b[pb++];
        }

        while (pb < nb) {
            c[pc++] = b[pb++];
        }

        while (pa < na) {
            c[pc++] = a[pa++];
        }
    }
}

void main() {
    int i, na, nb, nc;
    int *a, *b;
    int *c;

    printf("Enter number of elements in A: ");
    scanf_s("%d", &na);

    printf("Enter number of elements in B: ");
    scanf_s("%d", &nb);

    nc = na + nb;

    a = (int*)calloc(na, sizeof(int));
    b = (int*)calloc(nb, sizeof(int));
    c = (int*)calloc(nc, sizeof(int));

    for(i = 0; i < na; i++) {
        printf("a[%d]: ", i);
        scanf_s("%d", &a[i]);
    }

    puts("");

    for(i = 0; i < nb; i++) {
        printf("b[%d]: ", i);
        scanf_s("%d", &b[i]);
    }

    puts("Array A");
    for(i = 0; i < na; i++) {
        printf("%d ", a[i]);
    }
    puts("");

    puts("Array B");
    for(i = 0; i < nb; i++) {
        printf("%d ", b[i]);
    }
    puts("");

    mergeArr(a, b, c, na, nb, nc);
    mergeArr2(a, b, c, na, nb, nc);

    puts("Merged Array C");
    for(i = 0; i < nc; i++) {
        printf("%d ", c[i]);
    }
    puts("");

    free(a);
    free(b);
    free(c);

}