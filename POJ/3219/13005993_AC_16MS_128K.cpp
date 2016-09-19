#include<iostream>
using namespace std;

int n, k, m;
int a1, a2;
int main() {
	while (scanf("%d %d", &n, &k) != EOF) {
		a1 = a2 = 0;
		m = n-k;
		while (n >= 2) {
			a1 += n/2;
			n /= 2;
		}
		while (k >= 2) {
			a2 += k/2;
			k /= 2;
		}
		while (m >= 2) {
			a2 += m/2;
			m /= 2;
		}
		if (a1 > a2) printf("0\n");
		else printf("1\n");
	}
	return 0;
}