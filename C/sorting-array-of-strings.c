#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* copy_string(char* string) {
    int l = strlen(string);
    char* s = malloc(sizeof(char)*(l+1));
    for (int c = 0; c <= l; c++)
        s[c] = string[c];
    return s;
}

int lexicographic_sort(const char* a, const char* b) {
    int c = 0;
    while (a[c]== b[c])
        c++;
    
    if (!a[c] || !b[c]) {
        if (strlen(a) <= strlen(b))
            return 1;
        else
            return 0;
    }
        
    
    if (a[c] < b[c])
        return 1;
    else
        return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int c = 0;
    while (a[c]== b[c])
        c++;
    
    if (!a[c] || !b[c]) {
        if (strlen(a) >= strlen(b))
            return 1;
        else
            return 0;
    }
        
    
    if (a[c] > b[c])
        return 1;
    else
        return 0;
}


char* string_array_to_set(const char* string) {
    int arr[26] = {0};
    int index, x = 2;
    char* s = NULL;
    for (int c = 0, l = strlen(string); c < l; c++) {
        index = string[c] - 97;
        if ((++arr[index]) == 1) {
            s = realloc(s, sizeof(char)*x);
            s[x-2] = string[c];
            s[x-1] = '\0';
            x++;
        }
    }

    return s;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    char* temp_a = string_array_to_set(a);
    char* temp_b = string_array_to_set(b);

    int sort_by_length(const char*, const char*);
    int c;
    if (strlen(temp_a) == strlen(temp_b))
        c = lexicographic_sort(a, b);
    else
        c = sort_by_length(temp_a, temp_b);
    
    free(temp_a);
    free(temp_b);

    return c;
}

int sort_by_length(const char* a, const char* b) {
    int l_a = strlen(a), l_b = strlen(b);
    if (l_a == l_b)
        return lexicographic_sort(a, b);
    else if (l_a > l_b)
        return 0;
    else
        return 1;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){

    
    for (int c = 0; c < len-1; c++) {
        for (int d = c + 1; d < len; d++) {
            if (cmp_func(arr[c], arr[d]) == 0) {
                char* temp_c = copy_string(arr[c]);
                char* temp_d = copy_string(arr[d]);
                free(arr[c]);
                free(arr[d]);
                arr[c] = temp_d;
                arr[d] = temp_c;
            }
        }
    }
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


    for(int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}