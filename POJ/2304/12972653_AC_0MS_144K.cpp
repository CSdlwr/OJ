#include<iostream>
using namespace std;

int p, a, b, c;
int ans;
int main() {
	while (scanf("%d %d %d %d", &p, &a, &b, &c)) {
		if (p == 0 && a == 0 && b == 0 && c == 0) break;
		ans = 0;
		ans += 720;
		if (a <= p) ans += (p-a)*9;
		else ans += 360-(a-p)*9;
		ans += 360;
		if (b >= a) ans += (b-a)*9;
		else ans += 360-(a-b)*9;
		if (c <= b) ans += (b-c)*9;
		else ans += 360-(c-b)*9;
		printf("%d\n", ans);
	}
	return 0;
}