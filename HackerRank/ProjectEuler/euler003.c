#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long long gpf(long n);

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        long n; 
        scanf("%ld",&n);
        printf("%lli\n", gpf(n));
    }
    return 0;
}

long long gpf(long n)
{
    long long max_prime = -1;
 
    while (n % 2 == 0)
    {
        max_prime = 2;
        n = n / 2;
    }
    while (n % 3 == 0)
    {
        max_prime = 3;
        n = n / 3;
    }
 
    for (int i = 5; i <= sqrt(n); i += 6)
    {
        while (n % i == 0)
        {
            max_prime = i;
            n = n / i;
        }
        while (n % (i + 2) == 0)
        {
            max_prime = i + 2;
            n = n / (i + 2);
        }
    }
 
    if (n > 4)
        max_prime = n;
 
    return max_prime;
}