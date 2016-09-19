#include <iostream>
using namespace std;
#define MAXN 21

void dfs(int d, int sum);
int ans = 0;
int n;
bool vs[MAXN];
int mp[MAXN][MAXN];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &mp[i][j]);
	memset(vs, 0, sizeof(vs));
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}

void dfs(int d, int sum) {
	if (d >= n) {
		ans = ans < sum ? sum : ans;
		return ;
	}
	vs[d] = true;
	int t = 0;
	for (int i = 0; i < n; ++i) {
		if (!vs[i]) t += mp[d][i];
		else t -= mp[d][i];
	}
	dfs(d+1, sum + t);
	vs[d] = false;
	dfs(d+1, sum);
}