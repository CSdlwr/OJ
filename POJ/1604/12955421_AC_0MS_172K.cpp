#include <iostream>
using namespace std;

int f[10005];

int main() {
	f[0] = f[1] = 1;
	for (int i = 2; i <= 10000; ++i) {
		f[i] = i * f[i-1];
		while (f[i] % 10 == 0) {
			f[i] /= 10;
		}
		while (f[i] > 100000) {
			f[i] %= 100000;
		}
	}
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%5d -> %d\n", n, f[n]%10);
	}
	return 0;
}