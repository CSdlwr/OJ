#include <iostream>
using namespace std;
#define MAXNUM 105


int n, m, k;
bool mp[MAXNUM][MAXNUM];
bool vs[MAXNUM][MAXNUM];
int count = 0;

int dfs(int i, int j);

int main() {
	scanf("%d %d %d", &n, &m, &k);
	int r, c;
	for (int i = 0; i < k; ++i) {
		scanf("%d %d", &r, &c);
		mp[r][c] = true;
	}
	memset(vs, 1, sizeof(vs));

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (vs[i][j] && mp[i][j]) {
				int t = dfs(i, j);
				//printf("t=%d, ", t);
				count = count < t ? t : count;
			}
		}
	//printf("\n");
	printf("%d\n", count);
	return 0;
}

int dfs(int i, int j) {
	int cnt = 0;
	if (i < 1 || i > n || j < 1 || j > m || !vs[i][j] || !mp[i][j])
		return 0;
	else {
		vs[i][j] = false;
		++cnt;
		cnt += dfs(i, j+1);
 		//cnt += dfs(i+1, j+1);
 		cnt += dfs(i+1, j);
 		//cnt += dfs(i+1, j-1);
 		cnt += dfs(i, j-1);
 		//cnt += dfs(i-1, j-1);
 		cnt += dfs(i-1, j);
 		//cnt += dfs(i-1, j+1);
		return cnt;
	}
}