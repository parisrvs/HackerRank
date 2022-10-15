#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

int minimum(int *a, int a_count)
{
    int min = a[0];
    for (int c=1; c<a_count; c++)
        if (a[c] < min)
            min = a[c];
    
    return min;
}


int formingMagicSquare(int s_rows, int s_columns, int** s)
{
    int* c =  malloc(sizeof(int)*8);
    int c0[3][3] = {{8,1,6},{3,5,7},{4,9,2}};
    int c1[3][3] = {{6,1,8},{7,5,3},{2,9,4}};
    int c2[3][3] = {{4,9,2},{3,5,7},{8,1,6}};
    int c3[3][3] = {{2,9,4},{7,5,3},{6,1,8}};
    int c4[3][3] = {{8,3,4},{1,5,9},{6,7,2}};
    int c5[3][3] = {{4,3,8},{9,5,1},{2,7,6}};
    int c6[3][3] = {{6,7,2},{1,5,9},{8,3,4}};
    int c7[3][3] = {{2,7,6},{9,5,1},{4,3,8}};

    int count = 0;
    for (int x=0; x<3; x++)
        for (int y=0; y<3; y++)
            count += abs(c0[x][y] - s[x][y]);
    c[0] = count;
    count = 0;

    for (int x=0; x<3; x++)
        for (int y=0; y<3; y++)
            count += abs(c1[x][y] - s[x][y]);
    c[1] = count;
    count = 0;

    for (int x=0; x<3; x++)
        for (int y=0; y<3; y++)
            count += abs(c2[x][y] - s[x][y]);
    c[2] = count;
    count = 0;

    for (int x=0; x<3; x++)
        for (int y=0; y<3; y++)
            count += abs(c3[x][y] - s[x][y]);
    c[3] = count;
    count = 0;

    for (int x=0; x<3; x++)
        for (int y=0; y<3; y++)
            count += abs(c4[x][y] - s[x][y]);
    c[4] = count;
    count = 0;

    for (int x=0; x<3; x++)
        for (int y=0; y<3; y++)
            count += abs(c5[x][y] - s[x][y]);
    c[5] = count;
    count = 0;

    for (int x=0; x<3; x++)
        for (int y=0; y<3; y++)
            count += abs(c6[x][y] - s[x][y]);
    c[6] = count;
    count = 0;

    for (int x=0; x<3; x++)
        for (int y=0; y<3; y++)
            count += abs(c7[x][y] - s[x][y]);
    c[7] = count;
    count = 0;

    int min = minimum(c, 8);
    free(c);
    return min;

}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int** s = malloc(3 * sizeof(int*));

    for (int i = 0; i < 3; i++) {
        *(s + i) = malloc(3 * (sizeof(int)));

        char** s_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 3; j++) {
            int s_item = parse_int(*(s_item_temp + j));

            *(*(s + i) + j) = s_item;
        }
    }

    int result = formingMagicSquare(3, 3, s);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = NULL;

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = NULL;
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = NULL;
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return NULL;
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return NULL;
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
