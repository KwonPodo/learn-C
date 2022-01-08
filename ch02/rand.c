#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// 난수를 사용해서 배열의 요솟값 설정하기
// 1. rand, srand, time 함수의 선언이 들어 있는 헤더를 포함한다.
// 2. 난수의 seed를 srand함수 호출로 초기화한다.
// 3. 난수를 생성하기 위해 rand함수를 호출한다. (보통 srand는 한번만 호출한다.)

// rand 함수의 반환값은 0 ~ RAND_MAX 사이의 값. <stdlib.h>에 정의된 RAND_MAX값은 컴퓨터 환경에 따라 다르다.
// rand 함수는 seed를 사용하여 난수를 생성하기 떄문에 rand함수가 생성하는 난수는 srand로 seed를 초기화하지 않는 이상,생성되는 난수의 순서가 정해져있다.
// 이를 '의사 난수'라고 한다. => 난수처럼 보이지만 일정한 규칙에 따라 생성되는 수.


// 하지만 특정 seed값을 전달하여 srand를 호출해도, 그 이후에 rand함수가 생성하는 난수의 순서는 그 특정 seed를 기준으로 정해지기에,
// srand 함수에 전달하는 매개변수 또한 임의의(random한) 난수여야 한다.
// 난수를 생성하기위해 난수를 전달해야하는 딜레마가 생긴다. 

// 이를 해결하기 위한 방법 중 하나가 srand의 인자로 현재 시간의 값을 전달하는 것이다.


int maxof(const int *p, int n) {
    int i;
    int max = p[0];
    for (i = 0; i < n; i++){
        if(max < p[i])
            max = p[i];
    }
    printf("sizeof p: %d\n", sizeof(p));
    printf("sizeof p[0]: %d\n", sizeof(p[0]));
    
    return max;
}

void main() {
    int i;
    int *height;
    int number;

    printf("Number of People: ");
    scanf_s("%d", &number);

    height = calloc(number, sizeof(int));
    // 시간으로 난수 seed 초기화
    srand(time(NULL));

    for(i = 0; i < number; i++) {
        // 100 ~ 189의 난수를 생성, 대입.
        height[i] = 100 + rand() % 90;
        printf("height[%d] = %d\n", i, height[i]);
    }

    printf("Max height of given people's height is %d.\n", maxof(height, number));

    int x, y;
    x = rand();
    y = rand();
    printf("x: %d, y: %d\n", x, y);

}