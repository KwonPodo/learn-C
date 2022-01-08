/*
    요소의 이동 횟수를 계산할 수 있도록 버전1과 버전 2를 수정한 프로그램을 작성하세요.
*/
#include <stdlib.h>
#include <stdio.h>

int insertion(int a[], int n) {
    int i, j, temp;
    int cnt = 0;

    // 인덱스 0은 이미 정렬된 것으로 보고 시작한다.
    for (i = 1; i < n; i++) {
        temp = a[i]; // 삽입될 숫자인 i번째 정수를 temp 변수로 복사

        // 현재 i - 1까지만 정렬되었다고 보고, i - 1 부터 역순으로 조사, 비교한다.
        // j 값은 음수가 아니어야하며
        // temp 값보다 정렬된 배열에 있는 값이 크면 j번째 요소를 j + 1번째로 이동시킨다.
        for (j = i - 1; j >=0 && a[j] > temp; j--) {
            a[j + 1] = a[j];
            cnt++;
        }
        a[j + 1] = temp;
    }
    return cnt;
}

int shell(int a[], int n) {
    int h, i, j;
    int cnt = 0;
    
    for (h = n / 2; h > 0; h /= 2) {
        for (i = h; i < n; i++) {
            // 현재 삽입될 요소인 i번째 정수를 tmp변수로 복사
            int tmp = a[i];

            // 현재 정렬된 배열은 i - h까지이므로 i - h번째부터 역순으로 조사한다.
            // j 값은 i이상이어야 하고
            // tmp 값보다 정렬된 배열에 있는 값이 크면 j번째 요소를 j+h번째로 복사
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
                a[j + h] = a[j]; // 요소 복사, 이동
                cnt++;
            }
            a[j + h] = tmp;
        }
    }

    return cnt;
}

int shell2(int a[], int n) {
    int i, j, h;
    int cnt = 0;

    // h의 초기값을 구한다.
    // 1부터 시작하여 값을 3배하고 1을 더하면서 n / 9를 넘지 않는 가장 큰 값을 h에 대입한다.
    for (h = 1; h < n / 9; h = h * 3 + 1);

    for (; h > 0; h /=3) {
        for(i = h; i < n; i++) {
            int tmp = a[i];
            for (j = i - h; j >= 0 && a[j] > tmp; j--) {
                a[j + h] = a[j];
                cnt++;
            } 
            a[j + h] = tmp;
        }
    }

    return cnt;
}

void main() {
    int i, nx;
    int *x;

    printf("Number of elements: ");
    scanf_s("%d", &nx);

    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++){
        printf("x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    // int cnt = insertion(x, nx);
    // int cnt = shell(x, nx);
    int cnt = shell2(x, nx);

    puts("Ascending Sort");
    for(i = 0; i < nx; i++){
        printf("%d ", x[i]);
    }
    puts("");

    printf("cnt: %d\n", cnt);

    free(x);
}