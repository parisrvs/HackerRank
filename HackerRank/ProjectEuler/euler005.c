#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long long int get_euler005(int);

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        printf("%lli\n", get_euler005(n));
    }
    return 0;
}


long long int get_euler005(int n)
{
    long long int number = n;
    while(true)
    {
        int c = 1;
        for (; c<=n; c++)
            if(number % c != 0)
                break;
        if (c > n)
            return number;
        else
            number++;
    }
    return number;
}
