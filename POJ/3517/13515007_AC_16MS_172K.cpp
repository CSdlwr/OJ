#include<iostream>
using namespace std;

int n, k, m;
int f[10005];

int main() {
	while (scanf("%d %d %d", &n, &k, &m)) {
		if (n == 0 && k == 0 && m == 0) break;
		f[1] = 0;
		for (int i = 2; i < n; ++i) f[i] = (f[i-1]+k) % i;
		f[n] = (f[n-1]+m) % n;
		printf("%d\n", f[n]+1);
	}
	return 0;
}