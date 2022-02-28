/**
 * 이진 트리 구조의 표현 : 연결 리스트
 */

struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

typedef struct treeNode node;

node *head, *tail;

void initTree() {
    head = (node*)malloc(sizeof(node));
    tail = (node*)malloc(sizeof(node));

    head->left = tail;
    head->right = tail;
    tail->left = tail;
    tail->right = tail;
}

void preorder_traverse(node *t) {
    if (t != tail) {
        visit(t);
        preorder_traverse(t->left);
        preorder_traverse(t->right);
    }
}