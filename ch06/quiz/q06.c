// Bidirection buble sort

// {9, 1, 3, 4, 5, 6, 7, 8}
// 이 배열은 bubble3 알고리즘을 사용해도 빠른 시간 안에 정렬 작업을 마칠 수는 없습니다.
// 맨 앞 요소 9는 1회의 패스를 거치더라도 한칸만 뒤로 이동하기 때문이죠
// 그래서 홀수 번째의 패스는 가장 작은 요소를 맨 앞으로 옮기고, 
// 짝수 번째 패스는 가장 큰 요소를 맨 뒤로 옮기는 방식을 사용하면
// 이러한 정렬을 더 적은 횟수로 비교를 수행할 수 있습니다.
// 이러한 양방향 버블 정렬을 수행하는 프로그램을 작성하세요.

#include <stdio.h>
#include <stdlib.h>

void cocktailSort(int x[], int n) {
    int i, j;
    int temp;

    int odd, even, last;
    last = n - 1;
    even = n - 1;
    odd = 0;
    while (odd < even) {

        // 짝수 패스 - 가장 큰 요소를 맨 뒤로
        for (i = 0; i < even; i++) {
            if (x[i] > x[i + 1]) {
                temp = x[i];
                x[i] =x[i + 1];
                x[i + 1] = temp;
                last = i;
            }
        }
        even = last;
        
        // 홀수 패스 - 가장 작은 요소를 맨 앞으로
        for (i = n - 1; i > odd; i--) {
            if (x[i - 1] > x[i]) {
                temp = x[i];
                x[i] = x[i - 1];
                x[i - 1] = temp;
                last = i;
            }
        }
        odd = last;

        
    }

}

void main() {
    int i, nx;
    int *x;
    int cmp_cnt = 0, swap_cnt = 0;

    puts("Bubble Sort");
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

    cocktailSort(x, nx);

    puts("Ascending Sort");
    for(i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    free(x);
}