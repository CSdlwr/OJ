#include <iostream>
using namespace std;
#define MAXW 85
#define MAXH 1005

int dfs(int i, int j);
int w, h;
char mp[MAXH][MAXW];
bool vs[MAXH][MAXW];
int main() {
	scanf("%d %d", &w, &h);
	char ch = getchar();
	for (int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) 
			scanf("%c", &mp[i][j]);
		getchar();
	}
	int maxcnt = 0;
	int t;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (!vs[i][j]) {
				t = dfs(i, j);
				maxcnt = maxcnt < t ? t :maxcnt;
			}
		}
	}
	printf("%d\n", maxcnt);
	return 0;
}

int dfs(int i, int j) {
	if (i >= 0 && i < h && j >= 0 && j < w && !vs[i][j] && mp[i][j] == '*') {
		vs[i][j] = true;
		int c1 = dfs(i+1, j);
		int c2 = dfs(i-1, j);
		int c3 = dfs(i, j+1);
		int c4 = dfs(i, j-1);
		return c1+c2+c3+c4+1;
	}
	else return 0;
}