// Queue 구현

#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int max; // Capacity of the Queue
    int num; // Current number of data in the Queue
    int *que; // Pointer to the first element of the Que
} ArrayIntQueue;

int Init(ArrayIntQueue *q, int max) {
    if ((q->que = (int*)calloc(max, sizeof(int))) == NULL){
        q->max = 0;
        return -1;
    }

    q->max = max;
    q->num = 0;

    return 0;
}

int Enqueue(ArrayIntQueue *q, int data) {
    if (q->num >= q->max) return -1;

    q->que[q->num++] = data;

    return 0;
}

int Dequeue(ArrayIntQueue *q, int *data) {
    if (q->num <= 0) return -1;

    *data = q->que[0];

    for (int i = 1; i < q->num; i++) {
        q->que[i - 1] = q->que[i];
    }

    q->num--;

    return 0;
}

int Size(ArrayIntQueue *q) {
    return q->num;
}

void Print(ArrayIntQueue *q) {
    int i;

    if (q->num == 0) {
        printf("No Data to print in the Queue\n");
    }
    for (i = 0; i < q->num; i++) {
        printf("%d ", q->que[i]);
    }
    puts("");
}

int main() {
    ArrayIntQueue q;
    int menu, data;

    if (Init(&q, 8) == -1) {
        puts("Initiating Queue failed...");
        return 1;
    }

    while (1) {
        printf("Current Data Size: %d/8\n", Size(&q));
        printf("Select Action. (1) Enqueue (2) Dequeue (3) Print Queue (0) End Program : ");
        scanf_s("%d", &menu);

        if (menu == 0)
            break;
        
        switch (menu)
        {
        case 1:
            printf("Enter data: ");
            scanf_s("%d", &data);
            if (Enqueue(&q, data) == -1) {
                printf("Queue is Full. Can't Enqueue the given data\n");
            }

            break;

        case 2:
            if (Dequeue(&q, &data) == -1) {
            printf("Queue is Empty. Can't Dequeue data\n");
            }
            
            printf("Dequeued data: %d\n", data);
            break;
        
        case 3:
            printf("Printing datas in the queue\n");
            Print(&q);
            break;


        default:
            break;
        }
    }
}