#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10005

int main() {
	long long dp[MAX_N];
	int n;
	int po[MAX_N];
	scanf("%d", &n);
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &po[i]);
	po[0] = po[1];
	sort(po+1, po+n+1);
	po[n+1] = po[n];
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i-1] + (po[i] - po[i-1]) * (i - 1);
		ans += dp[i];
	}
	dp[n+1] = 0;
	dp[n] = 0;
	for (int i = n; i >= 1; --i) {
		dp[i] = dp[i+1] + (po[i+1] - po[i]) * (n - i);
		ans += dp[i];
	}
	printf("%I64d\n", ans);
	return 0;
}