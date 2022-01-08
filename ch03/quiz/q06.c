#include <stdio.h>
#include <stdlib.h>

int cmp_longr(long * a, long * b);

void main() {
    long ky;
    int nx, retry, i = 1;
    long *x, *p;

    do {
        printf("Enter number of elements: ");
        scanf_s("%ld", &nx);
    } while (nx <= 0);

    x = calloc(nx, sizeof(long));

    puts("Enter elements");
    printf("x[0]: ");
    scanf_s("%ld", &x[0]);

    for(i; i < nx; i++) {
        do {
            printf("x[%d]: ", i);
            scanf_s("%ld", &x[i]);
        } while (x[i - 1] < x[i]);
    }

    printf("Searching for?: ");
    scanf_s("%ld", &ky);

    p = bsearch(&ky, x, nx, sizeof(long), (int(*)(const void *, const void *)) cmp_longr);

    if (p == NULL)
        puts("Search failed...");
    else {
        printf("%ld is at x[%d]\n", ky, (int)(p - x));
    }

    free(x);
}

int cmp_longr(long *a, long *b) {
    if (*a < *b) 
        return 1;
    else if (*a > *b) 
        return -1;
    else 
        return 0;
}