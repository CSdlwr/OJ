#include <stdio.h>
#include <stdlib.h>
#define MAXN 10005

struct cnd {
	int d, c;
}cnds[MAXN];

void swap(cnd* a, cnd* b);
int partition(cnd* a, int p, int r);
void qsort(cnd* a, int p, int r);

int main() {
	int n;
	while (scanf("%d", &n) != 0) {
		if (n == 0) break;
		for (int i = 0; i < n; ++i)
			scanf("%d %d", &cnds[i].d, &cnds[i].c);
		qsort(cnds, 0, n-1);
		int cnt = 1;
		int d = cnds[0].d, c = cnds[0].c;
		for (int i = 1; i < n; ++i) {
			if (cnds[i].d == d && cnds[i].c < c) 
				c = cnds[i].c;
			else if (cnds[i].c < c) {
				++cnt;
				c = cnds[i].c;
				d = cnds[i].d;
			}
		}
		printf("%d\n", cnt);
	}
}

void swap(cnd* a, cnd* b) {
	cnd t = *a;
	*a = *b;
	*b = t;
}

int partition(cnd* a, int p, int r) {
	int i = p - 1;
	int j = p;
	int x = a[r].d;
	while (j < r) {
		if (a[j].d <= x) {
			++i;
			swap(a+i, a+j);
		}
		++j;
	}
	++i;
	swap(a+i, a+r);
	return i;
}

void qsort(cnd* a, int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		qsort(a, p, q-1);
		qsort(a, q+1, r);
	}
}