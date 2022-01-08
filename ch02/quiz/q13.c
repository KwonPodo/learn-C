#include <stdio.h>

typedef struct {
    int y;
    int m;
    int d;
} Date;

int mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// 윤년 판단
int isleap(Date x) {
    return x.y % 400 == 0 || x.y % 100 != 0 && x.y % 4 == 0;
}

// 1. y년 m월 d일을 나타내는 구조체를 반환하는 함수

Date DateOf(int y, int m, int d) {
    Date given_date = {
        y, m, d
    };

    return given_date;
}

// 2. Date after n days

Date After(Date x, int n) {
    if (n + x.d > mdays[isleap(x)][x.m]) {
        x.m += 1;
        x.d = n + x.d - mdays[isleap(x)][x.m];
    } else {
        x.d += n;
    }

    return x;
}

// 3. Date before n days

Date Before(Date x, int n) {
    if (x.d >= n) {
        x.d -= n;
    } else {
        x.m -= 1;
        x.d = mdays[isleap(x)][x.m] + x.d - n;
    }

    return x;
}

void main() {
    int year, month, day;
    
    do {
        printf("Enter today's year: ");
        scanf_s("%d", &year);
    } while (year < 0);

    do {
        printf("Enter today's month: ");
        scanf_s("%d", &month);
    } while (month < 1 || month > 12);

    do {
        printf("Enter today's day: ");
        scanf_s("%d", &day);
    } while (day < 1 || day > 31);

    Date today = DateOf(year, month, day);

    printf("today.year: %d, today.month: %d, today.day: %d\n", today.y, today.m, today.d);
}