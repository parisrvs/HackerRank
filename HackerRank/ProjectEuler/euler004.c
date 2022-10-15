#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int get_palindrome(int);
int opposite(int);

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        printf("%i\n", get_palindrome(n));
    }
    return 0;
}

int get_palindrome(int n)
{
    int l = 10*100, e;
    for (int c = 999; c >= 100; c--)
    {
        for (int d = c; d >= 100; d--)
        {
            e = c*d;
            if (e < l)
                break;
            else if (e == opposite(e) && e > l && e < n)
                l = e;
            else
                continue;
        }
    }
    return l;
}

int opposite(int n)
{
    int m = 0;
    while (n != 0)
    {
        m = m*10 + n%10;
        n = n / 10;
    }
    return m;
}