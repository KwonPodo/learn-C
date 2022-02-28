/*
 * Circular Linked List(with DLL)
    단순 연결 리스트와 같은 노드 구조를 가지고 있지만, 연결리스트의 제일 마지막 노드가 가장 처음의 노드를 가리키고 있다는 것이다.
    우로보로스!

    테일이라는 개념을 없애고 헤드만 있으며, 연결리스트이 마지막 노드는 헤드가 가리키는 노드, 즉 맨 처음의 노드만을 가리킨다는 차이점이 있다.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node* prev;
} node;

node* createNode(int n) {
    node *new = (node*)malloc(sizeof(node));
    new->data = n;
    new->next = NULL;
    new->prev = NULL;

    return new;
}

void destroyNode(node *toFree) {
    free(toFree);
}

// head == &List, *head == List, **head == *List
void appendNode(node **head, node *newNode) {
    if ((*head) == NULL) {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        node *search = *head;
        while (search->next != *head) {
            search = search->next;
        }
        newNode->prev = search;
        newNode->next = *head;
        search->next = newNode;
        (*head)->prev = newNode;
    }
}

void removeNode(node **head, node *toRemove) {
    node *tmp = *head;

    toRemove->next->prev = toRemove->prev;
    toRemove->prev->next = toRemove->next;

    // 만약 지우고자 하는 것이 머리일 경우
    if ((*head) == toRemove) {
        *head = (*head)->next;
    }
    
    destroyNode(toRemove);
}

node* getNodeAt(node *head, int idx) {
    node *search = head;

    while (1) {
        if (idx-- <= 0) break;
        search = search->next;
        if (search->next == head) break;
    }

    return search;
}


int printAll(node *head) {
    node *print = head;

    if (print == NULL) {
        puts("No data");
        return 0;
    }

    while (1) {
        printf("%d ", print->data);
        print = print->next;
        if (print == head) break;
    }

    puts("");

    return 1;
}

int main() {
    node *List = NULL;
    node *newNode = NULL;
    node *current = NULL;
    int i, cnt = 0;

    for (i = 0; i < 5; i++) {
        newNode = createNode(i);
        appendNode(&List, newNode);
    }

    printAll(List);

    current = getNodeAt(List, 2);

    printf("%d\n", current->data);

    for (i = 0; i < 4; i++) {
        current = getNodeAt(List, 0);

        removeNode(&List, current);
    }

    printAll(List);

    return 0;
}