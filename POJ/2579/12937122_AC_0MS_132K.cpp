#include <iostream>
using namespace std;

int main() {
	char s[15];
	int r, c;
	char inp[9][10] ;
	while (scanf("%s", s)) {
		if (strcmp(s, "ENDOFINPUT") == 0) break;
		scanf("%d %d", &r, &c);
		int i = 0;
		char ch = getchar();
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				ch = getchar();
				inp[i][j] = ch;
			}
			ch = getchar();
		}
		scanf("%s", s);
		ch = getchar();
		for (int i = 0; i < r - 1; ++i) {
			for (int j = 0; j < c - 1; ++j) 
				printf("%d", (inp[i][j] + inp[i][j+1] + inp[i+1][j] + inp[i+1][j+1])/4 - 48);
			printf("\n");
		}
	}
	return 0;
} 