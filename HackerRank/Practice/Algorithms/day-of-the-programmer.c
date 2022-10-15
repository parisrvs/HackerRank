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
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
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

char* reverse_string(char* s)
{
    int l = strlen(s), counter = 0;
    char* news = malloc(sizeof(char)*(l+1));
    for (int c=l-1; c>=0; c--)
    {
        news[counter] = s[c];
        counter++;
    }
    news[l] = '\0';
    free(s);
    return news;
}



char* itos(int s)
{
    char* string = NULL;
    if (s == 0)
    {
        string = malloc(sizeof(char)*2);
        string[0] = '0';
        string[1] = '\0';
        return string;
    }
    
    int multiple = 10, counter = 0, temp;
    while(s)
    {
        temp = (s % multiple);
        if (temp == s && counter == 0)
        {
            string = malloc(sizeof(char)*2);
            string[0] = (char) (temp + 48);
            string[1] = '\0';
            return string;
        }
        else
        {
            string = realloc(string, sizeof(char)*(counter+2));
            string[counter] = (char) (temp + 48);
            string[counter+1] = '\0';
            counter++;
            //printf("%c", (char) (temp + 48));
        }
        s = s / multiple;
        
    }

    if (strlen(string) > 1)
        return reverse_string(string);
    else
        return string;
}


char* append_to_string(char* original, char* new)
{
    // Memory allocated for the new string on the heap using malloc.
    // No memory freed in this process.
    int l1 = strlen(original);
    int l2 = strlen(new);
    int newl = l1+l2;

    char* string = malloc(sizeof(char)*(newl+1));

    int c;
    for (c=0; c<l1; c++)
        string[c] = original[c];
    
    int d=0;
    for (; c<newl; c++)
    {
        string[c] = new[d];
        d++;
    }
    
    string[newl] = '\0';
    return string;
}


char* dayOfProgrammer(int year)
{
    char* yr = itos(year);
    if (year == 1918)
        return "26.09.1918";
    else if (((year <= 1917) && (year%4 == 0)) || ((year > 1918) && (year%400 == 0 || ((year%4 == 0) && (year%100 != 0)))))
    {
        char* y1 = "12.09.";
        char* y = append_to_string(y1, yr);
        free(yr);
        return y;
    }
    else
    {
        char* y1 = "13.09.";
        char* y = append_to_string(y1, yr);
        free(yr);
        return y;
    }
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int year = parse_int(ltrim(rtrim(readline())));

    char* result = dayOfProgrammer(year);

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

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
