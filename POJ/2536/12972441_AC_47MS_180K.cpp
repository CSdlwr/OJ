#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
double dist(double x1, double y1, double x2, double y2);
bool find(int a);
bool mp[105][105];
bool vs[105];
int link[105];
double gx[105], gy[105];
double hx[105], hy[105];
int n, m, s, v;
int main() {
	while (scanf("%d %d %d %d", &n, &m, &s, &v) != EOF) {
		for (int i = 0; i < n; ++i)
			scanf("%lf %lf", &gx[i], &gy[i]);
		for (int i = 0; i < m; ++i)
			scanf("%lf %lf", &hx[i], &hy[i]);
		memset(mp, 0, sizeof(mp));
		memset(link, -1, sizeof(link));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (dist(gx[i], gy[i], hx[j], hy[j])/v <= s*1.0) 
					mp[i][j] = true;
			}
		}
		int ans = 0;
		for (int i = 0; i < n ; ++i) {
			memset(vs, 0, sizeof(vs));
			if (find(i)) ++ans;
		}
		printf("%d\n", n-ans);
	}
	return 0;
}

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

bool find(int a) {
	for (int i = 0; i < m; ++i) {
		if (!vs[i] && mp[a][i]) {
			vs[i] = true;
			if (link[i] == -1 || find(link[i])) {
				link[i] = a;
				return true;
			}
		}
	}
	return false;
}