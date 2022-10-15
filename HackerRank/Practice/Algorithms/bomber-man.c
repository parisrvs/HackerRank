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
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */

/*
 * To return the string array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * char** return_string_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static char* a[5] = {"static", "allocation", "of", "string", "array"};
 *
 *     return a;
 * }
 *
 * char** return_string_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     char** a = malloc(5 * sizeof(char*));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = malloc(20 * sizeof(char));
 *     }
 *
 *     *(a + 0) = "dynamic";
 *     *(a + 1) = "allocation";
 *     *(a + 2) = "of";
 *     *(a + 3) = "string";
 *     *(a + 4) = "array";
 *
 *     return a;
 * }
 *
 */
void plantbombs(char**, int, int);
char** detonate(char**, int, int);
char** grid_copy(int, int);
void free_grid(char** grid, int rows, int columns);


char** bomberMan(int n, int grid_count, char** grid, int* result_count)
{
    int columns = strlen(grid[0]);
    int rows = grid_count;

    (*result_count) = grid_count;

    if (n == 1)
        return grid;
    else if ((n % 2) == 0)
    {
        plantbombs(grid, rows, columns);
        return grid;
    }
    
    char** newgrid1 = detonate(grid, rows, columns);
    char** newgrid2 = detonate(newgrid1, rows, columns);

    if ((n + 1)%4 == 0)
    {
        free_grid(newgrid2, rows, columns);
        return newgrid1;
    }
    else
    {
        free_grid(newgrid1, rows, columns);
        return newgrid2;
    }
}

void plantbombs(char** grid, int rows, int columns)
{
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < columns; c++)
            grid[r][c] = 'O';
    return;
}


char** detonate(char** grid, int rows, int columns)
{
    char** newgrid = grid_copy(rows, columns);
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < columns; c++)
            if (grid[r][c] == 'O')
            {
                newgrid[r][c] = '.';
                if (((r + 1) < rows) && ((r - 1) >= 0))
                {
                    newgrid[r + 1][c] = '.';
                    newgrid[r - 1][c] = '.';
                }
                else if ((r + 1) < rows)
                    newgrid[r + 1][c] = '.';
                else if ((r - 1) >= 0)
                    newgrid[r - 1][c] = '.';
                
                if (((c + 1) < columns) && ((c - 1) >= 0))
                {
                    newgrid[r][c + 1] = '.';
                    newgrid[r][c - 1] = '.';
                }
                else if ((c + 1) < columns)
                    newgrid[r][c + 1] = '.';
                else if ((c - 1) >= 0)
                    newgrid[r][c - 1] = '.';
            }
    return newgrid;
}


char** grid_copy(int rows, int columns)
{
    char** newgrid = malloc(sizeof(char*)*rows);
    for (int r = 0; r < rows; r++)
    {
        newgrid[r] = malloc(sizeof(char)*(columns+1));
        for (int c = 0; c < columns; c++)
            newgrid[r][c] = 'O';
        newgrid[r][columns] = '\0';
    }
    return newgrid;
}


void free_grid(char** grid, int rows, int columns)
{
    for (int c=0; c<rows; c++)
        free(grid[c]);
    free(grid);
    return;
}

 
 


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int r = parse_int(*(first_multiple_input + 0));

    int c = parse_int(*(first_multiple_input + 1));

    int n = parse_int(*(first_multiple_input + 2));

    char** grid = malloc(r * sizeof(char*));

    for (int i = 0; i < r; i++) {
        char* grid_item = readline();

        *(grid + i) = grid_item;
    }

    int result_count;
    char** result = bomberMan(n, r, grid, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%s", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

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
