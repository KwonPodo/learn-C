// int형 큐를 사용하는 프로그램에 임의의 데이터를 검색하는 함수를 추가하세요
// Search2 함수는 찾은 요소의 인덱스를 반환하지 않고,
// 찾은 데이터가 front에 위치한 데이터로부터 상대적으로 몇 번째 위치에 있는 지에 대한 인덱스 값을 반환합니다.
// 검색 실패 시 -1을 반환합니다.

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int front, rear;
    int max;
    int num;
    int *que;
}IntQueue;

int Init(IntQueue *q, int max) {
    q->num = q->front = q->rear = 0;
    if ((q->que = (int*)calloc(max, sizeof(int))) == NULL) {
        q->max = 0; // 존재하지 않는 배열에 다른 함수가 접근하지 못하도록 방지.
        return -1;
    }

    q->max = max;

    return 0;
}

int Enque(IntQueue *q, int data) {
// 1. 큐가 가득 차있는지 확인
    if (IsFull(q)) {
        return -1; // Queue is Full
    } else {
// 2. 큐의 rear에 데이터 추가 후 q->num + 1, q->rear + 1
// 3. 데이터 추가 후에 확정된 q->rear가 배열의 끝을 넘어설 경우 체크
//      넘어선다면, q->rear = 0으로 다음 데이터 추가 인덱스를 0을 배열 앞으로 지정.
        q->que[q->rear++] = data;
        q->num++;
        if (q->rear >= q->max) { // 배열의 끝에 도달할 경우
            q->rear = 0;
            
        }
        
        return 0;
    }
    
    

}

int Deque(IntQueue *q, int *data) {
// 1. 큐가 비어 있는지 확인
    if (IsEmpty(q)) {
        return -1;
    }
// 2. 확인 후, q->front에서 데이터를 뽑은 뒤 q->front++, q->num--
// 3. 데이터를 빼낸 후, q->front가 배열의 끝을 넘어설 경우 확인
//      넘어선다면, q->front = 0으로 다음 디큐 인덱스를 0으로 지정.
    *data = q->que[q->front++];
    q->num--;

    if (q->front >= q->max) {
        q->front = 0;
    }

    return 0;
}

void Print(const IntQueue *q) {
    int i, idx;
    
    if (IsEmpty(q)) {
        printf("No data to Print. Queue is Empty\n");
    } else {
        for (i = 0; i < q->num; i++) {
            printf("%d ", q->que[(i + q->front) % q->max]);
        }
        puts("");
    }

}

int IsEmpty(const IntQueue *q) {
    return q->num <= 0;
}

int IsFull(const IntQueue *q) {
    return q->num >= q->max;
}

void Terminate(IntQueue *q) {
    if (q->que != NULL) {
        free(q->que);
    }
    q->front = q->rear = q->num = q->max = 0;
}

int Size(const IntQueue *q) {
    return q->num;
}

int Capacity(const IntQueue *q) {
    return q->max;
}

int Search(const IntQueue *q, int data) {
    int i, idx;

    for (i = 0; i < q->num; i++) {
        idx = (i + q->front) % q->max;
        if (q->que[idx] == data) {
            return idx;
        }
    }

    return -1;
}

int Peek(const IntQueue *q, int *data) {
    return q->que[q->front];
}

void Clear(IntQueue *q) {
    q->num = 0;
    q->front = q->rear = 0;
}

int Search2(const IntQueue * q, int data) {
    int i;

    for (i = 0; i < q->num; i++) {
        if (q->que[(q->front + i) % q->max] == data) {
            return i;
        }
    }
    return -1;
}

int main() {
    IntQueue que;
    int data, menu, max, idx;

    printf("Max number of data: ");
    scanf_s("%d", &max);

    if (Init(&que, max) == -1) {
        printf("Initiating Queue failed\n");
        return 1;
    }
    while (1) {
        puts("");
        printf("Current Queue data: %d/%d\n", Size(&que), max);
        printf("Current front, rear status: %d, %d\n", que.front, que.rear);
        printf("Enter Action\n");
        printf("(1) Enque (2) Deque (3) Print (4) Clear (5) Peek (6) Search (7) Search2 (0) Terminate : ");
        scanf_s("%d", &menu);

        if (menu == 0) 
            break;
        
        switch (menu)
        {
        case 1:
            printf("Enter Data: ");
            scanf_s("%d", &data);

            if(Enque(&que, data) == -1)
                puts("Queue is Full. Cannot Enque given data");
            break;
        
        case 2:
            if (Deque(&que, &data) == -1)
                puts("Queue is Empty. No data to Deque from the Queue");
            
            printf("Dequeued data : %d\n", data);
            break;
        
        case 3:
            Print(&que);
            break;

        case 4:
            Clear(&que);
            break;
        
        case 5:
            Peek(&que, &data);
            printf("Peeked data: %d\n", data);
            break;
        
        case 6:
            printf("Enter data to Search for: ");
            scanf_s("%d", &data);

            if (idx = Search(&que, data) == -1) {
                printf("No such data\n");
                break;
            } else {
                printf("%d is at Idx %d\n", data, idx);
            }

        case 7:
            printf("Enter data to Search for: ");
            scanf_s("%d", &data);

            if (idx = Search2(&que, data) == -1) {
                printf("No such data\n");
                break;
            } else {
                return idx;
                break;
            }

        default:
            break;
        }
    }
    Terminate(&que);

    return 0;
}