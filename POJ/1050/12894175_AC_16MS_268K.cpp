#include <iostream>
using namespace std;
#define MAX_NUM 101

int input[MAX_NUM][MAX_NUM];
int dp[MAX_NUM];
int ans[MAX_NUM];
int n;
int maxlen = -999999999;
int main() {
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; ++i) 
		for (j = 0; j < n; ++j)
			scanf("%d", &input[i][j]);
	for (i = 0; i < n; ++i) {
		memset(ans, 0, sizeof(ans));
		for (j = i; j < n; ++j) {
			for (int k = 0; k < n; ++k) 
				ans[k] += input[j][k];
			dp[0] = ans[0];
			for (int k = 1; k < n; ++k) {
				if (dp[k-1] < 0)
					dp[k] = ans[k];
				else dp[k] = ans[k] + dp[k-1];
				maxlen = dp[k] > maxlen ? dp[k] : maxlen;
			}
		}
	}
	cout<<maxlen<<endl;
	return 0;
}