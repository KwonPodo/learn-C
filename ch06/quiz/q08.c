/*
    요소의 삽입 과정을 자세하게 출력할 수 있도록 단순 삽입 정렬 프로그램을 수정하세요.
    현재 선택한 요소 아래에 기호 +,
    삽입하는 위치의 요소 아래에 기호 ^,
    그 사이에 기호 -를 출력하세요.
    삽입하지 않는 (요소의 이동이 필요 없는) 경우에는 선택한 요소 아래에 +만 출력하면 됩니다.
*/
#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n) {
    int chosenIdx, compare_sortedIdx, temp;
    int i, j;

    for (chosenIdx = 1; chosenIdx < n; chosenIdx++) {
        temp = a[chosenIdx];

        // Print
        for (i = 0; i < n; i++) {
            printf("%d\t", a[i]);
        }
        puts("");

        for (i = 0; i < n; i++) {
            if (i == compare_sortedIdx) {
                printf("^");  
                for (j = compare_sortedIdx; j < chosenIdx; j++) {
                    printf("----");
                }
            } 
            if (i == chosenIdx) printf("+\t");
        }
        puts("");
        
        for (compare_sortedIdx = chosenIdx; compare_sortedIdx > 0 && a[compare_sortedIdx - 1] > temp; compare_sortedIdx--) {
            a[compare_sortedIdx] = a[compare_sortedIdx - 1];
        }
        a[compare_sortedIdx] = temp;
    }
}

void main() {
    int i, nx;
    int *x;

    puts("Selection Sort");
    printf("Number of elements: ");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i ++) {
        printf("x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    puts("Given Array");
    for (i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    insertion(x, nx);

    puts("Ascending Sort");
    for(i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    free(x);
}