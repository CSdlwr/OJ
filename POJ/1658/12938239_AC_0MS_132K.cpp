#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	int m, d, i1, i2, i3, i4;
	for (int i = 0; i < t; ++i) {
		scanf("%d %d %d %d", &i1, &i2, &i3, &i4);
		int m = i2 - i1;
		if (i3 == i1 + 2 * m) {
			printf("%d %d %d %d %d\n", i1, i2, i3, i3+m, i3+m*2);
			continue;
		} else {
			d = i2 / i1;
			printf("%d %d %d %d %d\n", i1, i2, i3, i3*d, i3*d*d);
		}
	}
	return 0;
}
