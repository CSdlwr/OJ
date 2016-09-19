#include <iostream>
using namespace std;
#define MAXNUM 27

int dirc[][3] = {{-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}};
bool fd = false;
bool vs[MAXNUM][MAXNUM];
struct position {
	int x, y;
}path[MAXNUM*MAXNUM];
void dfs(position p, int cnt);
int r, c;
int main() {
	int t; 
	scanf("%d\n", &t);
	int tt = 1;
	while (tt <= t) {
		memset(vs, 0, sizeof(vs));
		fd = false;
		scanf("%d %d", &r, &c);
		for (int i = 0; i < r; ++i) {
			if (fd) break;
			for (int j = 0; j < c; ++j) {
				if (fd) break; 
				position p;
				p.x = i; p.y = j;
				dfs(p, 0);
			}
		}
		printf("Scenario #%d:\n", tt++);
		if (fd) {
			for (int i = 0; i < r*c; ++i) {
				printf("%c%d", path[i].y+'A', path[i].x+1);
			}
			printf("\n");
		} else printf("impossible\n");
		printf("\n");
	}
	return 0;
}

void dfs(position p, int cnt) {
	if (!fd && p.x >= 0 && p.x < r && p.y >= 0 
		&& p.y < c && !vs[p.x][p.y]) {
		path[cnt] = p;
		vs[p.x][p.y] = true;
		if (cnt == r * c - 1) {
			fd = true;
			return;
		}
		for (int i = 0; i < 8; ++i) {
			position np;
			np.x = p.x + dirc[i][0];
			np.y = p.y + dirc[i][1];
			dfs(np, cnt + 1);
		}
		vs[p.x][p.y] = false;
	}
}