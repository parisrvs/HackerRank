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

    int* arr_rev = (int*) malloc(num * sizeof(int));
    int counter = 0;
    for (int i=num-1; i>=0; i--)
    {
        arr_rev[counter] = arr[i];
        counter++;
    }

    free(arr);
    arr = arr_rev;

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    
    free(arr_rev);
    return 0;
}