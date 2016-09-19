#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[150];
char aa[150];
float r;
char sr[7];
int n, ri, dn;

void multi(int num) {
	int i = 0, ca = 0, sum = 0;
	bool f = false;
	while (1) {
		if (a[i] == 0) f = true;
		if (!f) sum = num * (a[i]-'0') + ca;
		else sum = ca;
		a[i] = sum % 10 + '0';
		ca = sum / 10;
		++i;
		if (f && ca == 0) break;
	}
	a[i] = 0;
}

int main() {
	while (scanf("%s %d", &sr, &n) != EOF) {
		int l = strlen(sr);
		int i = 0, j = l-1;
		while (j >= 0) {
			if (sr[j] == '.') { 
				dn = l-j-1; j--;
			}
			a[i++] = sr[j--];
		}
		r = atof(sr);
		for (int i = 0; i < dn; ++i)
		r *= 10;
		dn *= n;
		int tr = r;
		a[i] = 0;
		for (i = 1; i < n; ++i) 
			multi(tr);
		l = strlen(a);
		i = 0;
		while (a[i] == '0') 
			++i;
		a[i-1] = 0;
		if (i) dn -= i;
		i = l-1; j = 0;
		while (a[i] != 0)
		aa[j++] = a[i--];
		aa[j] = 0;
		int k = 0;
		if (j < dn) {
			printf(".");
			while (k++ < dn-j) printf("0");
			printf("%s\n", aa);
		}
		else {
			while (aa[k] != 0) {
				printf("%c", aa[k++]);
				if (k == j-dn) printf(".");
			}
			printf("\n");
		}
	}
	return 0;
}