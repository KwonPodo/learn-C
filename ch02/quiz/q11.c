// dayofyear 함수를 변수 i와 days를 사용하지 않고 구현해 보시오. 또한 for문이 아닌 while문을 사용하시오.
#include <stdio.h>
#include <stdlib.h>

int mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* year년이 윤년인가? 
윤년의 조건:
년수가 4로 나누어 떨어지면 윤년이다.
년수가 4, 100, 400으로 나누어 떨어지면 윤년이다.
년수가 4, 100으로 나누어 떨어지면 평년으로 한다.
*/

int isleap(int year) {
    return year % 400 == 0 || year % 100 != 0 && year % 4 == 0;
}

/* year년 m월 d일의 그 해 지난 날 수를 구합니다. */
int dayofyear(int y, int m, int d) {
    int days_past = 0;
    int i;

    isleap(y) ? printf("%d년은 윤년입니다.\n") : printf("%d년은 평년입니다.\n");

    while(m > 0) {
        d += mdays[isleap(y)][m - 2];
        m--;
    }

    return d;
}

void main() {
    int year, month, day;
    int retry;

    do {
        printf("Year: "); scanf_s("%d", &year);
        printf("Month: "); scanf_s("%d", &month);
        printf("Day: "); scanf_s("%d", &day);
        
        printf("%d년의 %d일째입니다.\n", year, dayofyear(year, month, day));

        printf("Retry?(1-----Yes/0-----No:)");
        scanf_s("%d", &retry);

    } while (retry == 1);
}