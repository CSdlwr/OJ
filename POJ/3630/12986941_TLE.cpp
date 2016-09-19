#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;

int t, n;
char* ph[10001];

int partition(char* a[], int p, int r) {
	char* t;
	int j = p;
	int i = p-1;
	int x = strlen(a[r]);
	while (j < r) {
		if (strlen(a[j]) < x) {
			++i;
			t = a[j];
			a[j] = a[i];
			a[i] = t;
		}
		++j;
	}
	++i;
	t = a[i];
	a[i] = a[r];
	a[r] = t;
	return i;
}

void qsort(char* a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		qsort(a, p, q-1);
		qsort(a, q+1, r);
	}
}

int main() {
	bool fg;
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			ph[i] = (char*)malloc(11);
			scanf("%s", ph[i]);
		}
		qsort(ph, 0, n-1);
		fg = false;
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				fg = false;
				for (int k = 0; ph[i][k] != '\0'; ++k)
					if (ph[i][k] != ph[j][k]) {fg = true; break;}
				if (!fg) break;
			}
			if (!fg) break;
		}
		if (!fg) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}