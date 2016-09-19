#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int m, y;
	double r;
	scanf("%lf %d %d", &r, &m, &y);
	r = (1 + r/100);
	double ans = m;
	for (int i = 0; i < y; ++i) 
		ans = ans * r;
	printf("%.0lf\n", floor(ans));
	return 0;
}