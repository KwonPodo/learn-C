// 버블 정렬(버전2)의 아이디어는 배열이 정렬을 마쳤는지를 검사하는데에 응용할 수 있다.
// 전달받은 배열 a가 오름차순으로 정렬을 마쳤는지 검사하는 함수를 작성하세요.
// 이때 오름차순으로 정렬을 마친상태라면 1, 그렇지 않으면 0을 반환하도록 작성하세요.

#include <stdio.h>
#include <stdlib.h>

void main() {
    int i, nx;
    int *x;

    printf("Enter number of elements: ");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf_s("%d", &x[i]);
    }
    puts("");

    printf("Received Array: ");
    for (i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    is_sorted(x, nx) ? printf("Sorted!\n") : printf("Not Sorted..\n");
}

int is_sorted(const int a[], int n) {
    int i;

    for (i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return 0;
        }
    }

    return 1;
}

void bubble2(int* x, int n) {
    int i, j, temp;

    for (j = 0; j < n - 1; j++) {
        int cnt = 0;
        for (i = n - 1; i > j; i--) {
            if (x[i - 1] > x[i]) {
                temp = x[i];
                x[i] = x[i - 1];
                x[i - 1] = temp;
                cnt++;
            }
        }
        if (!cnt) break;
    }
}