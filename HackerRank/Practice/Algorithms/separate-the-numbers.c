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
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */
char* split(char*, int, int);
char* append(char*, char*);
char* reverse_string(char*);
char* lltos(long long);

void separateNumbers(char* s)
{
    int seq = 0, l = strlen(s), characters, c;
    char* string = NULL, *string1 = NULL;
    long long num1, num2;
    for (c = 0; c < l/2; c++)
    {
        string = split(s, 0, c+1);
        num1 = strtoll(string, NULL, 10);
        num2 = strtoll(string, NULL, 10);
        while (strlen(string) < l)
        {
            num2++;
            string1 = lltos(num2);
            string = append(string, string1);
        }
        if (strcmp(string, s) == 0)
        {
            seq = 1;
            free(string);
            break;
        }
        free(string);
    }
    if (seq)
        printf("YES %lli\n", num1);
    else
        printf("NO\n");
    return;
}

char* split(char* s, int start, int end)
{
    int l = strlen(s);
    if (start < 0)
        start = 0;
    if (end > l)
        end = l;
    
    char* string = NULL;
    int counter = 0;
    for (int c = start; c < end; c++)
    {
        string = realloc(string, sizeof(char)*(counter+2));
        string[counter] = s[c];
        string[counter+1] = '\0';
        counter++;
    }
    return string;
}


char* append(char* string1, char* string2)
{
    char* string = NULL;
    int counter = 0;
    for (int c = 0; string1[c] != '\0'; c++)
    {
        string = realloc(string, sizeof(char)*(counter+2));
        string[counter] = string1[c];
        string[counter+1] = '\0';
        counter++;
    }

    for (int c = 0; string2[c] != '\0'; c++)
    {
        string = realloc(string, sizeof(char)*(counter+2));
        string[counter] = string2[c];
        string[counter+1] = '\0';
        counter++;
    }

    free(string1);
    free(string2);
    return string;
}

char* lltos(long long s)
{
    char* string = NULL;
    if (s == 0)
    {
        string = malloc(sizeof(char)*2);
        string[0] = '0';
        string[1] = '\0';
        return string;
    }
    
    long long multiple = 10, counter = 0;
    long long temp;
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

int main()
{
    int q = parse_int(ltrim(rtrim(readline())));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        char* s = readline();

        separateNumbers(s);
    }

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
