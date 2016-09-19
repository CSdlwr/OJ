#include <iostream>
using namespace std;

int h[5850];
int min(int a, int b, int c, int d);
int main() {
	int p2, p3, p5, p7;
	p2 = p3 = p5 = p7 = 0;
	h[0] = 1;
	for (int i = 1; i < 5842; ++i) {
		h[i] = min(h[p2]*2, h[p3]*3, h[p5]*5, h[p7]*7);
		if (h[i] == h[p2]*2) ++p2;
		if (h[i] == h[p3]*3) ++p3;
		if (h[i] == h[p5]*5) ++p5;
		if (h[i] == h[p7]*7) ++p7;
	}
	int n;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		if (n == 1 || n > 20 && n % 10 == 1)
			printf("The %dst humble number is %d.\n", n, h[n-1]);
		else if (n == 2 || n > 20 && n % 10 == 2)
			printf("The %dnd humble number is %d.\n", n, h[n-1]);
		else if (n == 3 || n > 20 && n % 10 == 3)
			printf("The %drd humble number is %d.\n", n, h[n-1]);
		else printf("The %dth humble number is %d.\n", n, h[n-1]);
	}
	return 0;
}

int min(int a, int b, int c, int d) {
	int m = a > b ? b : a;
	m = m > c ? c : m;
	return m > d ? d : m;
}