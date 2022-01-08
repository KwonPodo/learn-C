#include <stdio.h>
#include <stdlib.h>

struct stack {
    int max;
    int num;
    int stk[256];
};

struct stack stk = {.max = 256, .num = 0, .stk = {0}};

int isEmpty() {
    return stk.num <= 0;
}

void Push(int n) {
    if (stk.num < stk.max) {
        stk.stk[stk.num++] = n;
    }
}

void Pop(int *n) {
    if (stk.num > 0 ) {
        *n = stk.stk[--stk.num];
    }
}

void quick_nr(int a[], int n) {
    int left, right, pivot, pivotIdx;
    int left_end, right_end;
    int t;

    left_end = left = 0;
    right_end = right = n - 1;

    Push(left);
    Push(right);

    while (!isEmpty()) {
            Pop(&right);
            Pop(&left);
            if (left >= right) continue;

            left_end = left;
            right_end = right;
            pivotIdx = (left + right) / 2;
            pivot = a[pivotIdx];

            while (1) {
                while (a[left] < pivot) left++;
                while (a[right] > pivot) right--;

                t = a[left];
                a[left] = a[right];
                a[right] = t;

                if (left >= right) break;
            }
            pivotIdx = left;

            Push(pivotIdx + 1);
            Push(right_end);

            Push(left_end);
            Push(pivotIdx - 1);
        }
}

void main() {
    int i, nx;
    int *x;

    InitStack(256);

    puts("배열을 나눈다.");
    printf("Number of elements: ");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++){
        printf("x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    quick(x, nx);


    for (i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    puts("");
    free(x);

}