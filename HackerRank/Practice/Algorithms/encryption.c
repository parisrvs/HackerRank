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

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* removespaces(char* s);
char** get_grid(int rows, int columns, char* string);
char* encrypt(int rows, int columns, char** grid);
void free_grid(int rows, char** string);

char* encryption(char* s)
{
    char* string = removespaces(s);
    int rows = floor(sqrt(strlen(string)));
    int columns = ceil(sqrt(strlen(string)));
    while((rows*columns) < strlen(string))
        rows++;
    char** grid = get_grid(rows, columns, string);
    char* result = encrypt(rows, columns, grid);
    free_grid(rows, grid);
    free(string);
    return result;
}

char* removespaces(char* s)
{
    int l = strlen(s), counter = 2;
    char* string = NULL;
    for (int c=0; c<l; c++)
        if (s[c] != ' ')
        {
            string = realloc(string, sizeof(char)*counter);
            string[counter-2] = s[c];
            string[counter-1] = '\0';
            counter++;
        }
    return string;
}


char** get_grid(int rows, int columns, char* string)
{
    int d, index = 0, l = strlen(string);
    char** grid = malloc(sizeof(char*)*rows);
    for (int c=0; c<rows; c++)
    {
        grid[c] = malloc(sizeof(char)*(columns+1));
        for (d=0; d<columns; d++)
        {
            if (index == l)
                grid[c][d] = '\0';
            else
            {
                grid[c][d] = string[index];
                index++;
            }
        }
        grid[c][d] = '\0';
    }
    return grid;
}

char* encrypt(int rows, int columns, char** grid)
{
    char* string = malloc(sizeof(char)*((rows*columns)+(columns+1)));
    int l, counter = 0, d;
    for (int c=0; c<columns; c++)
    {
        for (d=0; d<rows; d++)
        {
            if (grid[d][c] != '\0')
            {
                string[counter] = grid[d][c];
                counter++;
            }
        }
        string[counter] = ' ';
        counter++;
    }
    string[counter] = '\0';
    return string;
}

void free_grid(int rows, char** string)
{
    for (int c=0; c<rows; c++)
        free(string[c]);
    free(string);
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = encryption(s);

    fprintf(fptr, "%s\n", result);

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
