#include <iostream>
using namespace std;

int main() {
	int l, m;
	while (scanf("%d %d", &l, &m)) {
		if (l == m && l == 0) break;
		int s, e;
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &s, &e);
			l -= e - s + 1;
		}
		printf("%d\n", l+1);
	}
	return 0;
}