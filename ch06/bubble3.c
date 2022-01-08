// 각각의 패스에서 비교, 교환을 하다가 어떤 시점 이후에 교환이 수행되지 않는다면,
// 그보다 앞쪽의 요소는 이미 정렬을 마친 상태라고 생각해도 좋다.
// => 패스 내부의 멈춤 도입
#include <stdio.h>
#include <stdlib.h>

void bubble3(int a[], int n) {
    int i, j;
    int temp;
    int last;

    for (i = 0; i < n - 1; i++) {
        last = n - 1;
        for (j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;

                last = j;
            }
        }
        i = last;
    }
}

void bubble3_while(int a[], int n) {
    int i, j;
    int temp;
    int last;

    i = 0;
    while (i < n - 1) {
        last = n - 1;
        for (j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;

                last = j;
            }
        }

        i = last;
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

    bubble3(x, nx);

    puts("Ascending Sort");
    for(i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    free(x);
}