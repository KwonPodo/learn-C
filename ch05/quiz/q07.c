// 하노이의 탑의 move함수를 비재귀적으로 수정하세요
#include <stdio.h>

typedef struct stack {
    int top;
    int max;
    int *stk;
} IntStack;

void InitStack(IntStack *s, int max) {
    if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) {
        return 0;
        s->max = 0;
    }

    s->top = s->max = 0;
    return 1;
}

void Terminate(IntStack *s) {
    if (s->stk != NULL) {
        free(s);
    }

    s->max = s->top = 0;
}

int IsFull(IntStack *s) {
    return s->top >= s->max;
}

int IsEmpty(IntStack *s) {
    return s->top == 0;
}

int Push(IntStack *s, int data) {
    if (IsFull(s)) return 0;

    s->stk[s->top++] = data;

    return 1;
}

int Pop(IntStack *s, int *data) {
    if (IsEmpty(s)) return 0;

    *data = s->stk[--s->top];

    return 1;
}

// 원반 [1] ~ [n]을 x 기둥에서 y 기둥으로 옮김
void move(int n, int x, int y) {
    // 1. 1 ~ n - 1을 가운데 기둥으로 옮김
    // 2. n을 y 기둥으로 옮김
    // 3. 1 ~ n - 1을 y 기둥으로 옮김
    if (n > 1) 
        move(n - 1, x, 6 - x- y);

    printf("원반[%d]를 %d 기둥에서 %d 기둥으로 옮김\n", n, x, y);

    if (n > 1)
        move(n - 1, 6 - x - y, y);

    while(1) {
        n -= 1;
        x = 6 - x - y;

    }
}

int main () {
    int n; // 원반의 개수
    int start_pillar = 1; // 시작 기둥
    int end_pillar = 3; // 목표 기둥
    printf("Hanoi\n원반 개수 : ");
    scanf_s("%d", &n);

    move(n, start_pillar, end_pillar);

    return 0;
}