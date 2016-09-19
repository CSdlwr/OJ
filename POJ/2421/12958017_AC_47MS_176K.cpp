#include <iostream>
using namespace std;
#define INF 0xfffffff

int prim();
int w[105][105];
int n, bn;
int a, b;
bool vs[105];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &w[i][j]);
	scanf("%d", &bn);
	memset(vs, 0, sizeof(vs));
	for (int i = 0; i < bn; ++i) {
		scanf("%d %d", &a, &b);
		w[a-1][b-1] = w[b-1][a-1] = 0;
	}
	printf("%d\n", prim());
	return 0;
}

int prim() {
	int sum = 0;
	int k[105];
	memset(k, 0x0f, sizeof(k));
	k[0] = 0;
	int v, min;
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
		vs[v] = true;
		sum += k[v];
		for (int j = 0; j < n; ++j)
			if (!vs[j] && w[v][j] < k[j])
				k[j] = w[v][j];
	}
	return sum;
}