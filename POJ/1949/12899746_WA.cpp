#include <iostream>
using namespace std;
#define MAX_N 10005
#define MAX_D 105

int cost[MAX_N];
int depends[MAX_N][MAX_D];
int dp[MAX_N];

int main() {
	int n;
	scanf("%d", &n);
	int i = 1;
	while (i <= n) {
		scanf("%d", &cost[i]);
		cin>>depends[i][0];
		for (int j = 1; j <= depends[i][0]; ++j)
			scanf("%d", &depends[i][j]);
		++i;
	}
	dp[1] = cost[1] - depends[1][0];
	int ans = -1;
	for (i = 2; i <= n; ++i) {
		int max_pre = -1;
		for (int j = 1; j <= depends[i][0]; ++j) {
			max_pre = max_pre < dp[depends[i][j]] ? dp[depends[i][j]] : max_pre;
		}
		dp[i] = max_pre + cost[i];
		ans = ans < dp[i] ? dp[i] : ans;
	}

	cout<<ans;
	return 0;
}