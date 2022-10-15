#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++)
    {
        long n; 
        scanf("%ld",&n);
        long count = 10, counter = 6;
        long int *a = malloc(sizeof(long)*7);
        a[0] = 1;
        a[1] = 2;
        a[2] = 3;
        a[3] = 5;
        a[4] = 8;
        a[5] = 13;
        a[6] = 21;
        if (n <= 21)
        {
            printf("%li\n", count);
        }
        else
        {
            while(a[counter] <= n)
            {
                if (a[counter] % 2 == 0)
                    count += a[counter];
                a = realloc(a, sizeof(long)*(counter+2));
                a[counter+1] = a[counter] + a[counter-1];
                counter++;
            }
            printf("%li\n", count);
        }
        free(a);
        a = NULL;
    }
    return 0;
}

/*
        while(a[-1] <= n):
            if a[-1]%2 == 0:
                count += a[-1]
            a.append(a[-1]+a[-2])
        print(count)

*/