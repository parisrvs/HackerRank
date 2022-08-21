#include <stdio.h>
#include "/home/paris/Codes/HackerRank/clibs/myio.h"
#include "/home/paris/Codes/HackerRank/clibs/myalgo.h"


char* change_time(char*, int* h, int* m, int* s);
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


int main(void) {
    char* time = get_string("String: ");
    char* result = timeConversion(time);
    printf("%s\n", result);
    free(time);
    free(result);
    return 0;
}