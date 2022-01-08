#include <stdio.h>

void recur1(int n) {
    if (n > 0) {
        recur1(n - 1);
        printf("%d ", n);
        recur1(n - 2);
    }
}

void recur2(int n) {
    if (n > 0) {
        recur2(n - 2);
        printf("%d ", n);
        recur2(n - 1);
    }
}

void main() {
    int n;

    printf("Enter a number : ");
    scanf_s("%d", &n);

    recur1(n);
}