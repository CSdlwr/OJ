#include <iostream>
#include <queue>
using namespace std;
#define INF 0x0f0f0f0f
int gmin(int a, int b);
int bfs();
int ek();

int path[105], flow[105];
int mp[105][105];
int s, t;
char ch;
int v1, v2, c;
int main() {
	int n, np, nc, m;
	while (scanf("%d %d %d %d", &n, &np, &nc, &m) != EOF) {
		s = 0; t = n + 1;
		memset(mp, 0, sizeof(mp));
		for (int i = 0; i < m; ++i) {
			while ((ch = getchar()) != '(') ;
			scanf("%d,%d)%d", &v1, &v2, &c);
			mp[++v1][++v2] += c;
		}
		for (int i = 0; i < np; ++i) {
			while ((ch = getchar()) != '(') ;
			scanf("%d)%d", &v1, &c);
			mp[0][++v1] += c;
		}
		for (int i = 0; i < nc; ++i) {
			while ((ch = getchar()) != '(') ;
			scanf("%d)%d", &v1, &c);
			mp[++v1][n+1] += c;
		}
		printf("%d\n", ek());
	}
	return 0;
}

int ek() {
	int maxflow = 0;
	int iflow = 0;
	while ((iflow = bfs()) != INF) {
		maxflow += iflow;
		int cur = t;
		int prev = path[cur];
		while (cur != 0) {
			mp[prev][cur] -= iflow;
			mp[cur][prev] += iflow;
			cur = prev;
			prev = path[cur];
		}
	}
	return maxflow;
}

int bfs() {
	memset(path, 0x0f, sizeof(path));
	memset(flow, 0x0f, sizeof(flow));
	queue<int> q;
	q.push(0);
	int cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 1; i <= t; ++i) {
			if (path[i] == INF && mp[cur][i] != 0) {
				path[i] = cur;
				flow[i] = gmin(flow[cur], mp[cur][i]);
				if (i == t) return flow[t];
				q.push(i);
			}
		}
	}
	return flow[t];
}

int gmin(int a, int b) {
	return a > b ? b : a;
}