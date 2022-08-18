#include "myalgo.c"


long long fibinacci(int);
long long gcd(long long, long long);


// int* array, int size_of_array
void int_array_print(int*, int);

// int* array, int* size_of_array, int item_to_remove
int* int_array_remove(int*, int*, int);

// int* array, int* size_of_array, int index_of_item_to_pop
int* int_array_pop(int*, int*, int);

// int* array, int* size_of_array, int item_to_append
int* int_array_append(int* arr, int* size, int item);

// int* array, int size_of_array
int int_array_max(int*, int);

// int* array, int size_of_array
void int_array_bubble_sort(int*, int);

// part of - int_array_binary_search
// int* array, int low, int high, int item_to_search
int binary_search(int*, int, int, int);

// int* array, int size_of_array, int item_to_search
int int_array_binary_search(int*, int, int);