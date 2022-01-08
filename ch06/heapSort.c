/*
    힙 정렬 (Heap Sort)

*/
#include <stdio.h>
#include <stdlib.h>

void makeHeap(int a[]);

void heapSort(int a[], int n){
    int t, i;
    int exchange_nodeIdx;

    makeHeap(a);

    while (1) {
        // 루트를 뽑아서 배열의 마지막과 스왑한다.
        t = a[0];
        a[0] = a[n - 1];
        a[n - 1] = t;

        i = 0;
        // 루트를 제외한 나머지는 힙 상태이므로 루트와 바꿔치기한 말단의 노드만 제자리를 찾으면 된다.
        while(1) {
            // 방식은 자신보다 큰 자식 노드들 중, 가장 값이 큰 노드와 교환하는 식으로 리프에 도달하거나 자식들이 자신보다 커질 때까지 내려간다.
            // 힙 상태를 유지하기 위해서이다.

            exchange_nodeIdx = (a[i * 2 + 1] < a[i * 2 + 2]) ? a[i * 2 + 2] : a[i * 2 + 1];
            t = a[exchange_nodeIdx];
            a[exchange_nodeIdx] = a[i];
            a[i] = t;

            i = exchange_nodeIdx;
        }
    }

}

void main() {
    int i, nx;
    int *x;

    printf("Enter number of elements in X: ");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    for(i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    puts("");

    puts("Given Array");

    for(i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");

    heapSort(x, nx);

    puts("Sorted Array");
    for(i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    
    puts("");

    free(x);

}