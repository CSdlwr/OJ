#include <iostream>
using namespace std;
#define MAX_LEN 1000

int maxLen(int i, int j);
int max(int a, int b, int c, int d);

int input[MAX_LEN][MAX_LEN];
int d[MAX_LEN][MAX_LEN];
int r, c;
int main() {
	cin>>r>>c;
	memset(d, -1, sizeof(d));
	for (int i = 1; i <= r; ++i) 
		for (int j = 1; j <= c; ++j)
			cin>>input[i][j];
	int max = 0, tmp;
	for (int i = 1; i <= r; ++i) 
		for (int j = 1; j <= c; ++j) {
			tmp = maxLen(i, j);
			if (tmp > max)
				max = tmp;
		}

	cout<<max<<endl;

	return 0;
}

int maxLen(int i, int j) {
	if (i < 1 || j < 1 || i > r || j > c) {
		d[i][j] = 0;
		return d[i][j];
	}
	else {
		int left = 0, right = 0, up = 0, down = 0;
		if (input[i][j] > input[i][j-1]) {
			if (d[i][j-1] == -1)
				left = maxLen(i, j-1);
			else left = d[i][j-1];
		}
		if (input[i][j] > input[i][j+1]) {
			if (d[i][j+1] == -1)
				right = maxLen(i, j+1);
			else right = d[i][j+1];
		}
		if (input[i][j] > input[i-1][j]) {
			if (d[i-1][j] == -1)
				up = maxLen(i-1, j);
			else up = d[i-1][j];
		}
		if (input[i][j] > input[i+1][j]) {
			if (d[i+1][j] == -1)
				down = maxLen(i+1, j);
			else down = d[i+1][j];
		}
		d[i][j] = 1 + max(left, right, up, down);
		return d[i][j];
	}
}

int max(int a, int b, int c, int d) {
	int max = a > b ? a : b;
	max = max > c ? max : c;
	max = max > d ? max : d;
	return max;
}