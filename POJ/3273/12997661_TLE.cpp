#include<iostream>
using namespace std;

int me = 0, sum  = 0;;
int n, m;
int e[100005];

bool judge(int m) {
	int t = 0, g = 1;
	for (int i = 0; i < n; ++i) {
		if (t + e[i] <= m) t += e[i];
		else { t = e[i]; g++; }
	}
	if (g <= m) return false; // m is too small
	return true; // m is too big
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i=0; i < n; ++i) {
		scanf("%d", &e[i]);
		sum += e[i];
		me = me < e[i] ? e[i] : me;
	}
	int l = me, h = sum, mid;
	while (l < h) {
		mid = (l+h)/2;
		if (judge(mid)) l = mid;
		else h = mid;
	}
	printf("%d\n", mid);
	return 0;
}