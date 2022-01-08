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

int factorial(int n) {
    if (n <= 0) return 1;
    else {
        return n * factorial(n - 1);
    }

}

int factorial_nr(int n) {
    int sum = 1;

    while (n > 0) {
        sum = sum * n--;
    }

    return sum;
}

// f(n) = f(n - 1) + f(n - 2), 단 f(1) = f(2) = 1
int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int fibonacci_nr(int n) {
    int sum = 0;

    Push(n - 2);
    Push(n - 1);
    while(!isEmpty()) {
        Pop(&n);
        if (n == 1 || n == 2) {
            sum += 1;
            continue;
        } else {
            Push(n - 2);
            Push(n - 1);
            continue;
        }
    }

    return sum;
}

void r(int n) {
    if (n > 0) {
        printf("%d ", n);
        r(n - 1);
        r(n - 2);
    }
}

void r_nr(int n) {
    Push(n);

    while (!isEmpty()) {
        Pop(&n);
        if (n <= 0) continue;
        else {
            printf("%d ", n);
            Push(n - 2);
            Push(n - 1);
            continue;
        }
    }
}

void r2(int n) {
    if (n > 0) {
        r2(n - 1);
        printf("%d ", n);
        r2(n - 2);
    }
}

void r2_nr(int n) {
    int prev;

    while (1) {
        while (n >= 0) {
            Push(n);
            n = n - 1;
        }
        
        if (!isEmpty()) {
            Pop(&n);

            // process
            if (n > 0) {
                printf("%d ", n);
            }
            n = n - 2;
        } else {
            break;
        }
    }
}

int partition(int a[], int n) {
    int left, right, pivot, pivotIdx;
    int left_end, right_end;
    int t;

    left_end = left = 0;
    right_end = right = n - 1;
    pivotIdx = (left + right) / 2;
    pivot = a[pivotIdx];

    while (1) {
        // a[left] >= pivot을 찾을때까지 
        while(a[left] < pivot) left++;
        // a[right] <= pivot을 찾을떄까지
        while(a[right] > pivot) right--;

        //swap
        t = a[left];
        a[left] = a[right];
        a[right] = t;

        if (left >= right) break;
    }

    return left;
}

void quick_r2(int a[], int n) {
    int left, right, pivot, pivotIdx;
    int left_end, right_end;
    int t;

    
    if (n > 1) {
        left_end = left = 0;
        right_end = right = n - 1;
        pivotIdx = (left + right) / 2;
        pivot = a[pivotIdx];

        while (1) {
            // a[left] >= pivot을 찾을때까지 
            while(a[left] < pivot) left++;
            // a[right] <= pivot을 찾을떄까지
            while(a[right] > pivot) right--;

            //swap
            t = a[left];
            a[left] = a[right];
            a[right] = t;

            if (left >= right) break;
        }

        pivotIdx = left;

        quick_r2(a, pivotIdx);
        quick_r2(&a[pivotIdx + 1], n - pivotIdx - 1);
    }
}

void quick_r(int a[], int n) {
    int left, right, pivot, pivotIdx;
    int left_end, right_end;
    int t;

    
    if (n > 1) {
        pivotIdx = partition(a, n);

        quick_r(a, pivotIdx);
        quick_r(&a[pivotIdx + 1], n - pivotIdx - 1);
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
    int n = fibonacci(6);

    // printf("%d\n", fibonacci(5));
    // printf("%d\n", fibonacci_nr(5));
    // r(3);
    // puts("");
    // r_nr(3);
    // puts("");
    // r2(4);
    // puts("");
    // r2_nr(4);
    // puts("");

    int a[] = {1, 8, 7, 4, 5, 2, 6, 3, 9};
    int b[] = {5, 8, 4, 2, 6, 1, 3, 9, 7};
    int c[] = {5, 7, 1, 4, 6, 2, 3, 9, 8};
    // quick_r2(a, 9);
    // quick_r2(b, 9);
    // quick_r2(c, 9);

    quick_nr(a, 9);
    quick_nr(b, 9);
    quick_nr(c, 9);

    for (int i = 0; i < 9; i++) {
        printf("%d ", a[i]);
    }
    puts("");
    for (int i = 0; i < 9; i++) {
        printf("%d ", b[i]);
    }
    puts("");
    for (int i = 0; i < 9; i++) {
        printf("%d ", c[i]);
    }
    puts("");
}