/**
 * 후위 순회 (Postorder Traverse)
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

void postorder_traverse(node *n) {
    if (n != tail) {
        postorder_traverse(n->left);  // 왼쪽 작은 나무를 방문한다.
        postorder_traverse(n->right);     // 오른쪽 작은 나무를 방문한다.
        visit(n);   // 뿌리를 방문한다.
    }
}

void postorder_traverse_nr(node *n) {

    while (1) {
        // 뿌리부터 시작하여 계속하여 왼쪽 노드로 진행하여 끝까지 이동한다.
        while (n != tail) {
                push(n);
                n = n->left;
            }

        while (!isEmpty()) {
            node* tmp = n;
            pop(&n);
            
            if (n->right != NULL) {
                if (n->right == tmp) {
                    visit(n);
                } else {
                    push(n);
                    n = n->right;
                    break;
                }
                // push(n);
                // n = n->right;
                // break;
            } else {
                visit(n);
            }
        }

        if (isEmpty()) {
            break;
        }
    
}