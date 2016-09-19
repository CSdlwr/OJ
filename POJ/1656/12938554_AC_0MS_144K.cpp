#include <iostream>
#include <string.h>
using namespace std;

bool mp[100][101];

int main() {
	int n, x, y, l;
	char cmd[10];
	memset(mp, 0, sizeof(mp));
	scanf("%d", &n);
	while (n-- > 0) {
		scanf("%s %d %d %d", cmd, &x, &y, &l);
		--x; --y;
		int ans = 0;
		if (strcmp(cmd, "BLACK") == 0) {
			for (int i = x; i <x+l; ++i) 
				for (int j = y; j < y+l; ++j) 
					if (!mp[i][j]) mp[i][j] = true;

		} else if (strcmp(cmd, "WHITE") == 0) {
			for (int i = x; i < x+l; ++i)
				for (int j = y; j < y+l; ++j)
					if (mp[i][j]) mp[i][j] = false;
		} else {
			for (int i = x; i < x+l; ++i)
				for (int j = y; j < y+l; ++j)
					if (mp[i][j]) ++ans;
			printf("%d\n", ans);
		}
	}
	return 0;
}
