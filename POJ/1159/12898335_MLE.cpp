#include <iostream>
using namespace std;
#define MAX_LEN 5010

int find(int i, int j);

char s[MAX_LEN];
int dp[MAX_LEN][MAX_LEN];
int main() {
	int n;
	cin>>n;
	cin>>(s+1);
	memset(dp, -1, sizeof(dp));
	cout<<find(1, n)<<endl;
	return 0;
}

int find(int i, int j) {
	if (i >= j)
		return 0;
	if (s[i] == s[j]) {
		dp[i][j] = dp[i+1][j-1];
		if (dp[i][j] == -1)
			dp[i][j] = find(i+1, j-1);
	} else {
		int l = dp[i][j-1];
		if (l == -1)
			l = find(i, j-1);
		int r = dp[i+1][j];
		if (r == -1)
			r = find(i+1, j);
		dp[i][j] = l > r ? r : l;
		dp[i][j]++;
	}
	return dp[i][j];
}