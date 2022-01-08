// 기수 변환 과정을 상세히 출력하는 프로그램을 작성하시오.

#include <stdio.h>
#include <stdlib.h>

int card_conv(unsigned num, int base, char d[]);
int print_process(int num, int base, int quot, int remainder);

void main(void) {
    char conv_arr[10] = {0};
    int i, retry, base;
    unsigned num;

    do {
        printf("Enter a positive number to convert: ");
        scanf_s("%d", &num);

        do {
            printf("Enter a base number (2 <= base <= 36): ");
            scanf_s("%d", &base);
        } while (base < 2 || base > 36);

        int len = card_conv(num, base, conv_arr);

        for (i = 0; i < len; i++) {
            printf("%c ", conv_arr[i]);
        }

        puts("Retry?");
        printf("Enter 1 if Yes, 0 if No\n");
        scanf_s("%d", &retry);

    } while (retry == 1);
}

int card_conv(unsigned num, int base, char d[]) {
    char str[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int quot, remainder;
    int digit;

    if (num == 0) {
        d[digit++] = str[digit];
    } else {
        while(num) {
            remainder = num % base;
            quot = num / base;

            print_process(num, base, quot, remainder);

            d[digit++] = str[remainder];
            num = quot;
        }
    }
    return digit;
}

int print_process(int num, int base, int quot, int remainder) {
    printf("%d|        %d ---- %d\n", base, num, remainder);
    if (quot) {
        printf(" +---------\n"); 

    } else {
        printf(" +---------\n");
        printf("          %d\n", quot);
    }
}