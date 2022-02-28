#include <stdio.h>
#include "member.h"
#include "chainHash.h"


int main() {
    int menu, action, result;
    
    struct member target;
    struct chainHash hashTable;
    initTable(&hashTable, 13);

    do {
        printf("Enter Action (1) Add (2) Remove (3) Search (4) Clear (5) Dump (0) Terminate\n");
        printf("Action : "); scanf("%d", &action);

        switch (action)
        {
        case 0:
            terminateTable(&hashTable);
            break;
        
        case 1:
            target = scanMember("추가", MEMBER_NO | MEMBER_NAME);

            result = addData(&hashTable, &target);

            if (!result) {
                puts("Error. Add Failed");
            }
            break;
        
        case 2:
            target = scanMember("삭제", MEMBER_NO);

            result = removeData(&hashTable, &target);

            if (!result) {
                puts("Error. Remove Failed");
            }
            break;
        
        case 3:
            target = scanMember("검색", MEMBER_NO);
            struct node *tmp = search(&hashTable, &target);
            puts("");
            printMember(&(tmp->data));
            break;
        
        case 4:
            clearTable(&hashTable);
            break;

        case 5:
            dumpTable(&hashTable);
            break;
        default:
            break;
        }

        puts("");
    } while (action != 0);
}