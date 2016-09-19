#include <iostream>
using namespace std;

int d[1000][1000];
char s1[1000], s2[1000];
int maxLen(int i, int j);

int main() {
	while (cin>>(s1+1)>>(s2+1)) {
		memset(d, 0, sizeof(d));

		int l1 = strlen(s1+1);
		int l2 = strlen(s2+1);
// 		for (int i = 0; i <= l1; ++i)
// 			d[i][0] = 0;
// 		for (int i = 0; i <= l2; ++i)
// 			d[0][i] = 0;
		//maxLen(strlen(s1)-1, strlen(s2)-1);
		for (int i = 1; i <= l1; ++i) {
			for (int j = 1; j <= l2; ++j) {
				if (s1[i] == s2[j]) 
					d[i][j] = d[i-1][j-1] + 1;
				else if (d[i-1][j] > d[i][j-1])
					d[i][j] = d[i-1][j];
				else d[i][j] = d[i][j-1];
			}
		}
		
		cout<<d[l1][l2]<<endl;
	}
	return 0;
}