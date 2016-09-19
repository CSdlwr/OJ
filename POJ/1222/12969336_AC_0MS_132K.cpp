#include <iostream>
using namespace std;
void enum0();
bool judge();
int n;
int pu[6][8];
int pr[8][8];
int main() {
	scanf("%d", &n);
	for (int p = 1; p <= n; ++p) {
		for (int i = 1; i <= 5; ++i) 
			for (int j = 1; j <= 6; ++j)
				scanf("%d", &pu[i][j]);
		enum0();
		printf("PUZZLE #%d\n", p);
		for (int i = 1; i <= 5; ++i) {
			for (int j = 1; j < 7; ++j) {
				printf("%d", pr[i][j]);
				if (j == 6) printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}

bool judge() {
	for (int i = 1; i < 5; ++i) 
		for (int j = 1; j < 7; ++j) 
			pr[i+1][j] = (pu[i][j]+pr[i][j]+pr[i][j-1]+pr[i][j+1]+pr[i-1][j])%2;
	for (int j = 1; j < 7; ++j)
		if ((pu[5][j]+pr[5][j]+pr[5][j-1]+pr[5][j+1]+pr[4][j])%2 == 1) 
			return false;
	return true;
}

void enum0() {
	memset(pr, 0, sizeof(pr));
	while (!judge()) {
		pr[1][1]++;
		int c = 1;
		while (pr[1][c] > 1) {
			pr[1][c] = 0;
			c++;
			pr[1][c]++;
		}
	}
}
