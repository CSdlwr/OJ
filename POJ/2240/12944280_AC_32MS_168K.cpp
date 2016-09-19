#include <iostream>
using namespace std;
#define MAXN 35
#define MAXM 1000

struct edge {
	int v1, v2;
	double r;
}es[MAXM];
bool bellman_ford();
char curr[MAXN][30];
int n, m;
int main() {
	int i = 1;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		getchar();
		for (int i = 0; i < n; ++i) 
			gets(curr[i]);
		scanf("%d", &m);
		char t1[30], t2[30];
		int v1, v2;
		double r;
		for (int i = 0; i < m; ++i) {
			scanf("%s%lf%s", t1, &r, t2);
			for (int j = 0; j < n; ++j) {
				if (strcmp(curr[j], t1) == 0)
					v1 = j;
				if (strcmp(curr[j], t2) == 0)
					v2 = j;
			}
			es[i].v1 = v1;
			es[i].v2 = v2;
			es[i].r = r;
		}
		char ch = getchar();
		ch = getchar();
		if (bellman_ford()) printf("Case %d: Yes\n", i);
		else printf("Case %d: No\n", i);
		++i;
	}
	return 0;
}

bool bellman_ford() {
	double d[MAXN];
	for (int i = 1; i < n; ++i)
		d[i] = 1;
	d[0] = 10;
	bool f;
	for (int i = 0; i < n-1; ++i) {
		f = false;
		for (int j = 0; j < m; ++j) {
			double t = d[es[j].v1]*es[j].r;
			if (t > d[es[j].v2]) {
				d[es[j].v2] = t;
				f = true;
			}
		}
		if (!f) break;
	}
	for (int i = 0; i < m; ++i) {
		double t = d[es[i].v1]*es[i].r;
		if (t > d[es[i].v2]) return true;
	}
	return false;
}