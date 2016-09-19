#include<iostream>
#include<string.h>
using namespace std;

char mp[800][800];
int n;
void draw(int n, int i, int j, char c) {
	if (n == 1) { mp[i][j] = c; return ;}
	int w = 1;
	for (int ww = 1; ww < n; ++ww) w *= 3;
	draw(n-1, i, j, c);
	draw(n-1, i, j+w/3, ' ');
	draw(n-1, i, j+w-w/3, c);
	draw(n-1, i+w/3, j, ' ');
	draw(n-1, i+w/3, j+w/3, c);
	draw(n-1, i+w-w/3, j, c);
	draw(n-1, i+w-w/3, j+w/3, ' ');
	draw(n-1, i+w-w/3, j+w-w/3, c);
}

int main() {
	while (scanf("%d", &n) != EOF) {
		if (n == -1) break;
		memset(mp, '\0', sizeof(mp));
		draw(n, 0, 0, 'X');
		int w = 1;
		for (int i = 1; i < n; ++i) w*=3;
		for (int i = 0; i < w; ++i) {
			for (int j = 0; j < w; ++j)
				printf("%c", mp[i][j]);
			printf("\n");
		}
	}
	return 0;
}