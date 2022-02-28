// 배열의 길이를 구하는 프로그램
#include <stdio.h>


// len의 값은 문자열의 길이이자 널문자가 들어있는 인덱스이다.
int strLen(const char *s) {
    int len = 0;

    while (s[len] != 0) {
        len++;
    }

    return len;
}

int strLen2(char *s) {
    int len = 0;

    while (*s++) len++;

    return len;
}

int strLen3(char *s) {
    char *p = s;
    while (*s) s++;

    return s - p;
}

int main() {
    char str[256];

    printf("Enter string: "); scanf("%s", str);

    printf("len: %d\n", strLen(str));
    printf("len: %d\n", strLen2(str));
    printf("len: %d\n", strLen3(str));
}