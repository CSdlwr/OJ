#include <iostream>
using namespace std;
#include <queue>

int mp[5][6];
bool vs[5][6];
int dircx[] = {0, 0, 1, -1};
int dircy[] = {1, -1, 0, 0};
int prev[25];

void bfs();
void print(int i);

int main() {
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			scanf("%d", &mp[i][j]);
	memset(vs, 0, sizeof(vs));
	memset(prev, -1, sizeof(prev));
	bfs();
	return 0;
}

void bfs() {
	queue<int> que;	
	que.push(0);
	int cur;
	int curx, cury;
	prev[0] = -1;
	vs[0][0] = true;
	while (!que.empty()) {
		cur = que.front();
		curx = cur / 5;
		cury = cur % 5;
		if (curx == 4 && cury == 4) {
			print(24);
			printf("(4, 4)\n");
			break;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = curx + dircx[i];
			int ny = cury + dircy[i];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !vs[nx][ny] && mp[nx][ny] == 0) {
				vs[nx][ny] = true;
				que.push(nx * 5 + ny);
				prev[nx * 5 + ny] = cur;
			}
		}
		que.pop();
	}
}

void print(int i) {
	if (i != 0) {
		print(prev[i]);
		printf("(%d, %d)\n", prev[i]/5, prev[i]%5);
	}
}