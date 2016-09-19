#include <iostream>
using namespace std;
#define INF 0x0f0f0f0f
void floyd();
int min(int a, int b);
int mp[21][21];

int main() {
	int ts = 1;
	int n, s, e;
	while (scanf("%d", &n) != EOF) {
		memset(mp, 0x0f, sizeof(mp));
		for (int i = 0; i < n; ++i) {
			scanf("%d", &e);
			mp[1][e] = mp[e][1] = 1;
		}
		mp[1][1]= 0;
		for (int i = 2; i <= 19; ++i) {
			scanf("%d", &n);
			for (int j = 0; j < n; ++j) {
				scanf("%d", &e);
				mp[i][e] = mp[e][i] = 1;
				mp[i][i] = 0;
			}
		}
		floyd();
		printf("Test Set #%d\n", ts++);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &s, &e);
			printf("%d to %d: %d\n", s, e, mp[s][e]);
		}
		printf("\n");
	}
	return 0;
}


void floyd() {
	for (int k = 1; k <= 20; ++k) 
		for (int i = 1; i <= 20; ++i)
			for (int j = 1; j <= 20; ++j)
				if (mp[i][k] != INF && mp[k][j] != INF)
					mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
}

int min(int a, int b) {
	return a > b ? b : a;
}