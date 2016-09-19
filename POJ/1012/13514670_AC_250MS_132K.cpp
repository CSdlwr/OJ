#include<iostream>
#include<string.h>
using namespace std;

int k, a[20], ans[20];

int main() {
	memset(ans, 0, sizeof(ans));
	while (scanf("%d", &k)) {
		if (k == 0) break;
		else if (ans[k]) { printf("%d\n", ans[k]); continue; }
		int m = k+1;
		while (1) {
			a[0] = 0;
			int i = 1;
			for (; i <= k; ++i) {
				a[i] = (a[i-1]+m-1) % (k*2-i+1);
				if (a[i] < k) break;
			}
			if (i == k+1) { printf("%d\n", m); ans[k] = m;  break; }
			else ++m;
		}
	}
	return 0;
}