#include <iostream>
using namespace std;

char inp[5000];
int dp[5000];
int main() {
	while (1) {
		scanf("%s", inp+1);
		int t = strlen(inp+1);
		if (strlen(inp+1) == 1 && inp[1] == '0')
			break;
		dp[1] = 1;
		if (inp[2] == '0')
			dp[2] = 1;
		else if (inp[2] > '6' && inp[1] >= '2' || inp[2] < '6' && inp[1] > '2')
			dp[2] = 1;
		else dp[2] = 2;
		for (int i = 3; i <= strlen(inp+1); ++i) {
			if (inp[i] == '0') 
				dp[i] = dp[i-2];
			else if (inp[i] > '6' && inp[i-1] >= '2'
				|| inp[i] <= '6' && inp[i-1] > '2') 
				dp[i] = dp[i-1];
			else dp[i] = dp[i-1] + dp[i-2];
		}
		printf("%d\n", dp[strlen(inp+1)]);
	}
	
	return 0;
}