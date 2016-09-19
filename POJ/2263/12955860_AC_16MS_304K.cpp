#include <iostream>
using namespace std;
#define INF 0x0f0f0f0f

int find(char* cn);
int gmax(int a, int b);
int gmin(int a, int b);
int dijkstra(int s, int e);
int n, r;
int mp[205][205];
char city[205][35];
int main() {
	int sc = 1;
	while (scanf("%d %d", &n, &r)) {
		if (n == 0 && r == 0) break;
		int w, i1, i2;
		char c1[35], c2[35];
		memset(city, 0, sizeof(city));
		memset(mp, 0x0f, sizeof(mp));
		for (int i = 0; i < r; ++i)	{
			scanf("%s%s%d", c1, c2, &w);
			i1 = find(c1);
			i2 = find(c2);
			if (mp[i1][i2] == INF || w > mp[i1][i2])
				mp[i1][i2] = mp[i2][i1] = w;
		}
		scanf("%s%s", c1, c2);
		i1 = find(c1);
		i2 = find(c2);
		printf("Scenario #%d\n", sc++);
		if (i1 == -1 || i2 == -1)
			printf("0 tons\n\n");
		else
			printf("%d tons\n\n", dijkstra(i1, i2));
	}
	return 0;
}

int dijkstra(int s, int e) {
	int d[205];
	bool vs[205];
	memset(vs, 0, sizeof(vs));
	memset(d, 0, sizeof(d));
	d[s] = INF;
	for (int i = 0; i < n; ++i) {
		int max = -1;
		int v = -1;
		for (int j = 0; j < n; ++j) {
			if (!vs[j] && d[j] > max) {
				max = d[j];
				v = j;
			}
		}
		if (v == -1 || v == e) break;
		vs[v] = true;
		for (int j = 0; j < n; ++j) {
			if (!vs[j] && mp[v][j] < INF) {
				d[j] = gmax(d[j], gmin(d[v], mp[v][j]));
			}
		}
	}
	return d[e];
}

int gmin(int a, int b) {
	return a > b ? b : a;
}

int gmax(int a, int b) {
	return a > b ? a : b;
}

int find(char* cn) {
	int i = 0;
	while (city[i][0] != '\0') {
		if (strcmp(city[i], cn) == 0)
			return i;
		++i;
	}
	strcpy(city[i], cn);
	return i;
}