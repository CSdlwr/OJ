#include<iostream>
using namespace std;
#define INF 0x0f0f0f0f
bool judge();
void enum1();
int pu[5][6];
int pr[5][6];
char ch;
int same = 0;
int ans = INF;
int main() {
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= 4; ++j) {
			ch = getchar();
			if (ch == 'b') pu[i][j] = 1;
			else pu[i][j] = 0;
			same += pu[i][j];
		}
		getchar();
	}
	if (same == 0 || same == 16) {
		printf("0\n");
		return 0;
	}
	enum1();
	for (int i = 1; i < 5; ++i)
		for (int j = 1; j < 5; ++j)
			pu[i][j] = (pu[i][j]+1)%2;
	enum1();
	if (ans == INF) printf("Impossible\n");
	else printf("%d\n", ans);
	return 0;
}

bool judge() {
	for (int i = 1; i < 4; ++i) 
		for (int j = 1; j < 5; ++j) 
			pr[i+1][j] = (pu[i][j]+pr[i][j]+pr[i][j-1]+pr[i][j+1]+pr[i-1][j])%2;
	for (int j = 1; j < 5; ++j)
		if ((pu[4][j]+pr[4][j]+pr[4][j-1]+pr[4][j+1]+pr[3][j])%2 == 1)
			return false;
	return true;
}

void enum1() {
	memset(pr, 0, sizeof(pr));
	while (1) {
		if (judge()) {
			int t = 0;
			for (int i = 1; i < 5; ++i)
				for (int j = 1; j < 5; ++j)
					t += pr[i][j];
			ans = ans > t ? t : ans;
		}
		pr[1][1]++;
		int c = 1;
		while (pr[1][c] > 1) {
			pr[1][c] = 0;
			c++;
			if (c == 5) return ;
			pr[1][c]++;
		}
	}
}