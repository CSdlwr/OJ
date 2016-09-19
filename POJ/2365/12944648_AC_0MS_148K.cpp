#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n;
	double r;
	double px[105];
	double py[105];
	scanf("%d %lf", &n, &r);
	for (int i = 0; i < n; ++i)
		scanf("%lf %lf", &px[i], &py[i]);
	double sum = 0;
	for (int i = 1; i < n; ++i)
		sum += sqrt((px[i]-px[i-1])*(px[i]-px[i-1]) + (py[i]-py[i-1])*(py[i]-py[i-1]));
	sum += sqrt((px[0]-px[n-1])*(px[0]-px[n-1]) + (py[0]-py[n-1])*(py[0]-py[n-1]));
	sum += 2 * 3.141592654 * r;
	printf("%.2lf\n", sum);
	return 0;
}