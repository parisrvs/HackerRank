#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);


    int l = strlen(s), counter = 2;
    char* word = NULL;

    for (int c=0; c<=l; c++)
    {
        if ((s[c] == ' ' || s[c] == '\0') && word != NULL)
        {
            printf("%s\n", word);
            free(word);
            word = NULL;
            counter = 2;
        }
        else
        {
            word = realloc(word, sizeof(char)*counter);
            word[counter-2] = s[c];
            word[counter-1] = '\0';
            counter++;
        }
    }

    free(s);
    return 0;
}