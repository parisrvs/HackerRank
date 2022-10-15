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
 * Complete the 'twoPluses' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY grid as parameter.
 */

typedef struct NODE
{
    int x;
    int count;
    int r;
    int c;
    struct NODE* next;
}NODE;

NODE* node = NULL;
int LIMIT = 1;

int checkpluses(char**, int, int, int, int, int, int);
NODE* add_to_node(int, int, int, int, NODE*);
void isort_llist_desc(NODE*);
void markpluses(NODE*, char**);
int check_pluses(int, int, char**, int);
void free_node(NODE*);
int allpluses(int, char**, int);


int twoPluses(int grid_count, char** grid)
{
    int max = allpluses(grid_count, grid, 0);
    int limit = LIMIT - 4, temp;
    while(limit > 0)
    {
        temp = allpluses(grid_count, grid, limit);
        if (temp > max)
            max = temp;
        limit = limit - 4;
    }
    free_node(node);
    node = NULL;
    return max;
}


int allpluses(int grid_count, char**grid, int limit)
{
    int rows = grid_count, max = 0, temp;
    int columns = strlen(grid[0]);
    for (int r = 1; r < rows; r++)
        for (int c = 1; c < columns; c++)
            if (grid[r][c] == 'G')
                checkpluses(grid, rows, columns, r, c, 1, limit);
    
    if (node)
    {
        isort_llist_desc(node);
        NODE* n = NULL;
        for (n = node; n != NULL; n = (*n).next)
        {
            markpluses(n, grid);
            temp = check_pluses(rows, columns, grid, limit);
            temp = temp * ((*n).count);
            if (max <= temp)
                max = temp;
            markpluses(n, grid);
        }
        LIMIT = (*node).count;
    }
    
    
    if (max == 0)
        return 1;
    else
        return max;
}


int checkpluses(char** grid, int rows, int columns, int r, int c, int check, int limit)
{
    int x = 1, count = 1;
    while(((c+x) < columns) && ((c-x) >= 0) && ((r+x) < rows) && ((r-x) >= 0))
    {   
        if (grid[r+x][c] == 'B' || grid[r-x][c] == 'B' ||  grid[r][c+x] == 'B' || grid[r][c-x] == 'B')
            break;
        else
            count += 4;
        x++;
        if (count == limit)
            break;
    }

    if (count > 1 && check)
        node = add_to_node(x, count, r, c, node);
    
    return count;
}


int check_pluses(int rows, int columns, char** grid, int limit)
{
    int max = 0, x;
    for (int r = 1; r < rows; r++)
        for (int c = 1; c < columns; c++)
            if (grid[r][c] == 'G')
            {
                x = checkpluses(grid, rows, columns, r, c, 0, limit);
                if (max < x)
                    max = x;
            }
    return max;
}


NODE* add_to_node(int x, int count, int r, int c, NODE* head)
{
    NODE* n = malloc(sizeof(NODE));
    (*n).c = c;
    (*n).x = x;
    (*n).count = count;
    (*n).r = r;

    if (head == NULL)
        (*n).next = NULL;
    else
        (*n).next = head;
    
    return n;
}


void isort_llist_desc(NODE* head)
{
    if (!head || (*head).next == NULL)
        return;

    NODE* c, *d;
    int temp_c, temp_x, temp_r, temp_count;
    for (c = head; c != NULL; c = (*c).next)
    {
        for (d = (*c).next; d != NULL; d = (*d).next)
        {
            if ((*c).count < (*d).count)
            {
                temp_c = (*c).c;
                temp_count = (*c).count;
                temp_r = (*c).r;
                temp_x = (*c).x;

                (*c).count = (*d).count;
                (*c).x = (*d).x;
                (*c).r = (*d).r;
                (*c).c = (*d).c;

                (*d).x = temp_x;
                (*d).count = temp_count;
                (*d).r = temp_r;
                (*d).c = temp_c;
            }
        }
    }
    return;
}

void markpluses(NODE* head, char** grid)
{
    int row = (*head).r;
    int column = (*head).c;
    for (int c = 1; c < (*head).x; c++)
    {
        if (grid[row+c][column] == 'G')
            grid[row+c][column] = 'B';
        else
            grid[row+c][column] = 'G';
        
        if (grid[row-c][column] == 'G')
            grid[row-c][column] = 'B';
        else
            grid[row-c][column] = 'G';

        if (grid[row][column+c] == 'G')
            grid[row][column+c] = 'B';
        else
            grid[row][column+c] = 'G';
        
        if (grid[row][column-c] == 'G')
            grid[row][column-c] = 'B';
        else
            grid[row][column-c] = 'G';
    }
    if (grid[row][column] == 'G')
        grid[row][column] = 'B';
    else
        grid[row][column] = 'G';
        
    return;
}

void free_node(NODE* head)
{
    NODE* temp;
    while(head)
    {
        temp = head;
        head = (*head).next;
        free(temp);
    }
    return;
}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int m = parse_int(*(first_multiple_input + 1));

    char** grid = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char* grid_item = readline();

        *(grid + i) = grid_item;
    }

    int result = twoPluses(n, grid);

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
