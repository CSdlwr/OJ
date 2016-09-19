#include<iostream>
#include<string.h>
using namespace std;
void topsort(int n);
bool mp[105][105];
int id[105];
int ans[105];
int n, in;
int main() {
	scanf("%d", &n);
	memset(mp, 0, sizeof(mp));
	memset(id, 0, sizeof(id));
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= n; ++i) {
		while (scanf("%d", &in)) {
			if (in == 0) break;
			mp[i][in] = true;
			id[in]++;
		}
	}
	topsort(n);
	for (int i = 1; i <= n; ++i) {
		printf("%d", ans[i]);
		if (i != n) printf(" ");
	}
	printf("\n");
	return 0;
}

void topsort(int n) {
	int loc, cnt = 1;
	for (int i = 0; i < n; ++i) {
		loc = -1;
		for (int j = 1; j <= n; ++j) 
			if (id[j] == 0) {
				loc = j;
				break;
			}
		ans[cnt++] = loc;
		id[loc] = -1;
		for (int j = 1; j <= n; ++j) 
			if (mp[loc][j]) --id[j];
	}
}