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
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */
void printmatrix(int, int, int**);
void free_matrix(int, int, int**);
void rotate_matrix(int rows, int columns, int matrix_rows, int matrix_columns, int **matrix);


void matrixRotation(int matrix_rows, int matrix_columns, int** matrix, int r)
{
    int rows = 0, columns = 0, temp_r = matrix_rows, temp_c = matrix_columns, temp_rc;
    while(rows < matrix_rows/2 && columns < matrix_columns/2)
    {
        temp_rc = abs(((temp_r - rows)*2) + (((temp_c - columns)*2) - 4));
        for (int c = 0; c < (r%temp_rc); c++)
            rotate_matrix(rows, columns, matrix_rows, matrix_columns, matrix);
        rows++;
        columns++;
        temp_r--;
        temp_c--;
    }
    printmatrix(matrix_rows, matrix_columns, matrix);
    free_matrix(rows, columns, matrix);
    return;
}

void printmatrix(int r, int c, int **matrix)
{
    for (int x=0; x<r; x++)
        for (int y=0; y<c; y++)
            if (y == c-1)
                printf("%i\n", matrix[x][y]);
            else
                printf("%i ", matrix[x][y]);
}


void free_matrix(int r, int c, int** matrix)
{
    for (int x=0; x<r; x++)
        free(matrix[x]);
    free(matrix);
    return;
}


void rotate_matrix(int rows, int columns, int matrix_rows, int matrix_columns, int **matrix)
{
    int r1 = rows, r2 = matrix_rows - 1 - rows, c1 = columns, c2 = matrix_columns - 1 - columns, r, c;

    int temp1 = matrix[r2][c1], temp2;
    for (r = r2; r > r1; r--)
        matrix[r][c1] = matrix[r-1][c1];
    
    temp2 = matrix[r2][c2];
    for (c = c2; c > c1+1; c-- )
        matrix[r2][c] = matrix[r2][c-1];
    matrix[r2][c] = temp1;

    temp1 = matrix[r1][c2];
    for (r = r1; r < r2-1; r++)
        matrix[r][c2] = matrix[r+1][c2];
    matrix[r][c2] = temp2;

    for (c = c1; c < c2-1; c++)
        matrix[r1][c] = matrix[r1][c+1];
    matrix[r1][c] = temp1;
}



int main()
{
    char** first_multiple_input = split_string(rtrim(readline()));

    int m = parse_int(*(first_multiple_input + 0));

    int n = parse_int(*(first_multiple_input + 1));

    int r = parse_int(*(first_multiple_input + 2));

    int** matrix = malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++) {
        *(matrix + i) = malloc(n * (sizeof(int)));

        char** matrix_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < n; j++) {
            int matrix_item = parse_int(*(matrix_item_temp + j));

            *(*(matrix + i) + j) = matrix_item;
        }
    }

    matrixRotation(m, n, matrix, r);

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
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
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
        return '\0';
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
