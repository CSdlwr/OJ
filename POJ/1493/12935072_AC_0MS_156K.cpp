#include <iostream>
using namespace std;

int numx[15];

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		int num, max = 0;
		char ch = getchar();
		for (int i = 0; i < n; ++i) {
			num = 0;
			for (int j = 0; j < 25; ++j) 
				if ((ch = getchar()) == 'X') ++num;
			ch = getchar();
			numx[i] = num;
			if (num > max) max = num;
		}
		if (n != 1) {
			int ans = 0;
			for (int i = 0; i < n; ++i)
				ans += max - numx[i];
			printf("%d\n", ans);
		} else printf("0\n");
	}
	return 0;
}