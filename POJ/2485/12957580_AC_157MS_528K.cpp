#include <iostream>
using namespace std;
#define INF 0x0f0f0f0f
int prim();
int w[505][505];
int t, n;
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &w[i][j]);
		printf("%d\n", prim());
	}
	return 0;
}

int prim() {
	int max = -1;
	int k[505];
	bool vs[505];
	memset(k, 0x0f, sizeof(k));
	memset(vs, 0, sizeof(vs));
	k[0] = 0;
	int min, v;
	for (int i = 0; i < n; ++i) {
		min = INF;
		v = -1;
		for (int j = 0; j < n; ++j) {
			if (!vs[j] && k[j] < min) {
				min = k[j];
				v = j;
			}
		}
		if (v == -1) break;
		if (max < k[v]) max = k[v];
		vs[v] = true;
		for (int j = 0; j < n; ++j)
			if (!vs[j] && w[v][j] < k[j])
				k[j] = w[v][j];
	}
	return max;
}