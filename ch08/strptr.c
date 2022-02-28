// 포인터로 문자열을 출력
#include <stdio.h>

int main() {
    int a = 5;
    int *p = &a;

    printf("sizeof(a): %d\nsizeof(p): %d\n", sizeof(a), sizeof(p));
    char arr[] = "123456788";
    char *ptr = "123456788";
    printf("%s\n", ptr);
    printf("sizeof(arr): %d\nsizeof(ptr): %u\n", sizeof(arr), sizeof(*ptr));

    return 0;
}