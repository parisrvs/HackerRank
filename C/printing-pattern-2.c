#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);

    int p = n, c, z;
    for (int x = 1; x <= (n*2-1); x++) {

        if (p == 1)
            c = 0;
        else if (p == n)
            c = 1;

        z = (n*2-1) - (p*2-1);
        z = z / 2;
        int o = n;
        
            
        for (int m = 0; m < z; m++)
            printf("%i ", o--);
        for (int m = 0; m < (p*2-1); m++)
            printf("%i ", o);
        for (int m = 0; m < z; m++)
            printf("%i ", ++o);
 

        if (c)
            p--;
        else
            p++;
        
        printf("\n");
    }
    return 0;
}