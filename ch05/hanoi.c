#include <stdio.h>
int cnt = 0;
// 원반 [1] ~ [n]을 x 기둥에서 y 기둥으로 옮김
void move(int n, int x, int y) {
    // 1. 1 ~ n - 1을 가운데 기둥으로 옮김
    // 2. n을 y 기둥으로 옮김
    // 3. 1 ~ n - 1을 y 기둥으로 옮김
    if (n > 1) 
        move(n - 1, x, 6 - x- y);

    printf("원반[%d]를 %d 기둥에서 %d 기둥으로 옮김 cnt: %d\n", n, x, y, ++cnt);

    if (n > 1)
        move(n - 1, 6 - x - y, y);
}

int main () {
    int n; // 원반의 개수
    int start_pillar = 1; // 시작 기둥
    int end_pillar = 3; // 목표 기둥
    printf("Hanoi\n원반 개수 : ");
    scanf_s("%d", &n);

    move(n, start_pillar, end_pillar);

    return 0;
}