#include <iostream>
using namespace std;

char inp[100005];
int dp[100005];
int main() {
	while (scanf("%s", inp+1) != EOF) {
		if (inp[1] == '0')
			break;
		dp[1] = 1;
		if (inp[2] == '0' || inp[1] > '2' || inp[1] == 2 && inp[2] > '6')
			dp[2] = 1;
		else dp[2] = 2;
		for (int i = 3; i <= strlen(inp+1); ++i) {
			if (inp[i] == '0') 
				dp[i] = dp[i-2];
			else if (inp[i-1] > '2' || inp[i-1] == 2 && inp[i] > '6' || inp[i-1] == '0')
				dp[i] = dp[i-1];
			else dp[i] = dp[i-1] + dp[i-2];
		}
		printf("%d\n", dp[strlen(inp+1)]);
	}
	return 0;
}