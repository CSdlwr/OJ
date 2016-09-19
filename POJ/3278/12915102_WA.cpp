#include <iostream>
#include <queue>
using namespace std;
#define MAXNUM 200000

int mp[MAXNUM+10];
bool vs[MAXNUM+10];
int prev[MAXNUM];
int cnt = 0;
bool fd = false;
int n, k;
void bfs();

int main() {
	scanf("%d %d", &n, &k);
	memset(vs, 0, sizeof(vs));
	memset(prev, -1, sizeof(prev));
	bfs();
	printf("%d\n", cnt);
	return 0;
}

void bfs() {
	queue<int> que;
	int cur, l, r, dr;
	cur = n;
	que.push(cur);
	vs[n] = true;
	while (!que.empty()) {
		cur = que.front();
		if (fd) {
			break;
		}
		l = cur - 1;
		if (l >= 0 && !vs[l]) {
			vs[l] = true;
			prev[l] = cur;
			que.push(l);
			if (l == k) {
				fd = true;
				while (prev[l] != -1) {
					l = prev[l];
					++cnt;
				}
			}
		}
		r = cur + 1;
		if (r <= MAXNUM && !vs[r]) {
			vs[r] = true;
			prev[r] = cur;
			que.push(r);
			if (r == k) {
				fd = true;
				while (prev[r] != -1) {
					r = prev[r];
					++cnt;
				}
			}
		}
		dr = cur * 2;
		if (dr <= MAXNUM && !vs[dr]) {
			vs[dr] = true;
			prev[dr] = cur;
			que.push(dr);
			if (dr == k) {
				fd = true;
				while (prev[dr] != -1) {
					dr = prev[dr];
					++cnt;
				}
			}
		}
		que.pop();
	}
}