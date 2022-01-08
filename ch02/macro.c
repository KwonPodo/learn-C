#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{ type t = x; x = y; y = t;} while(0)

void arr_reverse(int p[], int n) {
    int i;
    for (i = 0; i < n / 2; i++) {
        swap(int, p[i], p[n - 1 - i]);
    }


    puts("Reverse Array");
    for (i = 0; i < n; i++) {
        printf("p[%d]: %d\n", i, p[i]);
    }
}

int main() {
    int i;
    int *x;
    int nx;

    printf("Number of elements: ");
    scanf_s("%d", &nx);

    x = calloc(nx, sizeof(int));

    for(i = 0; i < nx; i++) {
        printf("Enter a number to insert in the array: ");
        scanf_s("%d", &x[i]);
    }

    arr_reverse(x, nx);
    free(x);

    return 0;
}