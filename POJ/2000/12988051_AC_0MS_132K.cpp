#include<iostream>
using namespace std;

int n, ans;
int main() {
	int sum, i;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		i = 1; 
		sum = 0;
		ans = 0;
		while (1) {
			sum = i*(1+i)/2;
			if (sum >= n) break;
			++i;
		}
		for (int j = 1; j <= i; ++j)
		ans += j*j;
		ans -= (sum-n)*i;
		printf("%d %d\n", n, ans);
	}
	return 0;
}