#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int m, y;
	float r;
	scanf("%f %d %d", &r, &m, &y);
	r = (1 + r/100);
	float ans = m;
	for (int i = 0; i < y; ++i) 
		ans = ans * r;
	printf("%.0f\n", floor(ans));
	return 0;
}