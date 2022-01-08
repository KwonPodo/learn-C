/**
 * 단순 삽입 정렬 (Straight Insertion Sort)
 * 
 * : 정렬되지 않은 부분의 첫 요소를 정렬된 부분의 알맞은 위치에 삽입하는 정렬 알고리즘
 * 
 * 1. 두 번째 자료부터 시작해서 그 앞의 자료들과 비교 후, 삽입할 위치를 지정
 * 2. 지정한 위치에 삽입하기 위해 자료들을 한 칸씩 뒤로 옮긴 후 삽입한다.
 * 3. 이를 n = 1 -> n - 1까지 반복하여 정렬한다.
 */

#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n) {
    int chosenIdx, compare_sortedIdx, temp;

    for (chosenIdx = 1; chosenIdx < n; chosenIdx++) {
        temp = a[chosenIdx];
        
        for (compare_sortedIdx = chosenIdx; compare_sortedIdx > 0 && a[compare_sortedIdx - 1] > temp; compare_sortedIdx--) {
            a[compare_sortedIdx] = a[compare_sortedIdx - 1];
        }
        a[compare_sortedIdx] = temp;
    }
}

void insertion2(int a[], int n) {
    int i, j, temp;

    for (i = 1; i < n; i++) {
        temp = a[i];

        for (j = i; j > 0 && a[j - 1] > temp; j--) {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
}

void insertion3(int a[], int n) {
    int i, j, temp;

    for (i = 0; i < n; i++) {
        temp = a[i];

        j = i - 1;
        while(j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--; 
        }
        a[j] = temp;
    }
}

void insertion4(int a[], int n) {
    int i, j, temp;

    // 인덱스 0은 이미 정렬된 것으로 보고 시작한다.
    for (i = 1; i < n; i++) {
        temp = a[i]; // 삽입될 숫자인 i번째 정수를 temp 변수로 복사

        // 현재 i - 1까지만 정렬되었다고 보고, i - 1 부터 역순으로 조사, 비교한다.
        // j 값은 음수가 아니어야하며
        // temp 값보다 정렬된 배열에 있는 값이 크면 j번째 요소를 j + 1번째로 이동시킨다.
        for (j = i - 1; j >=0 && a[j] > temp; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

void main() {
    int i, nx;
    int *x;

    puts("Straight Insertion Sort");

    printf("Number of elements: ");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    printf("Given Array\n");
    for (i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    insertion(x, nx);

    printf("Sorted Array\n");
    for (i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    free(x);
}