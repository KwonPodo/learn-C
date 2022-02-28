// 포인터 교환 함수를 매크로 swap으로 만들어보자
#include <stdio.h>
#define swap(type, x, y) do {type *t = *x; *x = *y; *y = t;} while(0)

// 두 포인터 값을 서로 교환하는 프로그램
void swap_ptr (char **x, char **y) {
    char *tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    char *s1 = "ABCD";
    char *s2 = "EFGH";

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    swap(char, &s1, &s2);
    // swap_ptr(&s1, &s2);

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    return 0;
}