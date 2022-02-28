#include <stdio.h>

int main() {
    union seoul {
        float a;
        int b;
        char c[4];
    };

    union seoul list;
    list.c[0] = 'd';
    list.c[1] = 0;
    list.c[2] = 0;
    list.c[3] = 1;

    // list.age = 38;
    // list.income = 562;

    printf("%d\n", list.b);
}