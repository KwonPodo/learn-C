#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

// while문을 빠져나올땐 항상 left == right이기 때문에 이 값을 기준으로 왼쪽은 미만, 오른쪽은 초과이다.

void partition(int a[], int n) {
    int i, t;
    int left = 0;
    int right = n - 1;
    int pivot = a[n / 2];

    while (left < right) {
        while (a[left] < pivot) left++;
        while (a[right] > pivot) right--;

        if (left < right) {
            t = a[left];
            a[left] = a[right];
            a[right] = t;
        }
    }
}

// l, r 교차시 과정 끝나는 파티션
void partition2(int a[], int n) {
    int i, t;
    int left = 0;
    int right = n - 1;
    int pivot = a[n / 2];

    while (left <= right) {
        while (a[left] < pivot) left++;
        while (a[right] > pivot) right--;

        if (left <= right) {
            t = a[left];
            a[left] = a[right];
            a[right] = t;

            // left++, right--을 넣지 않으면 무한루프에 빠진다.
            left++; 
            right--;
        }
    }
    // while문 종료시 l과 r이 교차된 이후이다
    // 피벗 값 이하의 범위 : 0 ~ l - 1
    // 피벗 값 이상의 범위 : r + 1 ~ n - 1
}

void main() {
    int i, nx;
    int *x;

    puts("배열을 나눈다.");
    printf("Number of elements: ");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++){
        printf("x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    partition2(x, nx);


    for (i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");
    free(x);
}