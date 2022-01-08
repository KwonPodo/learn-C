// 연습문제 Q2와 마찬가지로 비교, 교환 과정을 자세히 출력하는 프로그램으로 수정하세요.

#include <stdio.h>
#include <stdlib.h>

void bubble3(int x[], int n) {
    int i, j, temp;
    int last;

    i = 0;
    while (i < n - 1) {
        last = n - 1;
        
        printf("Pass %d:\n", i + 1);

        for (j = n - 1; j > i; j--) {

            for (int k = 0; k < n; k++) {
                if (k == j) {
                    x[k - 1] > x[k] ? printf("   +") : printf("   -");
                }
                printf("\t%d", x[k]);
            }
            puts("");


            if (x[j - 1] > x [j]) {
                temp = x[j];
                x[j] = x[j - 1];
                x[j - 1] = temp;

                last = j;
            }
        }

        i = last;
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

    bubble3(x, nx);

    puts("Ascending Sort");
    for(i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    free(x);
}