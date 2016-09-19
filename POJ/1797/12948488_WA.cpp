#include <iostream>
using namespace std;
#define MAXN 1005
#define INF 0xfffffff

int dijkstra();
int w[MAXN][MAXN];
int n, m;
int main() {
	int t;
	scanf("%d", &t);
	for (int nn = 1; nn <= t; ++nn) {
		scanf("%d %d", &n, &m);
		int v1, v2, wt;
		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d", &v1, &v2, &wt);
			w[v1][v2] = w[v2][v1] = wt;
		}
		printf("Scenario #%d:\n", nn);
		printf("%d\n\n", dijkstra());
	}
	return 0;
}

int dijkstra() {
	int d[MAXN];
	bool vs[MAXN];
	memset(vs, 0, sizeof(vs));
	d[1] = INF;
	for (int i = 2; i <= n; ++i) 
		d[i] = 0;
	int max, v;
	for (int i = 0; i < n; ++i) {
		max = 0;
		v = 0;
		for (int j = 1; j <= n; ++j) {
			if (!vs[j] && d[j] > max) {
				max = d[j];
				v = j;
			}
		}
		if (max == 0) break;
		if (v == n) break;
		vs[v] = true;
		for (int j = 1; j <= n; ++j) {
			if (!vs[j] && d[j] < w[v][j])
				d[j] = w[v][j];
		}
	}
	return d[n];
}