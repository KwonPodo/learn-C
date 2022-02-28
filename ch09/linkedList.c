/**
 * 연결리스트 (Linked List)
 * 
 * 정적인 구조를 지닌 배열과는 달리 동적인 구조를 지닌다.
 * 필요한만큼 메모리를 동적할당하여 유지하고 해제할 수 있어 메모리활용에 있어 경제적이다.
 * 또한 요소를 삽입하기 위해 해당 위치 뒤쪽의 요소들을 모두 이동시켜야하는 배열과는 다르게
 * 원하는 위치에 링크를 변경하여 바로 요소를 삽입하고 뺄 수 있다는 장점이 있다.
 *  => 재배열이 배열보다 쉽다.
 * 
 * 다만 속도는 처음 주소와 인덱스만 있다면 바로 요소에 접근할 수 있는 배열과는 다르게
 * 연결리스트는 포인터를 타고 타고 타고 가서 요소에 접근해야 하기에 배열이 더 빠르며, 
 * 곧바로 원하는 요소에 접근할 수 없다는 단점이 있다.
 *  => 탐색이 배열보다 어렵다.
 * 
 * 단순 연결리스트의 핵심은 바로 어떠한 노드를 찾을 땐, 해당 노드 바로 앞의 노드.next값을 아는 것이 중요하다는 것이다.
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * Head = NULL;
struct node * Tail = NULL;

int InitNode() {
    Head = (struct node*)malloc(sizeof(struct node));
    Tail = (struct node*)malloc(sizeof(struct node));
    if (Head == NULL || Tail == NULL) {
        free(Head), free(Tail);
        return 0;
    }

    Head->next = Tail;
    Tail->next = Tail;

    return 1;
}

void Terminate() {
    if (Head->next != NULL) free(Head);
    if (Head->next != NULL) free(Tail);
}

int insert_node(int n) {
    struct node * new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) return 0;

    struct node * prev = Head;

    new->data = n;

    new->next = prev->next;
    prev->next = new;   

    return 1;
}

int insert_node_afterPtr(struct node *prev, int n) {
    struct node * new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) return 0;

    new->data = n;

    new->next = prev->next;
    prev->next = new;   

    return 1;
}

// if return value == Tail, then the search failed.
struct node * find_node(int key) {
    struct node *explorer = Head->next;

    while (explorer != Tail) {
        if (explorer->data == key) break;

        explorer = explorer->next;
    }

    return explorer;
}

int insert_node_afterKey(int n, int key) {
    struct node *kptr = find_node(key);

    if (kptr == Tail) {
        return 0;
    } else {
        insert_node_afterPtr(kptr, n);
        return 1;
    }
}

int insert_node_beforeKey(int n, int key) {
    struct node *prev = Head;
    struct node *explorer = prev->next;

    while (explorer->data != key && explorer != Tail) {
        prev = prev->next;
        explorer = prev->next;
    }

    if (explorer == Tail) {
        return 0;
    } else {
        struct node *new = (struct node*)malloc(sizeof(struct node));
        new->data = n;

        new->next = explorer;
        prev->next = new;

        return 1;
    }
}

int delete_nextNode(struct node *prev) {
    if (prev->next == Tail) {
        return 0;
    }

    struct node *toDelete = prev->next;

    prev->next = toDelete->next;

    free(toDelete);

    return 1;
}

int delete_node_byKey(int key) {
    struct node *prev = Head;
    struct node *explorer = prev->next;

    while (explorer->data != key && explorer != Tail) {
        prev = prev->next;
        explorer = prev->next;
    }

    if (explorer != Tail) {
        // explorer pointer acts as toDelete pointer int the delete_nextNode()
        prev->next = explorer->next;
        free(explorer);

        return 1;
    } else {
        return 0;
    }
}




void print_All() {
    struct node *explorer = Head->next;

    if (explorer == Tail) {
        printf("No data\n");

        return;
    } 

    while (explorer != Tail) {
        printf("%d ", explorer->data);
        explorer = explorer->next;
    }
    puts("");

}

void delete_All() {
    struct node *explorer, *prev;
    prev = Head;
    explorer = prev->next;

    while (explorer != Tail) {
        struct node *toDelete = explorer;

        explorer = explorer->next;
        prev->next = explorer;
        free(toDelete);
    }
}

// int insert_node(struct node * prev, int n)
// struct node * find_node(int key)
// int insert_node_afterKey(int n, int key)
// int insert_node_beforeKey(int n, int key)
// int delete_nextNode(struct node *prev)
// int delete_node_byKey(int key)
// void print_All()
// void delete_All()
int main(){
    int action, retry;
    int key, data;
    retry = 1;

    if (!InitNode()) {
        printf("InitNode Failed\n");
        return 0;
    }
    
    do {
        printf("Current data status\n");
        print_All();

        printf("Enter Action\n");
        printf("1. Insert Node at the front   2. Insert Node after key    3. Insert Node before key   4. Delete Node by key   5. Delete All   6. Print All    7. Terminate    8. Return to Menu\n");
        printf("Action: ");
        scanf("%d", &action);

        switch (action)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);

            if (!insert_node(data)) {
                puts("Insert Failed");
            } else {
                puts("Insert Success!");
            }

            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);

            printf("Enter key: ");
            scanf("%d", &key);

            if (!insert_node_afterKey(data, key)) {
                puts("Insert Failed");
            } else {
                puts("Insert Success!");
            }

            break;
        
        case 3:
            printf("Enter data to insert: ");
            scanf("%d", &data);

            printf("Enter key: ");
            scanf("%d", &key);

            if (!insert_node_beforeKey(data, key)) {
                puts("Insert Failed");
            } else {
                puts("Insert Success!");
            }

            break;
        
        case 4:
            printf("Enter key to delete: ");
            scanf("%d", &key);

            if (!delete_node_byKey(key)) {
                puts("Delete Failed");
            } else {
                puts("Delete Success!");
            }

            break;
        
        case 5:
            delete_All();
            printf("Deleted All Nodes\n");

            break;
        
        case 6:
            print_All();

            break;
        
        case 7:
            Terminate();
            retry = 0;
            break;
        
        case 8:
            break;
        
        default:
            break;
        }

        puts("");

    } while (retry == 1);

}
