#include<iostream>
using namespace std;

int k, a[20];

int main() {
	while (scanf("%d", &k)) {
		if (k == 0) break;
		int m = k+1;
		while (1) {
			a[0] = 0;
			int i = 1;
			for (; i <= k; ++i) {
				a[i] = (a[i-1]+m-1) % (k*2-i+1);
				if (a[i] < k) break;
			}
			if (i == k+1) { printf("%d\n", m); break; }
			else ++m;
		}
	}
	return 0;
}