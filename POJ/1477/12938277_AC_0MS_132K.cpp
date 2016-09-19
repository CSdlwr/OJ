#include <iostream>
using namespace std;

int inp[55];

int main() {
	int n, s = 0;
	while (scanf("%d", &n)) {
		if (n == 0)	 break;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &inp[i]);
			sum += inp[i];
		}
		int ave = sum / n;
		int ans = 0;
		for (int i = 0; i < n; ++i)
			if (inp[i] < ave) ans += ave - inp[i];
		printf("Set #%d\n", ++s);
		printf("The minimum number of moves is %d.\n\n", ans);
	}
	return 0;
}