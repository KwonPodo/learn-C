#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

// typedef struct {
//     int max; // 집합 최대 개수
//     int num;  // 집합 원소 개수
//     int *set; // 집합
// } intSet;

int Init(intSet *s, int max) {
    if ((s->set = (int*)calloc(max, sizeof(int))) == NULL) {
        s->max = 0;
        return 0;
    }

    s->max = max;
    s->num = 0;

    return 1;
}

int isFull(const intSet *s) {
    return s->num >= s->max;
}

int isEmpty(const intSet *s) {
    return s->num <= 0;
}


int isMember(const intSet *s, int n) {
    int i;
    for (i = 0; i < s->num; i++) {
        if (s->set[i] == n) {
            return 1;
        }
    }

    return 0;
}

void Add(intSet *s, int n) {
    // Find Redundant member 
    int i;
    int flag = 1;

    if (!isMember(s, n) && s->num < s->max) {
        s->set[s->num++] = n;
    }
}

void Remove(intSet *s, int n) {
    // Search for matching element
    int i;

    for (i = 0; i < s->num; i++) {
        if (s->set[i] == n) {
            break;
        }
    }

    if (i == s->num + 1) {
        printf("No matching element\n");
    } else {
        // 마지막 요소와 찾아낸 제거할 요소의 자리를 바꾸고 s->num--을 행한다.
        s->set[i] = s->set[(s->num--) - 1];
    }
}

void Clear(intSet *s) {
    s->num = 0;
}

int Capacity(const intSet *s) {
    return s->max;
}

int CurrentSize(const intSet *s) {
    return s->num;
}

//  s2의 원소개수가 s1의 최대 크기보다 클 경우, s1->max만큼만 복사한다.
void Assign(intSet *s1, const intSet *s2) {
    int len = (Capacity(s1) < Capacity(s2)) ? s1->max : s2->max;

    int i;

    for (i = 0; i < len; i++) {
        s1->set[i] = s2->set[i];
    }

    s1->num = s2->num;
}

int isEqual(const  intSet *s1, const intSet *s2) {
    int i, j;

    if (CurrentSize(s1) != CurrentSize(s2)) return 0;
    else {
        for (i = 0; i < s1->num; i++) {
            for (j = 0; j < s2->num; j++) {
                if (s1->set[i] == s2->set[j]) {
                    break;
                }
            }

            if (j >= s2->num) {
                return 0;
            }
        }

        return 1;
    }
}

intSet* Union(intSet *s1, const intSet *s2, const intSet *s3) {
    int i;

    Assign(s1, s2);
    for (i = 0; i < s3->num; i++) {
        if (!isMember(s2, s3->set[i])) {
            s1->set[s1->num] = s3->set[i];
            s1->num++;
        }
    }

    return s1;
}

intSet* Intersection(intSet *s1, const intSet *s2, const intSet *s3) {
    if (isEqual(s2, s3)) {
        Assign(s1, s2);
        return s1;
    } else {
        int i;
        s1->num = 0;

        for (i = 0; i < s3->num; i++) {
            if (isMember(s2, s3->set[i])) {
                Add(s1, s3->set[i]);
            }
        }

        return s1;
    }
}


intSet* Difference(intSet *s1, const intSet *s2, const intSet *s3) {
    Assign(s1, s2);

    for (int i = 0; i < s3->num; i++) {
        if (isMember(s1, s3->set[i])) {
            Remove(s1, s3->set[i]);
        }
    }

    return s1;
}

intSet* SymmetricDiff(intSet *s1, const intSet *s2, const intSet *s3) {
    intSet un, inter;
    Init(&un, 32); Init(&inter, 32);

    Union(&un, s2, s3);
    Intersection(&inter, s2, s3);
    Difference(s1, &un, &inter);
    
    Terminate(&un);
    Terminate(&inter);

    return s1;
}

intSet* ToUnion(intSet *s1, const intSet *s2) {
    int i;
    for (i = 0; i < s2->num; i++) {
        if (!isMember(s1, s2->set[i])) {
            Add(s1, s2->set[i]);
        }
    }

    return s1;
}

intSet* ToIntersect(intSet *s1, const intSet *s2) {
    int i;
    for (i = 0; i < s1->num; i++) {
        if (!isMember(s2, s1->set[i])) {
            Remove(s1, s1->set[i]);
        }
    }

    return s1;
}

intSet* ToDiff(intSet *s1, const intSet *s2) {
    int i;
    for (i = 0; i < s1->num; i++) {
        if (isMember(s2, s1->set[i])) {
            Remove(s1, s1->set[i]);
        }
    }

    return s1;
}

int IsSubset(const intSet *s1, const intSet *s2) {
    int i;

    for (i = 0; i < s1->num; i++) {
        if (!isMember(s2, s1->set[i])) {
            return 0;
        }
    }

    return 1;
}

int IsProperSubset(const intSet *s1, const intSet *s2) {
    if(!isEqual(s1, s2) && IsSubset(s1, s2)) {
        return 1;
    } else {
        return 0;
    }
}

void Print(const intSet *s) {
    int i;

    printf("{ ");
    for (i = 0; i < s->num; i++) {
        printf("%d ", s->set[i]);
    }
    printf(" }\n");
}

void PrintLn(const intSet *s) {
    Print(s);
    puts("");
}

void Terminate(intSet *s) {
    if (s->set != NULL) {
        free(s->set);
    }
    s->num = s->max = 0;
}

int main() {
    intSet s1, s2, s3;
    Init(&s1, 24);
    Init(&s2, 24);
    Init(&s3, 24);

    // s1 = { 1, 2, 3, 6, 7 }
    Add(&s1, 1);
    Add(&s1, 2);
    Add(&s1, 3);
    Add(&s1, 6);
    Add(&s1, 7);

    // s2 = { 2, 3, 5, 8 ,9 }
    Add(&s2, 2);
    Add(&s2, 3);
    Add(&s2, 5);
    Add(&s2, 8);
    Add(&s2, 9);

    printf("s1 : "); PrintLn(&s1);
    printf("s2 : "); PrintLn(&s2);

    Assign(&s3, &s1);
    ToDiff(&s3, &s2);
    printf("s3 : "); PrintLn(&s3);

    if (IsSubset(&s3, &s1)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    puts("");

    if (IsProperSubset(&s3, &s1)) {
        puts("True");
    } else {
        puts("False");
    }

    // SymmetricDiff(&s3, &s1, &s2);
    // printf("s3 : Symmetric Diff s1, s2 : "); PrintLn(&s3);

    // ToUnion(&s1, &s2);
    // printf("Made s1 to Union of s1 and s2 : "); PrintLn(&s1);

    // ToIntersect(&s1, &s2);
    // printf("Made s1 to Intersection of s2 : "); PrintLn(&s1);

    Terminate(&s1);
    Terminate(&s2);
    Terminate(&s3);
}