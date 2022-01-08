// 버블 정렬(버전2)를 연습문제 Q2처럼 비교, 교환 과정을 자세히 출력하는 프로그램으로 수정하세요
#include <stdio.h>
#include <stdlib.h>

void bubble2(int* x, int n, int *cmp, int *swap) {
    int i, j, k, temp;
    int cnt;

    for (j = 0; j < n - 1; j++) {
        cnt = 0;
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

        if (!cnt) break;
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

    bubble2(x, nx, &cmp_cnt, &swap_cnt);

    puts("Ascending Sort");
    for(i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    printf("Compared times: %d\n", cmp_cnt);
    printf("Swapped times: %d\n", swap_cnt);

    free(x);
}