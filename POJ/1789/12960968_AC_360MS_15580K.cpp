#include <iostream>
using namespace std;
#define INF 0x0f0f0f0f
int prim();
int n;
int w[2005][2005];
char cs[2005][8];
int main() {
	while (scanf("%d", &n)) {
		if (n == 0) break;
		for (int i = 0; i < n; ++i)
			scanf("%s", cs[i]);
		int cnt;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				cnt = 0;
				for (int k = 0; k < 7; ++k) 
					if (cs[i][k] != cs[j][k]) ++cnt;
				w[i][j] = w[j][i] = cnt;
			}
		}
		printf("The highest possible quality is 1/%d.\n", prim());
	}
	return 0;
}

int prim() {
	int sum = 0;
	int k[2005];
	bool vs[2005];
	memset(k, 0x0f, sizeof(k));
	k[0] = 0;
	memset(vs, 0, sizeof(vs));
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