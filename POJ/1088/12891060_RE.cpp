#include <iostream>
using namespace std;
#define MAX_LEN 100

int maxLen(int i, int j);
int max(int a, int b, int c, int d);

int input[MAX_LEN][MAX_LEN];
int d[MAX_LEN][MAX_LEN];
int r, c;
int main() {
	cin>>r>>c;
	memset(d, 0, sizeof(d));
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
	if (i < 1 || j < 1 || i > r || j > c)
		return 0;
	else {
		int left = 0, right = 0, up = 0, down = 0;
		if (input[i][j] > input[i][j-1])
			left = maxLen(i, j-1);
		if (input[i][j] > input[i][j+1])
			right = maxLen(i, j+1);
		if (input[i][j] > input[i-1][j])
			up = maxLen(i-1, j);
		if (input[i][j] > input[i+1][j])
			down = maxLen(i+1, j);
		return 1 + max(left, right, up, down);
	}
}

int max(int a, int b, int c, int d) {
	int max = a > b ? a : b;
	max = max > c ? max : c;
	max = max > d ? max : d;
	return max;
}