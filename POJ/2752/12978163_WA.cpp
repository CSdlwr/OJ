#include<iostream>
#include<string.h>
using namespace std;

char p[400005];
int f[400005];

void cpf(char p[], int len) {
	int k = 0;
	f[1] = 0;
	for (int q = 2; q <= len; ++q) {
		while (k > 0 && p[k+1] != p[q])
			k = f[k];
		if (p[k+1] == p[q]) k++;
		f[q] = k;
	}
}

void print(int len) {
	int t = f[len];
	if (t != 0) print(t);
	printf("%d ", len);
}

int main() {
	int len;
	while (scanf("%s", p+1) != EOF) {
		len = strlen(p+1);
		cpf(p, len);
		print(f[len]);
		printf("%d\n", len);
	}
	return 0;
}