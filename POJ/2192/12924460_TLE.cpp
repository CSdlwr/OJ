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
		if (dfs(0, 0))
			printf("Data set %d: yes\n", i);
		else
			printf("Data set %d: no\n", i);
		++i;
	}
}

bool dfs(int x, int y) {
	if (x >= strlen(a) && y >= strlen(b))
		return true;
	if (x < strlen(a) && a[x] == c[x+y])
		if (dfs(x+1, y)) return true;
	if (y < strlen(b) && b[y] == c[x+y])
		if (dfs(x, y+1)) return true;
	return false;
}