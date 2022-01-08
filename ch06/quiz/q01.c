// 버블 정렬의 각 패스에서 비교, 교환은 처음(왼쪽)부터 수행해도 됩니다.
// (각 패스에서 가장 큰 값의 요소가 끝으로 옮겨집니다)
// 그렇게 수정한 프로그램을 작성하세요.

#include <stdio.h>
#include <stdlib.h>

void bubbleSortLeft(int *x, int n);

void main() {
    int i, nx;
    int *x;

    puts("Bubble Sort Starting from the left");

    printf("Enter number of the elements: ");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    printf("Enter Element\n");
    for (i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    printf("Given Array: ");
    for(i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    bubbleSortLeft(x, nx);

    printf("Sorted Array: ");
    for(i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    free(x);

}

void bubbleSortLeft(int *x, int n) {
    int i, j, temp;

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (x[j] > x[j + 1]) {
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }
}