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

char* change_time(char*, int* h, int* m, int* s);

char** split_string(char* string, char c, int* size) {
    int l = 2, l_string = strlen(string), count = 0;

    char** strings = NULL;

    for (int x = 0; x < l_string; x++)
    {   
        if (string[x] == c) {
            while(string[x+1] && string[x+1] == c)
                x++;
            if (string[x+1] && x < l_string) {
                count++;
                strings = (char**) realloc(strings, sizeof(char*)*count);
                strings[count-1] = NULL;
                l = 2;
            } else {
                break;
            }

        } else {
            if (!count) {
                strings = (char**) malloc(sizeof(char*)*(count+1));
                strings[count] = NULL;
                count++;
            }
            strings[count-1] = (char*) realloc(strings[count-1], sizeof(char)*l);
            strings[count-1][l-2] = string[x];
            strings[count-1][l-1] = '\0';
            l++;
        }
    }

    *size = count;
    return strings;
}


char* timeConversion(char* s) {

    int hours, minutes, seconds;
    char*t = change_time(s, &hours, &minutes, &seconds);
    
    if ((strcmp(t, "AM") == 0) && (hours == 12))
        hours = 0;
    else if ((strcmp(t, "PM") == 0) && (hours >= 1 && hours <= 11))
        hours += 12;
    
    char* result = (char*) malloc(sizeof(char*)*9);
    sprintf(result, "%.2i:%.2i:%.2i\n", hours, minutes, seconds);
    free(t);
    return result;
}

char* change_time(char* s, int *h, int* m, int* sec) {
    int count;
    char** time = split_string(s, ':', &count);

    char* t = (char*) malloc(sizeof(char)*3);
    *h = atoi(time[0]);
    *m = atoi(time[1]);
    t[0] = time[2][0];
    t[1] = time[2][1];
    t[2] = '\0';
    *sec = atoi(t);

    t[0] = time[2][2];
    t[1] = time[2][3];

    for (int c = 0; c < count; c++)
        free(time[c]);
    free(time);
    return t;
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
