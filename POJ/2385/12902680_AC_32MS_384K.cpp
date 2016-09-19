#include <iostream>
using namespace std;
#define MAXT 1005
#define MAXW 35
int max(int a, int b);

int main() {
	int t, w;
	int dp[MAXT][MAXW];
	int p[MAXW];
	for (int i = 0; i < MAXW; ++i)
		p[i] = (i % 2 == 0) ? 1 : 2;
	memset(dp, 0, sizeof(dp));
	int f[MAXT];
	cin>>t>>w;
	for (int i = 1; i <= t; ++i) {
		cin>>f[i];
		if (f[i] == 1) dp[i][0] = dp[i-1][0] + 1;
		else dp[i][0] = dp[i-1][0];
	}
	for (int i = 1; i <= t; ++i) {
		for (int j = 1; j <= w; ++j) {
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);
			if (p[j] == f[i])
				dp[i][j]++;
		}
	}
	cout<<dp[t][w];
	return 0;
} 

int max(int a, int b) {
	return a > b ? a : b;
}