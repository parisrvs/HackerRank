#include <stdio.h>
#include "/home/paris/Codes/HackerRank/clibs/myio.h"
#include "/home/paris/Codes/HackerRank/clibs/myalgo.h"

int pageCount(int n, int p) {
    if (p == 1)
        return 0;
    
    if (((n%2) && (p == n || p == n-1)) || (!(n%2) && (p == n)))
        return 0;
    
    if (n % 2 == 0 && p == n - 1)
        return 1;
        
    int count_front = 1, count_back = 0, c;
    c = 2;
    while (c <= p) {
        if (p == c || p == (c + 1))
            break;
        c+=2;
        count_front++;
    }

    c = n;
    while (p <= c) {
        if (p == c || p == (c - 1))
            break;
        c-=2;
        count_back++;
    }
    
    if (count_back > count_front)
        return count_front;
    
    return count_back;
}

int main(void) {
    // int count = get_int("Count: ");
    // int *arr = malloc(sizeof(int)*count);
    
    // int c;
    // for (c = 0; c < count; c++)
    //     *(arr+c) = get_int("Number: ");
    // printf("%i\n", sockMerchant(count, count, arr));
    // free(arr);

    int n = get_int("Totap Pages: ");
    int p = get_int("Page: ");
    printf("%i\n", pageCount(n, p));
}