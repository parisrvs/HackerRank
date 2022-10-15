#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int euler007(int);
void generate_primes(void);

int *primes = NULL, counter = 0;

int main()
{
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        printf("%i\n", euler007(n));
    }
    free(primes);
    return 0;
}


int euler007(int n)
{
    if (primes == NULL)
        generate_primes();
    return primes[n-1];
}

void generate_primes(void)
{
    int max_prime = 104743;
    int *a = malloc(sizeof(int)*(max_prime+1));
    for (int c=0; c<=max_prime; c++)
        a[c] = 1;
    
    int p = 2;
    while(p*p <= max_prime)
    {
        if (a[p])
            for (int c=(p*p); c < max_prime+1; c+=p)
                a[c] = 0;
        p+=1;
    }
    for (int c=2; c<max_prime+1; c++)
    {
        if (a[c])
        {
            primes = realloc(primes, sizeof (int)*(counter+1));
            primes[counter] = c;
            counter++;
        }
    }
    free(a);
}