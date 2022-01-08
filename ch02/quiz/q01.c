#include <stdio.h>
#include <stdlib.h>

// 키의 최솟값을 구하는 프로그램을 작성하시오.
int minof(const int a[], int n);

void main() {
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

    int min = minof(height, number);

    printf("Minimum height of the people given is %d\n", min);
    free(height);
}

int minof(const int a[], int n) {
    int min = a[0];
    int i;
    
    for (i = 0; i < n; i++) {
        if (min > a[i]) min = a[i];
    }

    return min;
}