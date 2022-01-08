// 선형 검색
#include <stdio.h>
#include <stdlib.h>

// 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 선형 검색
int search(const int a[], int n, int key);

int main(void) {
    int i, nx, ky, idx;
    int *x;
    puts("선형검색");
    printf("요소 개수: ");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf_s("%d", &x[i]);
    }

    printf("검색값: ");
    scanf_s("%d", &ky);

    idx = search(x, nx, ky);
    if(idx == -1) puts("검색에 실패했습니다.");
    else printf("%d는 x[%d]에 있습니다.\n", ky, idx);

    free(x);
}

int search(const int a[], int n, int key) {
    int i = 0;

    while (1) {
        if (i == n) {
            break;
        }

        if (a[i] == key)
            return i;
        
        i++;
    }

    // for (i = 0; i < n; i++) {
    //     if(a[i] == key)
    //         return i;
    // }

    return -1;
}