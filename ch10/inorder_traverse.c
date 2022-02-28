/**
 * 중위 순회 (Inorder Traverse)
 */
#include <stdio.h>
#include <stdlib.h>

struct _node {
    int data;
    struct _node *left;
    struct _node *right;
};

typedef struct _node node;

node *head, *tail;

void visit(node *n) {
    printf("%d ", n->data);
}

void inorder_traverse(node *n) {
    if (n != tail) {
        inorder_traverse(n->left);  // 왼쪽 작은 나무를 방문한다.
        visit(n);   // 뿌리를 방문한다.
        inorder_traverse(n->right);     // 오른쪽 작은 나무를 방문한다.
    }
}

void inorder_traverse_nr(node *n) {

    while (1) {
        while (n != tail) {
                push(n);
                n = n->left;
            }

        if (!isEmpty()) {
            pop(&n);
            visit(n);
            n = n->right;
        } else {
            break;
        }
    }
    
}