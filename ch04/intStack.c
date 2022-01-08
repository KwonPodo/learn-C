// int형 스택 IntStack
#include <stdio.h>
#include <stdlib.h>

struct stack {
    int max;
    int ptr;
    int *stk;
};

struct stack IntStack;

//스택 초기화
int Initialize(struct stack *s, int max) {
    s->ptr = 0;
    if (s->stk = (int*)calloc(max, sizeof(int)) == NULL) {
        // 배열 생성 실패시
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

// 스택에 데이터를 푸시
int Push(struct stack *s, int x) {
    if (s->ptr >= s->max) return -1;

    s->stk[s->ptr++] = x;
    
    return 0;
}

// 스택에서 데이터를 팝
int Pop(struct stack *s, int *x) {
    if (s->ptr <= 0) return -1;

    *x = s->stk[--(s->ptr)];

    return 0;
}

// 스택에서 데이터를 피크
int Peek(const struct stack *s, int *x) {
    if (s->ptr <= 0) return -1;
    else {
        *x = s->stk[s->ptr - 1];
        return 0;
    }
}

// 스택 비우기
void Clear(struct stack *s) {
    s->ptr = 0;
}

// 스택의 최대용량
int Capacity(const struct stack *s) {
    return s->max;
}

// 스택의 데이터 개수
int Size(const struct stack *s) {
    return s->ptr;
}

// 스택이 비어있는지 확인
int IsEmpty(const struct stack *s) {
    return s->ptr <= 0 ? 1 : 0;
}

// 스택이 가득 차있는지 확인
int IsFull(const struct stack *s) {
    return s->ptr >= s->max ? 1 : 0;
}

// 스택에서 검색
// 꼭대기부터 검색 : 먼저 Pop되는 데이터를 찾기 위함
int Search(const struct stack *s, int x) {
    int i;
    
    for (i = s->ptr; i >= 0; i--) {
        if (s->stk[i] == x) {
            return i;
        }
    }
    
    return -1;
}

// 모든 데이터 출력 Bottom ~ Top
void Print(const struct stack *s) {
    int i;
    for (i = 0; i < s->max; i++) {
        printf("s->stk[%d]: %d\n", i, s->stk[i]);
    }
}

// 스택 종료
void Terminate(struct stack *s) {
    if (s->stk != NULL) {
        free(s->stk);
    }

    s->max = s->ptr = 0;
}