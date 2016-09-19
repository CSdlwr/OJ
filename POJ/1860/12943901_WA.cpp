#include <iostream>
using namespace std;
#define MAXM 105
#define MAXN 105

struct edge {
	int v1, v2;
	double c, r;
}es[MAXM];
bool bellman_ford();
int n, m, s;
double v;
int main() {
	scanf("%d %d %d %lf", &n, &m, &s, &v);
	int v1, v2;
	double r12, c12, r21, c21;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %lf %lf %lf %lf", &v1, &v2, &r12, &c12, &r21, &c21);
		es[i].v1 = v1;
		es[i].v2 = v2;
		es[i].r = r12;
		es[i].c = c12;
		es[m+i].v1 = v2;
		es[m+i].v2 = v1;
		es[m+i].r = r21;
		es[m+i].c = c21;
	}
	if (bellman_ford()) printf("YES\n");
	else printf("NO\n");
	return 0;
}

bool bellman_ford() {
	bool f = false;
	double d[MAXN];
	for (int i = 1; i <= n; ++i)
		d[i] = 0.0;
	d[s] = v;
	for (int i = 0; i < n-1; ++i) {
		f = false;
		for (int j = 0; j < 2*m; ++j) {
			double t = (d[es[j].v1] - es[j].c)*es[j].r;
			if (d[es[j].v2] < t && d[es[j].v2] > 0) {
				d[es[j].v2] = t;
				f = true;
			}
		}
		if (d[s] > v) return true;
		if (!f) break;
	}
	for (int i = 0; i < 2*m; ++i) {
		int t = (d[es[i].v1] - es[i].c)*es[i].r;
		if (d[es[i].v2] < t)
			return true;
	}
	return false;
}