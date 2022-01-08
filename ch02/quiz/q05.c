#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, t, x, y) do {type t = x; x = y; y = t;} while (0);


void main(void) {
    int temp, num, i;
    int * a;

    printf("Enter the length of the array: ");
    scanf_s("%d", &num);

    a = calloc(num, sizeof(int));

    srand(time(NULL));

    for (i = 0; i < num; i++) {
        a[i] = rand() % 90;
        printf("%d ", a[i]);
    }

    puts("");

    for (i = 0; i < num; i++) {
        printf("a[%d]와 a[%d]를 교환합니다.\n", i, num - 1 -i);
        temp = a[i];
        a[i] = a[num - 1 - i];
        a[num - 1 - i] = temp;
    }

    printf("역순 정렬을 종료합니다.\n");

}