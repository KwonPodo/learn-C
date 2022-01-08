// int형 스택 IntStack의 사용

#include <stdio.h>
#include <stdlib.h>

// 스택을 구현하는 구조체
typedef struct {
    int max; // 스택 용량
    int ptr; // 스택 포인터 : 스택에 쌓여 있는 데이터의 개수를 나태냄
    int *stk; // 스택의 첫 요소에 대한 포인터
} IntStack;

// 스택 초기화
int Initialize(IntStack *, int);

// 스택에 데이터를 푸시
int Push(IntStack *, int );

// 스택에서 데이터를 팝
int Pop(IntStack *, int *);

// 스택에서 데이터를 피크
int Peek(const IntStack *, int *);

// 스택 비우기
void Clear(IntStack *);

// 스택의 최대용량
int Capacity(const IntStack *);

// 스택의 데이터 개수
int Size(const IntStack *);

// 스택이 비어있는지 확인
int IsEmpty(const IntStack *);

// 스택이 가득 차있는지 확인
int IsFull(const IntStack *);

// 스택에서 검색
int Search(const IntStack *, int );

// 모든 데이터 출력
void Print(const IntStack *);

// 스택 종료
void Terminate(IntStack *);



int main() {
    IntStack s;

    if(Initialize(&s, 64) == -1) {
        puts("스택 생성에 실패하였습니다.");
        return 1;
    }

    while(1) {
        int menu, data;

        printf("현재 데이터 수 : %d/64\n", Size(&s));
        printf("(1) Push (2) Pop (3) Peek (4) Print (5) Clear (6) Stack Status (7) Search (0) Terminate: ");
        scanf_s("%d", &menu);

        if (menu == 0) break;

        switch (menu)
        {
        case 1 :
            printf("Data to push: ");
            scanf_s("%d", &data);
            if (Push(&s, data) == -1)
                puts("\tError!: Push Failed");
            break;
        
        case 2 :
            if (Pop(&s, &data) == -1)
                puts("\tError!: Pop Failed");
            else 
                printf("Popped data is %d\n", data);
            break;
        
        case 3 :
            if(Peek(&s, &data) == -1)
                puts("\tError!: Peek Failed");
            else {
                printf("Peeked data is %d.\n", data);
            }
            break;
        
        case 4 :
            puts("Printing...");
            Print(&s);
            break;
        
        case 5 :
            Clear(&s);
        
        case 6 :
            puts("Stack Status");
            
            printf("Stack Capacity: %d\n", Capacity(&s));
            if (IsEmpty(&s))
                puts("Stack is currently Empty");
            else if (IsFull(&s))
                puts("Stack is currently Full");
            else {
                printf("Current Stack Size: %d\n", Size(&s));
            }

        case 7 :
            printf("Searching for?: ");
            scanf_s("%d", &data);

            if (Search(&s, data) == -1)
                printf("No such data\n");
            else {
                printf("%d is at %dth index of the stack (from the bottom)\n", data, Search(&s, data));
            }

        default:
            break;
        }
    }
    Terminate(&s);
    return 0;
}

//스택 초기화
int Initialize(IntStack *s, int max) {
    s->ptr = 0;
    if ((s->stk = (int *)calloc(max, sizeof(int))) == NULL) {
        // 배열 생성 실패시
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

// 스택에 데이터를 푸시
int Push(IntStack *s, int x) {
    if (s->ptr >= s->max) return -1;

    s->stk[s->ptr++] = x;
    
    return 0;
}

// 스택에서 데이터를 팝
int Pop(IntStack *s, int *x) {
    if (s->ptr <= 0) return -1;

    *x = s->stk[--(s->ptr)];

    return 0;
}

// 스택에서 데이터를 피크
int Peek(const IntStack *s, int *x) {
    if (s->ptr <= 0) return -1;
    else {
        *x = s->stk[s->ptr - 1];
        return 0;
    }
}

// 스택 비우기
void Clear(IntStack *s) {
    s->ptr = 0;
}

// 스택의 최대용량
int Capacity(const IntStack *s) {
    return s->max;
}

// 스택의 데이터 개수
int Size(const IntStack *s) {
    return s->ptr;
}

// 스택이 비어있는지 확인
int IsEmpty(const IntStack *s) {
    return s->ptr <= 0 ? 1 : 0;
}

// 스택이 가득 차있는지 확인
int IsFull(const IntStack *s) {
    return s->ptr >= s->max ? 1 : 0;
}

// 스택에서 검색
// 꼭대기부터 검색 : 먼저 Pop되는 데이터를 찾기 위함
int Search(const IntStack *s, int x) {
    int i;
    
    for (i = s->ptr; i >= 0; i--) {
        if (s->stk[i] == x) {
            return i;
        }
    }
    
    return -1;
}

// 모든 데이터 출력 Bottom ~ Top
void Print(const IntStack *s) {
    int i;
    for (i = 0; i < s->max; i++) {
        printf("s->stk[%d]: %d\n", i, s->stk[i]);
    }
}

// 스택 종료
void Terminate(IntStack *s) {
    if (s->stk != NULL) {
        free(s->stk);
    }

    s->max = s->ptr = 0;
}