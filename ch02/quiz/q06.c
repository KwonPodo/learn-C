#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0);

int card_conv(unsigned x, int n, char d[]);

void main (void) {
    char conv_to_base_reversed[512];
    int i, base;
    unsigned num;

    printf("Enter a positive number to convert: ");
    scanf_s("%d", &num);

    do {
        printf("Enter a base number(2 <= base <= 36): ");
        scanf_s("%d", &base);
    } while (base < 2 || base > 36);

    int length = card_conv(num, base, conv_to_base_reversed);
    printf("length: %d\n", length);

    puts("conv_to_base_reversed");
    for (i = 0; i < length; i++) {
        printf("%c ", conv_to_base_reversed[i]);
    }

    puts("");
    puts("conv_to_base_right");

    for (i = 0; i < length / 2; i++) {
        swap(int, conv_to_base_reversed[i], conv_to_base_reversed[length - 1 - i]);
    }

    for (i = 0; i < length; i++) {
        printf("%c ", conv_to_base_reversed[i]);
    }
}

int card_conv(unsigned x, int n, char d[]) {
    char str[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digit = 0;

    if (x == 0) {
        d[digit++] = str[digit];
    } else {
        while (x) {
        d[digit++] = str[x % n];
        x /= n;
        }
    }
    return digit;
}