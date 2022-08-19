#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);

    char* numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (; a <= b; a++) {
        if (a <= 9)
            printf("%s\n", numbers[a]);
        else if (a % 2 == 0)
            printf("even\n");
        else
            printf("odd\n");
    }
    return 0;
}

