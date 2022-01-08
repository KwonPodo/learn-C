// 키의 합계를 구하는 프로그램을 작성하시오.
#include <stdio.h>
#include <stdlib.h>

int sumof(const int a[], int n);

void main(void) {
    int i, number;
    int *height;

    do {
    printf("Enter the number of people(must be positive number): ");
    scanf_s("%d", &number);    
    } while (number < 0);

    height = calloc(number, sizeof(int));

    for (i = 0; i < number; i++) {
        printf("Enter the height of height[%d]: ", i);
        scanf_s("%d", &height[i]);
    }

    int sum = sumof(height, number);

    printf("Sum of the given height of people is %d\n", sum);
    free(height);
}

int sumof(const int a[], int n) {
    int i;
    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += a[i];
    }

    return sum;
}