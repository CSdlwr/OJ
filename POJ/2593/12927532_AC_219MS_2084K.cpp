#include <iostream>
using namespace std;

int max1[100005];
int max2[100005];
int dp1[100005];
int dp2[100005];

int maxdp(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	int input[100005];
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &input[i]);
			if (i == 0) {
				dp1[i] = input[i];
				max1[i] = dp1[i];
			} else {
				if (dp1[i-1] > 0)
				dp1[i] = input[i] + dp1[i-1];
				else dp1[i] = input[i];
				max1[i] = maxdp(max1[i-1], dp1[i]);
			}
		}
		dp2[n-1] = input[n-1];
		int ans = -999999999;
		dp2[n-1] = input[n-1];
		max2[n-1] = dp2[n-1];
		for (int i = n-2; i >= 0; --i) {
			if (dp2[i+1] > 0)
				dp2[i] = input[i] + dp2[i+1];
			else dp2[i] = input[i];
			max2[i] = maxdp(max2[i+1], dp2[i]);
		}
		for (int i = 0; i < n-1; ++i) {
			int t = max1[i] + max2[i+1];
			ans = ans < t ? t : ans;
		}
		printf("%d\n", ans);
	}
}