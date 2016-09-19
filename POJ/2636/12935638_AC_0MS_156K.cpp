#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int k, t;
		scanf("%d", &k);
		int sum = 0;
		for (int j = 0; j < k; ++j) {
			scanf("%d", &t);
			sum += t;
		}
		printf("%d\n", sum - k + 1);
	}
	return 0;
}