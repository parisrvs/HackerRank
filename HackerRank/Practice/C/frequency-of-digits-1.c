#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    char* s = malloc(1000*sizeof(char));
    scanf("%s", s);
    int l =strlen(s);
    s = realloc(s, l+1);

    int* arr = malloc(sizeof(int)*10);
    for (int c=0; c<10; c++)
        arr[c] = 0;
    
    int z;
    for (int c=0; c<l; c++)
    {
        if (s[c] >= 48 && s[c] <= 57)
        {
            z = (int) (s[c] - 48);
            arr[z] += 1;
        }
    }

    for (int c=0; c<10; c++)
        if (c == 9)
            printf("%i\n", arr[c]);
        else
            printf("%i ", arr[c]);

    free(arr);
    free(s);
    return 0;
}
