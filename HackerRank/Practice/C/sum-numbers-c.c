#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    float x, y;
	scanf("%f %f", &x, &y);
    
    printf("%i %i\n%.1f %.1f\n", n+m, n-m, x+y, x-y);
    
    return 0;
}
