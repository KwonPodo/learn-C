#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} node;

node* createNode(int data) {
    node *new = (node*)malloc(sizeof(node));

    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    return new;
}

void destroyNode(node *toKill) {
    free(toKill);
}

// head == &List, *head == List, **head == *List
void appendNode(node **head, node *new) {
    if ((*head) == NULL) {
        (*head) = new;
        new->next = NULL;
        new->prev = NULL;
    } else {
        node *tail = *head;

        while (tail->next != NULL) {
            tail = tail->next;
        }
        new->prev = tail;
        tail->next = new;
    }
}

// head == &List, *head == List, **head == *List
void removeNode(node **head, node *toRemove) {
    if ((*head) == toRemove) {
        *head = toRemove->next;
        if ((*head) != NULL) {
            (*head)->prev = NULL;
        }
    } else {
        node *tmp = toRemove;

        if (toRemove->prev != NULL) {
            toRemove->prev->next = tmp->next;
        }
        if (toRemove->next != NULL) {
            toRemove->next->prev = tmp->prev;
        }

    }
        destroyNode(toRemove);
}

node* getNodeAt(node *head, int idx) {
    node *search = head;

    while ((idx--) > 0 && search != NULL) {
        search = search->next;
    }

    return search;
}

void appendAfterNode(node *idxNode, node *new) {
    if (idxNode->next == NULL) {
        idxNode->next = new;
        new->prev = idxNode;
    } else {
        new->next = idxNode->next;
        new->next->prev = new;
        new->prev = idxNode;
        idxNode->next = new;
    }
}

int countNode(node *head) {
    int cnt = 0;
    node *counter = head;
    while (counter != NULL) {
        cnt++;
        counter = counter->next;
    }

    return cnt;
}

void printList(node *printer) {
    while (printer != NULL) {
        printf("%d ", printer->data);
        printer = printer->next;
    }

    if (printer == NULL) {
        puts("No data");
    }

    puts("");
}

int main() {
    int i = 0;
    int count = 0;
    node *List = NULL;
    node *newNode = NULL;
    node *current = NULL;

    // add 5 nodes
    for (i = 0; i < 5; i++) {
        newNode = createNode(i);
        appendNode(&List, newNode);
    }

    // print List
    printList(List);

    // 리스트의 세번째 칸 뒤에 노드 삽입
    current = getNodeAt(List, 2);
    newNode = createNode(3000);
    appendAfterNode(current, newNode);

    // 리스트 출력
    printList(List);

    // 특정 노드를 제거
    current = getNodeAt(List, 3);
    removeNode(&List, current);

    puts("");
    printList(List);
    puts("");
    // 모든 노드를 메모리에서 제거
    count = countNode(List);
    printf("count: %d\n", count);

    for (i = 0; i < count; i++) {
        current = getNodeAt(List, 0);
        removeNode(&List, current);
    }

    printList(List);


    return 0;
}