#include<stdio.h>

int t;
int n, m;
int x, y;
char d;
int f[100005], r[100005];

int find(int x) {
	if (x == f[x]) return x;
	int t = f[x];
	f[x] = find(f[x]);
	r[x] = (r[x]+r[t])%2;
	return f[x];
}

void us(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) {
		f[fx] = fy;
		r[fx] = (r[y]+1+r[x])%2;
	}
}

int main() {
	scanf("%d", &t);
	getchar();
	while (t-- > 0) {
		scanf("%d %d", &n, &m);
		getchar();
		for (int i = 1; i <= n; ++i) {
			f[i] = i; r[i] = 0;
		}
		for (int i=0; i<m; ++i) {
			scanf("%c %d %d", &d, &x, &y);
			getchar();
			if (d == 'A') {
				if (find(x) != find(y)) printf("Not sure yet.\n");
				else if (r[x] == r[y]) printf("In the same gang.\n");
				else printf("In different gangs.\n");
			} else  us(x, y);
		}
	}
	return 0;
}