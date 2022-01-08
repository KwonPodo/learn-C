// 숫자가 아닌 문자열로 기둥 이름을 출력하도록 프로그램을 수정하세요.

#include <stdio.h>

void move(int n, int x, int y) {
    char name[] = {'A', 'B', 'C'};
    
    if (n > 1) move(n - 1, x, 6 - x - y);
    
    printf("원반[%d]를 기둥 %c에서 기둥 %c로 옮김", n, name[x - 1], name[y - 1]);

    if (n > 1) move(n - 1, 6 - x - y, y);
}

void main() {
    int n;
    int x = 1;
    int y = 3;
    printf("Enter a number : ");
    scanf_s("%d", &n);
    
    move(n, x, y);

}

