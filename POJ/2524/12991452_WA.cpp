#include<iostream>
#include<string.h>
using namespace std;

bool vs[50005];
int f[50005];
int r[50005];
int n, m;
int a, b;
int cnt;
int set;
int find(int x) {
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}

bool us(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	else if (r[a] > r[b]) {
		f[b] = a;
		r[a] += r[b];
	} else {
		f[a] = b;
		r[b] += r[a];
	}
	return true;
}

int main() {
	while (scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0) break;
		memset(vs, 0, sizeof(vs));
		cnt = set = 0;
		for (int i = 1; i <= n; ++i) {
			f[i] = i;
			r[i] = 1;
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &a, &b);
			if (!vs[a]) { ++cnt; vs[a] = true; }
			if (!vs[b]) { ++cnt; vs[a] = true; }
			if (us(a, b)) ++set;
		}
		printf("%d\n", cnt-set+n-cnt);
	}
	return 0;
}