#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print_word(int);

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
    
    for (int c = a; c <= b; c++)
    {
        if (c >= 1 && c <= 9)
            print_word(c);
        else if (c%2 == 0)
            printf("even\n");
        else
            printf("odd\n");
    }
    return 0;
}

void print_word(int n)
{
    if (n==1)
        printf("one\n");
    else if (n==2)
        printf("two\n");
    else if (n==3)
        printf("three\n");
    else if (n==4)
        printf("four\n");
    else if (n==5)
        printf("five\n");
    else if (n==6)
        printf("six\n");
    else if (n==7)
        printf("seven\n");
    else if (n==8)
        printf("eight\n");
    else
        printf("nine\n");
}
