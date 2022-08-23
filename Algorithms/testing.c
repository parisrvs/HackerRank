#include <stdio.h>
#include "/home/paris/Codes/HackerRank/clibs/myio.h"
#include "/home/paris/Codes/HackerRank/clibs/myalgo.h"


int divisibleSumPairs(int n, int k, int ar_count, int* ar) {
    int count = 0;
    for (int x = 0; x < ar_count - 1; x++)
        for (int y = x+1; y < ar_count; y++)
            if (((ar[x] + ar[y]) % k) == 0)
                count++;
    
    return count;
}

int main(void) {
    int count = get_int("Count: ");
    int *arr = malloc(sizeof(int)*count);
    
    int c;
    for (c = 0; c < count; c++)
        *(arr+c) = get_int("Number: ");
    
    int d = get_int("K ");
    printf("%i\n", divisibleSumPairs(count, d, count, arr));
    free(arr);
}