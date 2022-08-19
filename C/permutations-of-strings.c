#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int largest_k(int, char**);
int largest_l(int, char**, int);
void swap(char**, int, int);
void reverse(char**, int, int);


int next_permutation(int n, char **s)
{
    int k = largest_k(n, s);
    if (k < 0)
        return 0;
    
    int l = largest_l(n, s, k);
    swap(s, k, l);
    reverse(s, n, k);
    return 1;
}



int largest_k(int size, char** strings) {
    int k = size - 1;
    while ((k > 0) && (strcmp(strings[k-1], strings[k]) >= 0))
        k--;
    return k-1;
}


int largest_l(int n, char** s, int k) {
    int l = k + 1;
    while ((l < n) && (strcmp(s[k], s[l]) <= 0))
        l++;
    return l - 1;
}


void swap(char** s, int k, int l) {
    char* temp = s[k];
    s[k] = s[l];
    s[l] = temp;
}


void reverse(char** s, int n, int k) {
    if ((k + 1) == (n - 1))
        return;
    
    k++;
    int count = 0, l;
    char** strings = (char**) malloc(sizeof(char*)*(n-k));
    for (int c = k; c < n; c++) {
        l = strlen(s[c]);
        strings[count] = (char*) malloc(sizeof(char)*(l+1));
        for (int x = 0; x <= l; x++)
            strings[count][x] = s[c][x];
        count++;
    }
	
    for (int x = k; x < n; x++) {
        free(s[x]);
        s[x] = strings[--count];
    }
    free(strings);
}


int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}