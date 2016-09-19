#include <iostream>
#include <math.h>
using namespace std;
#define INF 0x0f0f0f0f
struct point {
	int x, y;
}pos[755];
int prim();
double dist(point p1, point p2);
double w[755][755];
int p[755];
double k[755];


int n, m;
int main() {
	scanf("%d", &n);
	int x, y;
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &x, &y);
		pos[i].x = x; pos[i].y = y;
	}
	for (int i = 1; i <= n; ++i) 
		for (int j = i + 1; j <= n; ++j) 
			w[i][j] = w[j][i] = dist(pos[i], pos[j]);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		w[x][y] = w[y][x] = 0;
	}
	int c = prim();
	for (int i = 1; i <= n; ++i)
		if (k[i] != 0) printf("%d %d\n", p[i], i);
	return 0;
}

int prim() {
	int cnt = 0;
	memset(p, -1, sizeof(p));
	bool vs[755];
	for (int i = 1; i <= n; ++i)
		k[i] = INF;
	memset(vs, 0, sizeof(vs));
	k[1] = 0;
	int v;
	double min;
	for (int i = 1; i <= n; ++i) {
		min = INF;
		v = -1;
		for (int j = 1; j <= n; ++j) {
			if (!vs[j] && k[j] < min) {
				min = k[j];
				v = j;
			}
		}
		if (v == -1) break;
		vs[v] = true;
		if (k[v] != 0) ++cnt;
		for (int j = 1; j <= n; ++j) {
			if (!vs[j] && w[v][j] < k[j]) {
				k[j] = w[v][j];
				p[j] = v;
			}
		}
	}
	return cnt;
}

double dist(point p1, point p2) {
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)*1.0 + 1.0*(p1.y-p2.y)*(p1.y-p2.y));
}