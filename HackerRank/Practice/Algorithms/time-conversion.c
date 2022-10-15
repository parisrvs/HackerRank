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
 * Complete the 'timeConversion' function below.
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
char* timeConversion(char* s) {
    int l = strlen(s);
    char* time = malloc(sizeof(char)*(l-1));
    for (int c = 0; c < l-2; c++)
        if (c > 1)
            time[c] = s[c];
        else
            time[c] = '0';
    
    time[l-2] = '\0';

    int l1 = strlen(time);

    char format = 'P';
    if (s[l-2] == 'A')
        format = 'A';

    if (s[0] == '1' && s[1] == '2' && format == 'P')
    {
        *time = '1';
        *(time+1) = '2';
        return time;
    }
    else if (s[0] == '1' && s[1] == '2' && format == 'A')
    {
        return time;
    }

    if (format == 'P')
    {
        char* hour = malloc(sizeof(char)*3);
        if (hour == NULL)
            return NULL;
        hour[0] = s[0];
        hour[1] = s[1];
        hour[2] = '\0';
        
        int h = atoi(hour);
        h = h + 12;
        free(hour);

        int length = snprintf(NULL, 0, "%i", h);
        char* str = malloc(sizeof(char)*(length + 1));
        snprintf(str, length+1, "%i", h);
        
        *time = str[0];
        *(time+1) = str[1];
        free(str);
    }
    else
    {
        time[0] = s[0];
        time[1] = s[1];
    }
    return time;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

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
