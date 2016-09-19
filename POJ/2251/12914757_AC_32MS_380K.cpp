#include <iostream>
#include <queue>
using namespace std;
#define MAXNUM 32

struct postion {
	int h, x, y;
};

int dirc[][3] = {{0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}, {1, 0, 0}, {-1, 0, 0}};
char mp[MAXNUM][MAXNUM][MAXNUM];
bool vs[MAXNUM][MAXNUM][MAXNUM];
int prev[MAXNUM*MAXNUM*MAXNUM];
bool fd = false;
int cnt = 0;
void bfs();
void calcnt(int e);
int l, r, c;
postion start;
int main() {
	while (1) {
		cnt = 0;
		fd = false;
		memset(vs, 0, sizeof(vs));
		memset(prev, -1, sizeof(prev));
		scanf("%d %d %d", &l, &r, &c);
		if (l == 0 && r == 0 && c == 0)
			break;
		getchar();
		char ch;
		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < r; ++j) {
				for (int k = 0; k < c; ++k) {
					ch = getchar();
					if (ch == 'S') {
						start.h = i;
						start.x = j;
						start.y = k;
					}
					mp[i][j][k] = ch;
				}
				ch = getchar();
			}
			if (i < l - 1)
				ch = getchar();
		}
		bfs();
		if (fd) printf("Escaped in %d minute(s).\n", cnt);
		else printf("Trapped!\n");
	}
	
	return 0;
}

void bfs() {
	queue<postion> que;
	que.push(start);
	vs[start.h][start.x][start.y] = true;
	prev[start.h*(r*c)+start.x*r+start.y] = -1;
	postion next, cur;
	while (!que.empty()) {
		cur = que.front();
 		if (fd) break;
		for (int i = 0; i < 6; ++i) {
			next.h = cur.h + dirc[i][0];
			next.x = cur.x + dirc[i][1];
			next.y = cur.y + dirc[i][2];
			if (next.h >= 0 && next.h < l 
				&& next.x >= 0 && next.x < r 
				&& next.y >= 0 && next.y < c 
				&& mp[next.h][next.x][next.y] != '#' 
				&& !vs[next.h][next.x][next.y]) {
					int sum = next.h*(r*c) + next.x * c + next.y;
					int csum = cur.h * (r * c) + cur.x * c + cur.y;
				prev[next.h*(r*c) + next.x * c + next.y] = cur.h * (r * c) + cur.x * c + cur.y;
				//++cnt;
				vs[next.h][next.x][next.y] = true;
		 		if (mp[next.h][next.x][next.y] == 'E') {
		 			fd = true;
					int p = next.h*(r*c)+next.x*c+next.y;
					while (prev[p] != -1) {
						cnt++;
						p = prev[p];
					}
		 			break;
		 		}
				que.push(next);
			}
		}
		que.pop();
	}
}
