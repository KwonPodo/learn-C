// 요소의 개수가 n인 배열 a에서 key와 일치하는 모든 요소의 인덱스를 배열 idx의 맨 앞부터 순서대로 저장하고,
// 일치한 요소의 개수를 반환하는 함수를 작성하세요.
// 예를 들어, 요소의 개수가 8인 배열 a의 요소가 {1, 9, 2, 9, 4, 6, 7, 9}이고 key가 9이면
// 배열 idx에 {1, 3, 7}을 저장하고 3을 반환합니다.

#include <stdio.h>
#include <stdlib.h>

int search_idx(const int a[], int n, int key, int idx[]);

void main() {
    int i, ky, nx;
    int *x, *idx;

    do {
        printf("Enter a number of elements (element > 0): ");
        scanf_s("%d", &nx);
    } while(nx <= 0);

    x = (int*)calloc(nx, sizeof(int));
    idx = (int*)calloc(nx, sizeof(nx));

    for(i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    printf("Searching for?: ");
    scanf_s("%d", &ky);

    search_idx(x, nx, ky, idx) == -1 ? printf("%d를 찾지 못했습니다.\n", ky) : printf("%d는 배열 x에 %d개 저장되어있습니다.\n", ky, search_idx(x, nx, ky, idx));
}

int search_idx(const int a[], int n, int key, int idx[]) {
    int i, cnt = 0;
    
    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            idx[cnt++] = a[i];
        }
    }

    return cnt == 0 ? -1 : cnt;
}