#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


char** split_string(char*, char, int*);

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);

    int size;
    char** strings = split_string(s, ' ', &size);
    for (int x = 0; x < size; x++)
        printf("%s\n", strings[x]);
    //Write your logic to print the tokens of the sentence here.

    for (int x = 0; x < size; x++)
        free(strings[x]);
    free(strings);
    free(s);
    return 0;
}


// char** split_string(char* string, char c, int* size) {
//     int found = 0, new = 1;
//     for (int x = 0, l = strlen(string); x < l; x++) {
//         if (string[x] == c) {
//             while(string[x] && string[x] == c)
//                 x++;
            
//             if (x < l) {

//             }
                
            

//         }
            
//     }
// }

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
            strings[count-1] = realloc(strings[count-1], sizeof(char)*l);
            strings[count-1][l-2] = string[x];
            strings[count-1][l-1] = '\0';
            l++;
        }
    }

    *size = count;
    return strings;
}