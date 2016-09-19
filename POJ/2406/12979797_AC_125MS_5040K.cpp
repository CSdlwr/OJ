#include<iostream>
#include<string.h>
using namespace std;
char p[1000005];
int f[1000005];
void cpf(char p[], int len) {
	int k = 0;
	f[1] = 0;
	for (int q = 2; q <= len; ++q) {
		while (k > 0 && p[q] != p[k+1])
			k = f[k];
		if (p[q] == p[k+1]) k++;
		f[q] = k;
	}
}

int main() {
	while(scanf("%s", p+1)) {
		if (p[1] == '.') break;
		int s = strlen(p+1);
		cpf(p, s);
		if (s%(s-f[s]) == 0) printf("%d\n", s/(s-f[s]));
		else printf("1\n");
	}
	return 0;
}