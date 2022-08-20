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
double area(triangle tr);

void sort_by_area(triangle* tr, int n) {
    for (int x = 0; x < n-1; x++)
        for (int y = x+1; y < n; y++) {
            if (area(tr[x]) > area(tr[y])) {
                int temp_a = tr[x].a;
                int temp_b = tr[x].b;
                int temp_c = tr[x].c;
                tr[x].a = tr[y].a;
                tr[x].b = tr[y].b;
                tr[x].c = tr[y].c;
                tr[y].a = temp_a;
                tr[y].b = temp_b;
                tr[y].c = temp_c;
            }
        }
}


double area(triangle tr) {
    double p = (tr.a + tr.b + tr.c) / (double) 2;
    double temp = (double) (p * (p - tr.a) * (p - tr.b) * (p - tr.c));
    double area = sqrt(temp);
    return area;
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
    printf("-----------------\n");
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}