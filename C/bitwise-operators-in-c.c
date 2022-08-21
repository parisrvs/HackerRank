#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    int max_and = 0;
    int max_or = 0;
    int max_xor = 0;

    int x, y, z;

    for (int c = 1; c <= n; c++) {
        for (int d = c + 1; d <= n; d++) {
            x = (c & d);
            if (x > max_and && x < k)
                max_and = x;
            
            y = (c | d);
            if (y > max_or && y < k)
                max_or = y;
            
            z = (c ^ d);
            if (z > max_xor && z < k)
                max_xor = z;
        }
    }
    
    printf("%i\n%i\n%i\n", max_and, max_or, max_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
