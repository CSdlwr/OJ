#include<iostream>
#include<string.h>
using namespace std;

int n;
int a, b, c;
char n1[10], n2[10], in[10];
int ma, mi, t;
int main() {
	while (scanf("%d", &n)) {
		if (n == -1) break;
		ma = 0; mi = 555;
		for (int i = 0; i < n; ++i) {
			scanf("%d %d %d %s", &a, &b, &c, &in);
			t = a*b*c;
			if (t > ma) { ma = t; strcpy(n1, in);}
			if (t < mi) { mi = t; strcpy(n2, in);}
		}
		printf("%s took clay from %s.\n", n1, n2);
	}
	return 0;
}