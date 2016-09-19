#include <iostream>
using namespace std;
#define INF 0x0f0f0f0f

int mp[305][305];
int min(int a, int b);
int max(int a, int b);
void floyd();
int n, m, t;
int main() {
	scanf("%d %d %d", &n, &m, &t);
	int s, e, h;
	memset(mp, 0x0f, sizeof(mp));
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d %d", &s, &e, &h);
		mp[s][e] = h;
	}
	floyd();
	for (int i = 0; i < t; ++i) {
		scanf("%d %d", &s, &e);
		if (mp[s][e] == INF) printf("-1\n");
		else printf("%d\n", mp[s][e]);
	}
	return 0;
}

void floyd() {
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (mp[i][k] != INF && mp[k][j] != INF)
					mp[i][j] = min(mp[i][j], max(mp[i][k], mp[k][j]));
}

int min(int a, int b) {
	return a > b ? b : a;
}

int max(int a, int b) {
	return a > b ? a : b;
}