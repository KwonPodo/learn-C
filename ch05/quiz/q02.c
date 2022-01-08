// 재쉬 함수 호출을 사용하지 않고 gcd함수를 작성하세요.

#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) {
    if (y == 0) return x;

    return gcd(y, x % y);
}

int gcd_nr(int x, int y) {
    while (y != 0) {
        int remainder = x % y;
        x = y;
        y = remainder;
    }
    return x;
}

void main() {
    int a, b;
    puts("Euclidian algorithm without recursive model");
    printf("Enter a number: ");
    scanf_s("%d", &a);

    printf("Enter a number: ");
    scanf_s("%d", &b);

    printf("Greatest Common Divisor of %d, %d is %d\n", a, b, gcd(a, b));
}