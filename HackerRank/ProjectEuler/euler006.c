#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long long euler006(int);

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        printf("%lli\n", euler006(n));
    }
    return 0;
}


long long euler006(int n)
{
    long long count1 = 0, count2 = 0;
    for (int c=1; c<=n; c++)
    {
        count1 += c;
        count2 += pow(c, 2);
    }
    count1 = pow(count1, 2);
    return llabs(count1 - count2);
}