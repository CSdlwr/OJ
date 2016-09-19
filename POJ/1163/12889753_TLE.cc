#include<iostream>
using namespace std;

int d[101][101];
int n;
int sum(int i, int j);

int main() {
	cin>>n;
	int i = 0, j = 0;
	while (i < n) {
		j = 0;
		while (j <= i)
			cin>>d[i][j++];
		i++;
	}
	cout<<sum(0, 0);
	return 0;
}

int sum(int i, int j) {
	if (i >= n) return 0;
	int l = sum(i+1, j);
	int r = sum(i+1, j+1);
	return l > r ? d[i][j] + l : d[i][j] + r;
}