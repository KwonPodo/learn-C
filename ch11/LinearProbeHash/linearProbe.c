/**
 * 선형 탐사법의 삽입 알고리즘
 * 1. 삽입할 레코드의 해시값을 해시 함수를 이용하여 구한 뒤, 이를 try에 저장
 * 2. while (해시 테이블[try]가 비어 있지 않을 동안)
 *      2.1 try = (try + 1) % tableSize
 * 3. 해시 테이블[try]에 레코드를 기입
 * 
 * 
 * 선형 탐사법의 검색 알고리즘
 * 1. 검색할 키의 해시값을 구하여 try에 저장
 * 2. while (해시 테이블[try]가 비어 있지 않을 동안)
 *      2.1 if (key == table[try]) return try;
 *          else { try = (try + 1) % tableSize }
 * 3. 테이블을 다 훑어봤는데도 안나오면 없는 것이므로 return -1
 * 
 * 요소를 삭제하고나서 검색을 할 때, 선형으로 순차탐색을 진행하기 때문에 
 * 버킷이 비어있는 것과, 버킷의 요소를 삭제한 상태를 구분할 수가 없다.
 * 이렇게 되면 그 둘을 구분할 수 없게 되어 원하는 요소가 뒤쪽 버킷에 있음에도 불구하고
 * 검색을 멈추게 되어 원하는 요소를 찾을 수 없게 된다.
 * 따라서 버킷의 상태를 저장해야한다.
 * 1. 비어 있는 상태 -> 검색을 멈춘다. 비어있는 버킷을 만난다면 현재 해시테이블에 저장된 버킷의 내용을 다 보았다는 뜻이기 때문.
 * 2. 삭제된 상태 -> 삭제되어 있을 경우, 검색시 검색을 멈추지 말고 계속 진행해야 한다.
 * 3. 데이터가 들어 있는 상태
 */

#include "member.h"
#include "linearProbe.h"
#include <stdlib.h>
#include <stdio.h>

static int hash(int key, int size) {
    return key % size;
}

static int reHashK(int key, int size) {
    return (key + 1) % size;
}

void setBucket(struct bucket *b, struct member *m, enum status s) {
    b->data = *m;
    b->state = s;
}

int initTable(struct linearHash *h, int size) {
    h->table = (struct bucket*)calloc(size, sizeof(struct bucket));

    if (h->table == NULL) {
        h->size = 0;
        return 0;
    }

    h->size = size;

    for (int i = 0; i < h->size; i++) {
        h->table->state = empty;
    }

    return 1;
}

struct bucket* searchBucket(const struct linearHash *h, const struct member *m) {
    int try = hash(m->no, h->size);
    int record = m->no;

    struct bucket *search = &(h->table[try]);

    while (search->state != empty) {
        search = &(h->table[try]);
        if (search->data.no == record) {
            printf("search->data.no: %d\n", search->data.no);
            return search;
        }

        try = reHashK(m->no, h->size);
    }

    return NULL;
}

int addData(struct linearHash *h, struct member *m) {
    int try = hash(m->no, h->size);
    
    struct bucket *b = &(h->table[try]);
    struct bucket *start = b;

    struct bucket *dum = searchBucket(h, m);
    if (searchBucket(h, m) != NULL) return 0;

    while (b->state != empty) {
        try = reHashK(m->no, h->size);
        // printf("%d\n", try);
        b = &(h->table[try]);

        if (b == start) return 0;
    }

    if (b->state == empty) {
        setBucket(b, m, occupied);
    }

    return 1;
}

int removeData(struct linearHash *h, struct member *m) {
    struct bucket *r = searchBucket(h, m);
    if (r == NULL) {
        puts("No such Data");
        return 0;
    }

    r->state = deleted;

    return 1;
}

void dumpTable(struct linearHash *h) {
    int i;
    for (i = 0; i < h->size; i++) {
        printf("%02d : ", i);
        switch (h->table[i].state)
        {
        case occupied:
            printf(" %d(%s)\n", h->table[i].data.no, h->table[i].data.name);
            break;
        
        case deleted:
            printf("Deleted\n");
            break;

        case empty:
            printf("Empty\n");
            break;
        
        default:
            break;
        }
    }
}

void clearTable(struct linearHash *h) {
    int i;
    for (i = 0; i < h->size; i++) {
        h->table[i].state = empty;
    }
}

void terminateTable(struct linearHash *h) {
    clearTable(h);
    if (h->table != NULL) free(h->table);
    h->size = 0;
}