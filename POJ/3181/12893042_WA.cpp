
//要用高精度

#include <iostream>
using namespace std;
#define MAX_LEN 1005

long long  d[MAX_LEN][MAX_LEN];
unsigned long maxWays(int i, int j);

 int main() {
 	int n, k;
 	cin>>n>>k;
 	memset(d, -1, sizeof(d));
 	d[1][1] = 1;
 	cout<<maxWays(n, k)<<endl;
 	return 0;
 }

unsigned long maxWays(int i, int j) {
	if (i == 1 || j == 1)
		return 1;
	long long t, t1;
	if (i == j) {
		if ((t = d[i][j-1]) == -1) 
			d[i][j] = 1 + maxWays(i, j-1);
		else d[i][j] = 1 + t;
	} else if (i < j) {
		if ((t = d[i][i]) == -1)
			d[i][j] = maxWays(i, i);
		else d[i][j] = t;
	} else {
		if ((t = d[i][j-1]) == -1)
			t = maxWays(i, j-1);
		if ((t1 = d[i-j][j]) == -1)
			t1 = maxWays(i-j, j);
		d[i][j] = t + t1;
	}
	return d[i][j];
}