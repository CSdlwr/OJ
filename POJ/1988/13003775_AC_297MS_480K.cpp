#include<iostream>
using namespace std;

int f[30005], r[30005], dist[30005];
int p;
char op;
int x, y;

int find(int x) {
	if (x == f[x]) return x;
	int t = f[x];
	f[x] = find(f[x]);
	dist[x] += dist[t];
	return f[x];
}

void us(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) {
		f[fy] = fx;
		dist[fy] += r[fx];
		r[fx] += r[fy];
	}
}

int main(){
	while (scanf("%d", &p) != EOF) {
		getchar();
		for (int i = 1; i <= 30000; ++i) {
			f[i] = i; r[i] = 1; dist[i] = 0;
		}
		for (int i = 0; i < p; ++i) {
			scanf("%c", &op);
			if (op == 'M') {
				scanf(" %d %d", &x, &y);
				getchar();
				us(x, y);
			} else {
				scanf(" %d", &x);
				getchar();
				find(x);
				printf("%d\n", r[f[x]]-dist[x]-1);
			}
		}
	}
	return 0;
}