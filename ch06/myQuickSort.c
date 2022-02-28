#include <stdlib.h>
#include <stdio.h>

#define MAX 30

struct range
{
    int left;
    int right;
};

struct range stack[MAX] = {0};
int num = 0;

int isEmpty()
{
    return num <= 0;
}

int isFull()
{
    return num >=MAX;
}

int push(struct range part)
{
    if (isFull())
        return 0;
    else
    {
        stack[num++] = part;
        return 1;
    }
}

struct range pop()
{
    if (isEmpty())
    {
        struct range null = {.left = 0, .right = 0};
        return null;
    }
    else 
    {
        return stack[--num];
    }
}

int partition(int a[], int left, int right)
{
    int pivotIdx = left;
    int pivot = a[pivotIdx];
    int t;
    int i;

    left++;
    while (left < right)
    {
        while (pivot > a[left] && left <= right)
            left++;

        while (pivot < a[right] && left <= right)
            right--;
        
        if (left < right)
        {
            // swap
            t = a[left];
            a[left] = a[right];
            a[right] = t;
        }
    }
    
    // swap
    t = a[pivotIdx];
    a[pivotIdx] = a[right];
    a[right] = t;

    return right;
}

void quickSort_nr(int a[], int left, int right)
{
    int pivotIdx;
    struct range target;
    int cnt = 0;

    pivotIdx = partition(a, left, right);
    // 오른쪽 부분의 범위
    struct range new1 = {.left = pivotIdx + 1, .right = right};
    // 왼쪽 부분의 범위
    struct range new2 = {.left = left, .right = pivotIdx - 1};

    push(new1); push(new2);
    
    while (!isEmpty())
    {
        target = pop();
        printf("target.left: %d\ttarget.right: %d\n", target.left, target.right);
        if (cnt++ == 5) break;

        pivotIdx = partition(a, target.left, target.right);
        printf("pivotIdx: %d, cnt: %d\n", pivotIdx, cnt);
        puts("");

        if (target.right > pivotIdx + 1)
        {
            

            new1.left = pivotIdx + 1; 
            new1.right = right;
            push(new1);
        }

        if (pivotIdx > target.left + 1)
        {
            new2.left = target.left;
            new2.right = pivotIdx - 1;

            push(new2);
        }
    }
}

void quickSort(int a[], int left, int right)
{
    int pivotIdx;
    if (right - left + 1 > 0)
    {
        pivotIdx = partition(a, left, right);
        quickSort(a, left, pivotIdx - 1);
        quickSort(a, pivotIdx + 1, right);
    }
}


int main()
{
    int a[] = { 5, 1, 6, 4, 8, 3, 7, 9, 2 };
    int i;

    // partition(a, 0, 8);
    // quickSort(a, 0, 8);
    quickSort_nr(a, 0, 8);

    for (i = 0; i < 9; i++)
    {
        printf("%d ", a[i]);
    }
    puts("");

}

// { 5, 1, 6, 4, 8, 3, 7, 9, 2 };