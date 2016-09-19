#include <iostream>
using namespace std;

int s[10000005];
int main() {
	int p1 = 0, p2 = 0;
	s[0] = 1;
	int v1, v2;
	for (int i = 1; i < 10000000; ++i) {
		v1 = 2 * s[p1] + 1;
		v2 = 3 * s[p2] + 1;
		s[i] = min(v1, v2);
		if (v1 == s[i]) ++p1;
		if (v2 == s[i]) ++p2;
	}
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", s[n-1]);
	}
	return 0;
}

int min(int a, int b) {
	return a > b ? b : a;
}