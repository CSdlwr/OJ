#include <iostream>
using namespace std;
struct e {
	int v1, v2, c;
}es[20005];
int findf(int i);
bool unionSet(int a, int b);
void swap(e* a, e* b);
bool unionSet(int a, int b);
void swap(e* a, e* b);
int partition(e a[], int p, int r);
void qsort(e a[], int p, int r);
int r[1005], f[1005];
int n, m, cnt;
int main() {
	scanf("%d %d", &n, &m);
	int v1, v2, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &v1, &v2, &c);
		es[i].v1 = v1;
		es[i].v2 = v2;
		es[i].c = c;
	}
	qsort(es, 0, m-1);
	for (int i = 1; i <= n; ++i) {
		r[i] = 1;
		f[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < m; ++i) 
		if (unionSet(es[i].v1, es[i].v2)) 
			sum += es[i].c;
	if (cnt != n) printf("-1\n");
	else printf("%d\n", sum);
	return 0;
}

int findf(int i) {
	if (i == f[i]) return i;
	return f[i] = findf(f[i]);
}

bool unionSet(int a, int b) {
	int fa = findf(a);
	int fb = findf(b);
	if (fa == fb) return false;
	if(r[fa] >= r[fb]) {
		f[fb] = fa;
		r[fa] += r[fb];
	} else {
		f[fa] = fb;
		r[fb] += r[fa];
	}
	cnt = r[fa] > r[fb] ? r[fa] : r[fb];
	return true;
}

void swap(e* a, e* b) {
	e t = *a;
	*a = *b;
	*b = t;
}

int partition(e a[], int p, int r) {
	int i = p - 1;
	int j = p;
	int x = a[r].c;
	while (j < r) {
		if (a[j].c > x) {
			++i;
			swap(a+i, a+j);
		}
		++j;
	}
	++i;
	swap(a+i, a+r);
	return i;
}

void qsort(e a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		qsort(a, p, q-1);
		qsort(a, q+1, r);
	}
}