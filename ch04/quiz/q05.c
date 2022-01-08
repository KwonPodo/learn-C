// 일반적으로 덱(Deque)이라는 양방향 큐(deque/double ended queue)는
// 시작과 끝 지점에서 양쪽으로 데이터를 인큐하거나 디큐하는 자료구조이다.
// 양방향 대기열을 구현하는 프로그램을 만드세요.
// 일반큐로 구현한 양방향 큐
#include <stdio.h>
#include <stdlib.h>

typedef struct double_ended_queue {
    int max;
    int num;
    int *que;
}IntDeque;

int IsEmpty(const IntDeque *q) {
    return q->num <= 0;
}

int IsFull(const IntDeque *q) {
    return q->num >= q->max;
}

int Init(IntDeque *q, int max) {
    q->num = 0;
    if ((q->que = (int*)calloc(max, sizeof(int))) == NULL) {
        q->max = 0; // 존재하지 않는 배열에 다른 함수가 접근하지 못하도록 방지.
        return 0;
    }

    q->max = max;

    return 1;
}

int Enque(IntDeque *q, int data) {
    if (IsFull(q)) return 0;
    else {
        q->que[q->num++] = data;

        return 1;
    }
}

int Deque(IntDeque *q, int *data) {
    if (IsEmpty(q)) return 0;
    else {
        *data = q->que[0];
        q->num--;

        for (int i = 1; i < q->num; i++) {
            q->que[i - 1] = q->que[i];
        }

        return 1;
    }
}


void Print(const IntDeque *q) {
    int i, idx;
    
    if (IsEmpty(q)) {
        printf("No data to Print. Deque is Empty\n");
    } else {
        for (i = 0; i < q->num; i++) {
            printf("%d ", q->que[i]);
        }
        puts("");
    }

}


void Terminate(IntDeque *q) {
    if (q->que != NULL) {
        free(q->que);
    }
    q->num = q->max = 0;
}

int Size(const IntDeque *q) {
    return q->num;
}

int Capacity(const IntDeque *q) {
    return q->max;
}

int Search(const IntDeque *q, int data) {
    int i, idx;

    for (i = 0; i < q->num; i++) {
        if (q->que[i] == data) {
            return i;
        }
    }

    return -1;
}

int Peek(const IntDeque *q, int *data) {
    return q->que[0];
}

void Clear(IntDeque *q) {
    q->num = 0;
}


int main() {
    IntDeque que;
    int data, menu, max, idx;

    printf("Max number of data: ");
    scanf_s("%d", &max);

    if (!Init(&que, max)) {
        printf("Initiating Deque failed\n");
        return 1;
    }
    while (1) {
        puts("");
        printf("Current Deque data: %d/%d\n", Size(&que), max);
        printf("Enter Action\n");
        printf("(1) Enque (2) Deque (3) Print (4) Clear (0) Terminate : ");
        scanf_s("%d", &menu);

        if (menu == 0) 
            break;
        
        switch (menu)
        {
        case 1:
            printf("Enter Data: ");
            scanf_s("%d", &data);

            if(!Enque(&que, data))
                puts("Deque is Full. Cannot Enque given data");
            break;
        
        case 2:
            if (!
            
            Deque(&que, &data))
                puts("Deque is Empty. No data to Deque from the Deque");
            
            printf("Dequeued data : %d\n", data);
            break;
        
        case 3:
            Print(&que);
            break;

        case 4:
            Clear(&que);
            break;

        default:
            break;
        }
    }
    Terminate(&que);

    return 0;
}