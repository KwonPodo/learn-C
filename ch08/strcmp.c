// 문자열 비교
#include <stdio.h>

int str_cmp(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] == s2[i]) {
        if (s1[i] == '\0') return 0;
        i++;
    }

    return (int)s1[i] - (int)s2[i];
}

int str_ncmp(const char *s1, const char *s2, int n) {
    int i = 0;

    while (s1[i] == s2[i] && i < n) {
        if (s1[i] == '\0') return 0;
        i++;
    }

    return (int)s1[i] - (int)s2[i];
}

int main() {
    char arr[128];
    puts("compare with ABCD");
    puts("if XXXX, promgram ends");

    while (1) {
        printf("Enter string: "); scanf("%s", arr);

        if (str_cmp("XXXX", arr) == 0) {
            break;
        }

        printf("str_cmp(\"ABCD\", st) : %d\n", str_cmp("ABCD", arr));
    }

    return 0;
}