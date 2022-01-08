// bsearch 함수를 사용해 내림차순으로 정렬된 배열을 검색합니다
#include <stdio.h>
#include <stdlib.h>

// 정수를 비교하는 함수(내림차순)
int int_cmpr(const int *a, const int *b) {
    if (*a < *b)
        return 1;
    else if (*a > *b) 
        return -1;
    else 
        return 0;
}

int main() {
    int i, nx, ky;
    int *x, *p;
    
    puts("Search using bsearch function");
    printf("Number of elements: ");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(nx));

    printf("내림차순으로 입력하세요.\n");
    printf("x[0]: ");
    scanf_s("%d", &x[0]);

    for (i = 1;i < nx; i++) {
        do {
            printf("x[%d]: ", i);
            scanf_s("%d", &x[i]);
        } while (x[i] > x[i - 1]);
    }

    printf("검색값: ");
    scanf_s("%d", &ky);

    p = bsearch(&ky, x, nx, sizeof(int), (int(*)(const void*, const void *))int_cmpr);
    if (p == NULL)
        puts("Searching failed...");
    else 
        printf("%d is int x[%d].\n", ky, (int)(p - x));
    
    free(x);

    return 0;
}