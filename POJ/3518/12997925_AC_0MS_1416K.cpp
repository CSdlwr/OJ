#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

bool pr[1300000];

int n;
int main() {
	memset(pr, 0, sizeof(pr));
	pr[1] = true;
	for (int i = 2; i <= sqrt(1300000*1.0); ++i) {
		if (!pr[i]) {
			for (int j = i+i; j < 1300000; j+=i)
				pr[j] = true;
		}
	}
	int k;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		if (!pr[n]) { printf("0\n"); continue; }
		int r = 0, l = 0;
		int i = n;
		while (pr[++i]) {
			r++;
		}
		i = n;
		while (pr[--i]) {
			l++;
		}
		printf("%d\n", r+l+2);
	}
	return 0;
}