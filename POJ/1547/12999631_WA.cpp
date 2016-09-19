#include<iostream>
using namespace std;

int n;
int a, b, c;
char n1[10], n2[10];
int ma, mi, t;
int main() {
	while (scanf("%d", &n)) {
		if (n == -1) break;
		ma = 0; mi = 555;
		for (int i = 0; i < n; ++i) {
			scanf("%d %d %d", &a, &b, &c);
			t = a*b*c;
			if (t > ma) { ma = t; scanf("%s", n1);}
			else if (t < mi) { mi = t; scanf("%s", n2);}
		}
		printf("%s took clay from %s\n", n1, n2);
	}
	return 0;
}