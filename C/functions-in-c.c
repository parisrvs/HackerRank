#include <stdio.h>
#include "/home/paris/Codes/HackerRank/clibs/myio.h"
#include "/home/paris/Codes/HackerRank/clibs/myalgo.h"


int max_of_four(int a, int b, int c, int d) {
    int num1, num2;
    if (a > b)
        num1 = a;
    else
        num1 = b;

    if (c > d)
        num2 = c;
    else
        num2 = d;
    
    if (num1 > num2)
        return num1;
    else
        return num2;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}