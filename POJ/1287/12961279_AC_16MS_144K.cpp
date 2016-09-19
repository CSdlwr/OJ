#include <iostream>
using namespace std;
#define INF 0x0f0f0f0f
int prim();
int w[55][55];
int p, r;
int main() {
	while(scanf("%d", &p)) {
		if (p == 0) break;
		scanf("%d", &r);
		if (r == 0) {
			printf("0\n");
			continue;
		}
		memset(w, 0x0f, sizeof(w));
		int v1, v2, l;
		for (int i = 0; i < r; ++i) {
			scanf("%d %d %d", &v1, &v2, &l);
			if (w[v1][v2] > l)
				w[v1][v2] = w[v2][v1] = l;
		}
		printf("%d\n", prim());
	}
	return 0;
}

int prim() {
	int sum = 0;
	int k[55];
	memset(k, 0x0f, sizeof(k));
	k[1] = 0;
	bool vs[55];
	memset(vs, 0, sizeof(vs));
	int min, v;
	for (int i = 0; i < p; ++i) {
		min = INF;
		v = -1;
		for (int j = 1; j <= p; ++j) {
			if (!vs[j] && k[j] < min) {
				min = k[j];
				v = j;
			}
		}
		if (v == -1) break;
		vs[v] = -1;
		sum += k[v];
		for (int j = 1; j <= p; ++j)
			if (!vs[j] && k[j] > w[v][j])
				k[j] = w[v][j];
	}
	return sum;
}