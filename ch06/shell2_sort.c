/*
    쉘 버전 2
    h = ..., 13, 4, 1
*/
#include <stdio.h>
#include <stdlib.h>

void shell(int a[], int n) {
    int i, j, h;

    // h의 초기값을 구한다.
    // 1부터 시작하여 값을 3배하고 1을 더하면서 n / 9를 넘지 않는 가장 큰 값을 h에 대입한다.
    for (h = 1; h < n / 9; h = h * 3 + 1);

    for (; h > 0; h /=3) {
        for(i = h; i < n; i++) {
            int tmp = a[i];
            for (j = i - h; j >= 0 && a[j] > tmp; j--) {
                a[j + h] = a[j];
            } 
            a[j + h] = tmp;
        }
    }
}

void main() {
    int i, nx;
    int *x;

    puts("Shell Sort2");
    printf("Number of elements: ");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++){
        printf("x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    shell(x, nx);

    puts("Ascending Sort");
    for(i = 0; i < nx; i++){
        printf("%d ", x[i]);
    }
    puts("");

    free(x);
}



