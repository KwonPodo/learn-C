#include <stdio.h>
#include <stdlib.h>
#include "member.h"
#include "chainHash.h"

// 해시 함수
static int hash (int key, int size) {
    return key % size;
}

// 노드의 각 멤버에 값을 설정
static void setNode(struct node *n, const struct member *x, struct node *next) {
    n->data = *x;
    n->next = next;
}

// 해시 테이블 초기화
int initTable(struct chainHash *h, int size) {
    int i;
    h->table = (struct node**)calloc(size, sizeof(struct node*));
    if (h->table == NULL) {
        h->size = 0;
        return 0;
    }

    h->size = size;
    for (i = 0; i < size; i++) {
        h->table[i] = NULL;
    }

    return 1;
}

// 검색
struct node* search(struct chainHash *h, const struct member *x) {
    int key = hash(x->no, h->size);
    struct node *s = h->table[key];

    while (s != NULL) {
        if (memberNoCmp(&(s->data), x)) {
            return s;
        }
        s = s ->next;
    }

    return NULL;
}

// 데이터 추가
int addData(struct chainHash *h, const struct member *x) {
    int key = hash(x->no, h->size);

    struct node *bucket = h->table[key];
    struct node *s = bucket;

    while (s != NULL) {
        if (s->data.no == x->no) {
            return 0;
        }

        s = s->next;
    }

    struct node *new = (struct node*)malloc(sizeof(struct node));
    setNode(new, x, bucket);
    h->table[key] = new;

    return 1;
}

// 데이터 삭제
int removeData(struct chainHash *h, const struct member *x) {
    int key = hash(x->no, h->size);

    struct node *s = search(h, x);
    struct node *prev_s = h->table[key];

    if (s == NULL) return 0;

    if (prev_s != s) {
        while (prev_s->next != s) {
            prev_s = prev_s->next;
        }
        prev_s->next = s->next;
    } else {
        h->table[key] = NULL;
    }

    free(s);

    return 1;
}

// 해시 테이블 덤프
void dumpTable(const struct chainHash *h) {
    struct node *t;
    struct node *data_ptr;
    int i = 0;

    for (i = 0; i < h->size; i++) {
        t = h->table[i];
        data_ptr = t;
        printf("%02d", i);
        
        while (data_ptr != NULL) {
            printf("->%d :(%s) ", data_ptr->data.no, data_ptr->data.name);
            data_ptr = data_ptr->next;
        }
        puts("");
    }
}

// 모든 데이터 삭제
void clearTable(struct chainHash *h) {
    struct node *t, *liberator;
    int i;

    for (i = 0; i < h->size; i++) {
        t = h->table[i];

        while (t != NULL) {
            liberator = t;
            t = t->next;
            free(liberator);
        }

        h->table[i] = NULL;
    }
}

// 해시 테이블 종료
void terminateTable(struct chainHash *h) {
    if (h->table == NULL) {
        h->size = 0;
    }

    free(h->table);
}