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

int get_digits(int);
char* ltos(long);
char** divide_string(char*, int);
void array_sort(int *arr, int arr_count);


void kaprekarNumbers(int p, int q)
{
    int* list = NULL;
    char* s = NULL, **news = NULL;
    int l, rightlength, list_count = 1;
    long n;
    for (int c = p; c <= q; c++)
    {
        rightlength = get_digits(c);
        n = (long)c * (long)c;
        s = ltos(n);
        news = divide_string(s, rightlength);

        long l1 = atol(news[0]);
        long l2 = atol(news[1]);

        if (l1 + l2 == c)
        {
            list = realloc(list, sizeof(int)*list_count);
            list[list_count-1] = c;
            list_count++;
        }

        for (int d=0; d<2; d++)
            free(news[d]);
        free(news);
        free(s);
    }
    if (list == NULL)
    {
        printf("INVALID RANGE\n");
        return;
    }
    
    list_count--;
    array_sort(list, list_count);
    for (int x=0; x<list_count; x++)
    {
        if (x == list_count-1)
            printf("%i\n", list[x]);
        else
            printf("%i ", list[x]);
    }   
    free(list);
}


char** divide_string(char* s, int r)
{
    int l = strlen(s), c, counter = 0, sizeleft = l-r;
    char** news = malloc(sizeof(char*)*2);
    news[0] = malloc(sizeof(char)*(sizeleft+1));
    news[1] = malloc(sizeof(char)*(r+1));

    for (c=0; c<sizeleft; c++)
        news[0][c] = s[c];
    news[0][c] = '\0';

    if (sizeleft == r)
        c = r;
    else
        c = r-1;

    for (; c<l; c++)
    {
        news[1][counter] = s[c];
        counter++;
    }
    news[1][counter] = '\0';
    return news;
}


int get_digits(int c)
{
    int digits = 0;
    while(c)
    {
        c = c/10;
        digits++;
    }
        
    return digits;
}


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

char* ltos(long s)
{
    char* string = NULL;
    if (s == 0)
    {
        string = malloc(sizeof(char)*2);
        string[0] = '0';
        string[1] = '\0';
        return string;
    }
    
    long multiple = 10, counter = 0;
    long temp;
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
        }
        s = s / multiple;
    }

    if (strlen(string) > 1)
        return reverse_string(string);
    else
        return string;
}


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


int main()
{
    int p = parse_int(ltrim(rtrim(readline())));

    int q = parse_int(ltrim(rtrim(readline())));

    kaprekarNumbers(p, q);

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
