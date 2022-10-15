#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k)
{
	int and_max = 0, or_max = 0, xor_max = 0;

    for (int c = 1; c <= n; c++)
        for (int d = c+1; d <= n; d++)
		{
            if (((c & d) > and_max) && ((c & d) < k))
				and_max = c & d;
			
            if (((c | d) > or_max) && ((c | d) < k))
                or_max = c | d;
			
            if (((c ^ d) > xor_max) && ((c ^ d) < k))
                xor_max = c ^ d;
        }

    printf("%i\n%i\n%i\n", and_max, or_max, xor_max);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}

