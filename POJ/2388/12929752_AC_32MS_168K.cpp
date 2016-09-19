#include<iostream>
using namespace std;
#define MAXN 10005

void qsort(int* a, int p, int r);
int partition(int* a, int p, int r);
void swap(int* a, int* b);

int main() {
	int n;
	int inp[MAXN];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &inp[i]);
	qsort(inp, 0, n-1);
	printf("%d\n", inp[n/2]);
// 
// 	for (int i = 0; i < n; ++i)
// 		printf("%d ", inp[i]);
	return 0;
}

void qsort(int* a, int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		qsort(a, p, q-1);
		qsort(a, q+1, r);
	}
}

int partition(int* a, int p, int r) {
	int i = p-1;
	int j = p;
	int x = a[r];
	for (; j < r; ++j) {
		if (a[j] <= x) {
			++i;
			swap(a+i, a+j);
		}
	}
	swap(a[r], a[++i]);
	return i;
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}