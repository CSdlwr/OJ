#include <iostream>
using namespace std;

int dp1[1005];
int dp2[1005];
float h[1005];

int main() {
	int n;
	scanf("%d", &n);
	//int cnt1 = 0, cnt2 = 0;
	//int t1, t2;
	for (int i = 0; i < n; ++i) {
		scanf("%f", &h[i]);
		dp1[i] = 1;
// 		if (i == 0) {
// 			t1 = dp1[i];
// 			continue;
// 		}
		for (int j = 0; j < i; ++j) {
			if (h[j] < h[i] && dp1[j] + 1 > dp1[i])
				dp1[i] = dp1[j] + 1;
		}
// 		if (dp1[i] <= t1) ++cnt1;
// 		else t1 = dp1[i];
	}
	
	dp2[n-1] = 1;
// 	t2 = dp2[n-1];
	for (int i = n-2; i >= 0; --i) {
		dp2[i] = 1;
		for (int j = n-1; j > i; --j) {
			if (h[j] < h[i] && dp2[j] + 1 > dp2[i])
				dp2[i] = dp2[j] + 1;
		}
// 		if (dp2[i] <= t2) ++cnt2;
// 		else t2 = dp2[i];
	}
	int cnt = 0, t;
	for (int i = 0; i < n; ++i) {
		t = dp1[i] + dp2[i];
		if (t > cnt) cnt = t;
	}
	printf("%d\n", n - cnt + 1);
// 	printf("%d\n", cnt1 < cnt2 ? cnt1 : cnt2);
}