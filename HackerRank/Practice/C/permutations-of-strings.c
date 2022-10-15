#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order


int SORTING = 0;

void sort_string(char** arr , int len);
int largest_index_k(char** s, int n);
int largest_index_l(char** s, int size, int k);
void swap(char** s, int size, int k, int l);
void reverse_sequence(char**s, int size, int k, int l);



int next_permutation(int n, char **s)
{
    if (SORTING == 0)
    {
        sort_string(s, n);
        SORTING++;
    }
        
    int k = largest_index_k(s, n);
    if (k < 0)
        return 0;

    int l = largest_index_l(s, n, k);

    swap(s, n, k, l);
    reverse_sequence(s, n, k, l);
    return 1;
}


void sort_string(char** arr , int len)
{
    char* temp = NULL;
    int swaps = 0;
    for (int c = 0; c < len ; c++)
    {
        for (int d = c + 1; d < len; d++)
        {
            if (strcmp(arr[c], arr[d]) > 0)
            {
                temp = arr[c];
                arr[c] = arr[d];
                arr[d] = temp;
            }
        }
    }
}


void reverse_sequence(char**s, int size, int k, int l)
{
    k = k + 1;
    if (k == size-1)
        return;
    
    char* temp;
    for (int c = size-1; c >= k; c--)
    {
        if (k >= c)
            break;
        temp = s[c];
        s[c] = s[k];
        s[k] = temp;
        k++;
    }
    return;
}


void swap(char** s, int size, int k, int l)
{
    char* temp = s[k];
    s[k] = s[l];
    s[l] = temp;
}


int largest_index_k(char** s, int n)
{
    int lindex = -1;

    for (int c=1; c<n; c++)
        if (strcmp(s[c-1], s[c]) < 0)
            if (c > lindex)
                lindex = c;
    
    lindex--;
    return lindex;
}


int largest_index_l(char** s, int size, int k)
{
    int lindex = -1;
    for (int c=0; c<size; c++)
        if (strcmp(s[k], s[c]) < 0)
            if (c > k)
                if (c > lindex)
                    lindex = c;
    
    return lindex;
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