#include <stdio.h>
#include <stdlib.h>

int array[32]; // 정렬된 배열
int index;
struct node {
    int data;
    struct node *left;
    struct node *right;
};

void binTreeSort (struct node *base) {
    if (base != NULL) {
        binTreeSort(base->left);
        array[index++] = base->data;
        binTreeSort(base->right);
    }
}

/**
 * 이미 정렬된 배열에서 중위 순회를 이용하여 균형잡힌 나무를 구성할 수 있다.
 */
struct node* balance (int n) {
    int nl, nr;
    struct node * new;
    if (n > 0) {
        nl = (n - 1) / 2;
        nr = n - nl - 1;

        new = malloc(sizeof(struct node));

        new->left = balance(nl);

        new->data = array[index++]; // index = 0

        new->right = balance(nr);

        return new;
        
    } else {
        return NULL;
    }
}

/**
 *  binTreeSort 함수와 balance 함수를 이용하여
 *  이미 구성되어 있는 검색나무를 균형을 잡아 본다.
 * 
 * 방식은 구성된 균형잡히지 않은 검색나무를 binTreeSort함수로 배열로 변환한다음
 *  -> 배열로 변환되어 정렬된 검색나무를 다시 balance함수로 변환하여 재구성하는 방식이다.
 */
void binTreeBalance (struct node *base, int *num) {
    int num_t = *num;
    index = 0;
    struct node *tmp = base;
    binTreeSort(tmp);
    // delete all nodes

    index = 0;
    base->left = balance(num_t);
    *num = num_t;
}