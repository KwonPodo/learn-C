#include <stdio.h>
#include <string.h>

char *my_strtok(char *p, char del[]) {
    printf("%d", strlen(p));

    return NULL;
}

int main() {
    char a[] = "Winter";
    // char *ptr = my_strtok(a, "+- ");
    printf("%d", strlen(a));

    // printf("%s", ptr);
}