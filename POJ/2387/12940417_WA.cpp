#include <iostream>
#include <string.h>
using namespace std;
#define INF 0xfffffff
//#define MAXT 4005
#define MAXN 1005

int mp[MAXN][MAXN];

int dijkstra();
int n, t;

int main() {
	while (scanf("%d %d", &t, &n) != EOF) {
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				mp[i][j] = INF;
		int v1, v2, len;
		for (int i = 1; i <= t; ++i) {
			scanf("%d %d %d", &v1, &v2, &len);
			if (len < mp[v1][v2])
				mp[v1][v2] = mp[v2][v1] = len;
		}
		printf("%d\n", dijkstra());
	}
	
	return 0;
}

int dijkstra() {
	int d[MAXN];
	bool vs[MAXN];
	memset(vs, 0, sizeof(vs));
	d[1] = 0;
	for (int i = 2; i <= n; ++i)
		d[i] = mp[1][i];
		
	for (int i = 1; i <= n; ++i) {
		int min = INF;
		int v = 0;
		for (int j = 1; j <= n; ++j) {
			if (!vs[i] && d[i] < min) {
				min = d[i];
				v = i;
			}
		}
		vs[v] = true;
		for (int j = 1; j <= n; ++j) {
			if (!vs[j] && mp[v][j] < INF && d[j] > d[v] + mp[v][j]) 
				d[j] = d[v] + mp[v][j];
		}
	}
	return d[n];
}
