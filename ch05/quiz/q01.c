// 재귀 함수 호출을 사용하지 않고 factorial 함수를 작성하세요.

#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    int result = n;
    while (n > 1) {
        result *= n - 1;
        n--;
    }

    return result;
}

void main() {
    int a;

    puts("Factorial without recursive model");
    printf("Enter a number: ");
    scanf_s("%d", &a);

    printf("%d! = %d\n", a, factorial(a));
}