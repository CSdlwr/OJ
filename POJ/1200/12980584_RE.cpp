#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
#define INF 0x7fffffff

int n, nc;
int cnt = 0;
bool vs[16000005];
char T[6000000];

void rk(char T[]) {
	int mod = INF;
	int d = 128;
	//int h = pow(d, n-1);
	int h = 1;
	for (int i = 0; i < n-1; ++i)
		h *= d;
	int t = 0;
	for (int i = 0; i < n; ++i)
		t = (t*d+T[i]) % mod;
	int l = strlen(T);
	for (int i = 0; i <= l-n; ++i) {
		if (!vs[t]) {
			++cnt;
			vs[t] = true;
		}
		if (i < l-n)
			t = ((t-T[i]*h)*d + T[i+n]) % mod;
	}
}

int main () {
	scanf("%d %d", &n, &nc);
	getchar();
	scanf("%s", T);
	memset(vs, 0, sizeof(vs));
	rk(T);
	printf("%d\n", cnt);
	return 0;
}