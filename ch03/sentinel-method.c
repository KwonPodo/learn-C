// 선형 검색
#include <stdio.h>
#include <stdlib.h>

// 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 선형 검색
int sentinelSearch(int a[], int n, int key);

int main(void) {
    int i, nx, ky, idx;
    int *x;
    puts("선형검색");
    printf("요소 개수: ");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx + 1, sizeof(int));

    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf_s("%d", &x[i]);
    }

    printf("검색값: ");
    scanf_s("%d", &ky);

    idx = sentinelSearch(x, nx, ky);
    if(idx == -1) puts("검색에 실패했습니다.");
    else printf("%d는 x[%d]에 있습니다.\n", ky, idx);

    free(x);
}

// 보초를 키 값이 아닌 다른 데이터를 집어넣으면 어떻게 되는가?
int sentinelSearch(int a[], int n, int key) {
    int i = 0;

    a[n] = key;

    while(1) {
        // key값을 못찾으면,
        // if문에서 주어진 배열의 길이를 벗어나게된다 (segmentaition error)
        // 즉 while문에서만 의미가 있는 것이 바로 보초법이다.
        // Why? for문에서는 항상 배열의 끝을 체크하기 때문에 보초법이 의미가 없다.
        // 반면 while문은 break를 걸지 않는 이상 무한루프의 반복이기때문에
        // flag방식으로 while 루프를 벗어난 뒤, 벗어난 방식을 체크해야한다. 
        if (a[i] == key)
            break;
        i++;
    }

    return i == n ? -1 : i;
}