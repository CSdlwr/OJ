#include<stdlib.h>

int t, c = 1;
int n, m, x, y;
int f[2005], r[2005];
bool flag;
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
		f[fy] = fx;
		r[fy] = (r[y]+1+r[x])%2;
	}
}

int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		flag = false;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			r[i] = 0; f[i] = i;
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &x, &y);
			if (flag) continue;
			if (find(x) == find(y)) {
				if (r[x] == r[y]) flag = true;
			} else us(x, y);
		}
		printf("Scenario #%d:\n", c++);
		if (flag) printf("Suspicious bugs found!\n\n");
		else printf("No suspicious bugs found!\n\n");
	}
	return 0;
}