#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int r[17], g[17], b[17];
	for (int i = 0; i < 16; ++i) 
		scanf("%d %d %d", r+i, g+i, b+i);
	int rr, gg, bb;
	double d, min;
	int ii;
	while (scanf("%d %d %d", &rr, &gg, &bb)) {
		ii = -1;
		min = 1000000;
		if (rr == -1 && gg == -1 && bb == -1) break;
		for (int i = 0; i < 16; ++i) {
			d = sqrt((double)(rr-r[i])*(double)(rr-r[i])+(double)(gg-g[i])*(double)(gg-g[i])+(double)(bb-b[i])*(double)(bb-b[i]));
			if (d == 0) {
				ii = i;
				break;
			} else if (d < min) {
				min = d;
				ii = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", rr, gg, bb, r[ii], g[ii], b[ii]);
	}
	return 0;
}