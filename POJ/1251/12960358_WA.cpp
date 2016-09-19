#include <iostream>
using namespace std;

struct edge {
	int v1, v2, c;
}eds[80];
int find(int i);
bool unionSet(int a, int b);
void swap(edge* e1, edge* e2);
int partition(edge a[], int p, int r);
void qsort(edge a[], int p, int r);
int f[80];
int r[80];
int n;
int main() {
	while (scanf("%d", &n)) {
		if (n == 0) break;
		int c, cnt = 0;
		char s, e;
		int nn;
		for (int i = 0; i < n-1; ++i) {
			scanf("\n%c %d", &s, &nn);
			for (int j = 0; j < nn; ++j) {
				scanf(" %c %d", &e, &c);
				eds[cnt].v1 = i; 
				eds[cnt].v2 = e-'A';
				eds[cnt++].c = c;
				eds[cnt].v1 = e-'A';
				eds[cnt].v2 = i;
				eds[cnt++].c = c;
			}
		}
		qsort(eds, 0, cnt-1);
		for (int i = 0; i < n; ++i) {
			r[i] = 1;
			f[i] = i;
		}
		int sum = 0;
		for (int i = 0; i < cnt; ++i) {
			if (unionSet(eds[i].v1, eds[i].v2)) 
				sum += eds[i].c;
		}
		printf("%d\n", sum);
	}
	return 0;
}

int find(int i) {
	if (f[i] == i) return i;
	return find(f[i]);
}

bool unionSet(int a, int b) {
	int aa = find(a);
	int bb = find(b);
	if (aa == bb) 
		return false;
	if (r[aa] >= r[bb]) {
		f[bb] = aa;
		r[aa] += r[bb];
	} else {
		f[aa] = bb;
		r[bb] += r[aa];
	}
	return true;
}

void swap(edge* e1, edge* e2) {
	edge t = *e1;
	*e1 = *e2;
	*e2 = t;
}

int partition(edge a[], int p, int r) {
	int i = p - 1;
	int j = p;
	int x = a[r].c;
	while (j < r) {
		if(a[j].c < x) {
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