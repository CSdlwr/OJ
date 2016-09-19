#include<iostream>
using namespace std;

int n;
char ans[15][26];
int cnt = 1;
int main() {
	while (scanf("%d", &n)) {
		if (n == 0) break;
		for (int i = 0; i < n; ++i) {
			if (i%2==0) scanf("%s", ans[i/2]);
			else scanf("%s", ans[n-i/2-1]);
		}
		printf("SET %d\n", cnt++);
		for (int i = 0; i < n; ++i)
		printf("%s\n", ans[i]);
	}
	return 0;
}