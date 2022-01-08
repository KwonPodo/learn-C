#include <stdio.h>
#include <stdlib.h>

void main() {
    int num = 10;
    int* ptr = &num;
    int** dptr = &ptr;
    int arr[2][3] = {1,2,3,4,5,6};

    printf("&num: %d\n", &num);
    printf("ptr: %d\n", ptr);
    printf("&ptr: %d\n", &ptr);
    printf("dptr: %d\n", dptr);
    printf("*dptr: %d\n", *dptr);
    printf("**dptr: %d\n", **dptr);
    puts("");

    printf("sizeof(arr): %d\n", sizeof(arr));
    printf("sizeof(&arr): %d\n", sizeof(&arr));
    printf("sizeof(arr[0]): %d\n", sizeof(arr[0]));
    printf("sizeof(&arr[0]): %d\n", sizeof(&arr[0]));
    printf("sizeof(arr[0][0]): %d\n", sizeof(arr[0][0]));
    puts("");

    printf("arr: %d\n", arr);
    printf("arr + 1: %d\n", (arr + 1));
    printf("&arr + 1: %d\n", (&arr + 1));
    printf("(arr[0] + 1): %d\n", (arr[0] + 1));
    printf("(&arr[0] + 1): %d\n", (&arr[0] + 1));
    puts("");

    printf("arr: %d\n", arr);
    printf("&arr: %d\n", (&arr));
    printf("(arr[0]): %d\n", (arr[0]));
    printf("(&arr[0]): %d\n", (&arr[0]));
    puts("");

    printf("*(arr + 1): %d\n", *(arr + 1));
    printf("*(arr[0] + 1): %d\n", *(arr[0] + 1));
    printf("*(&arr + 1): %d\n", *(&arr + 1));
    printf("**(&arr + 1): %d\n", **(&arr + 1));
    printf("**(&arr[0] + 1): %d\n", **(&arr[0] + 1));
    puts("");

    
    
}
