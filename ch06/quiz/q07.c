/*
    요소의 교환 과정을 자세하게 출력할 수 있도록 단순 선택 정렬 프로그램을 수정하세요.
    정렬하지 않은 부분의 첫번째 요소 위에는 기호 *을, 
    정렬하지 않은 부분의 가장 작은 값의 요소 위에는 기호 +를 출력하세요.
*/

#include <stdio.h>
#include <stdlib.h>

void selection(int a[], int n) {
    int firstIdx;
    int minIdx;
    int i, temp;

    for (firstIdx = 0; firstIdx < n; firstIdx++) {
        minIdx = firstIdx;

        // finding smallest element's idx in unordered part of the array
        for (i = firstIdx; i < n; i++) {
            if (a[i] < a[minIdx]) {
                minIdx = i;
            }
        }

        // Print
        for (i = 0; i < n; i++) {
            if (i == firstIdx) printf("*\t");
            else if (i == minIdx) printf("+");
            else printf("\t");
        }
        puts("");

        for (i = 0; i < n; i++) {
            printf("%d\t", a[i]);
        }
        puts("");

        // Swap a[firstIdx] <=> a[minIdx]
        temp = a[minIdx];
        a[minIdx] = a[firstIdx];
        a[firstIdx] = temp;
    }
}

void main() {
    int i, nx;
    int *x;

    puts("Selection Sort");
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

    selection(x, nx);

    puts("Ascending Sort");
    for(i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    free(x);
}
