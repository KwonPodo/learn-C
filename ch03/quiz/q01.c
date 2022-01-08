#include <stdio.h>
#include <stdlib.h>

// 이진 검색

// 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 이진검색

int bin_search(const int a[], int n, int key);

void main() {
    int i, nx, ky, idx;
    int *x;

    puts("Binary Search");
    printf("Number of elements:");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    puts("오름차순으로 입력하세요.");
    printf("x[0]: ");
    scanf_s("%d", &x[0]);

    for (i = 1; i < nx; i++) {
        do {
            printf("Enter x[%d]: ", i);
            scanf_s("%d", &x[i]);
        } while (x[i] < x[i - 1]);
    }

    printf("Searching for?: ");
    scanf_s("%d", &ky);

    idx = bin_search(x, nx, ky);

    idx == -1 ? printf("Searching for %d failed\n", ky) : printf("%d is in x[%d]\n", x[idx], idx);

    free(x);
}

int bin_search(const int a[], int n, int key) {
    int i;
    int pl, pc, pr;
    pl = 0;
    pr = n - 1;
    pc = (pl + pr) / 2;

    for (i = 0; pl <= pr; i++) {
        if (key < a[pc]) {
            pr = pc - 1;
            pc = (pl + pr) / 2;
        } else if (key > a[pc]) {
            pl = pc + 1;
            pc = (pr + pl) / 2;
        } else {
            return pc;
        }
    }

    return -1;
}