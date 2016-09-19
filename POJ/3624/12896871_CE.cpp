#include <iostream>
using namespace std;
#define MAX_NUM 3500
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


//int n, m;
//int w[MAX_NUM], d[MAX_NUM];
//int v[MAX_NUM][MAX_M];
//int maxValue(int i, int j);

//int main() {
//	cin>>n>>m;
//	int i;
//	for (i = 0; i < n; ++i) 
//		cin>>w[i]>>d[i];
//	memset(v, -1, sizeof(v));
//	cout<<maxValue(n-1, m)<<endl;
//	return 0;
//}
 
//int maxValue(int i, int j) {
//	if (i < 0 || j <= 0)
//		return 0;
//	if (j < w[i])
//		return maxValue(i-1, j);
//	int v1, v2;
//	if ((v1 = v[i-1][j]) == -1) 
//		v1 = maxValue(i-1, j);
//	if ((v2 = v[i-1][j-w[i]]) == -1)
//		v2 = maxValue(i-1, j-w[i]);
//	v2 += d[i];
//	v[i][j] = v1 > v2 ? v1 : v2;
//	return v[i][j];
//}