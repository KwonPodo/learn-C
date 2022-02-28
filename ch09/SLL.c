#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

typedef struct Node node;

node* SLL_CreateNode (int data) {
    node * NewNode = (node*)malloc(sizeof(node));

    NewNode->next = NULL;
    NewNode->data = data;

    return NewNode;
}

void SLL_DestroyNode (node * Node) {
    free(Node);
}

void SLL_AppendNode(node** Head, node* newNode) {
    if ((*Head) == NULL) {
        *Head = newNode;
    } else {
        node *Tail = *Head;
        while (Tail->next != NULL) {
            Tail = Tail->next;
        }

        Tail->next = newNode;
    }
}

node * SLL_GetNodeAt(node *Head, int location) {
    node * search = Head;

    while (search->next != NULL && (--location) > 0) {
        search = search->next;
    }

    return search;
}

void printAll(node *searchFrom) {

    while (searchFrom != NULL) {
        printf("%d ", searchFrom->data);
        searchFrom = searchFrom->next;
    }
    puts("");
}

// if return value is NULL, No data
node* findByKey(node *Head, int key) {
    node *search = Head;
    while (search->data != key && search != NULL) {
        search = search->next;
    }

    return search;
}

node* findByIndex(node *Head, int idx) {
    node *search = Head;
    while (search != NULL && (idx--) > 0) {
        search = search->next;
    }

    return search;
}

int countNode(node *Head) {
    int cnt = 0;
    node *search = Head;

    while (search != NULL) {
        cnt++;
        search = search->next;
    }

    return cnt;
}

int main() {
    node *List = NULL;
    node *newNode = NULL;
    int i, count, index;

    for (i = 0; i < 5; i++) {
        newNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, newNode);
    }

    printAll(List);

    count = countNode(List);
    printf("%d\n", count);
}