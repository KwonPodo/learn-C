// bsearch 함수를 사용한 구조체 배열에서의 검색

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
    int height;
    int weight;
} Person;

// Person형의 비교함수(오름차순으로 이름 정렬)
int npcmp(const Person *x, const Person *y) {
    return strcmp(x->name, y->name);
}

int main() {
    Person x[] = {
    {"김영준", 179, 79},
    {"박현규", 172, 61},
    {"이수진", 176, 52},
    {"최윤미", 165, 51},
    {"함진아", 181, 73},
    {"홍연의", 172, 84},
    };

    int nx = sizeof(x) / sizeof(x[0]);
    int retry;

    puts("이름으로 검색합니다.");
    do {
        Person temp, *p;
        printf("Name: ");
        scanf_s("%s", temp.name);
        p = bsearch(&temp, x, nx, sizeof(x[0]), (int(*)(const void *, const void *))npcmp);

        if (p == NULL) {
            puts("Search Failed");
        } else {
            puts("Search Success!");
            printf("x[%d] : %s %dcm %dkg\n", (int)(p - x), p->name, p->height, p->weight);
        }

        printf("Retry?: ");
        scanf_s("%d", &retry);

    } while (retry == 1);

    return 0;
}