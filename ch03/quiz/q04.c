// 이진 탐색의 과정을 자세히 출력하는 프로그램을 작성하세요. 각 행의 맨 왼쪽에 현재 검색하고 있는 요소의 인덱스를 출력하고,
// 검색 범위의 맨 앞 요소 위에 <-, 맨 끝 요소 위에 ->, 현재 검색하고 있는 중앙 요소 위에 +를 출력하세요ㅣ.

#include <stdio.h>
#include <stdlib.h>

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
    printf("Enter x[0]: ");
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
    int pl, pc, pr, i, j;
    pl = 0;
    pr = n - 1;
    pc = (pl + pr) / 2;

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



    while(pl <= pr) {
        printf("   |");

        for(j = 0; j <= pl; j++) {
            j == pl ? printf(" <-") : printf("   ");
        }
        for(j; j <= pc; j++) {
            j == pc ? printf("  +") : printf("   "); 
        }
        for(j; j <= pr; j++) {
            j == pr ? printf(" ->") : printf("   ");
        }
        puts("");

        printf("   |");
        for (i = 0; i < n; i++) {
            printf("  %d", a[i]);
        }
        puts("");

        if (a[pc] < key) {
            pl = pc + 1;
            pc = (pl + pr) / 2;
        } else if (a[pc] > key) {
            pr = pc - 1;
            pc = (pl + pr) / 2;
        } else {
            return pc;
        }
    }
    return -1;
}