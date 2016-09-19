#include<iostream>
using namespace std;

int t, n, ans;
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		ans = 0;
		while (n >= 5) {
			ans += n/5;
			n = n/5;
		}
		printf("%d\n", ans);
	}
	return 0;
}