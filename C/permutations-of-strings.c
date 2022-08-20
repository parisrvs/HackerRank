#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char**, int, int);
void reverse(char**, int, int);

int next_permutation(int n, char **s)
{
    for (int x = n - 2; x >= 0; x--)
        if (strcmp(s[x+1], s[x]) > 0)
            for (int y = n - 1; y > x; y--)
                if (strcmp(s[y], s[x]) > 0) {
                    swap(s, x, y);
                    reverse(s, n, x);
                    return 1;
                }
    return 0;
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