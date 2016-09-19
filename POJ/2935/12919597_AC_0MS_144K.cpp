#include <iostream>
#include <queue>
using namespace std;

struct state {
	int prev;
	char dirc;
	int n;
};

bool isblock(int dirc, int pox, int poy);
void print(int nn);
void bfs();
int cnt = 0;
void printInfo(int i);
bool vs[6][7];
state prev[6*6+1];
int bs[3][3];
int be[3][3];
bool fd = false;
int dirc[][3] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int sr, sc, er, ec;
int main() {
	while (scanf("%d %d", &sc, &sr) != EOF) {
		if (sc == sr && sc == 0)
			break;
		scanf("%d %d", &ec, &er);
		for (int i = 0; i < 3; ++i)
			scanf("%d %d %d %d", &bs[i][0], &bs[i][1], &be[i][0], &be[i][1]);
		memset(vs, 0, sizeof(vs));
		fd = false;
		--sc;
		--sr;
		--ec;
		--er;
		bfs();
	}
	return 0;
}

void bfs() {
	int cn, cr, cc, nn, nr, nc;
	queue<state> que;
	cr = sr;
	cc = sc;
	cn = cr * 6 + cc;
	vs[cr][cc] = true;
	state stc;
	stc.dirc = '0';
	stc.prev = -1;
	stc.n = cn;
	prev[cn] = stc;
	que.push(stc);
	while (!que.empty()) {
		stc = que.front();
		cr = stc.n / 6;
		cc = stc.n % 6;
		for (int i = 0; i < 4; ++i) {
			nr = cr + dirc[i][0];
			nc = cc + dirc[i][1];
			nn = nr * 6 + nc;
			bool ib = isblock(i, cr, cc);
			if (!ib && nr >= 0 
				&& nr < 6 && nc >= 0 && nc < 6 && !vs[nr][nc]) {
					state stn;
					stn.prev = stc.n;
					stn.dirc = i;
					stn.n = nn;
					que.push(stn);
					prev[nn] = stn;
					vs[nr][nc] = true;
					if (nr == er && nc == ec) {
						fd = true;
						print(nn);
						printf("\n");
						break;
					}
			}
		}
		que.pop();
	}
}

bool isblock(int dirc, int pox, int poy) {
	for (int i = 0; i < 3; ++i) {
		if (dirc == 0 && bs[i][1] == be[i][1] && bs[i][1] == pox
			&& bs[i][0] <= poy && be[i][0] > poy) // 向上
			return true;
		else if (dirc == 1 && bs[i][1] == be[i][1] && bs[i][1] == pox + 1
			&& bs[i][0] <= poy && be[i][0] > poy)  // 向下
			return true;
		else if (dirc == 2 && bs[i][0] == be[i][0] && bs[i][0] == poy
			&& bs[i][1] <= pox && be[i][1] > pox)  // 向左
			return true;
		else if (dirc == 3 && bs[i][0] == be[i][0] && bs[i][0] == poy + 1 
			&& bs[i][1] <= pox && be[i][1] > pox) // 向右
			return true;
	}
	return false;
}

void print(int nn) {
	if (prev[nn].prev != -1) {
		print(prev[nn].prev);
		printInfo(prev[nn].dirc);
	}
}

void printInfo(int i) {
	switch(i) {
		case 0: printf("N"); break;
		case 1: printf("S"); break;
		case 2: printf("W"); break;
		case 3: printf("E"); break;
		default: break;
	}
}