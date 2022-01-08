#include <stdio.h>
#include <stdlib.h>

// &arr은 배열 전체, arr은 하나의 행, arr[0]은 하나의 열을 가리키는 포인터.
// 년, 월, 일의 3개의 값이 주어지면 이를 이용해 해당하는 연도의 지난 날 수를 구하는 프로그램을 작성하시오.

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
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/* year년 m월 d일의 그 해 지난 날 수를 구합니다. */
int dayofyear(int y, int m, int d) {
    int days_past = 0;
    int i;

    isleap(y) ? printf("%d년은 윤년입니다.\n") : printf("%d년은 평년입니다.\n");

    for (i = 0; i < 12; i++) {
        if (i == m - 1) {
            days_past += d;
            break;
        }
        days_past += mdays[isleap(y)][i];
    }

    return days_past;
}

void main() {
    int year, month, day;
    int retry;

    do {
        printf("Year: "); scanf_s("%d", &year);
        printf("Month: "); scanf_s("%d", &month);
        printf("Day: "); scanf_s("%d", &day);
        
        printf("%d년의 %d일째입니다.\n", year, dayofyear(year, month, day));

        printf("Retry?(1-----Yes/0-----No: ");
        scanf_s("%d", &retry);

    } while (retry == 1);
}