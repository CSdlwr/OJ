#include <iostream>
using namespace std;

int h, w;
char data[21][21];
int distance(int x, int y);

int main() {
	while (cin>>w>>h) {
		if (w == 0 && h == 0)
			break;
		int i = 0, j = 0;
		int sx, sy;
		while (i < h)
			cin>>data[i++];
		for (i = 0; i < h; ++i)
			for (j = 0; j < w; ++j)
				if (data[i][j] == '@') {
					sx = j;
					sy = i;
				}
		        cout<<sx<<","<<sy<<endl;
				cout<<w<<","<<h<<endl;
				cout<<distance(sx, sy)<<endl;
	}
	return 0;
}

int distance(int x, int y) {
	if (x >= w || y >= h || data[y][x] == '#' || x < 0 || y < 0)
		return 0;
	data[y][x] = '#';
	return 1 + distance(x-1, y) + distance(x+1, y) + distance(x, y-1) + distance(x, y+1);
}
