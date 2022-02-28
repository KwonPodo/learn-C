/**
 * 이진 나무 타기: 순회 (Tree Traverse)
 * : 전위 순회 (Preorder Traverse)
 */

#include <stdio.h>
#include <stdlib.h>

// 트리 설정
typedef struct _node {
    int data;
    node *left;
    node *right;
} node;

node *head, *tail;

void initTree() {
    head = (node*)malloc(sizeof(node));
    tail = (node*)malloc(sizeof(node));

    head->left = tail;
    head->right = tail;
    tail->left = tail;
    tail->right = tail;
}

void terminateTree() {
    free(head);
    free(tail);
}

// 스택 설정

typedef struct nodeStack {
    int max;
    int top;
    node **stk;
} stack;

int initStack(stack *s, int max) {
    s->stk = (node**)calloc(max, sizeof(node*));
    if (s->stk == NULL) {
        s->max = 0;
        return 0;
    }
    s->max = max;
    s->top = 0;

    return 1;
}

void terminateStack(stack *s) {
    if (s != NULL) {
        free(s);
    }
    s->max = 0;
    s->top = 0;
}

int isFull(stack *s) {
    return s->top >= s->max;
}

int isEmpty(stack *s) {
    return s->top <= 0;
}

int push(stack *s, node *Node) {
    if (isFull(s)) {
        return 0;
    }

    s->stk[s->top++] = Node;

    return 1;
}

int pop(stack *s, node *result) {
    if (isEmpty(s)) {
        return 0;
    }

    result = s->stk[s->top--];

    return 1;
}

void printStack(stack *s) {
    int cnt = s->top;

    if (cnt <= 0) {
        printf("No data in the Stack\n");
    } else {
        for (int i = 0; i < cnt; i++) {
            printf("%d ", s->stk[i]);
        }
    }
}

void visit(node *n) {
    printf("%d ", n->data);
}
// 전위 순회(재귀)
void preorder_traverse(node *t) {
    if (t != tail) {
        visit(t);   // 뿌리를 방문한다.
        preorder_traverse(t->left);     // 왼쪽 작은 나무를 방문한다.
        preorder_traverse(t->right);    // 오른쪽 작은 나무를 방문한다.
    }
}


// 전위 순회(비재귀, 스택으로 구현)
void preorder_traverse_nr(node *n) {
    initTree();

    stack stk;
    initStack(&stk, 256);

    push(&stk, n);
    while (!isEmpty(&stk)) {
        pop(&stk, &n);

        if (n != tail) {
            visit(n);
            push(&stk, n->left);
            push(&stk, n->right);
        }
    }
}