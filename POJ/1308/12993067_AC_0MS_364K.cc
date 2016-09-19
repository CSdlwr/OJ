#include<stdio.h>
#include<string.h>
int v1, v2;
int f[1005];
bool vs[1005];
int r[1005];
bool fg = true;

int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

bool us(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (r[a] >= r[b]) {
		f[b] = a;
		r[a] += r[b];
	} else {
		f[a] = b;
		r[b] += r[a];
	}
	return true;
}

int main() {
	int cnt = 0;
	int c = 1;
	int v;
	for (int i = 1; i <= 1000; ++i) {
	f[i] = i; r[i] = 1;
	}
	memset(vs, 0, sizeof(vs));
	while (scanf("%d %d", &v1, &v2)) {
		if (v1 < 0 && v2 < 0) return 0;
		if (v1 == 0 && v2 == 0) {
			if (cnt == 0) {
			printf("Case %d is a tree.\n", c++);
			continue;
			}
			if (fg && cnt==r[find(v)]) printf("Case %d is a tree.\n", c++);
			else printf("Case %d is not a tree.\n", c++);
			fg = true;
			cnt = 0;
			for (int i = 1; i <= 1000; ++i) { 
				f[i] = i; r[i] = 1; 
			}
			memset(vs, 0, sizeof(vs));
			continue;
		} else if (!us(v1, v2)) fg = false;
		v = v1;
		if (!vs[v1]) {cnt++; vs[v1] = true;}
		if (!vs[v2]) {cnt++; vs[v2] = true;}
	}
	return 0;
}