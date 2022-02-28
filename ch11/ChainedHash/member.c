// 회원데이터 member 소스

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "member.h"

// 회원번호 비교 함수
int memberNoCmp(const struct member *x, const struct member *y) {
    return x->no == y->no;
}

// 회원 이름 비교 함수
int memberNameCmp(const struct member *x, const struct member *y) {
    return !strcmp(x->name, y->name);
}

// 회원 데이터를 출력(줄바꿈 x)
void printMember(const struct member *x) {
    puts("Print Member");
    printf("No : %d\n", x->no);
    printf("Name : %s\n", x->name);
}

// 회원 데이터를 출력(줄바꿈 O)
void printlnMember(const struct member *x) {
    printf("%d %s\n", x->no, x->name);

}

// 회원 데이터를 읽어들임
struct member scanMember(const char *message, int sw) {
    struct member temp;
    printf("%s하는 데이터를 입력하세요\n", message);
    if (sw & MEMBER_NO) {printf("NO : "); scanf("%d", &temp.no);}
    if (sw & MEMBER_NAME) {printf("Name : "); scanf("%s", temp.name);}

    return temp;
}