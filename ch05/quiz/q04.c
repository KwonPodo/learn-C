// 상향식 분석과 하향식 분석

/**
 * 상향식 분석
 *                                       출력
 * recur2(1) : recur2(-1) 1 recur2(0) => 1
 * recur2(2) : recur2(0) 2 recur2(1)  => 2 1
 * recur2(3) : recur2(1) 3 recur2(2)  => 1 3 2 1
 * recur2(4) : recur2(2) 4 recur2(3)  => 2 1 4 1 3 2 1 
 */
#include <stdio.h>
#include <stdlib.h>

void recur2(int n) {
    if (n > 0) {
        recur2(n - 2);
        printf("%d\n", n);
        recur2(n - 1);
    }
}

void main() {
    int n;

    printf("Enter a number : ");
    scanf_s("%d", &n);

    recur2(n);
}