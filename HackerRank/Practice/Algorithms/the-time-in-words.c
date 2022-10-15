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

char* time[] = {
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "quarter",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
    "twenty",
    "twenty one",
    "twenty two",
    "twenty three",
    "twenty four",
    "twenty five",
    "twenty six",
    "twenty senen",
    "twenty eight",
    "twenty nine",
    "half past"
};




char* timeInWords(int h, int m)
{
    char* string = malloc(sizeof(char)*1000);
    string[0] = '\0';
    if (m <= 30)
    {
        if (m == 0)
        {
            string = strcat(string, time[h]);
            string = strcat(string, " o' clock");
        }
        else if (m == 1)
        {
            string = strcat(string, time[m]);
            string = strcat(string, " minute past ");
            string = strcat(string, time[h]);
        }
        else if (m == 15)
        {
            string = strcat(string, "quarter past ");
            string = strcat(string, time[h]);
        }
        else if (m == 30)
        {
            string = strcat(string, "half past ");
            string = strcat(string, time[h]);
        }   
        else
        {
            string = strcat(string, time[m]);
            string = strcat(string, " minutes past ");
            string = strcat(string, time[h]);
        }
    }
    else
    {
        m = 60 - m;
        h++;
        if (h == 13)
            h = 1;
        
        if (m == 1)
        {
            string = strcat(string, time[m]);
            string = strcat(string, " minute to ");
            string = strcat(string, time[h]);
        }
        else if (m == 15)
        {
            string = strcat(string, "quarter to ");
            string = strcat(string, time[h]);
        }
        else
        {
            string = strcat(string, time[m]);
            string = strcat(string, " minutes to ");
            string = strcat(string, time[h]);
        }
    }
    int l = strlen(string);
    string = realloc(string, sizeof(char)*(l+1));
    return string;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int h = parse_int(ltrim(rtrim(readline())));

    int m = parse_int(ltrim(rtrim(readline())));

    char* result = timeInWords(h, m);

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
