// 키의 평균을 구하는 프로그램을 작성하시오.
#include <stdlib.h>
#include <stdio.h>

#define sum(sum, i, arr) do { sum += arr[i]; } while(0);

double aveof(const int a[], int n);

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

    double average = aveof(height, number);

    printf("Average height of the people given is %f\n", average);

    free(height);
}

double aveof(const int a[], int n) {
    int i, sum = 0;

    for (i = 0; i < n; i++) {
        sum(sum, i, a);
    }

    double average = (double)(sum / n);
    printf("Average: %f\n", average);
    return average;
}