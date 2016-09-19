#include <iostream>
using namespace std;
#define INF 0x0f0f0f0f

int w[105][105];
int n, a, b;
int min(int a, int b);
void floyd();
int main() {
	scanf("%d %d %d", &n, &a, &b);
	int nn, e;
	memset(w, 0x0f, sizeof(w));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &nn);
		for (int j = 0; j < nn; ++j) {
			scanf("%d", &e);
			w[i][e] = 1;
		}
	}
	floyd();
	if (w[a][b] == INF) printf("-1\n");
	else printf("%d\n", w[a][b]-1);
	return 0;
}

void floyd() {
	for (int k = 1; k <= n; ++k) 
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (w[i][k] != INF && w[k][j] != INF)
					w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
}

int min(int a, int b) {
	return a > b ? b : a;
}