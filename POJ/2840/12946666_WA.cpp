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
		printf("%d\n", (h+12)%24);
	}
	return 0;
}