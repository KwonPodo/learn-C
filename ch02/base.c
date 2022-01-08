#include <stdio.h>
#include <stdlib.h>

int change_to_base(int num, const int base) {
    char char_arr[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVXYZ";
    int conv[10] = {0};
    int quot, remainder;
    int i, j;
    quot = 1;
    i = 0;

    while(quot) {
        quot = num / base;
        remainder = num % base;
        conv[i] = char_arr[remainder];
        num = quot;
        i++;
    }

    // 거꾸로 저장했기 때문에 거꾸로 읽어준다.
    for (j = i - 1; j >= 0; j--) {
        printf("%c ", conv[j]);
    }

    return 0;
}

int car_convr(unsigned num, const int base, char d[]) {
    char char_arr[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVXYZ";
    int digit = 0;

    if (!num) {
        d[digit++] = 0;
    } else {
        while(num) {
        d[digit++] = char_arr[num % base];
        num /= base;
        }
    return digit;
    }
    return 0;
}

void main() {
    unsigned number, base;
    int retry = 1;
    char changed_num[100] = {0};

    do {
        printf("Enter a number: ");
        scanf_s("%d", &number);

        do {
        printf("Enter the base you want number to change into: ");
        scanf_s("%d", &base);
        } while(base < 2 || base > 36);

        //change_to_base(number, base);
        int digit = car_convr(number, base, changed_num);
        printf("digit: %d\n", digit);

        for (int i = digit - 1; i >= 0; i--) {
            printf("%c ", changed_num[i]);
        }

        printf("Retry? Enter 1 if Yes, 0 if not: ");
        scanf_s("%d", &retry);
    }while(retry == 1);
}