#include <stdlib.h>
#include <stdio.h>
#include <string.h>


long long fibinacci(int number) {
    long long int* arr = (long long int*) malloc(sizeof(long long int)*number);
    *(arr+0) = 0;
    *(arr+1) = 1;

    for (int c=2; c<number; c++)
        *(arr+c) = *(arr+(c-1)) + *(arr+(c-2));

    long long n = *(arr+(--number));
    free(arr);
    return n;
}


// For integers, a and b, their gratest common divisor or gcd(a,b) is the largest integer d, so that d divides both a and b.
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;

    return gcd(b, (a % b));
}


int* int_array_pop(int* arr, int* size, int index) {
    int c = 0, d = 0, l = *size;
    int* arr_copy = (int*) malloc(sizeof(int)*(*size));

    for (; c < (*size); c++) {
        if (index == c) {
            arr_copy = (int*) realloc(arr_copy, sizeof(int)*((*size) - 1));
            l--;
        } else {
            *(arr_copy+d) = *(arr+c);
            d++;
        }
    }

    free(arr);
    *size = l;
    return arr_copy;
}


int* int_array_append(int* arr, int* size, int item) {
    int l = *size;
    arr = (int*) realloc(arr, sizeof(int)*(l+1));
    *(arr+l) = item;
    *size = l + 1;
    return arr;
}


int* int_array_remove(int* arr, int* size, int item) {
    int c = 0, d = 0, l = *size;
    int* arr_copy = (int*) malloc(sizeof(int)*(*size));

    for (; c < (*size); c++) {
        if (item == *(arr+c)) {
            arr_copy = (int*) realloc(arr_copy, sizeof(int)*((*size) - 1));
            l--;
        } else {
            *(arr_copy+d) = *(arr+c);
            d++;
        }
    }

    free(arr);
    *size = l;
    return arr_copy;
}


void int_array_print(int* arr, int size) {
    if (!size) {
        printf("[]\n");
        return;
    }

    printf("[");
    for(int c=0; c<size; c++)
        if (c == size - 1)
            printf("%i]\n", *(arr+c));
        else
            printf("%i, ", *(arr+c));
    return;
}


int int_array_max(int* array, int size) {
    if (!size)
        return 0;
    int max = *array;
    for (int c = 1; c < size; c++)
        if (max < *(array+c))
            max = *(array+c);

    return max;
}


void int_array_bubble_sort(int* array, int size) {
    int temp;
    for (int c = 0; c < size-1; c++)
        for (int d = c+1; d < size; d++)
            if ( *(array+c) > *(array+d) ) {
                temp = *(array+c);
                *(array+c) = *(array+d);
                *(array+d) = temp;
            }
}


// continuation of int_array_binary_search(int* array, int size, int item)
// int binary_search(int* array, int low, int high, int item_to_search)
// returns -1 if the item is not found, else returns the index of the item [0 indexed]
int binary_search(int* array, int low, int high, int item) {
    if (high < low)
        return -1;

    int mid = (high + low) / 2;
    if (item == *(array+mid))
        return mid;
    else if (item > *(array+mid))
        return binary_search(array, mid+1, high, item);
    else
        return binary_search(array, low, mid-1, item);
}


// int_array_binary_search(int* array, int size_of_array, int item_to_search)
int int_array_binary_search(int* array, int size, int item) {
    return binary_search(array, 0, size-1, item);
}



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


int isLeapYear(int year) {
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return 1;
    return 0;
}