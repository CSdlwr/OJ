#include <iostream>
using namespace std;

int h[5850];
int min(int a, int b, int c, int d);
char* suffix(int n);
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
		printf("The %d%s humble number is %d.\n", n, suffix(n), h[n-1]);
	}
	return 0;
}

int min(int a, int b, int c, int d) {
	int m = a > b ? b : a;
	m = m > c ? c : m;
	return m > d ? d : m;
}

char* suffix(int n) {
	char* s = (char*)malloc(3);
	if (n == 1) s = "st";
	else if (n == 2) s = "nd";
	else if (n == 3) s = "rd";
	else if (n <= 20) s = "th";
	else if (n <= 100) s = suffix(n % 10);
	else s = suffix(n % 100);
	return s;
}