#include <stdio.h>
#include <stdlib.h>

void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *)) {
    size_t i;
    int * x = (int*)base;

    for (i = 0; i < nmemb; i++) {
        if (!(*compar)(key, (const void*)&x[i*size]))
            return (&x[i*size]);
    }
    if (i == nmemb)
        return NULL;
}

int int_cmp(int * a, int * b) {
    if (*a < *b)
        return -1;
    else if (*a > *b) 
        return 1;
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

    printf("오름차순으로 입력하세요.\n");
    printf("x[0]: ");
    scanf_s("%d", &x[0]);

    for (i = 1;i < nx; i++) {
        do {
            printf("x[%d]: ", i);
            scanf_s("%d", &x[i]);
        } while (x[i] < x[i - 1]);
    }

    printf("검색값: ");
    scanf_s("%d", &ky);

    p = seqsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *)) int_cmp);

    if (p == NULL)
        puts("Searching failed...");
    else 
        printf("%d is int x[%d].\n", ky, (int)(p - x));
    
    free(x);

    return 0;
}