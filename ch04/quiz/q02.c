// 하나의 배열을 공유하여 2개의 스택을 구현하는 스택 프로그램을 만드시오. 
// 스택에 저장하는 데이터는 int형 값으로 아래 그림처럼 배열의 처음과 끝을 사용하세요

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max; // 전체 스택 용량
    int l_ptr; // 왼쪽 스택에 쌓여있는 데이터의 개수를 나타냄(양수)
    int r_ptr; // 오른쪽 스택에 쌓여 있는 데이터의 개수를 나타냄(음수)
    int *l_stk; // 왼쪽 스택 기준, 첫 요소에 대한 포인터.
    int *r_stk; // 오른쪽 스택 기준, 첫 요소에 대한 포인터
} IntStack;


int Initialize(IntStack * s, int max) {
    s->l_ptr = 0;
    s->r_ptr = 0;

    if ((s->l_stk = (int*)calloc(max, sizeof(int))) == NULL) {
        // if creating array fails
        s->max = 0;
        return -1;
    }
    s->r_stk = &(s->l_stk)[max - 1];

    return 0;
}

// 왼쪽 스택에 푸쉬
int l_Push(IntStack *s, int x) {
    if (s->l_ptr - s->r_ptr >= s->max) return -1;

    s->l_stk[s->l_ptr++] = x;

    return 0;
}

// 오른쪽 스택에 푸쉬
int r_Push(IntStack *s, int x) {
    if ((s->l_ptr - s->r_ptr) >= s->max) return -1;

    s->r_stk[s->r_ptr--] = x;

    return 0;
}

// 왼쪽 스택에서 데이터를 팝
int l_Pop(IntStack *s, int *x) {
    if (s->l_ptr <= 0) return -1;

    *x = s->l_stk[--(s->l_ptr)];

    return 0;
}

// 오른쪽 스택에서 데이터를 팝
int r_Pop(IntStack *s, int *x) {
    if (s->r_ptr >= 0) return 1;

    *x = (s->r_stk[++(s->r_ptr)]);

    return 0;
}

// 왼쪽 스택에서 데이터를 피크
int l_Peek(IntStack *s, int *x) {
    if (s->l_ptr <= 0) return -1;
    else {
        *x = s->l_stk[s->l_ptr - 1];
        return 0;
    }
}

// 오른쪽 스택에서 데이터를 피크
int r_Peek(IntStack *s, int *x) {
    if (s->r_ptr >=0) return -1;
    else {
        *x = s->r_stk[s->r_ptr + 1];
        return 0;
    }
}

// 스택 비우기
void Clear(IntStack *s) {
    int stack;

    while (1) {
    printf("Choose which stack to clear\n");
    printf("(1) Left Stack (2) Right Stack (3) All (0) None: ");
    scanf_s("%d", &stack);

    if (stack == 0) break;
    switch (stack)
        {
        case 1:
            s->l_ptr = 0;
            break;

        case 2:
            s->r_ptr = 0;
            break;
        
        case 3:
            s->l_ptr = s->r_ptr = 0;
            break;
        
        default:
            break;
        }
    }
}

// 스택의 최대 용량
int Capacity(const IntStack *s) {
    return s->max - (s->l_ptr - s->r_ptr);
}

// 스택의 데이터 개수
int l_Size(const IntStack *s) {
    return s->l_ptr;
}

int r_Size(const IntStack *s) {
    return -(s->r_ptr);
}

// 스택이 비어있는지 확인
int l_IsEmpty(const IntStack *s) {
    return s->l_ptr >= 0;
}

int r_IsEmpty(const IntStack *s) {
    return s->r_ptr <= 0;
}

// 스택이 가득 차있는지 확인
int IsFull(const IntStack *s) {
    return s->l_ptr - s->r_ptr >= s->max;
}

// 스택에서 검색

int l_Search(const IntStack *s, int x) {
    int i;

    for (i = s->l_ptr - 1; i >= 0; i--) {
        if (s->l_stk[i] == x)
            return i;
    
    return -1;
    }
}

int r_Search(const IntStack *s, int x) {
    int i;

    for (i = 0; i >= s->r_ptr + 1; i--) {
        if (s->r_stk[i] == x)
            return i;
    
    return -1;
    }
}

// 전부 출력
void Print(const IntStack *s) {
    int i;
    for(i = 0; i < s->max; i++) {
        printf("s->stk[%d]: %d\n", i, s->l_stk[i]);
    }
}

// 스택 종료
void Terminate(IntStack *s) {
    if (s->l_stk != NULL) {
        free(s->l_stk);
    }

    if (s-> r_stk != NULL) {
        free(s->r_stk);
    }

    s->max = s->l_ptr = s->r_ptr = 0;
}


int main() {
    IntStack s;
    int data, direction;
    
    if(Initialize(&s, 8) == -1) {
        puts("Initiating Stack Failed..");
        return 1;
    }

    int menu, stack;
    while(1) {
        printf("Current Data size: %d/64", r_Size(&s) + l_Size(&s));
        printf("(1) Push (2) Pop (3) Peek (4) Print (5) Clear (6) Stack Status (7) Search (0) Terminate: ");
        scanf_s("%d", &menu);

        if (menu == 0) break;

        switch (menu)
        {
        case 1:
            printf("Enter Data: ");
            scanf_s("%d", &data);
            printf("Which Stack? (1) Left (2) Right (3) Return to menu\n");
            scanf_s("%d", &direction);

            if (direction == 1) {
                if (l_Push(&s, data) == -1)
                    puts("l_Push Failed....");
            } else if (direction == 2) {
                if (r_Push(&s, data) == -1)
                    puts("r_Push Failed....");
            }

            break;
        
        case 2:
            printf("Which Stack? (1) Left (2) Right (3) Return to menu\n");
            scanf_s("%d", &direction);

            if (direction == 1) {
                if (l_Pop(&s, &data) == -1)
                    puts("l_Pop Failed....");

                printf("Popped data: %d\n", data);
            } else if (direction == 2) {
                if (r_Pop(&s, &data) == 1)
                    puts("r_Pop Failed....");

                printf("Popped data: %d\n", data);
            }

            break;
        
        case 3:
            printf("Which Stack? (1) Left (2) Right (3) Return to menu\n");
            scanf_s("%d", &direction);

            if (direction == 1) {
                if (l_Peek(&s, &data) == -1)
                    puts("l_Peek Failed....");

                printf("Peeked data: %d\n", data);
            } else if (direction == 2) {
                if (r_Peek(&s, &data) == -1)
                    puts("r_Peek Failed....");
                    
                printf("Peeked data: %d\n", data);
            }

            break;

        case 4:
            Print(&s);
            break;
        
        case 5:
            Clear(&s);
            break;
        
        case 6:
            puts("Stack Status");
            printf("Stack Capacity: %d\n", Capacity(&s));

            if (IsFull(&s))
                puts("Stack is currently Full");
            else {
                puts("Current Stack size");

                printf("l_Stack: %d\n", l_Size(&s));
                printf("r_Stack: %d\n", r_Size(&s));
            }
            break;
        
        case 7:
            printf("Searching for?: ");
            scanf_s("%d", &data);

            if (l_Search(&s, data) == -1) 
                puts("No such data at l_Stack");
            else {
                printf("%d is at index %d", data, l_Search(&s, data));  
            }

            if (r_Search(&s, data) == -1)
                puts("No such data at r_Stack");
            else {
                printf("%d is at r_stk[%d]\n", data, r_Search(&s, data));
            }
            
            break;
        default:
            break;
        }
    }
    Terminate(&s);

    return 0;
}
