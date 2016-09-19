#include<malloc.h>
#include<iostream>
using namespace std;

int f[30001];
int r[30001];
int n, m;
int nn, n1, n2;

int find(int x) {
	if (x != f[x]) 
	return f[x] = find(f[x]);
}
void us(int a, int b) {
	int aa = find(a);
	int bb = find(b);
	if (aa != bb) {
		if (r[aa] > r[bb]) {
			f[bb] = aa;
			r[aa] += r[bb];
		} else {
			f[aa] = bb;
			r[bb] += r[aa];
		}
	}
}
int main() {
	while (scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0) break;
		if (m == 0) {
			printf("1\n");
			continue;
		}
		for  (int i = 0; i < n; ++i) {
			f[i] = i;
			r[i] = 1;
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &nn, &n1);
			for (int j = 1; j < nn; ++j) {
				scanf("%d", &n2);
				us(n1, n2);
			}
		}
		printf("%d\n", r[find(0)]);
	}
	return 0;
}