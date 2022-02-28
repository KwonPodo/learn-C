// 선형 탐사법으로 구현한 해시
#ifndef ___LINEAR_PROBE
#define ___LINEAR_PROBE

#include "member.h"

enum status {
    empty, occupied, deleted
};

struct bucket {
    struct member data;
    enum status state;
};

struct linearHash {
    int size;
    struct bucket *table;
};

int initTable(struct linearHash *h, int size);

struct bucket* searchBucket(const struct linearHash *h, const struct member *m);

int addData(struct linearHash *h, struct member *m);

int removeData(struct linearHash *h, struct member *m);

void dumpTable(struct linearHash *h);

void clearTable(struct linearHash *h);

void terminateTable(struct linearHash *h);

#endif