#include <stdlib.h>
#include <stdio.h>

void shakerSort(int a[], int n) 
{
    int i, j, k, cnt = 0;
    int tmp;
    k = 0;
    j = n - 1;

    while (k < j)
    {
        printf("k : %d\tj : %d\n", k, j);

        for (int l = 0; l < n; l++)
        {
            printf("%d ", a[l]);
        }
        puts("\n");

        for (i = k; i < j; i++)
        {
            if (a[i] > a[i + 1])
            {
                // swap
                tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
            }
        }

        for (i = i; i > k; i--)
        {
            if (a[i - 1] > a[i])
            {
                // swap
                tmp = a[i - 1];
                a[i - 1] = a[i];
                a[i] = tmp;
            }
        }

        k++; j--;
    }
}

int main() 
{
    int a[] = { 5, 1, 2, 6, 4, 3};
    int b[] = { 5, 3, 4, 1, 2 };

    // shakerSort(a, 6);
    // puts("");

    // printf("a : ");
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // puts("\n");


    shakerSort(b, 5);
    puts("\n");

    printf("b : ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", b[i]);
    }
    puts("");
}

// { 5, 3, 4, 1, 2 };
// { 5, 1, 2, 6, 4, 3 };