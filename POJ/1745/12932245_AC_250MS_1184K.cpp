#include <iostream>
using namespace std;
#define MAXN 10005
#define MAXK 105

bool dp[MAXN][MAXK];

int main() {
	int n, k;
	int inp;
	scanf("%d %d", &n, &k);
	scanf("%d ", &inp);
	memset(dp, 0, sizeof(dp));
	while (inp < 0)
		inp += k;
	dp[0][inp%k] = true;
	for (int i = 1; i < n; ++i) {
		scanf("%d", &inp);
		while (inp < 0)
			inp += k;
		for (int j = 0; j < k; ++j) {
			if (dp[i-1][j]) {
				dp[i][(j+inp)%k] = true;
				int t = j - inp;
				if (t < 0) {
					while (t < 0)
						t += k;
					dp[i][t] = true;
				} else dp[i][t] = true;
			}
		}
	}
	if (dp[n-1][0])	printf("Divisible\n");
	else printf("Not divisible\n");
	return 0;
}