#include <iostream>
using namespace std;

int main() {
	int n, d;
	int a[105];
	while (scanf("%d %d", &n, &d)) {
		if (n == 0 && d == 0) break;
		memset(a, 0, sizeof(a));
		int max = 0, t;
		for (int i = 0; i < d; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &t);
				a[j] += t;
				max = max < a[j] ? a[j] : max;
			}
		}
		if (max == d) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}