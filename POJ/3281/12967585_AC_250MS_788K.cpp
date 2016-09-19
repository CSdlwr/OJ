#include <iostream>
#include <queue>
using namespace std;
#define INF 0x0f0f0f0f
int ek();
int bfs();
int gmin_(int a, int b);
int mp[405][405];
int path[405], flow[405];
int n, f, d;
int s, t;
int main() {
	scanf("%d %d %d", &n, &f, &d);
	s = 0; 
	t = f + n + n + d + 1;
	int fi, di, l;
	memset(mp, 0, sizeof(mp));
	for (int i = 1; i <= f; ++i)
		mp[0][i] = 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &fi, &di);
		for (int j = 0; j < fi; ++j) {
			scanf("%d", &l);
			mp[l][f+i] = 1;
		}
		for (int j = 0; j < di; ++j) {
			scanf("%d", &l);
			mp[f+n+i][l+f+n+n] = 1;
			mp[l+f+n+n][t] = 1;
		}
		mp[f+i][f+n+i] = 1;
	}
	printf("%d\n", ek());
	return 0;
} 

int bfs() {
	queue<int> q;
	memset(path, 0x0f, sizeof(path));
	memset(flow, 0x0f, sizeof(flow));
	q.push(0);
	int cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 1; i <= t; ++i) {
			if (path[i] == INF && mp[cur][i] != 0) {
				q.push(i);
				path[i] = cur;
				flow[i] = gmin_(flow[cur], mp[cur][i]);
				if (i == t) return flow[i];
			}
		}
	}
	return INF;
}

int ek() {
	int mflow = 0;
	int iflow;
	int cur, prev;
	while ((iflow = bfs()) != INF) {
		mflow += iflow;
		cur = t;
		prev = path[cur];
		while (cur != 0) {
			mp[prev][cur] -= iflow;
			mp[cur][prev] += iflow;
			cur = prev;
			prev = path[cur];
		}
	}
	return mflow;
}

int gmin_(int a, int b) {
	return a > b ? b : a;
}