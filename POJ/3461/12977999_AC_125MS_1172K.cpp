#include<iostream>
#include<string.h>
using namespace std;

char p[10005], t[1000005];
int f[10005];
int n;
int cnt;

void cpf(char p[], int len) {
	int k = 0;
	f[1] = 0;
	for (int q = 2; q <= len; ++q) {
		while (k > 0 && p[k+1] != p[q]) 
			k = f[k];
		if (p[k+1] == p[q])
			++k;
		f[q] = k;
	}
}

void kmp(char p[], char t[], int lp, int lt) {
	cpf(p, lp);
	int q = 0;
	for (int i = 1; i <= lt; ++i) {
		while (q > 0 && p[q+1] != t[i])
			q = f[q];
		if (p[q+1] == t[i])	q++;
		if (q == lp) {
			++cnt;
			q = f[q];
		}
	}
}

int main() {
	scanf("%d", &n);
	getchar();
	while (n-- > 0) {
		cnt = 0;
		scanf("%s", p+1);
		getchar();
		scanf("%s", t+1);
		kmp(p, t, strlen(p+1), strlen(t+1));
		printf("%d\n", cnt);
	}
	return 0;
}
