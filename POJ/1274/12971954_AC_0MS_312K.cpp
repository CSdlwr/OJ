#include<iostream>
#include<string.h>
using namespace std;
bool find(int a);
int mp[205][205];
int link[205];
bool vs[205];
int n, m;
int sn, s;
int main() {
	while (scanf("%d %d", &n, &m) != EOF) {
		memset(link, 0, sizeof(link));
		memset(mp, 0, sizeof(mp));
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &sn);
			for (int j = 0; j < sn; ++j) {
				scanf("%d", &s);
				mp[i][s] = true;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			memset(vs, 0, sizeof(vs));
			if (find(i)) ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}

bool find(int a) {
	for (int i = 1; i <= m; ++i) {
		if (!vs[i] && mp[a][i]){
			vs[i] = true;
			if (link[i] == 0 || find(link[i])) {
				link[i] = a;
				return true;
			}
		}
	}
	return false;
}