// 배열 a의 모든 요소의 순서를 뒤섞는 shuffle 함수를 작성하시오. (n은 요소 개수);
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0);

void shuffle(int a[], int n);

void main(void) {
    int a[] = {0,1,2,3,4,5};
    int len = sizeof(a) / sizeof(int);

    puts("Printing a");
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    puts("");

    shuffle(a, len);

    puts("Printing shuffled a");
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }

}

void shuffle(int a[], int n) {
    int i, rand_i;
    srand(time(NULL));

    for (i = 0; i < n / 2; i++) {
        do {
        rand_i = rand() % (n + 1);
        } while (rand_i == i);

        swap(int, a[i], a[rand_i]);
    }
}