#include <stdio.h>
#include "/home/paris/Codes/HackerRank/clibs/myio.h"
#include "/home/paris/Codes/HackerRank/clibs/myalgo.h"


int absoluteValue(int x) {
    if (x < 0)
        return -x;
    return x;
}


int formingMagicSquare(int s_rows, int s_columns, int s[3][3]) {
    int combinations[8][3][3] = {
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}}, 
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
    };

    int min = 10000, sum;
    for (int x = 0; x < 8; x++) {
        sum = 0;
        for (int y = 0; y < 3; y++)
            for (int z = 0; z < 3; z++)
                sum += absoluteValue(combinations[x][y][z] - s[y][z]);
        
        printf("Sum: %i\tMin: %i\n", sum, min);
        if (sum < min)
            min = sum;
    }
    
    return min;
}

void print_matrix(int arr[3][3]) {
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++)
            printf("%3i", arr[c][d]);
        printf("\n");
    }
}


int main(void) {

    int arr1[3][3] = {{5, 3, 4}, {1, 5, 8}, {6, 4, 2}};
    int arr2[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 5}};
    int arr3[3][3] = {{4, 8, 2}, {4, 5, 7}, {6, 1, 6}};

    // print_matrix(arr1);
    int x1 = formingMagicSquare(3,3,arr1);
    printf("\n");
    // print_matrix(arr2);
    int x2 = formingMagicSquare(3,3,arr2);
    printf("\n");
    // print_matrix(arr3);
    int x3 = formingMagicSquare(3,3,arr3);
    printf("\n");
    printf("%i\t%i\t%i\n", x1, x2, x3);
}