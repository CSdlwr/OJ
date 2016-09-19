#include <iostream>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		int a, b, max = 0, ii = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d %d", &a, &b);
			a = a + b;
			if (a > 8 && a > max) {
				max = a;
				ii = i;
			}
		}
		if (max == 0) printf("0\n");
		else printf("%d\n", ii);
	}
	return 0;
}