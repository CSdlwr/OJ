#include <iostream>
using namespace std;
#define MAX_NUM 3000
#define MAX_M 13000

int w[MAX_NUM], d[MAX_NUM];
int v[MAX_NUM][MAX_M];
int n, m, t;
 int main() {
 	cin>>n>>m;
 	for (int i = 1; i <= n; ++i)
 		cin>>w[i]>>d[i];
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i == 0 || j == 0)
				v[i][j] = 0;
			else {
				v[i][j] = v[i-1][j];
				if (j >= w[i]) {
					int t = v[i-1][j-w[i]] + d[i];
					v[i][j] = v[i][j] < t ? t : v[i][j];
				}

			}
		}
	}
 	cout<<v[n][m]<<endl;
 	return 0;
 }