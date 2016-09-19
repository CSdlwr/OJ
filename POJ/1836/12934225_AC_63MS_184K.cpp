#include <iostream>
using namespace std;

int dp1[1005];
int dp2[1005];
float h[1005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%f", &h[i]);
		dp1[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (h[j] < h[i] && dp1[j] + 1 > dp1[i])
				dp1[i] = dp1[j] + 1;
		}
	}
	
	dp2[n-1] = 1;
	for (int i = n-2; i >= 0; --i) {
		dp2[i] = 1;
		for (int j = n-1; j > i; --j) {
			if (h[j] < h[i] && dp2[j] + 1 > dp2[i])
				dp2[i] = dp2[j] + 1;
		}
	}
	int max = 0;
	for (int i = 0, t1, t2; i < n; ++i) {
		t1 = 0, t2 = 0;
		for (int j = 0; j <= i; ++j) 
			if (dp1[j] > t1) t1 = dp1[j];
		for (int j = i + 1; j < n; ++j)
			if (dp2[j] > t2) t2 = dp2[j];
		if (max < t1 + t2) max = t1 + t2;
	}
	printf("%d\n", n - max);
}