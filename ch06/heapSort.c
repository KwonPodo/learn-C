/*
    힙 정렬 (Heap Sort)

    힙 : 부모 > 자식
    Upheap : 새로 삽입된 자료가 규칙에 맞게 지위가 상승하는 작동
    Downheap : 힙의 상단을 차지하던 자료를 힙의 규칙에 맞게 지위가 끌어내리는 동작

*/
#include <stdio.h>
#include <stdlib.h>

// 힙을 저장한 배열과 지위를 상승시킬 노드의 인덱스를 입력받아 힙의 조건에 맞게 지위를 상승시킨다.
void upheap_bubble(int a[], int i) {
    int cmpIdx = (i - 1) / 2;
    
    while (i > 0 && a[cmpIdx] < a[i]) {
        int tmp = a[cmpIdx];
        a[cmpIdx] = a[i];
        a[i] = tmp;

        i = cmpIdx;
    }
}

void upheap_insert(int a[], int i) {
    int parentIdx = (i - 1) / 2;

    int copy = a[i];
    while (i > 0 && a[parentIdx] < a[i]) {
        a[i] = a[parentIdx];

        i = parentIdx;
    }

    a[i] = copy;
}

// 힙을 저장한 배열과 힙의 노드개수, 그리고 하강시킬 노드의 인덱스를 입력받아 강등시킨다.
void downheap(int a[], int i, int hn) {
    int cmpIdx, tmp;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    tmp = a[i];

    while ((i <= (hn - 1) / 2) && (a[i] < a[left] || a[i] < a[right])) {
        cmpIdx = (a[left] < a[right]) ? a[right] : a[left];

        a[i] = a[cmpIdx];
        i = cmpIdx;

    }
    
    a[i] = tmp;
}


// 힙의 말단에 새로운 노드를 추가하고 그것을 업힙한다.
void insert (int a[], int *hn, int key) {
    a[*hn] = key;
    upheap_insert(a, *hn);

    (*hn)++;
}

// 배열과 힙의 노드수를 입력받아 힙의 뿌리를 리턴하며,
// 힙의 노드수를 하나 감소시키고 뿌리에 힙의 말단 노드를 집어넣어 다운힙을 수행한다.
int extract (int a[], int *hn) {
    int root = a[0];

    int tmp = a[*hn];
    a[*hn] = root;
    root = a[*hn];

    (*hn)--;
    downheap(a, 0, *hn);

    return root;

}

void heapSort(int a[], int n){
    int i;
    // 하향식 힙 생성을 이용한 힙 정렬
    // 힙의 노드 수
    int heapNodes = 0;

    for (i = 0; i < n; i++) {
        // 배열의 값을 차례대로 힙에 삽입
        insert(a, &heapNodes, a[i]);
    }

    // 힙의 최댓값을 꺼내어 역순으로 저장.
    for (i = heapNodes; i >= 1; i--) {
        a[i] = extract(a, &heapNodes);
    }
}

int main() {
    int i, nx;
    int *x;

    printf("Enter number of elements in X: ");
    scanf("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    for(i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
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

    return 1;
}

