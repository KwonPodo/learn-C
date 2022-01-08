// 일반적으로 덱(Deque)이라는 양방향 큐(deque/double ended queue)는
// 시작과 끝 지점에서 양쪽으로 데이터를 인큐하거나 디큐하는 자료구조이다.
// 양방향 대기열을 구현하는 프로그램을 만드세요.
// 순환큐로 구현한 양방향 큐
#include <stdio.h>
#include <stdlib.h>

typedef struct double_ended_queue {
    int front, rear;
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
    q->num = q->front = q->rear = 0;
    if ((q->que = (int*)calloc(max, sizeof(int))) == NULL) {
        q->max = 0; // 존재하지 않는 배열에 다른 함수가 접근하지 못하도록 방지.
        return 1;
    }

    q->max = max;

    return 0;
}

int front_Enque(IntDeque *q, int data) {
    if (q->num >= q->max) {
        return -1;
    } else {
        q->front--;
        if (q->front <= 0) {
            q->front = q->max - 1;
        }
        q->que[q->front] = data;
        q->num++;

        return 0;
    }
}

int rear_Enque(IntDeque *q, int data) {
    if (IsFull(q)) {
        return -1;
    } else {
        q->que[q->rear++] = data;
        q->num++;

        if (q->rear >= q->max)
            q->rear = 0;

        return 0;
    }
}

int front_Deque(IntDeque *q, int *data) {
    if (IsEmpty(q)) {
        return -1;
    } else {
        *data = q->que[q->front];
        q->front++;
        q->num--;
        
        if (q->front >= q->max) 
            q->front = 0;
        
        return 0;
    }
}

int rear_Deque(IntDeque *q, int *data) {
    if (q->num <= 0) {
        return -1;
    } else {
        *data = q->que[q->rear--];
        q->num--;

        if (q->rear < 0)
            q->rear = q->max;
        
        return 0;
    }
}

void Print(const IntDeque *q) {
    int i, idx;
    
    if (IsEmpty(q)) {
        printf("No data to Print. Deque is Empty\n");
    } else {
        for (i = 0; i < q->num; i++) {
            printf("%d ", q->que[(i + q->front) % q->max]);
        }
        puts("");
    }

}


void Terminate(IntDeque *q) {
    if (q->que != NULL) {
        free(q->que);
    }
    q->front = q->rear = q->num = q->max = 0;
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
        idx = (i + q->front) % q->max;
        if (q->que[idx] == data) {
            return idx;
        }
    }

    return -1;
}

int Peek(const IntDeque *q, int *data) {
    return q->que[q->front];
}

void Clear(IntDeque *q) {
    q->num = 0;
    q->front = q->rear = 0;
}


int main() {
    IntDeque que;
    int data, menu, max, idx;

    printf("Max number of data: ");
    scanf_s("%d", &max);

    if (Init(&que, max)) {
        printf("Initiating Deque failed\n");
        return 1;
    }
    while (1) {
        puts("");
        printf("Current Deque data: %d/%d\n", Size(&que), max);
        printf("Current front, rear status: %d, %d\n", que.front, que.rear);
        printf("Enter Action\n");
        printf("(1) front_Enque (2) front_Deque (3) Print (4) Clear (5) rear_Enque (6) rear_Deque (0) Terminate : ");
        scanf_s("%d", &menu);

        if (menu == 0) 
            break;
        
        switch (menu)
        {
        case 1:
            printf("Enter Data: ");
            scanf_s("%d", &data);

            if(front_Enque(&que, data) == -1)
                puts("Deque is Full. Cannot Enque given data");
            break;
        
        case 2:
            if (front_Deque(&que, &data) == -1)
                puts("Deque is Empty. No data to Deque from the Deque");
            
            printf("Dequeued data : %d\n", data);
            break;
        
        case 3:
            Print(&que);
            break;

        case 4:
            Clear(&que);
            break;
        
        case 5:
            printf("Enter Data: ");
            scanf_s("%d", &data);

            if(rear_Enque(&que, data) == -1)
                puts("Deque is Full. Cannot Enque given data");
            break;

        case 6:
            if (front_Deque(&que, &data) == -1)
                puts("Deque is Empty. No data to Deque from the Deque");
            
            printf("Dequeued data : %d\n", data);
            break;

        default:
            break;
        }
    }
    Terminate(&que);

    return 0;
}