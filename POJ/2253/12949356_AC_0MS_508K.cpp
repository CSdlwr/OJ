#include <iostream>
#include <math.h>
using namespace std;
#define MAXN 205
#define INF 0xfffffff

double dijkstra();
double max(double a, double b);
double dist(int x1, int y1, int x2, int y2);
double w[MAXN][MAXN];
int ix[MAXN], iy[MAXN];

int n;
int main() {
	int nn = 1;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		double dis;
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &ix[i], &iy[i]);
			for (int j = 0; j < i; ++j) {
				dis  = dist(ix[i], iy[i], ix[j], iy[j]);
				w[j][i] = w[i][j] = dis;
			}
		}
		printf("Scenario #%d\n", nn++);
		printf("Frog Distance = %.3lf\n\n", dijkstra());
	}
	return 0;
}

double dijkstra() {
	double d[MAXN];
	bool vs[MAXN];
	memset(vs, 0, sizeof(vs));
	d[0] = 0;
	for (int i = 1; i < n; ++i) 
		d[i] = INF;
	double min;
	int v;
	for (int i = 0; i < n; ++i) {
		min = INF;
		for (int j = 0; j < n; ++j) {
			if (!vs[j] && d[j] < min) {
				min = d[j];
				v = j;
			}
		}
		vs[v] = true;
		if (min == INF) break;
		if (v == 1) break;
		for (int j = 0; j < n; ++j) {
			if (!vs[j]) {
				double t = max(w[v][j], d[v]);
				d[j] = d[j] > t ? t : d[j];
			}
		}
	}
	return d[1];
}

double dist(int x1, int y1, int x2, int y2) {
	return sqrt((x1-x2)*(x1-x2)*1.0 + (y1-y2)*(y1-y2)*1.0);
}

double max(double a, double b) {
	return a > b ? a : b;
}