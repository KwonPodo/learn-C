/* 
    단순 삽입 정렬에서 배열의 첫 번째 요소 a[0]부터 데이터를 저장하지 않고
    a[1]부터 데이터를 저장하면 a[0]를 보초로 하여 삽입을 마치는 조건을 줄일 수 있습니다.
*/

// Sentinel Straight Insertion Sort
#include <stdio.h>
#include <stdlib.h>

void sentinel_Insertion(int a[], int n) {
    int temp, i, j;

    for (i = 1; i < n; i++) {
        temp = a[0] = a[i];
        for (j = i; a[j - 1] > temp; j--) {
            a[j] = a[j - 1];
        }
        a[j]= temp;
    }
}

void main() {
    int i, nx;
    int *x;

    puts("Sentinel Insertion Sort");
    printf("Number of elements: ");
    scanf_s("%d", &nx);

    // Sentinel Method를 사용하기 위해 +1로 동적할당
    x = (int*)calloc(nx + 1, sizeof(int));

    for (i = 1; i < nx; i ++) {
        printf("x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    puts("Given Array");
    for (i = 1; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    sentinel_Insertion(x, nx);

    puts("Ascending Sort");
    for(i = 1; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    free(x);
}