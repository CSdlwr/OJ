#include<iostream>
using namespace std;

int n;
int s, d;
int x1, x2;
int main () {
	scanf("%d", &n);
	while (n-- > 0) {
		scanf("%d %d", &s, &d);
		if (s < d || (s+d)%2 != 0) {
			printf("impossible\n");
			continue;
		}
		x1 = (s+d)/2;
		x2 = s - x1;
		if (x1 > x2) printf("%d %d\n", x1, x2);
		else printf("%d %d\n", x2, x1);
	}
	return 0;
}