#include <iostream>
using namespace std;

void dfs(int i, int k);

bool m[10][10];
bool c[10];
int count = 0;
int n, k;
int main() {
	while (1) {
		count = 0;
		scanf("%d %d", &n, &k);
		if (n == -1 && k == -1)
			break;
		char ch;
		for (int i = 0; i < n; ++i) {
			scanf("%c", &ch);
			for (int j = 0; j < n; ++j) {
				scanf("%c", &ch);
				if (ch == '#') m[i][j] = true;
				else m[i][j] = false;
			}
			c[i] = true;
		}
		dfs(0, k);
		cout<<count<<endl;
	}

	return 0;
}

void dfs(int i, int k) {
	if (k == 0)
		++count;
	else if (i >= n) 
		return ;
	else {
		for (int j = 0; j < n; ++j) {
			if (m[i][j] && c[j]) {
				c[j] = false;
				dfs(i + 1, k - 1);
				c[j] = true;
			}
		}
		dfs(i + 1, k);
	}
}