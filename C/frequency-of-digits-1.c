#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


char* get_string() {
    char c, *string = NULL;
    int len = 2;

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
        return get_string();
    }
    return string;
}

int main() {
    int arr[10] = {0}, digit;

    char* string = get_string();
    for (int c = 0, l = strlen(string); c < l; c++) {
        if (string[c] >= '0' && string[c] <= '9') {
            digit = string[c] - 48;
            arr[digit]++;
        }
    }

    for (int c = 0; c < 10; c++)
        printf("%i ", arr[c]);
    
    printf("\n");
    free(string);
    return 0;
}
