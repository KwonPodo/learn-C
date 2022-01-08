#include <stdio.h>
#include <stdlib.h>

int sum(int x, int y) {
    return x + y;
}

int mul(int x, int y) {
    return x * y;
}

void kuku(int(*calc)(int, int )) { // int(*calc)(int, int) == int calc(int, int)
    int i, j;
    for(i = 1; i <= 9; i++) {
        for(j = 1; j <= 9; j++) {
            printf("%3d", (*calc)(i, j));
        }
        puts("");
    }
}

int main() {
    puts("덧셈표");
    kuku(sum);

    puts("");

    puts("곱셈표");
    kuku(mul);

    return 0;
}