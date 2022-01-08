#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VMAX 21 // 시력의 최댓값 2.1 x 10


// 신체검사 데이터형
struct physCheck {
    char name[20]; //이름
    int height;  // 키
    double vision;  // 시력
};

// 키의 평균값을 구한다.
double ave_height(const struct physCheck dat[], int n) {
    int i;
    double sum = 0;

    for (i = 0; i < n; i++) {
        sum += dat[i].height;
    }


    printf("sum: %lf\n", sum);
    printf("average: %lf\n", sum/n);

    return sum / n;
}

// 시력 분포를 구한다
void dist_vision(const struct physCheck dat[], int n, int dist[]) {
    int i = 0;
    for (i = 0; i < VMAX; i++) {
        dist[i] = 0;
    }
    
    for (i = 0; i < VMAX; i++) {
        if(dat[i].vision >= 0.0 && dat[i].vision <= VMAX/10.0) {
            dist[(int)(dat[i].vision * 10)]++;
        }
    }
}

void main() {
    int i;
    struct physCheck x[] = {
        {"박현규", 162, 0.3},
        {"함진아", 173, 0.7},
        {"최윤미", 175, 2.0},
        {"홍연의", 171, 1.5},
        {"이수진", 168, 0.4},
        {"김영준", 174, 1.2},
        {"박영규", 169, 0.8}
    };

    int nx = sizeof(x) / sizeof(x[0]); // 사람 수
    int vdist[VMAX]; // 시력 분포
    
    puts("--- Physical Check Table ---");
    puts(" Name    height    vision   ");
    puts("--------------------------------------");

    for(i=0; i < nx; i++) {
        printf("%s    %d    %f\n", x[i].name, x[i].height, x[i].vision);
    }

    printf("\n average height: %3.1f cm\n", ave_height(x, nx));
    dist_vision(x, nx, vdist);

    printf("\n Vision distribution\n");
    for(i = 0; i < VMAX; i++)
        printf("%3.1f ~ : %2d명\n", i/10.0, vdist[i]);
}