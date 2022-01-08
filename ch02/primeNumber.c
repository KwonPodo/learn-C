// 소수의 조건: 2부터 n - 1까지의 어떤 정수로도 나누어 떨어지지 않으면 소수이다.

// 하지만 이 조건은 불필요한 계산을 하게된다. 예를 들어 2 또는 3으로 나누어지지 않을 경우 4나 6으로도 나누어지지 않을 것이기에 4나 6으로 나눌 필요가 없다.
// 따라서 조건에 변화를 줄 수 있다.
// : 2부터 n - 1까지 어떤 소수로도 나누어 떨어지지 않는다면 소수라고 할 수 있다.

// 여기서 추가로 더 단순하게 만들 수도 있다.
// 어떠한 n에 대하여 n을 이루는 소인수분해를 할 경우, 이 모든 소인수분해는 루트 n x 루트 n을 기준으로 대칭되게 나열된다
// 예시를 들자면, 1 x n, 2 x n/2, 3 x n/3 ... root n x root n, ... n/3 x 3, n/2 x 2, n x 1 이런식이다.
// 따라서 조건에 변화를 줄 수 있다.
// : n의 제곱근 이하의 어떤 소수로도 나누어떨어지지 않는다면, 소수라고 할 수 있다.

// 1000까지의 소수를 나열하라.
#include <stdio.h>
#include <math.h>

void cnt_all() {
    int i, num;
    unsigned counter = 0;

    for (num = 2; num <= 1000; num++) {
        for (i = 2; i < num; i++) {
            counter++;
            if (num % i == 0) {
                break;
            }
        }
        if (i == num) {
            //printf("%d\n", num);
        }
    }
    printf("cnt_all counter: %d\n", counter);
}

void odd_cnt_all() {
    int prime[1000] = {0};
    int num, i, j;
    int ptr = 0;
    unsigned counter = 0;

    prime[ptr++] = 2;
    for(num = 3; num <= 1000; num+=2) {
        for(j = 0; j < ptr; j++) {
            counter++;
            if (num % prime[j] == 0) {
                break;
        }
        if (j == ptr) prime[ptr++] = num;
        }
    }
    //puts("Printing prime numbers in prime arr");
        for(i = 0; i < ptr; i++) {
            //printf("%d\n", prime[i]);
        }
    printf("odd_cnt_all counter: %d\n", counter);
}

void root_cnt_all() {
    int prime[1000] = {0};
    int num, i, j;
    int ptr = 0;
    unsigned counter = 0;
    int flag;

    prime[ptr++] = 2;
    prime[ptr++] = 3;
    for(num = 5; num <= 1000; num+=2) {
        flag = 1;

        for(j = 0; counter++, prime[j] * prime[j] < ptr; j++) {
            counter++;
            if (num % prime[j] == 0) { // Not a prime number
                flag = 0;
                break;
        }
        if (flag) {
            prime[ptr++] = num;
        }
        }
    }
    //puts("Printing prime numbers in prime arr");
        for(i = 0; i < ptr; i++) {
            //printf("%d\n", prime[i]);
        }
    printf("root_cnt_all counter: %d\n", counter);
}

void main() {
    cnt_all();
    odd_cnt_all();
    root_cnt_all();
}
