#include <iostream>
using namespace std;

struct edge {
	int v1, v2, c;
}eds[15005];
int gmax(int a, int b);
int find(int i);
bool unionSet(int a, int b);
void swap(edge* a, edge* b);
int partition(edge a[], int p, int r);
void qsort(edge a[], int p, int r);
int r[1005];
int f[1005];
int cnt = 0, mc = -1;
int n, m;
int main() {
	scanf("%d %d", &n, &m);
	int v1, v2, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &v1, &v2, &c);
		eds[i].v1 = v1;
		eds[i].v2 = v2;
		eds[i].c = c;
	}
	qsort(eds, 0, m-1);
	for (int i = 1; i <= n; ++i) {
		f[i] = i;
		r[i] = 1;
	}
	edge ans[15005];
	for (int i = 0; i < m; ++i) {
		if (unionSet(eds[i].v1, eds[i].v2)) {
			ans[cnt].v1 = eds[i].v1;
			ans[cnt++].v2 = eds[i].v2;
			mc = gmax(mc, eds[i].c);
		}
	}
	printf("%d\n%d\n", mc, cnt);
	for (int i = 0; i < cnt; ++i)
		printf("%d %d\n", ans[i].v1, ans[i].v2);
	return 0;
}

int gmax(int a, int b) {
	return a > b ? a : b;
}

int find(int i) {
	if (i == f[i]) return i;
	return f[i] = find(f[i]);
}

bool unionSet(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	if (fa == fb) return false;
	if (r[fa] >= r[fb]) {
		f[fb] = fa;
		r[fa] += r[fb];
	} else {
		f[fa] = fb;
		r[fb] += r[fa];
	}
	return true;
}

void swap(edge* a, edge* b) {
	edge t = *a;
	*a = *b;
	*b = t;
}

int partition(edge a[], int p, int r) {
	int i = p - 1;
	int j = p;
	int x = a[r].c;
	while (j < r) {
		if (a[j].c < x) {
			++i;
			swap(a+i, a+j);
		}
		++j;
	}
	++i;
	swap(a+i, a+r);
	return i;
}

void qsort(edge a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		qsort(a, p, q-1);
		qsort(a, q+1, r);
	}
}