// 체인법으로 구현한 해시
#ifndef ___ChainHash
#define ___ChainHash

#include "member.h"

// 버킷을 나타내는 노드
struct node {
    struct member data;
    struct node *next;
};

// 해시 테이블
struct chainHash {
    int size;
    struct node **table;
};

// 해시 테이블 초기화
int initTable(struct chainHash *h, int size);

// 검색
struct node* search(struct chainHash *h, const struct member *x);

// 데이터 추가
int addData(struct chainHash *h, const struct member *x);

// 데이터 삭제
int removeData(struct chainHash *h, const struct member *x);

// 해시 테이블 덤프
void dumpTable(const struct chainHash *h);

// 모든 데이터 삭제
void clearTable(struct chainHash *h);

// 해시 테이블 종료
void terminateTable(struct chainHash *h);

#endif