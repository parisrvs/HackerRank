#include <stdio.h>
#include "/home/paris/Codes/HackerRank/clibs/myio.h"
#include "/home/paris/Codes/HackerRank/clibs/myalgo.h"


void bonAppetit(int bill_count, int* bill, int k, int b) {
    int sum = 0;
    for (int c = 0; c < bill_count; c++)
        if (c != k)
            sum += (*(bill+c));
    
    if ((sum / 2) == b)
        printf("Bon Appetit\n");
    else
        printf("%i\n", b - (sum/2));
}



int main(void) {
    int count = get_int("Count: ");
    int k = get_int("K: ");
    int *arr = malloc(sizeof(int)*count);
    
    int c;
    for (c = 0; c < count; c++)
        *(arr+c) = get_int("Number: ");
    
    
    int b = get_int("Charge: ");
    bonAppetit(count, arr, k, b);
    free(arr);
}