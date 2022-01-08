// 유클리드 호제법 (최대공약수) Euclian method of mutual division
// 두 정수를 직사각형의 두 변의 길이라고 생각한다면
// 정사각형으로 직사각형을 빈틈없이 채울 수 있을 때의 정사각형의 최대 길이는
// 최대공약수이다.

#include <stdio.h>
#include <stdlib.h>

int my_gcd(int x, int y) {
    int big, small;
    
    if (x > y) big = x, small = y;
    else big = y, small = x;

    if (big % small == 0) { // if (small == 0) return big;
        return small;
    }

    return gcd(small, big % small);
}

// 대소비교를 할 필요가 없음
// 어차피 y, x % y로 넣으면 나누어도 나머지가 본인 그자체이기 때문에 위치만 바뀌고 다시 실행됨
// 단순히 실행되는 스택 개수의 차이일뿐
int gcd(int x, int y) {
    if (y == 0) 
        return x;
    
    return (y, x % y);
}

void main () {
    int a, b;
    int result;

    puts("Getting Greatest Common Divisor(GCD) from two given numbers");
    printf("Enter a number: ");
    scanf_s("%d", &a);

    printf("Enter a number: ");
    scanf_s("%d", &b);

    result = gcd(a, b);

    printf("GCD of numbers %d, %d is %d\n", a, b, result);
}