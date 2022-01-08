#include <stdio.h>
#include <stdlib.h>

// 한 칸을 비워 두어서 가득 차있을 때와 비워져 있을 때를 구분할 수 있게끔 한다.
// 즉, q->front == q->rear 인 경우는 비어 있을 경우로만 한정된다.
// 들어있는 데이터의 개수를 세는 변수가 필요 없어진다.
typedef struct {
    int front; // 맨 앞 요소의 인덱스
    int rear; // 다음 요소를 넣을 곳을 가리키는 인덱스
    int max; 
    int *que;
} RingQue;

int Init(RingQue *q, int max) {
    if ((q->que = (int*)calloc(max + 1, sizeof(int) ) ) == NULL) {
        q->max = 0;
        return 0;
    } 
    q->max = q->front = q->rear = 0;

    return 1;
}

int IsEmpty(const RingQue *q) {
    return q->front == q->rear;
}

int IsFull(const RingQue *q) {
    return q->front == (q->rear + 1) % (q->max + 1);
}

int Enque(RingQue *q, int data) {
    if (IsFull(q))
        return 0;
    q->que[q->rear++] = data;

    if (q->rear >= q->max)
        q->rear = 0;
        
    return 1;
}

int Deque(RingQue *q, int *data){
    if (IsEmpty(q)) return 0;

    *data = q->que[q->front++];

    if (q->front >= q->max)
        q->front = 0;

    return 1;
}

void Terminate(RingQue *q) {
    if (q->que != NULL) {
        free(q->que);
    }
    q->front = q->rear = q->rear = 0;

}

int main() {
    int i, max, data, menu;
    RingQue q;

    printf("Enter max length of the QueArray: ");
    scanf_s("%d", &max);

    if (!Init(&q, max)) {
        puts("Initiating Que failed....");
        return 0;
    }

    while (1) {
        if (menu == 0) break;

        puts("");
        printf("Enter Action\n");
        printf("(1) Enque (2) Deque (3) Print (0) Terminate : ");
        scanf_s("%d", &menu);

        switch (menu)
        {
        case 1:
            printf("Enter data to Enque: ");
            scanf_s("%d", &data);

            Enque(&q, data);
            break;
        case 2:
            Deque(&q, &data);
            printf("Dequed data : %d\n", data);
            break;

        default:
            break;
        }
    }
    Terminate(&q);
}