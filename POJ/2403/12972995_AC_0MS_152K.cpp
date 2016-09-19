#include<iostream>
#include<string.h>
using namespace std;

char dic[1005][17];
int v[1005];
char d[17];
int ans;
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; ++i) 
		scanf("%s %d", dic[i], &v[i]);
	for (int i = 0; i < n; ++i) {
		ans = 0;
		while (scanf("%s", d))  {
			if (strcmp(d, ".") == 0) break;
			for (int j = 0; j < m; ++j) {
				if (strcmp(d, dic[j]) == 0) {
					ans += v[j];
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}