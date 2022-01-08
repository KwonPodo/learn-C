/**
 * 단순 삽입 정렬은 배열의 요소 개수가 많아지면 많아질수록 
 * 요소 삽입에 필요한 비교, 대입 비용이 무시할 수 없을 정도로 커진다.
 * 이때 배열에서 이미 정렬된 부분은 이진 검색을 사용할 수 있기 때문에 삽입할 위치를 더 빨리 찾을 수 있다.
 * 이진 검색을 사용하여 프로그램을 수정하라
 */

// 정렬되지 않은 부분의 첫 요소를 정렬된 부분의 알맞은 위치에 삽입하는 것
// => 정렬된 부분의 알맞은 위치를 이진 탐색으로 찾으면 훨씬 빠르게 탐색할 수 있다.

#include <stdio.h>
#include <stdlib.h>



int binary_search(int a[], int n, int key) {
    int l, c, r, i;
    l = 0;
    r = n - 1;
    c = (l + r) / 2;

    while (l <= r) {
        if (a[c] > key) {
            r = c - 1;
            c = (l + r) / 2;
        } else if (a[c] < key) {
            l = c + 1;
            c = (l + r) / 2;
        } else {
            return c + 1;
        }
    }
    
    if (l > r) return l;
}

void insertion(int a[], int n) {
    int i, j, temp;

    for (i = 1; i < n; i++) {
        temp = a[i];

        int index = binary_search(a, i, temp);
        for (j = i; j > index; j--) {
            a[j] = a[j - 1];
        }
        a[index] = temp;
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

    insertion(x, nx);

    printf("Sorted Array\n");
    for (i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    free(x);
}