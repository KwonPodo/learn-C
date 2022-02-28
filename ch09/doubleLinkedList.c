/**
 * 이중 연결 리스트 (Doubly Linked List)
 */
#include <stdio.h>
#include <stdlib.h>

struct dnode {
    int data;
    struct dnode *prev;
    struct dnode *next;
};


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
        scanf_s("%d", &action);

        switch (action)
        {
        case 1:
            printf("Enter data: ");
            scanf_s("%d", &data);

            if (!insert_node(data)) {
                puts("Insert Failed");
            } else {
                puts("Insert Success!");
            }

            break;
        case 2:
            printf("Enter data to insert: ");
            scanf_s("%d", &data);

            printf("Enter key: ");
            scanf_s("%d", &key);

            if (!insert_node_afterKey(data, key)) {
                puts("Insert Failed");
            } else {
                puts("Insert Success!");
            }

            break;
        
        case 3:
            printf("Enter data to insert: ");
            scanf_s("%d", &data);

            printf("Enter key: ");
            scanf_s("%d", &key);

            if (!insert_node_beforeKey(data, key)) {
                puts("Insert Failed");
            } else {
                puts("Insert Success!");
            }

            break;
        
        case 4:
            printf("Enter key to delete: ");
            scanf_s("%d", &key);

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