#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n, c=0;
    scanf("%d", &n);
    
    while(n > 0)
    {
        c += n%10;
        n = n/10;
    }

    printf("%i\n", c);
    return 0;
}
