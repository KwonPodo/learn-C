// 버블 정렬의 구현
#include <stdio.h>
#include <stdlib.h>

void bubble(int* x, int n) {
    int i, j, temp;

    for (j = 0; j < n - 1; j++) {
        for (i = n - 1; i > j; i--) {
            if (x[i - 1] > x[i]) {
                temp = x[i];
                x[i] = x[i - 1];
                x[i - 1] = temp;
            }
        }
    }
}

void main() {
    int i, nx;
    int *x;

    puts("Bubble Sort");
    printf("Number of elements: ");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i ++) {
        printf("x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    puts("Given Array");
    for (i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    bubble(x, nx);

    puts("Ascending Sort");
    for(i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    free(x);
}