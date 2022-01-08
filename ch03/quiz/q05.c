// 지금까지 살펴본 이진 검색 알고리즘은 검색할 값 key와 같은 값을 갖는 요소가 
// 하나 이상일 경우, 그 요소 중에서 맨 앞의 요소를 찾지 못한다.
// 이진 탐색으로 검색에 성공했을 때, 그 위치로부터 앞쪽으로 하나씩 검사하면 여러개의 같은 요소가 있을때에도
// 가장 앞쪽에 위치한 요소의 인덱스를 찾아낼 수 있다.

#include <stdio.h>
#include <stdlib.h>

int bin_search2(const int a[], int n, int key);

void main() {
    int i, idx, nx, ky;
    int *x;

    do {
        printf("Enter number of the elements: ");
        scanf_s("%d", &nx);
    } while (nx < 0);

    x = (int*)calloc(nx, sizeof(int));

    printf("Enter x[0]: ");
    scanf_s("%d", &x[0]);

    for(i = 1; i < nx; i++) {
        do {
            printf("Enter x[%d](must be same or bigger than %d): ", i, x[i - 1]);
            scanf_s("%d", &x[i]);
        } while (x[i] < x[i - 1]);
    }

    printf("Searching for?: ");
    scanf_s("%d", &ky);

    idx = bin_search2(x, nx, ky);

    idx == -1 ? printf("%d is not in the given array\n", ky) : printf("%d is at x[%d].\n", ky, idx);

    free(x);
}

int bin_search2(const int a[], int n, int key) {
    int i, pl, pc, pr, idx;
    pr = n - 1;
    pl = 0;
    pc = (pl + pr) / 2;

    while (pl <= pr) {
        if (a[pc] < key) {
            pl = pc + 1;
            pc = (pl + pr) / 2;
        } else if (a[pc] > key) {
            pr = pc - 1;
            pc = (pl + pr) / 2;
        } else {
            idx = pc;

            for(i = pc - 1; i >= 0; i--) {
                if (a[i] == key) {
                    idx = i;
                }
            }

            return idx;
        }
    }

    return -1;
}