#include <iostream>
using namespace std;

int cnt;
int main() {
	int n;
	int input[5005];
	int dp[5005];
	int cnt[5005];
	int maxlen = 1;
	int maxcnt = 1;
	bool mark = true;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &input[i]);
		dp[i] = 1;
		if (i > 0) {
			for (int j = 0; j < i; ++j) {
				if (input[j] > input[i] && dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					if (dp[i] > maxlen) maxlen = dp[i];
				}
			}
		}
	}
	cnt[0] = 1;
	dp[n] = maxlen + 1;
	for (int i = 1; i <= n; ++i) {
		if (dp[i] == 1) {
			cnt[i] = 1;
			continue;
		} else cnt[i] = 0;	
		for (int j = i - 1; j >= 0; --j) {
			if (input[j] > input[i] 
			&& dp[j] + 1 == dp[i]) {
				mark = true;
				for (int k = j + 1; k < i; ++k)
					if (input[j] == input[k]) {
						mark = false;
						break;
					}
				if (mark) cnt[i] += cnt[j];
			}
		}
		//maxcnt = maxcnt < cnt[i] ? cnt[i] : maxcnt;
	}
// 	for (int i = 0; i < n; ++i) {
// 		if (dp[i] == maxlen)
// 			maxcnt += cnt[i];
// 	}
	printf("%d %d\n", maxlen, cnt[n]);
}
