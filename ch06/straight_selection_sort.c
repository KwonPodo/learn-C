// 단순 선택 정렬 (Straight Selection Sort)
// 가장 작은 요소부터 선택해 알맞은 위치로 옮겨서 순서대로 정렬하는 알고리즘

// 1. 아직 정렬하지 않은 부분의 배열의 시작점을 firstIdx로 지정
// 2. 아직 정렬하지 않은 부분에서 가장 작은 키의 값 smallestIdx를 찾고,
// 3. 아직 정렬하지 않은 부분의 시작점과 해당 값을 교환한다.

#include <stdio.h>
#include <stdlib.h>

void selection(int a[], int n) {
    int i, smallestIdx, firstIdx;
    int temp;


    for (firstIdx = 0; firstIdx < n; firstIdx++) {
        smallestIdx = firstIdx;
        for (i = firstIdx; i < n; i++) {
            if (a[i] < a[smallestIdx]) {
                smallestIdx = i;
            }
        }

        // Swap
        temp = a[smallestIdx];
        a[smallestIdx] = a[firstIdx];
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