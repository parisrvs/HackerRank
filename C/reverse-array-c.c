#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


    int *arr_copy = (int*) malloc(num * sizeof(int));
    int count = 0;
    for (int c = num -1; c >= 0; c--)
        arr_copy[count++] = arr[c];
    
    free(arr);
    arr = arr_copy;

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    
    free(arr);
    return 0;
}