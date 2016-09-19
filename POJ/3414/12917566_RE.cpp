#include <iostream>
#include <queue>
using namespace std;
#define MAXNUM 205
void bfs();
int cnt = 0;
struct preOp {
	int prev, op;
	int aa, bb;
	int nb;
};
void print(preOp preop);
void printInfo(int i);

int mp[MAXNUM][MAXNUM];
bool vs[MAXNUM][MAXNUM];
preOp prev[MAXNUM];
int a, b, c;
bool fd = false;

int main() {
	scanf("%d %d %d", &a, &b, &c);
	memset(vs, 0, sizeof(vs));
	memset(prev, -1, sizeof(prev));
	bfs();
	if (!fd) printf("impossible\n");
	return 0;
}

void bfs() {
	queue<preOp> que;
	preOp cur;
	cur.aa = 0; 
	cur.bb = 0;
	cur.nb = 0;
	cur.prev = -1;
	prev[cur.nb] = cur;
	vs[0][0] = true;
	que.push(cur);
	while (!que.empty()) {
		cur = que.front();
		if (fd) break;
		for (int i = 0; i < 6; ++i) {
			preOp ne;
			ne.aa = cur.aa;
			ne.bb = cur.bb;
			if (i == 0)  // 填满a
				ne.aa = a;
			else if (i == 1)  // 填满b
				ne.bb = b;
			else if (i == 2)  // 倒空a
				ne.aa = 0;
			else if (i == 3)  // 倒空b
				ne.bb = 0;
			else if (i == 4) { // a->b
				if (cur.aa+cur.bb < b) {
					ne.bb = cur.aa + cur.bb;
					ne.aa = 0;
				}
				else {
					ne.aa = cur.aa+cur.bb - b;
					ne.bb = b;
				}
			} else { // b->a
				if (cur.aa+cur.bb < a) {
					ne.aa = cur.aa + cur.bb;
					ne.bb = 0;
				}
				else {
					ne.bb = cur.aa+cur.bb - a;
					ne.aa = a;
				}
			}
			if (!vs[ne.aa][ne.bb]) {
				ne.prev = cur.nb;
				ne.op = i;
				ne.nb = ne.aa*(b+1) + ne.bb;
				prev[ne.nb] = ne;
				que.push(ne);
				vs[ne.aa][ne.bb] = true;
				if (ne.aa == c || ne.bb == c) {
					fd = true;
					int t = ne.nb;
					while (t >= 0 && prev[t].prev != -1) {
						t = prev[t].prev;
						cnt++;
					}
					printf("%d\n", cnt);
					print(ne);
					break;
				}
			}
		}
		que.pop();
	}
}

void print(preOp preop) {
	if (preop.prev >= 0) {
		print(prev[preop.prev]);
		printInfo(preop.op);
	}
}

void printInfo(int i) {
	switch(i) {
		case 0: printf("FILL(1)\n"); break;
		case 1: printf("FILL(2)\n"); break;
		case 2: printf("DROP(1)\n"); break;
		case 3: printf("DROP(2)\n"); break;
		case 4: printf("POUR(1,2)\n"); break;
		case 5: printf("POUR(2,1)\n"); break;
		default: ;
	}
}