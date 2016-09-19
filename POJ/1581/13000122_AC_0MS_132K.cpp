#include<iostream>
#include<string.h>
using namespace std;

int n;
char tn[50];
char winer[50];
int wp = 0, wpt = 0;
int np, pt;
int sc[10];
int main() {
	scanf("%d", &n);
	while (n-- > 0) {
		scanf("%s", tn);
		np = pt = 0;
		for (int i = 0; i < 8; ++i) {
			scanf(" %d", &sc[i]);
			if (i%2 == 1 && sc[i] != 0) {
				np++;
				pt += sc[i] + 20*(sc[i-1]-1);
			}
		}
		if (np > wp || (np == wp && pt < wpt)) {
			wp = np; wpt = pt; strcpy(winer, tn);
		}
	}
	printf("%s %d %d\n", winer, wp, wpt);
	return 0;
}