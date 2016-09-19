#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		int h, m;
		scanf("%d:%d", &h, &m);
		if (m != 0) {
			printf("0\n");
			continue;
		}
		h += 12;
		h = h > 24 ? h - 24 : h;
		printf("%d\n", h);
	}
	return 0;
}