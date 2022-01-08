#include <stdio.h>
#include <stdlib.h>


typedef struct stack {
    int top;
    int max;
    int *stk;
} IntStack;

int InitStack(IntStack *s, int max) {
    if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) {
        return 0;
        s->max = 0;
    }

    s->top = 0;
    s->max = max;

    return 1;
}

void Terminate(IntStack *s) {
    if (s->stk != NULL) {
        free(s->stk);
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


// 재귀 함수
// 중위 표기법의 구현
void recur(int n) {
    if (n > 0) {
        // n의 값을 n - 1로 업데이트하고 함수의 시작 지점으로 돌아간다. 현재 n의 값을 잠시 저장해야한다.
        recur(n - 1);
        // n의 값을 출력 => 저장했던 n값을 다시 꺼내 그 값을 출력한다.
        printf("%d ", n);
        // n의 값을 n -2로 업데이트하고 함수의 시작 지점으로 돌아간다. 이떄, n값은 저장하지 않아도 된다.
        recur(n - 2);
    }
    
}

// 재귀를 제거
int recur_n(int n) {
    IntStack s;
    int data;

    InitStack(&s, 512);

    while (1) {
        if (n > 0) {
            Push(&s, n);
            n = n - 1;
            continue;
        }


        if (!IsEmpty(&s)) {
            Pop(&s, &n);
            printf("%d ", n);
            n = n - 2;
            continue;
        }

        Terminate(&s);
        break;
    }

    return 1;
}


void main() {
    int n;

    printf("Enter a number: ");
    scanf_s("%d", &n);

    recur(n);
    puts("");
    recur_n(n);
}