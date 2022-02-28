#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 32

FILE *fp;

typedef struct node{
    char *name;
    char* studentId;
    char *phoneNumber;
    struct node *next;
    struct node *prev;
} student;

student *head, *tail;

int init() {
    // 더미 생성
    head = (student*)malloc(sizeof(student));
    tail = (student*)malloc(sizeof(student));

    if (head == NULL || tail == NULL) {
        free(head); free(tail);
        return 0;
    }

    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;

    head->name = "DummyHead";
    tail->name = "DummyTail";

    return 1;
}

void terminate() {
    if (head != NULL || tail != NULL) {
        free(head); free(tail);
    }
}

void cleanBuff() {
    while (getchar() != '\n');
}

student* createStudent(char *name, char *studentId, char *phoneNumber) {
    student *new = (student*)malloc(sizeof(student));

    new->name = (char*)calloc(MAX, sizeof(char));
    new->phoneNumber = (char*)calloc(MAX, sizeof(char));
    new->studentId = (char*)calloc(MAX, sizeof(char));

    // printf("Enter student's name: "); 
    // gets(new->name);
    strcpy(new->name, name);

    // printf("Enter studentId: "); 
    // gets(new->studentId);
    strcpy(new->studentId, studentId);

    // printf("Enter student's phone number: "); 
    // gets(new->phoneNumber);
    strcpy(new->phoneNumber, phoneNumber);

    new->next = NULL;
    new->prev = NULL;

    return new;
}

// append to tail
void addStudent(student *new) {

    if (head->next == tail) {
        head->next = new;
        tail->prev = new;
        new->next = tail;
        new->prev = head;
    } else {
        new->prev = tail->prev;
        new->next = tail;

        tail->prev->next = new;
        tail->prev = new;
    }
}

student* searchStudent() {
    int menu;
    char *cmp = calloc(MAX, sizeof(char));
    student *s = head->next;

    do {
        printf("Search by? (1) Name (2) Id (3) Phone number: ");
        scanf("%d", &menu);
        
    } while (!(menu == 1 || menu == 2 || menu == 3));

    switch (menu)
    {
    case 1:
        cleanBuff();

        printf("Enter name: "); 
        scanf("%s", cmp);

        while (s != tail) {
            if (!strcmp(s->name, cmp)) break;
            s = s->next;
        }

        break;
    
    case 2:
        cleanBuff();

        printf("Enter Id: ");
        scanf("%s", cmp);

        while (s != tail) {
            if (!strcmp(s->studentId, cmp)) break;
            s = s->next;
        }

        break;
    
    case 3:
        cleanBuff();

        printf("Enter phone number: ");
        scanf("%s", cmp);

        while (s != tail) {
            if (!strcmp(s->phoneNumber, cmp)) break;
            s= s->next;
        }

        break;
    
    default:
        break;
    }

    free(cmp);

    return s;
}

void removeStudent(student *toRemove) {
    toRemove->prev->next = toRemove->next;
    toRemove->next->prev = toRemove->prev;

    if (!(toRemove == head || toRemove == tail)) {
        free(toRemove->name);
        free(toRemove->studentId);
        free(toRemove->phoneNumber);
        free(toRemove);
    }

}

void modifyStudent(student *toModify) {
    int menu, retry;
    char buff[MAX];

    cleanBuff();

    do {
        do {
        printf("Member to modify (1) Name (2) Id (3) Phone Number : ");
        scanf("%d", &menu);
        } while (!(menu == 1 || menu == 2 || menu == 3));

        cleanBuff();

        switch (menu)
        {
        case 1:
            printf("Enter New Name: ");
            scanf("%s", buff);

            strcpy(toModify->name, buff);
            break;
        
        case 2:
            printf("Enter New Id: ");
            scanf("%s", buff);
            
            strcpy(toModify->studentId, buff);
            break;
        
        case 3:
            printf("Enter New Phone Number: ");
            scanf("%s", buff);

            strcpy(toModify->phoneNumber, buff);
            break;
        
        default:
            break;
        }

        printf("Remodify? (1) Remodify (Any other num) Exit modify : ");
        scanf("%d", &retry);

    } while (retry == 1);
    
}

void printNode(const student *s) {
    printf("Name: %s\n", s->name);
    printf("Id: %s\n", s->studentId);
    printf("Phone Number: %s\n", s->phoneNumber);
    puts("");
}

int printAllNodes() {
    student *printer = head->next;

    if (printer == tail) {
        printf("No  data\n");
        return 0;
    }
    while (1) {
        if (printer == tail) {
            break;
        }
        printf("Name: %s\n", printer->name);
        printf("Id: %s\n", printer->studentId);
        printf("Phone number: %s\n", printer->phoneNumber);
        puts("");

        printer = printer->next;
    }

    return 1;
}

int writeFile(char ch) {
    student *node = head->next;

    switch (ch)
    {
    case 'a':
        fp = fopen("./addressBook.txt", "at");
        break;
    case 'w':
        fp = fopen("./addressBook.txt", "wt");
        break;

    default:
        puts("Write File ERROR!");
        return 0;
        break;
    }

    while (node != tail) {
            // Write node to file
            fputs(node->name, fp);
            fputc('\t', fp);

            fputs(node->studentId, fp);
            fputc('\t', fp);

            fputs(node->phoneNumber, fp);
            fputc('\t', fp);

            if (node->next != tail) {
                fputc('\n', fp);
            }

            node = node->next;
        }
    
    fclose(fp);

    return 1;
}

int readFile() {
    char name[MAX];
    char id[MAX];
    char phoneNum[MAX];
    int ch;
    student *new;

    fp = fopen("./addressBook.txt", "rt");

    while (!feof(fp)) {
        fscanf(fp, "%[^\t]s", name);
        ch = fgetc(fp); // read tab

        fscanf(fp, "%[^\t]s", id);
        ch = fgetc(fp); // read tab

        fscanf(fp, "%[^\t]s", phoneNum);
        ch = fgetc(fp); // read tab

        ch = fgetc(fp);  // 
        
        // 노드를 연결
        addStudent(createStudent(name, id, phoneNum));

    }

    fclose(fp);

    return 1;
}

int main() {
    char name[MAX], id[MAX], phoneNum[MAX];

    int i;
    int retry = 1;
    int menu;

    init();

    do {
        puts("");
        printf("Enter action (0) Load Saved File (1) Add (2) Remove (3)Modify data (4) Search (5) Print All (6) Terminate\n");
        printf("Action : "); scanf("%d", &menu);
        puts("");
        cleanBuff();

        switch (menu)
        {
        case 0:
            readFile();
            break;

        case 1:
            printf("Enter Name: "); gets(name);
            printf("Enter Id: "); gets(id);
            printf("Enter Phone Number: "); gets(phoneNum);

            addStudent(createStudent(name, id, phoneNum));
            writeFile('w');
            break;
        
        case 2:
            removeStudent(searchStudent());
            writeFile('w');
            break;
        
        case 3:
            modifyStudent(searchStudent());
            writeFile('w');
            break;
        
        case 4:
            printNode(searchStudent());

            break;
        
        case 5:
            printAllNodes();
            break;
        
        case 6: 
            retry = 0;
            break;
        
        default:
            break;
        }


    } while (retry == 1);

    terminate();

    return 0;
}