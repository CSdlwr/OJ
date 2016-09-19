#include <iostream>
using namespace std;

int dp1[100005];
int dp2[100005];

int main() {
	int n;
	int input[100005];
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 0; i < n; ++i) 
			scanf("%d", &input[i]);
		dp1[0] = input[0];
		dp2[n-1] = input[n-1];
		for (int i = 1; i < n; ++i) {
			if (dp1[i-1] > 0)
				dp1[i] = input[i] + dp1[i-1];
			else dp1[i] = input[i];
			if (dp2[n-i] > 0)
				dp2[n-1-i] = input[n-i-1] + dp2[n-i];
			else dp2[n-1-i] = input[n-i-1];
		}
// 		dp2[n-1] = input[n-1];
// 		for (int i = n-2; i >= 0; --i) {
// 			if (dp2[i+1] > 0)
// 				dp2[i] = input[i] + dp2[i+1];
// 			else dp2[i] = input[i];
// 		}
		int ans = dp1[0];
		for (int i = 0; i < n; ++i) {
			for (int j = n-1; j > i; --j) {
				int t = dp1[i] + dp2[j];
				ans = ans < t ? t : ans;
			}
		}
		printf("%d\n", ans);
	}
}