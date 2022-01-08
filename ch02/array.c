// 배열에 관하여
#include <stdio.h>
#include <stdlib.h>

#define N 5   

void printArr() {
    int i;
    int a[N];
    for(i = 0; i< N; i++) {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    puts("각 요소의 값");
    for(i = 0; i < N; i++) {
        printf("a[%d]: %d\n", i, a[i]);
    }
}

// 배열 요솟값 초기화하며 선언
// 배열의 길이 구하기

void init() {
    int i;
    int a[5] = {1,2,3,4,5};
    int na = sizeof(a) / sizeof(a[0]);
    printf("배열 a의 요소 개수는 %d입니다.\n", na);

    for(i = 0; i < na; i++) {
        printf("a[%d] = %d\n", i , a[i]);
    }
}

//  변수의 메모리 동적 할당
void alloc() {
    int * x;
    x = calloc(1, sizeof(int));

    if(x == NULL) {
        puts("메모리 할당 실패");
    } else {
        *x = 5;
        printf("*x = %d\n", *x);
        free(x);
    }
}

// 배열의 메모리 동적할당
void arrayAlloc() {
    int i;
    int *a;
    int na;
    printf("요소 개수: ");
    scanf_s("%d", &na);
    
    a = calloc(na, sizeof(int));

    if (a == NULL) {
        puts("메모리 할당 실패");
    } else {
        printf("%d개의 정수를 입력하세요.\n", na);
        for(i = 0; i < na; i++) {
            printf("a[%d]:", i);
            scanf_s("%d", &a[i]);
        }
        printf("*a: %d\n", *a);

        for(i = 0; i < na; i++) {
            printf("a[%d]: %d\n", i, a[i]);
        }
        free(a);
    }
}

void printPtr() {
    int a[5] = {1, 2, 3, 4, 5};
    int *p;
    p = a;
    printf("&a: %p\n", &a);
    printf("&a[0]: %p\n", &a[0]);
    printf("a: %p\n", a);
    printf("a[0]: %d\n", a[0]);
    printf("a[1]: %d\n", a[1]);
    
    for(int i = 0; i < 5; i++) {
        printf("a + %d: %p\n", i, a + i);
        printf("*(a + %d) : %d\n", i, *(a+i));
    }

    printf("sizeof array a is: %d\n", sizeof(a));
    printf("sizeof *p is: %d\n", sizeof(*p));
    printf("sizeof p is: %d\n", sizeof(p));
    printf("sizeof a[0]: %d\n", sizeof(a[0]));
}

// 배열 요소의 최댓값 구하기
// 매개변수로 전달받은 인수는 배열이 아닌, 포인터이므로 배열의 전체 길이는 인수로 전달해주어야 함.
int maxof(const int *p, int n) {
    int i;
    int max = p[0];
    for (i = 0; i < n; i++){
        if(max < p[i])
            max = p[i];
    }
    printf("sizeof p: %d\n", sizeof(p));
    printf("sizeof p[0]: %d\n", sizeof(p[0]));
    
    return max;
}

// 배열 요소를 역순으로 정렬하기.
void reverseArr() {
    int a[] = {22, 57, 11, 32, 91, 68, 70};
    int len = sizeof(a) / sizeof(a[0]) - 1;
    printf("len: %d\n", len);
    int i, temp;

    for (i = 0; i < len / 2; i++) {
        temp = a[i];
        a[i] = a[len - i];
        a[len - i] = temp;
    }

    for (i = 0; i <= len; i++){
        printf("in reverseArr: a[%d]: %d\n", i, a[i]);
    }
}

void main() {
    ///init();
    //alloc();
    //arrayAlloc();
    //printPtr();

    // 배열 전달 및 배열 요소의 최댓값 구하기
    // int i;
    // int *height;
    // int number;

    // printf("Number of People: ");
    // scanf_s("%d", &number);

    // height = calloc(number, sizeof(int));

    // for(i = 0; i < number; i++) {
    //     printf("height[%d]: \n", i);
    //     scanf_s("%d", &height[i]);
    // }

    // printf("Max height of given people's height is %d.\n", maxof(height, number));

    reverseArr();
}