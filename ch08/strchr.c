// 문자열에서 문자를 검색하는 프로그램
#include <stdio.h>

// 문자열 내에서 
char* str_chr(char *s, char ch) {
    int i = 0;
    int tmp;

    while (s[i] != ch) {
        if (s[i] == '\0') {
            return NULL;
        }
        i++;
    }
    
    return &s[i];
}

char* str_rchr(char *s, char ch) {
    int i = 0;
    int tmp = -1;

    while (s[i] != '\0') {
        if (s[i] == ch) {
            tmp = i;
        }
        i++;
    }

    if (tmp == -1) return NULL;
    else return &s[tmp];
}

int main() {
    char str[64];   // 검색할 문자열
    char tmp[64];
    char ch;     // 검색할 문자
    int idx;

    printf("string: "); scanf("%s", str);

    printf("to search for: "); scanf("%s", tmp);
    
    ch = tmp[0];

    char *p = str_rchr(str, ch);

    printf("%c\n", *p);
    printf("%c\n", *(p - 1));
    printf("%c\n", *(p - 2));
    return 0;
}