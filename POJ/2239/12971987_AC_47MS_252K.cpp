#include<iostream>
#include<string.h>
using namespace std;
bool find(int a);
int link[90];
bool vs[90];
int mp[305][90];
int n;
int cn, p, q;
int main() {
	while (scanf("%d", &n) != EOF) {
		memset(mp, 0, sizeof(mp));
		memset(link, 0, sizeof(link));
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &cn);
			for (int j = 0; j < cn; ++j) {
				scanf("%d %d", &p, &q);
				mp[i][(p-1)*12+q] = true;
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
	for (int i = 1; i <= 84; ++i) {
		if (!vs[i] && mp[a][i]) {
			vs[i] = true;
			if (link[i] == 0 || find(link[i])) {
				link[i] = a;
				return true;
			}
		}
	}
	return false;
}