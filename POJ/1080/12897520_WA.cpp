#include <iostream>
using namespace std;
#define MAX_LEN 110

int getm(char a, char b);
int m[][6] = {
	{5, -1, -2, -1, -3},
	{-1, 5, -3, -2, -4},
	{-2, -3, 5, -2, -2},
	{-1, -2, -2, 5, -1},
	{-3, -4, -2, -1, 0}
};

int main() {
	int n;
	char s1[MAX_LEN], s2[MAX_LEN];
	int dp[MAX_LEN][MAX_LEN];
	cin>>n;
	int l1 = 0, l2 = 0;
	while (n-- > 0) {
		scanf("%d", &l1);
		cin>>&s1[1];
		scanf("%d", &l2);
		cin>>&s2[1];
		for (int i = 1; i <= l1; ++i)
			dp[0][i] = getm('-', s2[i]);
		for (int i = 1; i <= l2; ++i)
			dp[i][0] = getm(s1[i], '-');
		dp[0][0] = 0;
		for (int i = 1; i <= l1; ++i) {
			for (int j = 1; j <= l2; ++j) {
				int a, b, c;
				a = dp[i-1][j-1] + getm(s1[i], s2[j]);
				b = dp[i-1][j] + getm(s1[i], '-');
				c = dp[i][j-1] + getm('-', s2[j]);
				dp[i][j] = a > b ? a : b;
				dp[i][j] = dp[i][j] > c ? dp[i][j] : c;
			}
		}
		cout<<dp[l1][l2]<<endl;
	}
	return 0;
}

int getm(char a, char b) {
	int i, j;
	switch(a) {
		case 'A': 
			i = 0; break;
		case 'C':
			i = 1; break;
		case 'G':
			i = 2; break;
		case 'T':
			i = 3; break;
		default:
			i = 4;
	}
	switch(b) {
		case 'A':
			j = 0; break;
		case 'C':
			j = 1; break;
		case 'G':
			j = 2; break;
		case 'T':
			j = 3; break;
		default:
			j = 4; break;
	}
	return m[i][j];
}