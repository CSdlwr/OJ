#include<iostream>
#include<string.h>
using namespace std;

int mxc, rl, rcnt;
int pc[10005];
bool rem[10005];
bool poli;
char re;
int x;
int main() {
	while (scanf("%d", &mxc) != EOF) {
		poli = true;
		rcnt = 0;
		memset(pc, 0, sizeof(pc));
		memset(rem, 0, sizeof(rem));
		getchar();
		scanf("%d", &rl);
		getchar();
		for (int i = 0; i < rl; ++i) {
		scanf("%d", &x); rem[x] = true;
		}
		getchar();
		while (scanf("%c", &re)) {
			if (re == 'e') break;
			else if (re == 'a') {
				scanf("%d", &x); getchar();
				pc[x]++;
			} else if (re == 'p') {
				scanf("%d", &x); getchar();
				if (x == 1) poli = true;
				else poli = false;
			} else {
				getchar();
				int i;
				bool f = false;
				if (poli) {
					for (i = 0; i < mxc; ++i)
					if (pc[i] > 0) { pc[i]--; rcnt++; break; f = true; }
				} else {
					for (i = mxc; i > 0; ++i) 
					if (pc[i] > 0) { pc[i]--; rcnt++; break; f = true; }
				}
				if (f && rem[rcnt]) printf("%d\n", i);
				else (!f) printf("-1\n");
			}
		}
		printf("\n");
	}
	return 0;
}