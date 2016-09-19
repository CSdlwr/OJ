#include <iostream>
using namespace std;
bool dfs(int x, int y);
char a[201], b[201], c[401];

int main() {
	int n;
	scanf("%d", &n);
	int i = 1;
	while (i <= n) {
		scanf("%s %s %s", a, b, c);
		if (dfs(strlen(a)-1, strlen(b)-1))
			printf("Data set %d: yes\n", i);
		else
			printf("Data set %d: no\n", i);
		++i;
	}
}

bool dfs(int x, int y) {
	if (x < 0 && y < 0)
		return true;
	if (x >= 0 && a[x] == c[x+y+1])
		if (dfs(x-1, y)) return true;
	if (y >= 0 && b[y] == c[x+y+1])
		if (dfs(x, y-1)) return true;
	return false;
}