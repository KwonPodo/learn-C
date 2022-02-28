// 저장한 문자열을 출력
#include <stdio.h>


// 문자열을 초기화하며 선언합니다.
int init() {
    char a[10] = "ABCD";
    printf("%s\n", a);

    return 0;
}

int main() {
    char a[10];
    a[0] = 'A';
    a[1] = 'B';
    a[2] = 'C';
    a[3] = 'D';
    a[4] = '\0';
    a[5] = 'X';

    printf("%s\n", a);

    init();

    return 0;
}