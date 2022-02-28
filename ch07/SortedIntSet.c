#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

int Init(intSet *s, int max) {
    if ((s->set = (int*)calloc(max, sizeof(int))) == NULL) {
        s->max = 0;
        return 0;
    }

    s->max = max;
    s->num = 0;

    return 1;
}

int isFull(const intSet *s) {
    return s->num >= s->max;
}

int isEmpty(const intSet *s) {
    return s->num <= 0;
}

int binary_search(const intSet *s, int key) {
    int left, center, right;
    left = 0;
    right = s->num - 1;
    center = (left + right) / 2;

    while (left <= right) {
        if (s->set[center] < key) {
            left = center + 1;
            center = (left + right) / 2;
        } else if (s->set[center] > key) {
            right = center - 1;
            center = (left + right) / 2;
        } else {
            return center;
        }
    }

    return -1;
}

void bubble_sort(intSet *s) {
    int i, j;
    int max;

    // for (i = 0; i < s->num; i++) {
    //     for (j = s->num - 1; j > i; j--) {
    //         if (s->set[j - 1] > s->set[j]) {
    //             // swap
    //             int temp = s->set[j];
    //             s->set[j] = s->set[j - 1];
    //             s->set[j - 1] = temp;
    //         }
    //     }
    // }

    for (i = (s->num - 1); i > 0; i--) {
        // Pass
        for (j = 0; j < i; j++) {
            if (s->set[j] > s->set[j + 1]) {
                // swap
                int tmp = s->set[j];
                s->set[j] = s->set[j + 1];
                s->set[j + 1] = tmp;
            }
        }
    }
}

void selection_sort(intSet *s) {
    int i, j;
    int m_idx;

    for (i = 0; i < s->num; i++) {
        m_idx = i;
        for (j = i + 1; j < s->num; j++) {
            if (s->set[m_idx] > s->set[j]) {
                m_idx = j;
            }
        }
        // swap
        int t = s->set[m_idx];
        s->set[m_idx] = s->set[i];
        s->set[i] = t;
    }
}

void insertion_sort(intSet *s) {
    int i, j;

    for (i = 1; i < s->num; i++) {
        int tmp = s->set[i];
        // 자신보다 작은 값이 나올때까지 찾는다.
        for (j = i; j >= 0; j--) {
            if (s->set[j - 1] >= tmp) {
                s->set[j] = s->set[j - 1];
            } else {
                s->set[j] = tmp;
                break;
            }
        }
    }
}

int isMember(const intSet *s, int n) {
    int i;
    if (binary_search(s, n) == -1) {
        return 0;
    } else {
        return 1;
    }
}

void Add(intSet *s, int n) {
    // Find Redundant member 
    int i;
    int flag = 1;

    if (!isMember(s, n) && s->num < s->max) {
        for (i = s->num++; i >= 0; i--) {
            if (s->set[i - 1] >= n) {
                s->set[i] = s->set[i - 1];
            } else {
                s->set[i] = n;
                break;
            }
        }
    }
}

void Remove(intSet *s, int n) {
    // Search for matching element
    int i;

    i = binary_search(s, n);

    if (i == -1) {
        printf("No such data\n");
    } else {
        for (i; i < s->num - 1; i++) {
            // swap
            int tmp = s->set[i];
            s->set[i] = s->set[i + 1];
            s->set[i + 1] = tmp;
        }
        s->num--;
    }
}

void Print(const intSet *s) {
    int i;

    printf("{ ");
    for (i = 0; i < s->num; i++) {
        printf("%d ", s->set[i]);
    }
    printf(" }\n");
}

void PrintLn(const intSet *s) {
    Print(s);
    puts("");
}

void Terminate(intSet *s) {
    if (s->set != NULL) {
        free(s->set);
    }
    s->num = s->max = 0;
}

int main() {
    intSet s1, s2, s3;
    Init(&s1, 24);
    Init(&s2, 24);
    Init(&s3, 24);

    // s1 = { 1, 2, 3, 6, 7 }
    Add(&s1, 1);
    Add(&s1, 3);
    Add(&s1, 6);
    Add(&s1, 2);
    Add(&s1, 7);

    PrintLn(&s1);

    // bubble_sort(&s1);
    // selection_sort(&s1);
    // insertion_sort(&s1);
    Remove(&s1, 3);
    Remove(&s1, 1);
    PrintLn(&s1);

    Terminate(&s1);
    Terminate(&s2);
    Terminate(&s3);
}