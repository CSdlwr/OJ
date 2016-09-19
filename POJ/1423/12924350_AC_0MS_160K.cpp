#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.141592653589793239
#define E 2.7182818284590452354

double stirling(int n);

int main() {
	int n;
	scanf("%d", &n);
	int t;
	while (n-- > 0) {
		scanf("%d", &t);
		printf("%d\n", (int)stirling(t)+1);
	}
	return 0;
}

double stirling(int n) {
	return log10(2*PI*n)/2 + n*log10(n/E) ;
}