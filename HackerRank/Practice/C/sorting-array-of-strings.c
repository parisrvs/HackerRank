#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number_of_distinct_characters(const char*);

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int d1 = number_of_distinct_characters(a);
    int d2 = number_of_distinct_characters(b);

    if ((d1 - d2) == 0)
        return strcmp(a, b);
    else
        return (d1 - d2);
}

int sort_by_length(const char* a, const char* b) {
    int c = strlen(a) - strlen(b);
    if (c == 0)
        return strcmp(a, b);
    else
        return c;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char* temp = NULL;
    int swaps = 0;
    for (int c = 0; c < len ; c++)
    {
        for (int d = c + 1; d < len; d++)
        {
            if (cmp_func(arr[c], arr[d]) > 0)
            {
                temp = arr[c];
                arr[c] = arr[d];
                arr[d] = temp;
            }
        }
    }
}

int number_of_distinct_characters(const char* a)
{
    int* alpha = malloc(sizeof(int)*26);
    for (int c=0; c<26; c++)
        alpha[c] = 0;
    
    int count;
    for (int c=0, l=strlen(a); c<l; c++)
    {
        count = a[c] - 'a';
        alpha[count]++;
    }

    int dist = 0;
    for (int c=0; c<26; c++)
        if (alpha[c] > 0)
            dist++;
    
    free(alpha);
    return dist;
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}