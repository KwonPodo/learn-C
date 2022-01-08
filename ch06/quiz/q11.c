/* 
    q10 처럼 이진 탐색을 통해 삽입할 위치를 찾는 방식은 검색은 빠르지만 삽입을 위해 요소를 하나씩 뒤쪽으로 
    미는 작업 비용이 단순 삽입 정렬 알고리즘과 같다.
    이러한 작업을 memmove함수를 사용해서 구현하면 비용을 줄여 좀 더 빠른 속도를 얻을 수 있다.
    이를 바탕으로 이진 삽입 정렬 함수를 수정하라
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bin_search(const int a[], int n, int key) {
    int l, c, r;
    l = 0;
    r = n - 1;
    c = (l + r) / 2;

    while (l <= r) {
        if (a[c] < key) {
            l = c + 1;
            c = (l + r) / 2;
        } else if (a[c] > key) {
            r = c - 1;
            c = (l + r) / 2;
        } else {
            return c + 1;
        }
    }
    if (l > r) {
        return l;
    }
}

void bin_insertion(int a[], int n) {
    int i, j, temp;
    int idx;

    for (i = 1; i < n; i++) {
        temp = a[i];
        idx = bin_search(a, i, temp);
        memmove(&a[idx + 1], &a[idx], (i - idx) * sizeof(int));
        a[idx] = temp;
    }
}

void main() {
    int i, nx;
    int *x;

    puts("Straight Insertion Sort");

    printf("Number of elements: ");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    printf("Given Array\n");
    for (i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    bin_insertion(x, nx);

    printf("Sorted Array\n");
    for (i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    free(x);
}