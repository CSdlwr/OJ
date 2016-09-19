#include<iostream>
#include<string.h>
using namespace std;
char a[1000];
int ans[10];
void multi(int n) {
	bool f = false;
	int ca = 0, sum, i = 0;
	while (1) {
		sum = (a[i]-'0')*n+ca;
		a[i] = sum%10+'0';
		ca = sum/10;
		if (a[++i] == '\0') { f = true; a[i] = '0';}
		if (f && ca == 0) break;
	}
	a[i] = '\0';
}
int t;
int main() {
	while (scanf("%d", &t)) {
		if (t == 0) break;
		memset(a, '0', sizeof(a));
		a[0] = '1';
		a[1] = '\0';
		for (int i = 2; i <= t; ++i)
			multi(i);
		memset(ans, 0, sizeof(ans));
		for (int i = 0; a[i] != '\0'; ++i)
			ans[a[i]-'0']++;
		printf("%d! --\n", t);
		for (int i = 0; i < 10; ++i) {
			if (i == 0 || i == 5) printf("   ");
			else printf("    ");
			printf("(%d)", i);
			printf("%5 d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}