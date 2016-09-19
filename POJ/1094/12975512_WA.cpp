#include<iostream>
#include<string.h>
using namespace std;
bool mp[27][27];
int id[27], tid[27];
int n, m;
char ans[27];
bool fd;
char v1, v2;

int topsort(int n) {
	int cnt = 0, loc, tm, flag = 1;
	memset(tid, 0, sizeof(tid));
	for (int i = 0; i < n; ++i)
		tid[i] = id[i];
	for (int i = 0; i < n; ++i) {
		tm = 0;
		for (int j = 0; j < n; ++j) {
			if (tid[j] == 0) {
				++tm;
				loc = j;
			}
		}
		if (tm == 0) return -1; // ÓÐ»·
		if (tm > 1)  return 0;//flag = 0;
		ans[cnt++] = (char)(loc+'A');
		tid[loc] = -1;
		for (int j = 0; j < n; ++j)
			if (mp[loc][j]) --tid[j];
	}
	return 1;
}

int main() {
	while (scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0) break;
		getchar();
		memset(mp, 0, sizeof(mp));
		memset(id, 0, sizeof(id));
		memset(ans, 0, sizeof(ans));
		fd = false;
		for (int i = 0; i < m; ++i) {
			scanf("%c<%c", &v1, &v2);
			getchar();
			if (fd) continue;
			mp[v1-'A'][v2-'A'] = true;
			id[v2-'A']++;
			int r = topsort(n);
			if (r == -1) {
				printf("Inconsistency found after %d relations.\n", i+1);
				fd = true;
			} else if (r == 1) {
				printf("Sorted sequence determined after %d relations: %s.\n", i+1, ans);
				fd = true;
			}
		}
		if (!fd) printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}