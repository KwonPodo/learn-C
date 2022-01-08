// 키와 함께 사람 수도 난수로 생성하도록 하는 프로그램을 작성하시오.
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void main(void) {
    int i, number;
    int *height;
    
    srand(time(NULL));

    number = rand() % 10;

    height = calloc(number, sizeof(int));


    for (i = 0; i < number; i++) {
        height[i] = 100 + rand() % 90;
    }

    printf("Random number generated: %d\n", number);
    for (i = 0; i < number; i++) {
        printf("%d ", height[i]);
    }

    free(height);
}