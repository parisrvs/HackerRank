#include <stdlib.h>
#include <string.h>

int valid_number(char*);

//get a string from the user
char* get_string(char* input) {
    char c, *string = NULL;
    int len = 2;
    printf("%s", input);

    do {
        c = getchar();
        if (c == '\n' && len != 2)
            break;
        string = realloc(string, len*sizeof(char));
        if (!string)
            return NULL;
        *(string + (len - 2)) = c;
        *(string + (len - 1)) = '\0';
        len++;
    } while (c != '\n');

    if (strlen(string) == 1 && *string == '\n') {
        free(string);
        return get_string(input);
    }
    return string;
}


char get_char(char* input)
{
    char* string = NULL;
    while (1)
    {
        string = get_string(input);
        if (strlen(string) == 1)
            break;
        else
            free(string);
    }
    char c = string[0];
    free(string);
    return c;
}


//get an int from the user
int get_int(char* input)
{
    char* string = NULL;
    while (1)
    {
        string = get_string(input);
        if (!valid_number(string))
            free(string);
        else
            break;
    }
    int c = atoi(string);
    free(string);
    return c;
}


//get a long int from the user
long get_long(char* input)
{
    char* string = NULL;
    while (1)
    {
        string = get_string(input);
        if (!valid_number(string))
            free(string);
        else
            break;
    }

    long l = atol(string);
    free(string);
    return l;
}


//get a long long int from the user
long long get_long_long(char* input)
{
    char* string = NULL;
    while (1)
    {
        string = get_string(input);
        if (!valid_number(string))
            free(string);
        else
            break;
    }

    long long ll = atoll(string);
    free(string);
    return ll;
}


// get a floating point number
float get_float(char* input)
{
    char* string = NULL;
    while(1)
    {
        string = get_string(input);
        if (!valid_number(string))
            free(string);
        else
            break;
    }
    double f = atof(string);
    free(string);
    return (float) f;
}


// get a double from the user
double get_double(char* input)
{
    char* string = NULL;
    while(1)
    {
        string = get_string(input);
        if (!valid_number(string))
            free(string);
        else
            break;
    }
    double d = atof(string);
    free(string);
    return d;
}


// validate number
int valid_number(char* string)
{
    int l = strlen(string);
    int index = 0, dot_count = 0;
    if (string[index] == '+' || string[index] == '-')
        index = 1;

    for (; index < l; index++)
        if (string[index] < '0' || string[index] > '9')
        {
            if (string[index] == '.' && dot_count == 0)
                dot_count++;
            else
                return 0;
        }

    return 1;
}


// validate integer
// int valid_number(char* string)
// {
//     int l = strlen(string);
//     int index = 0;
//     if (string[index] == '+' || string[index] == '-')
//         index = 1;

//     for (; index < l; index++)
//         if (string[index] < '0' || string[index] > '9')
//             return 0;

//     return 1;
// }