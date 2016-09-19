#include <iostream>
using namespace std;
#define MAX_NUM 100

int input[MAX_NUM][MAX_NUM];
int dp[MAX_NUM][MAX_NUM];

int main() {
	int v = 0, f = 0;
	cin>>f>>v;
	for (int i = 1; i <= f; ++i) 
		for (int j = 1; j <= v; ++j)
			cin>>input[i][j];
	for (int i = 0; i <= f; ++i) {
		for (int j = 0; j <= v; ++j) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else {
				dp[i][j] = dp[i-1][j-1] + input[i][j];
				dp[i][j] = dp[i][j] < dp[i][j-1] ? dp[i][j-1] : dp[i][j];
			}
		}
	}
	cout<<dp[f][v]<<endl;
	return 0;
}