// 배열 b의 모든 요소를 배열 a에 복사하는 함수를 작성하시오.(n은 요소 개수)
#include <stdio.h>
#include <stdlib.h>

void ary_copy(int a[], const int b[], int n);

void main(void) {
    const int b[] = {1,2,3,4,5,6};
    int len = sizeof(b) / sizeof(b[0]);
    int i;

    int *a = calloc(len, sizeof(int));

    ary_copy(a, b, len);

    puts("Printing array a");
    for (i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }

    free(a);
}

void ary_copy(int a[], const int b[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        a[i] = b[i];
    }
}