#include <stdio.h>
#include <stdlib.h>

typedef unsigned int bitSet;

#define bitSetNULL 0
#define bitSetBits 32

// 집합 두개가 같은지 확인
int isEqual(bitSet, bitSet);

// 집합 s에 n이 있는지 확인
int isThere(bitSet, int);

// 집합 s에 n을 추가
void add(bitSet*, int);

// 집합 s에서 n을 삭제
void delete(bitSet*, int);

// 교집합을 반환
bitSet intersection(bitSet s1, bitSet s2);

// 합집합을 반환
bitSet uni(bitSet s1, bitSet s2);

// 차집합을 반환
bitSet diff(bitSet s1, bitSet s2);

// 대칭차 반환
bitSet symmDiff(bitSet s1, bitSet s2);

// 집합 s의 원소 개수를 반환
int count(bitSet);

// 집합 s의 모든 원소를 출력
void printAll(bitSet);

// 집합 s의 모든 원소를 출력 줄바꿈 추가
void println(bitSet);

int main() {
    bitSet s = bitSetNULL;
    
    add(&s, 1);
    add(&s, 5);
    add(&s, 8);
    println(s);

    if (isThere(s, 5)) {
        printf("5 is there\n");
    } else {
        printf("5 is not there\n");
    }

    delete(&s, 5);
    println(s);

    printf("Count number of elements in bitSet: %d\n", count(s));
}

int isEqual(bitSet s1, bitSet s2) {
    return s1 == s2;
}

int isThere(bitSet s, int n) {
    return s & (1 << n);
}

void add(bitSet *s, int n) {
    *s = *s | (1 << n);
}

void delete(bitSet *s, int n) {
    *s = *s & ~(1 << n);
}

bitSet intersection(bitSet s1, bitSet s2) {
    return s1 & s2;
}

bitSet uni(bitSet s1, bitSet s2) {
    return s1 | s2;
}

bitSet symmDiff(bitSet s1, bitSet s2) {
    return (s1 | s2) & ~(s1 & s2);
}

bitSet diff(bitSet s1, bitSet s2) {
    return s1 & ~s2;
    // s1 & ~(s1 & s2);
}

int count(bitSet s) {
    int i, cnt = 0;
    for (i = 1; i < bitSetBits; i++) {
        if (s & (1 << i)) cnt++;
    }

    return cnt;
}

void printAll(bitSet s) {
    int i;

    for (i = 0; i < bitSetBits; i++) {
        if (s & (1 << i)) {
            printf("%d ", i);
        }
    }
}

void println(bitSet s) {
    printAll(s);
    puts("");
}