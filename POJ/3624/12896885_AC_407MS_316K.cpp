#include <iostream>
using namespace std;
#define MAX_NUM 3500
#define MAX_M 13000

int w[MAX_NUM], d[MAX_NUM];
int v[MAX_M];
int n, m, t;
 int main() {
 	cin>>n>>m;
 	for (int i = 1; i <= n; ++i)
 		cin>>w[i]>>d[i];
	memset(v, 0, sizeof(v));
	for (int i = 0; i <= n; ++i) {
		for (int j = m; j >= 1; --j) {
			if (i == 0 || j == 0)
				v[j] = 0;
			else {
				if (j >= w[i]) {
					int t = v[j-w[i]] + d[i];
					v[j] = v[j] < t ? t : v[j];
				}

			}
		}
	}
 	cout<<v[m]<<endl;
 	return 0;
 }