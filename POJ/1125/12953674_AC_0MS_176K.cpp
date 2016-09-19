#include <iostream>
using namespace std;

int mp[105][105];
void floyd();
int min(int a, int b);

int ans[2];
int sumcnt = 0;
int minsum = 0;
int maxcnt = 0;
int n;
int main() {
	while (scanf("%d", &n)) {
		if (n == 0) break;
		int nn;
		int a, b;
		memset(mp, 0x0f, sizeof(mp));
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &nn);
			mp[i][i] = 0;
			for (int j = 0; j < nn; ++j) {
				scanf("%d %d", &a, &b);
				mp[i][a] = b;
			}
		}
		floyd();
		minsum = 0xfffffff;
		for (int i = 1; i <= n; ++i) {
			bool f = false;
			sumcnt = maxcnt = 0;
			for (int j = 1; j <= n; ++j) {
				if (mp[i][j] == 0x0f0f0f0f) {
					f = true;
					break;
				}
				sumcnt += mp[i][j];
				maxcnt = maxcnt < mp[i][j] ? mp[i][j] : maxcnt;
			}
			if (!f && sumcnt < minsum) {
				minsum = sumcnt;
				ans[0] = i;
				ans[1] = maxcnt;
			}
		}
		printf("%d %d\n", ans[0], ans[1]);
	}
	return 0;
}

void floyd() {
	for (int k = 1; k <= n; ++k) 
		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= n; ++j) 
				if (mp[i][k] != 0x1f1f1f1f && mp[k][j] != 0x1f1f1f1f)
					mp[i][j] = min(mp[i][j], mp[i][k]+mp[k][j]);
}

int min(int a, int b) {
	return a > b ? b : a;
}