// 비교, 교환 과정을 자세히 출력하면서 버블 정렬하는 프로그램을 작성하세요.
// 비교하는 두 요소 사이에 교환을 수행하면 '+', 수행하지 않으면 '-'를 출력하고
// 정렬을 마치면 비교횟수와 교환 횟수를 출력하세요
#include <stdio.h>
#include <stdlib.h>

void bubble(int* x, int n, int *cmp, int *swap) {
    int i, j, k, temp;

    for (j = 0; j < n - 1; j++) {
        printf("Pass %d:\n", j + 1);
        for (i = n - 1; i > j; i--) {

            for (k = 0; k < n; k++) {
                if (k == i) {
                    if (x[k - 1] > x[k]) {
                        printf("   +");
                    } else {
                        printf("   -");
                    }
                }
                printf("\t%d", x[k]);
            }
            puts("");

            if (x[i - 1] > x[i]) {
                temp = x[i];
                x[i] = x[i - 1];
                x[i - 1] = temp;
                (*swap)++;
            }
            (*cmp)++;
        }
    }
}

void main() {
    int i, nx;
    int *x;
    int cmp_cnt = 0, swap_cnt = 0;

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

    bubble(x, nx, &cmp_cnt, &swap_cnt);

    puts("Ascending Sort");
    for(i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    printf("Compared times: %d\n", cmp_cnt);
    printf("Swapped times: %d\n", swap_cnt);

    free(x);
}