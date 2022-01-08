/**
 * 병합정렬 (Merge Sort)
 * 병합을 수행하는 단위를 가장 작은 1에서부터 전체 배열의 크기 N까지 2배씩 늘려가면서 병합을 반복하여 정렬하는 알고리즘.
 * 
 * 병합을 위해서는 비교하는 두 배열이 모두 정렬되어 있어야 한다.
 * 
 * 1. size = 1
 * 2. size < N일 동안
 *  2.1 size의 크기로 배열을 분할하여 두 분할씩 차례로 병합
 *  2.2 size *= 2
 */

#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int b[], int na, int nb) {
    int pa, pb, pc;
    int nc;
    int *c;

    nc = na + nb;
    c = (int*)calloc(nc, sizeof(int));

    pa = pb = pc = 0;

    while (pc < nc) {
        while (pa < na && pb < nb) {
            c[pc++] = (a[pa] < b[pb]) ? a[pa++] : b[pb++];
        }

        while (pa < na) {
            c[pc++] = a[pa++];
        }
        
        while (pb < nb) {
            c[pc++] = b[pb++];
        }
    }

    for (int i = 0; i < nc; i++) {
        a[i] = c[i];
    }

    free(c);

}

void merge_sort(int x[], int n) {
    int size;
    int size_b;
    int pa, pb;
    
    size = 1;

    while (size < n) {
        pa = 0;
        pb = size;
        size_b = (n % size == 0) ? size : n % size;
        while (pa < n) {
            merge(&x[pa], &x[pb], size, size_b);
            pa = pb + size;
            pb = pa + size;

            if (pb >= n) {
                size_b = 0;
            }
        }
        size *= 2;
    }
}

void merge_sort_r(int x[], int left, int right) {
    int center, n;
    int *temp;
    center = (left + right) / 2;
    n = right - left + 1;
    
    if (n > 1) {
        merge_sort_r(x, left, center);
        merge_sort_r(x, center + 1, right);

        merge(&x[left], &x[center + 1], center - left + 1, right - center);
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

    merge_sort_r(x, 0, nx - 1);

    puts("Sorted Array");
    for(i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }
    
    puts("");

    free(x);

}