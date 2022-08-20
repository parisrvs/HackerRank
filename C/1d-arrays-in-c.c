#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%i", &n);

    int *arr = (int*) malloc(sizeof(int)*n);
    for (int c = 0; c < n; c++)
        scanf("%i", (arr+c));
    
    int sum = 0;
    for (int c = 0; c < n; c++)
    sum += (*(arr+c));

    printf("%i\n", sum);
    free(arr);
    return 0;
}
