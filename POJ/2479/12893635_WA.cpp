
#include <iostream>
using namespace std;
#define MAX_LEN 50005

int input[MAX_LEN];
int dp1[MAX_LEN];
int dp2[MAX_LEN];
int maxlen1[MAX_LEN];
int maxlen2[MAX_LEN];
int max(int a, int b);

int main() {
	int t, n;
	scanf("%d", &t);
	while (t-- > 0) {
		int i = 0;
		scanf("%d", &n);
		for (; i < n; ++i) 
			scanf("%d", &input[i]);
		dp1[0] = input[0];
		maxlen1[0] = dp1[0];
		for (i = 1; i < n; ++i) {
			if (dp1[i-1] > 0)
				dp1[i] = dp1[i-1] + input[i];
			else dp1[i] = input[i];
			maxlen1[i] = max(dp1[i], maxlen1[i-1]);
		}
		int ans = -1;
		dp2[n-1] = input[n-1];
		maxlen2[n-1] = dp2[n-2];
		for (i = n-2; i >= 0; --i) {
			if (dp2[i+1] > 0)
				dp2[i] = dp2[i+1] + input[i];
			else dp2[i] = input[i];
			//ans = max(dp2[i+1], dp2[i]);
			maxlen2[i] = max(dp2[i], maxlen2[i+1]);
		}
		
 		int max = 0, tmp;
		for (int i = 0; i < n-1; ++i) {
			tmp = maxlen1[i] + maxlen2[i+1];
			max = max < tmp ? tmp : max;
		}
		cout<<max<<endl;
//  		for (i = 0; i < n; ++i) {
// 			for (int j = i + 1; j < n; ++j) {
// 				if ((tmp = dp1[i] + dp2[j]) > max)
// 					max = tmp;
// 			}
// 		}
		printf("%d", ans);
	}
}

int max(int a, int b) {
	return a > b ? a : b;
}