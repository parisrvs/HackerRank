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
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

typedef struct moves
{
    char* direction;
    int num_moves;
} moves;
 
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

moves* get_moves(int n, int r_q, int c_q)
{
    moves* m = malloc(sizeof(moves)*8);
    m[0].direction = "north";
    m[0].num_moves = n - r_q;

    m[1].direction = "north-west";
    m[1].num_moves = min(n - r_q, c_q - 1);

    m[2].direction = "north-east";
    m[2].num_moves = min(n - r_q, n - c_q);

    m[3].direction = "south";
    m[3].num_moves = r_q - 1;

    m[4].direction = "south-west";
    m[4].num_moves = min(r_q - 1, c_q - 1);

    m[5].direction = "south-east";
    m[5].num_moves = min(r_q - 1, n - c_q);

    m[6].direction = "west";
    m[6].num_moves = c_q - 1;

    m[7].direction = "east";
    m[7].num_moves = n - c_q;

    return m;

}



int queensAttack(int n, int k, int r_q, int c_q, int obstacles_rows, int obstacles_columns, int** obstacles)
{
    moves *m = get_moves(n, r_q, c_q);
    for (int c=0; c<k; c++)
    {
        if (obstacles[c][1] == c_q)
        {
            if (obstacles[c][0] > r_q)
                m[0].num_moves = min(obstacles[c][0] - r_q - 1, m[0].num_moves);
            else
                m[3].num_moves = min(r_q - obstacles[c][0] - 1, m[3].num_moves);
        }
        else if (obstacles[c][0] == r_q)
        {
            if (obstacles[c][1] > c_q)
                m[7].num_moves = min(obstacles[c][1] - c_q - 1, m[7].num_moves);
            else
                m[6].num_moves = min(c_q - obstacles[c][1] - 1, m[6].num_moves);
        }
        else if (obstacles[c][1] - obstacles[c][0] == c_q - r_q)
        {
            if (obstacles[c][1] < c_q && obstacles[c][0] < r_q)
                m[4].num_moves = min(min(c_q - obstacles[c][1] - 1, r_q - obstacles[c][0] - 1), m[4].num_moves);
            else if (obstacles[c][1] > c_q && obstacles[c][0] > r_q)
                m[2].num_moves = min(min(obstacles[c][1] - c_q - 1, obstacles[c][0] - r_q - 1), m[2].num_moves);
        }
        else if (obstacles[c][1] + obstacles[c][0] == c_q + r_q)
        {
            if (obstacles[c][1] < c_q && obstacles[c][0] > r_q)
                m[1].num_moves = min(min(obstacles[c][0] - r_q - 1, c_q - obstacles[c][1] - 1), m[1].num_moves);
            else if (obstacles[c][1] > c_q && obstacles[c][0] < r_q)
                m[5].num_moves = min(min(r_q - obstacles[c][0] - 1, obstacles[c][1] - c_q - 1), m[5].num_moves);
        }
    }

    int count = 0;
    for (int c=0; c<8; c++)
        count += m[c].num_moves;

    free(m);
    return count;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int k = parse_int(*(first_multiple_input + 1));

    char** second_multiple_input = split_string(rtrim(readline()));

    int r_q = parse_int(*(second_multiple_input + 0));

    int c_q = parse_int(*(second_multiple_input + 1));

    int** obstacles = malloc(k * sizeof(int*));

    for (int i = 0; i < k; i++) {
        *(obstacles + i) = malloc(2 * (sizeof(int)));

        char** obstacles_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 2; j++) {
            int obstacles_item = parse_int(*(obstacles_item_temp + j));

            *(*(obstacles + i) + j) = obstacles_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, k, 2, obstacles);

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
