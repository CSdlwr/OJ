#include <iostream>
using namespace std;
#define INF 0x0f0f0f0f
int prim();
int n;
int w[105][105];
int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i)	
			for (int j = 0; j < n; ++j) 
				scanf("%d", &w[i][j]);
		printf("%d\n", prim());
	}
	return 0;
}

int prim() {
	int sum = 0;
	int k[105];
	bool vs[105];
	memset(vs, 0, sizeof(vs));
	memset(k, 0x0f, sizeof(k));
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
		vs[v] = true;
		sum += k[v];
		for (int j = 0; j < n; ++j) 
			if (!vs[j] && w[v][j] < k[j])
				k[j] = w[v][j];
	}
	return sum;
}