#include<iostream>
using namespace std;

int n;
int r, rs;
int jn, jj;
int m[105][105];
bool f;
int main() {
	while (scanf("%d", &n)) {
		if (n == 0) break;
		f = false;
		r = -1;
		for (int i = 0; i < n; ++i) {
			rs = 0;
			for (int j = 0; j < n; ++j) {
				scanf("%d", &m[i][j]);
				rs += m[i][j];		
			}
			if (rs%2) {
				if (r == -1) r = i;
				else f = true;
			}
//			if (f) break;
		}
		if (f) printf("Corrupt\n");
		else if (r == -1) {
			for (int i = 0; i < n; ++i) {
				rs = 0;
				for (int j = 0; j < n; ++j)
					rs += m[j][i];
				if (rs%2) {
					f = true;
					break;
				}
			}
			if (!f) printf("OK\n");
			else printf("Corrupt\n");
		} else {
			jn = 0, jj = -1;
			for (int i = 0; i < n; ++i) {
				rs = 0;
				for (int j = 0; j < n; ++j)
					rs += m[j][i];
				if (rs%2 == 1) {
					++jn;
					jj = i;
				}
			}
			if (jn != 1) printf("Corrupt\n");
			else printf("Change bit (%d,%d)\n", r+1, jj+1);
		}
	}
	return 0;
}