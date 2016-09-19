#include <iostream>
using namespace std;

int cnt[105];

int main() {
	int n, q;
	int t, tt;
	while (scanf("%d %d", &n, &q)) {
		if (n == 0) break;
		memset(cnt, 0, sizeof(cnt));
		int max = 0, index = -1;
		for (int i = 0; i < n; ++i) {
			scanf("%d ", &t);
			for (int j = 0; j < t; ++j) {
				scanf("%d", &tt);
				++cnt[tt];
				if (cnt[tt] > max) {
					max = cnt[tt];
					index = tt;
				} else if (cnt[tt] == max && tt < index)
					index = tt;
			}
		}
		if (max < q) printf("0\n");
		else printf("%d\n", index);
	}
	return 0;
}