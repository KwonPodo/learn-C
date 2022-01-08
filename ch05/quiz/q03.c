// 배열 a의 모든 요소의 최대공약수를 구하는 다음 함수를 작성하세요.

#include <stdlib.h>
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a;

    return gcd(b, a % b);
}

int gcd_array(const int a[], int n) {
    if (n == 1) return a[0];
    else if (n == 2) return (gcd(a[0], a[1]));
    else // 배열의 포인터를 하나씩 뒤로 이동시킨다. 따라서 결국에는 12 와 3의 gcd를 구하고, 그 gcd로 6과의 gcd를 구하는 방식이 된다.
        return gcd(a[0], gcd_array(a + 1, n - 1)); // return gcd(a[0], gcd_array(&a[0], n - 1));
}

int my_gcd_array(const int a[], int n) {
    int i, result;
    result = a[0];

    for (i = 0; i < n; i++) {
        result = gcd(result, a[i]);
    }

    return result;
}

void main() {
    int a[] = {6, 3, 12};
    int n = 3;
    printf("%d\n", gcd_array(a, n));
}