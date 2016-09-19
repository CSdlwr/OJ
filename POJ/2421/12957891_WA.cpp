#include <iostream>
using namespace std;
#define INF 0xfffffff

int prim();
int w[105][105];
int n, bn;
int a, b;
bool vs[105];
bool bt[105];
int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &w[i][j]);
		scanf("%d", &bn);
		memset(vs, 0, sizeof(vs));
		memset(bt, 0, sizeof(bt));
		for (int i = 0; i < bn; ++i) {
			scanf("%d %d", &a, &b);
			bt[a-1] = bt[b-1] = true;
		}
		printf("%d\n", prim());
	}
	return 0;
}

int prim() {
	int sum = 0;
	int k[105];
	for (int i = 0; i < n; ++i) {
		if (bt[i]) k[i] = 0;
		else k[i] = INF;
	}
	
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