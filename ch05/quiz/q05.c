// recur3 함수를 비재귀적으로 구현하세요.
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
void recur3(int n) {
    if (n > 0) {
        // n = n - 1로 업데이트하고 함수의 시작지점으로 돌아간다. 이때의 n값을 저장한다.
        recur3(n - 1);
        // n = n - 2로 업데이트하고 함수의 시작지점으로 돌아간다. 이때의 n값을 저장한다.
        recur3(n - 2);
        // 저장한 n값을 꺼내어 출력한다.
        printf("%d ", n);
    }
}

// 재귀를 제거
int recur_n(int n) {
    IntStack s;
    int data;
    int cpy;
    InitStack(&s, 512);

    while (1) {
        if (n > 0) { // !종료조건 n <= 0
            Push(&s, n); // 스택에 계속 푸시
            n = n - 1;
            continue;
        }

        while(!IsEmpty(&s)) {
            cpy = n;
            Pop(&s, &n);

            if (n - 2 > 0) { // recur(n - 2) 가 실행가능한지 여부 확인
                if (n - 2 == cpy) { // recur(n - 2) 실행 후, 스택에서 저장된 
                    printf("%d ", n);
                } else {
                    Push(&s, n);
                    n = n - 2;
                    break;
                }
            } else {
                printf("%d ", n); // recur(n - 2)가 실행이 안되는 수이면 print실행, recur(n - 1)에 해당하는 재귀 종료
                
            }
        }

        if (IsEmpty(&s)) {
            Terminate(&s);
            break;
        }
    }

    return 1;
}


void main() {
    int n;

    printf("Enter a number: ");
    scanf_s("%d", &n);

    recur3(n);
    puts("");
    recur_n(n);
}