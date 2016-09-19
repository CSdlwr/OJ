#include <iostream>
using namespace std;

int u[1505];
int n;
int min(int a, int b, int c);
int main() {
	u[0] = 1;
	int p2, p3, p5;
	p2 = p3 = p5 = 0;
	for (int i = 1; i <= 1500; ++i) {
		u[i] = min(u[p2]*2, u[p3]*3, u[p5]*5);
		if (u[i] == u[p2]*2) ++p2;
		if (u[i] == u[p3]*3) ++p3;
		if (u[i] == u[p5]*5) ++p5;

	}
	while (scanf("%d", &n)) {
		if (n == 0) break;
		printf("%d\n", u[n-1]);
	}
	return 0;
}

int min(int a, int b, int c) {
	int m = a > b ? b : a;
	m = m > c ? c : m;
	return m;
}