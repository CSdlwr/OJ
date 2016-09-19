#include<iostream>
using namespace std;

int d[101][101];
int r[101][101];
int n;
int sum(int i, int j);

int main() {
	cin>>n;
	int i = 0, j = 0;
	while (i < n) {
		j = 0;
		while (j <= i) {
			cin>>d[i][j];
			r[i][j] = -1;
			j++;
		}
		++i;
	}
	cout<<sum(0, 0);
	return 0;
}

int sum(int i, int j) {
	if (i >= n) return 0;
	int left, right;
	if (r[i+1][j] != -1)
		left = r[i+1][j];
	else left = sum(i+1, j);
	if (r[i+1][j+1] != -1)
		right = r[i+1][j+1];
	else right = sum(i+1, j+1); 
	r[i][j] = left > right ? d[i][j] + left : d[i][j] + right;
	return r[i][j];
}

