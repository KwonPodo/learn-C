#include <stdio.h>
#include <stdlib.h>


void downheap(int a[], int idx, int hn) {
    int tmp, leftIdx, rightIdx, biggerIdx, lastIdx;
    lastIdx = hn - 1;

    while (1) {
        if (idx > hn / 2 - 1) break;

        leftIdx = 2 * idx + 1;
        rightIdx = 2 * idx + 2;

        // 오른쪽 자식이 없다면 
        if (lastIdx < rightIdx) biggerIdx = leftIdx;
        else {
            biggerIdx = (a[leftIdx] < a[rightIdx]) ? rightIdx : leftIdx;
        }

        if (a[idx] < a[biggerIdx]) {
            // swap
            tmp = a[idx];
            a[idx] = a[biggerIdx];
            a[biggerIdx] = tmp;

            idx = biggerIdx;
        } else {
            break;
        }
    }
}

void heapSort(int a[], int n) {
    int i;

    for (i = n/2 - 1; i >= 0; i--) {
        downheap(a, i, n);
    }

    for (i = n - 1; i > 0; i--) {
        int tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;

        downheap(a, 0, i);
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