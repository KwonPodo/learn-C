// 오래된 데이터를 버리는 용도
// 링 버퍼, 순환 큐는 
// 요소의 개수가 n인 배열에 계속해서 데이터가 입력될 때 
// 가장 최근에 들어온 데이터 n개만 저장하고 오래된 데이터는 버리는 용도로 사용할 수 있다.

// 원하는 개수만큼 데이터를 입력하고, 요소의 개수가 n인 배열에는 최근에 입력한 n개만 저장

#include <stdio.h>
#define N 4

int main() {
    int i;
    int cnt = 0;
    int retry;
    int a[N];
    
    puts("Enter an integer\n");

    do {
        printf("%dth integer : ", cnt + 1);
        scanf_s("%d", &a[cnt++ % N]);
        printf("Continue? Yes --- 1 / No --- 0 : ");
        scanf_s("%d", &retry);
    } while (retry == 1);

    i = cnt - N;
    // cnt < N 이므로 처음부터 요소 개수만큼 출력해도 무관하다
    if (i < 0) {
        i = 0;
        for (i; i < cnt; i++) {
            printf("%2dth integer = %d\n", i + 1, a[i % N]);
        }
    } else {
    // cnt > N인 경우
    for (; i < N; i++) 
        printf("%2dth integer = %d\n", i + 1, a[i % N]);
    }
    puts("");

    // i = 저장한 데이터 수와 최대 배열 길이의 차이
    i = cnt - N;
    // 그 차이 와 cnt 사이의 간격은 최대 배열 길이 N이므로 cnt까지 i를 증가
    // print하는 인덱스는 i % N으로 오래된 배열 cnt - N부터 차례대로 순환하며 프린트
    for(i; i < cnt; i++) {
        printf("%2dth integer = %d\n", i + 1, a[i % N]);
    }
    
    return 0;
}