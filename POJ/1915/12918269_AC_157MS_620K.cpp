#include <iostream>
#include <queue>
using namespace std;
#define MAXL 305

void bfs();
int cnt = 0;
bool fd = false;
bool vs[MAXL][MAXL];
int prev[MAXL*MAXL];
int dirc[][3] = {{1, -2}, {-1, -2}, {1, 2}, {-1, 2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};

int sx, sy, ex, ey;
int l;
int main() {
	int n;
	scanf("%d", &n);
	while (n-- > 0) {
		scanf("%d\n%d %d\n%d %d", &l, &sx, &sy, &ex, &ey);
		memset(vs, 0, sizeof(vs));
		memset(prev, -1, sizeof(prev));
		cnt = 0;
		fd = false;
		if (sx == ex && sy == ey)
			printf("0\n");
		else bfs();
	}
	return 0;
}

void bfs() {
	queue<int> que;
	int cn, cx, cy, nx, ny, nn;
	cx = sx; 
	cy = sy;
	cn = cx * l + cy;
	prev[cn] = -1;
	vs[cx][cy] = true;
	que.push(cn);
	while (!que.empty()) {
		if (fd) break;
		cn = que.front();
		cx = cn / l;
		cy = cn % l;
		for (int i = 0; i < 8; ++i) {
			nx = cx + dirc[i][0];
			ny = cy + dirc[i][1];
			nn = nx * l + ny;
			if (nx >= 0 && nx < l && 
				ny >= 0 && ny < l && !vs[nx][ny]) {
				vs[nx][ny] = true;
				prev[nn] = cn;
				que.push(nn);
				if (nx == ex && ny == ey) {
					fd = true;
					while (prev[nn] != -1) {
						++cnt;
						nn = prev[nn];
					}
					printf("%d\n", cnt);
					break;
				}
			}
		}
		que.pop();
	}
}