#include<iostream>
#include<string.h>
using namespace std;

bool mp[1100][1100];
int link[1100];
bool vs[1100];
bool find(int a);
int m, n, k;
int b;
int hi, hj, hn;
//int hns[35];
int main() {
	scanf("%d %d %d", &m, &n, &k);
	if ((b=m*n-k)%2) {
		printf("NO\n");
		return 0;
	}
	memset(mp, 0, sizeof(mp));
	memset(link, -1, sizeof(link));
	for (int i = 0; i < n*m; ++i) {
		if ((i+1)%n) mp[i][i+1] = true;
		if (i%n) mp[i][i-1] = true;
		if (i/n) mp[i][i-n] = true;
		if ((i/n)!=m-1) mp[i][i+n] = true;
	}
	for (int i = 0; i < k; ++i) {
		scanf("%d %d", &hj, &hi);
		hn = (hi-1)*n + hj-1;
		memset(mp[hn], 0, sizeof(mp[hn]));
		for (int j = 0; j < m*n; ++j)
			mp[j][hn] = false;
	}
	int ans = 0;
	for (int i = 0; i < m*n; ++i) {
		memset(vs, 0, sizeof(vs));
		if (find(i)) ++ans;
	}
	if (ans == b) printf("YES\n");
	else printf("NO\n");
	return 0;
}

bool find(int a) {
	for (int i = 0; i < m*n; ++i) {
		if (mp[a][i] && !vs[i]) {
			vs[i] = true;
			if (link[i] == -1 || find(link[i])) {
				link[i] = a;
				return true;
			}
		}
	}
	return false;
}