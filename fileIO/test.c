#include <stdio.h>
#include <stdlib.h>

FILE *fp;

int main(int argc, char const *argv[])
{
    char a[30];
    int b;
    printf("argc: %d\n", argc);
    int i;

    for (i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    fp = fopen(argv[1], "rt");
    fscanf(fp, "%d", &b);

    printf("%d", b);
    
    return 0;
}