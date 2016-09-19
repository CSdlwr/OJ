#include <iostream>
using namespace std;
#define MAX_N 2005

int main() {
	int n;
	int input[MAX_N];
	int dp[MAX_N];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &input[i]);
	dp[1] = 0;
	for (int i = 2; i <= n; ++i) {
		if (input[i] > input[i-1])
			dp[i] = dp[i-1];
		else
			dp[i] = dp[i-1] + input[i-1] - input[i];
	}
	int min = dp[n];

	for (int i = 2; i <= n; ++i) {
		if (input[i] > input[i-1])
			dp[i] = dp[i-1] + input[i] - input[i-1];
		else
			dp[i] = dp[i-1];
	}
	min = dp[n] < min ? dp[n] : min;
	printf("%d\n", min);
}