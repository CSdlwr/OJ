#include <iostream>
using namespace std;
#define MAXN 1005
#define INF 0xfffffff

int n, m, x;
void transpose(int a[][MAXN]);
void dijkstra(int w[][MAXN], int x, int* d);

int w[MAXN][MAXN];
int wt[MAXN][MAXN];
bool vs[MAXN];
int d1[MAXN], d2[MAXN];

int main() {
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j)
			w[i][j] = INF;
	int v1, v2, len;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &v1, &v2, &len);
		w[v1][v2] = len;
	}
	dijkstra(w, x, d1);
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j) 
			wt[i][j] = w[j][i];
			//swap(w[i]+j, w[j]+i);
	//transpose(w);
	dijkstra(wt, x, d2);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (d1[i]+d2[i] > ans) ans = d1[i] + d2[i];
	printf("%d\n", ans);
	return 0;
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// void transpose(int a[][MAXN]) {
// 	for (int i = 1; i <= n; ++i) {
// 		for (int j = 1; j <= n; ++j) {
// 			int t = a[i][j];
// 			a[i][j] = a[j][i];
// 			a[j][i] = t;
// 		}
// 	}
// }

void dijkstra(int w[][MAXN], int x, int* d) {
	//int d[MAXN];
	for (int i = 1; i <= n; ++i) {
		if (i == x) d[i] = 0;
		else d[i] = INF;
	}
	memset(vs, 0, sizeof(vs));
	for (int i = 1; i <= n; ++i) {
		int min = INF;
		int v = 0;
		for (int j = 1; j <= n; ++j) {
			if (!vs[j] && d[j] < min) {
				min = d[j];
				v = j;
			}
		}
		vs[v] = true;
		for (int j = 1; j <= n; ++j) 
			if (!vs[j] && w[v][j] < INF && d[j] > w[v][j] + d[v])
				d[j] = w[v][j] + d[v];
	}
}