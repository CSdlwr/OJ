#include<iostream>
#include<string.h>
using namespace std;

char mp[100][11];
char k[11];
char in[105];

int main() {
	while (scanf("%s", k)) {
		if (strcmp(k, "THEEND") == 0) break;
		scanf("%s", in);
		char min;
		int v;
		int l = strlen(k);
		int r = strlen(in) / l;
		int ii = 0;
		for (int j = 0; j < l; ++j) {
			min = 'Z'+1; v = -1;
			for (int i = 0; i < l; ++i) {
				if (k[i] != '0' && k[i] < min) {
					min = k[i];
					v = i;
				}
			}
			if (v == -1) break;
			k[v] = '0';
			for (int rr = 0; rr < r; ++ii, ++rr) 
				mp[rr][v] = in[ii];
		}
		for (int i = 0; i < r; ++i)
			printf("%s", mp[i]);
		printf("\n");
	}
	return 0;
}