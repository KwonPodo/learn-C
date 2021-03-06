// intํ ํ
#include <stdio.h>
#include <stdlib.h>

typedef struct ring_buffer {
    int front, rear; // front and rear of the ring queue
    int max; // max capacity of the queue
    int num; // number of the elements inside the queue
    int * que; // pointer towards the first element of the queue
} IntQueue;

// Initiate Queue
int Init(IntQueue *q, int max);

// Enqueue data into queue
int Enque(IntQueue *q, int data);

// Dequeue data from queue
int Deque(IntQueue *q, int *data);

// Peek data from queue
int Peek(const IntQueue *q, int *data);

// Clear all data int the queue
void Clear(IntQueue *q);

// Max Capacity of the queue
int Capacity(const IntQueue *q);

// Number of the data stored in the queue
int Size(const IntQueue *q);

// IsEmpty
int IsEmpty(const IntQueue *q);

// IsFull
int IsFull(const IntQueue *q);

// Search queue for the given data
int Search(const IntQueue *q, int data);

// Print datas in the queue
void Print(const IntQueue *q);

// Terminate Queue
void Terminate(IntQueue *q);



int main() {
    IntQueue que;
    int data, menu, max, idx;

    printf("Max number of data: ");
    scanf_s("%d", &max);

    if (!Init(&que, max)) {
        printf("Initiating Queue failed\n");
        return 1;
    }
    while (1) {
        puts("");
        printf("Current Queue data: %d/%d\n", Size(&que), max);
        printf("Current front, rear status: %d, %d\n", que.front, que.rear);
        printf("Enter Action\n");
        printf("(1) Enque (2) Deque (3) Print (4) Clear (5) Peek (6) Search (0) Terminate : ");
        scanf_s("%d", &menu);

        if (menu == 0) 
            break;
        
        switch (menu)
        {
        case 1:
            printf("Enter Data: ");
            scanf_s("%d", &data);

            if(!Enque(&que, data))
                puts("Queue is Full. Cannot Enque given data");
            break;
        
        case 2:
            if (!Deque(&que, &data))
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

            if (idx = Search(&que, data) == 0) {
                printf("No such data\n");
                break;
            } else {
                printf("%d is at Idx %d\n", data, idx);
            }
        default:
            break;
        }
    }
    Terminate(&que);

    return 0;
}

int Init(IntQueue *q, int max) {
    q->num = q->front = q->rear = 0;
    if ((q->que = (int*)calloc(max, sizeof(int))) == NULL) {
        q->max = 0; // ์กด์ฌํ์ง ์๋ ๋ฐฐ์ด์ ๋ค๋ฅธ ํจ์๊ฐ ์?๊ทผํ์ง ๋ชปํ๋๋ก ๋ฐฉ์ง.
        return 0;
    }

    q->max = max;

    return 1;
}

int Enque(IntQueue *q, int data) {
// 1. ํ๊ฐ ๊ฐ๋ ์ฐจ์๋์ง ํ์ธ
    if (IsFull(q)) {
        return 0; // Queue is Full
    } else {
// 2. ํ์ rear์ ๋ฐ์ดํฐ ์ถ๊ฐ ํ q->num + 1, q->rear + 1
// 3. ๋ฐ์ดํฐ ์ถ๊ฐ ํ์ ํ์?๋ q->rear๊ฐ ๋ฐฐ์ด์ ๋์ ๋์ด์ค ๊ฒฝ์ฐ ์ฒดํฌ
//      ๋์ด์?๋ค๋ฉด, q->rear = 0์ผ๋ก ๋ค์ ๋ฐ์ดํฐ ์ถ๊ฐ ์ธ๋ฑ์ค๋ฅผ 0์ ๋ฐฐ์ด ์์ผ๋ก ์ง์?.
        q->que[q->rear++] = data;
        q->num++;
        if (q->rear >= q->max) { // ๋ฐฐ์ด์ ๋์ ๋๋ฌํ? ๊ฒฝ์ฐ
            q->rear = 0;
            
        }
        
        return 1;
    }
    
    

}

int Deque(IntQueue *q, int *data) {
// 1. ํ๊ฐ ๋น์ด ์๋์ง ํ์ธ
    if (IsEmpty(q)) {
        return 0;
    }
// 2. ํ์ธ ํ, q->front์์ ๋ฐ์ดํฐ๋ฅผ ๋ฝ์ ๋ค q->front++, q->num--
// 3. ๋ฐ์ดํฐ๋ฅผ ๋นผ๋ธ ํ, q->front๊ฐ ๋ฐฐ์ด์ ๋์ ๋์ด์ค ๊ฒฝ์ฐ ํ์ธ
//      ๋์ด์?๋ค๋ฉด, q->front = 0์ผ๋ก ๋ค์ ๋ํ ์ธ๋ฑ์ค๋ฅผ 0์ผ๋ก ์ง์?.
    *data = q->que[q->front++];
    q->num--;

    if (q->front >= q->max) {
        q->front = 0;
    }

    return 1;
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

    return 0;
}

int Peek(const IntQueue *q, int *data) {
    return q->que[q->front];
}

void Clear(IntQueue *q) {
    q->num = 0;
    q->front = q->rear = 0;
}