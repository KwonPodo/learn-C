// 음이 아닌 정수의 순차곱셈
// 1. 0! = 1;
// 2. n > 0 일 때, n! = n * (n-1)!;

#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n > 0)
        return n * factorial(n - 1);
    else 
        return 1;

}

void main() {
    int num;

    do {
    printf("Enter a number: ");
    scanf_s("%d", &num);
    } while (num < 0);

    int result = factorial(num);

    printf("%d! = %d\n", num, result);
}