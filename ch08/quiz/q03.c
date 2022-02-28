// 포인터 x,y가 가리키는 문자열의 내용을 모두 바꾸어 넣는 함수를 작성해보자
#include <stdio.h>
#include <string.h>

void swap_ptr (char *x, char *y) {
    char tmp;
    int i;
    for (i = 0; i < 5; i++) {
        tmp = x[i];
        x[i] = y[i];
        y[i] = tmp;
    }
}

int main() {
    char s1[16];
    char s2[16];

    printf("s1: "); scanf("%s", s1);
    printf("s2: "); scanf("%s", s2);

    swap_ptr(s1, s2);

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    return 0;
}