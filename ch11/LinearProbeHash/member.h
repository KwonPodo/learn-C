// 회원 데이터 member Header
#ifndef ___member
#define ___member

struct member {
    int no;
    char name[20];
};

#define MEMBER_NO 1
#define MEMBER_NAME 2

// 회원번호 비교 함수
int memberNoCmp(const struct member *x, const struct member *y);

// 회원 이름 비교 함수  
int memberNameCmp(const struct member *x, const struct member *y);

// 회원 데이터를 출력(줄바꿈 x)
void printMember(const struct member *x);

// 회원 데이터를 출력(줄바꿈 O)
void printlnMember(const struct member *x);

// 회원 데이터를 읽어들임
struct member scanMember(const char *message, int sw);

#endif