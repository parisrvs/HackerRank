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
 * Complete the 'isValid' function below.
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
void array_sort(int *arr, int arr_count)
{
    int temp;
    for (int c=0; c<arr_count; c++)
        for (int d=c+1; d<arr_count; d++)
            if (arr[c] > arr[d])
            {
                temp = arr[c];
                arr[c] = arr[d];
                arr[d] = temp;
            }
}


char* isValid(char* s)
{
    int a[26] = {0}, l = strlen(s);
    for (int c = 0; c < l; c++)
    {
        int i = (int) (s[c] - 'a');
        a[i]++;
    }

    int count = 0, *arr = NULL;
    for (int c = 0; c < 25; c++)
    {
        if (a[c])
        {
            arr = realloc(arr, sizeof(int)*(count+1));
            arr[count] = a[c];
            count++;
        }
    }
    if (count == 1)
    {
        free(arr);
        return "YES";
    }
    
    array_sort(arr, count);
    int start = 0, end = count;
    if (arr[0] != arr[1])
    {
        if (arr[0] == 1)
            start = 1;
        else
        {
            free(arr);
            return "NO";
        }
    }
    else if (arr[count-1] != arr[count-2])
    {
        arr[count - 1]--;
        if (arr[count-1] != arr[count-2])
        {
            free(arr);
            return "NO";
        }
        else
            end = count - 1;
    }
    
    for (int c = start; c < (end - 1); c++)
    {
        if (arr[c] != arr[c+1])
        {
            free(arr);
            return "NO";
        }
    }
    free(arr);
    return "YES";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = isValid(s);

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
