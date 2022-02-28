/**
 * 이진트리탐색 (Binary Tree Search)
 *  : 알고리즘을 그대로 표현할 수 있도록 연결 리스트로 구현한다.
 * 
 * 뿌리 노드를 가리키는 base 시작점을 사용하며 끝은 NULL로 표현한다.
 * 
 * 원칙 : 왼쪽 자식 < 부모 < 오른쪽 자식
 * 
 * 1. 키 값이 현재 노드와 같다면 검색 성공
 * 2. 키 값이 현재 노드보다 크다면 오른쪽 자식 노드로 이동.
 * 3. 키 값이 현재 노드보다 작다면 왼쪽 자식 노드로 이동.
 * 4. 현재 노드가 널이라면 검색 실패
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode (int data) {
    struct node* new = malloc(sizeof(struct node));
    if (new == NULL) {
        return NULL;
    }

    new->data = data;
    new->left = new->right = NULL;

    return new;
}

// 이진나무검색
struct node* binTreeSearch(struct node *base, int key) {
    struct node *s = base->left;
    while(s != NULL) {
        if (s->data < key) {
            s = s->right;
        } else if (s->data > key) {
            s = s->left;
        } else {
            return s;
        }
    }

    if (s == NULL) return NULL;
}

// 이진나무검색의 삽입
struct node* binTreeInsert(struct node *base, int key, int *num) {
    struct node *prev = base;
    struct node *s = prev->left;

    while (s != NULL) {
        prev = s;
        if (s->data > key) {
            s = s->left;
        } else if (s->data < key) {
            s = s->right;
        }
    }

    if (s == NULL) {
        s = createNode(key);
        if (prev == base) {
            prev->left = s;
            prev->right = s;
        } else if (prev->data > key) {
            prev->left = s;
        } else if (prev->data < key) {
            prev->right = s;
        }
    }

    (*num)++;

    return s;
}

/**
 * 이진검색나무의 노드 삭제
 * 유형
 * 1. 삭제할 노드가 외부노드인 경우(자식 없음)
 *      -> 삭제할 노드의 부모의 포인터를 NULL로 조정, 삭제할 노드 삭제
 * 2. 삭제할 노드가 내부노드인 경우
 *      2.1 삭제할 노드의 자식이 한개인 경우
 *              2.1.1 삭제할 노드의 자식중 왼쪽 자식만 존재
 *              2.1.2 삭제할 노드의 자식중 오른쪽 노드만 존재
 *                      => 삭제할 노드의 자식중 있는 자식을 삭제할 노드의 부모와 연결, 해당 노드 삭제
 *      2.2 삭제할 노드의 자식이 두개인경우
 *              2.2.1 삭제할 노드의 오른쪽 자식의 왼쪽 자식이 없는 경우
 *                      => 삭제할 노드의 오른쪽 자식이 오른쪽 서브트리에서 가장 작은 값이므로 삭제할 노드의 부모와 링크
 *              2.2.2 삭제할 노드의 오른쪽 자식의 왼쪽 자식이 있는 경우
 *                      => 삭제할 노드의 오른쪽 자식이 오른쪽 서브트리에서 가장 작은 값이 아니므로 NULL을 만날 때까지 
 *                          왼쪽 자식을 타고 내려가 삭제할 노드의 오른쪽 서브트리에서 가장 작은 값을 찾아 삭제할 노드와 자리를 바꿔준다.
 * 
 */

struct node* binTreeDelete(struct node *base, int key, int *num) {
    struct node *small_prev = NULL;
    struct node *smallest = NULL;
    struct node *prev = base;
    struct node *toDel = base->left;

    // 지우고자 하는 노드 탐색
    while (toDel != NULL) {
        if (toDel->data == key) {
            break;
        } else {
            prev = toDel;

            if (toDel->data < key) {
                toDel = toDel->right;
            } else if (toDel->data > key) {
                toDel = toDel->left;
            }
        }
    }

    if (toDel == NULL) {
        return NULL;
    }

    // left, right가 모두 널일때 즉, 자식이 없을떄 (1)
    if (toDel->left == NULL && toDel->right == NULL) {
        smallest = toDel->left;

    } else {
        // left, right가 모두 존재할때, 즉, 자식이 2개일 때
        if (toDel->left != NULL && toDel->right != NULL) {
            // 지우려는 노드의 오른쪽 자식이 오른쪽 서브트리 중 가장 작은 값일 때 (2)
            if (toDel->right->left == NULL) {
                smallest = toDel->right;
                smallest->left = toDel->left;

            // 지우려는 노드의 오른쪽 자식이 오른쪽 서브트리 중 가장 작은 값이 아닐 때,
            // 값을 찾아서 오른쪽 서브트리의 왼쪽 자식을 타고 널을 만날때까지 계속 가야한다. (3)
            } else {
                smallest = toDel->right;

                while (smallest->left->left != NULL) {
                    smallest = smallest->left;
                }
                small_prev = smallest;
                smallest = small_prev->left;

                // smallest의 자손들을 smallest의 부모에게 넘긴다.
                small_prev->left = smallest->right;

                // 지우고자 하는 노드의 자손들을 smallest에게 넘긴다.
                smallest->right = toDel->right;
                smallest->left = toDel->left;
            }
        } else {
            // 자식이 1개 일때

            // 단 하나의 자식이 왼쪽 자식일 때 (1)
            if (toDel->left != NULL) {
                smallest = toDel->left;

            // 단 하나의 자식이 오른쪽 자식일 때
            } else if (toDel->right != NULL) {
                if (toDel->right->left == NULL) { // (2)
                    smallest = toDel->right;
                    smallest->left = toDel->left;
                } else { // (3)
                    smallest = toDel->right;
                    while (smallest->left->left != NULL) {
                        smallest = smallest->left;
                    }

                    small_prev = smallest;
                    smallest = small_prev->left;

                    small_prev->left = smallest->right;
                    
                    smallest->right = toDel->right;
                    smallest->left = toDel->left;
                }
            }
        }
    }

    if (prev == base || key < prev->data) {
        prev->left = smallest;
    } else {
        prev->right = smallest;
    }

    free(toDel);
    (*num)--;

    return prev;
}

/**
 * 1. 자식이 없을 경우(외부노드) : 부모노드가 널을 가리키게끔 하고, free해준다.
 *                                  son = toDel->left
 *                                  parent->left = son
 * 2. 자식이 있을 경우
 *      자식이 1개
 *          왼쪽 자식만 있을 경우 : 오른쪽 서브트리에서 적합 노드를 찾을 수 없게 된다.->왼쪽 서브트리를 그대로 올린다.
 *                                      => son = toDel->left;
 *                                          parent->?? = son;
 * 
 *          오른쪽 자식만 있을 경우 : 오른쪽 서브트리에서 가장 작은 놈을 찾는다. (동일)
 *                                      => toDel->right->left == NULL일시, toDel->right가 적합 노드가 된다.
 *                                          son = toDel->right;
 *                                          parent->right = son;
 * 
 *                                          != NULL일시,  toDel->left == NULL이 될 때까지 찾는다.
 *                                          nexth->left = son->right;
 *                                          son->right = toDel->right;
 *                                          parent->right = son;
 *      
 *      자식이 2개
 *          오른쪽 서브트리에서 가장 작은 노드를 찾는다. (동일)
 *          오른쪽 서브트리의 오른쪽 자식만 있는 경우
 *                                      => toDel->right 가 바로 적합 노드가 된다.
 *          오른쪽 서브트리의 왼쪽 자식만 있거나, 둘다 있는 경우
 *                                      => toDel->right->left == 널이 될 때까지 찾는다.
 *          
 */
struct node* binTreeDelete2 (struct node *base, int key, int *num) {
    struct node *parent, *son, *toDel, *nexth;
    parent = base;
    toDel = parent->left;

    while (toDel->data != key && toDel != NULL) {
        if (toDel->data < key) {
            toDel = toDel->right;
        } else if (toDel->data > key) {
            toDel = toDel->left;
        }
    }

    if (toDel == NULL) return NULL;

    if (toDel->right == NULL) {
        son = toDel->left;
    } else if (toDel->right->left == NULL) {
        son = toDel->right;
        son->left = toDel->left;
    } else {
        nexth = toDel->right;
        while (nexth->left->left != NULL) {
            nexth = nexth->left;
        }

        son = nexth->left;
        nexth->left = son->right;

        son->right = toDel->right;
        son->left = toDel->left;
    }

    if (parent == base || parent->data > key) {
        parent->left = son;
    } else {
        parent->right = son;
    }

    free(toDel);
    (*num)--;

    return parent;
}