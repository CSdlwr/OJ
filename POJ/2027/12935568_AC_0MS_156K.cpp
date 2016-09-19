#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if (n > 0) {
		int a, b;
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &a, &b);
			if  (a >= b) printf("MMM BRAINS\n");
			else printf("NO BRAINS\n");
		}
	}
	return 0;
}