#include <iostream>
using namespace std;
#define MAXM 30

char mp[MAXM][MAXM];
bool vs[MAXM];

int count = 1;
int r, c;
int dfs(int i, int j);

int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; ++i) {
		getchar();
		for (int j = 0; j < c; ++j)
			scanf("%c", &mp[i][j]);
	}
	printf("%d\n", dfs(0, 0));
	memset(vs, 0, sizeof(vs));
	return 0;
}

int dfs(int i, int j) {
	if (i < 0 || i >= r || j < 0 || j >= c || vs[mp[i][j] - 'A'])
		return 0;
	vs[mp[i][j] - 'A'] = true;
	int l = dfs(i, j-1);
	int r = dfs(i, j+1);
	int u = dfs(i-1, j);
	int d = dfs(i+1, j);
	int maxl = l > r ? l : r;
	maxl = maxl < u ? u : maxl;
	maxl = maxl < d ? d : maxl;
	vs[mp[i][j] - 'A'] = false;
	return maxl + 1;
}