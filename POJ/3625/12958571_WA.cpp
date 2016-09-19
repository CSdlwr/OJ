#include <iostream>
#include <math.h>
using namespace std;
#define INF 0x0f0f0f0f

struct point {
	double x, y;
}pos[1005];
double prim();
double dist(point a, point b);
double w[1005][1005];
int n, m;
int main() {
	scanf("%d %d", &n, &m);
	double x, y;
	for (int i = 1; i <= n; ++i) {
		scanf("%lf %lf", &x, &y);
		pos[i].x = x; pos[i].y = y;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			w[i][j] = w[j][i] = dist(pos[i], pos[j]);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		w[a][b] = w[b][a] = 0;
	}
	printf("%.2lf\n", prim());
	return 0;
}

double prim() {
	double sum = 0;
	double k[1005];
	bool vs[1005];
	memset(vs, 0, sizeof(vs));
	for (int i = 1; i <= n; ++i)
		k[i] = INF;
	k[1] = 0;
	int v;
	double min;
	for (int i = 0; i < n; ++i) {
		v = -1; 
		min = INF;
		for (int j = 1; j <= n; ++j) {
			if (!vs[j] && k[j] < min) {
				min = k[j];
				v = j;
			}
		}
		if (v == -1) break;
		vs[v] = true;
		sum += vs[v];
		for (int j = 0; j <= n; ++j)
			if (!vs[j] && w[v][j] < k[j])
				k[j] = w[v][j];
	}
	return sum;
}

double dist(point a, point b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}