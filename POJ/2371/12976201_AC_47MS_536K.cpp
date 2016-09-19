#include<iostream>
using namespace std;
int d[100005];
int n, k;

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int a[], int p, int r) {
	int i = p-1;
	int j = p;
	int x = a[r];
	while (j < r) {
		if (a[j] < x) {
			++i;
			swap(a+i, a+j);
		}
		++j;
	}
	++i;
	swap(a+i, a+r);
	return i;
}

void qsort(int a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		qsort(a, p, q-1);
		qsort(a, q+1, r);
	}
}

int main () {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &d[i]);
	qsort(d, 0, n-1);
	char t[4];
	getchar();
	scanf("###", t);
	scanf("%d", &k);
	int kk;
	for (int i = 0; i < k; ++i) {
		scanf("%d", &kk);
		printf("%d\n", d[kk-1]);
	}
	return 0;
}