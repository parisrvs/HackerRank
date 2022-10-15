#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int count;
    scanf("%i", &count);

    int* arr = malloc(sizeof(int)*count);
    if (arr == NULL)
        return 1;

    for (int c=0; c<count; c++)
        scanf("%i", arr+c);
    
    int sum = 0;
    for (int c=0; c<count; c++)
        sum += arr[c];

    printf("%i\n", sum);
    free(arr);
    return 0;
}