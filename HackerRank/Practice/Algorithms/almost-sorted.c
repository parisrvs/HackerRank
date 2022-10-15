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
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void reverse_array(int *arr, int index1, int index2)
{
    if (index1 == index2)
        return;

    int temp, start = index1;
    for (int c = index2; c >= index1; c--)
    {
        if (start >= c)
            break;
        temp = arr[c];
        arr[c] = arr[start];
        arr[start] = temp;
        start++;
    }
    return;
}


int is_sorted(int *arr, int arr_count)
{
    for (int c=0; c<arr_count-1; c++)
        if (arr[c] > arr[c+1])
            return 0;
    return 1;
}

void almostSorted(int arr_count, int* arr)
{
    if (is_sorted(arr, arr_count))
    {
        printf("yes\n");
        return;
    }
    else if (arr_count == 2)
    {
        printf("yes\nswap 1 2\n");
        return;
    }

    int index1, index2;
    for (index1 = 0; index1 < (arr_count - 1); index1++)
        if (arr[index1] > arr[index1+1])
            break;
    
    for (index2 = (index1 + 1); index2 < arr_count; index2++)
        if (arr[index1] < arr[index2])
            break;
    
    if (index2 >= arr_count || index1 >= (arr_count - 1))
    {
        printf("no\n");
        return;
    }
    
    index2--;
    int temp = arr[index2];
    arr[index2] = arr[index1];
    arr[index1] = temp;
    
    if (is_sorted(arr, arr_count))
    {
        printf("yes\nswap %i %i\n", (index1 + 1), (index2 + 1));
        return;
    }
    else
    {
        temp = arr[index2];
        arr[index2] = arr[index1];
        arr[index1] = temp;
    }
    
    reverse_array(arr, index1, index2);
    if (is_sorted(arr, arr_count))
    {
        printf("yes\nreverse %i %i\n", (index1 + 1), (index2 + 1));
        return;
    }
    printf("no\n");
}

int main()
{
    int n = parse_int(ltrim(rtrim(readline())));

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int arr_item = parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    }

    almostSorted(n, arr);

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
