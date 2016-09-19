#include<stdio.h>

int n, k;
int d, a, b;
int f[50005];
int r[50005];
int ans =  0;

int find(int x) {
	if (x == f[x]) return x;
	int t = f[x];
	f[x] = find(f[x]);
	r[x] = (r[x]+r[t])%3;
	return f[x];
}

void us(int x, int y, int d) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) {
		f[fy] = fx;
		r[fy] = (3-r[y]+d-1+r[x])%3;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		f[i] = i;
		r[i] = 0;
	}
	for (int i = 0; i < k; ++i) {
		scanf("%d %d %d", &d, &a, &b);
		if (a > n || b > n) ++ans;
		else if (d == 2 && a == b) ++ans;
		else if (find(a) == find(b)) {
			if (d == 1 && r[a] != r[b]) ++ans;
			if (d == 2 && (r[a]+1)%3 != r[b]) ++ans;
		} else us(a, b, d);
	}
	printf("%d\n", ans);
	return 0;
}