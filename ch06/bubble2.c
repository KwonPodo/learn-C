// 개선된 버블 정렬 알고리즘
// 어떤 패스에서 요소 교환 횟수가 0이라면,
// 그 이전패스에서 배열이 정렬을 마쳤다고 볼 수 있다.
// => 패스 단위의 멈춤 도입

#include <stdio.h>
#include <stdlib.h>


void bubble2(int* x, int n) {
    int i, j, temp;

    for (j = 0; j < n - 1; j++) {
        int cnt = 0;
        for (i = n - 1; i > j; i--) {
            if (x[i - 1] > x[i]) {
                temp = x[i];
                x[i] = x[i - 1];
                x[i - 1] = temp;
                cnt++;
            }
        }
        if (!cnt) break;
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

    bubble2(x, nx);

    puts("Ascending Sort");
    for(i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    free(x);
}