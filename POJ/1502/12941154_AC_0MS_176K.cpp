#include <iostream>
using namespace std;
#define MAXN 105
#define INF 0x7fffffff

int dijkstra();
int w[MAXN][MAXN];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j) 
			w[i][j] = INF;
	char inp[10];
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			scanf("%s", inp);
			if (!(strlen(inp) == 1 && inp[0] == 'x')) {
				w[i][j] = w[j][i] = atoi(inp);
			}
		}
	}
	printf("%d\n", dijkstra());
	return 0;
}

int dijkstra() {
	int d[MAXN];
	int vs[MAXN];
	int ans = 0;
	d[1] = 0;
	memset(vs, 0, sizeof(vs));
	for (int i = 2; i <= n; ++i)
		d[i] = INF;
	for(int i = 1; i <= n; ++i) {
		int min = INF;
		int v = 0;
		for (int j = 1; j <= n; ++j) {
			if (!vs[j] && d[j] < min) {
				min = d[j];
				v = j;
			}
		}
		vs[v] = true;
		if (d[v] > ans) ans = d[v];
		for (int j = 1; j <= n; ++j) {
			if (!vs[j] && w[v][j] < INF && d[j] > w[v][j]+d[v])
				d[j] = d[v] + w[v][j];
		}
	}
	return ans;
}