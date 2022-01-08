#include <stdio.h>
#include <stdlib.h>

// 선형 검색

// 요소의 개수가 n인 배열 a에서 key와 일치하는지 선형검색 + 스캐닝 과정 상세 표시

int linear_search(const int a[], int n, int key);

void main() {
    int i, nx, ky, idx;
    int *x;

    puts("Linear Search");
    printf("Number of elements:");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        printf("Enter x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    printf("Searching for?: ");
    scanf_s("%d", &ky);

    idx = linear_search(x, nx, ky);

    idx == -1 ? printf("Searching for %d failed\n", ky) : printf("%d is in x[%d]\n", x[idx], idx);

    free(x);
}

int linear_search(const int a[], int n, int key) {
    int i, j;

    printf("   |");
    for(i = 0; i < n; i++) {
        printf("  %d", i);
    }
    puts("");
    printf("---+");
    for (i = 0; i < n; i++) {
        printf("---");
    }
    puts("");

    for (i = 0; i < n; i++) {

        printf("   |");
        for(j = 0; j <= i; j++) {
            j == 0 ? printf("  ") : printf("   ");
        }
        printf("*");
        puts("");

        printf("  %d|", i);
        for (j = 0; j < n; j++) {
            printf("  %d", a[j]);
        }
        puts("");


        if (a[i] == key) return i;
    }

    return -1;
}