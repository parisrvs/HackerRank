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

int parse_int(char*);

/*
 * Complete the 'weightedUniformStrings' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY queries
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
int* get_weights(char c, int count);
char* get_alphabets(void);

char *alphabets = NULL;

typedef struct unistr
{
    char c;
    int count;
    int *weights;
}unistr;

char** weightedUniformStrings(char* s, int queries_count, int* queries, int* result_count)
{
    alphabets = get_alphabets();
    unistr* a = NULL;
    int l = strlen(s), c = 0, struct_counter = 0;
    int* weights = NULL, weights_counter = 0;

    while(c < l)
    {
        a = realloc(a, sizeof(unistr)*(struct_counter+1));
        a[struct_counter].c = s[c];
        a[struct_counter].count = 1;

        while(1)
        {
            if (s[c] == s[c+1])
                a[struct_counter].count += 1;
            else
                break;
            c++;
        }
        a[struct_counter].weights = get_weights(a[struct_counter].c, a[struct_counter].count);
        c++;
        struct_counter++;
    }

    for (int x = 0; x < struct_counter; x++)
    {   
        for (int y = 0; y < a[x].count; y++)
        {
            weights = realloc(weights, sizeof(int)*(weights_counter+1));
            weights[weights_counter] = a[x].weights[y];
            weights_counter++;
        }
        free(a[x].weights);
    }
    free(a);
    free(alphabets);
    
    int check;
    char** results = malloc(sizeof(char*)*queries_count);
    for (int x = 0; x < queries_count; x++)
    {   
        check = 1;
        for (int y = 0; y < weights_counter; y++)
        {
            if (queries[x] == weights[y])
            {
                results[x] = "Yes";
                check = 0;
                break;
            }
        }
        if (check)
            results[x] = "No";
    }
    
    *result_count = queries_count;
    free(weights);
    return results;
}


int* get_weights(char c, int count)
{
    int y;
    for (y = 1; y < 27; y++)
        if (c == alphabets[y])
            break;
    int * weights = NULL;
    for (int x = 1; x <= count; x++)
    {
        weights = realloc(weights, sizeof(int)*x);
        weights[x-1] = y*x;
    }
    return weights;
}


char* get_alphabets(void)
{
    char* alpha = malloc(sizeof(char)*28);
    alpha[0] = '+';
    int count = 1;

    for (char c = 'a'; c <= 'z'; c++)
    {
        alpha[count] = c;
        count++;
    }

    alpha[27] = '\0';
    return alpha;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    int queries_count = parse_int(ltrim(rtrim(readline())));

    int* queries = malloc(queries_count * sizeof(int));

    for (int i = 0; i < queries_count; i++) {
        int queries_item = parse_int(ltrim(rtrim(readline())));

        *(queries + i) = queries_item;
    }

    int result_count;
    char** result = weightedUniformStrings(s, queries_count, queries, &result_count);

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

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
