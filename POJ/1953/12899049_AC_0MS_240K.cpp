#include <iostream>
using namespace std;
#define MAX_N 50

int dp[MAX_N];

int main() {
	int t;
	cin>>t;
	int i = 0;
	while (i++ < t) {
		int n;
		cin>>n;
		dp[1] = 2;
		dp[2] = 3;
		for (int j = 3; j <= n; ++j) 
			dp[j] = dp[j-1] + dp[j-2];
		cout<<"Scenario #"<<i<<":"<<endl;
		cout<<dp[n]<<endl<<endl;
	}
	return 0;
}