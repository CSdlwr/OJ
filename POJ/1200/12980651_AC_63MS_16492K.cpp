#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int n, nc;
int cnt = 0;
int asc[128];
bool vs[16000005];
char T[8000000];

void rk(char T[], int l) {
	int d = nc;
	int h = 1;
	for (int i = 0; i < n-1; ++i) 
		h *= d;
	int t = 0;
	for (int i = 0; i < n; ++i)
		t = t*d+asc[T[i]];
	for (int i = 0; i <= l-n; ++i) {
		if (!vs[t]) {
			++cnt;
			vs[t] = true;
		}
		if (i < l-n)
			t = (t-asc[T[i]]*h)*d + asc[T[i+n]];
	}
}

int main () {
	while (scanf("%d %d", &n, &nc) != EOF) {
		cnt = 0;
		getchar();
		scanf("%s", T);
		int l = strlen(T);
		memset(vs, 0, sizeof(vs));
		memset(asc, 0, sizeof(asc));
		for (int i = 0, j = 0; i < l; ++i) {
			if (!asc[T[i]]) asc[T[i]] = j++;
			if (j == nc) break;
		}
		rk(T, l);
		printf("%d\n", cnt);
	}
	return 0;
}