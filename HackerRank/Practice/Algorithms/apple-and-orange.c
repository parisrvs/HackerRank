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
 * Complete the 'countApplesAndOranges' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER s
 *  2. INTEGER t
 *  3. INTEGER a
 *  4. INTEGER b
 *  5. INTEGER_ARRAY apples
 *  6. INTEGER_ARRAY oranges
 */

void countApplesAndOranges(int s, int t, int a, int b, int apples_count, int* apples, int oranges_count, int* oranges) {
    int* apple_array = malloc(sizeof(int)*apples_count);
    int* orange_array = malloc(sizeof(int)*oranges_count);
    int t_apples = 0, t_oranges = 0;

    for (int c=0; c<apples_count; c++)
        apple_array[c] = (apples[c])+a;

    for (int c=0; c<oranges_count; c++)
        orange_array[c] = (oranges[c])+b;
    
    for (int c=0; c<apples_count; c++)
        if (apple_array[c] >= s && apple_array[c] <=t)
            t_apples++;
    
    for (int c=0; c<oranges_count; c++)
        if (orange_array[c] >= s && orange_array[c] <= t)
            t_oranges++;
    
    free(apple_array);
    free(orange_array);
    printf("%i\n%i\n", t_apples, t_oranges);
}

int main()
{
    char** first_multiple_input = split_string(rtrim(readline()));

    int s = parse_int(*(first_multiple_input + 0));

    int t = parse_int(*(first_multiple_input + 1));

    char** second_multiple_input = split_string(rtrim(readline()));

    int a = parse_int(*(second_multiple_input + 0));

    int b = parse_int(*(second_multiple_input + 1));

    char** third_multiple_input = split_string(rtrim(readline()));

    int m = parse_int(*(third_multiple_input + 0));

    int n = parse_int(*(third_multiple_input + 1));

    char** apples_temp = split_string(rtrim(readline()));

    int* apples = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        int apples_item = parse_int(*(apples_temp + i));

        *(apples + i) = apples_item;
    }

    char** oranges_temp = split_string(rtrim(readline()));

    int* oranges = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int oranges_item = parse_int(*(oranges_temp + i));

        *(oranges + i) = oranges_item;
    }

    countApplesAndOranges(s, t, a, b, m, apples, n, oranges);

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
