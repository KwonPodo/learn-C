#include <stdio.h>
#include "member.h"
#include "linearProbe.h"

enum menuList {
    terminate, add, delete, search, clear, dump
};

enum menuList selectMenu() {
    int i;

    do {
        printf("Enter Action (0) Terminate (1) Add (2) Remove (3) Search (4) Clear (5) Dump\n");
        printf("Action : "); scanf("%d", &i);
    } while (i < terminate || i > dump);

    return (enum menuList)i;
}

int main() {
    enum menuList menu;

    struct linearHash hashTable;
    struct member target;

    initTable(&hashTable, 13);

    do {
        menu = selectMenu();
        puts("");

        switch (menu)
        {
        case terminate:
            terminateTable(&hashTable);
            break;
        
        case add:
            target = scanMember("추가", MEMBER_NAME | MEMBER_NO);
            if (!addData(&hashTable, &target)) {
                printf("addData Failed\n");
            }
            break;
        
        case delete:
            target = scanMember("삭제", MEMBER_NO);
            if (removeData(&hashTable, &target) == 0) {
                puts("removeData Failed");
            }

            break;
        
        case search:
            target = scanMember("검색", MEMBER_NO);
            puts("");
            
            struct bucket *s;
            if ((s = searchBucket(&hashTable, &target)) != NULL) {
                puts("Member found");
                printf("No : %d\nName : %s\n", s->data.no, s->data.name);
            } else {
                puts("No such Data");
            }

        case clear:
            clearTable(&hashTable);
            break;
        
        case dump:
            dumpTable(&hashTable);
            break;
        

        default:
            break;
        }
        puts("");
    } while (menu != terminate);
}