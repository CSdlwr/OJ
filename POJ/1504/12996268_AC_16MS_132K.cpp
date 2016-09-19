#include<iostream>
#include<string.h>
using namespace std;

int t;
char a[20], b[20];
int la, lb;

int sum, ca;
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%s%s", a, b);
		sum = ca = 0;
		int i = 0;
		while (a[i] != '\0' && b[i] != '\0') {
			sum = a[i]+b[i]+ca-'0'*2;
			ca = sum/10;
			a[i] = sum%10+'0';
			++i;
		}
		if (a[i] == '\0' && b[i] == '\0') {
			if (ca != 0)
			a[i++] = ca+'0';
		}
		else if (a[i] != '\0') {
			while (a[i] != '\0') {
				sum = a[i]+ca-'0';
				ca = sum/10;
				a[i] = sum%10+'0';
				++i;
			}
			if (ca != 0)
				a[i++] = ca+'0';
		} else if (b[i] != '\0') {
			while (b[i] != '\0') {
				sum = b[i]+ca-'0';
				ca = sum/10;
				a[i] = sum%10+'0';
				++i;
			}
			if (ca != 0)
				a[i++] = ca+'0';
		}
		a[i] = '\0';
		int k;
		for (int i = 0; i < strlen(a); ++i)
		if (a[i] != '0') { k = i; break;}
		printf("%s\n", a+k);
	}
	return 0;
}