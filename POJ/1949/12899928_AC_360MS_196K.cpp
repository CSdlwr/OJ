#include <iostream>
using namespace std;
#define MAX_N 10005
//#define MAX_D 105

int dp[MAX_N];
int cost;
int depends;

int main() {
	int n; 
	scanf("%d", &n);
	int i = 1; 
	int ans = -999999;
	while (i <= n) {
		scanf("%d", &cost);
		scanf("%d", &depends);
// 		if (i == 1)
// 			dp[i] = cost - depends;
		//else {
			int max_pre = 0, t;
			for (int j = 0; j < depends; ++j) {
				scanf("%d", &t);
				max_pre = max_pre < dp[t] ? dp[t] : max_pre;
			}
			dp[i] = cost + max_pre;
			ans = ans < dp[i] ? dp[i] : ans;
		//}
		++i;
	}
	//for (i = 1; i <= n; ++i)
	printf("%d\n", ans);
	return 0;
}