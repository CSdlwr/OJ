#include<iostream>
#include<string.h>
using namespace std;
bool find(int a);
bool vs[305];
int result[305];
bool mp[105][305];
int p, n;
int cn, s;
int main() {
	int ds;
	scanf("%d", &ds);
	while (ds-- > 0) {
		scanf("%d %d", &p, &n);
		memset(mp, 0, sizeof(mp));
		for (int i = 1; i <= p; ++i) {
			scanf("%d", &cn);		
			for (int j = 0; j < n; ++j) {
				scanf("%d", &s);
				mp[i][s] = true;
			}	
		}
		int ans = 0;
		for (int i = 1; i <= p; ++i) {
			memset(vs, 0, sizeof(vs));
			if (find(i)) {
				if (++ans == p) {
					printf("YES\n");
					break;
				}
			} else {
				printf("NO\n");
				break;
			}
		}
	}
	return 0;
}

bool find(int a) {
	for (int i = 1; i <= n; ++i) {
		if (!vs[i]) {
			vs[i] = true;
			if (result[i] == 0 || find(result[i])) {
				result[i] = a;
				return true;
			}
		}
	}
	return false;
}