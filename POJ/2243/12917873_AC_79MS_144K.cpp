#include <iostream>
#include <queue>
using namespace std;

void bfs();

bool vs[9][8];
bool fd = false;
char sr, sc, er, ec;
int cnt = 0;
int prev[8*8+1];
int dirc[][3] = {{1, -2}, {-1, -2}, {1, 2}, {-1, 2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};
int main() {
	while (scanf("%c%c %c%c", &sc, &sr, &ec, &er) != EOF) {
		getchar();
		cnt = 0; 
		fd = false;
		memset(vs, 0, sizeof(vs));
		memset(prev, -1, sizeof(prev));
		if (sc == ec && sr == er) 
			printf("To get from %c%c to %c%c takes %d knight moves.\n", sc, sr, ec, er, cnt);
		else {
			bfs();
			if (fd) printf("To get from %c%c to %c%c takes %d knight moves.\n", sc, sr, ec, er, cnt);
		}
	}
	return 0;
}

void bfs() {
	int curx, cury;
	curx = sr - '1';
	cury = sc - 'a';
	int curnb = curx * 8 + cury;
	int nex, ney, nenb;
	prev[curnb] = -1;
	queue<int> que;
	que.push(curnb);
	vs[curx][cury] = true;
	while (!que.empty()) {
		if (fd) break;
		curnb = que.front();
		curx = curnb / 8;
		cury = curnb % 8;
		for (int i = 0; i < 8; ++i) {
			nex = curx + dirc[i][0];
			ney = cury + dirc[i][1];
			nenb = nex * 8 + ney;
			if (nex >= 0 && nex < 8 && ney >= 0 
				&& ney < 8 && !vs[nex][ney]) {
				vs[nex][ney] = true;
				prev[nenb] = curnb;
				que.push(nenb);
				if (nex == er - '1' 
					&& ney == ec - 'a') {
					fd = true;
					while (prev[nenb] != -1) {
						nenb = prev[nenb];
						++cnt;
					}
					break;
				}
			}
		}
		que.pop();
	}
}