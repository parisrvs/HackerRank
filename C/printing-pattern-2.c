#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);

    int p = n, c, z = n;
    for (int x = 1; x <= (n*2-1); x++) {

        if (p == 1)
            c = 0;
        else if (p == n)
            c = 1;

        for (int y = 1; y <= (n*2-1); y++) {
            if (y == 1 || y == (n*2-1))
                printf("%i ", z);
            else
                printf("%i ", p);
        }

        if (c)
            p--;
        else
            p++;
        
        printf("\n");
    }
    return 0;
}