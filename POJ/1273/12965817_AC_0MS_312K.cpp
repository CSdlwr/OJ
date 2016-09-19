#include <iostream>
#include <queue>
using namespace std;
#define INF 0x0f0f0f0f
int gmin(int a, int b);
int edmonds_karp();
int bfs();
int mp[205][205];
int n, m;
int v1, v2, c;
int path[205], flow[205];
int maxflow;
int main() {
	while (scanf("%d %d", &n, &m) != EOF) {
		memset(mp, 0, sizeof(mp));
		for (int i = 1; i <= n; ++i) {
			scanf("%d %d %d", &v1, &v2, &c);
			if (mp[v1][v2] == 0) mp[v1][v2] = c;
			else mp[v1][v2] += c;
			
		}
		printf("%d\n", edmonds_karp());
	}
	return 0;
}

int edmonds_karp() {
	maxflow = 0;
	int iflow = 0;
	while ((iflow = bfs()) != INF) {
		maxflow += iflow;
		int cur = m;
		int prev = path[cur];
		while (cur != 1) {
			mp[prev][cur] -= iflow;
			mp[cur][prev] += iflow;
			cur = prev;
			prev = path[cur];
		}
	}
	return maxflow;
}

int bfs() {
	queue<int> q;
	memset(path, 0x0f, sizeof(path));
	memset(flow, 0x0f, sizeof(flow));
	q.push(1);
	int cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 2; i <= m; ++i) {
			if (path[i] == INF && mp[cur][i] != 0) {
				flow[i] = gmin(flow[cur], mp[cur][i]);
				q.push(i);
				path[i] = cur;
				if (i == m) return flow[m];
			}
		}
	}
	return flow[m];
}

int gmin(int a, int b) {
	return a > b ? b : a;
}