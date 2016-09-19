#include<iostream>
#include<string.h>
using namespace std;
int n;
char in[25];
char mp[10][25];
bool e;
int r;

int main() {
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		e = true;
		r = 0;
		getchar();
		while (scanf("%c", &in[0])) {
			if (in[0] == '\n') break;
			for (int i = 0; i < n-1; ++i) 
				scanf("%c", &in[1+i]);
			if (e) strcpy(mp[r++], in);
			else {
				for (int i = 0; i < n; ++i) 
					mp[r][n-i-1] = in[i];
				++r;
			}
			e = !e;
		}
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < r; ++j)
				printf("%c", mp[j][i]);
		printf("\n");
	}
	return 0;
}