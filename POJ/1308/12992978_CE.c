#include<stdio.h>

int v1, v2;
int f[1005];
bool fg = true;

int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

bool us(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	else f[b] = a;
	return true;
}

int main() {
	int c = 1;
	for (int i = 1; i <= 1000; ++i)
	f[i] = i;
	while (scanf("%d %d", &v1, &v2)) {
		if (v1 < 0 && v2 < 0) return 0;
		if (v1 == 0 && v2 == 0) {
			if (fg) printf("Case %d is a tree.\n", c++);
			else printf("Case %d is not a tree.\n", c++);
			fg = true;
			for (int i = 1; i <= 1000; ++i)
			f[i] = i;
		} else if (!us(v1, v2)) fg = false;
	}
	return 0;
}