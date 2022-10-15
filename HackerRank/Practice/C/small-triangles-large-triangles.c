#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

float area(triangle t)
{
    float p = ((t.a)+(t.b)+(t.c))/(float)2;
    return p*(p-t.a)*(p-t.b)*(p-t.c);
}


void sort_by_area(triangle* tr, int n) {
    triangle temp;
    for (int c=0; c<n; c++)
        for (int d=c+1; d<n; d++)
            if (area(tr[c]) > area(tr[d]))
            {
                temp = tr[c];
                tr[c] = tr[d];
                tr[d] = temp;
            }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}