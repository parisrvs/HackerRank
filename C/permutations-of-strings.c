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
    
    int end = n - 1;
    for (int start = k + 1; start < end; start++) {
        swap(s, start, end);
        end--;
    }
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


/*
8
dvet
lwi
m
pqdp
r
r
wtc
y
*/