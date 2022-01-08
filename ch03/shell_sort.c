#include <stdio.h>
#include <stdlib.h>

void shell(int a[], int n) {
    int h, i, j;
    
    for (h = n / 2; h > 0; h /= 2) {
        for (i = h; i < n; i++) {
            // 현재 삽입될 요소인 i번째 정수를 tmp변수로 복사
            int tmp = a[i];

            // 현재 정렬된 배열은 i - h까지이므로 i - h번째부터 역순으로 조사한다.
            // j 값은 i이상이어야 하고
            // tmp 값보다 정렬된 배열에 있는 값이 크면 j번째 요소를 j+h번째로 복사
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
                a[j + h] = a[j]; // 요소 복사, 이동
            }
            a[j + h] = tmp;
        }
    }
}

void main() {
    int i, nx;
    int *x;

    puts("Shell sort");
    printf("Enter number of elements: ");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    shell(x, nx);

    puts("Ascending sort");
    for (i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    free(x);
}