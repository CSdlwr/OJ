
#include <iostream>
using namespace std;
#define MAX_LEN 50005

int input[MAX_LEN];
int dp1[MAX_LEN];
int dp2[MAX_LEN];

int main() {
	int t, n;
	scanf("%d", &t);
	while (t-- > 0) {
		int i = 0;
		scanf("%d", &n);
		for (; i < n; ++i) 
			scanf("%d", &input[i]);
		dp1[0] = input[0];
		for (i = 1; i < n; ++i) {
			if (dp1[i-1] > 0)
				dp1[i] = dp1[i-1] + input[i];
			else dp1[i] = input[i];
		}
		dp2[n-1] = input[n-1];
		for (i = n-2; i >= 0; --i) {
			if (dp2[i+1] > 0)
				dp2[i] = dp2[i+1] + input[i];
			else dp2[i] = input[i];
		}
		int max = 0, tmp;
		for (i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if ((tmp = dp1[i] + dp2[j]) > max)
					max = tmp;
			}
		}
		printf("%d", max);
	}
}